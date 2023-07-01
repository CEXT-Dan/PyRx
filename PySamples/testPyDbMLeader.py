import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor


def PyRxCmd_pytestMLeader():
    try:
        # create anno
        mtext = PyDb.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(PyGe.Point3d(120, 102.5, 0))
        mtext.setContents("what we have, is failure to communicate")

        # create MLeader
        leader = PyDb.MLeader()
        leader.setDatabaseDefaults()
        leader.setContentType(PyDb.MLeaderContentType.kMTextContent)
        leader.setMText(mtext)
        
        #add a leader
        idx = leader.addLeaderLine(PyGe.Point3d(100, 100, 0))
        leader.addFirstVertex(idx, PyGe.Point3d(0, 0, 0))
        
        #add the object to the database
        db = PyDb.HostApplicationServices().workingDatabase()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.ForWrite)
        model.appendAcDbEntity(leader)

    except Exception as err:
        print(err)
