UpdateScene = class("UpdateScene", IScene)

function UpdateScene:ctor()
    cclog("update scene ctor.")
    self.helper = neo.GameHelper:getInstance()
    self.files = nil
    self.localFiles = nil
    self.updateList = {}
    self.progress = nil
    self.totalTasks = 1
    self.taskIndex = 0
    self.loopTask = nil
    self.latestConfig = nil
    self.updateSchedule = nil
    
    self:onEnter()
end

function UpdateScene:onEnter()
    cclog("update scene enter.")
    
    local visibleSize = cc.Director:getInstance():getVisibleSize()
    local origin = cc.Director:getInstance():getVisibleOrigin()

    local label = cc.Label:createWithSystemFont("Neo-X","sans",60)
    label:setAlignment(cc.TEXT_ALIGNMENT_CENTER)
    label:setWidth(visibleSize.width)
    label:setAnchorPoint(0,0)
    label:setPosition(0,visibleSize.height * .5 + 300)
    self:addChild(label)

    local progress = cc.Label:createWithSystemFont("0%","sans",40)
    progress:setAlignment(cc.TEXT_ALIGNMENT_CENTER)
    progress:setWidth(visibleSize.width)
    progress:setAnchorPoint(0,0)
    progress:setPosition(0,visibleSize.height * .5 + 250)
    self:addChild(progress)
    self.progress = progress
    
    
    
    local targetPlatform = cc.Application:getInstance():getTargetPlatform()
    if targetPlatform == cc.PLATFORM_OS_WINDOWS then
        performWithDelay(self,function() self:startGame() end,.1)
    else
        self:requestUpdateInfo()
    end
end

function UpdateScene:requestUpdateInfo()
    local lcfv = "file-version.json"
    local fp = cc.FileUtils:getInstance():fullPathForFilename(lcfv)
    local content = cc.FileUtils:getInstance():getStringFromFile(lcfv)
    self.localFiles = json.decode(content)
    
    local http = cc.XMLHttpRequest:new()
    local url = self.helper:getUpdateURL()
    http:open("GET", url, true)
    http:registerScriptHandler(function()
        if http.status == 200 then
            cclog("update config response")
            self.latestConfig = http.responseText
            cclog(string.format("response:%s", self.latestConfig))
            self.files = json.decode(self.latestConfig)
            cclog("local:%s, latest:%s", self.localFiles.ver, self.files.ver)
            if self.localFiles.ver < self.files.ver then
                self:updateGame()
            else
                self:startGame()
            end
        else
            cclog("version fail, %s", http.statusText)
            self:startGame()
        end
        --http:release()
    end)
    http:send(string.format("ver=%s", self.localFiles.ver))
end

function UpdateScene:update(dt)
    IScene.update(self, dt)
    cclog("update scene update")
   
    if #self.updateList == 0 then
        self:updateComplete()
        self:startGame()
    else
        self:updateProgress()
        local t = self.updateList[1]
        if t.done then
            table.remove(self.updateList,1)
            
            if #self.updateList == 0 then
                self:updateComplete()
                self:startGame()
            else
                self:updateFile(self.updateList[1])
            end
        end
    end
end

function UpdateScene:onExit()
    IScene.onExit(self)
    cclog("update scene exit.")
    
    if self.updateSchedule ~= nil then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.updateSchedule)
        self.updateSchedule = nil
    end
    
    self:dispose()
end

function UpdateScene:dispose()
    IScene.dispose(self)
    cclog("update scene dispose.")
    self.helper = nil
    self.files = nil
    self.localFiles = nil
    self.updateList = nil
    self.progress = nil
    self.totalTasks = 1
    self.taskIndex = 0
    self.loopTask = nil
    self.latestConfig = nil
    self.updateSchedule = nil
end

function UpdateScene:updateComplete()
    cclog("update complete")
    
    neo.GameHelper:writeStringToFile(string.format("_CURR_INSTALL_VERSION = %d", self.files.ver), self.helper:getLuaRoot() .. "version.lua")
    neo.GameHelper:writeStringToFile(self.latestConfig, string.format("%sfile-version.json", self.helper:getAssetRoot()))

end

function UpdateScene:updateGame()
    cclog("update")
    self:loopDirector("src")
    self:loopDirector("res")
    self.totalTasks = #self.updateList
    if self.totalTasks == 0 then
        self:updateComplete()
        self:startGame()
    else
        self:updateFile(self.updateList[1])
    end
    self.updateSchedule = cc.Director:getInstance():getScheduler():scheduleScriptFunc(function() self:update(.1) end, .1, false)
end

-----------
-- @see loopDirector
-----------
function UpdateScene:updateFile(entity)
    local loader;
    local function onProgress(p)
        cclog("progress %d", p)
    end

    local function onError()
        cclog("update error")
        --loader:release()
    end
    
    local function onComplete()
        self.taskIndex = self.taskIndex + 1
        self:updateProgress()
        cclog("%s complete", entity.f)
        entity.done = true
    end
    
    local url = string.format("%s%s/%s", self.helper:getCDN(), entity.src, entity.f);
    local save = string.format("%s/%s", entity.src, entity.f)
    cclog("load:%s to:%s", url, save)
    loader = neo.Loader:new(url, save)
    loader:setDelegate(onComplete, cc.LOADER_PROTOCOL_SUCCESS)
    loader:setDelegate(onProgress, cc.LOADER_PROTOCOL_PROGRESS)
    loader:setDelegate(onError, cc.LOADER_PROTOCOL_ERROR)
    loader:retain()
    loader:update()
end

function UpdateScene:startGame()
    local search = cc.FileUtils:getInstance():getSearchPaths()
    for key, var in ipairs(search) do
        cclog(string.format("%d:%s", key, var))
    end

    local search = cc.FileUtils:getInstance():getSearchResolutionsOrder()
    for key, var in ipairs(search) do
        cclog(string.format("%d:%s", key, var))
    end

    require "utils.Director"
    local ms = MainScene.new()
    Director.replaceScene(ms)
end

function UpdateScene:loopDirector(dir, saveDir)
    for i, entity in ipairs(self.files[dir]) do
        if entity.m ~= self:getLocalFileMd5(dir, entity.f) then
            local f = {}
            f.f = entity.f
            f.src = dir
            f.done = false
            table.insert(self.updateList,#self.updateList+1, f)
        end
    end
end

function UpdateScene:getLocalFileMd5(dir, file)
    for i, entity in ipairs(self.localFiles[dir]) do
        if file == entity.f then
            return entity.m
        end
    end
    
    return nil
end

function UpdateScene:updateProgress()
    local p = string.format("downloading... %d%% (%d/%d)", math.floor(self.taskIndex / self.totalTasks * 100), self.taskIndex, self.totalTasks)
    self.progress:setString(p)
end