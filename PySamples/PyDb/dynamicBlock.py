import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("added command = pydynprops")
print("added command = pymoddynprops")

def print_value(item):
  dataType = item.getType()
  match dataType:
    case Db.DwgDataType.kDwgText:
      print(item.getString())
    case Db.DwgDataType.kDwgReal:
      print(item.getDouble())
    case Db.DwgDataType.kDwgInt32:
      print(item.getInt32())
    case Db.DwgDataType.kDwg3Real:
      print(item.getPoint3d())
    case _:
      print("oops")


def PyRxCmd_pydynprops():
  try:
    ssresult = Ed.Editor.entSel("\nSelect block ref: ")
    if ssresult[0] != Ed.PromptStatus.eNormal:
      print(ssresult[0])
      return

    id = ssresult[1]
    if not id.isDerivedFrom(Db.BlockReference.desc()):
      print("not a BlockReference")
      return

    dynRef = Db.DynBlockReference(id)
    if not dynRef.isDynamicBlock():
      print("not a dynamic block")
      return

    props = dynRef.getBlockProperties()
    for prop in props:
      print("\n-------prop---------\n")
      print(prop.propertyName())
      print(prop.propertyType())
      print(prop.readOnly())
      print(prop.description())
      print_value(prop.value())

  except Exception as err:
    print(err)
    

#use the dynamic block sample drawing (North Arrow)
def PyRxCmd_pymoddynprops():
  try:
    ssresult = Ed.Editor.entSel("\nSelect block ref: ")
    if ssresult[0] != Ed.PromptStatus.eNormal:
      print(ssresult[0])
      return

    id = ssresult[1]
    if not id.isDerivedFrom(Db.BlockReference.desc()):
      print("not a BlockReference")
      return

    dynRef = Db.DynBlockReference(id)
    if not dynRef.isDynamicBlock():
      print("not a dynamic block")
      return

    props = dynRef.getBlockProperties()
    for prop in props:
      if prop.propertyName() == "Angle1":
        arg = Db.EvalVariant(3.14159265359)
        prop.setValue(arg)

  except Exception as err:
    print(err)
