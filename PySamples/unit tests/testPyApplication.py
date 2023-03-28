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
   PyRxApp.Printf("\nrun pyapptest :")
	
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")
   
def PyRxCmd_pyapptest():
	try:
		PyCurDocSelectAll()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyCurDocTest():
	try:
		db = PyAp.ApApplication().docManager().curDocument().database() 
		PyRxApp.Printf("\nPASS({})".format(db.getFilename())) 
	except Exception as err:
		PyRxApp.Printf(err)


def PyCurDocEdTest1():
	try:
		val = PyAp.ApApplication().docManager().curDocument().editor().getInteger("\nEnter an int")
		if(val[1] == PyEd.PromptStatus.Normal):
			PyRxApp.Printf("\nPASS({})".format(val[0])) 
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocEdTest2():
	try:
		doc =  PyAp.ApApplication().docManager().curDocument()
		val = doc.editor().getInteger("\nEnter an int")
		if(val[1] == PyEd.PromptStatus.Normal):
			PyRxApp.Printf("\nPASS({})".format(val[0])) 
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocEdTest3():
	try:
		app =  PyAp.ApApplication()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		val = ed.getString(1, "\nEnter a string")
		if(val[1] == PyEd.PromptStatus.Normal):
			PyRxApp.Printf("\nPASS({})".format(val[0])) 
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocEntsel():
	try:
		app =  PyAp.ApApplication()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		val = ed.entsel("\nSelect")
		if(val[2] == PyEd.PromptStatus.Normal):
			dbo = PyDb.openDbObject(val[0], False)
			PyRxApp.Printf("\nPASS({})".format(dbo.isA().name())) 
			p = val[1]
			PyRxApp.Printf("\nPASS({},{},{})".format(p.x, p.y, p.z))
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
	except Exception as err:
		PyRxApp.Printf(err)