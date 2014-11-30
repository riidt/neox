TerisGame = class("TerisGame")

function TerisGame:ctor(view, colorNums)
    self.view = view
    self.colorNums = colorNums
    
end

function TerisGame:dispose()
    self.view = nil
    self.colorNums = nil

end

function TerisGame:update(dt)
    --print("terisgame",  self.colorNums)
end

function TerisGame:start()
end

function TerisGame:onInput(code)
end