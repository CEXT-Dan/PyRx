import UnitTestPyAcGe
import UnitTestPyDatabase
import UnitTestPyDbObject
import UnitTestPyDbObjectId
import UnitTestPyDbPoint
import UnitTestPyDbEval
import UnitTestPyDbEntity
import UnitTestPyEditor

print("testname = pytestall")

def PyRxCmd_pytestall():
    try:
      UnitTestPyAcGe.PyRxCmd_pyge()
      UnitTestPyDatabase.PyRxCmd_pydbtest()
      UnitTestPyDbObject.PyRxCmd_pydbobject()
      UnitTestPyDbObjectId.PyRxCmd_pydbobjectid()
      UnitTestPyDbPoint.PyRxCmd_pydbpoint()
      UnitTestPyDbEval.PyRxCmd_pydbeval()
      UnitTestPyDbEntity.PyRxCmd_pyentity()
      UnitTestPyEditor.PyRxCmd_pyeditor()
    except Exception as err:
      print(err)
