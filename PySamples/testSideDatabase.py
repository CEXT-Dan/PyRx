from pyrx import Db


# option A, create a new function scope
def doSomething(sideDb: Db.Database):
    objHnd = Db.Handle("20128")
    objId = sideDb.getObjectId(False, objHnd)
    dbo = Db.DbObject(objId)
    print(dbo.isA().dxfName())


def PyRxCmd_pydoit1():
    sideDb = Db.Database(False, True)
    sideDb.readDwgFile("M:/Dev/Projects/PyRxGit/unit tests/testmedia/06457.dwg")
    sideDb.closeInput(True)
    doSomething(sideDb)


# option B, create a nested scope
def PyRxCmd_pydoit2():
    sideDb = Db.Database(False, True)
    sideDb.readDwgFile("M:/Dev/Projects/PyRxGit/unit tests/testmedia/06457.dwg")
    sideDb.closeInput(True)

    def using(sideDb: Db.Database):
        objHnd = Db.Handle("20128")
        objId = sideDb.getObjectId(False, objHnd)
        dbo = Db.DbObject(objId)
        print(dbo.isA().dxfName())

    using(sideDb)


# option c, try finally
def PyRxCmd_pydoit3():
    sideDb = Db.Database(False, True)
    sideDb.readDwgFile("M:/Dev/Projects/PyRxGit/unit tests/testmedia/06457.dwg")
    sideDb.closeInput(True)
    try:
        objHnd = Db.Handle("20128")
        objId = sideDb.getObjectId(False, objHnd)
        dbo = Db.DbObject(objId)
        print(dbo.isA().dxfName())
    finally:
        del dbo  # or dispose


# option D, call dispose
def PyRxCmd_pydoit4():
    sideDb = Db.Database(False, True)
    sideDb.readDwgFile("M:/Dev/Projects/PyRxGit/unit tests/testmedia/06457.dwg")
    sideDb.closeInput(True)
    objHnd = Db.Handle("20128")
    objId = sideDb.getObjectId(False, objHnd)
    dbo = Db.DbObject(objId)
    print(dbo.isA().dxfName())
    dbo.dispose()
