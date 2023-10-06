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

import AcadComTypes24 as Ac
import ComAcadApplication24 as AcadApp

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


theApp = Ac.getApp()

def move_points_com():
    
        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
        comMat = Ac.comMatrix3d(mat)

        for ent in theApp.ActiveDocument.ModelSpace:
            if ent.ObjectName == "AcDbPoint":
                ent.TransformBy(comMat)


print("OldTest:..")
print("test move_points_new....     time = 3.7837103999991086")
print("test move_points........     time = 3.9697672000038438")
print("test move_points_old....     time = 4.44495850000385")
print("test move_points_com....     time = 20.55892379999932")

print("\nrun command pyperftest")

def PyRxCmd_pyperftest():
    try:
        print("test move_points_new....\t time = {}".format(timeit.timeit(move_points_new, number=20)))
        print("test move_points........\t time = {}".format(timeit.timeit(move_points, number=20)))
        print("test move_points_old....\t time = {}".format(timeit.timeit(move_points_old, number=20)))
        print("test move_points_com....\t time = {}".format(timeit.timeit(move_points_com, number=20)))
    except Exception as err:
        print(err)


