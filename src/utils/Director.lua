require "utils.NumberUtils"
require "view.CocosView"
require "scene.MainScene"
require "scene.DemoScene"
require "scene.TerisScene"


local _scene = nil

local function updateScene() 
    if _scene then
        _scene:update(0.04)
    end 
end

local updateSchedule = cc.Director:getInstance():getScheduler():scheduleScriptFunc(updateScene, 0.04, false)

Director = {}
Director.replaceScene = function(scene)
    if _scene then
        _scene:onExit()
    end
    
    _scene = scene
    
    cc.Director:getInstance():replaceScene(scene)
    scene:onEnter()
end