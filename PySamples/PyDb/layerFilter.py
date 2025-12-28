import traceback

from pyrx import Ap, Db


@Ap.Command()
def doit():
    try:
        # new layer names
        layersNames = ["wh_layer1", "wh_layer2", "wh_layer3", "wh_layer4", "wh_layer5"]

        # get manager for the current database
        db = Db.curDb()
        lm = Ap.LayerFilterManager(db)

        # get a list of the current filters
        filters = lm.getFilters()
        # for filter in filters:
        #     print(filter.name())

        # get the root filter we want to add to
        root = filters[0]

        # create a new group
        newFilter = Ap.LayerGroup()
        newFilter.setName("WooHooFilter")
       
        # Create new layers and add them to the filter
        @Ap.using_scope()
        def _scope():
            lt = Db.LayerTable(db.layerTableId(), Db.OpenMode.kForWrite)
            colorIndex = 0
            for name in layersNames:
                # color
                colorIndex += 1
                clr = Db.Color()
                clr.setColorIndex(colorIndex)
                # create
                ltr = Db.LayerTableRecord()
                ltr.setName(name)
                ltr.setColor(clr)
                ltrid = lt.add(ltr)
                # add
                newFilter.addLayerId(ltrid)

        root.addNested(newFilter)
        lm.setFilters(root, newFilter)

    except Exception as err:
        traceback.print_exception(err)
