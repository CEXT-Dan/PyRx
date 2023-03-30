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
	PyRxApp.Printf("\nrun pydbdicttest :")
	   
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

def PyRxCmd_pydbdicttest():
	try:
		PyDbDictOpenForRead()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbDictOpenForRead():
	db = PyDb.DbHostApplicationServices().workingDatabase()  
	dictid = db.namedObjectsDictionaryId()
	dict = PyDb.DbDictionary(dictid,PyDb.OpenMode.ForRead)
	if dict.isNull():
		PyRxApp.Printf("\nFAIL")
	else:
		PyRxApp.Printf("\nPASS({})".format(dict.isA().name()))
	for (name,id) in dict.items():
		PyRxApp.Printf("\nitem({},{})".format(name,id ))	
	
	