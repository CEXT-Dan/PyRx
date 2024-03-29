import traceback
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

#converts fields to text for seleted refs
def PyRxCmd_fieldnuker5000() -> None:
    try:
        #modify filter
        filter = [(Db.DxfCode.kDxfStart, "INSERT")]
        ssres: tuple[Ed.PromptStatus,Ed.SelectionSet] = Ed.Editor.select(filter)
        if ssres[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(ssres[0])) 
            return
        
        for refid in ssres[1].objectIds():
            ref = Db.BlockReference(refid)
            for attid in ref.attributeIds():
                attref = Db.AttributeReference(attid,Db.OpenMode.kForWrite)
                if attref.hasFields():
                    attref.convertFieldToText()
                
    except Exception as err:
        traceback.print_exception(err)
   
#converts fields to text for named block
def PyRxCmd_fieldnuker9000() -> None:
    try:
        name = "Brdrtemplate" # getname
        
        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())
        
        #find the block
        if not bt.has(name):
            return #oof
        btrid = bt.getAt(name)
        btr = Db.BlockTableRecord(btrid)
        
        #nuke em from orbit
        attdefids = btr.objectIds(Db.AttributeDefinition.desc())
        for attdefid in attdefids:
            attdef = Db.AttributeDefinition(attdefid,Db.OpenMode.kForWrite)
            if attdef.hasFields():
                attdef.convertFieldToText()
        
        for refid in btr.getBlockReferenceIds():
            ref = Db.BlockReference(refid)
            for attid in ref.attributeIds():
                attref = Db.AttributeReference(attid,Db.OpenMode.kForWrite)
                if attref.hasFields():
                    attref.convertFieldToText()
                
    except Exception as err:
        traceback.print_exception(err)
        
        

