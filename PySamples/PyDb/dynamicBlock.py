from pyrx import Ap,Db, Ed, Ge
import traceback

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
        # python does not have a int32 or int16
        # flip actions want an int16
        # an alternative is to use setInt16

        fon = Db.EvalVariant(1, True)
        # fon.setInt16(Db.DxfCode.kDxfInt16, 1)

        foff = Db.EvalVariant(0, True)  # isInt16
        # foff.setInt16(Db.DxfCode.kDxfInt16, 0)

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

@Ap.Command()
def pyinsert():
    try:
        db = Db.curDb()
        ps, id, _ = Ed.Editor.entSel("\nPick a block", Db.BlockReference.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        #check if it's dynamic
        dynref = Db.DynBlockReference(id)
        if not dynref.isDynamicBlock():
            print("oof")
            return
        
        #this should return the effective name
        ref = Db.BlockReference(id)
        print("\n{}".format(ref.getBlockName()))
        
        #better to put this in its own function for a GC scope and remove the close()
        newref = Db.BlockReference(Ge.Point3d(2229, 1390, 0),dynref.dynamicBlockTableRecord())
        newref.setScaleFactors(Ge.Scale3d(25.4))
        newrefid = db.addToModelspace(newref)
        newref.close()
        
        # create a new DynBlockReference from the new reference 
        # and set the properties 
        newdynref = Db.DynBlockReference(newrefid)
        props = newdynref.getBlockProperties()
        for prop in props:
            if prop.propertyName() == 'Distance':
                prop.setValue(Db.EvalVariant(50.08))
            if prop.propertyName() == 'Distance1':
                prop.setValue(Db.EvalVariant(48.8156))
   
    except Exception as err:
        traceback.print_exception(err)