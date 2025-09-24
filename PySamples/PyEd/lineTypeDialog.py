from pyrx import Ap, Db, Ed, Rx


@Ap.Command()
def doit():
    db = Db.curDb()
    print(Ed.Core.linetypeDialog(db.celtype(), True))


# (ads_linetypeDialog)
@Ap.LispFunction()
def ads_linetypeDialog(args):
    db = Db.curDb()
    buff = []
    flag, name, id = Ed.Core.linetypeDialog(db.celtype(), True)
    if flag:
        buff.append((Rx.LispType.kListBegin, 0))
        buff.append((Rx.LispType.kText, name))
        buff.append((Rx.LispType.kObjectId, id))
        buff.append((Rx.LispType.kListEnd, 0))
    else:
        buff.append((Rx.LispType.kNil, 0))
    return buff
