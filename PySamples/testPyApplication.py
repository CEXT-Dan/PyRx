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
		PyCurDocTest()
		PyCurDocSelectAll()
		PyCurDocSelectAllFilter()
		PyCurDocEdTest1()
		PyCurDocEdTest2()
		PyCurDocEdTest3()
		PyCurDocEntsel()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyCurDocTest():
	try:
		db = PyAp.Application().docManager().curDocument().database() 
		PyRxApp.Printf("\nPASS({})".format(db.getFilename())) 
	except Exception as err:
		PyRxApp.Printf(err)


def PyCurDocEdTest1():
	try:
		val = PyAp.Application().docManager().curDocument().editor().getInteger("\nEnter an int")
		if(val[0] == PyEd.PromptStatus.kNormal):
			PyRxApp.Printf("\nPASS({})".format(val[1])) 
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocEdTest2():
	try:
		doc = PyAp.Application().docManager().curDocument()
		val = doc.editor().getInteger("\nEnter an int")
		if(val[0] == PyEd.PromptStatus.kNormal):
			PyRxApp.Printf("\nPASS({})".format(val[1])) 
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocEdTest3():
	try:
		app =  PyAp.Application()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		val = ed.getString(1, "\nEnter a string")
		if(val[0] == PyEd.PromptStatus.kNormal):
			PyRxApp.Printf("\nPASS({})".format(val[1])) 
	except Exception as err:
		PyRxApp.Printf(err)

def PyCurDocEntsel():
	try:
		app =  PyAp.Application()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		val = ed.entsel("\nSelect")
		if(val[0] == PyEd.PromptStatus.kNormal):
			dbo = PyDb.DbObject(val[1], PyDb.OpenMode.ForRead)
			PyRxApp.Printf("\nPASS({})".format(dbo.isA().name())) 
			p = val[2]
			PyRxApp.Printf("\nPASS({},{},{})".format(p.x, p.y, p.z))
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyCurDocSelectAll():
	try:
		app =  PyAp.Application()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		val = ed.selectAll()
		if(val[0] == PyEd.PromptStatus.kNormal):
			numids = len(val[1])
			PyRxApp.Printf("\nPASS numids({})".format(numids))
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyCurDocSelectAllFilter():
	try:
		app =  PyAp.Application()
		docm = app.docManager()
		doc = docm.curDocument()
		ed = doc.editor()
		filter = [(PyDb.DxfCode.DxfStart,"CIRCLE")]
		val = ed.selectAll(filter)
		if(val[0] == PyEd.PromptStatus.kNormal):
			numids = len(val[1])
			PyRxApp.Printf("\nPASS numids({})".format(numids))
			for id in val[0]:
				PyRxApp.Printf("\nPASS({})".format(id.objectClass().name()))
	except Exception as err:
		PyRxApp.Printf(err)