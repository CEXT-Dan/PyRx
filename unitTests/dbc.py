import os
import PyDb as Db

dbs = {}

mediapath = os.getcwd() + "\\testmedia\\"

def loaddbs():
    global mediapath
    mediapath = os.getcwd() + "\\testmedia\\"
    file_06457 = Db.HostApplicationServices().findFile(mediapath + "06457.dwg")
    dbs["06457"] = Db.Database(False, True)
    dbs["06457"].readDwgFile(file_06457)
    dbs["06457"].closeInput(True)
    
    file_TestPoints = Db.HostApplicationServices().findFile(mediapath + "TestPoints.dwg")
    dbs["TestPoints"] = Db.Database(False, True)
    dbs["TestPoints"].readDwgFile(file_TestPoints)
    dbs["TestPoints"].closeInput(True)
    
    file_subentpe = Db.HostApplicationServices().findFile(mediapath + "subentpe.dwg")
    dbs["subentpe"] = Db.Database(False, True)
    dbs["subentpe"].readDwgFile(file_subentpe)
    dbs["subentpe"].closeInput(True)
    
    file_ebim1 = Db.HostApplicationServices().findFile(mediapath + "example project location.dwg")
    dbs["ebim1"] = Db.Database(False, True)
    dbs["ebim1"].readDwgFile(file_ebim1)
    dbs["ebim1"].closeInput(True)
 
def cleardbs():
    global dbs
    dbs = {}
    