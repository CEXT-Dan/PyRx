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
		PyCurDocSelectAll()
		PyCurDocSelectAllFilter()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyCurDocSelectAll():
	try:
		app =  PyAp.ApApplication()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		val = ed.selectAll()
		if(val[1] == PyEd.PromptStatus.Normal):
			numids = len(val[0])
			PyRxApp.Printf("\nPASS numids({})".format(numids))
			for id in val[0]:
				PyRxApp.Printf("\nPASS({})".format(id.objectClass().name()))
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocSelectAllFilter():
	try:
		app =  PyAp.ApApplication()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		filter = [(PyDb.DxfCode.DxfStart,"CIRCLE")]
		val = ed.selectAll(filter)
		if(val[1] == PyEd.PromptStatus.Normal):
			numids = len(val[0])
			PyRxApp.Printf("\nPASS numids({})".format(numids))
			for id in val[0]:
				PyRxApp.Printf("\nPASS({})".format(id.objectClass().name()))
	except Exception as err:
		PyRxApp.Printf(err)

                