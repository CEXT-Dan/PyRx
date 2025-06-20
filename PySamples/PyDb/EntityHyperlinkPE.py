import traceback

from pyrx_imp import Db, Ed


def PyRxCmd_doit1():
    try:
        ps, id, _ = Ed.Editor.entSel("\nSelect: ")
        ent = Db.Entity(id, Db.OpenMode.kForWrite)
        pe = Db.EntityHyperlinkPE(ent.queryX(Db.EntityHyperlinkPE.desc()))
        hpc = pe.getHyperlinkCollection(ent)
        hpc.addTail("http://www.theswamp.org/", "theSwamp")
        pe.setHyperlinkCollection(ent, hpc)
    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_doit2():
    try:
        ps, id, _ = Ed.Editor.entSel("\nSelect: ")
        ent = Db.Entity(id)
        pe = Db.EntityHyperlinkPE(ent.queryX(Db.EntityHyperlinkPE.desc()))
        # if not pe.hasHyperlink(ent): #not in BricsCAD
        #     return
        hpc = pe.getHyperlinkCollection(ent)
        for idx in range(hpc.count()):
            lnk = hpc.item(idx)
            print(lnk.name(), lnk.description())
    except Exception as err:
        traceback.print_exception(err)