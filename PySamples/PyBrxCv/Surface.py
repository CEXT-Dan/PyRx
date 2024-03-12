import traceback
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Gs
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Cv

print("added command = CvCreateSurface")
print("added command = CvAddBreakline")
print("added command = CvAddBoundary")
print("added command = CvSurfaceList")

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

def PyRxCmd_CvCreateSurface() -> None:
    try:
        INNER_SURF_OFFSET = 10.0
        OUTER_SURF_OFFSET = 50.0
        
        points = []
        points.append(Ge.Point3d(-INNER_SURF_OFFSET, -INNER_SURF_OFFSET, 0))
        points.append(Ge.Point3d(INNER_SURF_OFFSET, -INNER_SURF_OFFSET, 0))
        points.append(Ge.Point3d(INNER_SURF_OFFSET, INNER_SURF_OFFSET, 0))
        points.append(Ge.Point3d(-INNER_SURF_OFFSET, INNER_SURF_OFFSET, 0))
 
        points.append(Ge.Point3d(-OUTER_SURF_OFFSET, -OUTER_SURF_OFFSET, 10))
        points.append(Ge.Point3d(OUTER_SURF_OFFSET, -OUTER_SURF_OFFSET, 10))
        points.append(Ge.Point3d(OUTER_SURF_OFFSET, OUTER_SURF_OFFSET, 10))
        points.append(Ge.Point3d(-OUTER_SURF_OFFSET, OUTER_SURF_OFFSET, 10))
        
        db = Db.curDb()
        pSurface = Cv.CvDbTinSurface()
        
        pSurface.initialize(
            Ge.Point3d(-OUTER_SURF_OFFSET, -OUTER_SURF_OFFSET, 0),
            Ge.Point3d(OUTER_SURF_OFFSET, OUTER_SURF_OFFSET, 10),
            100)
        
        successful = pSurface.addPoints(points)
        if not successful:
            print("Adding points to TIN Surface failed\n")
            return
        
        db.addToModelspace(pSurface)
 
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_CvAddBreakline() -> None:
    try:
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ",Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0])) 
            return

        constraints = []
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)

        points = []
        points.append(Ge.Point3d(-20, -20, 5))
        points.append(Ge.Point3d(-30, 0, 0))
        points.append(Ge.Point3d(-20, 20, -5))

        breakline1 = Cv.CvDbTinSurfaceBreakline(Cv.TinBreaklineType.eTinBreaklineNormal)
        breaklineId = 1007510122
        breakline1.setData(breaklineId, points)
        constraints.append(breakline1)

        pPolyline = Db.Polyline()
        pPolyline.addVertexAt(0, Ge.Point2d(20, -20), 0.5, -1.0, -1.0)
        pPolyline.addVertexAt(1, Ge.Point2d(30, 0), 0.0, -1.0, -1.0)
        pPolyline.addVertexAt(2, Ge.Point2d(20, 20), 0.0, -1.0, -1.0)
        pPolyline.setClosed(False)

        plid = db.addToModelspace(pPolyline)
        breakline2 = Cv.CvDbTinSurfaceBreakline(Cv.TinBreaklineType.eTinBreaklineNormal)
        breakline2.setDataId(plid,0.1)
        constraints.append(breakline2)

        successful = pSurface.addConstraints(constraints, True)
        if not successful:
            print("\nFailed to add constraints\n")
            return

        print(len(pSurface.getConstraints()))

    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_CvAddBoundary() -> None:
    try:
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ",Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0])) 
            return
        
        SHOW_BOUNDARY = 5.0
        HIDE_BOUNDARY = 9.0
        
        showBoundary = Cv.CvDbTinSurfaceBoundary(Cv.TinBoundaryType.eTinShow)
        hideBoundary = Cv.CvDbTinSurfaceBoundary(Cv.TinBoundaryType.eTinHide)
        
        showBoundaryPoints = []
        showBoundaryPoints.append(Ge.Point3d(-SHOW_BOUNDARY, -SHOW_BOUNDARY, 0))
        showBoundaryPoints.append(Ge.Point3d(SHOW_BOUNDARY, -SHOW_BOUNDARY, 0))
        showBoundaryPoints.append(Ge.Point3d(SHOW_BOUNDARY, SHOW_BOUNDARY, 0))
        showBoundaryPoints.append(Ge.Point3d(-SHOW_BOUNDARY, SHOW_BOUNDARY, 0))
        
        showBoundaryId = 1054400123
        showBoundary.setData(showBoundaryId, showBoundaryPoints)
        

        pPolyline = Db.Polyline()
        pPolyline.addVertexAt(0, Ge.Point2d(-HIDE_BOUNDARY, -HIDE_BOUNDARY), 0.0, -1.0, -1.0)
        pPolyline.addVertexAt(1, Ge.Point2d(HIDE_BOUNDARY, -HIDE_BOUNDARY), 0.5, -1.0, -1.0)
        pPolyline.addVertexAt(2, Ge.Point2d(HIDE_BOUNDARY, HIDE_BOUNDARY), 0.0, -1.0, -1.0)
        pPolyline.addVertexAt(3, Ge.Point2d(-HIDE_BOUNDARY, HIDE_BOUNDARY), 0.0, -1.0, -1.0)
        pPolyline.setClosed(True)

        plid = db.addToModelspace(pPolyline)
        hideBoundary.setDataId(plid, 0.1)
        
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)
        successful = pSurface.addConstraint(hideBoundary, True)
        if not successful:
            print("\nFailed to add hideBoundary\n")
            return
        
        successful = pSurface.addConstraint(showBoundary,True)
        if not successful:
            print("\nFailed to add showBoundary\n")
            return
        
    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_CvSurfaceList() -> None:
    try:
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ",Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0])) 
            return
        
        pSurface = Cv.CvDbTinSurface(esel[1])
        print('pointsCount',pSurface.pointsCount())
        print('trianglesCount',pSurface.trianglesCount())
        print('area2d',pSurface.area2d())
        print('area3d',pSurface.area3d())
        
        constraints = pSurface.getConstraints()
        for constraint in constraints:
            match constraint.constraintType():
                case Cv.TinConstraintType.eTinBreakline:
                    print('eTinBreakline')
                case Cv.TinConstraintType.eTinBoundary:
                    print('eTinBoundary')
                case Cv.TinConstraintType.eTinWall:
                    print('eTinWall')
                case _:
                    print('oops')
            
            print('is a database object: ',constraint.isDbResident())
                    
    except Exception as err:
        traceback.print_exception(err)
