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
		#getSplitCurves()
		createDbps()
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
		#for x in curves:
			#model.appendAcDbEntity(x)
		

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