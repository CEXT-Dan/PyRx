from pathlib import Path

from pyrx import Ap, Db, Ed, Ge, command
from pyrx.db.block import (
    BlockNotFoundError,
    add_block_definition,
    get_block_by_name,
    get_block_reference,
)
from pyrx.ed.prompt import get_point, get_real, get_string


def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command pyinsert")
    print("Added command pyinsertatt")
    print("Added command pyinsertdyn")
    print("Added command pyinsert2")
    print("Added command pyinsert_interactive")
    print("Added command py_add_block")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")

@Ap.Command()
def pyinsert() -> None:
    try:
        db = Db.HostApplicationServices().workingDatabase()
        block = Db.Database(False, True)
        block.readDwgFile("../dwg/18X36RP.dwg")
        block.closeInput(True)
        blockId = Db.ObjectId()
        db.insert(blockId, "WOOHOO", block, True)

        blockRef = Db.BlockReference(Ge.Point3d(100, 100, 0), blockId)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(blockRef)

    except Exception as err:
        print(err)


# https://adndevblog.typepad.com/autocad/2013/01/how-to-mimic-the-autocad-insert-command-in-arx-without-acedcommand-call.html

@Ap.Command()
def pyinsertatt() -> None:
    try:
        ptres = Ed.Editor.getPoint("\nSpecify insertion point: ")
        if ptres[0] != Ed.PromptStatus.eOk:
            print("Oops!: ", ptres[0])
            return

        db = Db.HostApplicationServices().workingDatabase()
        block = Db.Database(False, True)
        block.readDwgFile("../dwg/GRA.dwg")
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
                if attdef.hasFields():
                    of = Db.Field(attdef.getField())
                    flag = Db.FieldCodeFlag(
                        Db.FieldCodeFlag.kFieldCode | Db.FieldCodeFlag.kAddMarkers
                    )
                    nf = Db.Field(of.getFieldCode(flag))
                    attref.setField(nf)
                    nf.evaluate()

    except Exception as err:
        print(err)


@command
def pyinsert2():
    # ./media/rect.dwg
    BLOCK_NAME = "RECT"
    DESCRIPTION = "PY Insert Block"

    bref_id = get_block_reference(
        BLOCK_NAME,
        position=(20, 30, 0),
        scale=5.0,
        attributes={"DESCRIPTION": DESCRIPTION},
        dyn_properties={"W": 2.5, "H": 1.2},
        scale_dyn_properties=True,
    )
    bref = Db.BlockReference(bref_id)
    try:
        Db.curDb().addToModelspace(bref)
        print(f"Block '{BLOCK_NAME}' inserted with handle: {bref_id.handle()}")
    except Exception:
        bref.erase()
        raise


@command
def pyinsert_interactive():
    # ./media/rect.dwg
    block_name = get_string("\nEnter block name: ", cronly=True)

    try:
        btr_id = get_block_by_name(block_name)
    except BlockNotFoundError:
        print(f"Block '{block_name}' not found.")
        return
    position = get_point("\nSpecify insertion point: ")
    scale = get_real("\nSpecify scale factor: ")
    bref_id = get_block_reference(
        btr_id,
        position=position,
        scale=scale,
    )
    bref = Db.BlockReference(bref_id)
    try:
        Db.curDb().addToModelspace(bref)
        print(f"Block '{block_name}' inserted with handle: {bref_id.handle()}")
    except Exception:
        bref.erase()
        raise


@command
def py_add_block():
    try:
        btr_id = get_block_by_name("block_circle")
        print("Block 'block_circle' already exists.")
    except BlockNotFoundError:
        block_path = Path(__file__).parent / "media" / "block_circle.dwg"
        btr_id = add_block_definition(block_path)
        print("Block 'block_circle' added.")
    bref_id = get_block_reference(btr_id)
    bref = Db.BlockReference(bref_id)
    try:
        Db.curDb().addToModelspace(bref)
        print(f"Block 'block_circle' inserted with handle: {bref_id.handle()}")
    except Exception:
        bref.erase()
        raise


def do_insert_dyn(db, blockId):
    blockRef = Db.BlockReference(Ge.Point3d(100, 100, 0), blockId)
    return db.addToModelspace(blockRef)


@Ap.Command()
def pyinsertdyn():
    try:
        db = Db.curDb()
        block = Db.Database(False, True)
        block.readDwgFile("../dwg/screw.dwg")
        block.closeInput(True)
        blockId = Db.ObjectId()
        db.insert(blockId, "screw", block, True)

        # add a scope to close the new block
        blockRefid = do_insert_dyn(db, blockId)

        dynref = Db.DynBlockReference(blockRefid)
        if dynref.isDynamicBlock():
            print("true")
    except Exception as err:
        print(err)
