import os
from time import perf_counter

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
	
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")
         
def PyRxCmd_pycmd():
	try: 
		PyDbBTR()
	except Exception as err:
		PyRxApp.Printf(err)
                
def PyDbBTR():
	try:
		t1_start = perf_counter()

		db = PyDb.DbHostApplicationServices().workingDatabase()  
		id = db.modelspaceId()
		btr = PyDb.DbBlockTableRecord.fromDbObject(PyDb.openDbObject(id, False))
		ids = btr.objectIds()
		numids = len(ids)

		t1_stop = perf_counter()
	
		PyRxApp.Printf("Elapsed time: {t:.4f}".format(t = t1_stop-t1_start))  
		PyRxApp.Printf("\nCount({})".format(numids))  

	except Exception as err:
		PyRxApp.Printf(err)
