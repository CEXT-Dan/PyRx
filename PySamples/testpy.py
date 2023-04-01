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
		putCOLOR()
	except Exception as err:
		PyRxApp.Printf(err)
		
def putXDATA():
	try:
		doc = PyAp.ApApplication().docManager().curDocument()
		ed = doc.editor()
		val = ed.entsel("\nSelect")
		if(val[2] == PyEd.PromptStatus.Normal):
			dbo = PyDb.DbObject(val[0], PyDb.OpenMode.ForWrite)
			xd = [(PyDb.DxfCode.DxfRegAppName, "DAN"),(PyDb.DxfCode.DxfXdXCoord, PyGe.Point3d(1,10,100))]
			dbo.setXData(xd)
			xdres = dbo.xData("DAN");
			PyRxApp.Printf(xdres)
			p = xdres[1][1].toString()
			PyRxApp.Printf(p)
	except Exception as err:
		PyRxApp.Printf(err)
		
def putCOLOR():
	doc = PyAp.ApApplication().docManager().curDocument()
	ed = doc.editor()
	val = ed.entsel("\nSelect")
	if(val[2] == PyEd.PromptStatus.Normal):
		e = PyDb.DbEntity(val[0], PyDb.OpenMode.ForWrite)
		c = PyDb.CmColor()
		c.setRGB(127,127,127)
		e.setColor(c,True,doc.database())
				