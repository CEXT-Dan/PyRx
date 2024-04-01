import os
import PyDb as Db

mediapath = os.getcwd() + "\\testmedia\\"
print(mediapath)

dbs = {}

def loaddbs():
    file = Db.HostApplicationServices().findFile(mediapath + "06457.dwg")
    print(file)
    dbs["06457"] = Db.Database(False, True)
    dbs["06457"].readDwgFile(file)
    dbs["06457"].closeInput(True)
    print("06457 is open")
    
def cleardbs():
    dbs = None
    