import traceback
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

import PyRxDebug


def PyRxCmd_pystartdebug():
    PyRxDebug.startListener()


# sample vs code config
# {
#     "name": "Remote Attach",
#     "type": "python",
#     "request": "attach",
#     "port": 5678,
#     "host": "127.0.0.1",
#     "justMyCode": false
# }


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
