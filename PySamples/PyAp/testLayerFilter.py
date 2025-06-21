import traceback

from pyrx import Ap, Db


def PyRxCmd_doit():
    try:
        layersNames = ["layer_1", "layer_2", "layer_3", "layer_4", "layer_5"]
        db = Db.curDb()

        lm = Ap.LayerFilterManager()
        fliter = lm.getFilters()

        newFilter = Ap.LayerGroup()

        lt = Db.LayerTable(db.layerTableId(), Db.OpenMode.kForWrite)
        for name in layersNames:
            ltr = Db.LayerTableRecord()
            ltr.setName(name)
            newFilter.addLayerId(lt.add(ltr))
            ltr.close()  # must be closed
        lt.close()  # must be closed

        newFilter.setName("My Filter")
        fliter[0].addNested(newFilter)
        lm.setFilters(fliter[0], newFilter)

    except Exception as err:
        traceback.print_exception(err)
