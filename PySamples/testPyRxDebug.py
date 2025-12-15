import traceback

from pyrx import Ap, Db, Ge

# uncomment to set a break point manually
# import debugpy

print("added command = pytestdebug")

# 1- run the built-in command PYDEBUG, 
# 2- attach from VS code
# 3- setup the break point in pytestdebug
# 4- run pytestdebug

@Ap.Command()
def pytestdebug():
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
