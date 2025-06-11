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


class FieldEvaluator(Db.FieldEvaluator):
    def __init__(self, name, evalname):
        Db.FieldEvaluator.__init__(self, name, evalname)
        self.cache = {}

    def getVersion(self, fld: Db.Field):
        version = 1
        versionkey = "XLSXFieldVersion"
        fld.setData(versionkey, Db.AcValue(1))
        if fld.hasData(versionkey):
            ver = fld.getData(versionkey)
            version = ver.getInt32()
            print("\nVersion = {}".format(ver.format()))
        return version

    def evaluate(
        self, fld: Db.Field, ctx: int, db: Db.Database, res: Db.AcValue
    ) -> Db.FieldEvalStatus:
        try:
            # if you need version your fields
            version = self.getVersion(fld)

            if version == 1:
                fcode = fld.getFieldCode(Db.FieldCodeFlag.kFieldCode).strip("\\XLSXField")
                if fcode in self.cache:
                    res.setString(str(self.cache[fcode]))
                    return Db.FieldEvalStatus.kSuccess

                path, sheet, cell = fcode.split("|")
                workbook = xl.load_workbook(filename=path.strip(), read_only=True)
                worksheet = workbook[sheet]
                print("\nCell Value = {}".format(str(worksheet[cell].value)))
                res.setString(str(worksheet[cell].value))

            return Db.FieldEvalStatus.kSuccess

        except Exception as err:
            traceback.print_exception(err)
            return Db.FieldEvalStatus.kOtherError

    # not in ZRX or BRX
    def beginEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            print("beginEvaluateFields")
            self.cache.clear()
        except Exception as err:
            traceback.print_exception(err)

    # not in ZRX or BRX
    def endEvaluateFields(self, ctx: int, db: Db.Database):
        try:
            print("endEvaluateFields")
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
