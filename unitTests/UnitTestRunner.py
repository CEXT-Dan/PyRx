import UnitTestPyAcGe
import UnitTestPyRxObject
import UnitTestPyDatabase
import UnitTestPyDbObject
import UnitTestPyDbObjectId
import UnitTestPyDbEval
import UnitTestPyDbEntity
import UnitTestPyEditor
import UnitTestPyWx
import UnitTestResbuf
import UnitTestSheetSet
import UnitTestPyDbAssocPersSubentIdPE
import UnitTestPyBrep
import UnitTestMisc
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
    import UnitTestPyBcadBim

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
        importlib.reload(UnitTestResbuf)
        importlib.reload(UnitTestSheetSet)
        importlib.reload(UnitTestPyDbAssocPersSubentIdPE)
        importlib.reload(UnitTestPyBrep)
        importlib.reload(UnitTestMisc)

        if "BRX" in host:
            importlib.reload(UnitTestPyBcadCivil)
            importlib.reload(UnitTestPyBcadBim)

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
        cwd = os.getcwd().replace("\\", "/")
        print(Ed.Core.evaluateLisp('(load "{}/testLisp.lsp") '.format(cwd)))
        # load
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
        UnitTestPyBrep.brepTester()
        UnitTestPyWx.pywx()
        UnitTestMisc.MiscTester()

        if "ARX" in host or "BRX" in host:
            UnitTestSheetSet.sheetSetTester()

        if "BRX" in host:
            UnitTestPyBcadCivil.pybcciviltest()
            UnitTestPyBcadBim.pybcbimtest()

        if not "BRX" in host:
            UnitTestDocString.docstringtester()

        TestResultsChecker.CheckTestResults(testcfg.logFileName)

    except Exception as err:
        traceback.print_exception(err)
    finally:
        cleanup(dbc)


# for testing Ap.Command
@Ap.Command("foo", Ap.CmdFlags.MODAL)
def foofoo():
    print("foo")

@Ap.Command("far")
def farfar():
    print("far")

@Ap.Command()
def foobar():
    print("foobar")

@Ap.Command(Ap.CmdFlags.MODAL)
def foofar():
    print("foofar")

def somefunc():
    print("foofar")

Ap.Application.regCommand(
    os.getcwd(), "UnitTestRunner", "somefunc", somefunc, Ap.CmdFlags.MODAL
)

@Ap.LispFunction("C:LPF1")
def LPF_1(args):
    return 2
