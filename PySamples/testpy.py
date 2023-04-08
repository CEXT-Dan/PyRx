import os
from time import perf_counter
from inspect import signature

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
		createLine()
	except Exception as err:
		PyRxApp.Printf(err)

def createLine():
	try:
		db = PyAp.ApApplication().docManager().curDocument().database()
		model = PyDb.DbBlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		line = PyDb.DbLine(PyGe.Point3d(0,0,0),PyGe.Point3d(100,100,0))
		circle = PyDb.DbCircle(PyGe.Point3d(0,0,0),PyGe.Vector3d.kZAxis, 100)
		model.appendAcDbEntity(line)
		model.appendAcDbEntity(circle)
	except Exception as err:
		PyRxApp.Printf(err)
		
def getSplitCurves():
	doc = PyAp.ApApplication().docManager().curDocument()
	ed = doc.editor()
	entres = ed.entsel("\nSelect")
	pntres = ed.getPoint("\nPoint On Curve")

	if(entres[2] == PyEd.PromptStatus.Normal):
		entId = entres[0]
		curve = PyDb.DbCurve(entId, PyDb.OpenMode.kForRead)
		pnt = pntres[0]
		param = curve.getParamAtPoint(pnt)
		params = [param]
		curves = curve.getSplitCurves(params)
		db =doc.database()
		model = PyDb.DbBlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		for x in curves:
			model.appendAcDbEntity(x)
		
def createDbp():
	try:
		db = PyAp.ApApplication().docManager().curDocument().database()
		model = PyDb.DbBlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
		dbp = PyDb.DbPoint(PyGe.Point3d(100,100,0))
		model.appendAcDbEntity(dbp)
	except Exception as err:
		PyRxApp.Printf(err)
		
def createDbps():
	try:
		objs = []
		for x in range(10000):
			objs.append(PyDb.DbPoint(PyGe.Point3d(x,x,0)))

		db = PyAp.ApApplication().docManager().curDocument().database()
		model = PyDb.DbBlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)

		for o in objs:
			model.appendAcDbEntity(o)
	except Exception as err:
		PyRxApp.Printf(err)

# (pylisp)
def PyRxLisp_pylisp(args):
	try: 
		return [(PyRx.LispDataType.kListBegin, 0),
	            (PyRx.LispDataType.kText, "Text"),
		        (PyRx.LispDataType.kDouble, 12.23),
			    (PyRx.LispDataType.kListBegin, 0),
			    (PyRx.LispDataType.kInt16, 1),
			    (PyRx.LispDataType.kInt32, 2),
			    (PyRx.LispDataType.kNil, 0),
			     (PyRx.LispDataType.kT_atom, 0),
			    (PyRx.LispDataType.kListEnd, 0),
		     	(PyRx.LispDataType.kPoint3d,PyGe.Point3d(1,10,100)),
				(PyRx.LispDataType.kListEnd, 0)]
	except Exception as err:
		PyRxApp.Printf(err)

#(pylisprt '("hello world" 1 2 3 4 (1 10 100)))
def PyRxLisp_pylisprt(args):
	try: 
		return args
	except Exception as err:
		PyRxApp.Printf(err)
