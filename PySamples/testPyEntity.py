import os 
from time import perf_counter

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
	PyRxApp.Printf("\nrun pydbentitytest :")
	   
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

def PyRxCmd_pydbentitytest():
	try:
		PyDbEntSetLayer()
		PyDbEntSetLayer2()
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyDbEntSetLayer():
	app =  PyAp.ApApplication()
	docm = app.docManager()
	doc = docm.curDocument()
	ed = doc.editor()
	ss = ed.selectAll()
	t1_start = perf_counter()
	if(ss[1] == PyEd.PromptStatus.Normal):
		for id in ss[0]:
			PyDb.DbEntity(id, PyDb.OpenMode.kForWrite).setLayer("0")
	t1_stop = perf_counter()
	PyRxApp.Printf("\nNum Items = {}, Elapsed time: {t:.4f}".format(len(ss[0]), t = t1_stop-t1_start))
	
def PyDbEntSetLayer2():
	app =  PyAp.ApApplication()
	docm = app.docManager()
	doc = docm.curDocument()
	ed = doc.editor()
	ss = ed.selectAll()
	db = doc.database()
	clayer = db.clayer()
	t1_start = perf_counter()
	if(ss[1] == PyEd.PromptStatus.Normal):
		for id in ss[0]:
			PyDb.DbEntity(id, PyDb.OpenMode.ForWrite).setLayer(clayer)
	t1_stop = perf_counter()
	PyRxApp.Printf("\nNum Items = {}, Elapsed time: {t:.4f}".format(len(ss[0]), t = t1_stop-t1_start))
			
		   
