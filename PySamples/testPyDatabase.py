import os
import inspect

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
   PyRxApp.Printf("\nrun pydbatabasetest :")
	
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")
 
def PyRxCmd_pydbatabasetest():
	try:
		PyDbGet()
		PyDatabaseReadDwg()
		PyHostApptestCopy()
		PyHostApptestNest()
		PyDatabaseReadDwg()
		PyDbIsA()
		PyDbGetBlockTable()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbGet():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		PyRxApp.Printf("\nangbase = PASS({})".format(db.angbase()))
		PyRxApp.Printf("\nangdir = PASS({})".format(db.angdir()))
		PyRxApp.Printf("\nannoAllVisible = PASS({})".format(db.annoAllVisible()))
		
		p = db.extmin();
		PyRxApp.Printf("\nextmin PASS({},{},{})".format(p.x, p.y, p.z))
		
		p = db.extmax();
		PyRxApp.Printf("\nextmax PASS({},{},{})".format(p.x, p.y, p.z))
		
		PyRxApp.Printf("\nlastSavedAsVersion = PASS({})".format(db.lastSavedAsVersion()))
		PyRxApp.Printf("\nlastSavedAsMaintenanceVersion = PASS({})".format(db.lastSavedAsMaintenanceVersion()))

		PyRxApp.Printf("\nlayerEval = PASS({})".format(db.layerEval()))

	except Exception as err:
		PyRxApp.Printf(err)

def PyDbGetBlockTable():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		id = db.blockTableId()
		PyRxApp.Printf("\nPyDbGetBlockTable = PASS({})".format(id.objectClass().name()))
	except Exception as err:
		PyRxApp.Printf(err)

def PyDbIsA():
	try:
		db = Db.HostApplicationServices().workingDatabase()  
		PyRxApp.Printf("\nPASS({})".format(db.isA().name()))  
	except Exception as err:
		PyRxApp.Printf(err)
                
def PyHostApptestCopy():
	try:
		ha = PyDb.HostApplicationServices()
		db = ha.workingDatabase()  
		PrintDbPath(db)        
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyHostApptestNest():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		PrintDbPath(db)     
	except Exception as err:
		PyRxApp.Printf(err)

def PyDatabaseReadDwg():
	try:
		db = PyDb.Database(False,False)
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
