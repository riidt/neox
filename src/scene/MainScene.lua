cclog("hello2 file loaded")

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

------------------------------------------------------------------
--

C1 = class("C1", IScene)
C2 = class("C2", C1)

local c1 = C1.new()
local c2 = C2.new()
local s = cc.Scene:create()

cclog("object [%s] is [%s]:%s", "c1", "cc.Scene", c1:isTypeOf(cc.Scene))
cclog("object [%s] is [%s]:%s", "c1", "IScene", c1:isTypeOf(IScene))
cclog("object [%s] is [%s]:%s", "c1", "C1", c1:isTypeOf(C1))
cclog("object [%s] is [%s]:%s", "c2", "IScene", c2:isTypeOf(IScene))
cclog("object [%s] is [%s]:%s", "c2", "C1", c2:isTypeOf(C1))
cclog("object [%s] is [%s]:%s", "c2", "C2", c2:isTypeOf(C2))
cclog("object [%s] is [%s]:%s", "c1", "C2", c1:isTypeOf(C2))
--
------------------------------------------------------------------


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


ccs.ArmatureDataManager:getInstance():addArmatureFileInfoAsync("DragonBones_Tutorial_MultiBehavior.png", "DragonBones_Tutorial_MultiBehavior.plist", "DragonBones_Tutorial_MultiBehavior.xml", dataLoaded2)

cclog("scene/MainScene")