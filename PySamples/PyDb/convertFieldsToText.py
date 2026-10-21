import traceback
from pyrx import Ap, Db, Ed, Ge


@Ap.Command()
def doit():
    try:

        # "AcVar",
        # "AcVar.16.2",
        # "AcVar.17.0",
        # "AcDiesel",
        # "AcObjProp",
        # "AcObjProp.16.2",
        # "AcSm",
        # "AcSm.16.2",
        # "AcExpr",
        # "AcCount",
        # "AcCount2",

        ps, ss = Ed.Editor.select([(0, "*TEXT,ACAD_TABLE,INSERT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof {}:".format(ps))

        opt = Db.ConvertFieldToTextOption.kConvertFieldToTextNone
        stat = Db.Core.convertFieldsToText(ss.toList(), ["AcExpr"], opt)
        print(stat)

    except Exception as e:
        traceback.print_exc()
