import os
import os.path
import shutil 
import re
import sys
import json
import md5

from zipfile import * 
import zipfile 

vf = "../src/version.lua"
filehandler = open(vf,"r")
version = filehandler.read()
filehandler.close()
match = re.match(r'_CURR_INSTALL_VERSION = (\d+)', version, re.M|re.I)
version = int(match.group(1)) + 1
#content = '_CURR_INSTALL_VERSION = {}'.format(version)

#filehandler = open(vf, "w+")
#filehandler.write(content)
#filehandler.close()

def getMD5(strFile):
    fh = open(strFile, "r")
    m = md5.md5()
    strRead = ""

    while True:
        strRead = fh.read(8096)
        if not strRead:
            fh.close()
            break
        m.update(strRead)
    return m.hexdigest()



def zipSrc(folder):
    os.chdir(folder)
    srcDir = "."
    config = []
    for dirpath, dirnames, filenames in os.walk(srcDir):
        #print(dirpath)
        #for dirname in dirnames:
            #print(dirname)
            #f.write(os.path.join(dirpath,dirname)) 
        for filename in filenames:
            entity = {}
            f = os.path.join(dirpath,filename)
            entity["f"] = f.replace("\\", "/").replace("./", "")
            entity["m"] = getMD5(f)
            config.append(entity)

    os.chdir("../")
    return config

os.chdir("../")

config = {}
config["src"] = zipSrc("src")
config["res"] = zipSrc("res")
config["ver"] = version

fm = "file-version-" + str(version) + ".json"
save = "tools/" + fm
jsonData = json.dumps(config)
filehandler = open(save, "w+")
filehandler.write(jsonData)
filehandler.close()

#save = "res/file-version.json"
#filehandler = open(save, "w+")
#filehandler.write(jsonData)
#filehandler.close()

shutil.copy(save, "E:/wwwroot/cocos/" + fm)

if os.path.isdir("E:/wwwroot/cocos/updateRoot/"):
    shutil.rmtree("E:/wwwroot/cocos/updateRoot/")

os.mkdir(r'E:/wwwroot/cocos/updateRoot/')

shutil.copytree("src", "E:/wwwroot/cocos/updateRoot/src")
shutil.copytree("res", "E:/wwwroot/cocos/updateRoot/res")

wwwVerFile = "E:/wwwroot/cocos/ver.txt"
filehandler = open(wwwVerFile, "w+")
filehandler.write(str(version))
filehandler.close()