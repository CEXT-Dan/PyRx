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
    print("\nOnPyInitApp")
	
def OnPyUnloadApp():
    print("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
   print("\nOnPyLoadDwg")
   print("\nrun pydbatabasetest :")
	
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")
 
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
		print(err)
		
def PyDbGet():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		print("\nangbase = PASS({})".format(db.angbase()))
		print("\nangdir = PASS({})".format(db.angdir()))
		print("\nannoAllVisible = PASS({})".format(db.annoAllVisible()))
		
		p = db.extmin();
		print("\nextmin PASS({},{},{})".format(p.x, p.y, p.z))
		
		p = db.extmax();
		print("\nextmax PASS({},{},{})".format(p.x, p.y, p.z))
		
		print("\nlastSavedAsVersion = PASS({})".format(db.lastSavedAsVersion()))
		print("\nlastSavedAsMaintenanceVersion = PASS({})".format(db.lastSavedAsMaintenanceVersion()))

		print("\nlayerEval = PASS({})".format(db.layerEval()))

	except Exception as err:
		print(err)

def PyDbGetBlockTable():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		id = db.blockTableId()
		print("\nPyDbGetBlockTable = PASS({})".format(id.objectClass().name()))
	except Exception as err:
		print(err)

def PyDbIsA():
	try:
		db = Db.HostApplicationServices().workingDatabase()  
		print("\nPASS({})".format(db.isA().name()))  
	except Exception as err:
		print(err)
                
def PyHostApptestCopy():
	try:
		ha = PyDb.HostApplicationServices()
		db = ha.workingDatabase()  
		PrintDbPath(db)        
	except Exception as err:
		print(err)
		
def PyHostApptestNest():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		PrintDbPath(db)     
	except Exception as err:
		print(err)

def PyDatabaseReadDwg():
	try:
		db = PyDb.Database(False,False)
		db.readDwgFile("E:/Blocks/6036.dwg")
		dbcopy = db
		PrintDbPath(dbcopy)  
	except Exception as err:
		print(err)

def PrintDbPath(db):
	try:
		dbcopy = db
		print("\nPASS({})".format(dbcopy.getFilename()))      
	except Exception as err:
		print(err)
