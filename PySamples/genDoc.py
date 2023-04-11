import os
import inspect

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 

#just some ideas on getting help, work in progress

def PyRxCmd_pydoit():
	try:
		PyRxApp.Printf(dir(PyDb.Database))
		#PyRxApp.Printf(inspect.getmembers(PyDb))
		#PyRxApp.Printf(inspect.getsource(PyDb.DbObjectId))
		#PyRxApp.Printf(inspect.signature(collections.Counter))
		#PyRxApp.Printf(PyDb.PyDbEntity.setLayer.__doc__)
		#PyRxApp.Printf(inspect.getmembers(PyDb.DbEntity))
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyRxCmd_pydoit2():
	try:
		members = inspect.getmembers(PyDb.Entity)
		for x in members:
			  PyRxApp.Printf("\n{} ".format(x[0]))       
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyRxCmd_pydoit3():
	try:
		members = inspect.getmembers(PyDb)
		for x in members:
			  PyRxApp.Printf("\nName = {},{}\n.".format(x[0],x[1].__doc__))       
		
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyRxCmd_pydoit4():
	try:
		members = inspect.getmembers(PyDb.Dictionary)
		for x in members:
			  PyRxApp.Printf("\nName = {},{}\n.".format(x[0],x[1].__doc__))       
		
	except Exception as err:
		PyRxApp.Printf(err)