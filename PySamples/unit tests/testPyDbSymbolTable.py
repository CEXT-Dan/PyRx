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
	PyRxApp.Printf("\nrun pydbsymtabletest :")
	   
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

def PyRxCmd_pydbsymtabletest():
	try:
		PyDbSymOpenForRead()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbSymOpenForRead():
	db = PyDb.DbHostApplicationServices().workingDatabase()  
	btid = db.blockTableId()
	table = PyDb.DbSymbolTable(btid,PyDb.OpenMode.ForRead)
	if table.isNull():
		PyRxApp.Printf("\nFAIL")
	else:
		PyRxApp.Printf("\nPASS({})".format(table.isA().name()))
	for (id) in table.recordIds():
		PyRxApp.Printf("\nitem({})".format(id))	
	
	