import traceback
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Gs
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Cv
 
# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()
 
def PyRxCmd_CreateSurface() -> None:
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
 
 
def PyRxCmd_AddBreakline() -> None:
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
        pPolyline.addVertexAt(0, Ge.Point2d(20, -20), 0.5,0.0,0.0)
        pPolyline.addVertexAt(1, Ge.Point2d(30, 0), 0.0,0.0,0.0)
        pPolyline.addVertexAt(2, Ge.Point2d(20, 20), 0.0,0.0,0.0)
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
        
def PyRxCmd_SurfaceList() -> None:
    try:
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ",Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0])) 
            return
        
        pSurface = Cv.CvDbTinSurface(esel[1])

        print('pointsCount',pSurface.pointsCount(True) )
        print('trianglesCount',pSurface.trianglesCount(True) )
        print('area2d',pSurface.area2d(True) )
        print('area3d',pSurface.area3d(True) )
        
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