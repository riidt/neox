MainScene=class("MainScene", IScene)

function MainScene:ctor()
    local menu = cc.Menu:create()
    local visibleSize = cc.Director:getInstance():getVisibleSize()
    menu:setPosition(400, 400)
    self.menu = menu
    self:addChild(menu)
    
    self:buildMenu(6,"Level-6")
    self:buildMenu(5,"Level-5")
    self:buildMenu(4,"Level-4")
    self:buildMenu(3,"Level-3")
    self:buildMenu(1,"Demo")
    self:buildMenu(0,"About")
    
    local cache = cc.SpriteFrameCache:getInstance()

    --cache:addSpriteFrames("AssetTest.plist", "AssetTest.png")
    --cache:addSpriteFrames("gameItem.plist", "gameItem.png")
    cache:addSpriteFrames("orange.plist", "orange.png")
    
    --self:buildAnimation("scene.YellowWrap%04d", 48, 200, 170)
    
    self:buildAnimation("scene.OrangeColumn%04d", 29, 100, 270)
    --self:buildAnimation("scene.ColumnLight%04d", 17, 100, 270)
    self:buildAnimation("scene.OrangeLine%04d", 29, 100, 100)
    --self:buildAnimation("scene.LineLight%04d", 16, 100, 340)
    self:buildAnimation("scene.OrangeWrap%04d", 57, 150, 260)
    
    self:buildAnimation("effect.Explode%04d", 48, 100, 100)
    
end

function MainScene:buildAnimation(pattern, frames, x, y)
    local cache = cc.SpriteFrameCache:getInstance()
    local animFrames = {}
    for i = 1,frames do 
        local frame = cache:getSpriteFrame( string.format(pattern, i-1) )
        animFrames[i] = frame
    end

    local animation = cc.Animation:createWithSpriteFrames(animFrames, 0.04)

    local f = cache:getSpriteFrame(string.format(pattern, 0))
    local effect= cc.Sprite:createWithSpriteFrame(f)
    effect:runAction( cc.RepeatForever:create( cc.Animate:create(animation) ) )
    effect:setPosition(x, y)
    self:addChild(effect)
end

function MainScene:onEnter()
end

function MainScene:update(dt)
    
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