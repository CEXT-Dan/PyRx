import math
import traceback

from pyrx_imp import Db, Ge


def makeBlockRecord(db: Db.Database, name: str, bt: Db.BlockTable):
    if name in bt:
        return
    newBlock = Db.BlockTableRecord()
    # newBlock.setAnnotative(Db.AnnotativeStates.kTrue)
    newBlock.setName(name)
    bt.upgradeOpen()
    return bt.add(newBlock)

def initXaxisStationBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "XAXIS_STATION"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        line1 = Db.Line(Ge.Point3d(0, 2.5, 0.0), Ge.Point3d(0, -2.5, 0))
        blk.appendAcDbEntity(line1)
        attdef = Db.AttributeDefinition()
        attdef.setPosition(Ge.Point3d(0, -16.5, 0))
        attdef.setTag("XVALUE")
        attdef.setTextString("XSTATION")
        attdef.setRotation(1.5*math.pi)
        blk.appendAcDbEntity(attdef)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def initYaxisLevelBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "YAXIS_LEVEL"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        line1 = Db.Line(Ge.Point3d(2.5, 0, 0.0), Ge.Point3d(-2.5, 0, 0))
        blk.appendAcDbEntity(line1)
        attdef = Db.AttributeDefinition()
        attdef.setPosition(Ge.Point3d(-10, 0, 0))
        attdef.setTag("YVALUE")
        attdef.setTextString("YLEVEL")
        blk.appendAcDbEntity(attdef)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def initSagMPBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "SAG_MP"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        line1 = Db.Line(Ge.Point3d(0.0, 0.0, 0.0), Ge.Point3d(5, -5, 0))
        line2 = Db.Line(Ge.Point3d(5, -5, 0.0), Ge.Point3d(-5, -5, 0))
        line3 = Db.Line(Ge.Point3d(-5, -5, 0.0), Ge.Point3d(0, 0, 0))
        line4 = Db.Line(Ge.Point3d(0, -5, 0.0), Ge.Point3d(0, 0, 0))
        blk.appendAcDbEntity(line1)
        blk.appendAcDbEntity(line2)
        blk.appendAcDbEntity(line3)
        blk.appendAcDbEntity(line4)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid
    
def initSagPVIBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "SAG_PVI"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        line1 = Db.Line(Ge.Point3d(0.0, 0.0, 0.0), Ge.Point3d(-1, 3, 0))
        line2 = Db.Line(Ge.Point3d(-1, 3, 0.0), Ge.Point3d(1, 3, 0))
        line3 = Db.Line(Ge.Point3d(1, 3, 0.0), Ge.Point3d(0, 0, 0))
        line4 = Db.Line(Ge.Point3d(0, 3, 0.0), Ge.Point3d(0, 0, 0))
        blk.appendAcDbEntity(line1)
        blk.appendAcDbEntity(line2)
        blk.appendAcDbEntity(line3)
        blk.appendAcDbEntity(line4)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def initSagGradientBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "SAG_GRAD"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        arc1 = Db.Arc(Ge.Point3d(0.0, 5, 0.0), 5, math.pi, 2*math.pi)
        line1 = Db.Line(Ge.Point3d(-5, 5, 0.0), Ge.Point3d(5, 5, 0))
        line2 = Db.Line(Ge.Point3d(0, 5, 0.0), Ge.Point3d(0, 0, 0))
        blk.appendAcDbEntity(arc1)
        blk.appendAcDbEntity(line1)
        blk.appendAcDbEntity(line2)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def initCrestMPBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "CREST_MP"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        line1 = Db.Line(Ge.Point3d(0.0, 0.0, 0.0), Ge.Point3d(5, 5, 0))
        line2 = Db.Line(Ge.Point3d(5, 5, 0.0), Ge.Point3d(-5, 5, 0))
        line3 = Db.Line(Ge.Point3d(-5, 5, 0.0), Ge.Point3d(0, 0, 0))
        line4 = Db.Line(Ge.Point3d(0, 5, 0.0), Ge.Point3d(0, 0, 0))
        blk.appendAcDbEntity(line1)
        blk.appendAcDbEntity(line2)
        blk.appendAcDbEntity(line3)
        blk.appendAcDbEntity(line4)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def initCrestPVIBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "CREST_PVI"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        line1 = Db.Line(Ge.Point3d(0.0, 0.0, 0.0), Ge.Point3d(-1, -3, 0))
        line2 = Db.Line(Ge.Point3d(-1, -3, 0.0), Ge.Point3d(1, -3, 0))
        line3 = Db.Line(Ge.Point3d(1, -3, 0.0), Ge.Point3d(0, 0, 0))
        line4 = Db.Line(Ge.Point3d(0, -3, 0.0), Ge.Point3d(0, 0, 0))
        blk.appendAcDbEntity(line1)
        blk.appendAcDbEntity(line2)
        blk.appendAcDbEntity(line3)
        blk.appendAcDbEntity(line4)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def initCrestGradientBlock(db: Db.Database):
    bt = Db.BlockTable(db.blockTableId())
    name = "CREST_GRAD"
    if name not in bt:
        blkid = makeBlockRecord(db, name, bt)
        blk = Db.BlockTableRecord(blkid, Db.OpenMode.kForWrite)
        arc1 = Db.Arc(Ge.Point3d(0.0, -5, 0.0), 5, 0, math.pi)
        line1 = Db.Line(Ge.Point3d(-5, -5, 0.0), Ge.Point3d(5, -5, 0))
        line2 = Db.Line(Ge.Point3d(0, -5, 0.0), Ge.Point3d(0, 0, 0))
        blk.appendAcDbEntity(arc1)
        blk.appendAcDbEntity(line1)
        blk.appendAcDbEntity(line2)
        return blkid
    else:
        blkid = bt.getAt(name)
        return blkid

def makeRef(pos: Ge.Point3d, blkid: Db.ObjectId, db: Db.Database):
    blockRef = Db.BlockReference(pos, blkid)
    refid = db.addToModelspace(blockRef)            
    return refid

def makeRefAtt(pos: Ge.Point3d, blkid: Db.ObjectId, db: Db.Database, att: float):
    blockRef = Db.BlockReference(pos, blkid)
    refid = db.addToModelspace(blockRef)
    blockrec = Db.BlockTableRecord(blkid)
    if blockrec.hasAttributeDefinitions():
        attdefids = blockrec.objectIds(Db.AttributeDefinition.desc())
        attdefs = [Db.AttributeDefinition(id) for id in attdefids]
        for attdef in attdefs:
            if attdef.isConstant():
                continue
            attref = Db.AttributeReference()
            attref.setDatabaseDefaults(db)
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
            blockRef.appendAttribute(attref)
            attref.setTextString(str(att))            
    return refid

def PyRxCmd_dotestblocks():
    try:
        db = Db.curDb()
        anchor = Ge.Point3d(50, 50, 0)
        blkid = initXaxisStationBlock(db)
        makeRefAtt(anchor,blkid,db, 2.0)
        anchor = Ge.Point3d(-50, 50, 0)
        blkid = initYaxisLevelBlock(db)
        makeRefAtt(anchor,blkid,db, 17.5)
        anchor = Ge.Point3d(20, 50, 0)
        blkid = initCrestMPBlock(db)
        makeRef(anchor,blkid,db)
        anchor = Ge.Point3d(20, 40, 0)
        blkid = initCrestPVIBlock(db)
        makeRef(anchor,blkid,db)
        anchor = Ge.Point3d(20, 30, 0)
        blkid = initCrestGradientBlock(db)
        makeRef(anchor,blkid,db)
        anchor = Ge.Point3d(20, 20, 0)
        blkid = initSagMPBlock(db)
        makeRef(anchor,blkid,db)
        anchor = Ge.Point3d(20, 10, 0)
        blkid = initSagPVIBlock(db)
        makeRef(anchor,blkid,db)
        anchor = Ge.Point3d(20, 0, 0)
        blkid = initSagGradientBlock(db)
        makeRef(anchor,blkid,db)
        line1 = Db.Line(anchor, Ge.Point3d(0, 0, 0))
        db.addToModelspace(line1)
        
    except Exception as err:
        traceback.print_exception(err)
