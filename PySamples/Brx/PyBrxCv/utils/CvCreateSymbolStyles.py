import tempfile
import traceback

import requests

from pyrx import Ap, Cv, Db

# Literature
# https://www.sib.sachsen.de/download/CAD/Arbeitshilfe_zur_Anwendung_der_BFR-Verm_im_CAD(1).pdf
# Erläuterungen zu den Layernamen:
# # Die 800er Nummern am Anfang des Layernamens bezeichnen die Fachfolien der BFR-Vermessung
# https://www.sib.sachsen.de/download/CAD/2022-11-21_PLANVORLAGE_BFR-VERM_AutoCad2013.dxf

# Snippets
# https://github.com/CEXT-Dan/PyRx/discussions/131#discussioncomment-11278683
# https://github.com/CEXT-Dan/PyRx/issues/119#issuecomment-2480544502

target_url = "https://www.sib.sachsen.de/download/CAD/2022-11-21_PLANVORLAGE_BFR-VERM_AutoCad2013.dxf"

def importBlocksFromDb(destDb: Db.Database, srcDb: Db.Database) -> None:
    idmap = Db.IdMapping()
    srcblocks = Db.BlockTable(srcDb.blockTableId())

    destDb.wblockCloneObjects(
        srcblocks.recordIds(),
        destDb.blockTableId(),
        idmap,
        Db.DuplicateRecordCloning.kDrcIgnore,
    )

def PyRxCmd_cv_create_bfr_symbol_styles():
    try:
        _lock = Ap.AutoDocLock()
        destDb = Db.curDb()

        data = requests.get(target_url)
        sideDb = Db.Database(False, True)
        with tempfile.NamedTemporaryFile("wb", delete_on_close=False) as f:
            f.write(data.content)
            f.close()
            sideDb.dxfIn(f.name)
            sideDb.closeInput(True)

        importBlocksFromDb(destDb, sideDb)

        bt = Db.BlockTable(destDb.blockTableId())
        styleid = Cv.CvDbSymbolStyleManager.getManagerId(destDb)
        manager = Cv.CvDbSymbolStyleManager(styleid, Db.OpenMode.kForWrite)
        for name, id in bt.toDict().items(): 
            _btr = Db.BlockTableRecord(id, Db.OpenMode.kForRead)
            if name.startswith("8"):
                newid = manager.createSymbolStyle(name)
                style = Cv.CvDbSymbolStyle(newid)
                style.upgradeOpen()
                style.setCreatedBy("SSC")
                style.setSymbolType(Cv.SymbolType.eSymbolTypeBlock)
                style.setSymbolBlockId(id)
                style.downgradeOpen()

    except Exception:
        traceback.print_exc()