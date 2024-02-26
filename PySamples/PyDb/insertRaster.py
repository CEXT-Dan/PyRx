from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command do_raster")

def PyRxCmd_do_raster():
    try:
        dictName = "MY_IMAGE_NAME"
        db = Db.HostApplicationServices().workingDatabase()
        imageDictId = Db.RasterImageDef.imageDictionary(db)
        if imageDictId.isNull():
           imageDictId = Db.RasterImageDef.createImageDictionary(db)
           
        imageDef = Db.RasterImageDef()
        imageDef.setSourceFileName("C:\\Users\\Dan\\Pictures\\vb.jpg")
        imageDef.load()
       
        imageDict = Db.Dictionary(imageDictId, Db.OpenMode.kForWrite)
        imageDefId = imageDict.setAt(dictName,imageDef)
        imageDict.downgradeOpen()
        imageDef.downgradeOpen()
        
        image = Db.RasterImage()
        image.setDatabaseDefaults()
        image.setImageDefId(imageDefId)
        
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(image)
        
        Db.RasterImageDefReactor.setEnable(True)
        reactor = Db.RasterImageDefReactor()
        reactor.setOwnerId(image.objectId())
        
        #add a reactor
        reactorid = db.addObject(reactor)
        image.setReactorId(reactorid)
        imageDef.upgradeOpen()
        imageDef.addPersistentReactor(reactorid)
        
        #func will clean up this mess
        
    except Exception as err:
        print(err)