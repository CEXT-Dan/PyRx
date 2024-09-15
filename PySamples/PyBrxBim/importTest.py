import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx, Bim
import wx

_guid = "{ABE15A35-A99F-4C28-9E12-BEF2713D1451}"
_desc = "MyIfcImportReactor"

path = "M:/Dev/Projects/PyRxGit/unitTests/testmedia/example project location.ifc"


class IfcImportReactor(Bim.IfcImportReactor):
    def __init__(self, desc, guid):
        Bim.IfcImportReactor.__init__(self, desc, guid)

    def onStart(self, context, project, info):
        print(context, project, info)

    def onIfcProduct(self, context, entity, isParent, parentEntity):
        print(context, entity, isParent, parentEntity)

    def beforeCompletion(self, context, success):
        print(context, success)

    def onIfcProductImported(
        self, sourceEntity, isParent, sourceParentEntity, createdAcEntites, xfrom
    ):
        print(sourceEntity, isParent, sourceParentEntity, createdAcEntites, xfrom)


def PyRxCmd_doit1():
    try:
        db = Db.curDb()
        reactor = IfcImportReactor(_desc, _guid)
        opts = Bim.IfcImportOptions()
        
        print(reactor.attachReactor())
        
        Bim.IfcImportOptions.importIfcFile(db,path,opts)
         
    except Exception:
        traceback.print_exc()
    finally:
        print(reactor.detachReactor())
        
        

