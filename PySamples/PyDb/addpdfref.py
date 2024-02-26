from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

import traceback

def OnPyInitApp():
    print("\nAdded command - pyaddpdf")
    

#define a function just for scope, dict is closed
def addToNod(nod, defDictKey):
        dict = Db.Dictionary()
        nod.upgradeOpen()
        nod.setAt(defDictKey,dict)
        nod.downgradeOpen()
        
def PyRxCmd_pyaddpdf():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        nod = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForRead)
        defDictKey = Db.UnderlayDefinition.dictionaryKey(Db.PdfDefinition.desc())
        
        if not nod.has(defDictKey):
            addToNod(nod,defDictKey)
            
        pdfDef = Db.PdfDefinition()
        pdfDef.setSourceFileName("E:\\JacksonSetup.pdf")
        
        #required for BricsCAD, just an example of a platform condition
        if  Db.HostApplicationServices().product() == "BricsCAD":
            pdfDef.load("")

        pdfDict =  Db.Dictionary(nod.getAt(defDictKey), Db.OpenMode.kForWrite)
        idPdfDef = pdfDict.setAt("WOOHOO", pdfDef)
        
        pdfRef = Db.PdfReference()
        pdfRef.setDefinitionId(idPdfDef)
        pdfRef.setDatabaseDefaults()
       
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(pdfRef)
  
    except Exception as err:
        print(traceback.format_exc())
        
        
