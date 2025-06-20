import timeit

from pyrx import Ap, Db, Ge

# run this before release!!!
# PySamples\dwg\TestPoints.dwg


# calls Db.Point.desc() every loop
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


# caches Db.Point.desc()
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


# uses model.objectIds(desc) instead of
# if id.isDerivedFrom(desc):
def move_points_new():
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
    db = Db.curDb()
    model = Db.BlockTableRecord(db.modelSpaceId())
    for id in model.objectIds(Db.Point.desc()):
        ent = Db.Entity(id, Db.OpenMode.ForWrite)
        ent.transformBy(mat)


# model is iterable
def move_points_iter():
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
    db = Db.curDb()
    model = Db.BlockTableRecord(db.modelSpaceId())
    for id in model:
        ent = Db.Entity(id, Db.OpenMode.ForWrite)
        ent.transformBy(mat)


def move_points_com_iter():
    objType = "AcDbPoint"
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    for e in axDoc.modelSpace():
        if e.objectName() == objType:
            e.transformBy(mat)


def move_points_com():
    objType = "AcDbPoint"
    mat = Ge.Matrix3d()
    mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    axSpace = axDoc.modelSpace()
    for e in axSpace.entities():
        if e.objectName() == objType:
            e.transformBy(mat)


print("OldTest:..")
print("test move_points_new....     time = 3.5414436000000933")
print("test move_points........     time = 3.7101225000005797")
print("test move_points_old....     time = 4.271034999999756")
print("test move_points_iter....    time = 4.271034999999756")
print("test move_points_com_old.... time = 18.48414749999938")
print("test move_points_com....     time = 6.254062799998792")
print("test move_points_com_iter....time = 6.430184000004374")

print("\nrun command pyperftest")


def PyRxCmd_pyperftest():
    try:
        nruns = 20
        print(
            "test move_points_new....\t time = {}".format(
                timeit.timeit(move_points_new, number=nruns)
            )
        )
        print(
            "test move_points........\t time = {}".format(timeit.timeit(move_points, number=nruns))
        )
        print(
            "test move_points_old....\t time = {}".format(
                timeit.timeit(move_points_old, number=nruns)
            )
        )
        print(
            "test move_points_iter...\t time = {}".format(
                timeit.timeit(move_points_iter, number=nruns)
            )
        )
        print(
            "test move_points_com....\t time = {}".format(
                timeit.timeit(move_points_com, number=nruns)
            )
        )
        print(
            "test move_points_com_iter....\t time = {}".format(
                timeit.timeit(move_points_com_iter, number=nruns)
            )
        )
    except Exception as err:
        print(err)
