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
    def __init__(self, table):
        PyEd.Jig.__init__(self,table)
        self.table = table
        self.curPoint = PyGe.Point3d(0,0,0)
       
    #C++ sampler returns AcEdJig::DragStatus::kNoChange if not overridden  
    #acquireXXX returns a tuple AcEdJig::DragStatus and Value
    def sampler(self):
        self.setUserInputControls(PyEd.kAccept3dCoordinates or PyEd.kNullResponseAccepted)
        point_result_tuple = self.acquirePoint(self.curPoint)
        self.curPoint = point_result_tuple[1]
        return point_result_tuple[0]
    
    #C++ update returns True is not overridden
    def update(self):
        self.table.setPosition(self.curPoint)
        return True
       
    def doit(self):
        self.setDispPrompt("\nInsertion Point: ")
        self.drag()
        return self.curPoint
    
def PyRxCmd_pyjig():
    try: 
        db = PyAp.Application().docManager().curDocument().database()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        table = PyDb.Table()
     
        table.setSize(6,4)
        table.setDatabaseDefaults()
        table.setColumnWidth(80)
        table.setRowHeight(12)
        table.generateLayout()
     
        range = PyDb.CellRange()
        range.topRow = 1
        range.leftColumn = 0
        range.bottomRow = 6
        range.rightColumn = 4
        
        iter = table.getIterator(range)
        
        for cell in iter:
           table.setTextString(cell.row,cell.column,"sup {},{}".format(cell.row, cell.column))
           
        jig = MyJig (table)
        table.setPosition(jig.doit())
        
        model.appendAcDbEntity(table) 
        table.recomputeTableBlock(True)
           
    except Exception as err:
        PyRxApp.Printf(err)