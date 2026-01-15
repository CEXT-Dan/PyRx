"""
PyRx Command Module for Creating Tables in AutoCAD.

This module provides a command to create and populate a table entity in AutoCAD.
The table is created with specific dimensions, formatting, and content,
then added to the current drawing's model space.

Commands:
    pycreate_table - Creates a formatted table with headers, data, and merged cells

Functions:
    pycreate_table() -> None
        Main command function that creates a table entity with predefined structure

Example usage:
    Run 'pycreate_table' command in AutoCAD to create a sample table in the current drawing.
"""

from pyrx import Ap, Db, Ge

print("added command - pycreate_table")


# define a command
@Ap.Command()
def pycreate_table() -> None:
    """
    Create a formatted table entity and add it to the current drawing's model space.

    This function demonstrates creating a table with the following features:
    - 6 columns and 4 rows
    - Set column width (130) and row height (20)
    - Title in first cell ("Title")
    - Headers in second row (columns 0-3)
    - Sample data in subsequent rows
    - Custom coloring for title cell
    - Merged cells with "Merge Data" text

    The table is positioned at coordinates (300, 300, 0) and added to the model space.

    Example usage:
        In AutoCAD command line, type 'pycreate_table' then press Enter
        
    Attributes created:
        - Table entity with 6 columns x 4 rows
        - Header row with "Header" text in each column (rows 1-1)
        - Data rows with "Data" text in each cell (rows 2-5, cols 0-3)
        - Title cell at (0,0) with custom blue background and magenta text
        - Merged cells covering range from (4,2) to (5,3) containing "Merge Data"
    """
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a table, set the table's geometry, then call generateLayout
        table = Db.Table()
        table.setDatabaseDefaults()
        table.setSize(6, 4)          # 6 columns, 4 rows
        table.setColumnWidth(130)    # Set column width to 130 units
        table.setRowHeight(20)       # Set row height to 20 units
        table.generateLayout()       # Generate the internal layout structure

        # set position of the table in model space
        table.setPosition(Ge.Point3d(300, 300, 0))  # Position at (300, 300, 0)

        # populate the table with content
        table.setTextString(0, 0, "Title")     # Set title in first cell

        # add headers to second row (row index 1)
        for col in range(0, 4):
            table.setTextString(1, col, "Header")

        dataOffset = 2  # Start writing data from row 2

        # populate data rows
        for col in range(0, 4):
            for row in range(0, 4):
                table.setTextString(dataOffset + row, col, "Data")

        # set up colors for the title cell
        titleColor = Db.Color()
        titleColor.setRGB(0, 63, 255)      # Blue background color

        titleTextColor = Db.Color()
        titleTextColor.setRGB(255, 63, 255)  # Magenta text color

        # apply colors to the title cell
        table.setBackgroundColor(0, 0, titleColor)      # Set background color for (0,0)
        table.setContentColor(0, 0, 0, titleTextColor)  # Set text color for (0,0)

        # merge cells from (4,2) to (5,3) and add merged content
        table.mergeCells(4, 5, 2, 3)    # Merge rows 4-5, columns 2-3
        table.setTextString(4, 2, "Merge Data")  # Set text in merged cell

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(table)   # Add table to model space

    except Exception as err:
        print(err)
