import traceback

from pyrx import Db, Ge

# uncomment to set a break point manually
# import debugpy

print("added command = pystartdebug")
print("added command = pytestdebug")

# run the built-in command PYDEBUG


def PyRxCmd_doit():
    try:
        # uncomment to set a break point manually
        # debugpy.breakpoint()

        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId())

        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

        _transformedPoints = [
            Db.Point(id, Db.OpenMode.kForWrite).transformBy(mat)
            for id in model.objectIds(Db.Point.desc())
        ]

    except Exception as err:
        traceback.print_exception(err)
