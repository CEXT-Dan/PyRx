import pickle
import traceback

from pyrx import Db, Ed


def PyRxCmd_doit1() -> None:
    try:
        esres = Ed.Editor.entSel("\nSelect: ")
        if esres[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Entsel Error {}: ".format(esres[0]))

        data = {1: "WIDGET", 2: [1, 2, 3]}
        ent = Db.Entity(esres[1], Db.OpenMode.kForWrite)
        ent.setXDBinaryData("PYXD", pickle.dumps(data))

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit2() -> None:
    try:
        esres = Ed.Editor.entSel("\nSelect: ")
        if esres[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Entsel Error {}: ".format(esres[0]))

        ent = Db.Entity(esres[1], Db.OpenMode.kForWrite)
        bOut = ent.getXDBinaryData("PYXD")
        data = pickle.loads(bOut)
        data[1] = "pickle"
        data[2].append(4)
        ent.setXDBinaryData("PYXD", pickle.dumps(data))

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit3() -> None:
    try:
        filter = [(Db.DxfCode.kDxfXDataStart, 0), (Db.DxfCode.kDxfRegAppName, "PYXD")]
        ss = Ed.Editor.selectAll(filter)
        if ss[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Entsel Error {}: ".format(ss[0]))

        for id in ss[1].objectIds():
            ent = Db.Entity(id)
            _data = pickle.loads(ent.getXDBinaryData("PYXD"))
            # print(data)

    except Exception as err:
        traceback.print_exception(err)
