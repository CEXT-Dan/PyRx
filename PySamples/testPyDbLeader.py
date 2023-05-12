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
        
        #add anno to db and close!
        mtid = model.appendAcDbEntity(mtext)
        mtext.close()
       
        #create leader
        leader = PyDb.Leader()
        leader.setDatabaseDefaults()
        leader.appendVertex(PyGe.Point3d(0,0,0))
        leader.appendVertex(PyGe.Point3d(100,100,0))
        
        #set leader to red
        c = PyDb.Color()
        c.setRGB(255,0,0)
        leader.setColor(c)
        
        #add leader to db
        model.appendAcDbEntity(leader)
        
        #attach
        leader.attachAnnotation(mtid)

    except Exception as err:
        PyRxApp.Printf(err)
