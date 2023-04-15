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
		module = inspect.getmodule(PyGe);
		for members_1 in inspect.getmembers(module):
			PyRxApp.Printf("\n{}".format(members_1[0]))
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

def PyRxCmd_pydoit5():
	try:
		module = inspect.getmodule(PyDb);
		for members_1 in inspect.getmembers(module):
			PyRxApp.Printf("\n{}\n".format(members_1[0]))
			if inspect.isclass(members_1[1]):
				members_2 = inspect.getmembers(members_1[1])
				for x in members_2:
					if not x[0].startswith("__"):
						PyRxApp.Printf("{} ".format(x[0]))  
	except Exception as err:
		PyRxApp.Printf(err)