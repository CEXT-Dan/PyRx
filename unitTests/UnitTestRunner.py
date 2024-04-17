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
import testcfg
import os

from pyrx_imp import Rx
from pyrx_imp import Ap
from pyrx_imp import Ed
host = Ap.Application.hostAPI()

if not "BRX" in host:
    import UnitTestDocString


if "BRX" in host:
    import UnitTestPyBcadCivil

print("testname = runtests")

#load tests for lisp
if not "ZRX" in host:
    cwd = os.getcwd().replace('\\','/')
    Ed.Core.postCommand('(load "{}/testLisp.lsp") '.format(cwd))

def OnPyReload() -> None:
    try:
        import importlib
        importlib.reload(testcfg)
        importlib.reload(dbc)
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
        
        if "BRX" in host:
            importlib.reload(UnitTestPyBcadCivil)
            
        if not "BRX" in host:
            importlib.reload(UnitTestDocString)
            
        print("\nReloading Unit tests: ")
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
            
        if not "BRX" in host:
            UnitTestDocString.docstringtester()
            
    except Exception as err:
        print(err)
    finally:
        cleanup(dbc)
        
#helper finction for editor test
def PyRxLisp_pylispsstest(args):
    try:
        if args[0][0] == Rx.LispType.kSelectionSet and args[0][1].size() > 0:
            return True
        return False
    except Exception as err:
        print(err)
