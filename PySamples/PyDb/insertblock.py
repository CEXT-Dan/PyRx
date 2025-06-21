from pyrx import Db, Ed, Ge


def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command pyinsert")
    print("Added command pyinsertatt")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


def PyRxCmd_pyinsert() -> None:
    try:
        db = Db.HostApplicationServices().workingDatabase()
        block = Db.Database(False, True)
        block.readDwgFile("./dwg/18X36RP.dwg")
        block.closeInput(True)
        blockId = Db.ObjectId()
        db.insert(blockId, "WOOHOO", block, True)

        blockRef = Db.BlockReference(Ge.Point3d(100, 100, 0), blockId)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(blockRef)

    except Exception as err:
        print(err)


# https://adndevblog.typepad.com/autocad/2013/01/how-to-mimic-the-autocad-insert-command-in-arx-without-acedcommand-call.html


def PyRxCmd_pyinsertatt() -> None:
    try:
        ptres = Ed.Editor.getPoint("\nSpecify insertion point: ")
        if ptres[0] != Ed.PromptStatus.eOk:
            print("Oops!: ", ptres[0])
            return

        db = Db.HostApplicationServices().workingDatabase()
        block = Db.Database(False, True)
        block.readDwgFile("./dwg/GRA.dwg")
        block.closeInput(True)
        blockId = Db.ObjectId()
        db.insert(blockId, "GRA", block, True)

        blockRef = Db.BlockReference(ptres[1], blockId)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(blockRef)

        blockrec = Db.BlockTableRecord(blockId)
        if blockrec.hasAttributeDefinitions():
            attdefids = blockrec.objectIds(Db.AttributeDefinition.desc())
            attdefs = [Db.AttributeDefinition(id) for id in attdefids]
            for attdef in attdefs:
                if attdef.isConstant():
                    continue
                attref = Db.AttributeReference()
                attref.setPropertiesFrom(attdef)
                attref.setInvisible(attdef.isInvisible())
                basePoint = attdef.position()
                basePoint += blockRef.position().asVector()
                attref.setPosition(basePoint)
                attref.setHeight(attdef.height())
                attref.setRotation(attdef.rotation())
                attref.setFieldLength(attdef.fieldLength())
                attref.setHorizontalMode(attdef.horizontalMode())
                attref.setVerticalMode(attdef.verticalMode())
                attref.setTag(attdef.tag())
                attref.setTextString("XXX")
                attref.setAlignmentPoint(attdef.alignmentPoint() + blockRef.position().asVector())
                blockRef.appendAttribute(attref)

    except Exception as err:
        print(err)
