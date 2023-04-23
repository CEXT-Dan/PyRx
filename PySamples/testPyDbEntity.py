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
   PyRxApp.Printf("\nrun pydbentitytest :")
	
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

def PyRxCmd_pydbentitytest():
	try:
		PyDbObjectOpenForRead()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbObjectOpenForRead():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		id = db.blockTableId()
		dbo = PyDb.DbObject(id, PyDb.OpenMode.kForRead)
		if dbo.isNull():
			PyRxApp.Printf("\nFAIL")
		else:
		    PyRxApp.Printf("\nPASS({})".format(dbo.isA().name()))
	except Exception as err:
		PyRxApp.Printf(err)		