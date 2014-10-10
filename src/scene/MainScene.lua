cclog("hello2 file loaded")


function isTypeOf(instance, superClass)
    return false
end

local sceneGame = cc.Scene:create()

cclog("hello2 create panel")
local panel = ccs.GUIReader:getInstance():widgetFromJsonFile("NewProject_1.json")
cclog("set checkbox")
local cb = panel:getChildByName("CheckBox_24")
cb:setTouchEnabled(true)
cb:addEventListener(function(sender, eventType) 
    if eventType == ccui.CheckBoxEventType.selected then
        cb:setSelectedState(true)
    elseif eventType == ccui.CheckBoxEventType.unselected then
        cb:setSelectedState(false)
    end
end)

local btn = panel:getChildByName("Button_23")
btn:setTouchEnabled(true)
btn:addTouchEventListener(function(sender, eventType) 
    btn:setTitleText("click")

end)


panel:setPosition(50,200)
sceneGame:addChild(panel)

local rs = cc.Director:getInstance():getRunningScene()

cclog("object [%s] is [%s]:%s", rs, "IScene", isTypeOf(rs, IScene))

if rs ~= nil then
    cc.Director:getInstance():replaceScene(sceneGame)
else
    cc.Director:getInstance():runWithScene(sceneGame)
end

local function dataLoaded2(percent)
    if percent >= 1 then
        local armature = ccs.Armature:create("Dragon")
        armature:getAnimation():play("walk")
        armature:getAnimation():setSpeedScale(.5)
        armature:setPosition(150, 550)
        sceneGame:addChild(armature)


--        local armature = ccs.Armature:create("Dragon")
--        armature:getAnimation():play("stand")
--        armature:getAnimation():setSpeedScale(.5)
--        armature:setPosition(150, 150)
--        sceneGame:addChild(armature)
        
    end
end


--ccs.ArmatureDataManager:getInstance():addArmatureFileInfoAsync("DragonBones_Tutorial_MultiBehavior.png", "DragonBones_Tutorial_MultiBehavior.plist", "DragonBones_Tutorial_MultiBehavior.xml", dataLoaded2)

cclog("scene/MainScene")