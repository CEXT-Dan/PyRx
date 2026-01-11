from pyrx import Ap, Ax, Ge, command

print("added command - axTable")

@command
def axTable():
    """
    This function demonstrates the use of ActiveX automation with AutoCAD through PyRx.
    
    The API being used is ActiveX (Automation) which allows Python scripts to interact 
    with AutoCAD by creating and manipulating AutoCAD objects through COM (Component Object Model)
    interfaces. This approach uses the Ax module that provides ActiveX automation
    capabilities for AutoCAD, enabling direct access to AutoCAD's object model and methods.
    
    Functionality:
    - Creates an AutoCAD application instance using ActiveX automation
    - Accesses the active document and modelspace through ActiveX interfaces
    - Adds a table to the modelspace using ActiveX methods
    - Manipulates table cell content and properties using ActiveX APIs
    - Performs geometric operations and selection handling using ActiveX geometry services
    
    Note: This implementation leverages PyRx's Ax module which provides ActiveX automation 
    bindings for AutoCAD, allowing direct access to AutoCAD's COM objects and their methods.
    The function demonstrates advanced ActiveX table manipulation including:
    - Table creation with specified dimensions
    - Cell text manipulation
    - Cell extent calculations
    - Selection region handling
    - Hit testing for cell identification
    
    Requirements:
    - AutoCAD must be installed on the system

    Example usage:
        Run from AutoCAD command line: 'axTable'
    """
    
    # Create AutoCAD application instance using ActiveX automation
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    axModel = axDoc.modelSpace()
    
    # Add a table to modelspace using ActiveX methods
    axTable = axModel.addTable(Ge.Point3d(0, 0, 0), 7, 5, 1, 5)

    # Set and retrieve text from a specific cell using ActiveX APIs
    axTable.setText(0, 0, "woowhoo")
    print(axTable.text(0, 0))

    # Calculate cell extents using ActiveX geometry methods
    cex11 = axTable.cellExtents(1, 1, False)
    cex43 = axTable.cellExtents(4, 3, False)

    # Create a selection region using ActiveX selection methods
    sssub = axTable.selectSubRegion(
        cex11[0],
        cex43[3],
        Ge.Vector3d.kZAxis,
        Ge.Vector3d.kXAxis,
        Ax.AcSelectType.acTableSelectCrossing,
        False,
    )

    # Apply the selection to the table using ActiveX selection methods
    axTable.setSubSelection(*sssub)

    # Perform hit testing and geometric calculations using ActiveX services
    pnt = cex11[0] + (cex43[3] - cex11[0]) * 0.5
    bhit, row, col = axTable.hitTest(pnt, Ge.Vector3d.kZAxis)

    # Modify cell properties using ActiveX methods
    axTable.setCellTextHeight(row, col, 0.8)
    axTable.setText(row, col, "Bingo")
