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

from pyrx_imp import Ap
host = Ap.Application.hostAPI()

if 'BRX' in host:
  import UnitTestPyBcadCivil

print("testname = pytestall")

def PyRxCmd_pytestall():
    try:
      UnitTestPyAcGe.PyRxCmd_pyge()
      UnitTestPyRxObject.PyRxCmd_pyrxobject()
      UnitTestPyDatabase.PyRxCmd_pydbtest()
      UnitTestPyDbObject.PyRxCmd_pydbobject()
      UnitTestPyDbObjectId.PyRxCmd_pydbobjectid()
      UnitTestPyDbPoint.PyRxCmd_pydbpoint()
      UnitTestPyDbEval.PyRxCmd_pydbeval()
      UnitTestPyDbEntity.PyRxCmd_pyentity()
      UnitTestPyEditor.PyRxCmd_pyeditor()
      UnitTestPyWx.PyRxCmd_pywx()
      if 'BRX' in host:
          UnitTestPyBcadCivil.PyRxCmd_pybcciviltest()
    except Exception as err:
      print(err)
