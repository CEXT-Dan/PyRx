import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyGs as Gs

from timeit import default_timer as timer

# 0.1997940999990533 time to beat
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

# 0.18798900000001595 time to beat
def move_points_new():
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

    db = Db.HostApplicationServices().workingDatabase()
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForRead)

    desc = Db.Point.desc()
    for id in model.objectIds(desc):
        ent = Db.Entity(id, Db.OpenMode.ForWrite)
        ent.transformBy(mat)


# 0.2265791000027093 time to beat
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


def PyRxCmd_pydoit():
    try:
        for i in range(20):
            start = timer()
            move_points()
            end = timer()
            print(end - start)

    except Exception as err:
        print(err)


def PyRxCmd_pydoit2():
    try:
        for i in range(20):
            start = timer()
            move_points_old()
            end = timer()
            print(end - start)

    except Exception as err:
        print(err)


def PyRxCmd_pydoit3():
    try:
        for i in range(20):
            start = timer()
            move_points_new()
            end = timer()
            print(end - start)

    except Exception as err:
        print(err)
