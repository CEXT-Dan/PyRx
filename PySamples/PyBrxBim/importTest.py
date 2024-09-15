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
            print("\nonIfcProduct {}".format( entity.IfcId()))
            #print(context, entity, isParent, parentEntity)
            return True
        except Exception:
            traceback.print_exc()

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
