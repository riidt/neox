#include "GameHelper.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Loader.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "network/HttpClient.h"
#include <stdio.h>

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8) && (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#include <io.h>
#else
#include <unistd.h>
#endif

using namespace std;

USING_NS_CC;

namespace neo
{
	static string intToString(int val)
	{
		char buf[64];
		sprintf(buf, "%d", val);
		return buf;
	}

	static void __fsync(FILE *fp)
	{
		fflush(fp);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		int fd = _fileno(fp);
		_commit(fd);
#else
		int fd = fileno(fp);
		fsync(fd);
#endif
	}

	bool GameHelper::writeStringToFile(const string &content, const string &filePath)
	{
		char sufix[16] ;
		//获取临时文件后缀
		sprintf(sufix, "%ld", (long)time(NULL));
		string tmpFile(filePath);
		tmpFile.append(".").append(sufix);

		//将内容写入临时文件
		FILE* fp = fopen(tmpFile.c_str(), "wb");
		if(!fp) {
			return false;
		}
		fwrite(content.data(), 1, content.size(), fp);
		__fsync(fp);

		int ret = fclose(fp);
		if(ret != 0) {
			return false;
		}

		//重命名临时文件为正式文件
		Loader::removeFile(filePath.c_str());
		return Loader::moveFile(tmpFile.c_str(), filePath.c_str()) ;

	}

	GameHelper* GameHelper::s_helper = nullptr;

	GameHelper::GameHelper()
	{
		_init = false;
	}


	GameHelper::~GameHelper()
	{
		s_helper = nullptr;
	}

	GameHelper* GameHelper::getInstance()
	{
		if (s_helper == NULL)
		{
			s_helper = new GameHelper();
		}
		return s_helper;
	}

	string GameHelper::say()
	{
		return initWord;
	}

	void GameHelper::init()
	{
		if (_init)
			return;

		_isUpdating = true;
		_init = true;

		network::HttpClient::getInstance()->setTimeoutForConnect(2);
		network::HttpClient::getInstance()->setTimeoutForRead(1.5);

		root = FileUtils::getInstance()->getWritablePath() + "updateRoot/";
		createDir(root);
		initStructure();
		

		/*
		if (!FileUtils::getInstance()->isFileExist(initWord))
		{
			string localdata = FileUtils::getInstance()->getStringFromFile("file-version.json");
			
			writeStringToFile(localdata, root + initWord);
		}
		*/
	}

	void GameHelper::loadLocalVersion(int ver)
	{
		string installVersion = intToString(ver);

		initWord = "file-version-" + installVersion + ".json";

		currVersion = ver;
	}

	string GameHelper::getRoot()
	{
		return root;
	}

	string GameHelper::getLuaRoot()
	{
		return luaRoot;
	}

	string GameHelper::getAssetRoot()
	{
		return assetRoot;
	}
	int GameHelper::getCurrentVersion()
	{
		return currVersion;
	}


	void GameHelper::initStructure()
	{

		string path = "src";
		luaRoot = createPath(path);
		path = "res";
		assetRoot = createPath(path);

		vector<string> paths = FileUtils::getInstance()->getSearchPaths();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#else
		vector<string>::iterator it;
		it = paths.begin();
		it = paths.insert ( it , FileUtils::getInstance()->getWritablePath() );
		it = paths.insert ( it , root );
		it = paths.insert ( it , assetRoot );
		paths.insert ( it , luaRoot );
#endif
		//paths.push_back(FileUtils::getInstance()->getWritablePath());
		//paths.push_back(root);
		//paths.push_back(assetRoot);
		//paths.push_back(luaRoot);

		FileUtils::getInstance()->setSearchPaths(paths);
	}

	string GameHelper::createPath(string& folder)
	{
		string delim = "/";
		vector< string >* ret = new vector<string>();
        split(folder, ret);

		string path = root;
		int cnt = ret->size();
		vector<string>::iterator f;
		for (f = ret->begin(); f != ret->end(); f++)
		{
			string val = *f;
			
			if (val != "")
			{
				path += val + delim;
				createDir(path);
			}
		}

		return path;
    }


	//注意：当字符串为空时，也会返回一个空字符串
	void GameHelper::split(string& s, vector<string >* ret)
	{
		string delim = "/";
		size_t last = 0;
		size_t index=s.find_first_of(delim,last);
		while (index!=std::string::npos)
		{
			ret->push_back(s.substr(last,index-last));
			last=index+1;
			index=s.find_first_of(delim,last);
		}
		if (index-last>0)
		{
			ret->push_back(s.substr(last,index-last));
		}
	}

	void GameHelper::createDir(std::string& pathToSave)
	{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		DIR *pDir = NULL;
        
		pDir = opendir (pathToSave.c_str());
		if (! pDir)
		{
			mkdir(pathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
		}
#else
		if ((GetFileAttributesA(pathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
		{
			CreateDirectoryA(pathToSave.c_str(), 0);
		}
#endif
	}


	
	void GameHelper::debug(string& info)
	{
		
	}
}
