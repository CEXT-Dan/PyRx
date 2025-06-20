from pyrx_imp import Cv, Db, Ge


# determine angle between points
def angle_to(point1, point2):
    pa = Ge.Point3d(point1[0],point1[1],0)
    pb = Ge.Point3d(point2[0],point2[1],0)
    res = (pa-pb).angleTo(Ge.Vector3d.kYAxis,Ge.Vector3d.kZAxis)
    return res

def idsFromConstraintList(constraints):
    ids=[]
    for constraint in constraints:
        if Cv.CvDbTinSurfaceConstraint.className == constraint.className:
            ids.append(constraint.id())
    return ids

# create a sample surface
def createSampleTinSurface() -> Cv.CvDbTinSurface:

    INNER_OFFSET = 10
    OUTER_OFFSET = 50
    points = []

    points.append(Ge.Point3d(-INNER_OFFSET, -INNER_OFFSET, 0))
    points.append(Ge.Point3d(INNER_OFFSET, -INNER_OFFSET, 0))
    points.append(Ge.Point3d(INNER_OFFSET, INNER_OFFSET, 0))
    points.append(Ge.Point3d(-INNER_OFFSET, INNER_OFFSET, 0))

    points.append(Ge.Point3d(-OUTER_OFFSET, -OUTER_OFFSET, -10))
    points.append(Ge.Point3d(OUTER_OFFSET, -OUTER_OFFSET, -10))
    points.append(Ge.Point3d(OUTER_OFFSET, OUTER_OFFSET, 10))
    points.append(Ge.Point3d(-OUTER_OFFSET, OUTER_OFFSET, 10))

    pSurface = Cv.CvDbTinSurface()
    pSurface.setDatabaseDefaults()
    pSurface.initialize(Ge.Point3d(-OUTER_OFFSET, -OUTER_OFFSET, 0),
                        Ge.Point3d(OUTER_OFFSET, OUTER_OFFSET, 10),
                        100)
    successful = pSurface.addPoints(points)
    if not successful:
        print("failed @createSampleTinSurface")
    pSurface.updateObjectData()
    return pSurface

# create a sample 3d polyline
def create3dPolyline() -> Db.Polyline3d:
    pline = Db.Polyline3d()
    pline.setDatabaseDefaults()
    pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(-5, -20, 1)))
    pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(5, -20, 1)))
    pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(5, 20, 1)))
    pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(-5, 20, 1)))
    pline.setClosed(False)
    color = Db.Color()
    color.setRGB(255, 255, 0)
    pline.setColor(color)
    return pline
