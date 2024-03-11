import traceback
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Gs
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Cv

import pandas as pd

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()


def PyRxCmd_doit() -> None:
    try:

        data = {
            "Number": [],
            "Easting": [],
            "Northing": [],
            "Level": [],
            "Description": [],
        }

        filter = [(Db.DxfCode.kDxfStart, "BsysCvDbPoint")]
        ssres: tuple[Ed.PromptStatus, Ed.SelectionSet] = Ed.Editor.select(filter)
        if ssres[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(ssres[0]))
            return

        for cogo in [Cv.CvDbPoint(id) for id in ssres[1].objectIds()]:
            data["Number"].append(cogo.number())
            data["Easting"].append(cogo.easting())
            data["Northing"].append(cogo.northing())
            data["Level"].append(cogo.elevation())
            data["Description"].append(cogo.description())

        df = pd.DataFrame(data)
        with pd.ExcelWriter("e:\\pandas_to_excel.xlsx", engine="xlsxwriter") as writer:
            df.to_excel(writer, sheet_name="Points", index=False)

    except Exception as err:
        traceback.print_exception(err)

