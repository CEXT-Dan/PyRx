from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx, Ax

print("added command = pydynprops")
print("added command = pymoddynprops")
print("added command = pyflip")


def print_value(item):
    dataType = item.getType()
    match dataType:
        case Db.DwgDataType.kDwgText:
            print(item.getString())
        case Db.DwgDataType.kDwgReal:
            print(item.getDouble())
        case Db.DwgDataType.kDwgInt16:
            print(item.getInt16())
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


# use the dynamic block sample drawing (North Arrow)
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


# use the dynamic block sample drawing (flip)
def PyRxCmd_pyflip():
    try:

        fon = Db.EvalVariant()
        fon.setInt16(Rx.LispType.kInt16, 1)

        foff = Db.EvalVariant()
        foff.setInt16(Rx.LispType.kInt16, 0)

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
            if prop.propertyName() == "Flip state1":
                if prop.value().getInt16() == 0:
                    prop.setValue(fon)
                else:
                    prop.setValue(foff)

    except Exception as err:
        print(err)
