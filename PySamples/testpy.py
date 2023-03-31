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
		PyDbGetHelpDoc()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbGetHelpDoc():	
	db = PyDb.DbHostApplicationServices().workingDatabase()  
	PyRxApp.Printf(db.wblock.__doc__)
#	for x in dir(PyDb):
#	   PyRxApp.Printf("\n(({}:{})".format(x, ""))

                