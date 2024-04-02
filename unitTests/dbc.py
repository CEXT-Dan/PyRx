import os
import PyDb as Db

dbs = {}

def loaddbs():
    mediapath = os.getcwd() + "\\testmedia\\"
    file = Db.HostApplicationServices().findFile(mediapath + "06457.dwg")
    dbs["06457"] = Db.Database(False, True)
    dbs["06457"].readDwgFile(file)
    dbs["06457"].closeInput(True)
 
def cleardbs():
    dbs = None
    