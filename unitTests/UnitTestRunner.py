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
import UnitTestResbuf
import UnitTestSheetSet
import UnitTestPyDbAssocPersSubentIdPE
import dbc
import testcfg
import os
import traceback
import TestResultsChecker
#
from pyrx_imp import Rx
from pyrx_imp import Ap
from pyrx_imp import Ed
host = Ap.Application.hostAPI()

if not "BRX" in host:
    import UnitTestDocString

if "BRX" in host:
    import UnitTestPyBcadCivil
    
print("\nadded command = runtests: ")

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
        importlib.reload(UnitTestResbuf)
        importlib.reload(UnitTestSheetSet)
        importlib.reload(UnitTestPyDbAssocPersSubentIdPE)
        
        if "BRX" in host:
            importlib.reload(UnitTestPyBcadCivil)
            
        if not "BRX" in host:
            importlib.reload(UnitTestDocString)
            
        print("\nReloading Unit tests: ")
    except Exception as err:
        traceback.print_exception(err)
        
def cleanup(dbc):
    try:
        dbc.cleardbs()
    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_runtests() -> None:
    try:
        cwd = os.getcwd().replace('\\','/')
        print(Ed.Core.evaluateLisp('(load "{}/testLisp.lsp") '.format(cwd)))
        
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
        UnitTestResbuf.resbuftester()
        UnitTestPyDbAssocPersSubentIdPE.AssocPersSubentIdPETester()
        UnitTestPyWx.pywx()
        
        if "ARX" in host or "BRX" in host:
            UnitTestSheetSet.sheetSetTester()

        if "BRX" in host:
            UnitTestPyBcadCivil.pybcciviltest()
            
        if not "BRX" in host:
            UnitTestDocString.docstringtester()
            
        TestResultsChecker.CheckTestResults(testcfg.logFileName)
            
    except Exception as err:
        traceback.print_exception(err)
    finally:
        cleanup(dbc)
