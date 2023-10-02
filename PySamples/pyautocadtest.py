import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
 
import traceback

from pyautocad import Autocad, APoint


#pyautoacad from a command context
def PyRxCmd_pyautoacad():
    try:
        acad = Autocad()
        acad.prompt("Hello, Autocad from Python\n")
        print(acad.doc.Name)

        p1 = APoint(0, 0)
        p2 = APoint(50, 25)
        for i in range(5):
            text = acad.model.AddText('Hi %s!' % i, p1, 2.5)
            acad.model.AddLine(p1, p2)
            acad.model.AddCircle(p1, 10)
            p1.y += 10
            
    except Exception as err:
        traceback.print_exception(err)
        

def PyRxCmd_pyrx():
    try:
        #calls acutPrintf
        print("Hello, Autocad from Python\n")
        
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        
        p1 = Ge.Point3d(0,0,0)
        p2 = Ge.Point3d(50,25,0)
        
        #move to the right so we don't overlap pyautoacad
        p1 += (Ge.Vector3d.kXAxis * 100)
        p2 += (Ge.Vector3d.kXAxis * 100)
        
        for i in range(5):
            
            mt = Db.MText()
            mt.setDatabaseDefaults()
            mt.setLocation(p1)
            mt.setContents('PyHi %s!' % i)
            mt.setTextHeight(2.5)
            model.appendAcDbEntity(mt)
            
            line = Db.Line(p1, p2)
            model.appendAcDbEntity(line)
            
            circle = Db.Circle(p1,Ge.Vector3d.kZAxis, 10)
            model.appendAcDbEntity(circle)
            p1.y += 10
            
    except Exception as err:
        traceback.print_exception(err)
        