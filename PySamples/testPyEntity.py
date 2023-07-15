import os 
from time import perf_counter
 
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
	print("\nrun pydbentitytest :")
	   
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")

def PyRxCmd_pydbentitytest():
	try:
		PyDbEntSetLayer()
		PyDbEntSetLayer2()
	except Exception as err:
		print(err)
		
def PyDbEntSetLayer():
	app =  PyAp.Application()
	docm = app.docManager()
	doc = docm.curDocument()
	ed = doc.editor()
	ss = ed.selectAll()
	t1_start = perf_counter()
	if(ss[0] == PyEd.PromptStatus.kNormal):
		for id in ss[1].toList():
			PyDb.Entity(id, PyDb.OpenMode.kForWrite).setLayer("0")
	t1_stop = perf_counter()
	print("\nNum Items = {}, Elapsed time: {t:.4f}".format(len(ss[1]), t = t1_stop-t1_start))
	
def PyDbEntSetLayer2():
	app =  PyAp.Application()
	docm = app.docManager()
	doc = docm.curDocument()
	ed = doc.editor()
	ss = ed.selectAll()
	db = doc.database()
	clayer = db.clayer()
	t1_start = perf_counter()
	if(ss[0] == PyEd.PromptStatus.Normal):
		for id in ss[1]:
			PyDb.Entity(id, PyDb.OpenMode.ForWrite).setLayer(clayer)
	t1_stop = perf_counter()
	print("\nNum Items = {}, Elapsed time: {t:.4f}".format(len(ss[1]), t = t1_stop-t1_start))
			
		   
