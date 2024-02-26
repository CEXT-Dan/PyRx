from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command - pycreate_line")
print("added command - pycreate_circle")
print("added command - pycreate_polyline")

# define a command


def PyRxCmd_pycreate_line():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a line
        line = Db.Line()
        line.setDatabaseDefaults()

        # use Ge point
        line.setStartPoint(Ge.Point3d(0, 0, 0))
        line.setEndPoint(Ge.Point3d(100, 100, 0))

        # set a color
        color = Db.Color()
        color.setRGB(255, 255, 0)
        line.setColor(color)

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(line)

        # python garbage collects here, line and model will be closed or deleted
        # here

    except Exception as err:
        print(err)

    # define a command


def PyRxCmd_pycreate_circle():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a circle
        circle = Db.Circle()
        circle.setDatabaseDefaults()

        # use Ge point
        circle.setCenter(Ge.Point3d(100, 100, 0))
        circle.setRadius(10)

        # set a color
        color = Db.Color()
        color.setRGB(0, 255, 255)
        circle.setColor(color)

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(circle)

        # python garbage collects here, circle and model will be closed or deleted
        # here

    except Exception as err:
        print(err)

        # define a command


def PyRxCmd_pycreate_polyline():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a Polyline
        pline = Db.Polyline(4)
        pline.setDatabaseDefaults()
        
        #zero based
        pline.addVertexAt(0, Ge.Point2d(0, 0))
        pline.addVertexAt(1, Ge.Point2d(100, 0))
        
        #add a buldge here
        pline.addVertexAt(2, Ge.Point2d(100, 100), 3, 0, 0)
        pline.addVertexAt(3, Ge.Point2d(0, 100))
        pline.setClosed(True)


        # set a color
        color = Db.Color()
        color.setRGB(255, 0, 255)
        pline.setColor(color)

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(pline)

        # python garbage collects here, circle and model will be closed or deleted
        # here

    except Exception as err:
        print(err)
