require "view.IView"

CocosView = class("CocosView", IView)

function CocosView:ctor(root)
    self.root = root
    
    
    local cache = cc.SpriteFrameCache:getInstance()
    local f = cache:getSpriteFrame(string.format("scene.OrangeWrap%04d", 0))
    local effect= cc.Sprite:createWithSpriteFrame(f)
    effect:setPosition(200,200)
    self.root:addChild(effect)
end