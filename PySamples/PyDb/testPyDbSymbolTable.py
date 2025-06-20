from pyrx import Db


def OnPyInitApp():
    print("\nOnPyInitApp")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")
    print("\nadded command = pydbsymtabletest :")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


def PyRxCmd_pydbsymtabletest() -> None:
    try:
        PyDbSymOpenForRead()
    except Exception as err:
        print(err)


def PyDbSymOpenForRead() -> None:
    db = Db.HostApplicationServices().workingDatabase()
    btid = db.blockTableId()
    table = Db.SymbolTable(btid, Db.OpenMode.kForRead)
    if table.isNullObj():
        print("\nFAIL")
    else:
        print("\nPASS({})".format(table.isA().name()))
    for id in table.recordIds():
        print(id)
