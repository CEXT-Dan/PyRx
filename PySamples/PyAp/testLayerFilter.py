import traceback

from pyrx import Ap, Db

# using drawing ..\tests\media\06457.dwg
print("Added command = pylayerfilter")

@Ap.Command()
def pylayerfilter():
    try:
        
        # create a set of existing layer names we want to filter
        layersNames = set(["1_1_WALLS", "1_8_TEXT", "1_7_DIMS", "1_5_TOPS", "1_CRP_DIMS"])
        
        # get the current database 
        db = Db.curDb()
        
        # get the layer manager, w're going to att to the root
        lm = Ap.LayerFilterManager()
        root, _current= lm.getFilters()

        # create a new filter
        newFilter = Ap.LayerGroup()
        newFilter.setName("My Happy Filter")
        
        # add a scope so the layer table is disposed
        @Ap.using_scope()
        def _():
            # get layer table
            lt = Db.LayerTable(db.layerTableId())
            for name , id in lt.toDict().items():
                if name in layersNames:
                    newFilter.addLayerId(id)
               
        # add and set to current      
        root.addNested(newFilter)
        lm.setFilters(root, newFilter)
 
    except Exception as err:
        traceback.print_exception(err)



