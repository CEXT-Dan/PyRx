from __future__ import annotations

from pyrx import Ap, Ax


class TestAxDatabasePreferences:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_className(self):
        pref = self.axDoc.preferences()
        assert pref.className() == "AcadDatabasePreferences"

    def test_allowLongSymbolNames(self):
        pref = self.axDoc.preferences()
        pref.setAllowLongSymbolNames(False)
        assert pref.allowLongSymbolNames() == False
        pref.setAllowLongSymbolNames(True)
        assert pref.allowLongSymbolNames() == True

    def test_contourLinesPerSurface(self):
        pref = self.axDoc.preferences()
        orig = pref.contourLinesPerSurface()
        pref.setContourLinesPerSurface(orig + 1)
        assert pref.contourLinesPerSurface() == orig + 1
        pref.setContourLinesPerSurface(orig)
        assert pref.contourLinesPerSurface() == orig

    def test_displaySilhouette(self):
        pref = self.axDoc.preferences()
        pref.setDisplaySilhouette(False)
        assert pref.displaySilhouette() == False
        pref.setDisplaySilhouette(True)
        assert pref.displaySilhouette() == True

    def test_lineWeightDisplay(self):
        pref = self.axDoc.preferences()
        pref.setLineWeightDisplay(False)
        assert pref.lineWeightDisplay() == False
        pref.setLineWeightDisplay(True)
        assert pref.lineWeightDisplay() == True

    def test_lineweight(self):
        pref = self.axDoc.preferences()
        pref.setLineweight(Ax.AcLineWeight.acLnWt000)
        assert pref.lineweight() == Ax.AcLineWeight.acLnWt000
        pref.setLineweight(Ax.AcLineWeight.acLnWt050)
        assert pref.lineweight() == Ax.AcLineWeight.acLnWt050

    def test_maxActiveViewports(self):
        pref = self.axDoc.preferences()
        pref.setMaxActiveViewports(5)
        assert pref.maxActiveViewports() == 5
        pref.setMaxActiveViewports(10)
        assert pref.maxActiveViewports() == 10

    def test_objectSortByPSOutput(self):
        pref = self.axDoc.preferences()
        pref.setObjectSortByPSOutput(False)
        assert pref.objectSortByPSOutput() == False
        pref.setObjectSortByPSOutput(True)
        assert pref.objectSortByPSOutput() == True

    def test_objectSortByPlotting(self):
        pref = self.axDoc.preferences()
        pref.setObjectSortByPlotting(False)
        assert pref.objectSortByPlotting() == False
        pref.setObjectSortByPlotting(True)
        assert pref.objectSortByPlotting() == True

    def test_objectSortByRedraws(self):
        pref = self.axDoc.preferences()
        pref.setObjectSortByRedraws(False)
        assert pref.objectSortByRedraws() == False
        pref.setObjectSortByRedraws(True)
        assert pref.objectSortByRedraws() == True

    def test_objectSortByRegens(self):
        pref = self.axDoc.preferences()
        pref.setObjectSortByRegens(False)
        assert pref.objectSortByRegens() == False
        pref.setObjectSortByRegens(True)
        assert pref.objectSortByRegens() == True

    def test_objectSortBySelection(self):
        pref = self.axDoc.preferences()
        pref.setObjectSortBySelection(False)
        assert pref.objectSortBySelection() == False
        pref.setObjectSortBySelection(True)
        assert pref.objectSortBySelection() == True

    def test_objectSortBySnap(self):
        pref = self.axDoc.preferences()
        pref.setObjectSortBySnap(False)
        assert pref.objectSortBySnap() == False
        pref.setObjectSortBySnap(True)
        assert pref.objectSortBySnap() == True

    def test_oleLaunch(self):
        pref = self.axDoc.preferences()
        pref.setOLELaunch(False)
        assert pref.oleLaunch() == False
        pref.setOLELaunch(True)
        assert pref.oleLaunch() == True

    def test_renderSmoothness(self):
        pref = self.axDoc.preferences()
        orig = pref.renderSmoothness()
        new = 0.5 if orig != 0.5 else 0.7
        pref.setRenderSmoothness(new)
        assert pref.renderSmoothness() == new
        pref.setRenderSmoothness(orig)
        assert pref.renderSmoothness() == orig

    def test_segmentPerPolyline(self):
        pref = self.axDoc.preferences()
        orig = pref.segmentPerPolyline()
        pref.setSegmentPerPolyline(orig + 1)
        assert pref.segmentPerPolyline() == orig + 1
        pref.setSegmentPerPolyline(orig)
        assert pref.segmentPerPolyline() == orig

    def test_solidFill(self):
        pref = self.axDoc.preferences()
        pref.setSolidFill(False)
        assert pref.solidFill() == False
        pref.setSolidFill(True)
        assert pref.solidFill() == True

    def test_textFrameDisplay(self):
        pref = self.axDoc.preferences()
        pref.setTextFrameDisplay(False)
        assert pref.textFrameDisplay() == False
        pref.setTextFrameDisplay(True)
        assert pref.textFrameDisplay() == True

    def test_xrefEdit(self):
        pref = self.axDoc.preferences()
        pref.setXRefEdit(False)
        assert pref.xrefEdit() == False
        pref.setXRefEdit(True)
        assert pref.xrefEdit() == True

    def test_xrefLayerVisibility(self):
        pref = self.axDoc.preferences()
        pref.setXRefLayerVisibility(False)
        assert pref.xrefLayerVisibility() == False
        pref.setXRefLayerVisibility(True)
        assert pref.xrefLayerVisibility() == True
