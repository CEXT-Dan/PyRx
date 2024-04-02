import os
import PyDb as Db

dbs = {}

def loaddbs():
    global dbs
    mediapath = os.getcwd() + "\\testmedia\\"
    file_06457 = Db.HostApplicationServices().findFile(mediapath + "06457.dwg")
    dbs["06457"] = Db.Database(False, True)
    dbs["06457"].readDwgFile(file_06457)
    dbs["06457"].closeInput(True)
    
    file_TestPoints = Db.HostApplicationServices().findFile(mediapath + "TestPoints.dwg")
    dbs["TestPoints"] = Db.Database(False, True)
    dbs["TestPoints"].readDwgFile(file_TestPoints)
    dbs["TestPoints"].closeInput(True)
 
def cleardbs():
    global dbs
    dbs = None
    