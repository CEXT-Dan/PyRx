from __future__ import annotations

import os

import pytest

from pyrx import Ap, Ax


class TestAxPreferences:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axPreferences = self.axApp.preferences()

    def teardown_class(self):
        pass

    def test_axProfiles(self):
        axProfiles = self.axPreferences.profiles()
        assert len(axProfiles.getAllProfileNames()) != 0


class TestSelection:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axPreferences = self.axApp.preferences()

    @pytest.mark.known_failure_ZRX
    def test_axSelection_gripSize(self):
        axSelection = self.axPreferences.selection()
        flag = axSelection.gripSize()
        axSelection.setGripSize(flag + 1)
        assert axSelection.gripSize() != flag
        axSelection.setGripSize(flag)
        assert axSelection.gripSize() == flag

    @pytest.mark.known_failure_ZRX
    def test_axSelection_gripColorSelected(self):
        axSelection = self.axPreferences.selection()
        flag = axSelection.gripColorSelected()
        axSelection.setGripColorSelected(Ax.AcColor.acYellow)
        assert axSelection.gripColorSelected() != flag
        axSelection.setGripColorSelected(flag)
        assert axSelection.gripColorSelected() == flag

    def test_axSelection_gripColorUnselected(self):
        axSelection = self.axPreferences.selection()
        flag = axSelection.gripColorUnselected()
        axSelection.setGripColorUnselected(Ax.AcColor.acYellow)
        assert axSelection.gripColorUnselected() != flag
        axSelection.setGripColorUnselected(flag)
        assert axSelection.gripColorUnselected() == flag

    @pytest.mark.known_failure_ZRX
    def test_axSelection_displayGripsWithinBlocks(self):
        axSelection = self.axPreferences.selection()
        flag = axSelection.displayGripsWithinBlocks()
        axSelection.setDisplayGripsWithinBlocks(not flag)
        assert axSelection.displayGripsWithinBlocks() != flag
        axSelection.setDisplayGripsWithinBlocks(flag)
        assert axSelection.displayGripsWithinBlocks() == flag

    @pytest.mark.known_failure_ZRX
    def test_axSelection_displayGrips(self):
        axSelection = self.axPreferences.selection()
        flag = axSelection.displayGrips()
        axSelection.setDisplayGrips(not flag)
        assert axSelection.displayGrips() != flag
        axSelection.setDisplayGrips(flag)
        assert axSelection.displayGrips() == flag


class TestDrafting:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axPreferences = self.axApp.preferences()

    def test_axDrafting_autoSnapMarker(self):
        axDrafting = self.axPreferences.drafting()

        flag = axDrafting.autoSnapMarker()
        axDrafting.setAutoSnapMarker(not flag)
        assert axDrafting.autoSnapMarker() != flag
        axDrafting.setAutoSnapMarker(flag)
        assert axDrafting.autoSnapMarker() == flag

    def test_axDrafting_autoSnapMarkerSize(self):
        axDrafting = self.axPreferences.drafting()
        flag = axDrafting.autoSnapMarkerSize()
        axDrafting.setAutoSnapMarkerSize(flag + 1)
        assert axDrafting.autoSnapMarkerSize() != flag
        axDrafting.setAutoSnapMarkerSize(flag)
        assert axDrafting.autoSnapMarkerSize() == flag

    def test_axDrafting_autoSnapApertureSize(self):
        axDrafting = self.axPreferences.drafting()
        flag = axDrafting.autoSnapApertureSize()
        axDrafting.setAutoSnapApertureSize(flag + 1)
        assert axDrafting.autoSnapApertureSize() != flag
        axDrafting.setAutoSnapApertureSize(flag)
        assert axDrafting.autoSnapApertureSize() == flag


class TestDisplay:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axPreferences = self.axApp.preferences()

    @pytest.mark.known_failure_BRX
    def test_axDisplay_layoutDisplayMargins(self):
        axDisplay = self.axPreferences.display()
        flag = axDisplay.layoutDisplayMargins()
        axDisplay.setLayoutDisplayMargins(not flag)
        assert axDisplay.layoutDisplayMargins() != flag
        axDisplay.setLayoutDisplayMargins(flag)
        assert axDisplay.layoutDisplayMargins() == flag

    def test_axDisplay_graphicsWinModelBackgrndColor(self):
        axDisplay = self.axPreferences.display()
        flag = axDisplay.graphicsWinModelBackgrndColor()
        axDisplay.setGraphicsWinModelBackgrndColor((0, 255, 0))
        assert axDisplay.graphicsWinModelBackgrndColor() != flag
        axDisplay.setGraphicsWinModelBackgrndColor(flag)
        assert axDisplay.graphicsWinModelBackgrndColor() == flag

    @pytest.mark.known_failure_BRX
    def test_axDisplay_modelCrosshairColor(self):
        axDisplay = self.axPreferences.display()
        flag = axDisplay.modelCrosshairColor()
        axDisplay.setModelCrosshairColor((255, 255, 0))
        assert axDisplay.modelCrosshairColor() != flag
        axDisplay.setModelCrosshairColor(flag)
        assert axDisplay.modelCrosshairColor() == flag


class TestPrefFiles:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axPreferences = self.axApp.preferences()
        self.cwd = os.path.normcase(os.getcwd() + "\\")

    @pytest.mark.known_failure_BRX
    def test_axFiles_helpFilePath(self):
        axFiles = self.axPreferences.files()
        path = os.path.normcase(axFiles.helpFilePath())
        axFiles.setHelpFilePath(self.cwd)
        assert os.path.normcase(axFiles.helpFilePath()) == self.cwd
        axFiles.setHelpFilePath(path)
        assert axFiles.helpFilePath() == path

    def test_axFiles_logFilePath(self):
        axFiles = self.axPreferences.files()
        path = os.path.normcase(axFiles.logFilePath())
        axFiles.setLogFilePath(self.cwd)
        assert os.path.normcase(axFiles.logFilePath()) == self.cwd
        axFiles.setLogFilePath(path)
        assert os.path.normcase(axFiles.logFilePath()) == path

    def test_axFiles_toolPalettePath(self):
        axFiles = self.axPreferences.files()
        path = os.path.normcase(axFiles.toolPalettePath())
        axFiles.setToolPalettePath(self.cwd)
        assert os.path.normcase(axFiles.toolPalettePath()) == self.cwd
        axFiles.setToolPalettePath(path)
        assert os.path.normcase(axFiles.toolPalettePath()) == path

    def test_axFiles_qnewTemplateFile(self):
        axFiles = self.axPreferences.files()
        path = os.path.normcase(axFiles.qnewTemplateFile())
        axFiles.setQNewTemplateFile(self.cwd)
        assert os.path.normcase(axFiles.qnewTemplateFile()) == self.cwd
        axFiles.setQNewTemplateFile(path)
        assert os.path.normcase(axFiles.qnewTemplateFile()) == path
