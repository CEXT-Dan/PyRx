from pyrx import Ap, Db, Ed

RSG_NONULL = 1

def PyRxCmd_pydoit():
    try:
        doc = Ap.Application().docManager().curDocument()
        ed = doc.editor()
        entSelRes = ed.entSel("\nPick a curve: ")
        if entSelRes[0] != Ed.PromptStatus.eNormal:
            return

        id = entSelRes[1]
        if not id.objectClass().isDerivedFrom(Db.Curve.desc()):
            return

        db = doc.database()
        model = Db.BlockTableRecord(
            db.modelSpaceId(), Db.OpenMode.kForWrite)

        curve = Db.Curve(id, Db.OpenMode.kForRead)

        offset = 10  # default value
        getRealRes = ed.getReal("\nEnter an offest: ")
        if getRealRes[0] == Ed.PromptStatus.eNormal:
           offset = getRealRes[1]

        for i in range(0, 10):
            curves = curve.getOffsetCurves(offset)
            offset += 10

            for crv in curves:
                model.appendAcDbEntity(crv)

        ed.initGet(RSG_NONULL, "Y N")
        kwRes = ed.getKword("\nDelete original? [Yes/No]: ")

        do_delete = False
        if kwRes[0] == Ed.PromptStatus.eNormal and kwRes[1] == "Y":
            do_delete = True

        if do_delete:
            curve.upgradeOpen()
            curve.erase()

    except Exception as err:
        print(err)
