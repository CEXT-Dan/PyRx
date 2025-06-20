from pyrx import Ap, Db, Ge

print("added command = dodbtrans")
print("added command = dodoctrans")

# from acdbHostApplicationServices()->workingTransactionManager();
# Db.TransactionManager()

# from acDocManager->curDocument()->transactionManager()
# Ap.TransactionManager()

# for this database
# Db.Database().transactionManager()

# for this doc
# Ap.DocManager().activateDocument().transactionManager()


def do_something(tr):
    for obj in tr.getAllObjects():
        ent = Db.Entity.cast(obj)
        ent.upgradeOpen()
        ent.setColorIndex(1)


def make_objects(db, tmr):
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
    for ind in range(0, 100):
        pnt = Db.Point(Ge.Point3d(ind, ind, 0))
        model.appendAcDbEntity(pnt)
        tmr.addNewlyCreatedDBRObject(pnt)


def PyRxCmd_dodbtrans():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        tmr = Db.TransactionManager()
        tr = tmr.startTransaction()

        make_objects(db, tmr)

        do_something(tr)
        # tmr.abortTransaction()
        tmr.endTransaction()

    except Exception as err:
        print(err)


def PyRxCmd_dodoctrans():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        tmr = Ap.DocManager().curDocument().transactionManager()
        tmr.enableGraphicsFlush(True)

        tr = tmr.startTransaction()
        make_objects(db, tmr)

        tmr.queueForGraphicsFlush()
        do_something(tr)

        tmr.flushGraphics()
        tmr.endTransaction()
        # tmr.abortTransaction()

    except Exception as err:
        print(err)
