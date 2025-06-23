import traceback
from pyrx import Ap, Ax

print("added command itermodel")


@Ap.Command()
def itermodel() -> None:
    try:

        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axModel = axDoc.modelSpace()
        for ent in axModel:
            if ent.entityName() == "AcDbLine":
                line = Ax.AcadLine.cast(ent)
                line.setLayer("0")

    except Exception as err:
        traceback.print_exception(err)
