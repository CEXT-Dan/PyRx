import traceback

from pyrx import Db, Ed, Ge

print("Added command ssdoit")


def PyRxCmd_ssdoit() -> None:
    try:
        db = Db.curDb()
        es = Ed.Editor.entSel("\nSelect: ", Db.Solid3d.desc())
        if es[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Yeet! {}: ".format(es[0]))
        sourceIds = [es[1]]

        pts = []
        ppr = Ed.Editor.getPoint("\nFirst Point: ")
        if ppr[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Yeet! {}: ".format(ppr[0]))
        pts.append(ppr[1])

        ppr = Ed.Editor.getPoint(ppr[1], "\nEnd Point: ")
        if ppr[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Yeet! {}: ".format(ppr[0]))
        pts.append(ppr[1])

        Ed.Editor.initGet(1, "2D 3D Live")
        kwres = Ed.Editor.getKword("\nEnter section type [2D/3D/Live]: ")
        if kwres[0] != Ed.PromptStatus.eOk:
            raise RuntimeError("Yeet! {}: ".format(ppr[0]))

        st = Db.SectionType.k3dSection
        sec = Db.Section(pts, Ge.Vector3d.kZAxis)
        sec.setState(Db.SectionState.kPlane)
        _secid = db.addToModelspace(sec)
        sec.enableLiveSection(False)
        sec.setHeight(Db.SectionHeight.kHeightAboveSectionLine, 3.0)
        sec.setHeight(Db.SectionHeight.kHeightBelowSectionLine, 1.0)

        match kwres[1]:
            case "2D":
                st = Db.SectionType.k2dSection
            case "3D":
                st = Db.SectionType.k3dSection
            case "Live":
                st = Db.SectionType.kLiveSection
            case _:
                st = Db.SectionType.k3dSection

        ss = Db.SectionSettings(sec.getSettings(), Db.OpenMode.kForWrite)
        ss.setCurrentSectionType(st)

        if st == Db.SectionType.kLiveSection:
            sec.enableLiveSection(True)
        else:
            ss.setSourceObjects(st, sourceIds)
            if st == Db.SectionType.k2dSection:
                ss.setVisibility(st, Db.SectionGeometry.kBackgroundGeometry, True)
                ss.setHiddenLine(st, Db.SectionGeometry.kBackgroundGeometry, False)
            elif st == Db.SectionType.k3dSection:
                ss.setVisibility(st, Db.SectionGeometry.kForegroundGeometry, True)

            opts = (
                Db.SectionGeneration.kSourceSelectedObjects | Db.SectionGeneration.kDestinationFile
            )
            ss.setGenerationOptions(st, Db.SectionGeneration(opts))

        ent = Db.Entity(sourceIds[0])
        geo = sec.generateSectionGeometry(ent)
        for items in geo:
            db.addToModelspace(items)

    except Exception as err:
        traceback.print_exception(err)
