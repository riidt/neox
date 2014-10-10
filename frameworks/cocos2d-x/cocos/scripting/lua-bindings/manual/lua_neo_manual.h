
#ifndef LUA_NEO_MANUAL_H
#define LUA_NEO_MANUAL_H

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "LuaScriptHandlerMgr.h"

TOLUA_API int register_all_neo_manual(lua_State* tolua_S);

struct LuaLoaderEventData
{
    int value;

    LuaLoaderEventData(int _value = 0):value(_value)
    {
    }
};


#endif // #ifndef LUA_NEO_MANUAL_H
