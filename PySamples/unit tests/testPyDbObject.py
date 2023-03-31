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
	PyRxApp.Printf("\nrun pydbobjecttest :")
	   
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

def PyRxCmd_pydbobjecttest():
	try:
		PyDbObjectOpenForRead()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbObjectOpenForRead():
	try:
		db = PyDb.DbHostApplicationServices().workingDatabase()  
		id = db.blockTableId()
		dbo = PyDb.openDbObject(id, PyDb.OpenMode.ForRead)
		if dbo.isNull():
			PyRxApp.Printf("\nFAIL")
		else:
		    PyRxApp.Printf("\nPASS({})".format(dbo.isA().name()))
	except Exception as err:
		PyRxApp.Printf(err)		