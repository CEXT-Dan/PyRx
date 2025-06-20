from pyrx import Db, Ge


def PyRxCmd_pygetfields():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        nod = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForRead)

        fieldListId = nod.getAt("ACAD_FIELDLIST")
        fieldList = Db.Core.entGet(fieldListId)

        for fieldItem in fieldList:
            if fieldItem[0] == 330 and fieldItem[1].objectClass().isDerivedFrom(Db.Field.desc()):
                field = Db.Field(fieldItem[1], Db.OpenMode.kForRead)
                print(field.getValue())

    except Exception as err:
        print(err)


def PyRxCmd_pymakefield():
    try:
        db = Db.HostApplicationServices().workingDatabase()

        mtext = Db.MText()
        mtext.setLocation(Ge.Point3d(100, 100, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(mtext)

        field = Db.Field("%<\\AcExpr (9+9*42)>%")
        mtext.setField(field)
        field.evaluate()

    except Exception as err:
        print(err)
