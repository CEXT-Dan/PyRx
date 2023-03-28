import os

import PyRxApp# = all the global methods like acutPrintf, 
import PyAp# = application, document classes services 
import PyRx# = Runtime runtime 
import PyGi# = Graphics interface
import PyGe# = Geometry
import PyDb# = database

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
		dbo = PyDb.openDbObject(id, False)
		if dbo.isNull():
			PyRxApp.Printf("\nFAIL")
		else:
		    PyRxApp.Printf("\nPASS({})".format(dbo.isA().name()))
	except Exception as err:
		PyRxApp.Printf(err)		