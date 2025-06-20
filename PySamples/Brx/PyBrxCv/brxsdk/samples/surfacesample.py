import traceback

from pyrx import Cv, Db, Ed, Ge


def samp_tincreate() -> None:
    try:
        # defining offset parameters
        INNER_SURF_OFFSET = 10.0
        OUTER_SURF_OFFSET = 50.0

        # defining inner points
        points = []
        points.append(Ge.Point3d(-INNER_SURF_OFFSET, -INNER_SURF_OFFSET, 0))
        points.append(Ge.Point3d(INNER_SURF_OFFSET, -INNER_SURF_OFFSET, 0))
        points.append(Ge.Point3d(INNER_SURF_OFFSET, INNER_SURF_OFFSET, 0))
        points.append(Ge.Point3d(-INNER_SURF_OFFSET, INNER_SURF_OFFSET, 0))

        # defining outer points
        points.append(Ge.Point3d(-OUTER_SURF_OFFSET, -OUTER_SURF_OFFSET, 10))
        points.append(Ge.Point3d(OUTER_SURF_OFFSET, -OUTER_SURF_OFFSET, 10))
        points.append(Ge.Point3d(OUTER_SURF_OFFSET, OUTER_SURF_OFFSET, 10))
        points.append(Ge.Point3d(-OUTER_SURF_OFFSET, OUTER_SURF_OFFSET, 10))

        # open database and add surface object
        db = Db.curDb()
        pSurface = Cv.CvDbTinSurface()

        # add initial points to the surface
        pSurface.initialize(
            Ge.Point3d(-OUTER_SURF_OFFSET, -OUTER_SURF_OFFSET, 0),
            Ge.Point3d(OUTER_SURF_OFFSET, OUTER_SURF_OFFSET, 10),
            100,
        )

        # add list of points
        successful = pSurface.addPoints(points)
        if not successful:
            print("Adding points to TIN Surface failed\n")
            return

        db.addToModelspace(pSurface)

    except Exception as err:
        traceback.print_exception(err)


def samp_tinlistall() -> None:
    try:
        # fetch database
        _db = Db.curDb()
        filter = [(Db.DxfCode.kDxfStart, "BsysCvDbTinSurface")]
        ssres = Ed.Editor.selectAll(filter)
        if ssres[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(ssres[0]))
            return

        oIds = ssres[1].objectIds()
        print("\nThere is {} TIN surfaces in the drawing.".format(len(oIds)))
        for oId in oIds:
            print("\nTheir handles are: {}".format(oId))

    except Exception as err:
        traceback.print_exception(err)


def samp_tinaddbreakline() -> None:
    try:
        # fetch database and entity
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        constraints = []
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)

        # prepare points list
        points = []
        points.append(Ge.Point3d(-20, -20, 5))
        points.append(Ge.Point3d(-30, 0, 0))
        points.append(Ge.Point3d(-20, 20, -5))

        # add breakline and attach points to it
        breakline1 = Cv.CvDbTinSurfaceBreakline(Cv.TinBreaklineType.eTinBreaklineNormal)
        breaklineId = 1007510122
        breakline1.setData(breaklineId, points)
        constraints.append(breakline1)

        # create a polyline and add to model
        pPolyline = Db.Polyline()
        pPolyline.addVertexAt(0, Ge.Point2d(20, -20), 0.5, -1.0, -1.0)
        pPolyline.addVertexAt(1, Ge.Point2d(30, 0), 0.0, -1.0, -1.0)
        pPolyline.addVertexAt(2, Ge.Point2d(20, 20), 0.0, -1.0, -1.0)
        pPolyline.setClosed(False)

        plid = db.addToModelspace(pPolyline)

        # create 2nd breakline and add to surface
        breakline2 = Cv.CvDbTinSurfaceBreakline(Cv.TinBreaklineType.eTinBreaklineNormal)
        breakline2.setDataId(plid, 0.1)
        constraints.append(breakline2)

        successful = pSurface.addConstraints(constraints, True)
        if not successful:
            print("\nFailed to add constraints\n")
            return

        # print summary
        print(len(pSurface.getConstraints()))

    except Exception as err:
        traceback.print_exception(err)


def samp_tinaddboundary() -> None:
    try:
        # fetching database and select entity
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # define framing variables
        SHOW_BOUNDARY = 5.0
        HIDE_BOUNDARY = 9.0

        # create show/hide objects
        showBoundary = Cv.CvDbTinSurfaceBoundary(Cv.TinBoundaryType.eTinShow)
        hideBoundary = Cv.CvDbTinSurfaceBoundary(Cv.TinBoundaryType.eTinHide)

        # prepare point list for show boundary, attach to show object and set
        showBoundaryPoints = []
        showBoundaryPoints.append(Ge.Point3d(-SHOW_BOUNDARY, -SHOW_BOUNDARY, 0))
        showBoundaryPoints.append(Ge.Point3d(SHOW_BOUNDARY, -SHOW_BOUNDARY, 0))
        showBoundaryPoints.append(Ge.Point3d(SHOW_BOUNDARY, SHOW_BOUNDARY, 0))
        showBoundaryPoints.append(Ge.Point3d(-SHOW_BOUNDARY, SHOW_BOUNDARY, 0))

        showBoundaryId = 1054400123
        showBoundary.setData(showBoundaryId, showBoundaryPoints)

        # prepare polyline for hide boundary, attach to hide object and set
        pPolyline = Db.Polyline()
        pPolyline.addVertexAt(0, Ge.Point2d(-HIDE_BOUNDARY, -HIDE_BOUNDARY), 0.0, -1.0, -1.0)
        pPolyline.addVertexAt(1, Ge.Point2d(HIDE_BOUNDARY, -HIDE_BOUNDARY), 0.5, -1.0, -1.0)
        pPolyline.addVertexAt(2, Ge.Point2d(HIDE_BOUNDARY, HIDE_BOUNDARY), 0.0, -1.0, -1.0)
        pPolyline.addVertexAt(3, Ge.Point2d(-HIDE_BOUNDARY, HIDE_BOUNDARY), 0.0, -1.0, -1.0)
        pPolyline.setClosed(True)

        # push to model
        plid = db.addToModelspace(pPolyline)
        hideBoundary.setDataId(plid, 0.1)

        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)
        successful = pSurface.addConstraint(hideBoundary, True)
        if not successful:
            print("\nFailed to add hideBoundary\n")
            return

        successful = pSurface.addConstraint(showBoundary, True)
        if not successful:
            print("\nFailed to add showBoundary\n")
            return

    except Exception as err:
        traceback.print_exception(err)


def samp_tinlistdata() -> None:
    try:
        # get database and select entity
        _db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface object, fetch information and print
        pSurface = Cv.CvDbTinSurface(esel[1])
        print("pointsCount", pSurface.pointsCount())
        print("trianglesCount", pSurface.trianglesCount())
        print("area2d", pSurface.area2d())
        print("area3d", pSurface.area3d())

        # get surface contstraits, determine type and print
        constraints = pSurface.getConstraints()
        for constraint in constraints:
            match constraint.constraintType():
                case Cv.TinConstraintType.eTinBreakline:
                    print("eTinBreakline")
                case Cv.TinConstraintType.eTinBoundary:
                    print("eTinBoundary")
                case Cv.TinConstraintType.eTinWall:
                    print("eTinWall")
                case _:
                    print("oops")

            print("is a database object: ", constraint.isDbResident())

    except Exception as err:
        traceback.print_exception(err)


def samp_tinremovebreakline() -> None:
    try:
        # get database and select entity
        _db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface object, fetch information and print
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)

        # get surface contstraits and loop
        constraints = pSurface.getConstraints()
        for constraint in constraints:
            match constraint.constraintType():
                case Cv.TinConstraintType.eTinBreakline:
                    print("eTinBreakline")
                    pSurface.eraseConstraint(constraint.id(), True)
                case Cv.TinConstraintType.eTinWall:
                    print("eTinWall")
                    pSurface.eraseConstraint(constraint.id(), True)
                case _:
                    print("oops")

    except Exception as err:
        traceback.print_exception(err)


def samp_tinremoveboundary() -> None:
    try:
        # get database and select entity
        _db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface object, fetch information and print
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)

        # get surface contstraits and loop
        constraints = pSurface.getConstraints()
        for constraint in constraints:
            match constraint.constraintType():
                case Cv.TinConstraintType.eTinBoundary:
                    print("eTinBoundary")
                    pSurface.eraseConstraint(constraint.id(), True)
                case _:
                    print("oops")

    except Exception as err:
        traceback.print_exception(err)


def samp_tinchangestyle() -> None:
    try:
        # get database and select entity
        _db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface object and make checks
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)
        style = pSurface.style()
        if (style & Cv.TinSurfaceStyle.eTinStyleNone) != 0:
            print("\nNo style set")
        if (style & Cv.TinSurfaceStyle.eTinStylePoints) != 0:
            print("\nPoint style set")
        if (style & Cv.TinSurfaceStyle.eTinStyleBoundaryLine) != 0:
            print("\nBoundary style set")
        if (style & Cv.TinSurfaceStyle.eTinStyleTriangles) != 0:
            print("\nTriangle style set")
        if (style & Cv.TinSurfaceStyle.eTinStyleContours) != 0:
            print("\nColour style set")

        # get style input as integer between 0-2
        while True:
            ssResult = Ed.Editor.getInteger(
                "\nSet style(0 - off, 1 - triangles, 2 - contours and points) :"
            )
            if ssResult[0] == Ed.PromptStatus.eNormal:
                #                print(ssResult[1])
                if ssResult[1] in range(3):
                    break

        # update surface style as per input
        match ssResult[1]:
            case 0:
                print("\nSwitching off styles")
                pSurface.setStyle(Cv.TinSurfaceStyle.eTinStyleNone)
            case 1:
                print("\nSwitching style to triangles")
                pSurface.setStyle(Cv.TinSurfaceStyle.eTinStyleTriangles)
            case 2:
                print("\nSwitching style to contour and points")
                pSurface.setStyle(Cv.TinSurfaceStyle.eTinStyleContours)
                pSurface.setStyle(Cv.TinSurfaceStyle.eTinStylePoints)

        # get minor contour as positive float
        while True:
            ssResult = Ed.Editor.getDouble("\nEnter minor contour interval:")
            if ssResult[0] == Ed.PromptStatus.eNormal:
                if ssResult[1] > 0:
                    break
                print("\nEnter a positive value")
        minor = ssResult[1]

        # get major contour as positive float
        while True:
            ssResult = Ed.Editor.getDouble("\nEnter major contour interval:")
            if ssResult[0] == Ed.PromptStatus.eNormal:
                if ssResult[1] > 0 and ssResult[1] > minor:
                    break
                print("\nEnter a positive value larger than minor contour interval")
        major = ssResult[1]

        # set contour interval and enabling style
        pSurface.setMinorContoursInterval(minor)
        pSurface.setMajorContoursInterval(major)
        pSurface.setStyle(Cv.TinSurfaceStyle.eTinStyleContours)

        # get minor color input as integer between 0-255
        while True:
            ssResult = Ed.Editor.getInteger("\nEnter minor contour color:")
            if ssResult[0] == Ed.PromptStatus.eNormal:
                if ssResult[1] in range(256):
                    break
        minorColor = ssResult[1]

        # get major color input as integer between 0-255
        while True:
            ssResult = Ed.Editor.getInteger("\nEnter major contour color:")
            if ssResult[0] == Ed.PromptStatus.eNormal:
                if ssResult[1] in range(256):
                    break
        majorColor = ssResult[1]

        # fetching current color values, announcing and set
        curMinColor = pSurface.minorContoursColor()
        curMajColor = pSurface.majorContoursColor()
        print(
            "\nSwitching (minor, major) contour colors from: {} and {} to {} and {}".format(
                curMinColor[1], curMajColor[1], minorColor, majorColor
            )
        )
        pSurface.setMinorContoursColor(minorColor)
        pSurface.setMajorContoursColor(majorColor)

    except Exception as err:
        traceback.print_exception(err)


def samp_tinmerge() -> None:
    try:
        # get database and select surfaces
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect first TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return
        fSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)
        esel = Ed.Editor.entSel("\nSelect second TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return
        sSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)

        # get merge input as integer between 0-2
        while True:
            ssResult = Ed.Editor.getInteger("\n0 - merge to existing, 1 - create new surface")
            if ssResult[0] == Ed.PromptStatus.eNormal:
                if ssResult[1] in range(2):
                    break

        match ssResult[1]:
            case 0:
                try:
                    fSurface.merge(sSurface)
                    print("\nMerged second to first surface")
                except Exception as e:
                    print("\nMerging surfaces failed",e)
            case 1:
                try:
                    nSurface = Cv.CvDbTinSurface.mergeSurfaces(fSurface, sSurface)
                    db.addToModelspace(nSurface)
                    print("\nCreating new surface from first and second")
                except Exception as e:
                    print("\nCreating new surface failed",e)

    except Exception as err:
        traceback.print_exception(err)


def samp_tinmesh() -> None:
    try:
        # get database and select entity
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface object and get min/max
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForWrite)
        _maxEle = pSurface.maxElevation()
        _minEle = pSurface.minElevation()

        # we do not distinguish between TinSurfaceMeshType.TinSurfaceMeshDepth and TinSurfaceMeshType.TinSurfaceMeshElevation
        # we consider them being one relative order and one absolute and treat them the same

        # get mesh depth +1m
        mshAbove = pSurface.subDMesh()
        for i in range(mshAbove.numOfVertices()):
            ver = mshAbove.getVertexAt(i)
            ver += Ge.Vector3d.kZAxis * 1  # adding 1 to z-axis
            mshAbove.setVertexAt(i, ver)
        mshAbove.setColorIndex(1)
        db.addToModelspace(mshAbove)
        print("\nAdded mesh to model")

        # get mesh depth -1m
        mshBelow = pSurface.subDMesh()
        for i in range(mshBelow.numOfVertices()):
            ver = mshBelow.getVertexAt(i)
            ver -= Ge.Vector3d.kZAxis * 1  # substracting 1 to z-axis
            mshBelow.setVertexAt(i, ver)
        mshBelow.setColorIndex(2)
        db.addToModelspace(mshBelow)
        print("\nAdded mesh to model")

    except Exception as err:
        traceback.print_exception(err)


def samp_tindrape() -> None:
    try:
        # get database and select entity
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface object, bounding box and max
        pSurface = Cv.CvDbTinSurface(esel[1])
        bbox = pSurface.boundingBox()
        maxEle = pSurface.maxElevation()

        # generating point3d collection
        pts = []
        pts.append(Ge.Point3d(bbox[1][0], bbox[1][1], maxEle))  # xmax,ymax,zmax
        pts.append(Ge.Point3d(bbox[0][0], bbox[0][1], maxEle))  # xmin,ymin,zmax
        pts.append(Ge.Point3d(bbox[0][0] + 10, bbox[0][1] + 10, maxEle))  # xmin+10,ymin+10,zmax
        pts.append(
            Ge.Point3d(bbox[0][0] + 10, (bbox[0][1] + bbox[1][1]) / 2, maxEle)
        )  # xmin+10,(ymin+ymax)/2,zmax
        pts.append(
            Ge.Point3d(bbox[1][0], (bbox[0][1] + bbox[1][1]) / 2, maxEle)
        )  # xmax,(ymin+ymax)/2,zmax

        # flushing collection to polyline and model
        pline = Db.Polyline()
        pline.setColorIndex(1, True)
        for i, pt in enumerate(pts):
            print(pt)
            pline.addVertexAt(i, Ge.Point2d(pt[0], pt[1]), 0, -1, -1)
        _plid = db.addToModelspace(pline)

        # draping points to surface and drawing 3d poly to model
        dpts = pSurface.drapePoints(pts)
        for i, dpt in enumerate(dpts):
            dline = Db.Polyline3d()
            dline.setColorIndex(3, True)
            for j in range(len(dpt)):
                dline.appendVertex(Db.Polyline3dVertex(dpt[j]))
            _dlid = db.addToModelspace(dline)

    except Exception as err:
        traceback.print_exception(err)


def samp_tinvolumesurface() -> None:
    try:
        # get database and select entity
        db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return

        # get surface, clone , offset etc. not working currently
        CLONED_SURFACE_OFFSET = 10
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForRead)
        cSurface = Cv.CvDbTinSurface.cloneFrom(pSurface)
        cSurface.raiseSurface(CLONED_SURFACE_OFFSET)
        vSurface = Cv.CvDbVolumeSurface()
        vSurface.initialize(pSurface, cSurface, [])
        if vSurface.area2d() * CLONED_SURFACE_OFFSET == vSurface.fillVolume():
            print("\nVolume between the surfaces: {}".format(vSurface.fillVolume()))
        else:
            print("\nVolume was wrongly calculated!")
        db.addToModelspace(cSurface)
        db.addToModelspace(vSurface)

    except Exception as err:
        traceback.print_exception(err)


def samp_tinvolumesurfaceelevation() -> None:
    try:
        # get database and select entity
        _db = Db.curDb()
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
            return
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForRead)

        # get an elevation as float
        ssResult = Ed.Editor.getDouble("\nEnter an elevation reference level:")
        if ssResult[0] == Ed.PromptStatus.eNormal:
            elev = ssResult[1]

        # do volume calculations
        eSurface = Cv.CvDbVolumeSurface()
        eSurface.initialize(pSurface, elev, Cv.VolumeSurfaceType.eTinVolumeToElevation, [])
        dSurface = Cv.CvDbVolumeSurface()
        dSurface.initialize(pSurface, elev, Cv.VolumeSurfaceType.eTinVolumeToDepth, [])
        print(
            "\nElevation volumes calculated: fill volume {}, cut volume {}".format(
                eSurface.fillVolume(), eSurface.cutVolume()
            )
        )
        print(
            "\nDepth volumes calculated: fill volume {}, cut volume {}".format(
                dSurface.fillVolume(), dSurface.cutVolume()
            )
        )

    except Exception as err:
        traceback.print_exception(err)


def samp_tinvolumesurfacebounded() -> None:
    try:
        # defining offset parameters
        SURFACE_SIZE = 10.0

        # defining roofShapedPoints
        roofShapedPoints = []
        roofShapedPoints.append(Ge.Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0))
        roofShapedPoints.append(Ge.Point3d(0, -SURFACE_SIZE, SURFACE_SIZE))
        roofShapedPoints.append(Ge.Point3d(SURFACE_SIZE, -SURFACE_SIZE, 0))
        roofShapedPoints.append(Ge.Point3d(SURFACE_SIZE, SURFACE_SIZE, 0))
        roofShapedPoints.append(Ge.Point3d(0, SURFACE_SIZE, SURFACE_SIZE))
        roofShapedPoints.append(Ge.Point3d(-SURFACE_SIZE, SURFACE_SIZE, 0))

        # defining flatPoints
        flatPoints = []
        flatPoints.append(Ge.Point3d(-SURFACE_SIZE, -SURFACE_SIZE, SURFACE_SIZE / 2))
        flatPoints.append(Ge.Point3d(0, -SURFACE_SIZE, SURFACE_SIZE / 2))
        flatPoints.append(Ge.Point3d(SURFACE_SIZE, -SURFACE_SIZE, SURFACE_SIZE / 2))
        flatPoints.append(Ge.Point3d(SURFACE_SIZE, SURFACE_SIZE, SURFACE_SIZE / 2))
        flatPoints.append(Ge.Point3d(0, SURFACE_SIZE, SURFACE_SIZE / 2))
        flatPoints.append(Ge.Point3d(-SURFACE_SIZE, SURFACE_SIZE, SURFACE_SIZE / 2))

        # open database and add surface object
        db = Db.curDb()

        # add initial points to the surface
        tSurface = Cv.CvDbTinSurface()
        tSurface.initialize(
            Ge.Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0),
            Ge.Point3d(SURFACE_SIZE, SURFACE_SIZE, 0),
            len(roofShapedPoints),
        )
        _successful = tSurface.addPoints(roofShapedPoints)

        # add initial points to the surface
        tfSurface = Cv.CvDbTinSurface()
        tfSurface.initialize(
            Ge.Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0),
            Ge.Point3d(SURFACE_SIZE, SURFACE_SIZE, 0),
            len(flatPoints),
        )
        _successful = tfSurface.addPoints(flatPoints)

        db.addToModelspace(tSurface)
        db.addToModelspace(tfSurface)

        # volSurface1 bound the volume calculation to the upper left quarter of the created surface
        bdrNDBR = []
        bdrNDBR.append(Ge.Point3d(-SURFACE_SIZE, 0, 0))
        bdrNDBR.append(Ge.Point3d(0, 0, 0))
        bdrNDBR.append(Ge.Point3d(0, SURFACE_SIZE, 0))
        bdrNDBR.append(Ge.Point3d(-SURFACE_SIZE, SURFACE_SIZE, 0))
        volSurface1 = Cv.CvDbVolumeSurface()
        volSurface1.initialize(tSurface, tfSurface, bdrNDBR)

        # volSurface2 ound the volume calculation to the right half of the created surface
        pPolyline = Db.Polyline()
        pPolyline.addVertexAt(0, Ge.Point2d(0, -SURFACE_SIZE), 0, 0, 0)
        pPolyline.addVertexAt(1, Ge.Point2d(SURFACE_SIZE, -SURFACE_SIZE), 0, 0, 0)
        pPolyline.addVertexAt(2, Ge.Point2d(SURFACE_SIZE, SURFACE_SIZE), 0, 0, 0)
        pPolyline.addVertexAt(3, Ge.Point2d(0, SURFACE_SIZE), 0, 0, 0)
        pPolyline.setClosed(True)
        db.addToModelspace(pPolyline)
        volSurface2 = Cv.CvDbVolumeSurface()
        volSurface2.initialize(
            tSurface, 0.0, Cv.VolumeSurfaceType.eTinVolumeToElevation, pPolyline.id(), 0.1
        )

        print(
            "\nvolSurface1 volumes calculated: fill volume {}, cut volume {}".format(
                volSurface1.fillVolume(), volSurface1.cutVolume()
            )
        )
        print(
            "\nvolSurface2 volumes calculated: fill volume {}, cut volume {}".format(
                volSurface2.fillVolume(), volSurface2.cutVolume()
            )
        )

    except Exception as err:
        traceback.print_exception(err)


# ToDo
# sampTinMerge
# samp_do_TINListAllHandles
# sampTinToColorElevation
# sampTinToColorSlope
# sampTinJig
# sampGradingParameters
# samp_GradingSetRegion
# generateColorSheme
##generateMeshes
##generateFaces
# do_colorSchemesByElevation
# do_colorSchemesBySlope
# do_TINJig
