import traceback

import gemgis as gg
import shapely
from dem_stitcher.stitcher import stitch_dem
from OSMPythonTools.nominatim import Nominatim

from pyrx import Cv, Db, Ed, Ge

# all coordinate values in epsg:4326 until transformFromLonLatAlt
# https://gis.stackexchange.com/questions/238533/extracting-points-from-linestring-or-polygon-and-making-dictionary-out-of-them-i
# https://gis.stackexchange.com/questions/469331/iterate-through-geodataframes-and-overlay-them-to-create-a-single-output
# https://gemgis.readthedocs.io/en/latest/getting_started/tutorial/62_Extracting_contour_lines_from_raster.html
# https://github.com/ACCESS-Cloud-Based-InSAR/dem-stitcher

print("added command - cvgetdemtin")

def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

def getGeoDataId(db: Db.Database) -> Db.ObjectId:
    if not Db.Core.hasGeoData(db):
        data = Db.GeoData()
        data.setBlockTableRecordId(db.modelSpaceId())
        return data.postToDb()
    return Db.Core.getGeoDataObjId(db)

def getLocation(location):
    nominatim = Nominatim()
    location = nominatim.query(location, wkt=True)
    return location
 
def getLocationRaster(location):
    # converting WKT to shapely and getting rectified boundary box
    ls = shapely.from_wkt(location.wkt())
    coords = shapely.envelope(ls).exterior.coords 
    # getting raster boundary coords and remote fetching + stitching raster to array
    bounds = [min(coords)[0], min(coords)[1], max(coords)[0], max(coords)[1]]
    # dem_0 = 'glo_30'
    # dem_1 = 'nasadem'
    # ellipsoidal_hgt = True
 
    X, p = stitch_dem(bounds, # X: array, p: TIF
                    dem_name='glo_30',  # Global Copernicus 30 meter resolution DEM
                    dst_ellipsoidal_height=False,
                    dst_area_or_point='Point')
    return X, p, bounds

def PyRxCmd_cvgetdemtin():
    try:
        # db = Db.HostApplicationServices().workingDatabase()
        db = Db.curDb()

        # checking for georeference, ifnot request and set
        geoDataId = getGeoDataId(db)
        if geoDataId.isNull():
            return
        geoData = Db.GeoData(geoDataId, Db.OpenMode.kForRead)
        if not geoData.coordinateSystem():
            print("\nAborting, please set the coordinate system first")
            return
        if not geoData.coordinateType() == Db.GeoTypeOfCoordinates.kCoordTypGrid:
            print("\nSetting map grid recommended")

        # checking for location
        ssResult = Ed.Editor.getString("\nEnter desired location name: ")
        if ssResult[0] == Ed.PromptStatus.eNormal : 
            try:
                location = getLocation(ssResult[1])
                print("\aUsing " + str(location.displayName()))
            except Exception as e:
                print("\nEnter a correct value",e)

        # getting raster for location
        X, p, bounds = getLocationRaster(location)
        print("\nFetched raster and stitched to one")

        # get input for contour interval and analyze raster
        ssResult = Ed.Editor.getInteger("\nEnter contour interval: ")
        if ssResult[0] == Ed.PromptStatus.eNormal : 
            if ssResult[1] < 0 :
                print("\nEnter a positive integer value")
        interval = ssResult[1]
        gdf = gg.raster.extract_contour_lines_from_raster(raster=X,
            extent=(bounds[0], bounds[2], bounds[1], bounds[3]),
            target_crs='EPSG:4326',
            interval = interval)
        gdf['points'] = gdf.apply(lambda x: [y for y in x['geometry'].coords], axis=1)
        
        # create TIN surface and append lines to it
        constraints = []
        pSurface = Cv.CvDbTinSurface()
        for index, row in gdf.iterrows(): 
            pline = Db.Polyline(len(row['points']))
            for idx, p in enumerate(row['points']):
                tp = geoData.transformFromLonLatAlt(p[0],p[1],0)
                pline.addVertexAt(idx,Ge.Point2d(tp[0], tp[1]))
            pline.setClosed(False)
            pline.setElevation(row['Z'])
            plid = db.addToModelspace(pline)
            breakline = Cv.CvDbTinSurfaceBreakline(Cv.TinBreaklineType.eTinBreaklineNormal)
            breakline.setDataId(plid, 0.1)
            breakline.setIntersectionElevation(Cv.TinIntersectionElevation.eTinNotAllowed)
            constraints.append(breakline)

        successful = pSurface.addConstraints(constraints, True)
        if not successful:
            print("\nFailed to add constraints\n")
            return
        pSurface.setStyle(Cv.TinSurfaceStyle.eTinStyleContours)
        pSurface.setMajorContoursInterval(50)
        pSurface.setMajorContoursColor(27)
        pSurface.setMinorContoursInterval(5)
        pSurface.setMinorContoursColor(253)
        pSurface.updateObjectData()
        db.addToModelspace(pSurface)

        # print summary
        print(len(pSurface.getConstraints()))  

    except Exception:
        traceback.print_exc()
