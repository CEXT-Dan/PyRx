from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs


def PyRxCmd_pytestLeader():
    try:
        db = Db.HostApplicationServices().workingDatabase();
        model = Db.BlockTableRecord(db.modelSpaceId(),Db.OpenMode.ForWrite)
        
        #create anno
        mtext = Db.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(PyGe.Point3d(105, 100,0))
        mtext.setContents("what we have, is failure to communicate")
        
        #add anno to db and close!
        mtid = model.appendAcDbEntity(mtext)
        mtext.close()
       
        #create leader
        leader = Db.Leader()
        leader.setDatabaseDefaults()
        leader.appendVertex(PyGe.Point3d(0,0,0))
        leader.appendVertex(PyGe.Point3d(100,100,0))
        
        #set leader to red
        c = Db.Color()
        c.setRGB(255,0,0)
        leader.setColor(c)
        
        #add leader to db
        model.appendAcDbEntity(leader)
        
        #attach
        leader.attachAnnotation(mtid)

    except Exception as err:
        print(err)
