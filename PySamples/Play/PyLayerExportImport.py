import traceback

import pandas as pd

from pyrx import Db, Ed

print("added command - py_layerimport")
print("added command - py_layerexport")


def PyRxCmd_pydebug() -> None:
    import PyRxDebug

    PyRxDebug.startListener()


def updateLayers(db, layers):
    layerMap = {}
    clr = Db.Color()
    lt = Db.LayerTable(db.layerTableId())
    for layer in layers:
        if lt.has(layer[0]):
            ltrid = lt.getAt(layer[0])
            ltr = Db.LayerTableRecord(ltrid, Db.OpenMode.kForWrite)
            clr.setColorIndex(layer[1])
            ltr.setColor(clr)
        else:
            lt.upgradeOpen()
            ltr = Db.LayerTableRecord()
            ltr.setName(layer[0])
            clr.setColorIndex(layer[1])
            ltr.setColor(clr)
            layerMap[layer[0]] = lt.add(ltr)
            lt.downgradeOpen()
    return layerMap


def PyRxCmd_py_layerexport() -> None:
    try:
        path = Ed.Core.getFileD(
            "Enter file name for storing layer table", "mylayerfile.xlsx", "xlsx", 33
        )
        db = Db.curDb()
        lt = Db.LayerTable(db.layerTableId(), Db.OpenMode.kForRead)
        if not lt.hasFields:
            return

        layerTable = {
            "Name": [],
            "Color": [],
            "LineType": [],
            "LineWeight": [],
        }

        for record in lt.recordIds():
            ltr = Db.LayerTableRecord(record)
            layerTable["Name"].append(ltr.name())
            layerTable["Color"].append(ltr.color().colorIndex())
            layerTable["LineType"].append(ltr.linetypeObjectId().handle())
            layerTable["LineWeight"].append(ltr.lineWeight())

        df = pd.DataFrame(layerTable)
        with pd.ExcelWriter(path, engine="openpyxl") as writer:
            df.to_excel(writer, sheet_name="Layers", index=False)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_py_layerimport() -> None:
    try:
        path = Ed.Core.getFileD(
            "Enter file name for storing layer table", "mylayerfile.xlsx", "xlsx", 32
        )
        db = Db.curDb()

        try:
            df = pd.read_excel(path, sheet_name="Layers")
        except Exception as e:
            print("\nCould not read source file", e)
            return
        _layerMap = updateLayers(db, df.values.tolist())

    except Exception as err:
        traceback.print_exception(err)
