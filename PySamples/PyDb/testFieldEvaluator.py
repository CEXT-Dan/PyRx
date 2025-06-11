import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed

# %%<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|Show|A1>%%


print("added command - addevaluator")
print("added command - remevaluator")


class FieldEvaluator(Db.FieldEvaluator):
    def __init__(self, name, evalname):
        Db.FieldEvaluator.__init__(self, name, evalname)

    def evaluate(
        self, fld: Db.Field, ctx: int, db: Db.Database, res: Db.AcValue
    ) -> Db.FieldEvalStatus:
        try:
            fcode = fld.getFieldCode(Db.FieldCodeFlag.kFieldCode)
            print("\n-{}-".format(fcode))
            res.setString("YAY")
            return Db.FieldEvalStatus.kSuccess
        except Exception as err:
            traceback.print_exception(err)
            return Db.FieldEvalStatus.kOtherError

    # create your cache here
    def beginEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            print("beginEvaluateFields")
        except Exception as err:
            traceback.print_exception(err)

    # clear your cache here
    def endEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            print("endEvaluateFields")
        except Exception as err:
            traceback.print_exception(err)


# name qand evalname, is the fieldcode
evaluator = FieldEvaluator("XLSX Field", "XLSXField")


@Ap.Command()
def addevaluator():
    try:
        engine: Db.FieldEngine = Db.FieldEngine.getEngine()
        engine.registerEvaluator(evaluator)
    except Exception as err:
        print(err)


@Ap.Command()
def remevaluator():
    try:
        engine: Db.FieldEngine = Db.FieldEngine.getEngine()
        engine.unregisterEvaluator(evaluator)
    except Exception as err:
        print(err)
