import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed
import openpyxl as xl

#%<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|Show|A1>%
#%<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|Show|B1>%
#%<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|strings|A4>%


print("added command - addevaluator")
print("added command - remevaluator")


class FieldEvaluator(Db.FieldEvaluator):
    def __init__(self, name, evalname):
        Db.FieldEvaluator.__init__(self, name, evalname)
        self.cache = {}

    def evaluate(
        self, fld: Db.Field, ctx: int, db: Db.Database, res: Db.AcValue
    ) -> Db.FieldEvalStatus:
        try:
            fcode = fld.getFieldCode(Db.FieldCodeFlag.kFieldCode).strip("\\XLSXField")
            if fcode in self.cache:
                res.setString(str(self.cache[fcode]))
                return Db.FieldEvalStatus.kSuccess

            path, sheet, cell = fcode.split("|")
            workbook = xl.load_workbook(filename=path.strip(), read_only=True)
            worksheet = workbook[sheet]
            res.setString(str(worksheet[cell].value))

            return Db.FieldEvalStatus.kSuccess
        except Exception as err:
            traceback.print_exception(err)
            return Db.FieldEvalStatus.kOtherError

    def beginEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            self.cache.clear()
        except Exception as err:
            traceback.print_exception(err)

    # clear your cache here
    def endEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            self.cache.clear()
        except Exception as err:
            traceback.print_exception(err)


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
