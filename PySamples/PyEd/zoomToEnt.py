import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Ax

print("added comand pyzoom")
print("added comand pyzoomx")


@Ap.Command()
def pyzoom() -> None:
    try:
        ps, id, _ = Ed.Editor.entSel("\nSelect: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        ent = Db.Entity(id)
        ext = ent.getGeomExtents()
        v = ext.maxPoint() - ext.minPoint()

        view = Ed.Core.getCurrentView()
        view.setCenterPoint(Ge.Point2d(ext.midPoint().x, ext.midPoint().y))
        view.setWidth(v.length())
        view.setHeight(v.length())
        Ed.Core.setCurrentView(view)

    except Exception as err:
        traceback.print_exception(err)


import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Ax

@Ap.Command()
def pyzoomx() -> None:
    try:
        axapp = Ap.Application.acadApplication()
        
        ps, id, _ = Ed.Editor.entSel("\nSelect: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))
        
        ent = Db.Entity(id)
        ext = ent.getGeomExtents()
        
        v = ext.maxPoint() - ext.minPoint()
        axapp.zoomCenter(ext.midPoint(),v.length() )

    except Exception as err:
        traceback.print_exception(err)