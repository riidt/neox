MainScene=class("MainScene", IScene)

function MainScene:ctor()
    local menu = cc.Menu:create()
    local visibleSize = cc.Director:getInstance():getVisibleSize()
    menu:setPosition(visibleSize.width * .5, visibleSize.height * .5)
    self.menu = menu
    self:addChild(menu)
    
    self:buildMenu(6,"Level-6")
    self:buildMenu(5,"Level-5")
    self:buildMenu(4,"Level-4")
    self:buildMenu(3,"Level-3")
    self:buildMenu(1,"Demo")
    self:buildMenu(0,"About")
end

function MainScene:onEnter()
end

function MainScene:update(dt)
    cclog("MainScene update", dt)
end

function MainScene:onExit()
    
end

function MainScene:dispose()
    self.menu = nil
end

function MainScene:onSelectItem(tag)
    local item = self.menu:getChildByTag(tag)
    if tag == 0 then
        item:setString("riidt@riidt.com")
    elseif tag == 1 then
        Director.replaceScene(DemoScene.new())
    else
        Director.replaceScene(TerisScene.new(tag))
    end
end

function MainScene:buildMenu(tag, title)

    local item = nil
    local onSelectItem = function(tag,sender)
        self:onSelectItem(tag)
    end

    item = cc.MenuItemFont:create(title)
    item:registerScriptTapHandler(onSelectItem)
    item:setFontSizeObj(40)
    item:setTag(tag)
    self.menu:addChild(item)
    self.menu:alignItemsVertically()
end