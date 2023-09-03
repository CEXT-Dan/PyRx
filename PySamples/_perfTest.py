import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyGs as Gs
import timeit

#run this before release!!!
#PySamples\dwg\TestPoints.dwg

def move_points():
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

    db = Db.HostApplicationServices().workingDatabase()
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForRead)

    desc = Db.Point.desc()
    for id in model.objectIds():
        if id.isDerivedFrom(desc):
            ent = Db.Entity(id, Db.OpenMode.ForWrite)
            ent.transformBy(mat)

def move_points_new():
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

    db = Db.HostApplicationServices().workingDatabase()
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForRead)

    desc = Db.Point.desc()
    for id in model.objectIds(desc):
        ent = Db.Entity(id, Db.OpenMode.ForWrite)
        ent.transformBy(mat)

def move_points_old():
    try:
        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForRead)

        for id in model.objectIds():
            if id.objectClass().isDerivedFrom(Db.Point.desc()):
                ent = Db.Entity(id, Db.OpenMode.ForWrite)
                ent.transformBy(mat)

    except Exception as err:
        print(err)


# test move_points_new....     time = 7.21236990000034
# test move_points........     time = 8.443536700004188
# test move_points_old....     time = 10.899455000006128
def PyRxCmd_pyperftest():
    try:
        print("test move_points_new....\t time = {}".format(timeit.timeit(move_points_new, number=20)))
        print("test move_points........\t time = {}".format(timeit.timeit(move_points, number=20)))
        print("test move_points_old....\t time = {}".format(timeit.timeit(move_points_old, number=20)))
    except Exception as err:
        print(err)


