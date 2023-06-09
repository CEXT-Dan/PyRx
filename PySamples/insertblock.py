
import os

import PyRxApp# = all the global methods like acutPrintf, 
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
	
def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")
         
def PyRxCmd_pyinsert():
    try: 
        db = PyDb.HostApplicationServices().workingDatabase()
        db2 = PyDb.Database(False, False)
        if db2.readDwgFile("./dwg/18X36RP.dwg") != PyDb.ErrorStatus.eOk:
             print("fail")
        oid = PyDb.ObjectId()
        if db.insert(oid,"WOOHOO", db2, True) != PyDb.ErrorStatus.eOk:
              print("fail")

    except Exception as err:
        print(err)
