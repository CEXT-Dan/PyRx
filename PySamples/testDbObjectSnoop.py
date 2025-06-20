import traceback

from pyrx import Db, Ed

print("added command = dwgsnoop")
print("added command = dxfsnoop")

"""
dumps the dwg filer for an AcDbObject into a list of tuples
(Type , Value)

"""


def PyRxCmd_dwgsnoop():
    try:
        snoop = Db.SnoopDwgFiler()
        entRes = Ed.Editor.entSel("\nSelect: ")
        if entRes[0] != Ed.PromptStatus.eNormal:
            return
        ent = Db.Entity(entRes[1])
        ent.snoop(snoop)

        for item in snoop.buffer():
            if type(item[1]) is Db.ObjectId:
                if item[1].isNull():
                    continue
                dbo = Db.DbObject(item[1])
                print(item[0], dbo.isA().name())
                continue
            elif type(item[1]) is memoryview:
                print(item[0], item[1].hex(" ").upper())
                continue
            print(item[0], item[1])

    except Exception as err:
        traceback.print_exc(err)


def PyRxCmd_dxfsnoop():
    try:
        db = Db.curDb()
        ld = Db.Dictionary(db.layoutDictionaryId())
        dxf = Db.SnoopDxfFiler()
        ld.snoopdxf(dxf)
        print(dxf.buffer())
    except Exception as err:
        traceback.print_exc(err)
