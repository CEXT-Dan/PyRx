import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed
import openpyxl as xl

# Some notes
# - AcFdFieldEvaluatorLoader and AcFdFieldReactor are embedded (BricsCAD does not have the reactors)
# - if you follow the normal %<\MyFieldID fcode>%, it should pick up your evaluator
# - Fields are like custom objects, name and evalname(FieldID) should be unique if you plan on sharing
# - AutoCAD caches the last evaluation, so of the evaluator it not loaded, your data should still show


# %<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|Show|A1>%
# %<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|Show|B1>%
# %<\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|strings|A4>%

print("added command - addevaluator")
print("added command - remevaluator")
print("added command - makeField")

# you may not need to override all of these, in AutoCAD it's enough just to override
# format, or evaluate.

# for platforms that do not support begin/endEvaluateFields, use command ended event
# or on idle to clear your cache 


class FieldEvaluator(Db.FieldEvaluator):
    def __init__(self, name, evalname):
        Db.FieldEvaluator.__init__(self, name, evalname)
        self.cache = {}

    def getValueFromXL(self, field: Db.Field):
        fcode = field.getFieldCode(Db.FieldCodeFlag.kFieldCode).strip("\\XLSXField")
        if fcode in self.cache:
            return str(self.cache[fcode])
        path, sheet, cell = fcode.split("|")
        workbook = xl.load_workbook(filename=path.strip(), read_only=True)
        worksheet = workbook[sheet]
        return str(worksheet[cell].value)

    def format(self, field: Db.Field):
        print("\nformat")
        return self.getValueFromXL(field)

    def compile(self, field: Db.Field, db: Db.Database, result: Db.AcValue):
        try:
            print("\ncompile")
            result.setString(self.getValueFromXL(field))
            return Db.FieldEvalStatus.kSuccess
        except Exception as err:
            traceback.print_exception(err)
            return Db.FieldEvalStatus.kOtherError

    def evaluate(
        self, field: Db.Field, ctx: int, db: Db.Database, result: Db.AcValue
    ) -> Db.FieldEvalStatus:
        try:
            print("\nevaluate")
            result.setString(self.getValueFromXL(field))
            return Db.FieldEvalStatus.kSuccess
        except Exception as err:
            traceback.print_exception(err)
            return Db.FieldEvalStatus.kOtherError

    # not in ZRX or BRX
    def beginEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            print("\nbeginEvaluateFields")
            self.cache.clear()
        except Exception as err:
            traceback.print_exception(err)

    # not in ZRX or BRX
    def endEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            print("\nendEvaluateFields")
            self.cache.clear()
        except Exception as err:
            traceback.print_exception(err)


evaluator = FieldEvaluator("XLSX Field", "XLSXField")


@Ap.Command()
def makeField():
    try:
        db = Db.curDb()
        fld = Db.Field(
            "%<\\XLSXField M:\\Dev\\Projects\\PyRxGit\\tests\\media\\testdata.xlsx|strings|A4>%"
        )
        fld.evaluate()
        mt = Db.MText()
        db.addToCurrentspace(mt)
        mt.setField(fld)

    except Exception as err:
        print(err)


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
