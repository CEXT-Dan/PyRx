from pyrx import Db, Ge

print("added command = pytestMLeader")


def PyRxCmd_pytestMLeader():
    try:
        # create anno
        mtext = Db.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(Ge.Point3d(120, 102.5, 0))
        mtext.setContents("what we have, is failure to communicate")

        # create MLeader
        leader = Db.MLeader()
        leader.setDatabaseDefaults()
        leader.setContentType(Db.MLeaderContentType.kMTextContent)
        leader.setMText(mtext)

        # add a leader
        idx = leader.addLeaderLine(Ge.Point3d(100, 100, 0))
        leader.addFirstVertex(idx, Ge.Point3d(0, 0, 0))

        # add the object to the database
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(leader)

    except Exception as err:
        print(err)
