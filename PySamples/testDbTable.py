import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed

import pandas as pd
import openpyxl as xl

# create from excel 
def PyRxCmd_doit():
    try:
        wb = xl.load_workbook("E:\\ItsAlive.xlsx",read_only=True)
        ws = wb.active
        
        table = Db.Table()
        table.setDatabaseDefaults()
        
        # add one for the title and header
        table.setSize(ws.max_row+2, ws.max_column)
        table.generateLayout()

        # note openpyxl cell indexing is not zero based ..?..
        for row in ws.iter_rows():
            for cell in row:
                table.setTextString(
                    cell.row+1, cell.column-1, "{}".format(cell.value))
                
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(table)

    except Exception as err:
        traceback.print_exception(err)
  
# create from pandas       
def PyRxCmd_doit2():
    try:
        db = Db.curDb()
 
        data = {"calories": [420, 380, 390],
                "duration": [50, 40, 45]}
 
        df = pd.DataFrame(data)
 
        table = Db.Table()
        table.setDatabaseDefaults(db)
 
        # add one for the title and header
        table.setSize(df.shape[0]+2, df.shape[1])
 
        #title
        table.setTextString(0, 0, "I Like to Move It, Move It")
        
        headers = df.columns.values.tolist()
        datas = df.values.tolist()
 
        for col, value in enumerate(headers):
            table.setTextString(1, col, "{}".format(value))
 
        for row, data in enumerate(datas):
            for col, value in enumerate(data):
                table.setTextString(row+2, col, "{}".format(value))
 
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(table)
 
    except Exception as err:
        print(traceback.format_exc())

#simple iteration
def PyRxCmd_doit3():
    try:
        es = Ed.Editor.entSel("\nSelect a table: ", Db.Table.desc())
        if es[0]!= Ed.PromptStatus.eNormal:
            return
        
        table = Db.Table(es[1])
        for cell in table.cells(Db.CellRange(1,0,3,3)):
            print(table.textString(cell))

    except Exception as err:
        traceback.print_exception(err)
        
#simple iteration Format opt
def PyRxCmd_doit4():
    try:
        es = Ed.Editor.entSel("\nSelect a table: ", Db.Table.desc())
        if es[0]!= Ed.PromptStatus.eNormal:
            return
        
        table = Db.Table(es[1])
        for cellValue in table.cellValues():
            print(cellValue)
            
    except Exception as err:
        traceback.print_exception(err)
                

