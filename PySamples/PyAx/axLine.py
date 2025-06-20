from pyrx import Ap, Ax, Ge, command

print("added command - axLine")


@command
def axLine():

    # get the application, document, and modelspace
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    axModel = axDoc.modelSpace()

    # add a lines to modelspace, then access it properties
    # use Ge.Point3d class instead of a variant
    axLine1 = axModel.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
    axLine2 = axModel.addLine(Ge.Point3d(0, 100, 0), Ge.Point3d(100, 0, 0))

    interdata = axLine1.intersectWith(axLine2, Ax.AcExtendOption.acExtendNone)
    if len(interdata) == 0:
        print("\nDoes not interset:")
        return

    axCircle = axModel.addCircle(interdata[0], 10)
    axCircle.setColor(Ax.AcColor.acCyan)
