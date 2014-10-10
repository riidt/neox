import os
import os.path
import shutil 
import re
import sys

from zipfile import * 
import zipfile 

vf = "E:/wwwroot/cocos/version.php"
version = open(vf,"r").read()
match = re.match(r'.*\necho "(\d+)\.(\d+)\.(\d+)"', version, re.M|re.I)
version = "{0}.{1}.{2}".format(match.group(1), match.group(2), int(match.group(3)) + 1)
content = '<?php \necho "{}";'.format( version)

open(vf, "w+").write(content)




def zipSrc():
    f = zipfile.ZipFile('dynimic.zip','w',zipfile.ZIP_DEFLATED)
    os.chdir("src/dynimic")
    srcDir = "."
    for dirpath, dirnames, filenames in os.walk(srcDir):
        print(dirpath)
        #for dirname in dirnames:
            #print(dirname)
            #f.write(os.path.join(dirpath,dirname)) 
        for filename in filenames:
            print(filename)
            f.write(os.path.join(dirpath,filename)) 
    f.close()


zipSrc()

shutil.copy("../../dynimic.zip", "E:/wwwroot/cocos/cocos.zip")