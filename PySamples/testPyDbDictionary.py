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
	print("\nrun pydbdicttest :")
	   
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")

def PyRxCmd_pydbdicttest():
	try:
		PyDbDictOpenForRead()
	except Exception as err:
		print(err)
		
def PyDbDictOpenForRead():
	db = PyDb.HostApplicationServices().workingDatabase()  
	dictid = db.namedObjectsDictionaryId()
	dict = PyDb.Dictionary(dictid,PyDb.OpenMode.kForRead)
	if dict.isNullObj():
		print("\nFAIL")
	else:
		print("\nPASS({})".format(dict.isA().name()))
	for (name,id) in dict.asDict().items():
		print("\nitem({},{})".format(name,id ))	
	
	