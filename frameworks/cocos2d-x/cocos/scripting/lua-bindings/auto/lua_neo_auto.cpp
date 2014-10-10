#include "lua_neo_auto.hpp"
#include "GameHelper.h"
#include "Loader.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_neo_GameHelper_getLuaRoot(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_getLuaRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getLuaRoot();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLuaRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getLuaRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_getAssetRoot(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_getAssetRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getAssetRoot();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAssetRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getAssetRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_getRoot(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_getRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getRoot();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_setUpdateURL(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_setUpdateURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setUpdateURL(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUpdateURL",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_setUpdateURL'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_createPath(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_createPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        std::string ret = cobj->createPath(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createPath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_createPath'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_say(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_say'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->say();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "say",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_say'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_getUpdateURL(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_getUpdateURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getUpdateURL();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUpdateURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getUpdateURL'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_setCDN(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_setCDN'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCDN(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCDN",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_setCDN'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_init(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->init();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_init'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_loadLocalVersion(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_loadLocalVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->loadLocalVersion(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadLocalVersion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_loadLocalVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_getCDN(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_getCDN'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getCDN();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCDN",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getCDN'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_debug(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_debug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->debug(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "debug",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_debug'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_getCurrentVersion(lua_State* tolua_S)
{
    int argc = 0;
    neo::GameHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::GameHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_GameHelper_getCurrentVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getCurrentVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrentVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getCurrentVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_GameHelper_writeStringToFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        bool ret = neo::GameHelper::writeStringToFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "writeStringToFile",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_writeStringToFile'.",&tolua_err);
#endif
    return 0;
}
int lua_neo_GameHelper_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"neo.GameHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        neo::GameHelper* ret = neo::GameHelper::getInstance();
        object_to_luaval<neo::GameHelper>(tolua_S, "neo.GameHelper",(neo::GameHelper*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_GameHelper_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_neo_GameHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameHelper)");
    return 0;
}

int lua_register_neo_GameHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"neo.GameHelper");
    tolua_cclass(tolua_S,"GameHelper","neo.GameHelper","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GameHelper");
        tolua_function(tolua_S,"getLuaRoot",lua_neo_GameHelper_getLuaRoot);
        tolua_function(tolua_S,"getAssetRoot",lua_neo_GameHelper_getAssetRoot);
        tolua_function(tolua_S,"getRoot",lua_neo_GameHelper_getRoot);
        tolua_function(tolua_S,"setUpdateURL",lua_neo_GameHelper_setUpdateURL);
        tolua_function(tolua_S,"createPath",lua_neo_GameHelper_createPath);
        tolua_function(tolua_S,"say",lua_neo_GameHelper_say);
        tolua_function(tolua_S,"getUpdateURL",lua_neo_GameHelper_getUpdateURL);
        tolua_function(tolua_S,"setCDN",lua_neo_GameHelper_setCDN);
        tolua_function(tolua_S,"init",lua_neo_GameHelper_init);
        tolua_function(tolua_S,"loadLocalVersion",lua_neo_GameHelper_loadLocalVersion);
        tolua_function(tolua_S,"getCDN",lua_neo_GameHelper_getCDN);
        tolua_function(tolua_S,"debug",lua_neo_GameHelper_debug);
        tolua_function(tolua_S,"getCurrentVersion",lua_neo_GameHelper_getCurrentVersion);
        tolua_function(tolua_S,"writeStringToFile", lua_neo_GameHelper_writeStringToFile);
        tolua_function(tolua_S,"getInstance", lua_neo_GameHelper_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(neo::GameHelper).name();
    g_luaType[typeName] = "neo.GameHelper";
    g_typeCast["GameHelper"] = "neo.GameHelper";
    return 1;
}

int lua_neo_Loader_getFileName(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::Loader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_Loader_getFileName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getFileName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFileName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_getFileName'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_Loader_getUrl(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::Loader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_Loader_getUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getUrl();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_getUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_Loader_update(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::Loader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_Loader_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->update();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_update'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_Loader_getPath(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::Loader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_Loader_getPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getPath();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_getPath'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_Loader_getConnectionTimeout(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::Loader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_Loader_getConnectionTimeout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getConnectionTimeout();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getConnectionTimeout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_getConnectionTimeout'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_Loader_setConnectionTimeout(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (neo::Loader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_neo_Loader_setConnectionTimeout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setConnectionTimeout(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setConnectionTimeout",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_setConnectionTimeout'.",&tolua_err);
#endif

    return 0;
}
int lua_neo_Loader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    neo::Loader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new neo::Loader();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"neo.Loader");
        return 1;
    }
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj = new neo::Loader(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"neo.Loader");
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cobj = new neo::Loader(arg0, arg1);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"neo.Loader");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Loader",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_neo_Loader_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_neo_Loader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Loader)");
    return 0;
}

int lua_register_neo_Loader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"neo.Loader");
    tolua_cclass(tolua_S,"Loader","neo.Loader","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"Loader");
        tolua_function(tolua_S,"new",lua_neo_Loader_constructor);
        tolua_function(tolua_S,"getFileName",lua_neo_Loader_getFileName);
        tolua_function(tolua_S,"getUrl",lua_neo_Loader_getUrl);
        tolua_function(tolua_S,"update",lua_neo_Loader_update);
        tolua_function(tolua_S,"getPath",lua_neo_Loader_getPath);
        tolua_function(tolua_S,"getConnectionTimeout",lua_neo_Loader_getConnectionTimeout);
        tolua_function(tolua_S,"setConnectionTimeout",lua_neo_Loader_setConnectionTimeout);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(neo::Loader).name();
    g_luaType[typeName] = "neo.Loader";
    g_typeCast["Loader"] = "neo.Loader";
    return 1;
}
TOLUA_API int register_all_neo(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"neo",0);
	tolua_beginmodule(tolua_S,"neo");

	lua_register_neo_GameHelper(tolua_S);
	lua_register_neo_Loader(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

