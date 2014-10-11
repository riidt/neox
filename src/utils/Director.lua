require "scene.MainScene"

Director = {}

Director.replaceScene = function(scene)
    local rs = cc.Director:getInstance():getRunningScene()
    
    cc.Director:getInstance():replaceScene(scene)
    scene:onEnter()
    
    rs:onExit()
end