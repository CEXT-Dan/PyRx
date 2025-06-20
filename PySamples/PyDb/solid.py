import math

from pyrx_imp import Db, Ed, Ge


def PyRxCmd_pyproject():
    try:

        box =  Db.Solid3d() 
        box.setDatabaseDefaults()
        box.createBox(20.0,20.0,1.0)
        
        circle =  Db.Circle(Ge.Point3d(3.0,3.0,7.0),Ge.Vector3d(-0.537925, -0.651525, -0.534932), 1.0)
        ents = box.projectOnToSolid(circle, Ge.Vector3d(0.0,0.0,1.0))
        
        model = Db.BlockTableRecord(Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(box)
        
        for e in ents:
            model.appendAcDbEntity(e)
            
        print(box.getMassProp())
        
    except Exception as err:
        print(err)


def PyRxCmd_pyrevolve():
    try:
        entsel = Ed.Editor.entSel("\nSelect curve to revolve: ")
        if entsel[0] != Ed.PromptStatus.eNormal:
            return
        if not entsel[1].isDerivedFrom(Db.Curve.desc()):
            return

        pathsel = Ed.Editor.entSel("\nSelect Line: ")
        if pathsel[0] != Ed.PromptStatus.eNormal:
            return
        if not pathsel[1].isDerivedFrom(Db.Line.desc()):
            return

        curve = Db.Curve(entsel[1])
        line = Db.Line(pathsel[1])

        rob = Db.RevolveOptions()
        rob.setCloseToAxis(False)
        rob.setDraftAngle(0)
        rob.setTwistAngle(0)
        
        solid = Db.Solid3d()
        vec =  line.getEndPoint() - line.getStartPoint()
        solid.createRevolvedSolid(curve, line.getStartPoint(), vec , math.pi * 2, 0, rob)

        model = Db.BlockTableRecord(
            Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(solid)

    except Exception as err:
        print(err)


def PyRxCmd_pyextrudepath():
    try:
        entsel = Ed.Editor.entSel("\nSelect curve")
        if entsel[0] != Ed.PromptStatus.eNormal:
            return
        if not entsel[1].isDerivedFrom(Db.Curve.desc()):
            return

        pathsel = Ed.Editor.entSel("\nSelect path")
        if pathsel[0] != Ed.PromptStatus.eNormal:
            return
        if not pathsel[1].isDerivedFrom(Db.Curve.desc()):
            return

        curves = []
        curve = Db.Curve(entsel[1])
        curves.append(curve)
        regions = Db.Region.createFromCurves(curves)

        if len(regions) == 0:
            return

        path = Db.Curve(pathsel[1])
        solid = Db.Solid3d()
        solid.extrudeAlongPath(regions[0], path)
        model = Db.BlockTableRecord(
            Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(solid)

    except Exception as err:
        print(err)


def PyRxCmd_pyextrude():
    try:
        entsel = Ed.Editor.entSel("Select curve")
        if entsel[0] != Ed.PromptStatus.eNormal:
            return
        if not entsel[1].isDerivedFrom(Db.Curve.desc()):
            return

        curves = []
        curve = Db.Curve(entsel[1])
        curves.append(curve)
        regions = Db.Region.createFromCurves(curves)

        if len(regions) == 0:
            return

        solid = Db.Solid3d()
        solid.extrude(regions[0], 25.4)
        model = Db.BlockTableRecord(
            Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(solid)

    except Exception as err:
        print(err)
