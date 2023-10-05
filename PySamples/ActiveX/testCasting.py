# import
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback

import AcadComTypes24 as Ac
import ComAcadApplication24 as AcadApp


def PyRxCmd_docast():
    try:
        acad = Ac.getApp()
        for layout in acad.ActiveDocument.Layouts:
            if layout.ModelType:
                continue
            for entity in layout.Block:
                if entity.EntityName != 'AcDbBlockReference':
                    continue
                #cast
                ref = AcadApp.IAcadBlockReference(entity)
                if not ref.HasAttributes:
                    continue
                for attrib in ref.GetAttributes():
                    print("  {}: {}".format(attrib.TagString, attrib.TextString))
                    
    except Exception as err:
        traceback.print_exception(err)
        
        
