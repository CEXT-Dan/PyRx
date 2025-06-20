from pyrx_imp import Db, Ge

print("added command - pycreate_table")


# define a command
def PyRxCmd_pycreate_table():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a table, set the table's geometry, then call generateLayout
        table = Db.Table()
        table.setDatabaseDefaults()
        table.setSize(6, 4)
        table.setColumnWidth(130)
        table.setRowHeight(20)
        table.generateLayout()

        table.setPosition(Ge.Point3d(300, 300, 0))

        table.setTextString(0, 0, "Title")

        for col in range(0, 4):
            table.setTextString(1, col, "Header")

        dataOffset = 2

        for col in range(0, 4):
            for row in range(0, 4):
                table.setTextString(dataOffset + row, col, "Data")

        titleColor = Db.Color()
        titleColor.setRGB(0, 63, 255)

        titleTextColor = Db.Color()
        titleTextColor.setRGB(255, 63, 255)

        table.setBackgroundColor(0, 0, titleColor)
        table.setContentColor(0, 0, 0, titleTextColor)

        table.mergeCells(4, 5, 2, 3)
        table.setTextString(4, 2, "Merge Data")

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(table)

    except Exception as err:
        print(err)
