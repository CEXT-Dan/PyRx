import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx, Bim
import wx

_guid = "{ABE15A35-A99F-4C28-9E12-BEF2713D1452}"
_desc = "MyIfcExportReactor"

path = "E:\\temp\\out.ifc"


class IfcExportReactor(Bim.IfcExportReactor):
    def __init__(self, desc, guid):
        try:
            Bim.IfcExportReactor.__init__(self, desc, guid)
            self.m_adjustProjectData = False
            self.m_onBeginIfcModelSetup = False
            self.m_onEntity = False
            self.m_onEndIfcModelSetup = False
            self.m_onEntityConstructed = False
        except Exception:
            traceback.print_exc()

    def adjustProjectData(self, context, data: Bim.IfcProjectData):
        try:
            self.m_adjustProjectData = True

            data.setProjectName("BRX BIM IFC Export Sample")
            data.setProjectDescription("this is a BRX BIM sample case")
            data.setProjectPhase("testing")
            data.setProjectNorthAngle(0.0)

            data.setAuthorGivenName("noname")
            data.setAuthorFamilyName("none")
            data.setAuthorOrganization("private")

            data.setApplicationFullName("BRX BIM sample")
            data.setApplicationIdentifier("12345-67890")
            data.setApplicationVersion("1.2.3")
            data.setApplicationDeveloper("Bricsys BRX Team")

            data.setSiteName("OnTheMoon")
            data.setSiteDescription("crater on the moon")
            data.setSiteLandTitleNumber("xyz")
            data.setSiteInternalLocation("---xyz---")
            data.setSitePostalBox("12345")
            data.setSiteTown("MoonCity")
            data.setSiteRegion("MoonLand")
            data.setSitePostalCode("Moon12345")
            data.setSiteCountry("AllMoon")
            data.setSiteAddressLines("left-right")
            data.setSiteBuildableArea(123.0)
            data.setSiteTotalArea(234.0)
            data.setSiteBuildingHeightLimit = 33.0

            # print(context, project, info)
        except Exception:
            traceback.print_exc()

    def onBeginIfcModelSetup(self, context):
        try:
            self.m_onBeginIfcModelSetup = True
            # print(context, project, info)
        except Exception:
            traceback.print_exc()

    def onEntity(self, context, entity):
        try:
            self.m_onEntity = True
            return Bim.IfcEntity.create()
        except Exception as err:
            traceback.print_exception(err)
            return Bim.IfcEntity.create()

    def onEndIfcModelSetup(self, context):
        try:
            self.m_onEndIfcModelSetup = True
        except Exception:
            traceback.print_exc()

    def onEntityConstructed(self, contructedEntity, sourceBCEntity):
        try:
            self.m_onEntityConstructed = True
        except Exception:
            traceback.print_exc()


def PyRxCmd_doit1():
    try:
        db = Db.curDb()
        reactor = IfcExportReactor(_desc, _guid)
        opts = Bim.IfcImportOptions()

        reactor.attachReactor()

        Bim.IfcImportOptions.importIfcFile(db, path, opts)

        print("adjustProjectData", reactor.m_adjustProjectData)
        print("onBeginIfcModelSetup", reactor.m_onBeginIfcModelSetup)
        print("onEntity", reactor.m_onEntity)
        print("onEndIfcModelSetup", reactor.m_onEndIfcModelSetup)
        print("onEntityConstructed", reactor.m_onEntityConstructed)

    except Exception:
        traceback.print_exc()
    finally:
        reactor.detachReactor()
