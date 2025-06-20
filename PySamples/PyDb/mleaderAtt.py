from pyrx import Db, Ed, command


@command
def doit():
    ps, id, _ = Ed.Editor.entSel("\nSelect: \n")

    ml = Db.MLeader(id, Db.OpenMode.kForWrite)
    mlBlock = Db.BlockTableRecord(ml.blockContentId())
    mldefs = mlBlock.objectIds(Db.AttributeDefinition.desc())

    for id in mldefs:
        mlAttRef = ml.getBlockAttribute(id)  # renamed from getblockattributevalue
        print(mlAttRef.isA().name(), mlAttRef.textString())

        mlAttRef.setTextString("oof")
        ml.setBlockAttribute(id, mlAttRef)
