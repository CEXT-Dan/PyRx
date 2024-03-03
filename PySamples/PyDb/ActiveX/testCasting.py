# import
from pyrx_impx import Rx
from pyrx_impx import Ge
from pyrx_impx import Gi
from pyrx_impx import Db
from pyrx_impx import Ap
from pyrx_impx import Ed
from pyrx_impx import Gs
from pyrx_impx import Ax
import traceback

print("added command = docast")

def PyRxCmd_docast() -> None:
    try:
        acad = Ax.getApp()
        for layout in acad.ActiveDocument.Layouts:
            if layout.ModelType:
                continue
            for entity in layout.Block:
                if entity.EntityName != 'AcDbBlockReference':
                    continue
                #cast
                print(entity)
                ref = Ax.IAcadBlockReference(entity)
                if not ref.HasAttributes:
                    continue
                for attrib in ref.GetAttributes():
                    print("  {}: {}".format(attrib.TagString, attrib.TextString))
                    
    except Exception as err:
        traceback.print_exception(err)
        
        
