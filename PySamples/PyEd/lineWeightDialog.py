from pyrx import Ap, Db, Ed, Rx


@Ap.Command()
def doit():
    db = Db.curDb()
    print(Ed.Core.lineWeightDialog(db.celweight(), True))


# (ads_lineWeightDialog)
@Ap.LispFunction()
def ads_lineWeightDialog(args):
    db = Db.curDb()
    buff = []
    flag, lw = Ed.Core.lineWeightDialog(db.celweight(), True)
    if flag:
        return (Rx.LispType.kInt32, lw)
    else:
        return (Rx.LispType.kNil, 0)
