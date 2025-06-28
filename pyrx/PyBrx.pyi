from __future__ import annotations

from typing import Any, ClassVar, Self

import wx

from pyrx import Brx as PyBrx
from pyrx import Db as PyDb
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

eBim: LicensedFeature  # 2
eCommunicator: LicensedFeature  # 1
eCore: LicensedFeature  # 0
eMechanical: LicensedFeature  # 3

class Core:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def getOpenObjects() -> list: ...
    @staticmethod
    def isLicenseAvailable(val: PyBrx.LicensedFeature, /) -> bool: ...

class DbProperties:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def dumpAll(id: PyDb.ObjectId, /) -> None: ...
    @staticmethod
    def getValue(id: PyDb.ObjectId, name: str, /) -> PyDb.AcValue: ...
    @staticmethod
    def isReadOnly(id: PyDb.ObjectId, name: str, /) -> tuple: ...
    @staticmethod
    def isValid(id: PyDb.ObjectId, name: str, /) -> tuple: ...
    @staticmethod
    def listAll(id: PyDb.ObjectId, /) -> list: ...
    @staticmethod
    def setValue(id: PyDb.ObjectId, name: str, val: PyDb.AcValue, /) -> None: ...

class LicensedFeature(_BoostPythonEnum):
    eCore: ClassVar[Self]  # 0
    eCommunicator: ClassVar[Self]  # 1
    eBim: ClassVar[Self]  # 2
    eMechanical: ClassVar[Self]  # 3

class PyBrxPanel:
    def __init__(self, name: str, configKey: str = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def backgroundColor(self, /) -> int: ...
    def create(self, panel: wx.Panel, /) -> bool: ...
    def destroy(self, /) -> None: ...
    def isFloating(self, /) -> bool: ...
    def setIcon(self, imagePath: str, /) -> None: ...
    def tabTextColor(self, /) -> int: ...
