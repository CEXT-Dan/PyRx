import os

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor
def OnPyInitApp():
    PyRxApp.Printf("\nOnPyInitApp")

def OnPyUnloadApp():
   PyRxApp.Printf("\nOnPyUnloadApp")

def OnPyLoadDwg():
   PyRxApp.Printf("\nOnPyLoadDwg")

def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")
         
def PyRxCmd_pycmd():
	try: 
		createPolyLine()
	except Exception as err:
		PyRxApp.Printf(err)
		
def printItem():
	p = PyGe.Point3d(0,0,0)
	print(p)

def createPolyLine():
	try:
		db = PyAp.Application().docManager().curDocument().database()
		model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		pline = PyDb.Polyline(4)
		pline.setDatabaseDefaults()
		pline.addVertexAt(0, PyGe.Point2d(0,0),0,0,0)
		pline.addVertexAt(1, PyGe.Point2d(100,0),0,0,0)
		pline.addVertexAt(2, PyGe.Point2d(100,100),3,0,0)
		pline.addVertexAt(3, PyGe.Point2d(0,100),0,0,0)
		pline.setClosed(True)
		model.appendAcDbEntity(pline)

		if pline.segType(2) == PyDb.SegType.kArc:
			circArc2d = pline.getArcSeg2dAt(2)
			print(circArc2d.type())
			print(circArc2d.hasStartPoint())
			print(circArc2d.hasEndPoint())
			print(circArc2d.isOn(PyGe.Point2d(50,250)))
			param = circArc2d.paramOf(PyGe.Point2d(50,250))
			print(param)

			curves = circArc2d.getSplitCurves(param)
			print(curves)
			print(curves[0].hasStartPoint())
			print(curves[0].hasEndPoint())
			print(curves[1].hasStartPoint())
			print(curves[1].hasEndPoint())

			print(curves[0].type())
			print(curves[1].type())
			print(curves[0].getEndPoint() == curves[1].getStartPoint())
			curves[0].reverseParam()
			curves[1].reverseParam()
			print(curves[1].getEndPoint() == curves[0].getStartPoint())

	except Exception as err:
		PyRxApp.Printf(err)
	
def createLine():
	try:
		db = PyAp.Application().docManager().curDocument().database()
		model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		line = PyDb.Line(PyGe.Point3d(0,0,0),PyGe.Point3d(100,100,0))
		circle = PyDb.Circle(PyGe.Point3d(0,0,0),PyGe.Vector3d.kZAxis, 100)

		lplane = line.getPlane()
		cplane = circle.getPlane()

		print(lplane.type())
		print(cplane.type())

		model.appendAcDbEntity(line)
		model.appendAcDbEntity(circle)
	except Exception as err:
		PyRxApp.Printf(err)
		
def getSplitCurves():
	doc = PyAp.Application().docManager().curDocument()
	ed = doc.editor()
	entres = ed.entsel("\nSelect")
	pntres = ed.getPoint("\nPoint On Curve")

	if(entres[2] == PyEd.PromptStatus.Normal):
		entId = entres[0]
		curve = PyDb.Curve(entId, PyDb.OpenMode.kForRead)
		pnt = pntres[0]
		param = curve.getParamAtPoint(pnt)
		params = [param]
		curves = curve.getSplitCurves(params)
		db = doc.database()
		model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		for x in curves:
			model.appendAcDbEntity(x)
		
def createDbp():
	try:
		db = PyAp.Application().docManager().curDocument().database()
		model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		dbp = PyDb.DbPoint(PyGe.Point3d(100,100,0))
		model.appendAcDbEntity(dbp)
	except Exception as err:
		PyRxApp.Printf(err)
		
def createDbps():
	try:
		objs = []
		for x in range(10000):
			objs.append(PyDb.DbPoint(PyGe.Point3d(x,x,0)))

		db = PyAp.Application().docManager().curDocument().database()
		model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)

		for o in objs:
			model.appendAcDbEntity(o)
	except Exception as err:
		PyRxApp.Printf(err)
