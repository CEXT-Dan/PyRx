import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

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

        pdfDict =  Db.Dictionary(nod.getAt(defDictKey), Db.OpenMode.kForWrite)
        idPdfDef = pdfDict.setAt("WOOHOO", pdfDef)
        
        pdfRef = Db.PdfReference()
        pdfRef.setDefinitionId(idPdfDef)
        pdfRef.setDatabaseDefaults()
       
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(pdfRef)
  
    except Exception as err:
        print(traceback.format_exc())
        
        
