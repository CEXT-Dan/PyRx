import traceback

import contextily as cx
import rasterio
import xmltodict
from pyproj import Transformer
from pyrx_imp import Ap, Cv, Db, Ed, Ge
from rasterio.warp import Resampling, calculate_default_transform, reproject

# all coordinate values in epsg:4326 until transformFromLonLatAlt
# https://contextily.readthedocs.io/en/latest/intro_guide.html
# https://rasterio.readthedocs.io/en/latest/topics/reproject.html

print("added command - cvgetosmtin")

lonlat_to_webmercator = Transformer.from_crs("EPSG:4326", "EPSG:3857", always_xy=True)

def getTransform(lon, lat):
    x, y = lonlat_to_webmercator.transform(lon, lat)
    return x, y

def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

def getGeoDataId(db: Db.Database) -> Db.ObjectId:
    if not Db.Core.hasGeoData(db):
        data = Db.GeoData()
        data.setBlockTableRecordId(db.modelSpaceId())
        return data.postToDb()
    return Db.Core.getGeoDataObjId(db)

def getBounds(tin: Cv.CvDbTinSurface, geoData: Db.GeoData):
    bounds = tin.boundingBox()
    # print(bounds)
    min = geoData.transformToLonLatAlt(Ge.Point3d(bounds[0].x, bounds[0].y, 0))
    max = geoData.transformToLonLatAlt(Ge.Point3d(bounds[1].x, bounds[1].y, 0))
    return min.x, min.y, max.x, max.y

def PyRxCmd_cvgetosmtin():
    try:
        db = Db.curDb()
        _host = Ap.Application.hostAPI()

        # checking for georeference, ifnot request and set
        geoDataId = getGeoDataId(db)
        if geoDataId.isNull():
            return
        geoData = Db.GeoData(geoDataId, Db.OpenMode.kForRead)
        if not geoData.coordinateSystem():
            print("\nAborting, please set the coordinate system first")
            return
        if not geoData.coordinateType() == Db.GeoTypeOfCoordinates.kCoordTypGrid:
            print("\nSetting map grid required")
            return

        # select input
        esel = Ed.Editor.entSel("\nSelect TIN Surface: ", Cv.CvDbTinSurface.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0])) 
            return
        
        pSurface = Cv.CvDbTinSurface(esel[1], Db.OpenMode.kForRead)
        geoCS = xmltodict.parse(geoData.coordinateSystem())
        epsg = geoCS['Dictionary']['Alias'][0]['@id']
        t_epsg = "EPSG:" + str(epsg)
        print("\nDrawing has EPSG code: " + str(t_epsg))

        # transform 4326 -> 3587, get raster and transform to target EPSG
        # we need to ask for the file path here

        path = Ed.Core.getFileD("Enter file name for storing raster", "myrasterfile.tif", "tif", 33)
        n_path= path[:-4]+'_warped.tif'

        west, south, east, north = getBounds(pSurface, geoData)
        west_trans, south_trans = getTransform(west, south)
        east_trans, north_trans = getTransform(east, north)
        img, ext = cx.bounds2raster(west_trans, south_trans, east_trans, north_trans, path=path, zoom=15, source=cx.providers.OpenTopoMap)

        dst_crs = t_epsg

        with rasterio.open(path) as src:
            transform, width, height = calculate_default_transform(
                src.crs, dst_crs, src.width, src.height, *src.bounds)
            kwargs = src.meta.copy()
            kwargs.update({
                'crs': dst_crs,
                'transform': transform,
                'width': width,
                'height': height
            })

            with rasterio.open(n_path, 'w', **kwargs) as dst:
                for i in range(1, src.count + 1):
                    reproject(
                        source=rasterio.band(src, i),
                        destination=rasterio.band(dst, i),
                        src_transform=src.transform,
                        src_crs=src.crs,
                        dst_transform=transform,
                        dst_crs=dst_crs,
                        resampling=Resampling.nearest)
        print("\nRaster was transformed to " + str(t_epsg) + " and saved")

    except Exception:
        traceback.print_exc()
