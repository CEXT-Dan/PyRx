import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx, Bim
import wx

_guid = "{ABE15A35-A99F-4C28-9E12-BEF2713D1451}"
_desc = "MyIfcImportReactor"

path = "M:/Dev/Projects/PyRxGit/unitTests/testmedia/example project location.ifc"


class IfcImportReactor(Bim.IfcImportReactor):
    def __init__(self, desc, guid):
        try:
            Bim.IfcImportReactor.__init__(self, desc, guid)
        except Exception:
            traceback.print_exc()

    def onStart(self, context, project, info):
        try:
            print(context, project, info)
        except Exception:
            traceback.print_exc()

    def onIfcProduct(self, context, entity, isParent, parentEntity):
        try:
            try:
                if entity.isKindOf(Bim.IfcEntityDesc.IfcWindow):
                    print("yay")
                    print(entity.getAttribute("OverallHeight"))
                    print(context.getLocalPlacement(entity))
            
            
                # print(context.getLocalPlacement(entity))
                # print("\nonIfcProduct {}".format( entity.IfcId()))
                # print("\nonIfcProduct {}".format( entity.getAttribute()))
                # print(context, entity, isParent, parentEntity)
                return True
            except:
                return False
            
        except Exception as err:
            traceback.print_exception(err)
            return False
        

    def beforeCompletion(self, context, success):
        try:
            print(context, success)
        except Exception:
            traceback.print_exc()

    def onIfcProductImported(
        self, sourceEntity, isParent, sourceParentEntity, createdAcEntites, xfrom
    ):
        try:
            print(sourceEntity, isParent, sourceParentEntity, createdAcEntites, xfrom)
        except Exception:
            traceback.print_exc()


def PyRxCmd_doit1():
    try:
        db = Db.curDb()
        reactor = IfcImportReactor(_desc, _guid)
        opts = Bim.IfcImportOptions()

        print(reactor.attachReactor())

        Bim.IfcImportOptions.importIfcFile(db, path, opts)

    except Exception:
        traceback.print_exc()
    finally:
        print(reactor.detachReactor())
