
#include "loader.h"
#include "GameHelper.h"
#include "cocos2d.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>
#include <vector>
#include <thread>

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8) && (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#endif


using namespace cocos2d;
using namespace std;

namespace neo
{
#define BUFFER_SIZE    8192
#define TEMP_FILE_NAME    ".tmp"
#define LOW_SPEED_LIMIT 1L
#define LOW_SPEED_TIME 5L

struct ErrorMessage
{
    Loader::ErrorCode code;
    Loader* loader;
};

struct ProgressMessage
{
    int percent;
    Loader* loader;
};

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8
	
	static char* WcharToChar(const wchar_t* w_str)
	{
		int nStrLen = WideCharToMultiByte(CP_UTF8, 0, w_str, -1, NULL, 0, NULL, NULL);  
		char* pStr = new char[nStrLen + 1];  
		memset(pStr, 0, nStrLen + 1);
		WideCharToMultiByte(CP_UTF8, 0, w_str, -1, pStr, nStrLen, NULL, NULL);
		return pStr;
	}

	static wchar_t* CharToWchar(const char* c_str)
	{
		int nStrLen = MultiByteToWideChar(CP_UTF8, 0, c_str, -1, NULL, 0);  
		wchar_t* pWStr = new wchar_t[nStrLen + 1];  
		memset(pWStr, 0, nStrLen + 1);  
		MultiByteToWideChar(CP_UTF8, 0, c_str, -1, pWStr, nStrLen);
		return pWStr;
	}
#endif

bool Loader::moveFile(const char* src, const char* dest)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

	wchar_t* w_src = CharToWchar(src);
	wchar_t* w_dest = CharToWchar(dest);
	bool result = MoveFileExW(w_src, w_dest, MOVEFILE_REPLACE_EXISTING) ? true : false;
	delete[] w_src;
	delete[] w_dest;
	return result;
#else
	return rename(src, dest) == 0;
#endif
}

bool Loader::removeFile(const char* filePath)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	WCHAR* w_src = CharToWchar(filePath);
	bool r = DeleteFileW(w_src);
	delete[] w_src;
	return r;
#else
	return remove( filePath )== 0 ? true : false;
#endif
}

Loader::Loader(const char* url, const char* fileName)
: _url(url)
, _curl(nullptr)
, _connectionTimeout(0)
, _delegate(nullptr)
, _isDownloading(false)
, _shouldDeleteDelegateWhenExit(true)
{
	string file = fileName;
	string delim = "/";
	int index = file.find_last_of(delim);
	if (index != -1)
	{
		_fileName = file.substr(index + 1);
		_path = file.substr(0, index);
		_path = GameHelper::getInstance()->createPath(_path);
	}
	else
	{
		_path = "";
		_fileName = fileName;
	}
}

Loader::~Loader()
{
    if (_shouldDeleteDelegateWhenExit)
    {
        delete _delegate;
    }
}

void Loader::checkFolder()
{
	
}

void Loader::update()
{
    if (_isDownloading) return;
    
    _isDownloading = true;
    
    auto t = std::thread(&Loader::downLoad, this);
    t.detach();
}

static size_t downLoadPackage(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = (FILE*)userdata;
    size_t written = fwrite(ptr, size, nmemb, fp);
    return written;
}

int loaderProgressFunc(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
    static int percent = 0;
    int tmp = (int)(nowDownloaded / totalToDownload * 100.0);
    
    if (percent != tmp)
    {
        percent = tmp;
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
            auto loader = static_cast<Loader*>(ptr);
            if (loader->_delegate)
                loader->_delegate->onProgress(percent);
        });
        
        CCLOG("downloading... %d%%", percent);
    }
    
    return 0;
}

void Loader::setDelegate(LoaderDelegateProtocol* delegate)
{
	_delegate = delegate;
}

bool Loader::downLoad()
{
    // Create a file to save package.
	const string outFileName = _path + _fileName + TEMP_FILE_NAME;
    FILE *fp = fopen(outFileName.c_str(), "wb");
    if (! fp)
    {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
            if (this->_delegate)
                this->_delegate->onError(ErrorCode::CREATE_FILE);
        });
        CCLOG("can not create file %s", outFileName.c_str());
        return false;
    }
    
    // Download pacakge
	_curl = curl_easy_init();
    CURLcode res;
    curl_easy_setopt(_curl, CURLOPT_URL, getUrl());
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, downLoadPackage);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(_curl, CURLOPT_PROGRESSFUNCTION, loaderProgressFunc);
    curl_easy_setopt(_curl, CURLOPT_PROGRESSDATA, this);
    curl_easy_setopt(_curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_LIMIT, LOW_SPEED_LIMIT);
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_TIME, LOW_SPEED_TIME);

    res = curl_easy_perform(_curl);
    curl_easy_cleanup(_curl);
    if (res != 0)
    {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
            if (this->_delegate)
                this->_delegate->onError(ErrorCode::NETWORK);
        });
        CCLOG("error when download package");
        fclose(fp);
        return false;
    }
    
    CCLOG("succeed downloading package %s", getUrl());
    
    fclose(fp);

	string des = _path + _fileName;

	/*
	if (!removeFile(des.c_str()))
	{
		Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
            if (this->_delegate)
                this->_delegate->onError(ErrorCode::CREATE_FILE);
        });
        CCLOG("error when remove file");
	}
	*/

	if (!moveFile(outFileName.c_str(), des.c_str()))
	{
		Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
            if (this->_delegate)
                this->_delegate->onError(ErrorCode::CREATE_FILE);
        });
        CCLOG("error when move file");
        return false;
	}

	Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this] {
            if (this->_delegate) this->_delegate->onSuccess();
        });

    return true;
}



const char* Loader::getUrl() const
{
    return _url.c_str();
}

const char* Loader::getPath() const
{
	return _path.c_str();
}

const char* Loader::getFileName() const
{
	return _fileName.c_str();
}

void Loader::setConnectionTimeout(unsigned int timeout)
{
    _connectionTimeout = timeout;
}

unsigned int Loader::getConnectionTimeout()
{
    return _connectionTimeout;
}

}
