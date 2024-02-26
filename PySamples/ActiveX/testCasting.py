# import
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
import traceback

import AxApp24 as Ax

def PyRxCmd_docast():
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
        
        
