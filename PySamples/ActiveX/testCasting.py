# import
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback

import AxApp24 as Ax
import AxAppUtils24 as AxUtils


def PyRxCmd_docast():
    try:
        acad = AxUtils.getApp()
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
        
        
