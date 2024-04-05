import UnitTestPyAcGe
import UnitTestPyRxObject
import UnitTestPyDatabase
import UnitTestPyDbObject
import UnitTestPyDbObjectId
import UnitTestPyDbEval
import UnitTestPyDbEntity
import UnitTestPyEditor
import UnitTestPyWx
import UnitTestPyActiveX
import dbc

import importlib
from pyrx_imp import Rx
from pyrx_imp import Ap
host = Ap.Application.hostAPI()

if "BRX" in host:
    import UnitTestPyBcadCivil

print("testname = runtests")

def OnPyInitApp() -> None:
    try:
        importlib.reload(UnitTestPyAcGe)
        importlib.reload(UnitTestPyRxObject)
        importlib.reload(UnitTestPyDatabase)
        importlib.reload(UnitTestPyDbObject)
        importlib.reload(UnitTestPyDbObjectId)
        importlib.reload(UnitTestPyDbEval)
        importlib.reload(UnitTestPyDbEntity)
        importlib.reload(UnitTestPyEditor)
        importlib.reload(UnitTestPyWx)
        importlib.reload(UnitTestPyActiveX)
        importlib.reload(dbc)
        if "BRX" in host:
            importlib.reload(UnitTestPyBcadCivil)
        print("\nLoading Unit tests: ")
    except Exception as err:
        print(err)
        
def cleanup(dbc):
    try:
        dbc.cleardbs()
    except Exception as err:
        print(err)
    
def PyRxCmd_runtests() -> None:
    try:
        
        #TODO: make a prompt to select what tests to run
        # uses dbx so load databases later
        UnitTestPyActiveX.pyactivex()
        
        #load 
        dbc.loaddbs()
        
        UnitTestPyAcGe.pyge()
        UnitTestPyRxObject.pyrxobject()
        UnitTestPyDatabase.pydbtest()
        UnitTestPyDbObject.pydbobject()
        UnitTestPyDbObjectId.pydbobjectid()
        UnitTestPyDbEval.pydbeval()
        UnitTestPyDbEntity.pyentity()
        UnitTestPyEditor.pyeditor()
        UnitTestPyWx.pywx()

        if "BRX" in host:
            UnitTestPyBcadCivil.pybcciviltest()

    except Exception as err:
        print(err)
    finally:
        cleanup(dbc)
