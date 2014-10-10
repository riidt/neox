
#include "lua_neo_manual.h"
#include "neo/Loader.h"
#include "CCLuaEngine.h"
#include "cocos2d.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"

USING_NS_CC;
using namespace neo;

class LuaLoaderDelegateProtocol:public Ref, public LoaderDelegateProtocol
{
public:
    virtual ~LuaLoaderDelegateProtocol()
    {}
    
    virtual void onProgress(int percent) override
    {
        int handler = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)this, ScriptHandlerMgr::HandlerType::LOADER_PROGRESS);
        if (0 != handler)
        {
            LuaLoaderEventData eventData(percent);
            BasicScriptData data((void*)this,&eventData);
            LuaEngine::getInstance()->handleEvent(ScriptHandlerMgr::HandlerType::LOADER_PROGRESS, (void*)&data);
        }
    }
    
    virtual void onSuccess() override
    {
        int handler = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)this, ScriptHandlerMgr::HandlerType::LOADER_SUCCESS);
        if (0 != handler)
        {
            LuaLoaderEventData eventData;
            BasicScriptData data((void*)this,&eventData);
            LuaEngine::getInstance()->handleEvent(ScriptHandlerMgr::HandlerType::LOADER_SUCCESS, (void*)&data);
        }
    }
    
    virtual void onError(Loader::ErrorCode errorCode) override
    {
        int handler = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)this, ScriptHandlerMgr::HandlerType::LOADER_ERROR);
        if (0 != handler)
        {
            LuaLoaderEventData eventData((int)errorCode);
            BasicScriptData data((void*)this,&eventData);
            LuaEngine::getInstance()->handleEvent(ScriptHandlerMgr::HandlerType::LOADER_ERROR, (void*)&data);
        }
    }
};

static int lua_neo_loader_setDelegate(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    Loader* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"neo.Loader",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (Loader*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'lua_neo_loader_setDelegate'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (2 == argc)
    {        
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(L, 2, "LUA_FUNCTION", 0, &tolua_err) ||
                !tolua_isnumber(L, 3, 0, &tolua_err) )
        {
                goto tolua_lerror;
        }
#endif
        LuaLoaderDelegateProtocol* delegate = dynamic_cast<LuaLoaderDelegateProtocol*>( self->getDelegate());
        if (nullptr == delegate)
        {
            delegate = new LuaLoaderDelegateProtocol();
            if (nullptr == delegate)
                return 0;
            
            self->setUserObject(delegate);
            self->setDelegate(delegate);
            delegate->release();
        }
        
        LUA_FUNCTION handler = toluafix_ref_function(L, 2, 0);
        ScriptHandlerMgr::HandlerType handlerType = (ScriptHandlerMgr::HandlerType) ((int)tolua_tonumber(L,3,0) + (int)ScriptHandlerMgr::HandlerType::LOADER_PROGRESS);
            
        ScriptHandlerMgr::getInstance()->addObjectHandler((void*)delegate, handler, handlerType);
        return 0;
    }
    
    CCLOG("'setDelegate' function of Loader has wrong number of arguments: %d, was expecting %d\n", argc, 2);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'setDelegate'.",&tolua_err);
    return 0;
#endif
}

static void extendLoader(lua_State* L)
{
    lua_pushstring(L, "neo.Loader");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "setDelegate", lua_neo_loader_setDelegate);
    }
    lua_pop(L, 1);
}


int register_all_neo_manual(lua_State* tolua_S)
{
    extendLoader(tolua_S);
    return 0;
}
