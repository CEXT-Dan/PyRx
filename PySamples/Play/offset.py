import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

RSG_NONULL = 1

def PyRxCmd_pydoit():
    try:
        doc = PyAp.Application().docManager().curDocument()
        ed = doc.editor()
        entSelRes = ed.entSel("\nPick a curve: ")
        if entSelRes[0] != PyEd.PromptStatus.eNormal:
            return

        id = entSelRes[1]
        if not id.objectClass().isDerivedFrom(PyDb.Curve.desc()):
            return

        db = doc.database()
        model = PyDb.BlockTableRecord(
            db.modelSpaceId(), PyDb.OpenMode.kForWrite)

        curve = PyDb.Curve(id, PyDb.OpenMode.kForRead)

        offset = 10  # default value
        getRealRes = ed.getReal("\nEnter an offest: ")
        if getRealRes[0] == PyEd.PromptStatus.eNormal:
           offset = getRealRes[1]

        for i in range(0, 10):
            curves = curve.getOffsetCurves(offset)
            offset += 10

            for crv in curves:
                model.appendAcDbEntity(crv)

        ed.initGet(RSG_NONULL, "Y N")
        kwRes = ed.getKword("\nDelete original? [Yes/No]: ")

        do_delete = False
        if kwRes[0] == PyEd.PromptStatus.eNormal and kwRes[1] == "Y":
            do_delete = True

        if do_delete:
            curve.upgradeOpen()
            curve.erase()

    except Exception as err:
        PyRxApp.Printf(err)
