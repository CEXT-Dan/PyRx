import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor


def PyRxCmd_pytestLeader():
    try:
        
        db = PyDb.HostApplicationServices().workingDatabase();
        model = PyDb.BlockTableRecord(db.modelSpaceId(),PyDb.OpenMode.ForWrite)
        
        #create anno
        mtext = PyDb.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(PyGe.Point3d(105, 100,0))
        mtext.setContents("what we have, is failure to communicate")
        
        #create leader
        leader = PyDb.MLeader()
        leader.setDatabaseDefaults()
        leader.setContentType(PyDb.mlc)


    except Exception as err:
        PyRxApp.Printf(err)
