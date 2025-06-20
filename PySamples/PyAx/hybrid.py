import traceback

from pyrx_imp import Ap, Ax, Db, Ed

print("added command PYHY_GETENT")
print("added command PYHY_GETENT2")
print("added command PYHY_GETDB")
print("PYHY_SIDEDB")

# It’s recommended not to mix Ax objects with Db objects.
# The reason is that Ax opens and closes database objects for each function call.
# Ax also locks/unlocks the document for each call.
#
# Ease of use VS performance
#
# While in the Db space, this becomes the programmers responsibility.
# This is one reason the Db space is much more performant, a database object my be
# open for write during multiple function calls. These states may conflict,
# e.g. Ax may close  and object previously opened for write in Db.
# This sample tries to show safe examples of using both


@Ap.Command("PYHY_GETENT")
def get_entity():
    try:
        ps, id, pnt = Ed.Editor.entSel("\nPick a line: \n", Db.Line.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oops! {}: ".format(ps))

        # use ObjectId.acadObject to get the Ax Object
        axLine = Ax.AcadLine.cast(id.acadObject())
        axLine.setTrueColor(Ax.AcadAcCmColor(0, 255, 0))
        print(axLine.objectName(), pnt)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command("PYHY_GETENT2")
def get_entity2():
    try:
        ps, id, pnt = Ed.Editor.entSel("\nPick a line: \n", Db.Line.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oops! {}: ".format(ps))
        
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axDoc.objectIdToObject(id)

        # use AcadDocument.objectIdToObject to get the Ax Object
        axLine = Ax.AcadLine.cast(axDoc.objectIdToObject(id))
        axLine.setTrueColor(Ax.AcadAcCmColor(255, 255, 0))
        print(axLine.objectName(), pnt)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command("PYHY_GETDB")
def get_getallentnames():
    try:
        db = Db.curDb()
        allEntNames = set()
        
        # this fuction returns Ax.AcadDatabase
        axDb = db.acadDatabase()
        for axEnt in axDb.modelSpace():
            allEntNames.add(axEnt.entityName())
        print(allEntNames)
    except Exception as err:
        traceback.print_exception(err)

# hybrid with side database, function doSomething adds a
# garbage scope. Python's GC is first open, first delete
# we dont want the database to be deleted first
@Ap.Command("PYHY_SIDEDB")
def get_getallentnames_from_side_db():
    try:
        sideDb = Db.Database(False, True)
        sideDb.readDwgFile("M:\\Dev\\Projects\\PyRxGit\\unitTests\\testmedia\\06457.dwg")
        sideDb.closeInput(True)
        doSomething(sideDb)
    except Exception as err:
        traceback.print_exception(err)

def doSomething(sideDb: Db.Database):
    allEntNames = set()
    
    # this fuction returns Ax.AcadDatabase
    axDb = sideDb.acadDatabase()
    for axEnt in axDb.modelSpace():
        allEntNames.add(axEnt.entityName())
    print(allEntNames)

