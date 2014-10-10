#ifndef __GAMEHELPER_H__
#define __GAMEHELPER_H__

#include <iostream>
#include <vector>

#include "cocos2d.h"

using namespace std;
USING_NS_CC;

namespace neo
{
	class GameHelper : public Ref
	{
	public:
		static GameHelper* getInstance();
		static bool writeStringToFile(const string &content, const string &filePath);

		virtual void init();
		virtual void loadLocalVersion(int ver);
		virtual string say();
		virtual string getRoot();
		virtual string getLuaRoot();
		virtual string getAssetRoot();
		string getUpdateURL(){return _updateURL;}
		void setUpdateURL(string url){_updateURL = url;}
		string getCDN(){return _cdn;}
		void setCDN(string cdn){_cdn = cdn;}
		virtual void debug(string& info);
		virtual int getCurrentVersion();
		string createPath(string& folder);
	private:
		GameHelper();
		virtual ~GameHelper();
		static GameHelper* s_helper;
		virtual void initStructure();
		virtual void split(string& s, vector<string>* ret);
		virtual void createDir(std::string& pathToSave);
		string initWord;
		string root;
		string _cdn;
		string _updateURL;
		string luaRoot;
		string assetRoot;
		bool _init;
		bool _isUpdating;
		int currVersion;
	};
}
#endif// __APP_DELEGATE_H__