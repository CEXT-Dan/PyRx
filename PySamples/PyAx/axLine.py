from pyrx import Ap, Ax, Ge, command

print("added command - axLine")


@command
def axLine():
    """
    This function demonstrates the use of ActiveX automation with AutoCAD through PyRx.
    
    The API being used is ActiveX (Automation) which allows Python scripts to interact 
    with AutoCAD by creating and manipulating AutoCAD objects through COM (Component Object Model)
    interfaces. This approach uses the Ax module that provides ActiveX automation
    capabilities for AutoCAD, enabling direct access to AutoCAD's object model and methods.
    
    Functionality:
    - Creates an AutoCAD application instance using ActiveX automation
    - Accesses the active document and modelspace through ActiveX interfaces
    - Adds two lines to the modelspace using ActiveX methods
    - Calculates intersection point of the two lines using ActiveX geometry operations
    - Creates a circle at the intersection point with cyan color
    
    Note: This implementation leverages PyRx's Ax module which provides ActiveX automation 
    bindings for AutoCAD, allowing direct access to AutoCAD's COM objects and their methods.
    
    Requirements:
    - AutoCAD must be installed on the system
    
    Example usage:
        Run from AutoCAD command line: 'axLine'
    """
    
    # get the application, document, and modelspace using ActiveX automation
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    axModel = axDoc.modelSpace()

    # add a lines to modelspace, then access it properties
    # use Ge.Point3d class instead of a variant
    axLine1 = axModel.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
    axLine2 = axModel.addLine(Ge.Point3d(0, 100, 0), Ge.Point3d(100, 0, 0))

    interdata = axLine1.intersectWith(axLine2, Ax.AcExtendOption.acExtendNone)
    if len(interdata) == 0:
        print("\nDoes not intersect:")
        return

    axCircle = axModel.addCircle(interdata[0], 10)
    axCircle.setColor(Ax.AcColor.acCyan)
