import os

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

#just like in ARX, ent must not be null
class MyJig(PyEd.Jig):
    def __init__(self, line, basepoint):
        PyEd.Jig.__init__(self,line)
        self.line = line
        self.curPoint = basepoint
       
    #C++ sampler returns AcEdJig::DragStatus::kNoChange if not overridden  
    #acquireXXX returns a tuple AcEdJig::DragStatus and Value
    def sampler(self):
        self.setUserInputControls(PyEd.kAccept3dCoordinates or PyEd.kNullResponseAccepted)
        point_result_tuple = self.acquirePoint(self.curPoint)
        self.curPoint = point_result_tuple[1]
        return point_result_tuple[0]
    
    #C++ update returns True is not overridden
    def update(self):
        self.line.setEndPoint(self.curPoint)
        return True
       
    def doit(self):
        self.setDispPrompt("\nInsertion Point: ")
        self.drag()
        return self.curPoint
    
def PyRxCmd_pyjig():
    try: 
        doc = PyAp.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()
        
        point_result_tuple = ed.getPoint("\nPick startPoint")
        start_point = point_result_tuple[0]
        
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        line = PyDb.Line(start_point,start_point)
        line.setDatabaseDefaults()
        
        jig = MyJig (line,start_point)
        line.setEndPoint(jig.doit())
        model.appendAcDbEntity(line) 

    except Exception as err:
        PyRxApp.Printf(err)