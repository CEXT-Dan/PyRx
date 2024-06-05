import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx

print("added command = pycreate_hatch")

def PyRxCmd_pycreate_hatch():
    try: 
        db = Db.HostApplicationServices().workingDatabase()
       
        hatch = Db.Hatch()
        hatch.setDatabaseDefaults()
        normal = Ge.Vector3d(0,0,1)
        hatch.setNormal(normal)
        hatch.setElevation(0)
        
        hatch.setAssociative(False)
        
        hatch.setPattern(Db.HatchPatternType.kPreDefined, "SOLID")
        hatch.setHatchStyle(Db.HatchStyle.kNormal)
        
        vertexPts = []
        vertexPts.append(Ge.Point2d(2.0, 2.0))
        vertexPts.append(Ge.Point2d(8.0, 2.0))
        vertexPts.append(Ge.Point2d(8.0, 8.0))
        vertexPts.append(Ge.Point2d(2.0, 8.0))
        vertexPts.append(Ge.Point2d(2.0, 2.0))
        
        vertexBulges = []
        for n in range(len(vertexPts)):
            vertexBulges.append(0.0)
            
        hatch.appendLoopBulges(Db.HatchLoopType.kExternal, vertexPts, vertexBulges)
            
        cenPt = Ge.Point2d(5.0, 5.0)
        TWOPI = 2.0 * 3.1415926535897932
        cirArc = Ge.CircArc2d()
        cirArc.setCenter(cenPt)
        cirArc.setRadius(1.0)
        cirArc.setAngles(0.0, TWOPI)
        
        edgePtrs = []
        edgeTypes = []
 
        edgePtrs.append(cirArc)
        edgeTypes.append(Db.HatchEdgeType.kCirArc)
        
        hatch.appendLoopEdges(Db.HatchLoopType.kDefault, edgePtrs, edgeTypes)
        hatch.evaluateHatch()
        
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(hatch)      
    except Exception as err:
        print(err)