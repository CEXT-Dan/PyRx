import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

from openpyxl import load_workbook

def PyRxCmd_pydoit():
    try:
        table = PyDb.Table()
        table.setSize(22,8)
        table.generateLayout()
        table.setDatabaseDefaults()
        
        wb  = load_workbook('sample.xlsx')
        sheet = wb.active
        for icol in range(7): 
            for irow in range(20):
                val = sheet.cell(row=irow+1, column=icol+1)
                table.setTextString(irow,icol,"{}".format(val.value))
            
        db = PyAp.Application().docManager().curDocument().database()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        model.appendAcDbEntity(table)   
        
    except Exception as err:
        PyRxApp.Printf(err)
        
