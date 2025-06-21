from pyrx import Db


# Db.LayoutManager.getLayouts
def remoteDb(path: str):
    db = Db.Database(False, True)
    db.readDwgFile(path)
    db.closeInput(True)
    try:
        man = Db.LayoutManager()
        token = man.setupForLayouts(db)
        print(man.getLayouts(db))
    finally:
        man.clearSetupForLayouts(token)


def PyRxCmd_doit():
    try:
        man = Db.LayoutManager()
        print(man.getLayouts())
        remoteDb("E:/06457Submittal.dwg")
    except Exception as err:
        print(err)
