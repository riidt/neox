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

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
    cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(1080,1920, 1)
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