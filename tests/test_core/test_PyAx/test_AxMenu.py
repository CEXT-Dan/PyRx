from __future__ import annotations
import pytest

from pyrx import Ap, Ax


class TestAxMenu:

    def setup_class(self):
        axApp = Ap.Application.acadApplication()
        AxMenuBar = axApp.menuBar()
        axMenuGroups = axApp.menuGroups()
        axMenuGroup = axMenuGroups.item(0)
        axPopupMenus = axMenuGroup.menus()
        axNewMenu = axPopupMenus.add("TestMenu")
        axMenuItem = axNewMenu.addMenuItem(axNewMenu.count() + 1, "Open", "^C^C_OPEN ")
        axMenuItem.setHelpString("woohoo")
        axNewMenu.insertInMenuBar(AxMenuBar.count() + 1)

    def test_menuggroups_iterable(self):
        axApp = Ap.Application.acadApplication()
        nItems = 0
        for item in axApp.menuGroups():
            nItems += 1
        axMenuGroups = axApp.menuGroups()
        assert nItems == axMenuGroups.count()
        assert nItems != 0

    def test_menuggroups_item(self):
        axApp = Ap.Application.acadApplication()
        axMenuGroups = axApp.menuGroups()

        for idx in range(axMenuGroups.count()):
            item = axMenuGroups.item(idx)
            assert len(item.name()) != 0
