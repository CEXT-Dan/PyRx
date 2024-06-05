import traceback
from pyrx_imp import Rx, Ge, Gs, Gi, Db, Ap, Ed

def PyRxCmd_pystartdebug():
    import PyRxDebug
    PyRxDebug.startListener()

def PyRxCmd_doit():
    try:
        # set a break point
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId())

        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

        transformedPoints = [
            Db.Point(id, Db.OpenMode.kForWrite).transformBy(mat)
            for id in model.objectIds(Db.Point.desc())
        ]

    except Exception as err:
        traceback.print_exception(err)
