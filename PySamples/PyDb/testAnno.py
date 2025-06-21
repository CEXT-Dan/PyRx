import traceback

from pyrx import Db, Ed


# example using Db.AnnotationScale.cast
def PyRxCmd_doit1() -> None:
    try:
        db = Db.curDb()

        entres = Ed.Editor.entSel("\nSelect an mtext", Db.MText.desc())
        if entres[0] != Ed.PromptStatus.eOk:
            print("Oops: ", entres[0])
            return

        ctxman = db.objectContextManager()
        ctxcoll = ctxman.contextCollection("ACDB_ANNOTATIONSCALES")

        mt = Db.MText(entres[1], Db.OpenMode.kForWrite)

        print(mt.isAnnotative())

        if mt.isAnnotative() == Db.AnnotativeStates.kFalse:
            mt.setAnnotative(Db.AnnotativeStates.kTrue)

        print(mt.isAnnotative())

        # don't need to cast unless we want to use AnnotationScale methods
        if ctxcoll.hasContext("1:1"):
            annoScale = ctxcoll.getContext("1:100")
            mt.addContext(annoScale)

        if ctxcoll.hasContext("1:100"):
            annoScale = Db.AnnotationScale.cast(ctxcoll.getContext("1:100"))
            print(annoScale.getName())
            mt.addContext(annoScale)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit2() -> None:
    try:
        db = Db.curDb()

        entres = Ed.Editor.entSel("\nSelect an mtext", Db.MText.desc())
        if entres[0] != Ed.PromptStatus.eOk:
            print("Oops: ", entres[0])
            return

        ctxman = db.objectContextManager()
        ctxcoll = ctxman.contextCollection("ACDB_ANNOTATIONSCALES")

        mt = Db.MText(entres[1], Db.OpenMode.kForWrite)

        # don't need to cast unless we want to use AnnotationScale methods
        if ctxcoll.hasContext("1:100"):
            annoScale = ctxcoll.getContext("1:100")
            mt.removeContext(annoScale)

    except Exception as err:
        traceback.print_exception(err)


# example using Db.AnnotationScale.desc, no need to cast
def PyRxCmd_doit3() -> None:
    try:
        db = Db.curDb()
        ctxman = db.objectContextManager()
        ctxcoll = ctxman.contextCollection("ACDB_ANNOTATIONSCALES")

        # optional
        annoScales = ctxcoll.toList(Db.AnnotationScale.desc())

        for annoScale in annoScales:
            print(annoScale.getName())

    except Exception as err:
        traceback.print_exception(err)
