require "json"
require "Cocos2d"
require "Cocos2dConstants"

-- cclog
cclog = function(...)
    local txt = string.format(...)
    local http = cc.XMLHttpRequest:new()
    local url = "http://10.130.136.47/cocos/log.php"
    http:open("POST", url, true)
    http:send(string.format("log=%s", txt))
    print(txt)
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
    return msg
end

local dw = 1080
local dh = 1920

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
    local win = cc.Director:getInstance():getWinSizeInPixels()
    local sx, sy = win.width / dw, win.height / dh
    local scale = math.max(sx, sy)
    cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(dw,dh, cc.ResolutionPolicy.SHOW_ALL)
    cc.FileUtils:getInstance():addSearchPath("src")
    cc.FileUtils:getInstance():addSearchPath("res")
	cc.FileUtils:getInstance():addSearchResolutionsOrder("src");
	cc.FileUtils:getInstance():addSearchResolutionsOrder("res");
	
	require "DeprecatedEnum"
    require "DeprecatedClass"
    require "Deprecated"
    
    local helper = neo.GameHelper:getInstance()
    helper:init()
    
    require "version"
    cclog("version.lua:%s", _CURR_INSTALL_VERSION)
    helper:loadLocalVersion(_CURR_INSTALL_VERSION)
    
    require "IScene"
    require "update"
    
    local us = UpdateScene.new()
    local rs = cc.Director:getInstance():getRunningScene()

    if rs ~= nil then
        cc.Director:getInstance():replaceScene(us)
    else
        cc.Director:getInstance():runWithScene(us)
    end
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    error(msg)
end