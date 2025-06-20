from __future__ import annotations

from pyrx import Ap
from tests import HOST


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

    # in BricsCAD, dynamic menues are persisted in the CUI (SR-26299 2011)
    # GRX shutdown behavior, the menus are null, it's OK in a command context
    def teardown_class(self):
        if HOST is None or "GRX" in HOST:
            return
        axApp = Ap.Application.acadApplication()
        axMenuGroups = axApp.menuGroups()
        axMenuGroup = axMenuGroups.item(0)
        axPopupMenus = axMenuGroup.menus()
        for item in axPopupMenus:
            if item.name() == "TestMenu":
                item.removeFromMenuBar()
                return

    def test_menu_added(self):
        axApp = Ap.Application.acadApplication()
        axMenuGroups = axApp.menuGroups()
        axMenuGroup = axMenuGroups.item(0)
        axPopupMenus = axMenuGroup.menus()
        names = [item.name() for item in axPopupMenus]
        assert "TestMenu" in names

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
        assert axMenuGroups.count() != 0
        for idx in range(axMenuGroups.count()):
            item = axMenuGroups.item(idx)
            assert len(item.name()) != 0
