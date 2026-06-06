from pyrx import Ap, Db
import traceback

# when working with side dababases, it's important to make sure
# the database is diposed last

# other ideas
# https://discuss.python.org/t/add-using-scope/104613/4
# https://discuss.python.org/t/delay-gc-on-object/104602/9


@Ap.Command()
def doitscope():
    try:
        for file in Ap.Application.listFilesInPath("E:\\temp", ".dwg"):
            sdb = Db.Database(False, True)
            sdb.readDwgFile(file)
            sdb.closeInput(True)

            @Ap.using_scope()
            def _() -> None:
                ms = sdb.modelSpace()
                crvs = [Db.Curve(id) for id in ms.objectIds(Db.Curve.desc())]
                print(crvs)

    except Exception as err:
        print(err)


# option A, create a new function scope
def doSomething(sideDb: Db.Database):
    objHnd = Db.Handle("20128")
    objId = sideDb.getObjectId(False, objHnd)
    dbo = Db.DbObject(objId)
    print(dbo.isA().dxfName())


@Ap.Command()
def doitfuncscope():
    try:
        sideDb = Db.Database(False, True)
        sideDb.readDwgFile("M:/Dev/Projects/PyRxGit/tests/media/06457.dwg")
        sideDb.closeInput(True)
        doSomething(sideDb)
    except Exception:
        print(traceback.format_exc())


# option B, create a nested scope
@Ap.Command()
def doitnfuncscope():
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
@Ap.Command()
def pydoit3():
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
@Ap.Command()
def pydoit4():
    sideDb = Db.Database(False, True)
    sideDb.readDwgFile("M:/Dev/Projects/PyRxGit/unit tests/testmedia/06457.dwg")
    sideDb.closeInput(True)
    objHnd = Db.Handle("20128")
    objId = sideDb.getObjectId(False, objHnd)
    dbo = Db.DbObject(objId)
    print(dbo.isA().dxfName())
    dbo.dispose()


# use DbObjectCloseScope
def scope1():
    items_to_close: list[Db.DbObject] = []  # Pre-initialized list container
    db = Db.Database(False, True)
    db.readDwgFile("M:\\Dev\\Projects\\PyRxGit\\tests\\media\\06457.dwg")
    db.closeInput(True)
    with Db.DbObjectCloseScope(items_to_close):
        for id in db.modelSpace():
            ent = Db.Entity(id, Db.OpenMode.ForWrite)
            items_to_close.append(ent)


@Ap.Command()
def pydoit5():
    try:
        scope1()
    except Exception as err:
        traceback.print_exc()


# use DbObjectCloseScope.add
def scope2():
    db = Db.Database(False, True)
    db.readDwgFile("M:\\Dev\\Projects\\PyRxGit\\tests\\media\\06457.dwg")
    db.closeInput(True)
    with Db.DbObjectCloseScope() as tx_scope:
        for id in db.modelSpace():
            ent = Db.Entity(id, Db.OpenMode.ForWrite)
            tx_scope.add(ent)


@Ap.Command()
def pydoit6():
    try:
        scope2()
    except Exception as err:
        traceback.print_exc()
