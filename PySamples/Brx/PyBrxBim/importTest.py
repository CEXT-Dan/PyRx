import traceback

from pyrx import Bim, Db, Ge

_guid = "{ABE15A35-A99F-4C28-9E12-BEF2713D1451}"
_desc = "MyIfcImportReactor"

path = "M:/Dev/Projects/PyRxGit/unitTests/testmedia/example project location.ifc"


def createBoxSolid(length, depth, height, translation: Ge.Vector3d, clr):
    try:
        solid = Db.Solid3d()
        solid.createBox(length, depth, height)
        mtx = Ge.Matrix3d()
        if not translation.isEqualTo(Ge.Vector3d.kIdentity):
            mtx.setToTranslation(translation)
            solid.transformBy(mtx)
        solid.setColorIndex(clr)
        db = Db.curDb()
        return db.addToModelspace(solid)
    except Exception as err:
        traceback.print_exception(err)
        return Db.ObjectId()


class IfcImportReactor(Bim.IfcImportReactor):
    def __init__(self, desc, guid):
        try:
            Bim.IfcImportReactor.__init__(self, desc, guid)
            self.m_onStartCalled = False
            self.m_onProductCalled = False
            self.m_completionCalled = False
            self.m_onIfcProductImportedCalled = False

        except Exception:
            traceback.print_exc()

    def onStart(self, context, project, info):
        try:
            self.m_onStartCalled = True
            # print(context, project, info)
        except Exception:
            traceback.print_exc()

    def onIfcProduct(self, context, entity, isParent, parentEntity):
        try:
            self.m_onProductCalled = True

            # get the name of the entity
            print(entity.isA().name())

            if entity.isKindOf(Bim.IfcEntityDesc.IfcWindow()):
                w = entity.getAttribute("OverallWidth")
                print("Width", w.type(), w.getReal())

                h = entity.getAttribute("OverallHeight")
                print("Height", h.type(), h.getReal())

                mat = context.getLocalPlacement(entity)
                createBoxSolid(100.0, 100.0, 100.0, mat.getTranslation(), 1)
                return True
            return False

        except Exception as err:
            traceback.print_exception(err)
            return False

    def beforeCompletion(self, context, success):
        try:
            self.m_completionCalled = True
            return True
        except Exception:
            traceback.print_exc()

    def onIfcProductImported(
        self, sourceEntity, isParent, sourceParentEntity, createdAcEntites, xform
    ):
        try:
            self.m_onIfcProductImportedCalled = True
        except Exception:
            traceback.print_exc()


def PyRxCmd_doit1():
    try:
        db = Db.curDb()
        reactor = IfcImportReactor(_desc, _guid)
        opts = Bim.IfcImportOptions()

        reactor.attachReactor()

        Bim.IfcImportOptions.importIfcFile(db, path, opts)

        print("onStartCalled", reactor.m_onStartCalled)
        print("onProductCalled", reactor.m_onProductCalled)
        print("completionCalled", reactor.m_completionCalled)
        print("onIfcProductImportedCalled", reactor.m_onIfcProductImportedCalled)

    except Exception:
        traceback.print_exc()
    finally:
        reactor.detachReactor()
