import os

import PyRxApp# = all the global methods like acutPrintf, 
import PyAp# = application, document classes services 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database

def OnPyInitApp():
    PyRxApp.Printf("\nOnPyInitApp")
	
def OnPyUnloadApp():
    PyRxApp.Printf("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
   PyRxApp.Printf("\nOnPyLoadDwg")
   PyRxApp.Printf("\nrun pydbatabasetest :")
	
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

def PyRxCmd_pydbatabasetest():
	try:
		PyDatabaseReadDwg()
		PyHostApptestCopy()
		PyHostApptestNest()
		PyDatabaseReadDwg()
		PyDbIsA()
		PyDbBT()
	except Exception as err:
		PyRxApp.Printf(err)

def PyDbBT():
	try:
		db = PyDb.DbHostApplicationServices().workingDatabase()  
		id = db.blockTableId()
		PyRxApp.Printf("\nPASS({})".format(id.objectClass().name()))
	except Exception as err:
		PyRxApp.Printf(err)

def PyDbIsA():
	try:
		db = PyDb.DbHostApplicationServices().workingDatabase()  
		PyRxApp.Printf("\nPASS({})".format(db.isA().name()))  
	except Exception as err:
		PyRxApp.Printf(err)
                
def PyHostApptestCopy():
	try:
		ha = PyDb.DbHostApplicationServices()
		db = ha.workingDatabase()  
		PrintDbPath(db)        
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyHostApptestNest():
	try:
		db = PyDb.DbHostApplicationServices().workingDatabase()  
		PrintDbPath(db)     
	except Exception as err:
		PyRxApp.Printf(err)

def PyDatabaseReadDwg():
	try:
		db = PyDb.DbDatabase()
		db.create(False,False)
		db.readDwgFile("E:/Blocks/6036.dwg")
		dbcopy = db
		PrintDbPath(dbcopy)  
	except Exception as err:
		PyRxApp.Printf(err)

def PrintDbPath(db):
	try:
		dbcopy = db
		PyRxApp.Printf("\nPASS({})".format(dbcopy.getFilename()))      
	except Exception as err:
		PyRxApp.Printf(err)
