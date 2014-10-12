DemoScene=class("DemoScene", IScene)

function DemoScene:ctor()
    local panel = ccs.GUIReader:getInstance():widgetFromJsonFile("NewProject_1.json")

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
        Director.replaceScene(MainScene.new())
    end)


    panel:setPosition(50,200)
    self:addChild(panel)
end

function DemoScene:onEnter()
    local function dataLoaded2(percent)
        if percent >= 1 then
            local armature = ccs.Armature:create("Dragon")
            armature:getAnimation():play("walk")
            armature:getAnimation():setSpeedScale(.5)
            armature:setPosition(150, 550)
            self:addChild(armature)


            --        local armature = ccs.Armature:create("Dragon")
            --        armature:getAnimation():play("stand")
            --        armature:getAnimation():setSpeedScale(.5)
            --        armature:setPosition(150, 150)
            --        sceneGame:addChild(armature)

        end
    end


    ccs.ArmatureDataManager:getInstance():addArmatureFileInfoAsync("DragonBones_Tutorial_MultiBehavior.png", "DragonBones_Tutorial_MultiBehavior.plist", "DragonBones_Tutorial_MultiBehavior.xml", dataLoaded2)
end

function DemoScene:update(dt)
    cclog("DemoScene update", dt)
end

function DemoScene:onExit()
    cclog("DemoScene onExit()")
end

function DemoScene:dispose()
    cclog("DemoScene dispose()")
end