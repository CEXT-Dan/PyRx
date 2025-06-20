import traceback

from pyrx import Ap, Bim, Db, Ge

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

    def onBeginIfcModelSetup(self, context: Bim.IfcExportContext):
        try:
            self.m_onBeginIfcModelSetup = True

            self.m_idMainBuilding = Db.ObjectId()
            if self.m_idMainBuilding.isNull():
                return

            pDb = self.m_idMainBuilding.database()
            mainBuilding = Bim.BimBuilding.createNewBuilding(pDb, "Main Building")

            floor_1 = Bim.BimStory.createNewStory(pDb, "Main Building", "Floor 1")
            floor_2 = Bim.BimStory.createNewStory(pDb, "Main Building", "Floor 2")
            floor_1.setElevation(1.0)
            floor_2.setElevation(4.0)
            mainBuilding.assignToEntity(self.m_idMainBuilding)

            useFirstFloor = True
            ids: list[Db.ObjectId] = Bim.BimClassification.getAllUnclassified(pDb)
            for id in ids:
                if id == self.m_idMainBuilding:
                    continue
                if id.isDerivedFrom(Db.Solid3d.desc()):
                    Bim.BimClassification.classifyAs(id, Bim.BimElementType.eBimWall)
                if id.isDerivedFrom(Db.Face.desc()):
                    Bim.BimClassification.classifyAs(id, Bim.BimElementType.eBimFurnishingElement)
                if useFirstFloor:
                    floor_1.assignToEntity(id)
                else:
                    floor_2.assignToEntity(id)
                useFirstFloor = not useFirstFloor
        except Exception:
            traceback.print_exc()

    def onEntity(self, context: Bim.IfcExportContext, entity: Db.Entity):
        try:
            self.m_onEntity = True

            if entity.isA() == Db.Solid.desc():
                self.m_3dSolidEntFound = True

            model = context.ifcModel()
            db = context.database()
            if db.isNullObj():
                return Bim.IfcEntity()

            coordSys2d = Ge.Matrix2d.kIdentity
            coordSys3d = Ge.Matrix3d.kIdentity

            axis2d = context.getAxis2Placement2D(coordSys2d)
            axis3d = context.getAxis2Placement3D(coordSys3d)
            pt2d = context.getCartesianPoint2D(Ge.Point2d(1, 2))
            pt3d = context.getCartesianPoint3D(Ge.Point3d(1, 2, 3))
            vec2d = context.getDirection2D(Ge.Vector2d.kYAxis)
            vec3d = context.getDirection3D(Ge.Vector3d.kYAxis)

            m_numGeomToolsOk = 0
            if not axis2d.isNull():
                m_numGeomToolsOk += 1
            if not axis3d.isNull():
                m_numGeomToolsOk += 1
            if not pt2d.isNull():
                m_numGeomToolsOk += 1
            if not pt3d.isNull():
                m_numGeomToolsOk += 1
            if not vec2d.isNull():
                m_numGeomToolsOk += 1
            if not vec3d.isNull():
                m_numGeomToolsOk += 1
            print("m_numGeomToolsOk", m_numGeomToolsOk)

            if self.m_idMainBuilding.isNull():
                return Bim.IfcEntity()

            pFurnishing = Bim.IfcEntity.create(model, Bim.IfcEntityDesc.IfcFurnishingElement)
            if pFurnishing.isNull():
                return pFurnishing

            return pFurnishing

        except Exception as err:
            traceback.print_exception(err)
            return Bim.IfcEntity()

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
        doc = Ap.curDoc()
        reactor = IfcExportReactor(_desc, _guid)
        opts = Bim.IfcExportOptions()
        
        solid = Db.Solid3d()
        solid.createBox(50.0, 15.0, 8.0)
        doc.database().addToModelspace(solid)

        reactor.attachReactor()

        Bim.IfcExportOptions.exportIfcFile(doc,path,opts)

        print("adjustProjectData", reactor.m_adjustProjectData)
        print("onBeginIfcModelSetup", reactor.m_onBeginIfcModelSetup)
        print("onEntity", reactor.m_onEntity)
        print("onEndIfcModelSetup", reactor.m_onEndIfcModelSetup)
        print("onEntityConstructed", reactor.m_onEntityConstructed)

    except Exception:
        traceback.print_exc()
    finally:
        reactor.detachReactor()
