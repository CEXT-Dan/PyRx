from pyrx import Db

print("added command = pyxrecord")


def PyRxCmd_pyxrecord():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        nod = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForRead)
        if not nod.has("AcadDim_CRX"):
            print("fail")
            return

        xid = nod.getAt("AcadDim_CRX")
        xrec = Db.Xrecord(xid, Db.OpenMode.kForRead)

        rbChain = xrec.rbChain()
        print(rbChain)

        rbChain[7] = (65, 0)  # spline type
        xrec.upgradeOpen()
        xrec.setFromRbChain(rbChain)
        xrec.downgradeOpen()

        print(xrec.rbChain())

    except Exception as err:
        print(err)
