import traceback

from pyrx import Ap, Db

print("added command pywbco")


def importDimStyleFromDb(destDb: Db.Database, srcDb: Db.Database) -> None:
    idmap = Db.IdMapping()
    srcdims = Db.DimStyleTable(srcDb.dimStyleTableId())

    destDb.wblockCloneObjects(
        srcdims.recordIds(),
        destDb.dimStyleTableId(),
        idmap,
        Db.DuplicateRecordCloning.kDrcIgnore,
    )


def PyRxCmd_pywbco() -> None:
    try:
        _lock = Ap.AutoDocLock()
        destDb = Db.curDb()
        sourceDb = Db.Database(False, True)
        sourceDb.readDwgFile("E://06457Submittal.dwg")
        sourceDb.closeInput(True)

        # scope
        importDimStyleFromDb(destDb, sourceDb)

    except Exception as err:
        traceback.print_exception(err)
