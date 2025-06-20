import traceback

from pyrx_imp import Ap, Ax

print("added command PYAX_GETENT")
print("added command PYAX_GETSUBENT")
print("added command PYAX_SSALL")
print("added command PYAX_SSALLF")

@Ap.Command("PYAX_GETENT")
def get_entity():
    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axUtil = axDoc.utility()
        axEnt, pnt = axUtil.getEntity("\nPick a line")
        if axEnt.objectName() != "AcDbLine":
            raise RuntimeError("oops!: ")

        axLine = Ax.AcadLine.cast(axEnt)
        axLine.setTrueColor(Ax.AcadAcCmColor(0, 255, 0))
        print(axEnt.objectName(), pnt)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command("PYAX_GETSUBENT")
def get_subentity():
    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axUtil = axDoc.utility()
        ent, pnt, xf, ids = axUtil.getSubEntity("\nPick it")
        print(ent.objectName(), pnt, xf, ids)
    except Exception as err:
        traceback.print_exception(err)
        
@Ap.Command("PYAX_SSALL")
def get_select_all():
    try:
        axApp = Ap.Application.acadApplication()
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        axSet = axSets.add("PYRX")
        axSet.selectAll()
        
        types = set()
    
        for ent in axSet.entities():
            types.add(ent.objectName())

        for ent in axSet.entities():
            types.add(ent.objectName())

        print(types)
    except Exception as err:
        traceback.print_exception(err)
    finally:
        axSet.delete()
        
@Ap.Command("PYAX_SSALLF")
def get_select_all_filter():
    try:
        axApp = Ap.Application.acadApplication()
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        axSet = axSets.add("PYRX")
        
        # filter is a list of tuples, similar to Lisp
        axSet.selectAll([(0, "POINT,LINE")])
        
        #or use Db.DxfCode
        #axSet.selectAll([( Db.DxfCode.kDxfStart, "POINT,LINE")])

        types = set()
        
        for ent in axSet.entities():
            types.add(ent.objectName())

        for ent in axSet.entities():
            types.add(ent.objectName())

        print(types)
    except Exception as err:
        traceback.print_exception(err)
    finally:
        axSet.delete()

@Ap.Command("PYAX_WBLOCK")
def get_wblock_all():
    try:
        axApp = Ap.Application.acadApplication()
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        axSet = axSets.add("PYRX")
        axSet.selectOnScreen()
        acDoc.wblock("E:\\temp\\axWBlock.dwg",axSet)
    except Exception as err:
        traceback.print_exception(err)
    finally:
        axSet.delete()