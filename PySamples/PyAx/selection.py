import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed, Ax

print("added command PYAX_GETENT")
print("added command PYAX_GETSUBENT")


@Ap.Command("PYAX_GETENT")
def get_entity():
    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axUtil = axDoc.utility()
        axEnt, pnt = axUtil.getEntity("\nPick a line")
        if axEnt.objectName() != "AcDbLine":
            raise RuntimeError("oops!: ")

        # with Ax objects, a cast is required
        # Ax objects, differ from pyrx objects in that you don't need 
        # to open kForRead/kForWrite, the caveat is AxObjects are slower
        
        axLine = Ax.AcadLine.cast(axEnt)
        axLine.setTrueColor(Ax.AcadAcCmColor(0, 255, 0))
        print(axEnt.objectName(), pnt)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command("PYAX_GETSUBENT")
def get_subentity():
    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axUtil = axDoc.utility()
        ent, pnt, xf, ids = axUtil.getSubEntity("\nPick it")
        print(ent.objectName(), pnt, xf, ids)
    except Exception as err:
        traceback.print_exception(err)
