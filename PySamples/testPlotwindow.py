import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyPl as Pl

# port of
# https://through-the-interface.typepad.com/through_the_interface/2007/10/plotting-a-wind.html

import traceback


def PyRxCmd_doit():
    try:

        doc = Ap.curDoc()
        db = doc.database()

        ppr = Ed.Editor.getPoint("\nSelect first corner of plot area: ")
        if ppr[0] != Ed.PromptStatus.eOk:
            return

        pcr = Ed.Editor.getCorner(
            ppr[1], "\nSelect second corner of plot area: ")
        if pcr[0] != Ed.PromptStatus.eOk:
            return

        rbfrom = [(5003, 1)]
        rbto = [(5003, 2)]

        p1 = Ed.Core.trans(ppr[1], rbfrom, rbto, 0)
        p2 = Ed.Core.trans(pcr[1], rbfrom, rbto, 0)

        ext = Db.Extents2d()
        ext.addPoint(Ge.Point2d(p1.x, p1.y))
        ext.addPoint(Ge.Point2d(p2.x, p2.y))

        btr = Db.BlockTableRecord(db.currentSpaceId())
        lo = Db.Layout(btr.getLayoutId())

        pi = Pl.PlotInfo()
        pi.setLayout(btr.getLayoutId())

        ps = Db.PlotSettings(lo.modelType())
        ps.copyFrom(lo)

        psv = Db.PlotSettingsValidator()

        psv.setPlotWindowArea(ps, ext)
        psv.setPlotType(ps, Db.PlotType.kWindow)

        psv.setUseStandardScale(ps, True)
        psv.setStdScaleType(ps, Db.StdScaleType.kScaleToFit)
        psv.setPlotCentered(ps, True)
        psv.setPlotCfgName(
            ps, "DWG to PDF.pc3", "ANSI_A_(8.50_x_11.00_Inches)")
        
        psv.setPlotRotation(ps, Db.PlotRotation.k0degrees)

        pi.setOverrideSettings(ps)

        piv = Pl.PlotInfoValidator()
        piv.setMediaMatchingPolicy(Pl.MatchingPolicy.kMatchEnabled)
        piv.validate(pi)

        if Pl.PlotFactory.processPlotState() != Pl.ProcessPlotState.kNotPlotting:
            return

        pe = Pl.PlotFactory.createPublishEngine()

        ppd = Pl.PlotProgressDialog(True, 1, True)
        ppd.setPlotMsgString(
            Pl.PlotMSGIndex.kDialogTitle, "Custom Plot Progress")

        ppd.setPlotMsgString(
            Pl.PlotMSGIndex.kCancelSheetBtnMsg, "Cancel Job")

        ppd.setPlotMsgString(
            Pl.PlotMSGIndex.kCancelSheetBtnMsg, "Cancel Sheet")

        ppd.setPlotMsgString(
            Pl.PlotMSGIndex.kSheetSetProgressCaption, "Sheet Set Progress")

        ppd.setPlotMsgString(
            Pl.PlotMSGIndex.kSheetProgressCaption,  "Sheet Progress")

        ppd.setPlotProgressRange(0, 100)
        ppd.setPlotProgressPos(0)

        pe.beginPlot(ppd)
        pe.beginDocument(pi, doc.fileName(), 1, True, "E:\\test-output")

        ppd.onBeginSheet()

        ppd.setSheetProgressRange(0, 100)
        ppd.setSheetProgressPos(0)

        ppi = Pl.PlotPageInfo()
        pe.beginPage(ppi, pi, True)

        pe.beginGenerateGraphics()
        pe.endGenerateGraphics()

        pe.endPage()
        ppd.setSheetProgressPos(100)
        ppd.onEndSheet()

        pe.endDocument()
        ppd.setPlotProgressPos(100)
        ppd.onEndPlot()
        pe.endPlot()

    except Exception as err:
        print(traceback.format_exc())
