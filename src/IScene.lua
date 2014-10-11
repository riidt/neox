IScene = class("IScene", 
    function() 
        local s = cc.Scene:create()
        return s;
    end
)

function IScene:onEnter()
    cclog("IScene onEnter()")
end

function IScene:update(dt)
    cclog("IScene update", dt)
end

function IScene:onExit()
    cclog("IScene onExit()")
end

function IScene:dispose()
    cclog("IScene dispose()")
end
