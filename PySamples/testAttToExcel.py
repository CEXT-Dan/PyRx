import traceback

import openpyxl as Ex  # using openpyxl

from pyrx import Db, Ed


def selectRefs() -> list[Db.ObjectId]:
    entSetRes = Ed.Editor.entSel("\nSelectBlock: \n", Db.BlockReference.desc())
    if entSetRes[0] != Ed.PromptStatus.eNormal:
        raise Exception(entSetRes[0])

    ref = Db.BlockReference(entSetRes[1])
    btr = Db.BlockTableRecord(ref.blockTableRecord())
    return btr.getBlockReferenceIds()


# PyRxCmd_ defines a command, the command is doit
def PyRxCmd_doit():
    try:
        # create a workbook and get the active sheet
        wb = Ex.Workbook()
        ws = wb.active

        # iterate the attributes and populate the cells
        for nrow, refId in enumerate(selectRefs()):
            ref = Db.BlockReference(refId)
            attIds = ref.attributeIds()
            for ncol, attid in enumerate(attIds):
                att = Db.AttributeReference(attid)
                ws.cell(row=nrow + 1, column=ncol + 1, value=att.textString())

        # save it
        wb.save("e:\\pyattout.xlsx")

    except Exception as err:
        traceback.print_exception(err)
