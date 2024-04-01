import UnitTestPyAcGe
import UnitTestPyRxObject
import UnitTestPyDatabase
import UnitTestPyDbObject
import UnitTestPyDbObjectId
import UnitTestPyDbPoint
import UnitTestPyDbEval
import UnitTestPyDbEntity
import UnitTestPyEditor
import UnitTestPyWx
import UnitTestPyActiveX
import dbc


def OnPyUnloadApp():
    dbc.dbs = None


from pyrx_imp import Ap

host = Ap.Application.hostAPI()

if "BRX" in host:
    import UnitTestPyBcadCivil

print("testname = runtests")


def PyRxCmd_runtests() -> None:
    try:
        # uses dbx so load databases later
        UnitTestPyActiveX.pyactivex()
        
        dbc.loaddbs()
        UnitTestPyAcGe.pyge()
        UnitTestPyRxObject.pyrxobject()
        UnitTestPyDatabase.pydbtest()
        UnitTestPyDbObject.pydbobject()
        UnitTestPyDbObjectId.pydbobjectid()
        UnitTestPyDbPoint.pydbpoint()
        UnitTestPyDbEval.pydbeval()
        UnitTestPyDbEntity.pyentity()
        UnitTestPyEditor.pyeditor()
        UnitTestPyWx.pywx()

        if "BRX" in host:
            UnitTestPyBcadCivil.pybcciviltest()

    except Exception as err:
        print(err)
    finally:
        dbc.cleardbs()
