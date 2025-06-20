from pyrx import Db, Ge

print("added command = pytestLeader")


def PyRxCmd_pytestLeader():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)

        # create anno
        mtext = Db.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(Ge.Point3d(105, 100, 0))
        mtext.setContents("what we have, is failure to communicate")

        # add anno to db and close!
        mtid = model.appendAcDbEntity(mtext)
        mtext.close()

        # create leader
        leader = Db.Leader()
        leader.setDatabaseDefaults()
        leader.appendVertex(Ge.Point3d(0, 0, 0))
        leader.appendVertex(Ge.Point3d(100, 100, 0))

        # set leader to red
        c = Db.Color()
        c.setRGB(255, 0, 0)
        leader.setColor(c)

        # add leader to db
        model.appendAcDbEntity(leader)

        # attach
        leader.attachAnnotation(mtid)

    except Exception as err:
        print(err)
