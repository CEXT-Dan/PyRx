import PyRx  # = Runtime runtime 
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services 
import PyEd  # = editor 

def OnPyInitApp():
    print("\nOnPyInitApp")
	
def OnPyUnloadApp():
    print("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
	print("\nOnPyLoadDwg")
	print("\nrun pydbsymtabletest :")
	   
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")

def PyRxCmd_pydbsymtabletest():
	try:
		PyDbSymOpenForRead()
	except Exception as err:
		print(err)
		
def PyDbSymOpenForRead():
	db = PyDb.HostApplicationServices().workingDatabase()  
	btid = db.blockTableId()
	table = PyDb.SymbolTable(btid,PyDb.OpenMode.kForRead)
	if table.isNullObj():
		print("\nFAIL")
	else:
		print("\nPASS({})".format(table.isA().name()))
	for id in table.recordIds():
		print(id)	
	
	