require "teris.TerisGame"
TerisScene = class("TerisScene", IScene)

function TerisScene:ctor(colorNums)
    self.colorNums = colorNums
    local visibleSize = cc.Director:getInstance():getVisibleSize()
    local menu = cc.Menu:create()
    menu:setPosition(visibleSize.width-80, 40)
    menu:setAnchorPoint(0,0)
    self.menu = menu
    self:addChild(menu)
    
    self:buildBackButton()
    local view = CocosView.new(self)
    local game = TerisGame.new(view, colorNums)
    self.game= game
end

function TerisScene:onEnter()
    self.game:start()
end

function TerisScene:update(dt)
    self.game:update(dt)
end

function TerisScene:onExit()
    cclog("TerisScene onExit()")
end

function TerisScene:dispose()
    self.menu=nil
end

function TerisScene:buildBackButton()
    local item = nil
    local onSelectItem = function(tag,sender)
        Director.replaceScene(MainScene.new())
    end

    item = cc.MenuItemFont:create("Back")
    item:registerScriptTapHandler(onSelectItem)
    item:setFontSizeObj(40)
    item:setTag(0)
    self.menu:addChild(item)
    self.menu:alignItemsVertically()
end