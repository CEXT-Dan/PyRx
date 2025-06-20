import traceback

from pyrx import Ap, Ge


@Ap.Command()
def xextrudededsolid() -> None:
    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axModel = axDoc.modelSpace()

        # compute the vector
        direction = Ge.Point3d(15, 20, 0) - Ge.Point3d(10, 0, 0)

        # create the circle
        circle = axModel.addCircle(Ge.Point3d(10, 0, 0), 5)

        # set the normal to the extrusion direction
        circle.setNormal(direction)

        # create a region to extrude
        regions = axModel.addRegion([circle])

        _solid = axModel.addExtrudedSolid(regions[0], direction.length(), 0.0)

        circle.erase()

    except Exception as err:
        traceback.print_exception(err)
