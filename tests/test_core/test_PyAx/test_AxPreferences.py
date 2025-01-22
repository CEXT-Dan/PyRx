from __future__ import annotations
import pytest
from tests import HOST
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

    def test_axSelection(self):
        axSelection = self.axPreferences.selection()
        assert axSelection.displayGrips() == True
        
        # grips
        flag = axSelection.displayGrips()
        axSelection.setDisplayGrips(not flag)
        assert axSelection.displayGrips() != flag
        axSelection.setDisplayGrips(flag)
        
        # grips in blocks
        flag = axSelection.displayGripsWithinBlocks()
        axSelection.setDisplayGripsWithinBlocks(not flag)
        assert axSelection.displayGripsWithinBlocks() != flag
        axSelection.setDisplayGripsWithinBlocks(flag)
        
        # grip size
        flag = axSelection.gripSize()
        axSelection.setGripSize(flag + 1)
        assert axSelection.gripSize() != flag
        axSelection.setGripSize(flag)
