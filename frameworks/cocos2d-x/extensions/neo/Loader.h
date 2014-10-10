#ifndef __Loader__
#define __Loader__

#include <string>

#include <mutex>

#include "cocos2d.h"
#include "extensions/ExtensionMacros.h"

using namespace cocos2d;
using namespace std;

namespace neo
{

class LoaderDelegateProtocol;

class Loader : public Node
{
public:
    enum class ErrorCode
    {
        CREATE_FILE,
        NETWORK,
        NO_NEW_VERSION,
        UNCOMPRESS,
    };

	static bool removeFile(const char* filePath);
	static bool moveFile(const char* src, const char* dest);
    
    Loader(const char* packageUrl = NULL, const char* storagePath = NULL);

    virtual ~Loader();
    
    typedef std::function<void(int)> ErrorCallback;
    typedef std::function<void(int)> ProgressCallback;
    typedef std::function<void(void)> SuccessCallback;

    using Node::update;
    virtual void update();  
    const char* getUrl() const;
    const char* getPath() const;
    const char* getFileName() const;

    void setDelegate(LoaderDelegateProtocol *delegate);
    LoaderDelegateProtocol* getDelegate() const { return _delegate ;}
    void setConnectionTimeout(unsigned int timeout);
    unsigned int getConnectionTimeout();
    friend int loaderProgressFunc(void *, double, double, double, double);

protected:
    bool downLoad();

private:
    std::string _path;
	std::string _fileName;
    std::string _url;
    void *_curl;
    unsigned int _connectionTimeout;
    LoaderDelegateProtocol *_delegate; 
    bool _isDownloading;
    bool _shouldDeleteDelegateWhenExit;
	void checkFolder();
};

class LoaderDelegateProtocol
{
public:
    virtual ~LoaderDelegateProtocol(){};
public:
    virtual void onError(Loader::ErrorCode errorCode) {};
    virtual void onProgress(int percent) {};
    virtual void onSuccess() {};
};

}
#endif /* defined(__Loader__) */
