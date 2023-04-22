import os

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def PyRxCmd_pycreate_table():
    try: 
        db = PyAp.Application().docManager().curDocument().database()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        table = PyDb.Table()
        table.setPosition(PyGe.Point3d(100,100,0))
        table.setSize(6,4)
        table.generateLayout()
        table.setDatabaseDefaults()
        table.setColumnWidth(80)
        model.appendAcDbEntity(table)
        
        range = PyDb.CellRange()
        range.topRow = 1
        range.leftColumn = 0
        range.bottomRow = 6
        range.rightColumn = 4
        
        for cell in table.getIterator(range):
           table.setTextString(cell.row,cell.column,"sup {},{}".format(cell.row, cell.column))
           
        for cell in table.getIterator(range):
           print(table.textString(cell.row, cell.column))
           
    except Exception as err:
        PyRxApp.Printf(err)