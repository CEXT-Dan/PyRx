from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs


def PyRxCmd_doit():
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
                print(item[0], item[1].hex(' ').upper())
                continue
            print(item[0], item[1])

    except Exception as err:
        print(err)
