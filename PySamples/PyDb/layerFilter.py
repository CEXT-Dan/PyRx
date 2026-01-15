"""
PyRx Command Module for Creating Layer Filters and Layers.

This module provides a command to create multiple layers with different colors
and organize them into a layer filter group. The function demonstrates how to 
work with AutoCAD's layer management system, including creating layers,
setting their properties, and organizing them into filters.

Commands:
    doit - Creates 5 colored layers and organizes them into a filter group

Functions:
    doit() -> None
        Main command function that creates layers and sets up layer filtering

Example usage:
    Run 'doit' command in AutoCAD to create colored layers and organize them 
    into a "WooHooFilter" layer group.
"""

import traceback

from pyrx import Ap, Db


@Ap.Command()
def doit() -> None:
    """
    Create multiple colored layers and organize them into a filter group.

    This function performs the following operations:
    1. Defines a list of layer names to be created
    2. Gets the current database and layer filter manager
    3. Retrieves existing filters from the manager
    4. Creates a new layer group named "WooHooFilter"
    5. Uses a scope to create layers with different colors:
       - Each layer gets a unique color index (1-5)
       - Layers are created with names: wh_layer1 through wh_layer5
       - Each layer is added to the newly created filter group
    6. Adds the new filter group to the root filter and updates the manager

    The function demonstrates:
    - Working with LayerTableRecords to create layers
    - Using Color objects to set layer colors
    - Managing layer filters through LayerFilterManager
    - Proper scope management for database operations

    Example usage:
        In AutoCAD command line, type 'doit' then press Enter
        
    Creates 5 layers named:
        - wh_layer1 (color index 1)
        - wh_layer2 (color index 2)  
        - wh_layer3 (color index 3)
        - wh_layer4 (color index 4)
        - wh_layer5 (color index 5)

    All layers are grouped under a new filter called "WooHooFilter"
    """
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
