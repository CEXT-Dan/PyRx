import os

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def PyRxCmd_pycreate_hatch():
    try: 
        db = PyDb.HostApplicationServices().workingDatabase()
       
        hatch = PyDb.Hatch()
        hatch.setDatabaseDefaults()
        normal = PyGe.Vector3d(0,0,1)
        hatch.setNormal(normal)
        hatch.setElevation(0)
        
        hatch.setAssociative(False)
        
        hatch.setPattern(PyDb.HatchPatternType.kPreDefined, "SOLID")
        hatch.setHatchStyle(PyDb.HatchStyle.kNormal)
        
        vertexPts = []
        vertexPts.append(PyGe.Point2d(2.0, 2.0))
        vertexPts.append(PyGe.Point2d(8.0, 2.0))
        vertexPts.append(PyGe.Point2d(8.0, 8.0))
        vertexPts.append(PyGe.Point2d(2.0, 8.0))
        vertexPts.append(PyGe.Point2d(2.0, 2.0))
        
        vertexBulges = []
        for n in range(len(vertexPts)):
            vertexBulges.append(0.0)
            
        hatch.appendLoopBulges(PyDb.HatchLoopType.kExternal, vertexPts, vertexBulges)
            
        cenPt = PyGe.Point2d(5.0, 5.0)
        TWOPI = 2.0 * 3.1415926535897932
        cirArc = PyGe.CircArc2d()
        cirArc.setCenter(cenPt)
        cirArc.setRadius(1.0)
        cirArc.setAngles(0.0, TWOPI)
        
        edgePtrs = []
        edgeTypes = []
 
        edgePtrs.append(cirArc)
        edgeTypes.append(PyDb.HatchEdgeType.kCirArc)
        
        hatch.appendLoopEdges(PyDb.HatchLoopType.kDefault, edgePtrs, edgeTypes)
        hatch.evaluateHatch()
        
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        model.appendAcDbEntity(hatch)      
    except Exception as err:
        PyRxApp.Printf(err)