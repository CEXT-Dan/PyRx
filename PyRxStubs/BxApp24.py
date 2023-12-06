# -*- coding: mbcs -*-
# Created by makepy.py version 0.5.01
# By python version 3.12.0 (tags/v3.12.0:0fb18b0, Oct  2 2023, 13:03:39) [MSC v.1935 64 bit (AMD64)]
# From type library 'axbricscadapp1.tlb'
# On Wed Dec  6 08:20:12 2023
'BricsCAD App 24.0 Type Library (x64)'
makepy_version = '0.5.01'
python_version = 0x30c00f0

import win32com.client.CLSIDToClass, pythoncom, pywintypes
import win32com.client.util
from pywintypes import IID
from win32com.client import Dispatch
import BxDb24

def VTR8ArrayOrVal(__values):
    if isinstance(__values, list) or isinstance(__values, tuple):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, __values)
    return __values

def VTI2ArrayOrVal(__values):
    if isinstance(__values, list) or isinstance(__values, tuple):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_I2, __values)
    return __values

def VTVARArrayOrVal(__values):
    if isinstance(__values, list) or isinstance(__values, tuple):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_VARIANT, __values)
    return __values

def VTDISPArrayOrVal(__values):
    if isinstance(__values, list) or isinstance(__values, tuple):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_DISPATCH, __values)
    return __values

# The following 3 lines may need tweaking for the particular server
# Candidates are pythoncom.Missing, .Empty and .ArgNotFound
defaultNamedOptArg=pythoncom.Empty
defaultNamedNotOptArg=pythoncom.Empty
defaultUnnamedArg=pythoncom.Empty

CLSID = IID('{58B85F2E-40FC-4422-A821-84C954420139}')
MajorVersion = 24
MinorVersion = 0
LibraryFlags = 8
LCID = 0x0

class constants:
    acLsAll                       =65535      # from enum AcLayerStateMask
    acLsColor                     =32         # from enum AcLayerStateMask
    acLsFrozen                    =2          # from enum AcLayerStateMask
    acLsLineType                  =64         # from enum AcLayerStateMask
    acLsLineWeight                =128        # from enum AcLayerStateMask
    acLsLocked                    =4          # from enum AcLayerStateMask
    acLsNewViewport               =16         # from enum AcLayerStateMask
    acLsNone                      =0          # from enum AcLayerStateMask
    acLsOn                        =1          # from enum AcLayerStateMask
    acLsPlot                      =8          # from enum AcLayerStateMask
    acLsPlotStyle                 =256        # from enum AcLayerStateMask
    ACADSECURITYPARAMS_ALGID_RC4  =26625      # from enum AcadSecurityParamsConstants
    ACADSECURITYPARAMS_ADD_TIMESTAMP=32         # from enum AcadSecurityParamsType
    ACADSECURITYPARAMS_ENCRYPT_DATA=1          # from enum AcadSecurityParamsType
    ACADSECURITYPARAMS_ENCRYPT_PROPS=2          # from enum AcadSecurityParamsType
    ACADSECURITYPARAMS_SIGN_DATA  =16         # from enum AcadSecurityParamsType
    odDwfAscii                    =2          # from enum OdDwfFormat
    odDwfCompressedBinary         =0          # from enum OdDwfFormat
    odDwfUncompressedBinary       =1          # from enum OdDwfFormat
    odDwf_v42                     =42         # from enum OdDwfVersion
    odDwf_v55                     =55         # from enum OdDwfVersion
    odDwf_v60                     =600        # from enum OdDwfVersion
    od2000_Template               =14         # from enum OdSaveAsType
    od2000_dwg                    =12         # from enum OdSaveAsType
    od2000_dxf                    =13         # from enum OdSaveAsType
    od2004_Template               =26         # from enum OdSaveAsType
    od2004_dwg                    =24         # from enum OdSaveAsType
    od2004_dxf                    =25         # from enum OdSaveAsType
    od2007_Template               =38         # from enum OdSaveAsType
    od2007_dwg                    =36         # from enum OdSaveAsType
    od2007_dxf                    =37         # from enum OdSaveAsType
    od2010_Template               =50         # from enum OdSaveAsType
    od2010_dwg                    =48         # from enum OdSaveAsType
    od2010_dxf                    =49         # from enum OdSaveAsType
    od2013_Template               =62         # from enum OdSaveAsType
    od2013_dwg                    =60         # from enum OdSaveAsType
    od2013_dxf                    =61         # from enum OdSaveAsType
    od2018_Template               =66         # from enum OdSaveAsType
    od2018_dwg                    =64         # from enum OdSaveAsType
    od2018_dxf                    =65         # from enum OdSaveAsType
    odNative                      =64         # from enum OdSaveAsType
    odR09_dxf                     =-5         # from enum OdSaveAsType
    odR10_dxf                     =-4         # from enum OdSaveAsType
    odR12_dwg                     =-3         # from enum OdSaveAsType
    odR12_dxf                     =1          # from enum OdSaveAsType
    odR13_dwg                     =4          # from enum OdSaveAsType
    odR13_dxf                     =5          # from enum OdSaveAsType
    odR14_dwg                     =8          # from enum OdSaveAsType
    odR14_dxf                     =9          # from enum OdSaveAsType
    odR15_Template                =14         # from enum OdSaveAsType
    odR15_dwg                     =12         # from enum OdSaveAsType
    odR15_dxf                     =13         # from enum OdSaveAsType
    odR18_Template                =26         # from enum OdSaveAsType
    odR18_dwg                     =24         # from enum OdSaveAsType
    odR18_dxf                     =25         # from enum OdSaveAsType
    odR21_Template                =38         # from enum OdSaveAsType
    odR21_dwg                     =36         # from enum OdSaveAsType
    odR21_dxf                     =37         # from enum OdSaveAsType
    odR24_Template                =50         # from enum OdSaveAsType
    odR24_dwg                     =48         # from enum OdSaveAsType
    odR24_dxf                     =49         # from enum OdSaveAsType
    odR27_Template                =62         # from enum OdSaveAsType
    odR27_dwg                     =60         # from enum OdSaveAsType
    odR27_dxf                     =61         # from enum OdSaveAsType
    odR32_Template                =66         # from enum OdSaveAsType
    odR32_dwg                     =64         # from enum OdSaveAsType
    odR32_dxf                     =65         # from enum OdSaveAsType
    odUnknown                     =-1         # from enum OdSaveAsType
    PDFEXPORT_EXCLUDE_OFFLAYER    =1          # from enum PdfExportLayerSettingType
    PDFEXPORT_INCLUDE_OFFLAYER    =2          # from enum PdfExportLayerSettingType
    PDFEXPORT_NOLAYER             =0          # from enum PdfExportLayerSettingType
    PDFEXPORT_LAYOUTS_ACTIVE      =0          # from enum PdfExportLayoutSettingType
    PDFEXPORT_LAYOUTS_ALL         =1          # from enum PdfExportLayoutSettingType
    e3rdPartyAddedFile            =14         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eAltFontFile                  =7          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eDGNUnderlay                  =20         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eDWFUnderlay                  =21         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eDataLinkFile                 =25         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eDwgFile                      =0          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eEdgeTextureFile              =26         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eFontFile                     =3          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eFontMapFile                  =13         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eGeneratedFile                =27         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eImageFile                    =2          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eMaterialTextureFile          =23         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eNoType                       =-1         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    ePDFUnderlay                  =22         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    ePfbAltFontFile               =9          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    ePfbFontFile                  =5          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    ePhotometricWebFile           =24         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    ePlotCfgFile                  =11         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    ePlotStyleTableFile           =12         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eSheetSetFile                 =18         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eSheetSetSupportFile          =19         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eShxAltFontFile               =8          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eShxFontFile                  =4          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eTtfAltFontFile               =10         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eTtfFontFile                  =6          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eUserAddedFile                =15         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eXrefAttachFile               =16         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eXrefFile                     =1          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eXrefOverlayFile              =17         # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0001
    eFileAdded                    =0          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    eFileAlreadyAdded             =5          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    eFileNotAdded                 =2          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    eFileNotAddedBadArg           =4          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    eFileNotAddedToPreventCycle   =3          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    eRelationshipAdded            =1          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0002
    eAutoCAD14                    =3          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0003
    eAutoCAD2000                  =2          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0003
    eAutoCADR18                   =1          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0003
    eAutoCADR21                   =4          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0003
    eNoConversion                 =0          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0003
    eOverwriteCancel              =3          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0004
    eOverwriteNo                  =0          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0004
    eOverwriteYes                 =1          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0004
    eOverwriteYesToAll            =2          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0004
    eOverwriteYesToAllReadOnly    =4          # from enum __MIDL___MIDL_itf_ax_bricscadapp_0000_0000_0004

from win32com.client import DispatchBaseClass
class IAcadApplication(DispatchBaseClass):
    'An instance of the BricsCAD application'
    CLSID = IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')
    coclass_clsid = IID('{0E86524E-1812-426A-9A63-2C2B51B0D0E4}')

    def DefineFunction(self, FunctionName=defaultNamedNotOptArg, FunctionPointer=defaultNamedNotOptArg):
        'Adds a macro to the command list, similar to (defun c:cmd) in lisp.'
        return self._oleobj_.InvokeTypes(45, LCID, 1, (24, 0), ((8, 1), (12, 1)),FunctionName
            , FunctionPointer)

    def Eval(self, Expression=defaultNamedNotOptArg):
        'Evaluates an expression in VBA.'
        return self._oleobj_.InvokeTypes(33, LCID, 1, (24, 0), ((8, 1),),Expression
            )

    # Result is of type IAcadState
    def GetAcadState(self):
        'Retrieves an AcadState object.'
        ret = self._oleobj_.InvokeTypes(42, LCID, 1, (9, 0), (),)
        if ret is not None:
            ret = Dispatch(ret, 'GetAcadState', '{C2016470-443B-40D0-AD93-231ACFDCF594}')
        return ret

    def GetInterfaceObject(self, ProgID=defaultNamedNotOptArg):
        'Accepts a program ID and attempts to load it into BricsCAD as an in-process server'
        ret = self._oleobj_.InvokeTypes(20, LCID, 1, (9, 0), ((8, 1),),ProgID
            )
        if ret is not None:
            ret = Dispatch(ret, 'GetInterfaceObject', None)
        return ret

    def ListArx(self):
        'Gets the currently loaded BricsCAD ARX applications.'
        return self._ApplyTypes_(18, 1, (12, 0), (), 'ListArx', None,)

    def LoadArx(self, Name=defaultNamedNotOptArg):
        'Loads the specified BricsCAD ARX application'
        return self._oleobj_.InvokeTypes(19, LCID, 1, (24, 0), ((8, 1),),Name
            )

    def LoadDVB(self, Name=defaultNamedNotOptArg):
        'Loads the specified BricsCAD VBA project file.'
        return self._oleobj_.InvokeTypes(30, LCID, 1, (24, 0), ((8, 1),),Name
            )

    def Quit(self):
        'Closes the drawing file and exits the BricsCAD application'
        return self._oleobj_.InvokeTypes(25, LCID, 1, (24, 0), (),)

    def RunCommand(self, Command=defaultNamedNotOptArg):
        'Runs a commmand.'
        return self._oleobj_.InvokeTypes(47, LCID, 1, (24, 0), ((8, 1),),Command
            )

    def RunMacro(self, MacroPath=defaultNamedNotOptArg):
        'Runs a VBA macro from the Application object'
        return self._oleobj_.InvokeTypes(35, LCID, 1, (24, 0), ((8, 1),),MacroPath
            )

    def RunScript(self, Script=defaultNamedNotOptArg):
        'Runs a script.'
        return self._oleobj_.InvokeTypes(48, LCID, 1, (24, 0), ((8, 1),),Script
            )

    # The method StatusId is actually a property, but must be used as a method to correctly pass the arguments
    def StatusId(self, VportObj=defaultNamedNotOptArg):
        'Gets the current active status of the viewport.'
        return self._oleobj_.InvokeTypes(17, LCID, 2, (11, 0), ((9, 1),),VportObj
            )

    def UndefineFunction(self, FunctionName=defaultNamedNotOptArg):
        'Removes a previously defined VBA macro from the command list.'
        return self._oleobj_.InvokeTypes(46, LCID, 1, (24, 0), ((8, 1),),FunctionName
            )

    def UnloadArx(self, Name=defaultNamedNotOptArg):
        'Unloads the specified BricsCAD ARX application'
        return self._oleobj_.InvokeTypes(23, LCID, 1, (24, 0), ((8, 1),),Name
            )

    def UnloadDVB(self, Name=defaultNamedNotOptArg):
        'Unloads the specified BricsCAD VBA project file.'
        return self._oleobj_.InvokeTypes(31, LCID, 1, (24, 0), ((8, 1),),Name
            )

    def Update(self):
        'Updates the object to the drawing screen'
        return self._oleobj_.InvokeTypes(24, LCID, 1, (24, 0), (),)

    def Zoom(self, Type=defaultNamedNotOptArg, vParams=defaultNamedNotOptArg):
        'Zoom. Not implemented yet.'
        return self._oleobj_.InvokeTypes(26, LCID, 1, (24, 0), ((3, 1), (16396, 1)),Type
            , vParams)

    def ZoomAll(self):
        'Zooms the current viewport to display the entire drawing'
        return self._oleobj_.InvokeTypes(37, LCID, 1, (24, 0), (),)

    def ZoomCenter(self, Center=defaultNamedNotOptArg, Magnify=defaultNamedNotOptArg):
        'Zooms the current viewport to a specified center point and magnification'
        return self._oleobj_.InvokeTypes(38, LCID, 1, (24, 0), ((12, 1), (5, 1)),Center
            , Magnify)

    def ZoomExtents(self):
        'Zooms the current viewport to the drawing extents'
        return self._oleobj_.InvokeTypes(36, LCID, 1, (24, 0), (),)

    def ZoomPickWindow(self):
        'Zooms the current viewport to a window defined by points picked on the screen'
        return self._oleobj_.InvokeTypes(41, LCID, 1, (24, 0), (),)

    def ZoomPrevious(self):
        'Zooms the current viewport to its previous extents'
        return self._oleobj_.InvokeTypes(43, LCID, 1, (24, 0), (),)

    def ZoomScaled(self, scale=defaultNamedNotOptArg, ScaleType=defaultNamedNotOptArg):
        'Zooms the current viewport to given scale factor'
        return self._oleobj_.InvokeTypes(39, LCID, 1, (24, 0), ((5, 1), (3, 1)),scale
            , ScaleType)

    def ZoomWindow(self, LowerLeft=defaultNamedNotOptArg, UpperRight=defaultNamedNotOptArg):
        'Zooms the current viewport to the area specified by two opposite corners of a rectangle'
        return self._oleobj_.InvokeTypes(40, LCID, 1, (24, 0), ((12, 1), (12, 1)),LowerLeft
            , UpperRight)

    _prop_map_get_ = {
        # Method 'ActiveDocument' returns object of type 'IAcadDocument'
        "ActiveDocument": (5, 2, (9, 0), (), "ActiveDocument", '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}'),
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (4, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Caption": (3, 2, (8, 0), (), "Caption", None),
        # Method 'Documents' returns object of type 'IAcadDocuments'
        "Documents": (32, 2, (9, 0), (), "Documents", '{CFFD1390-466A-49D9-9EE0-1884E930DFF9}'),
        "FullName": (6, 2, (8, 0), (), "FullName", None),
        "HWND": (44, 2, (20, 0), (), "HWND", None),
        "Height": (7, 2, (3, 0), (), "Height", None),
        "LocaleId": (10, 2, (3, 0), (), "LocaleId", None),
        # Method 'MenuBar' returns object of type 'IAcadMenuBar'
        "MenuBar": (29, 2, (9, 0), (), "MenuBar", '{A174CCC8-D19F-421F-8F4E-65C2E4F43167}'),
        # Method 'MenuGroups' returns object of type 'IAcadMenuGroups'
        "MenuGroups": (28, 2, (9, 0), (), "MenuGroups", '{798225D3-984D-471E-84F3-D1EC56FA05EA}'),
        "Name": (2, 2, (8, 0), (), "Name", None),
        "Path": (9, 2, (8, 0), (), "Path", None),
        # Method 'Preferences' returns object of type 'IAcadPreferences'
        "Preferences": (14, 2, (9, 0), (), "Preferences", '{03CE46C1-93A9-4E5C-B7F5-7AC7E2D48948}'),
        "VBE": (27, 2, (9, 0), (), "VBE", None),
        "Visible": (1, 2, (11, 0), (), "Visible", None),
        "Width": (13, 2, (3, 0), (), "Width", None),
        "WindowLeft": (8, 2, (3, 0), (), "WindowLeft", None),
        "WindowState": (34, 2, (3, 0), (), "WindowState", None),
        "WindowTop": (11, 2, (3, 0), (), "WindowTop", None),
        "version": (12, 2, (8, 0), (), "version", None),
    }
    _prop_map_put_ = {
        "ActiveDocument": ((5, LCID, 4, 0),()),
        "Height": ((7, LCID, 4, 0),()),
        "Visible": ((1, LCID, 4, 0),()),
        "Width": ((13, LCID, 4, 0),()),
        "WindowLeft": ((8, LCID, 4, 0),()),
        "WindowState": ((34, LCID, 4, 0),()),
        "WindowTop": ((11, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadDocument(DispatchBaseClass):
    'A BricsCAD drawing'
    CLSID = IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
    coclass_clsid = IID('{3975E80C-5EC5-4EE0-B432-E9EC7BBB9A5A}')

    def AbortTransaction(self):
        'Aborts the current transaction with rollback of all changes done to the database since StartTransaction'
        return self._oleobj_.InvokeTypes(81, LCID, 1, (24, 0), (),)

    def Activate(self):
        'Makes the specified drawing active'
        return self._oleobj_.InvokeTypes(57, LCID, 1, (24, 0), (),)

    def AuditInfo(self, FixErr=defaultNamedNotOptArg):
        'Evaluates the integrity of the drawing'
        return self._oleobj_.InvokeTypes(43, LCID, 1, (24, 0), ((11, 1),),FixErr
            )

    def Close(self, SaveChanges=defaultNamedOptArg, FileName=defaultNamedOptArg):
        'Closes the specified drawing, or all open drawings'
        return self._oleobj_.InvokeTypes(58, LCID, 1, (24, 0), ((12, 17), (12, 17)),SaveChanges
            , FileName)

    def CopyObjects(self, Objects=defaultNamedNotOptArg, Owner=defaultNamedOptArg, IdPairs=defaultNamedOptArg):
        'Duplicates multiple objects.'
        return self._ApplyTypes_(4, 1, (12, 0), ((12, 1), (12, 17), (16396, 19)), 'CopyObjects', None,Objects
            , Owner, IdPairs)

    def EndTransaction(self):
        'Finishes the current transaction and commits all changes done to the database since StartTransaction'
        return self._oleobj_.InvokeTypes(80, LCID, 1, (24, 0), (),)

    def EndUndoMark(self):
        'Marks the end of a block of operations'
        return self._oleobj_.InvokeTypes(69, LCID, 1, (24, 0), (),)

    def EvaluateLisp(self, lispString=defaultNamedNotOptArg):
        'Executes a LISP expression.'
        return self._ApplyTypes_(76, 1, (12, 0), ((8, 1),), 'EvaluateLisp', None,lispString
            )

    def Export(self, FileName=defaultNamedNotOptArg, Extension=defaultNamedNotOptArg, SelectionSet=defaultNamedNotOptArg):
        'Exports the BricsCAD drawing to a WMF, SAT, EPS, DXF, BMP or PDF format'
        return self._oleobj_.InvokeTypes(45, LCID, 1, (24, 0), ((8, 1), (8, 1), (9, 1)),FileName
            , Extension, SelectionSet)

    def GetVariable(self, Name=defaultNamedNotOptArg):
        'Gets the current setting of a system variable'
        return self._ApplyTypes_(51, 1, (12, 0), ((8, 1),), 'GetVariable', None,Name
            )

    def HandleToObject(self, Handle=defaultNamedNotOptArg):
        'Returns the object that corresponds with a specified handle.'
        ret = self._oleobj_.InvokeTypes(18, LCID, 1, (9, 0), ((8, 1),),Handle
            )
        if ret is not None:
            ret = Dispatch(ret, 'HandleToObject', None)
        return ret

    def Import(self, FileName=defaultNamedNotOptArg, InsertionPoint=defaultNamedNotOptArg, ScaleFactor=defaultNamedNotOptArg):
        'Imports a drawing file in SAT, EPS, DXF, or WMF format'
        ret = self._oleobj_.InvokeTypes(44, LCID, 1, (9, 0), ((8, 1), (12, 1), (5, 1)),FileName
            , InsertionPoint, ScaleFactor)
        if ret is not None:
            ret = Dispatch(ret, 'Import', None)
        return ret

    def LoadShapeFile(self, FullName=defaultNamedNotOptArg):
        'Loads a shape file (SHX)'
        return self._oleobj_.InvokeTypes(53, LCID, 1, (24, 0), ((8, 1),),FullName
            )

    # Result is of type IAcadDocument
    def New(self, TemplateFileName=defaultNamedNotOptArg):
        'Creates a new document in SDI mode. Not implemented yet.'
        ret = self._oleobj_.InvokeTypes(46, LCID, 1, (9, 0), ((8, 1),),TemplateFileName
            )
        if ret is not None:
            ret = Dispatch(ret, 'New', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    def ObjectIdToObject(self, ObjectID=defaultNamedNotOptArg):
        'Returns the object that corresponds with a specified object ID.'
        ret = self._oleobj_.InvokeTypes(19, LCID, 1, (9, 0), ((20, 1),),ObjectID
            )
        if ret is not None:
            ret = Dispatch(ret, 'ObjectIdToObject', None)
        return ret

    def ObjectIdToObject32(self, ObjectID=defaultNamedNotOptArg):
        'Returns the object that corresponds with a specified object ID.'
        ret = self._oleobj_.InvokeTypes(74, LCID, 1, (9, 0), ((3, 1),),ObjectID
            )
        if ret is not None:
            ret = Dispatch(ret, 'ObjectIdToObject32', None)
        return ret

    # Result is of type IAcadDocument
    def Open(self, FullName=defaultNamedNotOptArg, Password=defaultNamedOptArg):
        'Opens an existing drawing file (DWG) and makes it the active document. Not implemented yet.'
        ret = self._oleobj_.InvokeTypes(42, LCID, 1, (9, 0), ((8, 1), (12, 17)),FullName
            , Password)
        if ret is not None:
            ret = Dispatch(ret, 'Open', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    def PurgeAll(self):
        'Removes unused named references such as unused blocks or layers from the document'
        return self._oleobj_.InvokeTypes(50, LCID, 1, (24, 0), (),)

    def Regen(self, WhichViewports=defaultNamedNotOptArg):
        'Regenerates the entire drawing and recomputes the screen coordinates and view resolution for all objects'
        return self._oleobj_.InvokeTypes(54, LCID, 1, (24, 0), ((3, 1),),WhichViewports
            )

    def Save(self):
        'Saves the document or menu group'
        return self._oleobj_.InvokeTypes(47, LCID, 1, (24, 0), (),)

    def SaveAs(self, FullFileName=defaultNamedNotOptArg, SaveAsType=defaultNamedOptArg, vSecurityParams=defaultNamedOptArg):
        'Saves the document or menu group to a specified file'
        return self._oleobj_.InvokeTypes(48, LCID, 1, (24, 0), ((8, 1), (12, 17), (12, 17)),FullFileName
            , SaveAsType, vSecurityParams)

    def SendCommand(self, Command=defaultNamedNotOptArg):
        'Sends a command string from a VB or VBA application to the document for processing'
        return self._oleobj_.InvokeTypes(63, LCID, 1, (24, 0), ((8, 1),),Command
            )

    def SetVariable(self, Name=defaultNamedNotOptArg, Value=defaultNamedNotOptArg):
        'Sets the value of a system variable'
        return self._oleobj_.InvokeTypes(52, LCID, 1, (24, 0), ((8, 1), (12, 1)),Name
            , Value)

    def StartTransaction(self):
        "Starts a new transaction for this document's database"
        return self._oleobj_.InvokeTypes(79, LCID, 1, (24, 0), (),)

    def StartUndoMark(self):
        'Marks the beginning of a block of operations'
        return self._oleobj_.InvokeTypes(68, LCID, 1, (24, 0), (),)

    def Wblock(self, FileName=defaultNamedNotOptArg, SelectionSet=defaultNamedNotOptArg):
        'Writes out the given selection set as a new drawing file'
        return self._oleobj_.InvokeTypes(49, LCID, 1, (24, 0), ((8, 1), (9, 1)),FileName
            , SelectionSet)

    # Result is of type ITransmittalOperation
    def getTransmittalOperationInterface(self):
        'Gets the TransmittalOperation object for the document.'
        ret = self._oleobj_.InvokeTypes(75, LCID, 1, (9, 0), (),)
        if ret is not None:
            ret = Dispatch(ret, 'getTransmittalOperationInterface', '{7EFB484A-0280-4ED6-A73F-6DBE663DB79D}')
        return ret

    _prop_map_get_ = {
        "Active": (56, 2, (11, 0), (), "Active", None),
        # Method 'ActiveDimStyle' returns object of type 'IAcadDimStyle'
        "ActiveDimStyle": (26, 2, (9, 0), (), "ActiveDimStyle", '{F1E716A4-FBC3-4893-A8C4-5E59A537D7CE}'),
        # Method 'ActiveLayer' returns object of type 'IAcadLayer'
        "ActiveLayer": (24, 2, (9, 0), (), "ActiveLayer", '{A5484251-D4DF-4F32-A23F-445882F48F1B}'),
        # Method 'ActiveLayout' returns object of type 'IAcadLayout'
        "ActiveLayout": (62, 2, (9, 0), (), "ActiveLayout", '{50D89DB1-E146-428F-92BD-87F4EB9A46B4}'),
        # Method 'ActiveLinetype' returns object of type 'IAcadLineType'
        "ActiveLinetype": (25, 2, (9, 0), (), "ActiveLinetype", '{908A55EF-9ED0-4A36-BD47-AD0818AF9317}'),
        # Method 'ActiveMaterial' returns object of type 'IAcadMaterial'
        "ActiveMaterial": (77, 2, (9, 0), (), "ActiveMaterial", '{4D24EA66-A2B3-4129-8367-81D93B44BE07}'),
        # Method 'ActivePViewport' returns object of type 'IAcadPViewport'
        "ActivePViewport": (30, 2, (9, 0), (), "ActivePViewport", '{894A0DA6-C91F-458C-AC86-7FEDBF35CD30}'),
        # Method 'ActiveSelectionSet' returns object of type 'IAcadSelectionSet'
        "ActiveSelectionSet": (33, 2, (9, 0), (), "ActiveSelectionSet", '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}'),
        "ActiveSpace": (31, 2, (3, 0), (), "ActiveSpace", None),
        # Method 'ActiveTextStyle' returns object of type 'IAcadTextStyle'
        "ActiveTextStyle": (27, 2, (9, 0), (), "ActiveTextStyle", '{EE473D68-C42F-4A9D-8393-C3975C17BC4A}'),
        # Method 'ActiveUCS' returns object of type 'IAcadUCS'
        "ActiveUCS": (28, 2, (9, 0), (), "ActiveUCS", '{F5F78A02-09C6-49EB-812A-04B5ACC46F71}'),
        # Method 'ActiveViewport' returns object of type 'IAcadViewport'
        "ActiveViewport": (29, 2, (9, 0), (), "ActiveViewport", '{A9B1F951-1AA7-4C23-8D57-AA199803D381}'),
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (66, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        # Method 'Blocks' returns object of type 'IAcadBlocks'
        "Blocks": (3, 2, (9, 0), (), "Blocks", '{98F7CE82-8E41-4D58-A784-30B3F33F7853}'),
        # Method 'Dictionaries' returns object of type 'IAcadDictionaries'
        "Dictionaries": (9, 2, (9, 0), (), "Dictionaries", '{B6D57083-036D-48AB-8BF4-0902B5C88BFF}'),
        # Method 'DimStyles' returns object of type 'IAcadDimStyles'
        "DimStyles": (6, 2, (9, 0), (), "DimStyles", '{DAB1760C-8402-4520-AD32-9396AEF1C677}'),
        "ElevationModelSpace": (15, 2, (5, 0), (), "ElevationModelSpace", None),
        "ElevationPaperSpace": (16, 2, (5, 0), (), "ElevationPaperSpace", None),
        # Method 'FileDependencies' returns object of type 'IAcadFileDependencies'
        "FileDependencies": (70, 2, (9, 0), (), "FileDependencies", '{DA84BC48-A8C9-45CC-B042-07B8C95CD0E4}'),
        "FullName": (34, 2, (8, 0), (), "FullName", None),
        # Method 'Groups' returns object of type 'IAcadGroups'
        "Groups": (5, 2, (9, 0), (), "Groups", '{973585F9-D300-4BA7-9D0F-6EE59533A0DC}'),
        "HWND": (64, 2, (20, 0), (), "HWND", None),
        "Height": (61, 2, (3, 0), (), "Height", None),
        # Method 'Layers' returns object of type 'IAcadLayers'
        "Layers": (7, 2, (9, 0), (), "Layers", '{EA5AF871-E4B9-4903-9509-DF622C0DC6E7}'),
        # Method 'Layouts' returns object of type 'IAcadLayouts'
        "Layouts": (20, 2, (9, 0), (), "Layouts", '{88CC8ED5-7AEF-459A-BE86-45C7AFD8EAE8}'),
        "Limits": (17, 2, (12, 0), (), "Limits", None),
        # Method 'Linetypes' returns object of type 'IAcadLineTypes'
        "Linetypes": (8, 2, (9, 0), (), "Linetypes", '{669E518F-46F5-4E21-8447-7F8D1435AE94}'),
        "MSpace": (40, 2, (11, 0), (), "MSpace", None),
        # Method 'Materials' returns object of type 'IAcadMaterials'
        "Materials": (73, 2, (9, 0), (), "Materials", '{6B7DDA98-B483-40F8-905C-2DF10E936021}'),
        # Method 'ModelSpace' returns object of type 'IAcadModelSpace'
        "ModelSpace": (1, 2, (9, 0), (), "ModelSpace", '{ECE694AB-7306-4687-AD03-C7017AE8DED1}'),
        "Name": (35, 2, (8, 0), (), "Name", None),
        "NumTransactions": (78, 2, (3, 0), (), "NumTransactions", None),
        "ObjectSnapMode": (37, 2, (11, 0), (), "ObjectSnapMode", None),
        # Method 'PaperSpace' returns object of type 'IAcadPaperSpace'
        "PaperSpace": (2, 2, (9, 0), (), "PaperSpace", '{39377F68-1F53-4433-90AE-05526FEA4FE5}'),
        "Path": (36, 2, (8, 0), (), "Path", None),
        "PickfirstSelectionSet": (55, 2, (9, 0), (), "PickfirstSelectionSet", None),
        # Method 'Plot' returns object of type 'IAcadPlot'
        "Plot": (23, 2, (9, 0), (), "Plot", '{445545BB-394E-481A-AC4F-F073E53030E8}'),
        # Method 'PlotConfigurations' returns object of type 'IAcadPlotConfigurations'
        "PlotConfigurations": (21, 2, (9, 0), (), "PlotConfigurations", '{38436519-BF47-4848-B6B2-CB6944F167D3}'),
        # Method 'Preferences' returns object of type 'IAcadDatabasePreferences'
        "Preferences": (22, 2, (9, 0), (), "Preferences", '{41A5D923-4AB8-48DD-B24D-FBAFE94BA683}'),
        "ReadOnly": (38, 2, (11, 0), (), "ReadOnly", None),
        # Method 'RegisteredApplications' returns object of type 'IAcadRegisteredApplications'
        "RegisteredApplications": (10, 2, (9, 0), (), "RegisteredApplications", '{AD2DE5AD-7787-4890-A818-BF9E0B1D4F43}'),
        "Saved": (39, 2, (11, 0), (), "Saved", None),
        # Method 'SectionManager' returns object of type 'IAcadSectionManager'
        "SectionManager": (72, 2, (9, 0), (), "SectionManager", '{47495992-2633-4FA4-8B0F-213F0C2D20A5}'),
        # Method 'SelectionSets' returns object of type 'IAcadSelectionSets'
        "SelectionSets": (32, 2, (9, 0), (), "SelectionSets", '{37E34D42-8CD8-4E25-83BF-80C791AFEADE}'),
        # Method 'SummaryInfo' returns object of type 'IAcadSummaryInfo'
        "SummaryInfo": (71, 2, (9, 0), (), "SummaryInfo", '{95D1CD9E-63E7-4860-9BE2-8F684047E102}'),
        # Method 'TextStyles' returns object of type 'IAcadTextStyles'
        "TextStyles": (11, 2, (9, 0), (), "TextStyles", '{2D0D8EA6-992A-4CF8-966F-3DE39A3BF22F}'),
        # Method 'UserCoordinateSystems' returns object of type 'IAcadUCSs'
        "UserCoordinateSystems": (12, 2, (9, 0), (), "UserCoordinateSystems", '{B07B7A4C-A7D7-4116-BD27-D46030FDFE1B}'),
        # Method 'Utility' returns object of type 'IAcadUtility'
        "Utility": (41, 2, (9, 0), (), "Utility", '{5046A00A-7C22-4D39-ADE0-FB1AE3709B4D}'),
        # Method 'Viewports' returns object of type 'IAcadViewports'
        "Viewports": (14, 2, (9, 0), (), "Viewports", '{181E70E5-A50B-46DA-93EE-BCC068BFEBEC}'),
        # Method 'Views' returns object of type 'IAcadViews'
        "Views": (13, 2, (9, 0), (), "Views", '{E1673534-4417-4D0A-95FB-6E02246096D6}'),
        "Width": (60, 2, (3, 0), (), "Width", None),
        "WindowState": (59, 2, (3, 0), (), "WindowState", None),
        "WindowTitle": (65, 2, (8, 0), (), "WindowTitle", None),
        # Method 'database' returns object of type 'IAcadDatabase'
        "database": (67, 2, (9, 0), (), "database", '{236374B2-E248-484D-91D4-C13FA726645D}'),
    }
    _prop_map_put_ = {
        "ActiveDimStyle": ((26, LCID, 4, 0),()),
        "ActiveLayer": ((24, LCID, 4, 0),()),
        "ActiveLayout": ((62, LCID, 4, 0),()),
        "ActiveLinetype": ((25, LCID, 4, 0),()),
        "ActiveMaterial": ((77, LCID, 4, 0),()),
        "ActivePViewport": ((30, LCID, 4, 0),()),
        "ActiveSpace": ((31, LCID, 4, 0),()),
        "ActiveTextStyle": ((27, LCID, 4, 0),()),
        "ActiveUCS": ((28, LCID, 4, 0),()),
        "ActiveViewport": ((29, LCID, 4, 0),()),
        "ElevationModelSpace": ((15, LCID, 4, 0),()),
        "ElevationPaperSpace": ((16, LCID, 4, 0),()),
        "Height": ((61, LCID, 4, 0),()),
        "Limits": ((17, LCID, 4, 0),()),
        "MSpace": ((40, LCID, 4, 0),()),
        "ObjectSnapMode": ((37, LCID, 4, 0),()),
        "Width": ((60, LCID, 4, 0),()),
        "WindowState": ((59, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadDocuments(DispatchBaseClass):
    'The collection of all BricsCAD drawings open in the current session'
    CLSID = IID('{CFFD1390-466A-49D9-9EE0-1884E930DFF9}')
    coclass_clsid = IID('{5F5D38B7-C56C-4250-B088-2B06EEEC1EE9}')

    # Result is of type IAcadDocument
    def Add(self, TemplateName=defaultNamedOptArg):
        'Creates a member object and adds it to the appropriate collection'
        ret = self._oleobj_.InvokeTypes(1610743812, LCID, 1, (9, 0), ((12, 17),),TemplateName
            )
        if ret is not None:
            ret = Dispatch(ret, 'Add', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    def Close(self):
        'Closes the specified drawing, or all open drawings'
        return self._oleobj_.InvokeTypes(1610743814, LCID, 1, (24, 0), (),)

    # Result is of type IAcadDocument
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection, group, or selection set'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    # Result is of type IAcadDocument
    def Open(self, Name=defaultNamedNotOptArg, ReadOnly=defaultNamedOptArg, Password=defaultNamedOptArg):
        'Opens an existing drawing file (DWG) and makes it the active document'
        ret = self._oleobj_.InvokeTypes(1610743813, LCID, 1, (9, 0), ((8, 1), (12, 17), (12, 17)),Name
            , ReadOnly, Password)
        if ret is not None:
            ret = Dispatch(ret, 'Open', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
    }
    _prop_map_put_ = {
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection, group, or selection set'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadLayerStateManager(DispatchBaseClass):
    'IAcadLayerStateManager Interface'
    CLSID = IID('{65CDCC9F-F651-4DC4-A361-A8307F08AEE3}')
    coclass_clsid = IID('{2F38A4F0-DDE8-488C-B53C-5E364C267B53}')

    def Delete(self, bsName=defaultNamedNotOptArg):
        'Deletes the specified layers state.'
        return self._oleobj_.InvokeTypes(1610743813, LCID, 1, (24, 0), ((8, 1),),bsName
            )

    def Export(self, bsName=defaultNamedNotOptArg, bsFilename=defaultNamedNotOptArg):
        'Exports the specified layer state to the specified file.'
        return self._oleobj_.InvokeTypes(1610743816, LCID, 1, (24, 0), ((8, 1), (8, 1)),bsName
            , bsFilename)

    def Import(self, bsFilename=defaultNamedNotOptArg):
        'Imports all layer states from the specified file.'
        return self._oleobj_.InvokeTypes(1610743815, LCID, 1, (24, 0), ((8, 1),),bsFilename
            )

    # The method Mask is actually a property, but must be used as a method to correctly pass the arguments
    def Mask(self, bsName=defaultNamedNotOptArg):
        'Sets the mask used for restoring the specified layer state.'
        return self._oleobj_.InvokeTypes(1610743809, LCID, 2, (3, 0), ((8, 1),),bsName
            )

    def Rename(self, bsName=defaultNamedNotOptArg, bsNewName=defaultNamedNotOptArg):
        'Renames the specified layers state.'
        return self._oleobj_.InvokeTypes(1610743814, LCID, 1, (24, 0), ((8, 1), (8, 1)),bsName
            , bsNewName)

    def Restore(self, bsName=defaultNamedNotOptArg):
        'Restores the layers to the specified state as per the layer state mask.'
        return self._oleobj_.InvokeTypes(1610743812, LCID, 1, (24, 0), ((8, 1),),bsName
            )

    def Save(self, bsName=defaultNamedNotOptArg, eMask=defaultNamedNotOptArg):
        'Saves the attribute mask and the state of all layers into the specified layer state.'
        return self._oleobj_.InvokeTypes(1610743811, LCID, 1, (24, 0), ((8, 1), (3, 1)),bsName
            , eMask)

    def SetDatabase(self, iHostDb=defaultNamedNotOptArg):
        'Sets the working database for the layer state manager.'
        return self._oleobj_.InvokeTypes(1610743808, LCID, 1, (24, 0), ((9, 1),),iHostDb
            )

    # The method SetMask is actually a property, but must be used as a method to correctly pass the arguments
    def SetMask(self, bsName=defaultNamedNotOptArg, arg1=defaultUnnamedArg):
        'Sets the mask used for restoring the specified layer state.'
        return self._oleobj_.InvokeTypes(1610743809, LCID, 4, (24, 0), ((8, 1), (3, 1)),bsName
            , arg1)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadMenuBar(DispatchBaseClass):
    'This collection contains all the menus that are displayed in the Briccad menu bar'
    CLSID = IID('{A174CCC8-D19F-421F-8F4E-65C2E4F43167}')
    coclass_clsid = IID('{DE927728-3684-4835-8255-54350D951307}')

    # Result is of type IAcadPopupMenu
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
        # Method 'Parent' returns object of type 'IAcadApplication'
        "Parent": (1610743812, 2, (9, 0), (), "Parent", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
    }
    _prop_map_put_ = {
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadMenuGroup(DispatchBaseClass):
    'IAcadMenuGroup Interface'
    CLSID = IID('{DF14CB14-CDC6-463F-B71C-356149D1F935}')
    coclass_clsid = IID('{A07E5142-51E0-441E-B442-1F46F53F3888}')

    def Save(self, MenuFileType=defaultNamedNotOptArg):
        'Saves the menu group'
        return self._oleobj_.InvokeTypes(1610743816, LCID, 1, (24, 0), ((3, 1),),MenuFileType
            )

    def SaveAs(self, MenuFileName=defaultNamedNotOptArg, MenuFileType=defaultNamedNotOptArg):
        'Saves the menu group to a specified file'
        return self._oleobj_.InvokeTypes(1610743817, LCID, 1, (24, 0), ((8, 1), (3, 1)),MenuFileName
            , MenuFileType)

    def Unload(self):
        'Unloads the menu group'
        return self._oleobj_.InvokeTypes(1610743815, LCID, 1, (24, 0), (),)

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "MenuFileName": (1610743812, 2, (8, 0), (), "MenuFileName", None),
        # Method 'Menus' returns object of type 'IAcadPopupMenus'
        "Menus": (1610743813, 2, (9, 0), (), "Menus", '{3305CB53-F955-41F3-A47B-B7AA53B22D48}'),
        "Name": (1610743810, 2, (8, 0), (), "Name", None),
        # Method 'Parent' returns object of type 'IAcadMenuGroups'
        "Parent": (1610743809, 2, (9, 0), (), "Parent", '{798225D3-984D-471E-84F3-D1EC56FA05EA}'),
        # Method 'Toolbars' returns object of type 'IAcadToolbars'
        "Toolbars": (1610743814, 2, (9, 0), (), "Toolbars", '{F7DF12AA-4EF4-4EEE-8D00-68BB80D7F092}'),
        "Type": (1610743811, 2, (3, 0), (), "Type", None),
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadMenuGroups(DispatchBaseClass):
    'A collection of MenuGroup objects'
    CLSID = IID('{798225D3-984D-471E-84F3-D1EC56FA05EA}')
    coclass_clsid = IID('{FE3FC546-AF40-4A2E-9C5C-14B7B4B8A54D}')

    # Result is of type IAcadMenuGroup
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{DF14CB14-CDC6-463F-B71C-356149D1F935}')
        return ret

    # Result is of type IAcadMenuGroup
    def Load(self, MenuFileName=defaultNamedNotOptArg, BaseMenu=defaultNamedOptArg):
        'Loads a menu group from a menu file'
        ret = self._oleobj_.InvokeTypes(1610743813, LCID, 1, (9, 0), ((8, 1), (12, 17)),MenuFileName
            , BaseMenu)
        if ret is not None:
            ret = Dispatch(ret, 'Load', '{DF14CB14-CDC6-463F-B71C-356149D1F935}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
        # Method 'Parent' returns object of type 'IAcadApplication'
        "Parent": (1610743812, 2, (9, 0), (), "Parent", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
    }
    _prop_map_put_ = {
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{DF14CB14-CDC6-463F-B71C-356149D1F935}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{DF14CB14-CDC6-463F-B71C-356149D1F935}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadPlot(DispatchBaseClass):
    'Plot interface object'
    CLSID = IID('{445545BB-394E-481A-AC4F-F073E53030E8}')
    coclass_clsid = IID('{126D4FCB-3E3D-491B-9F0B-D6C9D362116A}')

    def DisplayPlotPreview(self, PreviewMode=defaultNamedNotOptArg):
        'Displays the Plot Preview dialog box with the specified partial or full view preview.'
        return self._oleobj_.InvokeTypes(5, LCID, 1, (24, 0), ((3, 1),),PreviewMode
            )

    def PlotToDevice(self, plotConfig=defaultNamedOptArg):
        'Plots a layout to a device.'
        return self._oleobj_.InvokeTypes(8, LCID, 1, (11, 0), ((12, 17),),plotConfig
            )

    def PlotToFile(self, plotFile=defaultNamedNotOptArg, plotConfig=defaultNamedOptArg):
        'Plots a layout to the specified file.'
        return self._oleobj_.InvokeTypes(9, LCID, 1, (11, 0), ((8, 1), (12, 17)),plotFile
            , plotConfig)

    def SetLayoutsToPlot(self, layoutList=defaultNamedNotOptArg):
        'Specifies the layout or layouts to plot.'
        return self._oleobj_.InvokeTypes(6, LCID, 1, (24, 0), ((12, 1),),layoutList
            )

    def StartBatchMode(self, entryCount=defaultNamedNotOptArg):
        'Invokes batchmode printing. Not implemented yet.'
        return self._oleobj_.InvokeTypes(7, LCID, 1, (24, 0), ((3, 1),),entryCount
            )

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "BatchPlotProgress": (4, 2, (11, 0), (), "BatchPlotProgress", None),
        "NumberOfCopies": (3, 2, (3, 0), (), "NumberOfCopies", None),
        "QuietErrorMode": (2, 2, (11, 0), (), "QuietErrorMode", None),
    }
    _prop_map_put_ = {
        "BatchPlotProgress": ((4, LCID, 4, 0),()),
        "NumberOfCopies": ((3, LCID, 4, 0),()),
        "QuietErrorMode": ((2, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPopupMenu(DispatchBaseClass):
    'IAcadPopupMenu Interface'
    CLSID = IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
    coclass_clsid = IID('{62AB6B80-D12D-40C8-8970-9915E69E05E0}')

    # Result is of type IAcadPopupMenuItem
    def AddMenuItem(self, Index=defaultNamedNotOptArg, Label=defaultNamedNotOptArg, Macro=defaultNamedNotOptArg):
        'Adds a popup menu item to a popup menu'
        ret = self._oleobj_.InvokeTypes(1610743818, LCID, 1, (9, 0), ((12, 1), (8, 1), (8, 1)),Index
            , Label, Macro)
        if ret is not None:
            ret = Dispatch(ret, 'AddMenuItem', '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')
        return ret

    # Result is of type IAcadPopupMenuItem
    def AddSeparator(self, Index=defaultNamedNotOptArg):
        'Adds a separator to an existing menu'
        ret = self._oleobj_.InvokeTypes(1610743820, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'AddSeparator', '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')
        return ret

    # Result is of type IAcadPopupMenu
    def AddSubMenu(self, Index=defaultNamedNotOptArg, Label=defaultNamedNotOptArg):
        'Adds a submenu to an existing menu'
        ret = self._oleobj_.InvokeTypes(1610743819, LCID, 1, (9, 0), ((12, 1), (8, 1)),Index
            , Label)
        if ret is not None:
            ret = Dispatch(ret, 'AddSubMenu', '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
        return ret

    def InsertInMenuBar(self, Index=defaultNamedNotOptArg):
        'Inserts the popup menu into the menu bar at a specified location'
        return self._oleobj_.InvokeTypes(1610743821, LCID, 1, (24, 0), ((12, 1),),Index
            )

    # Result is of type IAcadPopupMenuItem
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a group'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')
        return ret

    def RemoveFromMenuBar(self):
        'Removes the popup menu from the menu bar'
        return self._oleobj_.InvokeTypes(1610743822, LCID, 1, (24, 0), (),)

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
        "Name": (1610743813, 2, (8, 0), (), "Name", None),
        "NameNoMnemonic": (1610743815, 2, (8, 0), (), "NameNoMnemonic", None),
        "OnMenuBar": (1610743817, 2, (11, 0), (), "OnMenuBar", None),
        "Parent": (1610743812, 2, (9, 0), (), "Parent", None),
        "ShortcutMenu": (1610743816, 2, (11, 0), (), "ShortcutMenu", None),
        "TagString": (1610743823, 2, (8, 0), (), "TagString", None),
    }
    _prop_map_put_ = {
        "Name": ((1610743813, LCID, 4, 0),()),
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a group'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadPopupMenuItem(DispatchBaseClass):
    'A single popup menu item'
    CLSID = IID('{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')
    coclass_clsid = IID('{E24D7979-088A-435B-B939-D8E18AD4BE1D}')

    def Delete(self):
        'Deletes a specified menu item'
        return self._oleobj_.InvokeTypes(1610743826, LCID, 1, (24, 0), (),)

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Caption": (1610743823, 2, (8, 0), (), "Caption", None),
        "Check": (1610743816, 2, (11, 0), (), "Check", None),
        "Enable": (1610743814, 2, (11, 0), (), "Enable", None),
        "EndSubMenuLevel": (1610743827, 2, (3, 0), (), "EndSubMenuLevel", None),
        "HelpString": (1610743824, 2, (8, 0), (), "HelpString", None),
        "Index": (1610743822, 2, (3, 0), (), "Index", None),
        "Label": (1610743810, 2, (8, 0), (), "Label", None),
        "Macro": (1610743820, 2, (8, 0), (), "Macro", None),
        # Method 'Parent' returns object of type 'IAcadPopupMenu'
        "Parent": (1610743809, 2, (9, 0), (), "Parent", '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}'),
        # Method 'SubMenu' returns object of type 'IAcadPopupMenu'
        "SubMenu": (1610743819, 2, (9, 0), (), "SubMenu", '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}'),
        "TagString": (1610743812, 2, (8, 0), (), "TagString", None),
        "Type": (1610743818, 2, (3, 0), (), "Type", None),
    }
    _prop_map_put_ = {
        "Check": ((1610743816, LCID, 4, 0),()),
        "Enable": ((1610743814, LCID, 4, 0),()),
        "EndSubMenuLevel": ((1610743827, LCID, 4, 0),()),
        "HelpString": ((1610743824, LCID, 4, 0),()),
        "Label": ((1610743810, LCID, 4, 0),()),
        "Macro": ((1610743820, LCID, 4, 0),()),
        "TagString": ((1610743812, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPopupMenus(DispatchBaseClass):
    'A collection of PopupMenu objects'
    CLSID = IID('{3305CB53-F955-41F3-A47B-B7AA53B22D48}')
    coclass_clsid = IID('{18B24243-321E-4980-9351-57C02F246EC9}')

    # Result is of type IAcadPopupMenu
    def Add(self, MenuName=defaultNamedNotOptArg):
        'Creates a menu and adds it to the appropriate collection'
        ret = self._oleobj_.InvokeTypes(1610743813, LCID, 1, (9, 0), ((8, 1),),MenuName
            )
        if ret is not None:
            ret = Dispatch(ret, 'Add', '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
        return ret

    def InsertMenuInMenuBar(self, MenuName=defaultNamedNotOptArg, Index=defaultNamedNotOptArg):
        'Inserts a menu into the menu bar'
        return self._oleobj_.InvokeTypes(1610743814, LCID, 1, (24, 0), ((8, 1), (12, 1)),MenuName
            , Index)

    # Result is of type IAcadPopupMenu
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a group'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
        return ret

    def RemoveMenuFromMenuBar(self, Index=defaultNamedNotOptArg):
        'Removes the popup menu from the menu bar'
        return self._oleobj_.InvokeTypes(1610743815, LCID, 1, (24, 0), ((12, 1),),Index
            )

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
        # Method 'Parent' returns object of type 'IAcadMenuGroup'
        "Parent": (1610743812, 2, (9, 0), (), "Parent", '{DF14CB14-CDC6-463F-B71C-356149D1F935}'),
    }
    _prop_map_put_ = {
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a group'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadPreferences(DispatchBaseClass):
    'This object specifies the current BricsCAD settings'
    CLSID = IID('{03CE46C1-93A9-4E5C-B7F5-7AC7E2D48948}')
    coclass_clsid = IID('{A3EAF524-D893-4F6F-8D07-7F9416F7EBB9}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        # Method 'Display' returns object of type 'IAcadPreferencesDisplay'
        "Display": (1610743810, 2, (9, 0), (), "Display", '{0D71BC3C-9854-4076-BD32-D545259AB752}'),
        # Method 'Drafting' returns object of type 'IAcadPreferencesDrafting'
        "Drafting": (1610743815, 2, (9, 0), (), "Drafting", '{35D9C296-C2E9-4DAB-93CA-4A62F71C9FC1}'),
        # Method 'Files' returns object of type 'IAcadPreferencesFiles'
        "Files": (1610743809, 2, (9, 0), (), "Files", '{125FA500-9ABC-4F98-87AD-869AEFA4AD72}'),
        # Method 'OpenSave' returns object of type 'IAcadPreferencesOpenSave'
        "OpenSave": (1610743811, 2, (9, 0), (), "OpenSave", '{5E24ED87-DC43-4771-B7E6-7FE35C21CAB1}'),
        # Method 'Output' returns object of type 'IAcadPreferencesOutput'
        "Output": (1610743812, 2, (9, 0), (), "Output", '{1560A14A-D97B-4B3B-BF95-D0F703723442}'),
        # Method 'Profiles' returns object of type 'IAcadPreferencesProfiles'
        "Profiles": (1610743817, 2, (9, 0), (), "Profiles", '{52F0656B-9D63-4C67-ADBF-E9C732ED271B}'),
        # Method 'Selection' returns object of type 'IAcadPreferencesSelection'
        "Selection": (1610743816, 2, (9, 0), (), "Selection", '{CE512178-E98E-4225-800E-0A29DEE39BCD}'),
        # Method 'System' returns object of type 'IAcadPreferencesSystem'
        "System": (1610743813, 2, (9, 0), (), "System", '{408546BA-FF59-4AA8-98C5-A1DBA4B730F8}'),
        # Method 'User' returns object of type 'IAcadPreferencesUser'
        "User": (1610743814, 2, (9, 0), (), "User", '{689AE380-B75C-430E-8A70-D116D8B4FA63}'),
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesDisplay(DispatchBaseClass):
    'This object contains the options from the Display tab on the Options dialog'
    CLSID = IID('{0D71BC3C-9854-4076-BD32-D545259AB752}')
    coclass_clsid = IID('{100E11DA-6700-452D-B6BE-0B65FDB2E17A}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "AutoTrackingVecColor": (1610743841, 2, (19, 0), (), "AutoTrackingVecColor", None),
        "CursorSize": (1610743823, 2, (3, 0), (), "CursorSize", None),
        "DisplayLayoutTabs": (1610743853, 2, (11, 0), (), "DisplayLayoutTabs", None),
        "DisplayScreenMenu": (1610743821, 2, (11, 0), (), "DisplayScreenMenu", None),
        "DisplayScrollBars": (1610743819, 2, (11, 0), (), "DisplayScrollBars", None),
        "DockedVisibleLines": (1610743825, 2, (3, 0), (), "DockedVisibleLines", None),
        "GraphicsWinLayoutBackgrndColor": (1610743833, 2, (19, 0), (), "GraphicsWinLayoutBackgrndColor", None),
        "GraphicsWinModelBackgrndColor": (1610743829, 2, (19, 0), (), "GraphicsWinModelBackgrndColor", None),
        "HistoryLines": (1610743849, 2, (3, 0), (), "HistoryLines", None),
        "ImageFrameHighlight": (1610743855, 2, (11, 0), (), "ImageFrameHighlight", None),
        "LayoutCreateViewport": (1610743817, 2, (11, 0), (), "LayoutCreateViewport", None),
        "LayoutCrosshairColor": (1610743839, 2, (19, 0), (), "LayoutCrosshairColor", None),
        "LayoutDisplayMargins": (1610743809, 2, (11, 0), (), "LayoutDisplayMargins", None),
        "LayoutDisplayPaper": (1610743811, 2, (11, 0), (), "LayoutDisplayPaper", None),
        "LayoutDisplayPaperShadow": (1610743813, 2, (11, 0), (), "LayoutDisplayPaperShadow", None),
        "LayoutShowPlotSetup": (1610743815, 2, (11, 0), (), "LayoutShowPlotSetup", None),
        "MaxAutoCADWindow": (1610743851, 2, (11, 0), (), "MaxAutoCADWindow", None),
        "ModelCrosshairColor": (1610743831, 2, (19, 0), (), "ModelCrosshairColor", None),
        "ShowRasterImage": (1610743827, 2, (11, 0), (), "ShowRasterImage", None),
        "TextFont": (1610743843, 2, (8, 0), (), "TextFont", None),
        "TextFontSize": (1610743847, 2, (3, 0), (), "TextFontSize", None),
        "TextFontStyle": (1610743845, 2, (3, 0), (), "TextFontStyle", None),
        "TextWinBackgrndColor": (1610743835, 2, (19, 0), (), "TextWinBackgrndColor", None),
        "TextWinTextColor": (1610743837, 2, (19, 0), (), "TextWinTextColor", None),
        "TrueColorImages": (1610743857, 2, (11, 0), (), "TrueColorImages", None),
        "XRefFadeIntensity": (1610743859, 2, (3, 0), (), "XRefFadeIntensity", None),
    }
    _prop_map_put_ = {
        "AutoTrackingVecColor": ((1610743841, LCID, 4, 0),()),
        "CursorSize": ((1610743823, LCID, 4, 0),()),
        "DisplayLayoutTabs": ((1610743853, LCID, 4, 0),()),
        "DisplayScreenMenu": ((1610743821, LCID, 4, 0),()),
        "DisplayScrollBars": ((1610743819, LCID, 4, 0),()),
        "DockedVisibleLines": ((1610743825, LCID, 4, 0),()),
        "GraphicsWinLayoutBackgrndColor": ((1610743833, LCID, 4, 0),()),
        "GraphicsWinModelBackgrndColor": ((1610743829, LCID, 4, 0),()),
        "HistoryLines": ((1610743849, LCID, 4, 0),()),
        "ImageFrameHighlight": ((1610743855, LCID, 4, 0),()),
        "LayoutCreateViewport": ((1610743817, LCID, 4, 0),()),
        "LayoutCrosshairColor": ((1610743839, LCID, 4, 0),()),
        "LayoutDisplayMargins": ((1610743809, LCID, 4, 0),()),
        "LayoutDisplayPaper": ((1610743811, LCID, 4, 0),()),
        "LayoutDisplayPaperShadow": ((1610743813, LCID, 4, 0),()),
        "LayoutShowPlotSetup": ((1610743815, LCID, 4, 0),()),
        "MaxAutoCADWindow": ((1610743851, LCID, 4, 0),()),
        "ModelCrosshairColor": ((1610743831, LCID, 4, 0),()),
        "ShowRasterImage": ((1610743827, LCID, 4, 0),()),
        "TextFont": ((1610743843, LCID, 4, 0),()),
        "TextFontSize": ((1610743847, LCID, 4, 0),()),
        "TextFontStyle": ((1610743845, LCID, 4, 0),()),
        "TextWinBackgrndColor": ((1610743835, LCID, 4, 0),()),
        "TextWinTextColor": ((1610743837, LCID, 4, 0),()),
        "TrueColorImages": ((1610743857, LCID, 4, 0),()),
        "XRefFadeIntensity": ((1610743859, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesDrafting(DispatchBaseClass):
    'This object contains the options from the Drafting tab on the Options dialog'
    CLSID = IID('{35D9C296-C2E9-4DAB-93CA-4A62F71C9FC1}')
    coclass_clsid = IID('{F6B948E8-500C-4305-A2EA-71FA28A35530}')

    _prop_map_get_ = {
        "AlignmentPointAcquisition": (1610743829, 2, (3, 0), (), "AlignmentPointAcquisition", None),
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "AutoSnapAperture": (1610743815, 2, (11, 0), (), "AutoSnapAperture", None),
        "AutoSnapApertureSize": (1610743817, 2, (3, 0), (), "AutoSnapApertureSize", None),
        "AutoSnapMagnet": (1610743811, 2, (11, 0), (), "AutoSnapMagnet", None),
        "AutoSnapMarker": (1610743809, 2, (11, 0), (), "AutoSnapMarker", None),
        "AutoSnapMarkerColor": (1610743819, 2, (3, 0), (), "AutoSnapMarkerColor", None),
        "AutoSnapMarkerSize": (1610743821, 2, (3, 0), (), "AutoSnapMarkerSize", None),
        "AutoSnapTooltip": (1610743813, 2, (11, 0), (), "AutoSnapTooltip", None),
        "AutoTrackTooltip": (1610743827, 2, (11, 0), (), "AutoTrackTooltip", None),
        "FullScreenTrackingVector": (1610743825, 2, (11, 0), (), "FullScreenTrackingVector", None),
        "PolarTrackingVector": (1610743823, 2, (11, 0), (), "PolarTrackingVector", None),
    }
    _prop_map_put_ = {
        "AlignmentPointAcquisition": ((1610743829, LCID, 4, 0),()),
        "AutoSnapAperture": ((1610743815, LCID, 4, 0),()),
        "AutoSnapApertureSize": ((1610743817, LCID, 4, 0),()),
        "AutoSnapMagnet": ((1610743811, LCID, 4, 0),()),
        "AutoSnapMarker": ((1610743809, LCID, 4, 0),()),
        "AutoSnapMarkerColor": ((1610743819, LCID, 4, 0),()),
        "AutoSnapMarkerSize": ((1610743821, LCID, 4, 0),()),
        "AutoSnapTooltip": ((1610743813, LCID, 4, 0),()),
        "AutoTrackTooltip": ((1610743827, LCID, 4, 0),()),
        "FullScreenTrackingVector": ((1610743825, LCID, 4, 0),()),
        "PolarTrackingVector": ((1610743823, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesFiles(DispatchBaseClass):
    'This object contains the options from the Files tab on the Options dialog'
    CLSID = IID('{125FA500-9ABC-4F98-87AD-869AEFA4AD72}')
    coclass_clsid = IID('{354D8744-81E2-4BB0-AC00-2C2471F3BEBE}')

    def GetProjectFilePath(self, ProjectName=defaultNamedNotOptArg):
        'Gets the directory in which BricsCAD looks for external reference files'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743854, LCID, 1, (8, 0), ((8, 1),),ProjectName
            )

    def SetProjectFilePath(self, ProjectName=defaultNamedNotOptArg, ProjectFilePath=defaultNamedNotOptArg):
        'Sets the directory in which BricsCAD looks for external reference files'
        return self._oleobj_.InvokeTypes(1610743853, LCID, 1, (24, 0), ((8, 1), (8, 1)),ProjectName
            , ProjectFilePath)

    _prop_map_get_ = {
        "AltFontFile": (1610743827, 2, (8, 0), (), "AltFontFile", None),
        "AltTabletMenuFile": (1610743851, 2, (8, 0), (), "AltTabletMenuFile", None),
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "AutoSavePath": (1610743839, 2, (8, 0), (), "AutoSavePath", None),
        "ColorBookPath": (1610743865, 2, (8, 0), (), "ColorBookPath", None),
        "ConfigFile": (1610743819, 2, (8, 0), (), "ConfigFile", None),
        "CustomDictionary": (1610743825, 2, (8, 0), (), "CustomDictionary", None),
        "DefaultInternetURL": (1610743817, 2, (8, 0), (), "DefaultInternetURL", None),
        "DriversPath": (1610743811, 2, (8, 0), (), "DriversPath", None),
        "FontFileMap": (1610743829, 2, (8, 0), (), "FontFileMap", None),
        "HelpFilePath": (1610743815, 2, (8, 0), (), "HelpFilePath", None),
        "LicenseServer": (1610743820, 2, (8, 0), (), "LicenseServer", None),
        "LogFilePath": (1610743843, 2, (8, 0), (), "LogFilePath", None),
        "MainDictionary": (1610743823, 2, (8, 0), (), "MainDictionary", None),
        "MenuFile": (1610743813, 2, (8, 0), (), "MenuFile", None),
        "ObjectARXPath": (1610743863, 2, (8, 0), (), "ObjectARXPath", None),
        "PostScriptPrologFile": (1610743835, 2, (8, 0), (), "PostScriptPrologFile", None),
        "PrintFile": (1610743831, 2, (8, 0), (), "PrintFile", None),
        "PrintSpoolExecutable": (1610743833, 2, (8, 0), (), "PrintSpoolExecutable", None),
        "PrintSpoolerPath": (1610743837, 2, (8, 0), (), "PrintSpoolerPath", None),
        "PrinterConfigPath": (1610743855, 2, (8, 0), (), "PrinterConfigPath", None),
        "PrinterDescPath": (1610743857, 2, (8, 0), (), "PrinterDescPath", None),
        "PrinterStyleSheetPath": (1610743859, 2, (8, 0), (), "PrinterStyleSheetPath", None),
        "QNewTemplateFile": (1610743869, 2, (8, 0), (), "QNewTemplateFile", None),
        "SupportPath": (0, 2, (8, 0), (), "SupportPath", None),
        "TempFilePath": (1610743845, 2, (8, 0), (), "TempFilePath", None),
        "TempXrefPath": (1610743847, 2, (8, 0), (), "TempXrefPath", None),
        "TemplateDwgPath": (1610743841, 2, (8, 0), (), "TemplateDwgPath", None),
        "TextEditor": (1610743821, 2, (8, 0), (), "TextEditor", None),
        "TextureMapPath": (1610743849, 2, (8, 0), (), "TextureMapPath", None),
        "ToolPalettePath": (1610743867, 2, (8, 0), (), "ToolPalettePath", None),
        "WorkspacePath": (1610743861, 2, (8, 0), (), "WorkspacePath", None),
    }
    _prop_map_put_ = {
        "AltFontFile": ((1610743827, LCID, 4, 0),()),
        "AltTabletMenuFile": ((1610743851, LCID, 4, 0),()),
        "AutoSavePath": ((1610743839, LCID, 4, 0),()),
        "ColorBookPath": ((1610743865, LCID, 4, 0),()),
        "CustomDictionary": ((1610743825, LCID, 4, 0),()),
        "DefaultInternetURL": ((1610743817, LCID, 4, 0),()),
        "DriversPath": ((1610743811, LCID, 4, 0),()),
        "FontFileMap": ((1610743829, LCID, 4, 0),()),
        "HelpFilePath": ((1610743815, LCID, 4, 0),()),
        "LogFilePath": ((1610743843, LCID, 4, 0),()),
        "MainDictionary": ((1610743823, LCID, 4, 0),()),
        "MenuFile": ((1610743813, LCID, 4, 0),()),
        "ObjectARXPath": ((1610743863, LCID, 4, 0),()),
        "PostScriptPrologFile": ((1610743835, LCID, 4, 0),()),
        "PrintFile": ((1610743831, LCID, 4, 0),()),
        "PrintSpoolExecutable": ((1610743833, LCID, 4, 0),()),
        "PrintSpoolerPath": ((1610743837, LCID, 4, 0),()),
        "PrinterConfigPath": ((1610743855, LCID, 4, 0),()),
        "PrinterDescPath": ((1610743857, LCID, 4, 0),()),
        "PrinterStyleSheetPath": ((1610743859, LCID, 4, 0),()),
        "QNewTemplateFile": ((1610743869, LCID, 4, 0),()),
        "SupportPath": ((0, LCID, 4, 0),()),
        "TempFilePath": ((1610743845, LCID, 4, 0),()),
        "TempXrefPath": ((1610743847, LCID, 4, 0),()),
        "TemplateDwgPath": ((1610743841, LCID, 4, 0),()),
        "TextEditor": ((1610743821, LCID, 4, 0),()),
        "TextureMapPath": ((1610743849, LCID, 4, 0),()),
        "ToolPalettePath": ((1610743867, LCID, 4, 0),()),
        "WorkspacePath": ((1610743861, LCID, 4, 0),()),
    }
    # Default property for this class is 'SupportPath'
    def __call__(self):
        return self._ApplyTypes_(*(0, 2, (8, 0), (), "SupportPath", None))
    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesOpenSave(DispatchBaseClass):
    'This object contains the options from the Open and Save tab on the Options dialog'
    CLSID = IID('{5E24ED87-DC43-4771-B7E6-7FE35C21CAB1}')
    coclass_clsid = IID('{E21FACEF-E6A4-4DE1-8315-7F0F07EB877E}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "AutoAudit": (1610743831, 2, (11, 0), (), "AutoAudit", None),
        "AutoSaveInterval": (1610743813, 2, (3, 0), (), "AutoSaveInterval", None),
        "CreateBackup": (1610743815, 2, (11, 0), (), "CreateBackup", None),
        "DWFFormat": (1610743836, 2, (3, 0), (), "DWFFormat", None),
        "DemandLoadARXApp": (1610743825, 2, (3, 0), (), "DemandLoadARXApp", None),
        "FullCRCValidation": (1610743817, 2, (11, 0), (), "FullCRCValidation", None),
        "IncrementalSavePercent": (1610743811, 2, (3, 0), (), "IncrementalSavePercent", None),
        "LogFileOn": (1610743819, 2, (11, 0), (), "LogFileOn", None),
        "MRUNumber": (1610743835, 2, (3, 0), (), "MRUNumber", None),
        "ProxyImage": (1610743827, 2, (3, 0), (), "ProxyImage", None),
        "SaveAsType": (1610743833, 2, (3, 0), (), "SaveAsType", None),
        "SavePreviewThumbnail": (1610743809, 2, (11, 0), (), "SavePreviewThumbnail", None),
        "ShowProxyDialogBox": (1610743829, 2, (11, 0), (), "ShowProxyDialogBox", None),
        "TempFileExtension": (1610743821, 2, (8, 0), (), "TempFileExtension", None),
        "XrefDemandLoad": (1610743823, 2, (3, 0), (), "XrefDemandLoad", None),
    }
    _prop_map_put_ = {
        "AutoAudit": ((1610743831, LCID, 4, 0),()),
        "AutoSaveInterval": ((1610743813, LCID, 4, 0),()),
        "CreateBackup": ((1610743815, LCID, 4, 0),()),
        "DWFFormat": ((1610743836, LCID, 4, 0),()),
        "DemandLoadARXApp": ((1610743825, LCID, 4, 0),()),
        "FullCRCValidation": ((1610743817, LCID, 4, 0),()),
        "IncrementalSavePercent": ((1610743811, LCID, 4, 0),()),
        "LogFileOn": ((1610743819, LCID, 4, 0),()),
        "ProxyImage": ((1610743827, LCID, 4, 0),()),
        "SaveAsType": ((1610743833, LCID, 4, 0),()),
        "SavePreviewThumbnail": ((1610743809, LCID, 4, 0),()),
        "ShowProxyDialogBox": ((1610743829, LCID, 4, 0),()),
        "TempFileExtension": ((1610743821, LCID, 4, 0),()),
        "XrefDemandLoad": ((1610743823, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesOutput(DispatchBaseClass):
    'This object contains the options from the Output tab on the Options dialog'
    CLSID = IID('{1560A14A-D97B-4B3B-BF95-D0F703723442}')
    coclass_clsid = IID('{46B6BEE0-DA5A-4089-AC8A-70A254F31659}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "DefaultOutputDevice": (1610743809, 2, (8, 0), (), "DefaultOutputDevice", None),
        "DefaultPlotStyleForLayer": (1610743827, 2, (8, 0), (), "DefaultPlotStyleForLayer", None),
        "DefaultPlotStyleForObjects": (1610743825, 2, (8, 0), (), "DefaultPlotStyleForObjects", None),
        "DefaultPlotStyleTable": (1610743823, 2, (8, 0), (), "DefaultPlotStyleTable", None),
        "OLEQuality": (1610743817, 2, (3, 0), (), "OLEQuality", None),
        # Method 'Pdf' returns object of type 'IAcadPreferencesPdfOutput'
        "Pdf": (1610743828, 2, (9, 0), (), "Pdf", '{21F2EB66-F27E-40AF-A3F5-7F2E7D6F6AA6}'),
        "PlotLegacy": (1610743815, 2, (11, 0), (), "PlotLegacy", None),
        "PlotPolicy": (1610743821, 2, (3, 0), (), "PlotPolicy", None),
        "PrinterPaperSizeAlert": (1610743813, 2, (11, 0), (), "PrinterPaperSizeAlert", None),
        "PrinterSpoolAlert": (1610743811, 2, (3, 0), (), "PrinterSpoolAlert", None),
        "UseLastPlotSettings": (1610743819, 2, (11, 0), (), "UseLastPlotSettings", None),
    }
    _prop_map_put_ = {
        "DefaultOutputDevice": ((1610743809, LCID, 4, 0),()),
        "DefaultPlotStyleForLayer": ((1610743827, LCID, 4, 0),()),
        "DefaultPlotStyleForObjects": ((1610743825, LCID, 4, 0),()),
        "DefaultPlotStyleTable": ((1610743823, LCID, 4, 0),()),
        "OLEQuality": ((1610743817, LCID, 4, 0),()),
        "PlotLegacy": ((1610743815, LCID, 4, 0),()),
        "PlotPolicy": ((1610743821, LCID, 4, 0),()),
        "PrinterPaperSizeAlert": ((1610743813, LCID, 4, 0),()),
        "PrinterSpoolAlert": ((1610743811, LCID, 4, 0),()),
        "UseLastPlotSettings": ((1610743819, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesPdfOutput(DispatchBaseClass):
    'This object contains the pdf output options'
    CLSID = IID('{21F2EB66-F27E-40AF-A3F5-7F2E7D6F6AA6}')
    coclass_clsid = IID('{CB5F57D2-535C-4550-BDAC-FBFDB8778294}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "CreateBookmarks": (1610743821, 2, (11, 0), (), "CreateBookmarks", None),
        "EmbeddedTtf": (1610743814, 2, (11, 0), (), "EmbeddedTtf", None),
        "ExportHyperlinks": (1610743820, 2, (11, 0), (), "ExportHyperlinks", None),
        "LayersSetting": (1610743815, 2, (3, 0), (), "LayersSetting", None),
        "LayoutsToExport": (1610743816, 2, (3, 0), (), "LayoutsToExport", None),
        "PaperHeight": (1610743817, 2, (3, 0), (), "PaperHeight", None),
        "PaperSizeOverride": (1610743810, 2, (11, 0), (), "PaperSizeOverride", None),
        "PaperWidth": (1610743818, 2, (3, 0), (), "PaperWidth", None),
        "ShxTextAsGeometry": (1610743811, 2, (11, 0), (), "ShxTextAsGeometry", None),
        "SimpleGeomOptimization": (1610743812, 2, (11, 0), (), "SimpleGeomOptimization", None),
        "TtfTextAsGeometry": (1610743813, 2, (11, 0), (), "TtfTextAsGeometry", None),
        "UsePlotStyles": (1610743819, 2, (11, 0), (), "UsePlotStyles", None),
        "ZoomToExtents": (1610743809, 2, (11, 0), (), "ZoomToExtents", None),
    }
    _prop_map_put_ = {
        "CreateBookmarks": ((1610743821, LCID, 4, 0),()),
        "EmbeddedTtf": ((1610743814, LCID, 4, 0),()),
        "ExportHyperlinks": ((1610743820, LCID, 4, 0),()),
        "LayersSetting": ((1610743815, LCID, 4, 0),()),
        "LayoutsToExport": ((1610743816, LCID, 4, 0),()),
        "PaperHeight": ((1610743817, LCID, 4, 0),()),
        "PaperSizeOverride": ((1610743810, LCID, 4, 0),()),
        "PaperWidth": ((1610743818, LCID, 4, 0),()),
        "ShxTextAsGeometry": ((1610743811, LCID, 4, 0),()),
        "SimpleGeomOptimization": ((1610743812, LCID, 4, 0),()),
        "TtfTextAsGeometry": ((1610743813, LCID, 4, 0),()),
        "UsePlotStyles": ((1610743819, LCID, 4, 0),()),
        "ZoomToExtents": ((1610743809, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesProfiles(DispatchBaseClass):
    'This object contains the options from the Profiles tab on the Options dialog'
    CLSID = IID('{52F0656B-9D63-4C67-ADBF-E9C732ED271B}')
    coclass_clsid = IID('{71AE8036-20F2-4439-BF71-F27400E3291D}')

    def CopyProfile(self, oldProfileName=defaultNamedNotOptArg, newProfileName=defaultNamedNotOptArg):
        'Copies the specified profile'
        return self._oleobj_.InvokeTypes(1610743816, LCID, 1, (24, 0), ((8, 1), (8, 1)),oldProfileName
            , newProfileName)

    def DeleteProfile(self, ProfileName=defaultNamedNotOptArg):
        'Deletes the specified profile'
        return self._oleobj_.InvokeTypes(1610743813, LCID, 1, (24, 0), ((8, 1),),ProfileName
            )

    def ExportProfile(self, ProfileName=defaultNamedNotOptArg, RegFile=defaultNamedNotOptArg):
        'Exports the active profile so it can be shared with other users'
        return self._oleobj_.InvokeTypes(1610743812, LCID, 1, (24, 0), ((8, 1), (8, 1)),ProfileName
            , RegFile)

    def GetAllProfileNames(self, pNames=pythoncom.Missing):
        'Gets all available profiles for the system'
        return self._ApplyTypes_(1610743817, 1, (24, 0), ((16396, 2),), 'GetAllProfileNames', None,pNames
            )

    def ImportProfile(self, ProfileName=defaultNamedNotOptArg, RegFile=defaultNamedNotOptArg, IncludePathInfo=defaultNamedNotOptArg):
        'Imports a profile created by another user'
        return self._oleobj_.InvokeTypes(1610743811, LCID, 1, (24, 0), ((8, 1), (8, 1), (11, 1)),ProfileName
            , RegFile, IncludePathInfo)

    def RenameProfile(self, origProfileName=defaultNamedNotOptArg, newProfileName=defaultNamedNotOptArg):
        'Renames the specified profile'
        return self._oleobj_.InvokeTypes(1610743815, LCID, 1, (24, 0), ((8, 1), (8, 1)),origProfileName
            , newProfileName)

    def ResetProfile(self, Profile=defaultNamedNotOptArg):
        'Resets the value in the specified profile to its default values'
        return self._oleobj_.InvokeTypes(1610743814, LCID, 1, (24, 0), ((8, 1),),Profile
            )

    _prop_map_get_ = {
        "ActiveProfile": (1610743809, 2, (8, 0), (), "ActiveProfile", None),
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
    }
    _prop_map_put_ = {
        "ActiveProfile": ((1610743809, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesSelection(DispatchBaseClass):
    'This object contains the options from the Selection tab on the Options dialog'
    CLSID = IID('{CE512178-E98E-4225-800E-0A29DEE39BCD}')
    coclass_clsid = IID('{469FB7EC-09CF-4D1D-BAC8-4553F5098ADD}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "DisplayGrips": (1610743819, 2, (3, 0), (), "DisplayGrips", None),
        "DisplayGripsWithinBlocks": (1610743821, 2, (11, 0), (), "DisplayGripsWithinBlocks", None),
        "GripColorSelected": (1610743823, 2, (3, 0), (), "GripColorSelected", None),
        "GripColorUnselected": (1610743825, 2, (3, 0), (), "GripColorUnselected", None),
        "GripSize": (1610743827, 2, (3, 0), (), "GripSize", None),
        "PickAdd": (1610743811, 2, (11, 0), (), "PickAdd", None),
        "PickAuto": (1610743815, 2, (11, 0), (), "PickAuto", None),
        "PickBoxSize": (1610743817, 2, (3, 0), (), "PickBoxSize", None),
        "PickDrag": (1610743813, 2, (11, 0), (), "PickDrag", None),
        "PickFirst": (1610743809, 2, (11, 0), (), "PickFirst", None),
        "PickGroup": (1610743829, 2, (11, 0), (), "PickGroup", None),
    }
    _prop_map_put_ = {
        "DisplayGrips": ((1610743819, LCID, 4, 0),()),
        "DisplayGripsWithinBlocks": ((1610743821, LCID, 4, 0),()),
        "GripColorSelected": ((1610743823, LCID, 4, 0),()),
        "GripColorUnselected": ((1610743825, LCID, 4, 0),()),
        "GripSize": ((1610743827, LCID, 4, 0),()),
        "PickAdd": ((1610743811, LCID, 4, 0),()),
        "PickAuto": ((1610743815, LCID, 4, 0),()),
        "PickBoxSize": ((1610743817, LCID, 4, 0),()),
        "PickDrag": ((1610743813, LCID, 4, 0),()),
        "PickFirst": ((1610743809, LCID, 4, 0),()),
        "PickGroup": ((1610743829, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesSystem(DispatchBaseClass):
    'This object contains the options from the System tab on the Options dialog'
    CLSID = IID('{408546BA-FF59-4AA8-98C5-A1DBA4B730F8}')
    coclass_clsid = IID('{8A48E79C-D378-4111-82D9-A25F84F5B6DC}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "BeepOnError": (1610743819, 2, (11, 0), (), "BeepOnError", None),
        "DisplayOLEScale": (1610743811, 2, (11, 0), (), "DisplayOLEScale", None),
        "EnableStartupDialog": (1610743817, 2, (11, 0), (), "EnableStartupDialog", None),
        "LoadAcadLspInAllDocuments": (1610743823, 2, (11, 0), (), "LoadAcadLspInAllDocuments", None),
        "ShowWarningMessages": (1610743821, 2, (11, 0), (), "ShowWarningMessages", None),
        "SingleDocumentMode": (1610743809, 2, (11, 0), (), "SingleDocumentMode", None),
        "StoreSQLIndex": (1610743813, 2, (11, 0), (), "StoreSQLIndex", None),
        "TablesReadOnly": (1610743815, 2, (11, 0), (), "TablesReadOnly", None),
    }
    _prop_map_put_ = {
        "BeepOnError": ((1610743819, LCID, 4, 0),()),
        "DisplayOLEScale": ((1610743811, LCID, 4, 0),()),
        "EnableStartupDialog": ((1610743817, LCID, 4, 0),()),
        "LoadAcadLspInAllDocuments": ((1610743823, LCID, 4, 0),()),
        "ShowWarningMessages": ((1610743821, LCID, 4, 0),()),
        "SingleDocumentMode": ((1610743809, LCID, 4, 0),()),
        "StoreSQLIndex": ((1610743813, LCID, 4, 0),()),
        "TablesReadOnly": ((1610743815, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadPreferencesUser(DispatchBaseClass):
    'This object contains the options from the User tab on the Options dialog'
    CLSID = IID('{689AE380-B75C-430E-8A70-D116D8B4FA63}')
    coclass_clsid = IID('{DD509194-682F-49FE-9984-C7F0EE819A45}')

    _prop_map_get_ = {
        "ADCInsertUnitsDefaultSource": (1610743817, 2, (3, 0), (), "ADCInsertUnitsDefaultSource", None),
        "ADCInsertUnitsDefaultTarget": (1610743819, 2, (3, 0), (), "ADCInsertUnitsDefaultTarget", None),
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "HyperlinkDisplayCursor": (1610743813, 2, (11, 0), (), "HyperlinkDisplayCursor", None),
        "HyperlinkDisplayTooltip": (1610743815, 2, (11, 0), (), "HyperlinkDisplayTooltip", None),
        "KeyboardAccelerator": (1610743809, 2, (3, 0), (), "KeyboardAccelerator", None),
        "KeyboardPriority": (1610743811, 2, (3, 0), (), "KeyboardPriority", None),
        "SCMCommandMode": (1610743827, 2, (3, 0), (), "SCMCommandMode", None),
        "SCMDefaultMode": (1610743823, 2, (3, 0), (), "SCMDefaultMode", None),
        "SCMEditMode": (1610743825, 2, (3, 0), (), "SCMEditMode", None),
        "SCMTimeMode": (1610743829, 2, (11, 0), (), "SCMTimeMode", None),
        "SCMTimeValue": (1610743831, 2, (3, 0), (), "SCMTimeValue", None),
        "ShortCutMenuDisplay": (1610743821, 2, (11, 0), (), "ShortCutMenuDisplay", None),
    }
    _prop_map_put_ = {
        "ADCInsertUnitsDefaultSource": ((1610743817, LCID, 4, 0),()),
        "ADCInsertUnitsDefaultTarget": ((1610743819, LCID, 4, 0),()),
        "HyperlinkDisplayCursor": ((1610743813, LCID, 4, 0),()),
        "HyperlinkDisplayTooltip": ((1610743815, LCID, 4, 0),()),
        "KeyboardAccelerator": ((1610743809, LCID, 4, 0),()),
        "KeyboardPriority": ((1610743811, LCID, 4, 0),()),
        "SCMCommandMode": ((1610743827, LCID, 4, 0),()),
        "SCMDefaultMode": ((1610743823, LCID, 4, 0),()),
        "SCMEditMode": ((1610743825, LCID, 4, 0),()),
        "SCMTimeMode": ((1610743829, LCID, 4, 0),()),
        "SCMTimeValue": ((1610743831, LCID, 4, 0),()),
        "ShortCutMenuDisplay": ((1610743821, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadSecurityParams(DispatchBaseClass):
    'Security Parameters Interface'
    CLSID = IID('{A058E098-4DCF-4E3B-93BC-EF0FA19B718A}')
    coclass_clsid = IID('{06F4FD5D-DBD9-4B44-B464-6683CC541EDD}')

    _prop_map_get_ = {
        "Action": (1, 2, (3, 0), (), "Action", None),
        "Algorithm": (5, 2, (3, 0), (), "Algorithm", None),
        "Comment": (10, 2, (8, 0), (), "Comment", None),
        "Issuer": (8, 2, (8, 0), (), "Issuer", None),
        "KeyLength": (6, 2, (3, 0), (), "KeyLength", None),
        "Password": (2, 2, (8, 0), (), "Password", None),
        "ProviderName": (4, 2, (8, 0), (), "ProviderName", None),
        "ProviderType": (3, 2, (3, 0), (), "ProviderType", None),
        "SerialNumber": (9, 2, (8, 0), (), "SerialNumber", None),
        "Subject": (7, 2, (8, 0), (), "Subject", None),
        "TimeServer": (11, 2, (8, 0), (), "TimeServer", None),
    }
    _prop_map_put_ = {
        "Action": ((1, LCID, 4, 0),()),
        "Algorithm": ((5, LCID, 4, 0),()),
        "Comment": ((10, LCID, 4, 0),()),
        "Issuer": ((8, LCID, 4, 0),()),
        "KeyLength": ((6, LCID, 4, 0),()),
        "Password": ((2, LCID, 4, 0),()),
        "ProviderName": ((4, LCID, 4, 0),()),
        "ProviderType": ((3, LCID, 4, 0),()),
        "SerialNumber": ((9, LCID, 4, 0),()),
        "Subject": ((7, LCID, 4, 0),()),
        "TimeServer": ((11, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadSelectionSet(DispatchBaseClass):
    'A group of one or more BricsCAD objects specified for processing as a single unit'
    CLSID = IID('{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')
    coclass_clsid = IID('{F3862E27-3753-44F7-BDB0-24468C8E8CF6}')

    def AddItems(self, pSelSet=defaultNamedNotOptArg):
        'Adds one or more objects to the specified selection set'
        pSelSet = VTDISPArrayOrVal(pSelSet)
        return self._oleobj_.InvokeTypes(7, LCID, 1, (24, 0), ((12, 1),),pSelSet
            )

    def Clear(self):
        'Clears the specified selection set of all items'
        return self._oleobj_.InvokeTypes(9, LCID, 1, (24, 0), (),)

    def Delete(self):
        'Deletes a specified object'
        return self._oleobj_.InvokeTypes(14, LCID, 1, (24, 0), (),)

    def Erase(self):
        'Erases all the objects in a selection set'
        return self._oleobj_.InvokeTypes(4, LCID, 1, (24, 0), (),)

    def Highlight(self, bFlag=defaultNamedNotOptArg):
        'Sets the highlight status for the given object, or for all objects in a given selection set'
        return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((11, 1),),bFlag
            )

    # Result is of type IAcadEntity
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection, group, or selection set'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{FFE64704-CEBD-4C88-A867-E7C821AFE488}')
        return ret

    def RemoveItems(self, Objects=defaultNamedNotOptArg):
        'Removes specified items from the group or selection set'
        pSelSet = VTDISPArrayOrVal(pSelSet)
        return self._oleobj_.InvokeTypes(8, LCID, 1, (24, 0), ((12, 1),),Objects
            )

    def Select(self, Mode=defaultNamedNotOptArg, Point1=defaultNamedOptArg, Point2=defaultNamedOptArg, FilterType=defaultNamedOptArg
            , FilterData=defaultNamedOptArg):
        'Selects objects and places them into a selection set'
        Point1 = VTR8ArrayOrVal(Point1)
        Point2 = VTR8ArrayOrVal(Point2)
        FilterType = VTI2ArrayOrVal(FilterType)
        FilterData = VTVARArrayOrVal(FilterData)
        return self._oleobj_.InvokeTypes(10, LCID, 1, (24, 0), ((3, 1), (12, 17), (12, 17), (12, 17), (12, 17)),Mode
            , Point1, Point2, FilterType, FilterData)

    def SelectAtPoint(self, Point=defaultNamedNotOptArg, FilterType=defaultNamedOptArg, FilterData=defaultNamedOptArg):
        'Selects an object passing through a given point and places it into a selection set'
        Point = VTR8ArrayOrVal(Point)
        FilterType = VTI2ArrayOrVal(FilterType)
        FilterData = VTVARArrayOrVal(FilterData)
        return self._oleobj_.InvokeTypes(11, LCID, 1, (24, 0), ((12, 1), (12, 17), (12, 17)),Point
            , FilterType, FilterData)

    def SelectByPolygon(self, Mode=defaultNamedNotOptArg, PointsList=defaultNamedNotOptArg, FilterType=defaultNamedOptArg, FilterData=defaultNamedOptArg):
        'Selects entities within a fence and adds them to the selection set'
        PointsList = VTR8ArrayOrVal(PointsList)
        FilterType = VTI2ArrayOrVal(FilterType)
        FilterData = VTVARArrayOrVal(FilterData)
        return self._oleobj_.InvokeTypes(12, LCID, 1, (24, 0), ((3, 1), (12, 1), (12, 17), (12, 17)),Mode
            , PointsList, FilterType, FilterData)

    def SelectOnScreen(self, FilterType=defaultNamedOptArg, FilterData=defaultNamedOptArg):
        'Prompts the user to pick an object from the screen'
        FilterType = VTI2ArrayOrVal(FilterType)
        FilterData = VTVARArrayOrVal(FilterData)
        return self._oleobj_.InvokeTypes(13, LCID, 1, (24, 0), ((12, 17), (12, 17)),FilterType
            , FilterData)

    def Update(self):
        'Updates the object to the drawing screen'
        return self._oleobj_.InvokeTypes(5, LCID, 1, (24, 0), (),)

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (6, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1, 2, (3, 0), (), "Count", None),
        "Name": (2, 2, (8, 0), (), "Name", None),
    }
    _prop_map_put_ = {
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection, group, or selection set'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{FFE64704-CEBD-4C88-A867-E7C821AFE488}')
        return ret
    
    def __getitem__(self, *args): 
        try:
            return self.__call__(*args)
        except:
            raise IndexError

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{FFE64704-CEBD-4C88-A867-E7C821AFE488}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadSelectionSets(DispatchBaseClass):
    'The collection of all selection sets in the drawing'
    CLSID = IID('{37E34D42-8CD8-4E25-83BF-80C791AFEADE}')
    coclass_clsid = IID('{2F021E6D-67B2-4955-9135-A28F93BCEE6D}')

    # Result is of type IAcadSelectionSet
    def Add(self, Name=defaultNamedNotOptArg):
        'Creates a member object and adds it to the appropriate collection'
        ret = self._oleobj_.InvokeTypes(4, LCID, 1, (9, 0), ((8, 1),),Name
            )
        if ret is not None:
            ret = Dispatch(ret, 'Add', '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')
        return ret

    # Result is of type IAcadSelectionSet
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection, group, or selection set'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (2, 2, (3, 0), (), "Count", None),
    }
    _prop_map_put_ = {
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection, group, or selection set'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(2, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadState(DispatchBaseClass):
    'Application State Interface'
    CLSID = IID('{C2016470-443B-40D0-AD93-231ACFDCF594}')
    coclass_clsid = IID('{5696C1B9-643B-4E6E-B711-DB897137424E}')

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "IsQuiescent": (2, 2, (11, 0), (), "IsQuiescent", None),
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadToolbar(DispatchBaseClass):
    'IAcadToolbar Interface'
    CLSID = IID('{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')
    coclass_clsid = IID('{A8D0AE76-640B-44AA-BB5C-6986706CA9F6}')

    # Result is of type IAcadToolbarItem
    def AddSeparator(self, Index=defaultNamedNotOptArg):
        'Adds a separator to an existing toolbar'
        ret = self._oleobj_.InvokeTypes(1610743830, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'AddSeparator', '{EBCED992-0BB7-4165-B4D6-44261F377565}')
        return ret

    # Result is of type IAcadToolbarItem
    def AddToolbarButton(self, Index=defaultNamedNotOptArg, Name=defaultNamedNotOptArg, HelpString=defaultNamedNotOptArg, Macro=defaultNamedNotOptArg
            , FlyoutButton=defaultNamedOptArg):
        'Adds a toolbar item to a toolbar at a specified position'
        ret = self._oleobj_.InvokeTypes(1610743829, LCID, 1, (9, 0), ((12, 1), (8, 1), (8, 1), (8, 1), (12, 17)),Index
            , Name, HelpString, Macro, FlyoutButton)
        if ret is not None:
            ret = Dispatch(ret, 'AddToolbarButton', '{EBCED992-0BB7-4165-B4D6-44261F377565}')
        return ret

    def Delete(self):
        'Deletes a specified object'
        return self._oleobj_.InvokeTypes(1610743833, LCID, 1, (24, 0), (),)

    def Dock(self, Side=defaultNamedNotOptArg):
        'Docks the toolbar to the owning frame window'
        return self._oleobj_.InvokeTypes(1610743831, LCID, 1, (24, 0), ((3, 1),),Side
            )

    def Float(self, top=defaultNamedNotOptArg, left=defaultNamedNotOptArg, NumberFloatRows=defaultNamedNotOptArg):
        'Floats the toolbar'
        return self._oleobj_.InvokeTypes(1610743832, LCID, 1, (24, 0), ((3, 1), (3, 1), (3, 1)),top
            , left, NumberFloatRows)

    # Result is of type IAcadToolbarItem
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{EBCED992-0BB7-4165-B4D6-44261F377565}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
        "DockStatus": (1610743817, 2, (3, 0), (), "DockStatus", None),
        "FloatingRows": (1610743825, 2, (3, 0), (), "FloatingRows", None),
        "Height": (1610743824, 2, (3, 0), (), "Height", None),
        "HelpString": (1610743827, 2, (8, 0), (), "HelpString", None),
        "LargeButtons": (1610743818, 2, (11, 0), (), "LargeButtons", None),
        "Name": (1610743813, 2, (8, 0), (), "Name", None),
        "Parent": (1610743812, 2, (9, 0), (), "Parent", None),
        "TagString": (1610743834, 2, (8, 0), (), "TagString", None),
        "Visible": (1610743815, 2, (11, 0), (), "Visible", None),
        "Width": (1610743823, 2, (3, 0), (), "Width", None),
        "left": (1610743819, 2, (3, 0), (), "left", None),
        "top": (1610743821, 2, (3, 0), (), "top", None),
    }
    _prop_map_put_ = {
        "FloatingRows": ((1610743825, LCID, 4, 0),()),
        "HelpString": ((1610743827, LCID, 4, 0),()),
        "Name": ((1610743813, LCID, 4, 0),()),
        "Visible": ((1610743815, LCID, 4, 0),()),
        "left": ((1610743819, LCID, 4, 0),()),
        "top": ((1610743821, LCID, 4, 0),()),
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{EBCED992-0BB7-4165-B4D6-44261F377565}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{EBCED992-0BB7-4165-B4D6-44261F377565}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadToolbarItem(DispatchBaseClass):
    'A single toolbar button'
    CLSID = IID('{EBCED992-0BB7-4165-B4D6-44261F377565}')
    coclass_clsid = IID('{C9F46D28-7AEE-48F1-B8B7-6F8E7EC40625}')

    def AttachToolbarToFlyout(self, MenuGroupName=defaultNamedNotOptArg, ToolbarName=defaultNamedNotOptArg):
        'Attaches a toolbar to a toolbar button defined as a flyout'
        return self._oleobj_.InvokeTypes(1610743823, LCID, 1, (24, 0), ((8, 1), (8, 1)),MenuGroupName
            , ToolbarName)

    def Delete(self):
        'Deletes a specified object'
        return self._oleobj_.InvokeTypes(1610743824, LCID, 1, (24, 0), (),)

    def GetBitmaps(self, SmallIconName=pythoncom.Missing, LargeIconName=pythoncom.Missing):
        'Gets the large and small bitmaps used as icons for the toolbar item'
        return self._ApplyTypes_(1610743821, 1, (24, 0), ((16392, 2), (16392, 2)), 'GetBitmaps', None,SmallIconName
            , LargeIconName)

    def SetBitmaps(self, SmallIconName=defaultNamedNotOptArg, LargeIconName=defaultNamedNotOptArg):
        'Sets the large and small bitmaps used as icons for the toolbar item'
        return self._oleobj_.InvokeTypes(1610743822, LCID, 1, (24, 0), ((8, 1), (8, 1)),SmallIconName
            , LargeIconName)

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743808, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        # Method 'Flyout' returns object of type 'IAcadToolbar'
        "Flyout": (1610743815, 2, (9, 0), (), "Flyout", '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}'),
        "HelpString": (1610743819, 2, (8, 0), (), "HelpString", None),
        "Index": (1610743818, 2, (3, 0), (), "Index", None),
        "Macro": (1610743816, 2, (8, 0), (), "Macro", None),
        "Name": (1610743810, 2, (8, 0), (), "Name", None),
        # Method 'Parent' returns object of type 'IAcadToolbar'
        "Parent": (1610743809, 2, (9, 0), (), "Parent", '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}'),
        "TagString": (1610743812, 2, (8, 0), (), "TagString", None),
        "Type": (1610743814, 2, (3, 0), (), "Type", None),
    }
    _prop_map_put_ = {
        "HelpString": ((1610743819, LCID, 4, 0),()),
        "Macro": ((1610743816, LCID, 4, 0),()),
        "Name": ((1610743810, LCID, 4, 0),()),
        "TagString": ((1610743812, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IAcadToolbars(DispatchBaseClass):
    'A collection of Toolbar objects'
    CLSID = IID('{F7DF12AA-4EF4-4EEE-8D00-68BB80D7F092}')
    coclass_clsid = IID('{6625C943-4F9E-4FCD-B847-454FCDC56C19}')

    # Result is of type IAcadToolbar
    def Add(self, ToolbarName=defaultNamedNotOptArg):
        'Creates a member object and adds it to the appropriate collection'
        ret = self._oleobj_.InvokeTypes(1610743815, LCID, 1, (9, 0), ((8, 1),),ToolbarName
            )
        if ret is not None:
            ret = Dispatch(ret, 'Add', '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')
        return ret

    # Result is of type IAcadToolbar
    def Item(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Item', '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1610743811, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        "Count": (1610743810, 2, (3, 0), (), "Count", None),
        "LargeButtons": (1610743813, 2, (11, 0), (), "LargeButtons", None),
        # Method 'Parent' returns object of type 'IAcadMenuGroup'
        "Parent": (1610743812, 2, (9, 0), (), "Parent", '{DF14CB14-CDC6-463F-B71C-356149D1F935}'),
    }
    _prop_map_put_ = {
        "LargeButtons": ((1610743813, LCID, 4, 0),()),
    }
    # Default method for this class is 'Item'
    def __call__(self, Index=defaultNamedNotOptArg):
        'Gets the member object at a given index in a collection'
        ret = self._oleobj_.InvokeTypes(0, LCID, 1, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, '__call__', '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')
        return ret

    def __str__(self, *args):
        return str(self.__call__(*args))
    def __int__(self, *args):
        return int(self.__call__(*args))
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,2,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')
    #This class has Count() property - allow len(ob) to provide this
    def __len__(self):
        return self._ApplyTypes_(*(1610743810, 2, (3, 0), (), "Count", None))
    #This class has a __len__ - this is needed so 'if object:' always returns TRUE.
    def __nonzero__(self):
        return True

class IAcadUtility(DispatchBaseClass):
    'A series of methods provided for utility purposes'
    CLSID = IID('{5046A00A-7C22-4D39-ADE0-FB1AE3709B4D}')
    coclass_clsid = IID('{AB480185-F159-4B5D-BC9E-AEA9AB722DF1}')

    def AngleFromXAxis(self, StartPoint=defaultNamedNotOptArg, EndPoint=defaultNamedNotOptArg):
        'Gets the angle of a line from the X axis'
        StartPoint = VTR8ArrayOrVal(StartPoint)
        EndPoint = VTR8ArrayOrVal(EndPoint)
        return self._oleobj_.InvokeTypes(1610743820, LCID, 1, (5, 0), ((12, 1), (12, 1)),StartPoint
            , EndPoint)

    def AngleToReal(self, Angle=defaultNamedNotOptArg, Unit=defaultNamedNotOptArg):
        'Converts an angle as a string to a real (double) value'
        return self._oleobj_.InvokeTypes(1610743808, LCID, 1, (5, 0), ((8, 1), (3, 1)),Angle
            , Unit)

    def AngleToString(self, Angle=defaultNamedNotOptArg, Unit=defaultNamedNotOptArg, precision=defaultNamedNotOptArg):
        'Converts an angle from a real (double) value to a string'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743809, LCID, 1, (8, 0), ((5, 1), (3, 1), (3, 1)),Angle
            , Unit, precision)

    def CreateTypedArray(self, *args):
        'Creates a variant that contains an array of typed arguments'
        return self._get_good_object_(self._oleobj_.Invoke(*((1610743826,0,1,1)+args)),'CreateTypedArray')

    def DistanceToReal(self, Distance=defaultNamedNotOptArg, Unit=defaultNamedNotOptArg):
        'Converts a distance from a string to a real (double) value'
        return self._oleobj_.InvokeTypes(1610743810, LCID, 1, (5, 0), ((8, 1), (3, 1)),Distance
            , Unit)

    def GetAngle(self, Point=defaultNamedOptArg, Prompt=defaultNamedOptArg):
        'Gets the angle specified. Considers the setting of the ANGBASE system variable'
        Point = VTR8ArrayOrVal(Point)
        return self._oleobj_.InvokeTypes(1610743819, LCID, 1, (5, 0), ((12, 17), (12, 17)),Point
            , Prompt)

    def GetCorner(self, Point=defaultNamedNotOptArg, Prompt=defaultNamedOptArg):
        'Gets a corner of a rectangle'
        Point = VTR8ArrayOrVal(Point)
        return self._ApplyTypes_(1610743821, 1, (12, 0), ((12, 1), (12, 17)), 'GetCorner', None,Point
            , Prompt)

    def GetDistance(self, Point=defaultNamedOptArg, Prompt=defaultNamedOptArg):
        'Gets the distance from the prompt line or a selected set of points on the screen'
        Point = VTR8ArrayOrVal(Point)
        return self._oleobj_.InvokeTypes(1610743822, LCID, 1, (5, 0), ((12, 17), (12, 17)),Point
            , Prompt)

    def GetEntity(self, Object=pythoncom.Missing, PickedPoint=pythoncom.Missing, Prompt=defaultNamedOptArg):
        'Gets an object interactively'
        Object=None
        PickedPoint=None
        return self._ApplyTypes_(1610743827, 1, (24, 0), ((16393, 2), (16396, 2), (12, 17)), 'GetEntity', None,Object
            , PickedPoint, Prompt)

    def GetInput(self):
        'Converts an input string from the user into a keyword index'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743816, LCID, 1, (8, 0), (),)

    def GetInteger(self, Prompt=defaultNamedOptArg):
        'Gets an integer value from the user'
        return self._oleobj_.InvokeTypes(1610743814, LCID, 1, (3, 0), ((12, 17),),Prompt
            )

    def GetKeyword(self, Prompt=defaultNamedOptArg):
        'Gets a keyword string from the user'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743817, LCID, 1, (8, 0), ((12, 17),),Prompt
            )

    def GetObjectIdString(self, Object=defaultNamedNotOptArg, asHex=defaultNamedNotOptArg):
        'Returns an integer or hexadecimal string for the given ObjectId.'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743839, LCID, 1, (8, 0), ((9, 1), (11, 1)),Object
            , asHex)

    def GetOrientation(self, Point=defaultNamedOptArg, Prompt=defaultNamedOptArg):
        'Gets the angle specified. Ignores the setting of the ANGBASE system variable'
        Point = VTR8ArrayOrVal(Point)
        return self._oleobj_.InvokeTypes(1610743823, LCID, 1, (5, 0), ((12, 17), (12, 17)),Point
            , Prompt)

    def GetPoint(self, Prompt=defaultNamedOptArg):
        'Gets the point selected in the application'
        Point = pythoncom.Empty
        return self._ApplyTypes_(1610743824, 1, (12, 0), ((12, 17), (12, 17)), 'GetPoint', None,Point
            , Prompt)
        
    def GetPointWithBase(self, Point=defaultNamedOptArg, Prompt=defaultNamedOptArg):
        'Gets the point selected in AutoCAD'
        Point = VTR8ArrayOrVal(Point)
        return self._ApplyTypes_(1610743824, 1, (12, 0), ((12, 17), (12, 17)), 'GetPoint', None,Point
            , Prompt)

    def GetReal(self, Prompt=defaultNamedOptArg):
        'Gets a real (double) value from the user'
        return self._oleobj_.InvokeTypes(1610743815, LCID, 1, (5, 0), ((12, 17),),Prompt
            )

    def GetRemoteFile(self, URL=defaultNamedNotOptArg, LocalFile=pythoncom.Missing, IgnoreCache=defaultNamedNotOptArg):
        'Downloads the file specified by a URL. Not mplemented yet.'
        return self._ApplyTypes_(1610743831, 1, (24, 0), ((8, 1), (16392, 2), (11, 1)), 'GetRemoteFile', None,URL
            , LocalFile, IgnoreCache)

    def GetString(self, HasSpaces=defaultNamedNotOptArg, Prompt=defaultNamedOptArg):
        'Gets a string from the user'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743818, LCID, 1, (8, 0), ((3, 1), (12, 17)),HasSpaces
            , Prompt)

    def GetSubEntity(self, Object=pythoncom.Missing, PickedPoint=pythoncom.Missing, transMatrix=pythoncom.Missing, ContextData=pythoncom.Missing
            , Prompt=defaultNamedOptArg):
        'Gets an object or subentity interactively'
        Object=pythoncom.Missing
        PickedPoint=pythoncom.Missing
        transMatrix=pythoncom.Missing
        ContextData=pythoncom.Missing
        return self._ApplyTypes_(1610743829, 1, (24, 0), ((16393, 2), (16396, 2), (16396, 2), (16396, 2), (12, 17)), 'GetSubEntity', None,Object
            , PickedPoint, transMatrix, ContextData, Prompt)

    def InitializeUserInput(self, Bits=defaultNamedNotOptArg, KeyWordList=defaultNamedOptArg):
        'Initializes the GetKeyword method'
        return self._oleobj_.InvokeTypes(1610743813, LCID, 1, (24, 0), ((3, 1), (12, 17)),Bits
            , KeyWordList)

    def IsRemoteFile(self, LocalFile=defaultNamedNotOptArg, URL=pythoncom.Missing):
        'Returns the URL that a remote file was downloaded from. Not mplemented yet.'
        return self._ApplyTypes_(1610743833, 1, (11, 0), ((8, 1), (16392, 2)), 'IsRemoteFile', None,LocalFile
            , URL)

    def IsURL(self, URL=defaultNamedNotOptArg):
        'Validates a given URL. Not mplemented yet.'
        return self._oleobj_.InvokeTypes(1610743830, LCID, 1, (11, 0), ((8, 1),),URL
            )

    def LaunchBrowserDialog(self, SelectedURL=pythoncom.Missing, DialogTitle=defaultNamedNotOptArg, OpenButtonCaption=defaultNamedNotOptArg, StartPageURL=defaultNamedNotOptArg
            , RegistryRootKey=defaultNamedNotOptArg, OpenButtonAlwaysEnabled=defaultNamedNotOptArg):
        'Launches the Web Browser dialog that allows the user to navigate to any URL and select a URL. Not mplemented yet.'
        return self._ApplyTypes_(1610743834, 1, (11, 0), ((16392, 2), (8, 1), (8, 1), (8, 1), (8, 1), (11, 1)), 'LaunchBrowserDialog', None,SelectedURL
            , DialogTitle, OpenButtonCaption, StartPageURL, RegistryRootKey, OpenButtonAlwaysEnabled
            )

    def LogMessage(self, msg=defaultNamedNotOptArg):
        'Writes message to temp log file during regress script test session'
        return self._oleobj_.InvokeTypes(1610743856, LCID, 1, (24, 0), ((8, 1),),msg
            )

    def ObjectId32ToObjectIdString(self, objectId32=defaultNamedNotOptArg):
        'Returns an integer string for the ObjectId, specified as 32 bit value.'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743838, LCID, 1, (8, 0), ((3, 1),),objectId32
            )

    def PolarPoint(self, Point=defaultNamedNotOptArg, Angle=defaultNamedNotOptArg, Distance=defaultNamedNotOptArg):
        'Gets the point at a specified angle and distance from a given point'
        Point = VTR8ArrayOrVal(Point)
        return self._ApplyTypes_(1610743825, 1, (12, 0), ((12, 1), (5, 1), (5, 1)), 'PolarPoint', None,Point
            , Angle, Distance)

    def Prompt(self, Message=defaultNamedNotOptArg):
        'Posts a prompt to the command line'
        return self._oleobj_.InvokeTypes(1610743828, LCID, 1, (24, 0), ((8, 1),),Message
            )

    def PutRemoteFile(self, URL=defaultNamedNotOptArg, LocalFile=defaultNamedNotOptArg):
        'Uploads a file to a remote location specified by a URL. Not mplemented yet.'
        return self._oleobj_.InvokeTypes(1610743832, LCID, 1, (24, 0), ((8, 1), (8, 1)),URL
            , LocalFile)

    def RealToString(self, Value=defaultNamedNotOptArg, Unit=defaultNamedNotOptArg, precision=defaultNamedNotOptArg):
        'Converts a real (double) value to a string'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(1610743811, LCID, 1, (8, 0), ((5, 1), (3, 1), (3, 1)),Value
            , Unit, precision)

    def SendModelessOperationEnded(self, operation=defaultNamedNotOptArg):
        'Notifyes the system about the end of a modeless operation.'
        return self._oleobj_.InvokeTypes(1610743836, LCID, 1, (24, 0), ((8, 0),),operation
            )

    def SendModelessOperationStart(self, operation=defaultNamedNotOptArg):
        'Notifyes the system about the start of a modeless operation.'
        return self._oleobj_.InvokeTypes(1610743835, LCID, 1, (24, 0), ((8, 0),),operation
            )

    def TranslateCoordinates(self, Point=defaultNamedNotOptArg, FromCoordSystem=defaultNamedNotOptArg, ToCoordSystem=defaultNamedNotOptArg, Displacement=defaultNamedNotOptArg
            , OCSNormal=defaultNamedOptArg):
        'Translates a point from one coordinate system to another coordinate system'
        Point = VTI2ArrayOrVal(Point)
        return self._ApplyTypes_(1610743812, 1, (12, 0), ((12, 1), (3, 1), (3, 1), (3, 1), (12, 17)), 'TranslateCoordinates', None,Point
            , FromCoordSystem, ToCoordSystem, Displacement, OCSNormal)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaAuditInfo(DispatchBaseClass):
    'IOdaAudit Interface'
    CLSID = IID('{56B202FE-BE71-43B4-B504-1902EDE89644}')
    coclass_clsid = None

    _prop_map_get_ = {
        "fixErrors": (3, 2, (11, 0), (), "fixErrors", None),
        "numErrors": (2, 2, (3, 0), (), "numErrors", None),
        "numFixes": (1, 2, (3, 0), (), "numFixes", None),
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaBagFiler(DispatchBaseClass):
    'IOdaBagFiler Interface'
    CLSID = IID('{6EBA6B5A-1D9F-4B21-BC0B-35EFDBAB543D}')
    coclass_clsid = IID('{DF962AF5-E3C8-4552-B65D-698F48DE2759}')

    def BufferToObject(self, pObj=defaultNamedNotOptArg, ResType=defaultNamedNotOptArg, ResValue=defaultNamedNotOptArg):
        'Writes result buffer to object.'
        return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((9, 1), (12, 1), (12, 1)),pObj
            , ResType, ResValue)

    def ObjectToBuffer(self, pObj=defaultNamedNotOptArg, ResType=pythoncom.Missing, ResValue=pythoncom.Missing):
        'Reads object and fills in result buffer.'
        return self._ApplyTypes_(1, 1, (24, 0), ((9, 1), (16396, 2), (16396, 2)), 'ObjectToBuffer', None,pObj
            , ResType, ResValue)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaBmpOut(DispatchBaseClass):
    'IOdaBmpOut Interface'
    CLSID = IID('{11C4F7AA-D8CC-4762-8C7C-3064E65EEDBD}')
    coclass_clsid = IID('{97B88F76-4023-412F-8C23-607C526E4E7D}')

    def WriteFile(self, database=defaultNamedNotOptArg, BitmapName=defaultNamedNotOptArg):
        'Writes Bmp file.'
        return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1), (8, 1)),database
            , BitmapName)

    _prop_map_get_ = {
        # Method 'Background' returns object of type 'IAcadAcCmColor'
        "Background": (2, 2, (9, 0), (), "Background", '{6F2B458D-6232-4085-AA60-BD5E8A967722}'),
        "BitPerPixel": (6, 2, (3, 0), (), "BitPerPixel", None),
        "Height": (4, 2, (3, 0), (), "Height", None),
        "Palette": (3, 2, (12, 0), (), "Palette", None),
        "Width": (5, 2, (3, 0), (), "Width", None),
    }
    _prop_map_put_ = {
        "Background": ((2, LCID, 4, 0),()),
        "BitPerPixel": ((6, LCID, 4, 0),()),
        "Height": ((4, LCID, 4, 0),()),
        "Palette": ((3, LCID, 4, 0),()),
        "Width": ((5, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaConsole(DispatchBaseClass):
    'IOdaConsole Interface'
    CLSID = IID('{9DFDB619-A15D-43CD-92D5-7987D452B9F1}')
    coclass_clsid = None

    def GetString(self, bAllowSpaces=defaultNamedNotOptArg):
        'Get user input string'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(2, LCID, 1, (8, 0), ((11, 1),),bAllowSpaces
            )

    def PutString(self, text=defaultNamedNotOptArg):
        'Output string'
        return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((8, 1),),text
            )

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaDwf3dExport(DispatchBaseClass):
    'IOdaDwf3dExport Interface'
    CLSID = IID('{4E99C4A8-AFC0-45E9-B312-61D7DB4F2EE6}')
    coclass_clsid = IID('{7CCF62DE-076C-4ED9-9ED2-3D4A5AC9E4DE}')

    def Export3dDwf(self, database=defaultNamedNotOptArg, FileName=defaultNamedNotOptArg):
        'Export to 3D Dwf file.'
        return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1), (8, 1)),database
            , FileName)

    _prop_map_get_ = {
        # Method 'Background' returns object of type 'IAcadAcCmColor'
        "Background": (2, 2, (9, 0), (), "Background", '{6F2B458D-6232-4085-AA60-BD5E8A967722}'),
        "Palette": (4, 2, (12, 0), (), "Palette", None),
        "Title": (3, 2, (8, 0), (), "Title", None),
        "xSize": (5, 2, (3, 0), (), "xSize", None),
        "ySize": (6, 2, (3, 0), (), "ySize", None),
    }
    _prop_map_put_ = {
        "Background": ((2, LCID, 4, 0),()),
        "Palette": ((4, LCID, 4, 0),()),
        "Title": ((3, LCID, 4, 0),()),
        "xSize": ((5, LCID, 4, 0),()),
        "ySize": ((6, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaDwfImporter(DispatchBaseClass):
    'IOdaDwfImport Interface'
    CLSID = IID('{C5631279-833D-4FE0-8965-B06E2FEC0E9C}')
    coclass_clsid = IID('{46901A1D-C99C-45E0-B2F5-D99C07CD8BBB}')

    def Import(self, database=defaultNamedNotOptArg, FileName=defaultNamedNotOptArg, Password='0', wPaper=297.0
            , hPaper=210.0):
        'Import DWF file to database'
        return self._ApplyTypes_(1, 1, (24, 32), ((9, 1), (8, 1), (8, 49), (5, 49), (5, 49)), 'Import', None,database
            , FileName, Password, wPaper, hPaper)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaDwfImporter2(DispatchBaseClass):
    'IOdaDwfImport2 Interface'
    CLSID = IID('{7E8D21F1-6343-4CCC-9F7D-0B270A05DC12}')
    coclass_clsid = None

    def Close(self):
        'Release imported database'
        return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), (),)

    def Import(self, database=defaultNamedNotOptArg, FileName=defaultNamedNotOptArg, Password='0', wPaper=297.0
            , hPaper=210.0):
        'Import DWF file to database'
        return self._ApplyTypes_(1, 1, (24, 32), ((9, 1), (8, 1), (8, 49), (5, 49), (5, 49)), 'Import', None,database
            , FileName, Password, wPaper, hPaper)

    # The method Properties is actually a property, but must be used as a method to correctly pass the arguments
    def Properties(self, Name=defaultNamedNotOptArg):
        'Importer properties'
        return self._ApplyTypes_(2, 2, (12, 0), ((8, 1),), 'Properties', None,Name
            )

    # The method SetProperties is actually a property, but must be used as a method to correctly pass the arguments
    def SetProperties(self, Name=defaultNamedNotOptArg, arg1=defaultUnnamedArg):
        'Importer properties'
        return self._oleobj_.InvokeTypes(2, LCID, 4, (24, 0), ((8, 1), (12, 1)),Name
            , arg1)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaDwfPageData(DispatchBaseClass):
    'IOdaDwfPageData Interface'
    CLSID = IID('{6C2751B5-A21F-46D8-8EBE-59F0A15288D9}')
    coclass_clsid = None

    _prop_map_get_ = {
        "Author": (2, 2, (8, 0), (), "Author", None),
        "Comments": (6, 2, (8, 0), (), "Comments", None),
        "Company": (5, 2, (8, 0), (), "Company", None),
        "Copyright": (10, 2, (8, 0), (), "Copyright", None),
        "Description": (9, 2, (8, 0), (), "Description", None),
        "Keywords": (8, 2, (8, 0), (), "Keywords", None),
        "LayoutName": (1, 2, (8, 0), (), "LayoutName", None),
        "Reviewers": (7, 2, (8, 0), (), "Reviewers", None),
        "Subject": (4, 2, (8, 0), (), "Subject", None),
        "Title": (3, 2, (8, 0), (), "Title", None),
    }
    _prop_map_put_ = {
        "Author": ((2, LCID, 4, 0),()),
        "Comments": ((6, LCID, 4, 0),()),
        "Company": ((5, LCID, 4, 0),()),
        "Copyright": ((10, LCID, 4, 0),()),
        "Description": ((9, LCID, 4, 0),()),
        "Keywords": ((8, LCID, 4, 0),()),
        "Reviewers": ((7, LCID, 4, 0),()),
        "Subject": ((4, LCID, 4, 0),()),
        "Title": ((3, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaDwfTemplate(DispatchBaseClass):
    'IOdaDwfTemplate Interface'
    CLSID = IID('{8F2A46C2-4D8A-46D5-8BBE-B06A4027BE10}')
    coclass_clsid = IID('{81186CAF-6BAC-4DD6-B470-3C7930A28DD5}')

    def AddPage(self, LayoutName=defaultNamedNotOptArg):
        'method AddPage'
        return self._oleobj_.InvokeTypes(2, LCID, 1, (3, 0), ((8, 1),),LayoutName
            )

    # Result is of type IOdaDwfPageData
    # The method Page is actually a property, but must be used as a method to correctly pass the arguments
    def Page(self, Index=defaultNamedNotOptArg):
        'property Page'
        ret = self._oleobj_.InvokeTypes(4, LCID, 2, (9, 0), ((12, 1),),Index
            )
        if ret is not None:
            ret = Dispatch(ret, 'Page', '{6C2751B5-A21F-46D8-8EBE-59F0A15288D9}')
        return ret

    def RemoveAllPages(self):
        'method RemoveAllPages'
        return self._oleobj_.InvokeTypes(6, LCID, 1, (24, 0), (),)

    def RemovePage(self, Index=defaultNamedNotOptArg):
        'method RemovePage'
        return self._oleobj_.InvokeTypes(5, LCID, 1, (24, 0), ((12, 1),),Index
            )

    def WriteFile(self, database=defaultNamedNotOptArg, FileName=defaultNamedNotOptArg, FileType=defaultNamedNotOptArg, version=defaultNamedNotOptArg):
        'Writes DWF file.'
        return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1), (8, 1), (3, 1), (3, 1)),database
            , FileName, FileType, version)

    _prop_map_get_ = {
        # Method 'Background' returns object of type 'IAcadAcCmColor'
        "Background": (11, 2, (9, 0), (), "Background", '{6F2B458D-6232-4085-AA60-BD5E8A967722}'),
        "ExportInvisibleLayers": (12, 2, (11, 0), (), "ExportInvisibleLayers", None),
        "ForceInitialViewToExtents": (13, 2, (11, 0), (), "ForceInitialViewToExtents", None),
        "PageCount": (3, 2, (3, 0), (), "PageCount", None),
        "Palette": (21, 2, (12, 0), (), "Palette", None),
        "Password": (17, 2, (8, 0), (), "Password", None),
        "Publisher": (18, 2, (8, 0), (), "Publisher", None),
        "SkipLayerInfo": (15, 2, (11, 0), (), "SkipLayerInfo", None),
        "SkipNamedViewsInfo": (16, 2, (11, 0), (), "SkipNamedViewsInfo", None),
        "SourceProductName": (20, 2, (8, 0), (), "SourceProductName", None),
        "WideComments": (19, 2, (8, 0), (), "WideComments", None),
        "xSize": (22, 2, (3, 0), (), "xSize", None),
        "ySize": (23, 2, (3, 0), (), "ySize", None),
    }
    _prop_map_put_ = {
        "Background": ((11, LCID, 4, 0),()),
        "ExportInvisibleLayers": ((12, LCID, 4, 0),()),
        "ForceInitialViewToExtents": ((13, LCID, 4, 0),()),
        "Palette": ((21, LCID, 4, 0),()),
        "Password": ((17, LCID, 4, 0),()),
        "Publisher": ((18, LCID, 4, 0),()),
        "SkipLayerInfo": ((15, LCID, 4, 0),()),
        "SkipNamedViewsInfo": ((16, LCID, 4, 0),()),
        "SourceProductName": ((20, LCID, 4, 0),()),
        "WideComments": ((19, LCID, 4, 0),()),
        "xSize": ((22, LCID, 4, 0),()),
        "ySize": ((23, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaHostApp(DispatchBaseClass):
    'IOdaHostApp Interface'
    CLSID = IID('{E789E253-BEDC-44FF-B228-AD3A17D9AB3A}')
    coclass_clsid = None

    def AuditDatabase(self, pDoc=defaultNamedNotOptArg, bFixErrors=defaultNamedNotOptArg):
        'method AuditDatabase - perform database audit'
        return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 0), (11, 0)),pDoc
            , bFixErrors)

    def BrowseForOpenFileName(self, rootFolder=defaultNamedNotOptArg, fileFilter=defaultNamedNotOptArg, bOk=defaultNamedNotOptArg, FileName=defaultNamedNotOptArg):
        'show the open file dialog with preview '
        return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((8, 0), (8, 0), (16395, 0), (16392, 0)),rootFolder
            , fileFilter, bOk, FileName)

    def OriginalFileType(self, pDoc=defaultNamedNotOptArg, FileType=defaultNamedNotOptArg):
        'method OriginalFileType - return the original file version and type'
        return self._oleobj_.InvokeTypes(5, LCID, 1, (24, 0), ((9, 0), (16396, 0)),pDoc
            , FileType)

    # Result is of type IAcadDocument
    def Recover(self, FileName=defaultNamedNotOptArg, Password=defaultNamedOptArg):
        'Recover specified file'
        ret = self._oleobj_.InvokeTypes(6, LCID, 1, (9, 0), ((8, 1), (12, 17)),FileName
            , Password)
        if ret is not None:
            ret = Dispatch(ret, 'Recover', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        # Method 'AuditInfo' returns object of type 'IOdaAuditInfo'
        "AuditInfo": (4, 2, (9, 0), (), "AuditInfo", '{56B202FE-BE71-43B4-B504-1902EDE89644}'),
        "OpenDbPartially": (7, 2, (11, 0), (), "OpenDbPartially", None),
    }
    _prop_map_put_ = {
        "OpenDbPartially": ((7, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaHostApp2(DispatchBaseClass):
    'IOdaHostApp2 Interface'
    CLSID = IID('{CFE29DD1-2A1B-49F9-853E-11918A789C6D}')
    coclass_clsid = IID('{D81CF9E5-4C85-435B-876B-C706E2D5F00E}')

    def AuditDatabase(self, pDoc=defaultNamedNotOptArg, bFixErrors=defaultNamedNotOptArg):
        'method AuditDatabase - perform database audit'
        return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 0), (11, 0)),pDoc
            , bFixErrors)

    def BrowseForOpenFileName(self, rootFolder=defaultNamedNotOptArg, fileFilter=defaultNamedNotOptArg, bOk=defaultNamedNotOptArg, FileName=defaultNamedNotOptArg):
        'show the open file dialog with preview '
        return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((8, 0), (8, 0), (16395, 0), (16392, 0)),rootFolder
            , fileFilter, bOk, FileName)

    def OriginalFileType(self, pDoc=defaultNamedNotOptArg, FileType=defaultNamedNotOptArg):
        'method OriginalFileType - return the original file version and type'
        return self._oleobj_.InvokeTypes(5, LCID, 1, (24, 0), ((9, 0), (16396, 0)),pDoc
            , FileType)

    # Result is of type IAcadDocument
    def Recover(self, FileName=defaultNamedNotOptArg, Password=defaultNamedOptArg):
        'Recover specified file'
        ret = self._oleobj_.InvokeTypes(6, LCID, 1, (9, 0), ((8, 1), (12, 17)),FileName
            , Password)
        if ret is not None:
            ret = Dispatch(ret, 'Recover', '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')
        return ret

    _prop_map_get_ = {
        # Method 'Application' returns object of type 'IAcadApplication'
        "Application": (1, 2, (9, 0), (), "Application", '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}'),
        # Method 'AuditInfo' returns object of type 'IOdaAuditInfo'
        "AuditInfo": (4, 2, (9, 0), (), "AuditInfo", '{56B202FE-BE71-43B4-B504-1902EDE89644}'),
        # Method 'Console' returns object of type 'IOdaConsole'
        "Console": (8, 2, (9, 0), (), "Console", '{9DFDB619-A15D-43CD-92D5-7987D452B9F1}'),
        "OpenDbPartially": (7, 2, (11, 0), (), "OpenDbPartially", None),
    }
    _prop_map_put_ = {
        "Console": ((8, LCID, 4, 0),()),
        "OpenDbPartially": ((7, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class IOdaSvgExporter(DispatchBaseClass):
    'IOdaSvgExporter Interface'
    CLSID = IID('{FDAF1115-5A20-4D16-A509-01012B71E4F7}')
    coclass_clsid = IID('{C0F35882-6A8B-426C-8787-001E1073197A}')

    def Export(self, database=defaultNamedNotOptArg, FilePath=defaultNamedNotOptArg):
        'method Export'
        return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 1), (8, 1)),database
            , FilePath)

    # The method Properties is actually a property, but must be used as a method to correctly pass the arguments
    def Properties(self, Name=defaultNamedNotOptArg):
        'Exporter properties'
        return self._ApplyTypes_(2, 2, (12, 0), ((8, 1),), 'Properties', None,Name
            )

    # The method SetProperties is actually a property, but must be used as a method to correctly pass the arguments
    def SetProperties(self, Name=defaultNamedNotOptArg, arg1=defaultUnnamedArg):
        'Exporter properties'
        return self._oleobj_.InvokeTypes(2, LCID, 4, (24, 0), ((8, 1), (12, 1)),Name
            , arg1)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class ITransmittalFile(DispatchBaseClass):
    'ITransmittalFile Interface'
    CLSID = IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')
    coclass_clsid = IID('{D944169D-A83B-4A9E-B543-5C66F52E3D35}')

    # Result is of type ITransmittalFile
    def getDependee(self, nIndex=defaultNamedNotOptArg):
        'Returns files that have a direct dependency on this file.'
        ret = self._oleobj_.InvokeTypes(13, LCID, 1, (9, 0), ((3, 1),),nIndex
            )
        if ret is not None:
            ret = Dispatch(ret, 'getDependee', '{0A107B59-34CE-4F40-9AF2-26060A3C2099}')
        return ret

    # Result is of type ITransmittalFile
    def getDependent(self, nIndex=defaultNamedNotOptArg):
        'Returns files on which this file has a direct dependency.'
        ret = self._oleobj_.InvokeTypes(12, LCID, 1, (9, 0), ((3, 1),),nIndex
            )
        if ret is not None:
            ret = Dispatch(ret, 'getDependent', '{0A107B59-34CE-4F40-9AF2-26060A3C2099}')
        return ret

    _prop_map_get_ = {
        "FileType": (7, 2, (3, 0), (), "FileType", None),
        "database": (11, 2, (9, 0), (), "database", None),
        "fileExists": (2, 2, (3, 0), (), "fileExists", None),
        "fileSize": (4, 2, (3, 0), (), "fileSize", None),
        "includeInTransmittal": (8, 2, (3, 0), (), "includeInTransmittal", None),
        "lastModifiedTime": (5, 2, (7, 0), (), "lastModifiedTime", None),
        "numberOfDependees": (10, 2, (3, 0), (), "numberOfDependees", None),
        "numberOfDependents": (9, 2, (3, 0), (), "numberOfDependents", None),
        "sourcePath": (1, 2, (8, 0), (), "sourcePath", None),
        "version": (3, 2, (8, 0), (), "version", None),
    }
    _prop_map_put_ = {
        "includeInTransmittal": ((8, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class ITransmittalFilesGraph(DispatchBaseClass):
    'ITransmittalFilesGraph Interface'
    CLSID = IID('{DE88EA7C-176A-42C7-BF1A-CFCCDEAB3EDB}')
    coclass_clsid = IID('{658E0EA9-97D8-4D44-AFF0-A0F01094750D}')

    def addEdge(self, pTransmitFileFrom=defaultNamedNotOptArg, pTransmitFileTo=defaultNamedNotOptArg):
        'Adds an edge between specified files in the graph.'
        return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((9, 1), (9, 1)),pTransmitFileFrom
            , pTransmitFileTo)

    # Result is of type ITransmittalFile
    def getAt(self, nIndex=defaultNamedNotOptArg):
        'Returns the file based on its index in the graph. \r\nThe index can be used to iterate through the entries in the graph.'
        ret = self._oleobj_.InvokeTypes(5, LCID, 1, (9, 0), ((3, 1),),nIndex
            )
        if ret is not None:
            ret = Dispatch(ret, 'getAt', '{0A107B59-34CE-4F40-9AF2-26060A3C2099}')
        return ret

    def getNumberOfFiles(self, bIncludeMissingFiles=defaultNamedNotOptArg, bIncludeUnselectedFiles=defaultNamedNotOptArg):
        'Returns the number of files in the graph.'
        return self._oleobj_.InvokeTypes(4, LCID, 1, (3, 0), ((3, 1), (3, 1)),bIncludeMissingFiles
            , bIncludeUnselectedFiles)

    # Result is of type ITransmittalFile
    def getRoot(self):
        "The root of the graph is a dummy file. It doesn't represent any file. \r\nNavigation to all files can be done from this node by using numberOfDependents property and getDependent() method."
        ret = self._oleobj_.InvokeTypes(1, LCID, 1, (9, 0), (),)
        if ret is not None:
            ret = Dispatch(ret, 'getRoot', '{0A107B59-34CE-4F40-9AF2-26060A3C2099}')
        return ret

    def removeEdge(self, pTransmitFile=defaultNamedNotOptArg, pParentFile=defaultNamedNotOptArg):
        'Removes a file relation edge from a given file to its parent.'
        return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 1), (9, 1)),pTransmitFile
            , pParentFile)

    def reset(self):
        'Removes all entries in the graph, which leaves an empty transmittal package.'
        return self._oleobj_.InvokeTypes(6, LCID, 1, (24, 0), (),)

    # The method totalBytes is actually a property, but must be used as a method to correctly pass the arguments
    def totalBytes(self, bIncludedFilesOnly=defaultNamedNotOptArg):
        'Returns the total number of bytes based on files \r\nalready in the transmittal package. This calculation does not include dependency files that are missing.'
        return self._oleobj_.InvokeTypes(7, LCID, 2, (3, 0), ((3, 1),),bIncludedFilesOnly
            )

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class ITransmittalInfo(DispatchBaseClass):
    'ITransmittalInfo Interface'
    CLSID = IID('{122D84E7-A507-414C-A517-C33B19AF6BA5}')
    coclass_clsid = IID('{AD47B265-C3D5-437C-AA75-527C7A7793C6}')

    _prop_map_get_ = {
        "defaultOverwriteValue": (4, 2, (3, 0), (), "defaultOverwriteValue", None),
        "destinationRoot": (1, 2, (8, 0), (), "destinationRoot", None),
        "imageRelativePath": (7, 2, (3, 0), (), "imageRelativePath", None),
        "includeFontFile": (10, 2, (3, 0), (), "includeFontFile", None),
        "includeImageFile": (9, 2, (3, 0), (), "includeImageFile", None),
        "includeMaterialTextureFile": (23, 2, (3, 0), (), "includeMaterialTextureFile", None),
        "includePlotFile": (11, 2, (3, 0), (), "includePlotFile", None),
        "includeXrefDwg": (8, 2, (3, 0), (), "includeXrefDwg", None),
        "organizedFolder": (16, 2, (3, 0), (), "organizedFolder", None),
        "preserveSubdirs": (3, 2, (3, 0), (), "preserveSubdirs", None),
        "relativePath": (15, 2, (8, 0), (), "relativePath", None),
        "saveVersion": (2, 2, (3, 0), (), "saveVersion", None),
        "xrefRelativePath": (6, 2, (3, 0), (), "xrefRelativePath", None),
    }
    _prop_map_put_ = {
        "defaultOverwriteValue": ((4, LCID, 4, 0),()),
        "destinationRoot": ((1, LCID, 4, 0),()),
        "imageRelativePath": ((7, LCID, 4, 0),()),
        "includeFontFile": ((10, LCID, 4, 0),()),
        "includeImageFile": ((9, LCID, 4, 0),()),
        "includeMaterialTextureFile": ((23, LCID, 4, 0),()),
        "includePlotFile": ((11, LCID, 4, 0),()),
        "includeXrefDwg": ((8, LCID, 4, 0),()),
        "organizedFolder": ((16, LCID, 4, 0),()),
        "preserveSubdirs": ((3, LCID, 4, 0),()),
        "relativePath": ((15, LCID, 4, 0),()),
        "saveVersion": ((2, LCID, 4, 0),()),
        "xrefRelativePath": ((6, LCID, 4, 0),()),
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class ITransmittalOperation(DispatchBaseClass):
    'ITransmittalOperation Interface'
    CLSID = IID('{7EFB484A-0280-4ED6-A73F-6DBE663DB79D}')
    coclass_clsid = IID('{9A61E0FC-4311-457B-8C65-2AD3531DC5DD}')

    def addDrawingFile(self, fullpathname=defaultNamedNotOptArg, ppIAddedFile=pythoncom.Missing):
        'Adds a drawing file to transmittal package and resolves any dependencies based on transmittal options.'
        return self._ApplyTypes_(3, 1, (3, 0), ((8, 1), (16393, 2)), 'addDrawingFile', None,fullpathname
            , ppIAddedFile)

    def addFile(self, bstrFullPath=defaultNamedNotOptArg, pIParentFile=defaultNamedNotOptArg, bAddedBy3rdParty=defaultNamedNotOptArg, ppIAddedFile=pythoncom.Missing):
        'Adds a file to transmittal package. \r\nFiles added through this method are usually third party custom files or user added files. \r\nIf a drawing file is added through this method, its dependencies are not resolved. '
        return self._ApplyTypes_(1, 1, (3, 0), ((8, 1), (9, 1), (3, 1), (16393, 2)), 'addFile', None,bstrFullPath
            , pIParentFile, bAddedBy3rdParty, ppIAddedFile)

    def addToReport(self, bstrTextToAdd=defaultNamedNotOptArg, nIndex=defaultNamedNotOptArg):
        'Adds a section to the transmittal report. \r\nThe section will be appended at the end of the report. If nIndex = -1 then text will be append at the end of report.'
        return self._oleobj_.InvokeTypes(2, LCID, 1, (3, 0), ((8, 1), (3, 1)),bstrTextToAdd
            , nIndex)

    def createTransmittalPackage(self):
        'Creates a transmittal package at specified root directory \r\nbased on given files already added and the transmittal options. The final outcome of this \r\noperation is a directory that contains all files in transmittal package based on options given.'
        return self._oleobj_.InvokeTypes(4, LCID, 1, (24, 0), (),)

    # Result is of type ITransmittalFilesGraph
    def getTransmittalGraphInterface(self):
        'Returns the ITransmittalFilesGraph interface related to current transmittal operation.'
        ret = self._oleobj_.InvokeTypes(7, LCID, 1, (9, 0), (),)
        if ret is not None:
            ret = Dispatch(ret, 'getTransmittalGraphInterface', '{DE88EA7C-176A-42C7-BF1A-CFCCDEAB3EDB}')
        return ret

    # Result is of type ITransmittalInfo
    def getTransmittalInfoInterface(self):
        'Returns the ITransmittalInfo interface related to current transmittal operation.'
        ret = self._oleobj_.InvokeTypes(6, LCID, 1, (9, 0), (),)
        if ret is not None:
            ret = Dispatch(ret, 'getTransmittalInfoInterface', '{122D84E7-A507-414C-A517-C33B19AF6BA5}')
        return ret

    def getTransmittalReport(self):
        'Returns the transmittal report based on files in already in the transmittal package.'
        # Result is a Unicode object
        return self._oleobj_.InvokeTypes(5, LCID, 1, (8, 0), (),)

    _prop_map_get_ = {
    }
    _prop_map_put_ = {
    }
    def __iter__(self):
        "Return a Python iterator for this object"
        try:
            ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
        except pythoncom.error:
            raise TypeError("This object does not support enumeration")
        return win32com.client.util.Iterator(ob, None)

class _DAcadApplicationEvents:
    'Event interface for AcadApplication'
    CLSID = CLSID_Sink = IID('{93E291E9-BB72-429B-B4DE-DF76B88603EB}')
    coclass_clsid = IID('{0E86524E-1812-426A-9A63-2C2B51B0D0E4}')
    _public_methods_ = [] # For COM Server support
    _dispid_to_func_ = {
                1 : "OnSysVarChanged",
                2 : "OnNewDrawing",
                3 : "OnAppActivate",
                4 : "OnAppDeactivate",
                5 : "OnWindowMovedOrResized",
                6 : "OnBeginModal",
                7 : "OnEndModal",
                8 : "OnBeginQuit",
               10 : "OnBeginFileDrop",
               11 : "OnARXLoaded",
               12 : "OnARXUnloaded",
               13 : "OnBeginPlot",
               14 : "OnEndPlot",
               19 : "OnBeginSave",
               20 : "OnEndSave",
               21 : "OnBeginOpen",
               22 : "OnEndOpen",
               17 : "OnBeginCommand",
               18 : "OnEndCommand",
               15 : "OnBeginLisp",
               16 : "OnEndLisp",
               24 : "OnLispCancelled",
               25 : "OnWindowChanged",
        }

    def __init__(self, oobj = None):
        if oobj is None:
            self._olecp = None
        else:
            import win32com.server.util
            from win32com.server.policy import EventHandlerPolicy
            cpc=oobj._oleobj_.QueryInterface(pythoncom.IID_IConnectionPointContainer)
            cp=cpc.FindConnectionPoint(self.CLSID_Sink)
            cookie=cp.Advise(win32com.server.util.wrap(self, usePolicy=EventHandlerPolicy))
            self._olecp,self._olecp_cookie = cp,cookie
    def __del__(self):
        try:
            self.close()
        except pythoncom.com_error:
            pass
    def close(self):
        if self._olecp is not None:
            cp,cookie,self._olecp,self._olecp_cookie = self._olecp,self._olecp_cookie,None,None
            cp.Unadvise(cookie)
    def _query_interface_(self, iid):
        import win32com.server.util
        if iid==self.CLSID_Sink: return win32com.server.util.wrap(self)

    # Event Handlers
    # If you create handlers, they should have the following prototypes:
#	def OnSysVarChanged(self, SysvarName=defaultNamedNotOptArg, newVal=defaultNamedNotOptArg):
#		'Triggered when the value of a system variable is changed'
#	def OnNewDrawing(self):
#		'Triggered just before a new drawing is created'
#	def OnAppActivate(self):
#		'Triggered just before the main application window is activated'
#	def OnAppDeactivate(self):
#		'Triggered just before the main application window is deactivated'
#	def OnWindowMovedOrResized(self, HWNDFrame=defaultNamedNotOptArg, bMoved=defaultNamedNotOptArg):
#		'Happens when the main frame window is moved or resized'
#	def OnBeginModal(self):
#		'Triggered just before a modal dialog is displayed'
#	def OnEndModal(self):
#		'Triggered just after a modal dialog is dismissed'
#	def OnBeginQuit(self, Cancel=defaultNamedNotOptArg):
#		'Triggered just before an BricsCAD session ends or a document closes'
#	def OnBeginFileDrop(self, FileName=defaultNamedNotOptArg, Cancel=defaultNamedNotOptArg):
#		'Triggered when a file is dropped on the main application window'
#	def OnARXLoaded(self, AppName=defaultNamedNotOptArg):
#		'Triggered when an BricsCAD application has been loaded'
#	def OnARXUnloaded(self, AppName=defaultNamedNotOptArg):
#		'Triggered when an BricsCAD application has been unloaded'
#	def OnBeginPlot(self, DrawingName=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to print a drawing'
#	def OnEndPlot(self, DrawingName=defaultNamedNotOptArg):
#		'Triggered after a document has been sent to the printer'
#	def OnBeginSave(self, FileName=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to save the drawing'
#	def OnEndSave(self, FileName=defaultNamedNotOptArg):
#		'Triggered when BricsCAD has finished saving the drawing'
#	def OnBeginOpen(self, FileName=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to open an existing drawing'
#	def OnEndOpen(self, FileName=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD finishes opening an existing drawing'
#	def OnBeginCommand(self, CommandName=defaultNamedNotOptArg):
#		'Triggered immediately after a command is issued, but before it completes'
#	def OnEndCommand(self, CommandName=defaultNamedNotOptArg):
#		'Triggered immediately after a command completes'
#	def OnBeginLisp(self, FirstLine=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to evaluate a LISP expression'
#	def OnEndLisp(self):
#		'Triggered upon completion of evaluating a LISP expression'
#	def OnLispCancelled(self):
#		'Triggered when the evaluation of a LISP expression is cancelled'
#	def OnWindowChanged(self, WindowState=defaultNamedNotOptArg):
#		'Triggered when there is a change to the application or document windows'


class _DAcadDocumentEvents:
    'Event interface for ThisDrawing'
    CLSID = CLSID_Sink = IID('{63A90E32-CB8B-4A3B-ADFF-EF94A35278B2}')
    coclass_clsid = IID('{3975E80C-5EC5-4EE0-B432-E9EC7BBB9A5A}')
    _public_methods_ = [] # For COM Server support
    _dispid_to_func_ = {
                1 : "OnBeginSave",
                2 : "OnEndSave",
                6 : "OnBeginCommand",
                7 : "OnEndCommand",
                8 : "OnBeginLisp",
                9 : "OnEndLisp",
               10 : "OnLispCancelled",
               11 : "OnSelectionChanged",
               12 : "OnActivate",
               13 : "OnDeactivate",
               14 : "OnBeginRightClick",
               15 : "OnBeginShortcutMenuDefault",
               16 : "OnBeginShortcutMenuEdit",
               17 : "OnBeginShortcutMenuCommand",
               18 : "OnBeginShortcutMenuGrip",
               19 : "OnBeginShortcutMenuOsnap",
               30 : "OnEndShortcutMenu",
               20 : "OnBeginDoubleClick",
               21 : "OnObjectAdded",
               22 : "OnObjectErased",
               23 : "OnObjectModified",
               24 : "OnBeginPlot",
               25 : "OnEndPlot",
               29 : "OnWindowMovedOrResized",
               31 : "OnLayoutSwitched",
               32 : "OnWindowChanged",
               33 : "OnBeginClose",
               34 : "OnBeginDocClose",
        }

    def __init__(self, oobj = None):
        if oobj is None:
            self._olecp = None
        else:
            import win32com.server.util
            from win32com.server.policy import EventHandlerPolicy
            cpc=oobj._oleobj_.QueryInterface(pythoncom.IID_IConnectionPointContainer)
            cp=cpc.FindConnectionPoint(self.CLSID_Sink)
            cookie=cp.Advise(win32com.server.util.wrap(self, usePolicy=EventHandlerPolicy))
            self._olecp,self._olecp_cookie = cp,cookie
    def __del__(self):
        try:
            self.close()
        except pythoncom.com_error:
            pass
    def close(self):
        if self._olecp is not None:
            cp,cookie,self._olecp,self._olecp_cookie = self._olecp,self._olecp_cookie,None,None
            cp.Unadvise(cookie)
    def _query_interface_(self, iid):
        import win32com.server.util
        if iid==self.CLSID_Sink: return win32com.server.util.wrap(self)

    # Event Handlers
    # If you create handlers, they should have the following prototypes:
#	def OnBeginSave(self, FileName=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to save the drawing'
#	def OnEndSave(self, FileName=defaultNamedNotOptArg):
#		'Triggered when BricsCAD has finished saving the drawing'
#	def OnBeginCommand(self, CommandName=defaultNamedNotOptArg):
#		'Triggered immediately after a command is issued, but before it completes'
#	def OnEndCommand(self, CommandName=defaultNamedNotOptArg):
#		'Triggered immediately after a command completes'
#	def OnBeginLisp(self, FirstLine=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to evaluate a LISP expression'
#	def OnEndLisp(self):
#		'Triggered upon completion of evaluating a LISP expression'
#	def OnLispCancelled(self):
#		'Triggered when the evaluation of a LISP expression is cancelled'
#	def OnSelectionChanged(self):
#		'Triggered when the current pickfirst selection set changes'
#	def OnActivate(self):
#		'Triggered when a document window is activated'
#	def OnDeactivate(self):
#		'Triggered when the drawing window is deactivated'
#	def OnBeginRightClick(self, PickPoint=defaultNamedNotOptArg):
#		'Triggered after the user right-clicks on the drawing window'
#	def OnBeginShortcutMenuDefault(self, ShortcutMenu=pythoncom.Missing):
#		'Triggered after the user right-clicks on the drawing window, and before the shortcut menu appears in default mode'
#	def OnBeginShortcutMenuEdit(self, ShortcutMenu=pythoncom.Missing, SelectionSet=pythoncom.Missing):
#		'Triggered after the user right-clicks on the drawing window, and before the shortcut menu appears in edit mode'
#	def OnBeginShortcutMenuCommand(self, ShortcutMenu=pythoncom.Missing, Command=defaultNamedNotOptArg):
#		'Triggered after the user right-clicks on the drawing window, and before the shortcut menu appears in command mode'
#	def OnBeginShortcutMenuGrip(self, ShortcutMenu=pythoncom.Missing):
#		'Triggered after the user right-clicks on the drawing window, and before the shortcut menu appears in grip mode'
#	def OnBeginShortcutMenuOsnap(self, ShortcutMenu=pythoncom.Missing):
#		'Triggered after the user right-clicks on the drawing window, and before the shortcut menu appears in osnap mode'
#	def OnEndShortcutMenu(self, ShortcutMenu=pythoncom.Missing):
#		'Triggered after the shortcut menu appears'
#	def OnBeginDoubleClick(self, PickPoint=defaultNamedNotOptArg):
#		'Triggered after the user double-clicks on an object in the drawing'
#	def OnObjectAdded(self, Object=defaultNamedNotOptArg):
#		'Triggered when an object has been added to the drawing'
#	def OnObjectErased(self, ObjectID=defaultNamedNotOptArg):
#		'Triggered when an object has been erased from the drawing'
#	def OnObjectModified(self, Object=defaultNamedNotOptArg):
#		'Triggered when an object in the drawing has been modified'
#	def OnBeginPlot(self, DrawingName=defaultNamedNotOptArg):
#		'Triggered immediately after BricsCAD receives a request to print a drawing'
#	def OnEndPlot(self, DrawingName=defaultNamedNotOptArg):
#		'Triggered after a document has been sent to the printer'
#	def OnWindowMovedOrResized(self, HWNDFrame=defaultNamedNotOptArg, bMoved=defaultNamedNotOptArg):
#		'Happens when the drawing window is moved or resized.'
#	def OnLayoutSwitched(self, LayoutName=defaultNamedNotOptArg):
#		'Triggered after the user switches to a different layout'
#	def OnWindowChanged(self, WindowState=defaultNamedNotOptArg):
#		'Triggered when there is a change to the application or document windows'
#	def OnBeginClose(self):
#		'Triggered immediately after BricsCAD receives a request to close a drawing'
#	def OnBeginDocClose(self, Cancel=defaultNamedNotOptArg):
#		'Triggered before the BeginClose event. This is an opportunity to cancel the closing process'


class _IOdaHostAppEvents:
    '_IOdaHostAppEvents Interface'
    CLSID = CLSID_Sink = IID('{5FA75E80-D112-4186-AD8E-0992D7F13475}')
    coclass_clsid = IID('{D81CF9E5-4C85-435B-876B-C706E2D5F00E}')
    _public_methods_ = [] # For COM Server support
    _dispid_to_func_ = {
               32 : "OnStep",
               33 : "OnStart",
               34 : "OnStop",
               35 : "OnSetLimit",
               36 : "OnAuditError",
               37 : "OnAuditMessage",
               38 : "OnAuditErrorEx",
               39 : "OnGetPassword",
        }

    def __init__(self, oobj = None):
        if oobj is None:
            self._olecp = None
        else:
            import win32com.server.util
            from win32com.server.policy import EventHandlerPolicy
            cpc=oobj._oleobj_.QueryInterface(pythoncom.IID_IConnectionPointContainer)
            cp=cpc.FindConnectionPoint(self.CLSID_Sink)
            cookie=cp.Advise(win32com.server.util.wrap(self, usePolicy=EventHandlerPolicy))
            self._olecp,self._olecp_cookie = cp,cookie
    def __del__(self):
        try:
            self.close()
        except pythoncom.com_error:
            pass
    def close(self):
        if self._olecp is not None:
            cp,cookie,self._olecp,self._olecp_cookie = self._olecp,self._olecp_cookie,None,None
            cp.Unadvise(cookie)
    def _query_interface_(self, iid):
        import win32com.server.util
        if iid==self.CLSID_Sink: return win32com.server.util.wrap(self)

    # Event Handlers
    # If you create handlers, they should have the following prototypes:
#	def OnStep(self):
#		'method progress Step'
#	def OnStart(self, DisplayString=defaultNamedNotOptArg):
#		'method Start new progress meter'
#	def OnStop(self):
#		'method progress Stop'
#	def OnSetLimit(self, nMax=defaultNamedNotOptArg):
#		'method set progress limit'
#	def OnAuditError(self, DisplayString=defaultNamedNotOptArg):
#		'method audit error notification'
#	def OnAuditMessage(self, DisplayString=defaultNamedNotOptArg):
#		'method audit information'
#	def OnAuditErrorEx(self, Name=defaultNamedNotOptArg, Value=defaultNamedNotOptArg, Validation=defaultNamedNotOptArg, DefaultValue=defaultNamedNotOptArg):
#		'method audit error notification extention'
#	def OnGetPassword(self, FileName=defaultNamedNotOptArg, Value=pythoncom.Missing):
#		'ask user to supply password for file'


from win32com.client import CoClassBaseClass
# This CoClass is known by the name 'BricscadApp.AcPePick2PointsCtrl.24.0'
class AcPePick2PointsCtrl(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{4735C83D-5F58-4963-8571-A4424C619D7F}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcPePropertyEditorColor.24.0'
class AcPePropertyEditorColor(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{61F2A9AB-8A44-4C20-953A-735508C1CA85}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcPePropertyEditorEllipses.24.0'
class AcPePropertyEditorEllipses(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{7507B465-281A-465C-A724-A72D09327153}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcPePropertyEditorLType.24.0'
class AcPePropertyEditorLType(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{8C9F3B98-30E9-45CE-9F07-63955326E8D4}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcPePropertyEditorLWeight.24.0'
class AcPePropertyEditorLWeight(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{4F19983F-AB24-4FB9-ADC0-0B6026080239}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcPePropertyEditorLayer.24.0'
class AcPePropertyEditorLayer(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{96F57653-F913-4CAB-B511-2F14AF9138D3}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcPePropertyEditorTextStyle.24.0'
class AcPePropertyEditorTextStyle(CoClassBaseClass): # A CoClass
    #  
    CLSID = IID('{4B61C84D-A730-4760-A409-4023DD1D8E57}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadApplication,
    ]

# This CoClass is known by the name 'BricscadApp.AcadApplication.24.0'
class AcadApplication(CoClassBaseClass): # A CoClass
    # AcadApplication Class
    CLSID = IID('{0E86524E-1812-426A-9A63-2C2B51B0D0E4}')
    coclass_sources = [
        _DAcadApplicationEvents,
    ]
    default_source = _DAcadApplicationEvents
    coclass_interfaces = [
        IAcadApplication,
    ]
    default_interface = IAcadApplication

# This CoClass is known by the name 'BricscadApp.AcadDocument.24.0'
class AcadDocument(CoClassBaseClass): # A CoClass
    # AcadDocument Class | Bricscad24
    CLSID = IID('{3975E80C-5EC5-4EE0-B432-E9EC7BBB9A5A}')
    coclass_sources = [
        _DAcadDocumentEvents,
    ]
    default_source = _DAcadDocumentEvents
    coclass_interfaces = [
        IAcadDocument,
    ]
    default_interface = IAcadDocument

# This CoClass is known by the name 'BricscadApp.AcadDocuments.24.0'
class AcadDocuments(CoClassBaseClass): # A CoClass
    # AcadDocuments Class
    CLSID = IID('{5F5D38B7-C56C-4250-B088-2B06EEEC1EE9}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadDocuments,
    ]
    default_interface = IAcadDocuments

# This CoClass is known by the name 'BricscadApp.AcadLayerStateManager.24.0'
class AcadLayerStateManager(CoClassBaseClass): # A CoClass
    # AcadLayerStateManager Class
    CLSID = IID('{2F38A4F0-DDE8-488C-B53C-5E364C267B53}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadLayerStateManager,
    ]
    default_interface = IAcadLayerStateManager

# This CoClass is known by the name 'BricscadApp.AcadMenuBar.24.0'
class AcadMenuBar(CoClassBaseClass): # A CoClass
    # AcadMenuBar class
    CLSID = IID('{DE927728-3684-4835-8255-54350D951307}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadMenuBar,
    ]
    default_interface = IAcadMenuBar

# This CoClass is known by the name 'BricscadApp.AcadMenuGroup.24.0'
class AcadMenuGroup(CoClassBaseClass): # A CoClass
    # AcadMenuGroup class
    CLSID = IID('{A07E5142-51E0-441E-B442-1F46F53F3888}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadMenuGroup,
    ]
    default_interface = IAcadMenuGroup

# This CoClass is known by the name 'BricscadApp.AcadMenuGroups.24.0'
class AcadMenuGroups(CoClassBaseClass): # A CoClass
    # AcadMenuGroups class
    CLSID = IID('{FE3FC546-AF40-4A2E-9C5C-14B7B4B8A54D}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadMenuGroups,
    ]
    default_interface = IAcadMenuGroups

# This CoClass is known by the name 'BricscadApp.AcadPlot.24.0'
class AcadPlot(CoClassBaseClass): # A CoClass
    # AcadPlot Class
    CLSID = IID('{126D4FCB-3E3D-491B-9F0B-D6C9D362116A}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPlot,
    ]
    default_interface = IAcadPlot

# This CoClass is known by the name 'BricscadApp.AcadPopupMenu.24.0'
class AcadPopupMenu(CoClassBaseClass): # A CoClass
    # AcadPopupMenu class
    CLSID = IID('{62AB6B80-D12D-40C8-8970-9915E69E05E0}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPopupMenu,
    ]
    default_interface = IAcadPopupMenu

# This CoClass is known by the name 'BricscadApp.AcadPopupMenuItem.24.0'
class AcadPopupMenuItem(CoClassBaseClass): # A CoClass
    # AcadPopupMenuItem class
    CLSID = IID('{E24D7979-088A-435B-B939-D8E18AD4BE1D}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPopupMenuItem,
    ]
    default_interface = IAcadPopupMenuItem

# This CoClass is known by the name 'BricscadApp.AcadPopupMenus.24.0'
class AcadPopupMenus(CoClassBaseClass): # A CoClass
    # AcadPopupMenus class
    CLSID = IID('{18B24243-321E-4980-9351-57C02F246EC9}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPopupMenus,
    ]
    default_interface = IAcadPopupMenus

# This CoClass is known by the name 'BricscadApp.AcadPreferences.24.0'
class AcadPreferences(CoClassBaseClass): # A CoClass
    # AcadPreferences Class
    CLSID = IID('{A3EAF524-D893-4F6F-8D07-7F9416F7EBB9}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferences,
    ]
    default_interface = IAcadPreferences

# This CoClass is known by the name 'BricscadApp.AcadPreferencesDisplay.24.0'
class AcadPreferencesDisplay(CoClassBaseClass): # A CoClass
    # AcadPreferencesDisplay Class
    CLSID = IID('{100E11DA-6700-452D-B6BE-0B65FDB2E17A}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesDisplay,
    ]
    default_interface = IAcadPreferencesDisplay

# This CoClass is known by the name 'BricscadApp.AcadPreferencesDrafting.24.0'
class AcadPreferencesDrafting(CoClassBaseClass): # A CoClass
    # AcadPreferencesDrafting Class
    CLSID = IID('{F6B948E8-500C-4305-A2EA-71FA28A35530}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesDrafting,
    ]
    default_interface = IAcadPreferencesDrafting

# This CoClass is known by the name 'BricscadApp.AcadPreferencesFiles.24.0'
class AcadPreferencesFiles(CoClassBaseClass): # A CoClass
    # AcadPreferencesFiles Class
    CLSID = IID('{354D8744-81E2-4BB0-AC00-2C2471F3BEBE}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesFiles,
    ]
    default_interface = IAcadPreferencesFiles

# This CoClass is known by the name 'BricscadApp.AcadPreferencesOpenSave.24.0'
class AcadPreferencesOpenSave(CoClassBaseClass): # A CoClass
    # AcadPreferencesOpenSave Class
    CLSID = IID('{E21FACEF-E6A4-4DE1-8315-7F0F07EB877E}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesOpenSave,
    ]
    default_interface = IAcadPreferencesOpenSave

# This CoClass is known by the name 'BricscadApp.AcadPreferencesOutput.24.0'
class AcadPreferencesOutput(CoClassBaseClass): # A CoClass
    # AcadPreferencesOutput Class
    CLSID = IID('{46B6BEE0-DA5A-4089-AC8A-70A254F31659}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesOutput,
    ]
    default_interface = IAcadPreferencesOutput

# This CoClass is known by the name 'BricscadApp.AcadPreferencesPdfOutput.24.0'
class AcadPreferencesPdfOutput(CoClassBaseClass): # A CoClass
    # AcadPreferencesPdfOutput Class
    CLSID = IID('{CB5F57D2-535C-4550-BDAC-FBFDB8778294}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesPdfOutput,
    ]
    default_interface = IAcadPreferencesPdfOutput

# This CoClass is known by the name 'BricscadApp.AcadPreferencesProfiles.24.0'
class AcadPreferencesProfiles(CoClassBaseClass): # A CoClass
    # AcadPreferencesProfiles Class
    CLSID = IID('{71AE8036-20F2-4439-BF71-F27400E3291D}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesProfiles,
    ]
    default_interface = IAcadPreferencesProfiles

# This CoClass is known by the name 'BricscadApp.AcadPreferencesSelection.24.0'
class AcadPreferencesSelection(CoClassBaseClass): # A CoClass
    # AcadPreferencesSelection Class
    CLSID = IID('{469FB7EC-09CF-4D1D-BAC8-4553F5098ADD}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesSelection,
    ]
    default_interface = IAcadPreferencesSelection

# This CoClass is known by the name 'BricscadApp.AcadPreferencesSystem.24.0'
class AcadPreferencesSystem(CoClassBaseClass): # A CoClass
    # AcadPreferencesSystem Class
    CLSID = IID('{8A48E79C-D378-4111-82D9-A25F84F5B6DC}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesSystem,
    ]
    default_interface = IAcadPreferencesSystem

# This CoClass is known by the name 'BricscadApp.AcadPreferencesUser.24.0'
class AcadPreferencesUser(CoClassBaseClass): # A CoClass
    # AcadPreferencesUser Class
    CLSID = IID('{DD509194-682F-49FE-9984-C7F0EE819A45}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadPreferencesUser,
    ]
    default_interface = IAcadPreferencesUser

# This CoClass is known by the name 'BricscadApp.AcadSecurityParams.24.0'
class AcadSecurityParams(CoClassBaseClass): # A CoClass
    # AcadSecurityParams Class
    CLSID = IID('{06F4FD5D-DBD9-4B44-B464-6683CC541EDD}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadSecurityParams,
    ]
    default_interface = IAcadSecurityParams

# This CoClass is known by the name 'BricscadApp.AcadSelectionSet.24.0'
class AcadSelectionSet(CoClassBaseClass): # A CoClass
    # AcadSelectionSet Class
    CLSID = IID('{F3862E27-3753-44F7-BDB0-24468C8E8CF6}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadSelectionSet,
    ]
    default_interface = IAcadSelectionSet

# This CoClass is known by the name 'BricscadApp.AcadSelectionSets.24.0'
class AcadSelectionSets(CoClassBaseClass): # A CoClass
    # AcadSelectionSets Class
    CLSID = IID('{2F021E6D-67B2-4955-9135-A28F93BCEE6D}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadSelectionSets,
    ]
    default_interface = IAcadSelectionSets

# This CoClass is known by the name 'BricscadApp.AcadState.24.0'
class AcadState(CoClassBaseClass): # A CoClass
    # AcadState Class
    CLSID = IID('{5696C1B9-643B-4E6E-B711-DB897137424E}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadState,
    ]
    default_interface = IAcadState

# This CoClass is known by the name 'BricscadApp.AcadToolbar.24.0'
class AcadToolbar(CoClassBaseClass): # A CoClass
    # An AutoCAD toolbar
    CLSID = IID('{A8D0AE76-640B-44AA-BB5C-6986706CA9F6}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadToolbar,
    ]
    default_interface = IAcadToolbar

# This CoClass is known by the name 'BricscadApp.AcadToolbarItem.24.0'
class AcadToolbarItem(CoClassBaseClass): # A CoClass
    # AcadToolbarItem class
    CLSID = IID('{C9F46D28-7AEE-48F1-B8B7-6F8E7EC40625}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadToolbarItem,
    ]
    default_interface = IAcadToolbarItem

# This CoClass is known by the name 'BricscadApp.AcadToolbars.24.0'
class AcadToolbars(CoClassBaseClass): # A CoClass
    # AcadToolbars class
    CLSID = IID('{6625C943-4F9E-4FCD-B847-454FCDC56C19}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadToolbars,
    ]
    default_interface = IAcadToolbars

# This CoClass is known by the name 'BricscadApp.AcadUtility.24.0'
class AcadUtility(CoClassBaseClass): # A CoClass
    # AcadUtility Class
    CLSID = IID('{AB480185-F159-4B5D-BC9E-AEA9AB722DF1}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IAcadUtility,
    ]
    default_interface = IAcadUtility

# This CoClass is known by the name 'BricscadApp.OdaBagFiler.24.0'
class OdaBagFiler(CoClassBaseClass): # A CoClass
    # OdaBagFiler Class
    CLSID = IID('{DF962AF5-E3C8-4552-B65D-698F48DE2759}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IOdaBagFiler,
    ]
    default_interface = IOdaBagFiler

# This CoClass is known by the name 'BricscadApp.OdaBmpOut.24.0'
class OdaBmpOut(CoClassBaseClass): # A CoClass
    # OdaBmpOut Class
    CLSID = IID('{97B88F76-4023-412F-8C23-607C526E4E7D}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IOdaBmpOut,
    ]
    default_interface = IOdaBmpOut

# This CoClass is known by the name 'BricscadApp.OdaDwf3dExport.24.0'
class OdaDwf3dExport(CoClassBaseClass): # A CoClass
    # OdaDwf3dExport Class
    CLSID = IID('{7CCF62DE-076C-4ED9-9ED2-3D4A5AC9E4DE}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IOdaDwf3dExport,
    ]
    default_interface = IOdaDwf3dExport

# This CoClass is known by the name 'BricscadApp.OdaDwfImporter.24.0'
class OdaDwfImporter(CoClassBaseClass): # A CoClass
    # OdaDwfImporter Class
    CLSID = IID('{46901A1D-C99C-45E0-B2F5-D99C07CD8BBB}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IOdaDwfImporter,
    ]
    default_interface = IOdaDwfImporter

# This CoClass is known by the name 'BricscadApp.OdaDwfTemplate.24.0'
class OdaDwfTemplate(CoClassBaseClass): # A CoClass
    # OdaDwfTemplate Class
    CLSID = IID('{81186CAF-6BAC-4DD6-B470-3C7930A28DD5}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IOdaDwfTemplate,
    ]
    default_interface = IOdaDwfTemplate

# This CoClass is known by the name 'BricscadApp.OdaHostApp.24.0'
class OdaHostApp(CoClassBaseClass): # A CoClass
    # OdaHostApp Class
    CLSID = IID('{D81CF9E5-4C85-435B-876B-C706E2D5F00E}')
    coclass_sources = [
        _IOdaHostAppEvents,
    ]
    default_source = _IOdaHostAppEvents
    coclass_interfaces = [
        IOdaHostApp2,
    ]
    default_interface = IOdaHostApp2

# This CoClass is known by the name 'BricscadApp.OdaSvgExporter.24.0'
class OdaSvgExporter(CoClassBaseClass): # A CoClass
    # SvgExporter Class
    CLSID = IID('{C0F35882-6A8B-426C-8787-001E1073197A}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        IOdaSvgExporter,
    ]
    default_interface = IOdaSvgExporter

# This CoClass is known by the name 'BricscadApp.TransmittalFile.24.0'
class TransmittalFile(CoClassBaseClass): # A CoClass
    # TransmittalFile Class
    CLSID = IID('{D944169D-A83B-4A9E-B543-5C66F52E3D35}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        ITransmittalFile,
    ]
    default_interface = ITransmittalFile

# This CoClass is known by the name 'BricscadApp.TransmittalFilesGraph.24.0'
class TransmittalFilesGraph(CoClassBaseClass): # A CoClass
    # TransmittalFilesGraph Class
    CLSID = IID('{658E0EA9-97D8-4D44-AFF0-A0F01094750D}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        ITransmittalFilesGraph,
    ]
    default_interface = ITransmittalFilesGraph

# This CoClass is known by the name 'BricscadApp.TransmittalInfo.24.0'
class TransmittalInfo(CoClassBaseClass): # A CoClass
    # TransmittalInfo Class
    CLSID = IID('{AD47B265-C3D5-437C-AA75-527C7A7793C6}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        ITransmittalInfo,
    ]
    default_interface = ITransmittalInfo

# This CoClass is known by the name 'BricscadApp.TransmittalOperation.24.0'
class TransmittalOperation(CoClassBaseClass): # A CoClass
    # TransmittalOperation Class
    CLSID = IID('{9A61E0FC-4311-457B-8C65-2AD3531DC5DD}')
    coclass_sources = [
    ]
    coclass_interfaces = [
        ITransmittalOperation,
    ]
    default_interface = ITransmittalOperation

IAcadApplication_vtables_dispatch_ = 1
IAcadApplication_vtables_ = [
    (( 'Visible' , 'Visible' , ), 1, (1, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Visible' , 'Visible' , ), 1, (1, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'pAppName' , ), 2, (2, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Caption' , 'bstrCaption' , ), 3, (3, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 4, (4, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'ActiveDocument' , 'pActiveDoc' , ), 5, (5, (), [ (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'ActiveDocument' , 'pActiveDoc' , ), 5, (5, (), [ (9, 1, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'FullName' , 'FullName' , ), 6, (6, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'Height' , ), 7, (7, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'Height' , ), 7, (7, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'WindowLeft' , 'left' , ), 8, (8, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'WindowLeft' , 'left' , ), 8, (8, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'Path' , 'bstrPath' , ), 9, (9, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'LocaleId' , 'lcid' , ), 10, (10, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'WindowTop' , 'top' , ), 11, (11, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'WindowTop' , 'top' , ), 11, (11, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'version' , 'bstrVer' , ), 12, (12, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'Width' , ), 13, (13, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'Width' , ), 13, (13, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'Preferences' , 'pPreferences' , ), 14, (14, (), [ (16393, 10, None, "IID('{03CE46C1-93A9-4E5C-B7F5-7AC7E2D48948}')") , ], 1 , 2 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'StatusId' , 'VportObj' , 'bStatus' , ), 17, (17, (), [ (9, 1, None, None) , 
             (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'ListArx' , 'pVarListArray' , ), 18, (18, (), [ (16396, 10, None, None) , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'LoadArx' , 'Name' , ), 19, (19, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'GetInterfaceObject' , 'ProgID' , 'pObj' , ), 20, (20, (), [ (8, 1, None, None) , 
             (16393, 10, None, None) , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'UnloadArx' , 'Name' , ), 23, (23, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'Update' , ), 24, (24, (), [ ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'Quit' , ), 25, (25, (), [ ], 1 , 1 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
    (( 'Zoom' , 'Type' , 'vParams' , ), 26, (26, (), [ (3, 1, None, None) , 
             (16396, 1, None, None) , ], 1 , 1 , 4 , 0 , 272 , (3, 0, None, None) , 64 , )),
    (( 'VBE' , 'pDispVBE' , ), 27, (27, (), [ (16393, 10, None, None) , ], 1 , 2 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
    (( 'MenuGroups' , 'pMenuGroups' , ), 28, (28, (), [ (16393, 10, None, "IID('{798225D3-984D-471E-84F3-D1EC56FA05EA}')") , ], 1 , 2 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
    (( 'MenuBar' , 'pMenuBar' , ), 29, (29, (), [ (16393, 10, None, "IID('{A174CCC8-D19F-421F-8F4E-65C2E4F43167}')") , ], 1 , 2 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
    (( 'LoadDVB' , 'Name' , ), 30, (30, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
    (( 'UnloadDVB' , 'Name' , ), 31, (31, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
    (( 'Documents' , 'pDocuments' , ), 32, (32, (), [ (16393, 10, None, "IID('{CFFD1390-466A-49D9-9EE0-1884E930DFF9}')") , ], 1 , 2 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
    (( 'Eval' , 'Expression' , ), 33, (33, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 328 , (3, 0, None, None) , 0 , )),
    (( 'WindowState' , 'eWinState' , ), 34, (34, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 336 , (3, 0, None, None) , 0 , )),
    (( 'WindowState' , 'eWinState' , ), 34, (34, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 344 , (3, 0, None, None) , 0 , )),
    (( 'RunMacro' , 'MacroPath' , ), 35, (35, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 352 , (3, 0, None, None) , 0 , )),
    (( 'ZoomExtents' , ), 36, (36, (), [ ], 1 , 1 , 4 , 0 , 360 , (3, 0, None, None) , 0 , )),
    (( 'ZoomAll' , ), 37, (37, (), [ ], 1 , 1 , 4 , 0 , 368 , (3, 0, None, None) , 0 , )),
    (( 'ZoomCenter' , 'Center' , 'Magnify' , ), 38, (38, (), [ (12, 1, None, None) , 
             (5, 1, None, None) , ], 1 , 1 , 4 , 0 , 376 , (3, 0, None, None) , 0 , )),
    (( 'ZoomScaled' , 'scale' , 'ScaleType' , ), 39, (39, (), [ (5, 1, None, None) , 
             (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 384 , (3, 0, None, None) , 0 , )),
    (( 'ZoomWindow' , 'LowerLeft' , 'UpperRight' , ), 40, (40, (), [ (12, 1, None, None) , 
             (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 392 , (3, 0, None, None) , 0 , )),
    (( 'ZoomPickWindow' , ), 41, (41, (), [ ], 1 , 1 , 4 , 0 , 400 , (3, 0, None, None) , 0 , )),
    (( 'GetAcadState' , 'pVal' , ), 42, (42, (), [ (16393, 10, None, "IID('{C2016470-443B-40D0-AD93-231ACFDCF594}')") , ], 1 , 1 , 4 , 0 , 408 , (3, 0, None, None) , 0 , )),
    (( 'ZoomPrevious' , ), 43, (43, (), [ ], 1 , 1 , 4 , 0 , 416 , (3, 0, None, None) , 0 , )),
    (( 'HWND' , 'HWND' , ), 44, (44, (), [ (16404, 10, None, None) , ], 1 , 2 , 4 , 0 , 424 , (3, 0, None, None) , 0 , )),
    (( 'DefineFunction' , 'FunctionName' , 'FunctionPointer' , ), 45, (45, (), [ (8, 1, None, None) , 
             (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 432 , (3, 0, None, None) , 0 , )),
    (( 'UndefineFunction' , 'FunctionName' , ), 46, (46, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 440 , (3, 0, None, None) , 0 , )),
    (( 'RunCommand' , 'Command' , ), 47, (47, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 448 , (3, 0, None, None) , 0 , )),
    (( 'RunScript' , 'Script' , ), 48, (48, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 456 , (3, 0, None, None) , 0 , )),
]

IAcadDocument_vtables_dispatch_ = 1
IAcadDocument_vtables_ = [
    (( 'Plot' , 'pPlot' , ), 23, (23, (), [ (16393, 10, None, "IID('{445545BB-394E-481A-AC4F-F073E53030E8}')") , ], 1 , 2 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
    (( 'ActiveLayer' , 'pActLayer' , ), 24, (24, (), [ (16393, 10, None, "IID('{A5484251-D4DF-4F32-A23F-445882F48F1B}')") , ], 1 , 2 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
    (( 'ActiveLayer' , 'pActLayer' , ), 24, (24, (), [ (9, 1, None, "IID('{A5484251-D4DF-4F32-A23F-445882F48F1B}')") , ], 1 , 4 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
    (( 'ActiveLinetype' , 'pActLinetype' , ), 25, (25, (), [ (16393, 10, None, "IID('{908A55EF-9ED0-4A36-BD47-AD0818AF9317}')") , ], 1 , 2 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
    (( 'ActiveLinetype' , 'pActLinetype' , ), 25, (25, (), [ (9, 1, None, "IID('{908A55EF-9ED0-4A36-BD47-AD0818AF9317}')") , ], 1 , 4 , 4 , 0 , 328 , (3, 0, None, None) , 0 , )),
    (( 'ActiveDimStyle' , 'pActDimStyle' , ), 26, (26, (), [ (16393, 10, None, "IID('{F1E716A4-FBC3-4893-A8C4-5E59A537D7CE}')") , ], 1 , 2 , 4 , 0 , 336 , (3, 0, None, None) , 0 , )),
    (( 'ActiveDimStyle' , 'pActDimStyle' , ), 26, (26, (), [ (9, 1, None, "IID('{F1E716A4-FBC3-4893-A8C4-5E59A537D7CE}')") , ], 1 , 4 , 4 , 0 , 344 , (3, 0, None, None) , 0 , )),
    (( 'ActiveTextStyle' , 'pActTextStyle' , ), 27, (27, (), [ (16393, 10, None, "IID('{EE473D68-C42F-4A9D-8393-C3975C17BC4A}')") , ], 1 , 2 , 4 , 0 , 352 , (3, 0, None, None) , 0 , )),
    (( 'ActiveTextStyle' , 'pActTextStyle' , ), 27, (27, (), [ (9, 1, None, "IID('{EE473D68-C42F-4A9D-8393-C3975C17BC4A}')") , ], 1 , 4 , 4 , 0 , 360 , (3, 0, None, None) , 0 , )),
    (( 'ActiveUCS' , 'pActUCS' , ), 28, (28, (), [ (16393, 10, None, "IID('{F5F78A02-09C6-49EB-812A-04B5ACC46F71}')") , ], 1 , 2 , 4 , 0 , 368 , (3, 0, None, None) , 0 , )),
    (( 'ActiveUCS' , 'pActUCS' , ), 28, (28, (), [ (9, 1, None, "IID('{F5F78A02-09C6-49EB-812A-04B5ACC46F71}')") , ], 1 , 4 , 4 , 0 , 376 , (3, 0, None, None) , 0 , )),
    (( 'ActiveViewport' , 'pActView' , ), 29, (29, (), [ (16393, 10, None, "IID('{A9B1F951-1AA7-4C23-8D57-AA199803D381}')") , ], 1 , 2 , 4 , 0 , 384 , (3, 0, None, None) , 0 , )),
    (( 'ActiveViewport' , 'pActView' , ), 29, (29, (), [ (9, 1, None, "IID('{A9B1F951-1AA7-4C23-8D57-AA199803D381}')") , ], 1 , 4 , 4 , 0 , 392 , (3, 0, None, None) , 0 , )),
    (( 'ActivePViewport' , 'pActView' , ), 30, (30, (), [ (16393, 10, None, "IID('{894A0DA6-C91F-458C-AC86-7FEDBF35CD30}')") , ], 1 , 2 , 4 , 0 , 400 , (3, 0, None, None) , 0 , )),
    (( 'ActivePViewport' , 'pActView' , ), 30, (30, (), [ (9, 1, None, "IID('{894A0DA6-C91F-458C-AC86-7FEDBF35CD30}')") , ], 1 , 4 , 4 , 0 , 408 , (3, 0, None, None) , 0 , )),
    (( 'ActiveSpace' , 'ActSpace' , ), 31, (31, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 416 , (3, 0, None, None) , 0 , )),
    (( 'ActiveSpace' , 'ActSpace' , ), 31, (31, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 424 , (3, 0, None, None) , 0 , )),
    (( 'SelectionSets' , 'pSelSets' , ), 32, (32, (), [ (16393, 10, None, "IID('{37E34D42-8CD8-4E25-83BF-80C791AFEADE}')") , ], 1 , 2 , 4 , 0 , 432 , (3, 0, None, None) , 0 , )),
    (( 'ActiveSelectionSet' , 'pSelSet' , ), 33, (33, (), [ (16393, 10, None, "IID('{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')") , ], 1 , 2 , 4 , 0 , 440 , (3, 0, None, None) , 0 , )),
    (( 'FullName' , 'FullName' , ), 34, (34, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 448 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'Name' , ), 35, (35, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 456 , (3, 0, None, None) , 0 , )),
    (( 'Path' , 'Path' , ), 36, (36, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 464 , (3, 0, None, None) , 0 , )),
    (( 'ObjectSnapMode' , 'fSnapMode' , ), 37, (37, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 472 , (3, 0, None, None) , 0 , )),
    (( 'ObjectSnapMode' , 'fSnapMode' , ), 37, (37, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 480 , (3, 0, None, None) , 0 , )),
    (( 'ReadOnly' , 'bReadOnly' , ), 38, (38, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 488 , (3, 0, None, None) , 0 , )),
    (( 'Saved' , 'bSaved' , ), 39, (39, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 496 , (3, 0, None, None) , 0 , )),
    (( 'MSpace' , 'Mode' , ), 40, (40, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 504 , (3, 0, None, None) , 0 , )),
    (( 'MSpace' , 'Mode' , ), 40, (40, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 512 , (3, 0, None, None) , 0 , )),
    (( 'Utility' , 'pUtil' , ), 41, (41, (), [ (16393, 10, None, "IID('{5046A00A-7C22-4D39-ADE0-FB1AE3709B4D}')") , ], 1 , 2 , 4 , 0 , 520 , (3, 0, None, None) , 0 , )),
    (( 'Open' , 'FullName' , 'Password' , 'pDocObj' , ), 42, (42, (), [ 
             (8, 1, None, None) , (12, 17, None, None) , (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 1 , 4 , 1 , 528 , (3, 0, None, None) , 0 , )),
    (( 'AuditInfo' , 'FixErr' , ), 43, (43, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 536 , (3, 0, None, None) , 0 , )),
    (( 'Import' , 'FileName' , 'InsertionPoint' , 'ScaleFactor' , 'pObj' , 
             ), 44, (44, (), [ (8, 1, None, None) , (12, 1, None, None) , (5, 1, None, None) , (16393, 10, None, None) , ], 1 , 1 , 4 , 0 , 544 , (3, 0, None, None) , 0 , )),
    (( 'Export' , 'FileName' , 'Extension' , 'SelectionSet' , ), 45, (45, (), [ 
             (8, 1, None, None) , (8, 1, None, None) , (9, 1, None, "IID('{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')") , ], 1 , 1 , 4 , 0 , 552 , (3, 0, None, None) , 0 , )),
    (( 'New' , 'TemplateFileName' , 'pDocObj' , ), 46, (46, (), [ (8, 1, None, None) , 
             (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 1 , 4 , 0 , 560 , (3, 0, None, None) , 0 , )),
    (( 'Save' , ), 47, (47, (), [ ], 1 , 1 , 4 , 0 , 568 , (3, 0, None, None) , 0 , )),
    (( 'SaveAs' , 'FullFileName' , 'SaveAsType' , 'vSecurityParams' , ), 48, (48, (), [ 
             (8, 1, None, None) , (12, 17, None, None) , (12, 17, None, None) , ], 1 , 1 , 4 , 2 , 576 , (3, 0, None, None) , 0 , )),
    (( 'Wblock' , 'FileName' , 'SelectionSet' , ), 49, (49, (), [ (8, 1, None, None) , 
             (9, 1, None, "IID('{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')") , ], 1 , 1 , 4 , 0 , 584 , (3, 0, None, None) , 0 , )),
    (( 'PurgeAll' , ), 50, (50, (), [ ], 1 , 1 , 4 , 0 , 592 , (3, 0, None, None) , 0 , )),
    (( 'GetVariable' , 'Name' , 'Value' , ), 51, (51, (), [ (8, 1, None, None) , 
             (16396, 10, None, None) , ], 1 , 1 , 4 , 0 , 600 , (3, 0, None, None) , 0 , )),
    (( 'SetVariable' , 'Name' , 'Value' , ), 52, (52, (), [ (8, 1, None, None) , 
             (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 608 , (3, 0, None, None) , 0 , )),
    (( 'LoadShapeFile' , 'FullName' , ), 53, (53, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 616 , (3, 0, None, None) , 0 , )),
    (( 'Regen' , 'WhichViewports' , ), 54, (54, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 624 , (3, 0, None, None) , 0 , )),
    (( 'PickfirstSelectionSet' , 'pSelSet' , ), 55, (55, (), [ (16393, 10, None, None) , ], 1 , 2 , 4 , 0 , 632 , (3, 0, None, None) , 0 , )),
    (( 'Active' , 'pvbActive' , ), 56, (56, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 640 , (3, 0, None, None) , 0 , )),
    (( 'Activate' , ), 57, (57, (), [ ], 1 , 1 , 4 , 0 , 648 , (3, 0, None, None) , 0 , )),
    (( 'Close' , 'SaveChanges' , 'FileName' , ), 58, (58, (), [ (12, 17, None, None) , 
             (12, 17, None, None) , ], 1 , 1 , 4 , 2 , 656 , (3, 0, None, None) , 0 , )),
    (( 'WindowState' , 'pWinState' , ), 59, (59, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 664 , (3, 0, None, None) , 0 , )),
    (( 'WindowState' , 'pWinState' , ), 59, (59, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 672 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'pWidth' , ), 60, (60, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 680 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'pWidth' , ), 60, (60, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 688 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'pHeight' , ), 61, (61, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 696 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'pHeight' , ), 61, (61, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 704 , (3, 0, None, None) , 0 , )),
    (( 'ActiveLayout' , 'pLayout' , ), 62, (62, (), [ (9, 1, None, "IID('{50D89DB1-E146-428F-92BD-87F4EB9A46B4}')") , ], 1 , 4 , 4 , 0 , 712 , (3, 0, None, None) , 0 , )),
    (( 'ActiveLayout' , 'pLayout' , ), 62, (62, (), [ (16393, 10, None, "IID('{50D89DB1-E146-428F-92BD-87F4EB9A46B4}')") , ], 1 , 2 , 4 , 0 , 720 , (3, 0, None, None) , 0 , )),
    (( 'SendCommand' , 'Command' , ), 63, (63, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 728 , (3, 0, None, None) , 0 , )),
    (( 'HWND' , 'HWND' , ), 64, (64, (), [ (16404, 10, None, None) , ], 1 , 2 , 4 , 0 , 736 , (3, 0, None, None) , 0 , )),
    (( 'WindowTitle' , 'Title' , ), 65, (65, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 744 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 66, (66, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 752 , (3, 0, None, None) , 0 , )),
    (( 'database' , 'pDatabase' , ), 67, (67, (), [ (16393, 10, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , ], 1 , 2 , 4 , 0 , 760 , (3, 0, None, None) , 0 , )),
    (( 'StartUndoMark' , ), 68, (68, (), [ ], 1 , 1 , 4 , 0 , 768 , (3, 0, None, None) , 0 , )),
    (( 'EndUndoMark' , ), 69, (69, (), [ ], 1 , 1 , 4 , 0 , 776 , (3, 0, None, None) , 0 , )),
    (( 'getTransmittalOperationInterface' , 'ppITrmOp' , ), 75, (75, (), [ (16393, 10, None, "IID('{7EFB484A-0280-4ED6-A73F-6DBE663DB79D}')") , ], 1 , 1 , 4 , 0 , 784 , (3, 0, None, None) , 0 , )),
    (( 'EvaluateLisp' , 'lispString' , 'pvResult' , ), 76, (76, (), [ (8, 1, None, None) , 
             (16396, 10, None, None) , ], 1 , 1 , 4 , 0 , 792 , (3, 0, None, None) , 0 , )),
    (( 'ActiveMaterial' , 'pActMaterial' , ), 77, (77, (), [ (16393, 10, None, "IID('{4D24EA66-A2B3-4129-8367-81D93B44BE07}')") , ], 1 , 2 , 4 , 0 , 800 , (3, 0, None, None) , 0 , )),
    (( 'ActiveMaterial' , 'pActMaterial' , ), 77, (77, (), [ (9, 1, None, "IID('{4D24EA66-A2B3-4129-8367-81D93B44BE07}')") , ], 1 , 4 , 4 , 0 , 808 , (3, 0, None, None) , 0 , )),
    (( 'NumTransactions' , 'pNumTransactions' , ), 78, (78, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 816 , (3, 0, None, None) , 0 , )),
    (( 'StartTransaction' , ), 79, (79, (), [ ], 1 , 1 , 4 , 0 , 824 , (3, 0, None, None) , 0 , )),
    (( 'EndTransaction' , ), 80, (80, (), [ ], 1 , 1 , 4 , 0 , 832 , (3, 0, None, None) , 0 , )),
    (( 'AbortTransaction' , ), 81, (81, (), [ ], 1 , 1 , 4 , 0 , 840 , (3, 0, None, None) , 0 , )),
]

IAcadDocuments_vtables_dispatch_ = 1
IAcadDocuments_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Add' , 'TemplateName' , 'pDispDoc' , ), 1610743812, (1610743812, (), [ (12, 17, None, None) , 
             (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 1 , 4 , 1 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Open' , 'Name' , 'ReadOnly' , 'Password' , 'pDispDoc' , 
             ), 1610743813, (1610743813, (), [ (8, 1, None, None) , (12, 17, None, None) , (12, 17, None, None) , (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 1 , 4 , 2 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Close' , ), 1610743814, (1610743814, (), [ ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
]

IAcadLayerStateManager_vtables_dispatch_ = 1
IAcadLayerStateManager_vtables_ = [
    (( 'SetDatabase' , 'iHostDb' , ), 1610743808, (1610743808, (), [ (9, 1, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Mask' , 'bsName' , 'eMask' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , 
             (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Mask' , 'bsName' , 'eMask' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , 
             (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Save' , 'bsName' , 'eMask' , ), 1610743811, (1610743811, (), [ (8, 1, None, None) , 
             (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Restore' , 'bsName' , ), 1610743812, (1610743812, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Delete' , 'bsName' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Rename' , 'bsName' , 'bsNewName' , ), 1610743814, (1610743814, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Import' , 'bsFilename' , ), 1610743815, (1610743815, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Export' , 'bsName' , 'bsFilename' , ), 1610743816, (1610743816, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
]

IAcadMenuBar_vtables_dispatch_ = 1
IAcadMenuBar_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743812, (1610743812, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
]

IAcadMenuGroup_vtables_dispatch_ = 1
IAcadMenuGroup_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743809, (1610743809, (), [ (16393, 10, None, "IID('{798225D3-984D-471E-84F3-D1EC56FA05EA}')") , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'Name' , ), 1610743810, (1610743810, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Type' , 'menuType' , ), 1610743811, (1610743811, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'MenuFileName' , 'Name' , ), 1610743812, (1610743812, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Menus' , 'pMenus' , ), 1610743813, (1610743813, (), [ (16393, 10, None, "IID('{3305CB53-F955-41F3-A47B-B7AA53B22D48}')") , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Toolbars' , 'pToolbars' , ), 1610743814, (1610743814, (), [ (16393, 10, None, "IID('{F7DF12AA-4EF4-4EEE-8D00-68BB80D7F092}')") , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Unload' , ), 1610743815, (1610743815, (), [ ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Save' , 'MenuFileType' , ), 1610743816, (1610743816, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'SaveAs' , 'MenuFileName' , 'MenuFileType' , ), 1610743817, (1610743817, (), [ (8, 1, None, None) , 
             (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
]

IAcadMenuGroups_vtables_dispatch_ = 1
IAcadMenuGroups_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{DF14CB14-CDC6-463F-B71C-356149D1F935}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743812, (1610743812, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Load' , 'MenuFileName' , 'BaseMenu' , 'pMenuGroup' , ), 1610743813, (1610743813, (), [ 
             (8, 1, None, None) , (12, 17, None, None) , (16393, 10, None, "IID('{DF14CB14-CDC6-463F-B71C-356149D1F935}')") , ], 1 , 1 , 4 , 1 , 96 , (3, 0, None, None) , 0 , )),
]

IAcadPlot_vtables_dispatch_ = 1
IAcadPlot_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1, (1, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'QuietErrorMode' , 'pQuietErrorMode' , ), 2, (2, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'QuietErrorMode' , 'pQuietErrorMode' , ), 2, (2, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'NumberOfCopies' , 'pNumberOfCopies' , ), 3, (3, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'NumberOfCopies' , 'pNumberOfCopies' , ), 3, (3, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'BatchPlotProgress' , 'pBatchPlotProgress' , ), 4, (4, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'BatchPlotProgress' , 'pBatchPlotProgress' , ), 4, (4, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'DisplayPlotPreview' , 'PreviewMode' , ), 5, (5, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'SetLayoutsToPlot' , 'layoutList' , ), 6, (6, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'StartBatchMode' , 'entryCount' , ), 7, (7, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'PlotToDevice' , 'plotConfig' , 'pResult' , ), 8, (8, (), [ (12, 17, None, None) , 
             (16395, 10, None, None) , ], 1 , 1 , 4 , 1 , 136 , (3, 0, None, None) , 0 , )),
    (( 'PlotToFile' , 'plotFile' , 'plotConfig' , 'pResult' , ), 9, (9, (), [ 
             (8, 1, None, None) , (12, 17, None, None) , (16395, 10, None, None) , ], 1 , 1 , 4 , 1 , 144 , (3, 0, None, None) , 0 , )),
]

IAcadPopupMenu_vtables_dispatch_ = 1
IAcadPopupMenu_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743812, (1610743812, (), [ (16393, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'bstrName' , ), 1610743813, (1610743813, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'bstrName' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'NameNoMnemonic' , 'bstrName' , ), 1610743815, (1610743815, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'ShortcutMenu' , 'bFlag' , ), 1610743816, (1610743816, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'OnMenuBar' , 'bFlag' , ), 1610743817, (1610743817, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'AddMenuItem' , 'Index' , 'Label' , 'Macro' , 'pItem' , 
             ), 1610743818, (1610743818, (), [ (12, 1, None, None) , (8, 1, None, None) , (8, 1, None, None) , (16393, 10, None, "IID('{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')") , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'AddSubMenu' , 'Index' , 'Label' , 'pMenu' , ), 1610743819, (1610743819, (), [ 
             (12, 1, None, None) , (8, 1, None, None) , (16393, 10, None, "IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')") , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'AddSeparator' , 'Index' , 'pItem' , ), 1610743820, (1610743820, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{5B5C5A15-81D2-4360-937A-4F2FA18FB266}')") , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'InsertInMenuBar' , 'Index' , ), 1610743821, (1610743821, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'RemoveFromMenuBar' , ), 1610743822, (1610743822, (), [ ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'TagString' , 'bstrTag' , ), 1610743823, (1610743823, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcadPopupMenuItem_vtables_dispatch_ = 1
IAcadPopupMenuItem_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743809, (1610743809, (), [ (16393, 10, None, "IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')") , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Label' , 'bstrLabel' , ), 1610743810, (1610743810, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Label' , 'bstrLabel' , ), 1610743810, (1610743810, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'TagString' , 'bstrTag' , ), 1610743812, (1610743812, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'TagString' , 'bstrTag' , ), 1610743812, (1610743812, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Enable' , 'bFlag' , ), 1610743814, (1610743814, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Enable' , 'bFlag' , ), 1610743814, (1610743814, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Check' , 'bFlag' , ), 1610743816, (1610743816, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Check' , 'bFlag' , ), 1610743816, (1610743816, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'Type' , 'itemType' , ), 1610743818, (1610743818, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'SubMenu' , 'pMenu' , ), 1610743819, (1610743819, (), [ (16393, 10, None, "IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')") , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'Macro' , 'bstrMacro' , ), 1610743820, (1610743820, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'Macro' , 'bstrMacro' , ), 1610743820, (1610743820, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'Index' , 'nIndex' , ), 1610743822, (1610743822, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'Caption' , 'bstrCaption' , ), 1610743823, (1610743823, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'HelpString' , 'bstrHelp' , ), 1610743824, (1610743824, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'HelpString' , 'bstrHelp' , ), 1610743824, (1610743824, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'Delete' , ), 1610743826, (1610743826, (), [ ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'EndSubMenuLevel' , 'Level' , ), 1610743827, (1610743827, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'EndSubMenuLevel' , 'Level' , ), 1610743827, (1610743827, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
]

IAcadPopupMenus_vtables_dispatch_ = 1
IAcadPopupMenus_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743812, (1610743812, (), [ (16393, 10, None, "IID('{DF14CB14-CDC6-463F-B71C-356149D1F935}')") , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Add' , 'MenuName' , 'pMenu' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , 
             (16393, 10, None, "IID('{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}')") , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'InsertMenuInMenuBar' , 'MenuName' , 'Index' , ), 1610743814, (1610743814, (), [ (8, 1, None, None) , 
             (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'RemoveMenuFromMenuBar' , 'Index' , ), 1610743815, (1610743815, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
]

IAcadPreferences_vtables_dispatch_ = 1
IAcadPreferences_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Files' , 'pObj' , ), 1610743809, (1610743809, (), [ (16393, 10, None, "IID('{125FA500-9ABC-4F98-87AD-869AEFA4AD72}')") , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Display' , 'pObj' , ), 1610743810, (1610743810, (), [ (16393, 10, None, "IID('{0D71BC3C-9854-4076-BD32-D545259AB752}')") , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'OpenSave' , 'pObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{5E24ED87-DC43-4771-B7E6-7FE35C21CAB1}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Output' , 'pObj' , ), 1610743812, (1610743812, (), [ (16393, 10, None, "IID('{1560A14A-D97B-4B3B-BF95-D0F703723442}')") , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'System' , 'pObj' , ), 1610743813, (1610743813, (), [ (16393, 10, None, "IID('{408546BA-FF59-4AA8-98C5-A1DBA4B730F8}')") , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'User' , 'pObj' , ), 1610743814, (1610743814, (), [ (16393, 10, None, "IID('{689AE380-B75C-430E-8A70-D116D8B4FA63}')") , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Drafting' , 'pObj' , ), 1610743815, (1610743815, (), [ (16393, 10, None, "IID('{35D9C296-C2E9-4DAB-93CA-4A62F71C9FC1}')") , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Selection' , 'pObj' , ), 1610743816, (1610743816, (), [ (16393, 10, None, "IID('{CE512178-E98E-4225-800E-0A29DEE39BCD}')") , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Profiles' , 'pObj' , ), 1610743817, (1610743817, (), [ (16393, 10, None, "IID('{52F0656B-9D63-4C67-ADBF-E9C732ED271B}')") , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesDisplay_vtables_dispatch_ = 1
IAcadPreferencesDisplay_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'LayoutDisplayMargins' , 'Path' , ), 1610743809, (1610743809, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'LayoutDisplayMargins' , 'Path' , ), 1610743809, (1610743809, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'LayoutDisplayPaper' , 'Path' , ), 1610743811, (1610743811, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'LayoutDisplayPaper' , 'Path' , ), 1610743811, (1610743811, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'LayoutDisplayPaperShadow' , 'Path' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'LayoutDisplayPaperShadow' , 'Path' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'LayoutShowPlotSetup' , 'Path' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'LayoutShowPlotSetup' , 'Path' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'LayoutCreateViewport' , 'Path' , ), 1610743817, (1610743817, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'LayoutCreateViewport' , 'Path' , ), 1610743817, (1610743817, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'DisplayScrollBars' , 'Path' , ), 1610743819, (1610743819, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'DisplayScrollBars' , 'Path' , ), 1610743819, (1610743819, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'DisplayScreenMenu' , 'Path' , ), 1610743821, (1610743821, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'DisplayScreenMenu' , 'Path' , ), 1610743821, (1610743821, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'CursorSize' , 'Path' , ), 1610743823, (1610743823, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'CursorSize' , 'Path' , ), 1610743823, (1610743823, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'DockedVisibleLines' , 'Path' , ), 1610743825, (1610743825, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'DockedVisibleLines' , 'Path' , ), 1610743825, (1610743825, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'ShowRasterImage' , 'Path' , ), 1610743827, (1610743827, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'ShowRasterImage' , 'Path' , ), 1610743827, (1610743827, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'GraphicsWinModelBackgrndColor' , 'color' , ), 1610743829, (1610743829, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'GraphicsWinModelBackgrndColor' , 'color' , ), 1610743829, (1610743829, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'ModelCrosshairColor' , 'crossHairColor' , ), 1610743831, (1610743831, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'ModelCrosshairColor' , 'crossHairColor' , ), 1610743831, (1610743831, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'GraphicsWinLayoutBackgrndColor' , 'color' , ), 1610743833, (1610743833, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'GraphicsWinLayoutBackgrndColor' , 'color' , ), 1610743833, (1610743833, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
    (( 'TextWinBackgrndColor' , 'Path' , ), 1610743835, (1610743835, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
    (( 'TextWinBackgrndColor' , 'Path' , ), 1610743835, (1610743835, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
    (( 'TextWinTextColor' , 'Path' , ), 1610743837, (1610743837, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
    (( 'TextWinTextColor' , 'Path' , ), 1610743837, (1610743837, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
    (( 'LayoutCrosshairColor' , 'crossHairColor' , ), 1610743839, (1610743839, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
    (( 'LayoutCrosshairColor' , 'crossHairColor' , ), 1610743839, (1610743839, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
    (( 'AutoTrackingVecColor' , 'AutoTrackingVecColor' , ), 1610743841, (1610743841, (), [ (19, 1, None, None) , ], 1 , 4 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
    (( 'AutoTrackingVecColor' , 'AutoTrackingVecColor' , ), 1610743841, (1610743841, (), [ (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 328 , (3, 0, None, None) , 0 , )),
    (( 'TextFont' , 'Path' , ), 1610743843, (1610743843, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 336 , (3, 0, None, None) , 0 , )),
    (( 'TextFont' , 'Path' , ), 1610743843, (1610743843, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 344 , (3, 0, None, None) , 0 , )),
    (( 'TextFontStyle' , 'Path' , ), 1610743845, (1610743845, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 352 , (3, 0, None, None) , 0 , )),
    (( 'TextFontStyle' , 'Path' , ), 1610743845, (1610743845, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 360 , (3, 0, None, None) , 0 , )),
    (( 'TextFontSize' , 'Path' , ), 1610743847, (1610743847, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 368 , (3, 0, None, None) , 0 , )),
    (( 'TextFontSize' , 'Path' , ), 1610743847, (1610743847, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 376 , (3, 0, None, None) , 0 , )),
    (( 'HistoryLines' , 'Path' , ), 1610743849, (1610743849, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 384 , (3, 0, None, None) , 0 , )),
    (( 'HistoryLines' , 'Path' , ), 1610743849, (1610743849, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 392 , (3, 0, None, None) , 0 , )),
    (( 'MaxAutoCADWindow' , 'Path' , ), 1610743851, (1610743851, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 400 , (3, 0, None, None) , 0 , )),
    (( 'MaxAutoCADWindow' , 'Path' , ), 1610743851, (1610743851, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 408 , (3, 0, None, None) , 0 , )),
    (( 'DisplayLayoutTabs' , 'Path' , ), 1610743853, (1610743853, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 416 , (3, 0, None, None) , 0 , )),
    (( 'DisplayLayoutTabs' , 'Path' , ), 1610743853, (1610743853, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 424 , (3, 0, None, None) , 0 , )),
    (( 'ImageFrameHighlight' , 'Path' , ), 1610743855, (1610743855, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 432 , (3, 0, None, None) , 0 , )),
    (( 'ImageFrameHighlight' , 'Path' , ), 1610743855, (1610743855, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 440 , (3, 0, None, None) , 0 , )),
    (( 'TrueColorImages' , 'Path' , ), 1610743857, (1610743857, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 448 , (3, 0, None, None) , 0 , )),
    (( 'TrueColorImages' , 'Path' , ), 1610743857, (1610743857, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 456 , (3, 0, None, None) , 0 , )),
    (( 'XRefFadeIntensity' , 'Path' , ), 1610743859, (1610743859, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 464 , (3, 0, None, None) , 0 , )),
    (( 'XRefFadeIntensity' , 'Path' , ), 1610743859, (1610743859, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 472 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesDrafting_vtables_dispatch_ = 1
IAcadPreferencesDrafting_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMarker' , 'Path' , ), 1610743809, (1610743809, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMarker' , 'Path' , ), 1610743809, (1610743809, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMagnet' , 'Path' , ), 1610743811, (1610743811, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMagnet' , 'Path' , ), 1610743811, (1610743811, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapTooltip' , 'Path' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapTooltip' , 'Path' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapAperture' , 'Path' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapAperture' , 'Path' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapApertureSize' , 'Path' , ), 1610743817, (1610743817, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapApertureSize' , 'Path' , ), 1610743817, (1610743817, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMarkerColor' , 'Path' , ), 1610743819, (1610743819, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMarkerColor' , 'Path' , ), 1610743819, (1610743819, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMarkerSize' , 'Path' , ), 1610743821, (1610743821, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'AutoSnapMarkerSize' , 'Path' , ), 1610743821, (1610743821, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'PolarTrackingVector' , 'Path' , ), 1610743823, (1610743823, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'PolarTrackingVector' , 'Path' , ), 1610743823, (1610743823, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'FullScreenTrackingVector' , 'Path' , ), 1610743825, (1610743825, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'FullScreenTrackingVector' , 'Path' , ), 1610743825, (1610743825, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'AutoTrackTooltip' , 'Path' , ), 1610743827, (1610743827, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'AutoTrackTooltip' , 'Path' , ), 1610743827, (1610743827, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'AlignmentPointAcquisition' , 'Path' , ), 1610743829, (1610743829, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'AlignmentPointAcquisition' , 'Path' , ), 1610743829, (1610743829, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesFiles_vtables_dispatch_ = 1
IAcadPreferencesFiles_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'SupportPath' , 'orient' , ), 0, (0, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'SupportPath' , 'orient' , ), 0, (0, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'DriversPath' , 'Path' , ), 1610743811, (1610743811, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'DriversPath' , 'Path' , ), 1610743811, (1610743811, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'MenuFile' , 'Path' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'MenuFile' , 'Path' , ), 1610743813, (1610743813, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'HelpFilePath' , 'Path' , ), 1610743815, (1610743815, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'HelpFilePath' , 'Path' , ), 1610743815, (1610743815, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'DefaultInternetURL' , 'Path' , ), 1610743817, (1610743817, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'DefaultInternetURL' , 'Path' , ), 1610743817, (1610743817, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'ConfigFile' , 'ConfigFile' , ), 1610743819, (1610743819, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'LicenseServer' , 'Path' , ), 1610743820, (1610743820, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 64 , )),
    (( 'TextEditor' , 'Path' , ), 1610743821, (1610743821, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'TextEditor' , 'Path' , ), 1610743821, (1610743821, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'MainDictionary' , 'Path' , ), 1610743823, (1610743823, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'MainDictionary' , 'Path' , ), 1610743823, (1610743823, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'CustomDictionary' , 'Path' , ), 1610743825, (1610743825, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'CustomDictionary' , 'Path' , ), 1610743825, (1610743825, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'AltFontFile' , 'fontFile' , ), 1610743827, (1610743827, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'AltFontFile' , 'fontFile' , ), 1610743827, (1610743827, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'FontFileMap' , 'Path' , ), 1610743829, (1610743829, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'FontFileMap' , 'Path' , ), 1610743829, (1610743829, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'PrintFile' , 'Path' , ), 1610743831, (1610743831, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'PrintFile' , 'Path' , ), 1610743831, (1610743831, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'PrintSpoolExecutable' , 'Path' , ), 1610743833, (1610743833, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'PrintSpoolExecutable' , 'Path' , ), 1610743833, (1610743833, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
    (( 'PostScriptPrologFile' , 'Path' , ), 1610743835, (1610743835, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
    (( 'PostScriptPrologFile' , 'Path' , ), 1610743835, (1610743835, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
    (( 'PrintSpoolerPath' , 'Path' , ), 1610743837, (1610743837, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
    (( 'PrintSpoolerPath' , 'Path' , ), 1610743837, (1610743837, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
    (( 'AutoSavePath' , 'AutoSavePath' , ), 1610743839, (1610743839, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
    (( 'AutoSavePath' , 'AutoSavePath' , ), 1610743839, (1610743839, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
    (( 'TemplateDwgPath' , 'Path' , ), 1610743841, (1610743841, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
    (( 'TemplateDwgPath' , 'Path' , ), 1610743841, (1610743841, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 328 , (3, 0, None, None) , 0 , )),
    (( 'LogFilePath' , 'Path' , ), 1610743843, (1610743843, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 336 , (3, 0, None, None) , 0 , )),
    (( 'LogFilePath' , 'Path' , ), 1610743843, (1610743843, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 344 , (3, 0, None, None) , 0 , )),
    (( 'TempFilePath' , 'Path' , ), 1610743845, (1610743845, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 352 , (3, 0, None, None) , 0 , )),
    (( 'TempFilePath' , 'Path' , ), 1610743845, (1610743845, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 360 , (3, 0, None, None) , 0 , )),
    (( 'TempXrefPath' , 'Path' , ), 1610743847, (1610743847, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 368 , (3, 0, None, None) , 0 , )),
    (( 'TempXrefPath' , 'Path' , ), 1610743847, (1610743847, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 376 , (3, 0, None, None) , 0 , )),
    (( 'TextureMapPath' , 'Path' , ), 1610743849, (1610743849, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 384 , (3, 0, None, None) , 0 , )),
    (( 'TextureMapPath' , 'Path' , ), 1610743849, (1610743849, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 392 , (3, 0, None, None) , 0 , )),
    (( 'AltTabletMenuFile' , 'MenuFile' , ), 1610743851, (1610743851, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 400 , (3, 0, None, None) , 0 , )),
    (( 'AltTabletMenuFile' , 'MenuFile' , ), 1610743851, (1610743851, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 408 , (3, 0, None, None) , 0 , )),
    (( 'SetProjectFilePath' , 'ProjectName' , 'ProjectFilePath' , ), 1610743853, (1610743853, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 416 , (3, 0, None, None) , 0 , )),
    (( 'GetProjectFilePath' , 'ProjectName' , 'Path' , ), 1610743854, (1610743854, (), [ (8, 1, None, None) , 
             (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 424 , (3, 0, None, None) , 0 , )),
    (( 'PrinterConfigPath' , 'Path' , ), 1610743855, (1610743855, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 432 , (3, 0, None, None) , 0 , )),
    (( 'PrinterConfigPath' , 'Path' , ), 1610743855, (1610743855, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 440 , (3, 0, None, None) , 0 , )),
    (( 'PrinterDescPath' , 'Path' , ), 1610743857, (1610743857, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 448 , (3, 0, None, None) , 0 , )),
    (( 'PrinterDescPath' , 'Path' , ), 1610743857, (1610743857, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 456 , (3, 0, None, None) , 0 , )),
    (( 'PrinterStyleSheetPath' , 'Path' , ), 1610743859, (1610743859, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 464 , (3, 0, None, None) , 0 , )),
    (( 'PrinterStyleSheetPath' , 'Path' , ), 1610743859, (1610743859, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 472 , (3, 0, None, None) , 0 , )),
    (( 'WorkspacePath' , 'Path' , ), 1610743861, (1610743861, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 480 , (3, 0, None, None) , 0 , )),
    (( 'WorkspacePath' , 'Path' , ), 1610743861, (1610743861, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 488 , (3, 0, None, None) , 0 , )),
    (( 'ObjectARXPath' , 'Path' , ), 1610743863, (1610743863, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 496 , (3, 0, None, None) , 64 , )),
    (( 'ObjectARXPath' , 'Path' , ), 1610743863, (1610743863, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 504 , (3, 0, None, None) , 64 , )),
    (( 'ColorBookPath' , 'Path' , ), 1610743865, (1610743865, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 512 , (3, 0, None, None) , 0 , )),
    (( 'ColorBookPath' , 'Path' , ), 1610743865, (1610743865, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 520 , (3, 0, None, None) , 0 , )),
    (( 'ToolPalettePath' , 'Path' , ), 1610743867, (1610743867, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 528 , (3, 0, None, None) , 0 , )),
    (( 'ToolPalettePath' , 'Path' , ), 1610743867, (1610743867, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 536 , (3, 0, None, None) , 0 , )),
    (( 'QNewTemplateFile' , 'Path' , ), 1610743869, (1610743869, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 544 , (3, 0, None, None) , 0 , )),
    (( 'QNewTemplateFile' , 'Path' , ), 1610743869, (1610743869, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 552 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesOpenSave_vtables_dispatch_ = 1
IAcadPreferencesOpenSave_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'SavePreviewThumbnail' , 'Path' , ), 1610743809, (1610743809, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'SavePreviewThumbnail' , 'Path' , ), 1610743809, (1610743809, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'IncrementalSavePercent' , 'Path' , ), 1610743811, (1610743811, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'IncrementalSavePercent' , 'Path' , ), 1610743811, (1610743811, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'AutoSaveInterval' , 'Path' , ), 1610743813, (1610743813, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'AutoSaveInterval' , 'Path' , ), 1610743813, (1610743813, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'CreateBackup' , 'CreateBackup' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'CreateBackup' , 'CreateBackup' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'FullCRCValidation' , 'Path' , ), 1610743817, (1610743817, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'FullCRCValidation' , 'Path' , ), 1610743817, (1610743817, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'LogFileOn' , 'Path' , ), 1610743819, (1610743819, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'LogFileOn' , 'Path' , ), 1610743819, (1610743819, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'TempFileExtension' , 'Path' , ), 1610743821, (1610743821, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'TempFileExtension' , 'Path' , ), 1610743821, (1610743821, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'XrefDemandLoad' , 'Path' , ), 1610743823, (1610743823, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'XrefDemandLoad' , 'Path' , ), 1610743823, (1610743823, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'DemandLoadARXApp' , 'Path' , ), 1610743825, (1610743825, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'DemandLoadARXApp' , 'Path' , ), 1610743825, (1610743825, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'ProxyImage' , 'Path' , ), 1610743827, (1610743827, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'ProxyImage' , 'Path' , ), 1610743827, (1610743827, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'ShowProxyDialogBox' , 'Path' , ), 1610743829, (1610743829, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'ShowProxyDialogBox' , 'Path' , ), 1610743829, (1610743829, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'AutoAudit' , 'bAudit' , ), 1610743831, (1610743831, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'AutoAudit' , 'bAudit' , ), 1610743831, (1610743831, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'SaveAsType' , 'Path' , ), 1610743833, (1610743833, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'SaveAsType' , 'Path' , ), 1610743833, (1610743833, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
    (( 'MRUNumber' , 'Path' , ), 1610743835, (1610743835, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
    (( 'DWFFormat' , 'Path' , ), 1610743836, (1610743836, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
    (( 'DWFFormat' , 'Path' , ), 1610743836, (1610743836, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesOutput_vtables_dispatch_ = 1
IAcadPreferencesOutput_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'DefaultOutputDevice' , 'Path' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'DefaultOutputDevice' , 'Path' , ), 1610743809, (1610743809, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'PrinterSpoolAlert' , 'Path' , ), 1610743811, (1610743811, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'PrinterSpoolAlert' , 'Path' , ), 1610743811, (1610743811, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'PrinterPaperSizeAlert' , 'Path' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'PrinterPaperSizeAlert' , 'Path' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'PlotLegacy' , 'Path' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'PlotLegacy' , 'Path' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'OLEQuality' , 'Path' , ), 1610743817, (1610743817, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'OLEQuality' , 'Path' , ), 1610743817, (1610743817, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'UseLastPlotSettings' , 'Path' , ), 1610743819, (1610743819, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'UseLastPlotSettings' , 'Path' , ), 1610743819, (1610743819, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'PlotPolicy' , 'Path' , ), 1610743821, (1610743821, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'PlotPolicy' , 'Path' , ), 1610743821, (1610743821, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'DefaultPlotStyleTable' , 'Path' , ), 1610743823, (1610743823, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'DefaultPlotStyleTable' , 'Path' , ), 1610743823, (1610743823, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'DefaultPlotStyleForObjects' , 'Path' , ), 1610743825, (1610743825, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'DefaultPlotStyleForObjects' , 'Path' , ), 1610743825, (1610743825, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'DefaultPlotStyleForLayer' , 'Path' , ), 1610743827, (1610743827, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'DefaultPlotStyleForLayer' , 'Path' , ), 1610743827, (1610743827, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'Pdf' , 'pObj' , ), 1610743828, (1610743828, (), [ (16393, 10, None, "IID('{21F2EB66-F27E-40AF-A3F5-7F2E7D6F6AA6}')") , ], 1 , 2 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesPdfOutput_vtables_dispatch_ = 1
IAcadPreferencesPdfOutput_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'ZoomToExtents' , 'Flag' , ), 1610743809, (1610743809, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'ZoomToExtents' , 'Flag' , ), 1610743809, (1610743809, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'PaperSizeOverride' , 'Flag' , ), 1610743810, (1610743810, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'PaperSizeOverride' , 'Flag' , ), 1610743810, (1610743810, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'ShxTextAsGeometry' , 'Flag' , ), 1610743811, (1610743811, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'ShxTextAsGeometry' , 'Flag' , ), 1610743811, (1610743811, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'SimpleGeomOptimization' , 'Flag' , ), 1610743812, (1610743812, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'SimpleGeomOptimization' , 'Flag' , ), 1610743812, (1610743812, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'TtfTextAsGeometry' , 'Flag' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'TtfTextAsGeometry' , 'Flag' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'EmbeddedTtf' , 'Flag' , ), 1610743814, (1610743814, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'EmbeddedTtf' , 'Flag' , ), 1610743814, (1610743814, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'LayersSetting' , 'Value' , ), 1610743815, (1610743815, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'LayersSetting' , 'Value' , ), 1610743815, (1610743815, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'LayoutsToExport' , 'Value' , ), 1610743816, (1610743816, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'LayoutsToExport' , 'Value' , ), 1610743816, (1610743816, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'PaperHeight' , 'Value' , ), 1610743817, (1610743817, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'PaperHeight' , 'Value' , ), 1610743817, (1610743817, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'PaperWidth' , 'Value' , ), 1610743818, (1610743818, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'PaperWidth' , 'Value' , ), 1610743818, (1610743818, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'UsePlotStyles' , 'Value' , ), 1610743819, (1610743819, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'UsePlotStyles' , 'Value' , ), 1610743819, (1610743819, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'ExportHyperlinks' , 'Value' , ), 1610743820, (1610743820, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'ExportHyperlinks' , 'Value' , ), 1610743820, (1610743820, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'CreateBookmarks' , 'Value' , ), 1610743821, (1610743821, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'CreateBookmarks' , 'Value' , ), 1610743821, (1610743821, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesProfiles_vtables_dispatch_ = 1
IAcadPreferencesProfiles_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'ActiveProfile' , 'Path' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'ActiveProfile' , 'Path' , ), 1610743809, (1610743809, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'ImportProfile' , 'ProfileName' , 'RegFile' , 'IncludePathInfo' , ), 1610743811, (1610743811, (), [ 
             (8, 1, None, None) , (8, 1, None, None) , (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'ExportProfile' , 'ProfileName' , 'RegFile' , ), 1610743812, (1610743812, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'DeleteProfile' , 'ProfileName' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'ResetProfile' , 'Profile' , ), 1610743814, (1610743814, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'RenameProfile' , 'origProfileName' , 'newProfileName' , ), 1610743815, (1610743815, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'CopyProfile' , 'oldProfileName' , 'newProfileName' , ), 1610743816, (1610743816, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'GetAllProfileNames' , 'pNames' , ), 1610743817, (1610743817, (), [ (16396, 2, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesSelection_vtables_dispatch_ = 1
IAcadPreferencesSelection_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'PickFirst' , 'Path' , ), 1610743809, (1610743809, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'PickFirst' , 'Path' , ), 1610743809, (1610743809, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'PickAdd' , 'Path' , ), 1610743811, (1610743811, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'PickAdd' , 'Path' , ), 1610743811, (1610743811, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'PickDrag' , 'Path' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'PickDrag' , 'Path' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'PickAuto' , 'Path' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'PickAuto' , 'Path' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'PickBoxSize' , 'Path' , ), 1610743817, (1610743817, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'PickBoxSize' , 'Path' , ), 1610743817, (1610743817, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'DisplayGrips' , 'Path' , ), 1610743819, (1610743819, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'DisplayGrips' , 'Path' , ), 1610743819, (1610743819, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'DisplayGripsWithinBlocks' , 'Path' , ), 1610743821, (1610743821, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'DisplayGripsWithinBlocks' , 'Path' , ), 1610743821, (1610743821, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'GripColorSelected' , 'Path' , ), 1610743823, (1610743823, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'GripColorSelected' , 'Path' , ), 1610743823, (1610743823, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'GripColorUnselected' , 'Path' , ), 1610743825, (1610743825, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'GripColorUnselected' , 'Path' , ), 1610743825, (1610743825, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'GripSize' , 'Path' , ), 1610743827, (1610743827, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'GripSize' , 'Path' , ), 1610743827, (1610743827, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'PickGroup' , 'pick' , ), 1610743829, (1610743829, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'PickGroup' , 'pick' , ), 1610743829, (1610743829, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesSystem_vtables_dispatch_ = 1
IAcadPreferencesSystem_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'SingleDocumentMode' , 'Path' , ), 1610743809, (1610743809, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'SingleDocumentMode' , 'Path' , ), 1610743809, (1610743809, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'DisplayOLEScale' , 'Path' , ), 1610743811, (1610743811, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'DisplayOLEScale' , 'Path' , ), 1610743811, (1610743811, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'StoreSQLIndex' , 'Path' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'StoreSQLIndex' , 'Path' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'TablesReadOnly' , 'Path' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'TablesReadOnly' , 'Path' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'EnableStartupDialog' , 'Path' , ), 1610743817, (1610743817, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'EnableStartupDialog' , 'Path' , ), 1610743817, (1610743817, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'BeepOnError' , 'BeepOnError' , ), 1610743819, (1610743819, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'BeepOnError' , 'BeepOnError' , ), 1610743819, (1610743819, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'ShowWarningMessages' , 'Path' , ), 1610743821, (1610743821, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'ShowWarningMessages' , 'Path' , ), 1610743821, (1610743821, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'LoadAcadLspInAllDocuments' , 'pALID' , ), 1610743823, (1610743823, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'LoadAcadLspInAllDocuments' , 'pALID' , ), 1610743823, (1610743823, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
]

IAcadPreferencesUser_vtables_dispatch_ = 1
IAcadPreferencesUser_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'KeyboardAccelerator' , 'Path' , ), 1610743809, (1610743809, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'KeyboardAccelerator' , 'Path' , ), 1610743809, (1610743809, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'KeyboardPriority' , 'Path' , ), 1610743811, (1610743811, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'KeyboardPriority' , 'Path' , ), 1610743811, (1610743811, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'HyperlinkDisplayCursor' , 'Path' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'HyperlinkDisplayCursor' , 'Path' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'HyperlinkDisplayTooltip' , 'Path' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'HyperlinkDisplayTooltip' , 'Path' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'ADCInsertUnitsDefaultSource' , 'pIU' , ), 1610743817, (1610743817, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'ADCInsertUnitsDefaultSource' , 'pIU' , ), 1610743817, (1610743817, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'ADCInsertUnitsDefaultTarget' , 'pSUunits' , ), 1610743819, (1610743819, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'ADCInsertUnitsDefaultTarget' , 'pSUunits' , ), 1610743819, (1610743819, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'ShortCutMenuDisplay' , 'pSCM' , ), 1610743821, (1610743821, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'ShortCutMenuDisplay' , 'pSCM' , ), 1610743821, (1610743821, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'SCMDefaultMode' , 'pSCM' , ), 1610743823, (1610743823, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'SCMDefaultMode' , 'pSCM' , ), 1610743823, (1610743823, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'SCMEditMode' , 'pSCM' , ), 1610743825, (1610743825, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'SCMEditMode' , 'pSCM' , ), 1610743825, (1610743825, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'SCMCommandMode' , 'pSCM' , ), 1610743827, (1610743827, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'SCMCommandMode' , 'pSCM' , ), 1610743827, (1610743827, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'SCMTimeMode' , 'time' , ), 1610743829, (1610743829, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'SCMTimeMode' , 'time' , ), 1610743829, (1610743829, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'SCMTimeValue' , 'time' , ), 1610743831, (1610743831, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'SCMTimeValue' , 'time' , ), 1610743831, (1610743831, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
]

IAcadSecurityParams_vtables_dispatch_ = 1
IAcadSecurityParams_vtables_ = [
    (( 'Action' , 'pOperations' , ), 1, (1, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Action' , 'pOperations' , ), 1, (1, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Password' , 'pSecret' , ), 2, (2, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Password' , 'pSecret' , ), 2, (2, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'ProviderType' , 'pProvType' , ), 3, (3, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'ProviderType' , 'pProvType' , ), 3, (3, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'ProviderName' , 'pProvName' , ), 4, (4, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'ProviderName' , 'pProvName' , ), 4, (4, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Algorithm' , 'pAlgId' , ), 5, (5, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Algorithm' , 'pAlgId' , ), 5, (5, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'KeyLength' , 'pKeyLen' , ), 6, (6, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'KeyLength' , 'pKeyLen' , ), 6, (6, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'Subject' , 'pCertSubject' , ), 7, (7, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'Subject' , 'pCertSubject' , ), 7, (7, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'Issuer' , 'pCertIssuer' , ), 8, (8, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'Issuer' , 'pCertIssuer' , ), 8, (8, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'SerialNumber' , 'pSerialNum' , ), 9, (9, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'SerialNumber' , 'pSerialNum' , ), 9, (9, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'Comment' , 'pText' , ), 10, (10, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'Comment' , 'pText' , ), 10, (10, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'TimeServer' , 'pTimeServerName' , ), 11, (11, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'TimeServer' , 'pTimeServerName' , ), 11, (11, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
]

IAcadSelectionSet_vtables_dispatch_ = 1
IAcadSelectionSet_vtables_ = [
    (( 'Item' , 'Index' , 'pEntity' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{FFE64704-CEBD-4C88-A867-E7C821AFE488}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Count' , 'pVal' , ), 1, (1, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pVal' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 65 , )),
    (( 'Name' , 'bstrName' , ), 2, (2, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Highlight' , 'bFlag' , ), 3, (3, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Erase' , ), 4, (4, (), [ ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Update' , ), 5, (5, (), [ ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 6, (6, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'AddItems' , 'pSelSet' , ), 7, (7, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'RemoveItems' , 'Objects' , ), 8, (8, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'Clear' , ), 9, (9, (), [ ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'Select' , 'Mode' , 'Point1' , 'Point2' , 'FilterType' , 
             'FilterData' , ), 10, (10, (), [ (3, 1, None, None) , (12, 17, None, None) , (12, 17, None, None) , 
             (12, 17, None, None) , (12, 17, None, None) , ], 1 , 1 , 4 , 4 , 144 , (3, 0, None, None) , 0 , )),
    (( 'SelectAtPoint' , 'Point' , 'FilterType' , 'FilterData' , ), 11, (11, (), [ 
             (12, 1, None, None) , (12, 17, None, None) , (12, 17, None, None) , ], 1 , 1 , 4 , 2 , 152 , (3, 0, None, None) , 0 , )),
    (( 'SelectByPolygon' , 'Mode' , 'PointsList' , 'FilterType' , 'FilterData' , 
             ), 12, (12, (), [ (3, 1, None, None) , (12, 1, None, None) , (12, 17, None, None) , (12, 17, None, None) , ], 1 , 1 , 4 , 2 , 160 , (3, 0, None, None) , 0 , )),
    (( 'SelectOnScreen' , 'FilterType' , 'FilterData' , ), 13, (13, (), [ (12, 17, None, None) , 
             (12, 17, None, None) , ], 1 , 1 , 4 , 2 , 168 , (3, 0, None, None) , 0 , )),
    (( 'Delete' , ), 14, (14, (), [ ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcadSelectionSets_vtables_dispatch_ = 1
IAcadSelectionSets_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Count' , 'pVal' , ), 2, (2, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pVal' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 65 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Add' , 'Name' , 'pSet' , ), 4, (4, (), [ (8, 1, None, None) , 
             (16393, 10, None, "IID('{01374CB7-5D3B-4556-800C-9BFC71BBEC42}')") , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
]

IAcadState_vtables_dispatch_ = 1
IAcadState_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1, (1, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'IsQuiescent' , 'bQuiescent' , ), 2, (2, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

IAcadToolbar_vtables_dispatch_ = 1
IAcadToolbar_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{EBCED992-0BB7-4165-B4D6-44261F377565}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743812, (1610743812, (), [ (16393, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'bstrName' , ), 1610743813, (1610743813, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'bstrName' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Visible' , 'bFlag' , ), 1610743815, (1610743815, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Visible' , 'bFlag' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'DockStatus' , 'nStatus' , ), 1610743817, (1610743817, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'LargeButtons' , 'bFlag' , ), 1610743818, (1610743818, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'left' , 'nLeft' , ), 1610743819, (1610743819, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'left' , 'nLeft' , ), 1610743819, (1610743819, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'top' , 'nTop' , ), 1610743821, (1610743821, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'top' , 'nTop' , ), 1610743821, (1610743821, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'nWidth' , ), 1610743823, (1610743823, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'nHeight' , ), 1610743824, (1610743824, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'FloatingRows' , 'nRows' , ), 1610743825, (1610743825, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'FloatingRows' , 'nRows' , ), 1610743825, (1610743825, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'HelpString' , 'bstrHelp' , ), 1610743827, (1610743827, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'HelpString' , 'bstrHelp' , ), 1610743827, (1610743827, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'AddToolbarButton' , 'Index' , 'Name' , 'HelpString' , 'Macro' , 
             'FlyoutButton' , 'pItem' , ), 1610743829, (1610743829, (), [ (12, 1, None, None) , (8, 1, None, None) , 
             (8, 1, None, None) , (8, 1, None, None) , (12, 17, None, None) , (16393, 10, None, "IID('{EBCED992-0BB7-4165-B4D6-44261F377565}')") , ], 1 , 1 , 4 , 1 , 224 , (3, 0, None, None) , 0 , )),
    (( 'AddSeparator' , 'Index' , 'pItem' , ), 1610743830, (1610743830, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{EBCED992-0BB7-4165-B4D6-44261F377565}')") , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'Dock' , 'Side' , ), 1610743831, (1610743831, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'Float' , 'top' , 'left' , 'NumberFloatRows' , ), 1610743832, (1610743832, (), [ 
             (3, 1, None, None) , (3, 1, None, None) , (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'Delete' , ), 1610743833, (1610743833, (), [ ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'TagString' , 'bstrTag' , ), 1610743834, (1610743834, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
]

IAcadToolbarItem_vtables_dispatch_ = 1
IAcadToolbarItem_vtables_ = [
    (( 'Application' , 'pAppObj' , ), 1610743808, (1610743808, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743809, (1610743809, (), [ (16393, 10, None, "IID('{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')") , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'bstrName' , ), 1610743810, (1610743810, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Name' , 'bstrName' , ), 1610743810, (1610743810, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'TagString' , 'bstrTag' , ), 1610743812, (1610743812, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'TagString' , 'bstrTag' , ), 1610743812, (1610743812, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Type' , 'itemType' , ), 1610743814, (1610743814, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Flyout' , 'pTlbar' , ), 1610743815, (1610743815, (), [ (16393, 10, None, "IID('{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')") , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Macro' , 'bstrMacro' , ), 1610743816, (1610743816, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Macro' , 'bstrMacro' , ), 1610743816, (1610743816, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'Index' , 'nIndex' , ), 1610743818, (1610743818, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'HelpString' , 'bstrHelp' , ), 1610743819, (1610743819, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'HelpString' , 'bstrHelp' , ), 1610743819, (1610743819, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'GetBitmaps' , 'SmallIconName' , 'LargeIconName' , ), 1610743821, (1610743821, (), [ (16392, 2, None, None) , 
             (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'SetBitmaps' , 'SmallIconName' , 'LargeIconName' , ), 1610743822, (1610743822, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'AttachToolbarToFlyout' , 'MenuGroupName' , 'ToolbarName' , ), 1610743823, (1610743823, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'Delete' , ), 1610743824, (1610743824, (), [ ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
]

IAcadToolbars_vtables_dispatch_ = 1
IAcadToolbars_vtables_ = [
    (( 'Item' , 'Index' , 'pItem' , ), 0, (0, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( '_NewEnum' , 'pEnumVariant' , ), -4, (-4, (), [ (16397, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 65 , )),
    (( 'Count' , 'Count' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Application' , 'pAppObj' , ), 1610743811, (1610743811, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Parent' , 'pParent' , ), 1610743812, (1610743812, (), [ (16393, 10, None, "IID('{DF14CB14-CDC6-463F-B71C-356149D1F935}')") , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'LargeButtons' , 'bFlag' , ), 1610743813, (1610743813, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'LargeButtons' , 'bFlag' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Add' , 'ToolbarName' , 'pTlbar' , ), 1610743815, (1610743815, (), [ (8, 1, None, None) , 
             (16393, 10, None, "IID('{618F1FE3-4CF9-41D4-A070-387C8560D4EC}')") , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
]

IAcadUtility_vtables_dispatch_ = 1
IAcadUtility_vtables_ = [
    (( 'AngleToReal' , 'Angle' , 'Unit' , 'Value' , ), 1610743808, (1610743808, (), [ 
             (8, 1, None, None) , (3, 1, None, None) , (16389, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'AngleToString' , 'Angle' , 'Unit' , 'precision' , 'bstrValue' , 
             ), 1610743809, (1610743809, (), [ (5, 1, None, None) , (3, 1, None, None) , (3, 1, None, None) , (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'DistanceToReal' , 'Distance' , 'Unit' , 'Value' , ), 1610743810, (1610743810, (), [ 
             (8, 1, None, None) , (3, 1, None, None) , (16389, 10, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'RealToString' , 'Value' , 'Unit' , 'precision' , 'bstrValue' , 
             ), 1610743811, (1610743811, (), [ (5, 1, None, None) , (3, 1, None, None) , (3, 1, None, None) , (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'TranslateCoordinates' , 'Point' , 'FromCoordSystem' , 'ToCoordSystem' , 'Displacement' , 
             'OCSNormal' , 'transPt' , ), 1610743812, (1610743812, (), [ (12, 1, None, None) , (3, 1, None, None) , 
             (3, 1, None, None) , (3, 1, None, None) , (12, 17, None, None) , (16396, 10, None, None) , ], 1 , 1 , 4 , 1 , 88 , (3, 0, None, None) , 0 , )),
    (( 'InitializeUserInput' , 'Bits' , 'KeyWordList' , ), 1610743813, (1610743813, (), [ (3, 1, None, None) , 
             (12, 17, None, None) , ], 1 , 1 , 4 , 1 , 96 , (3, 0, None, None) , 0 , )),
    (( 'GetInteger' , 'Prompt' , 'Value' , ), 1610743814, (1610743814, (), [ (12, 17, None, None) , 
             (16387, 10, None, None) , ], 1 , 1 , 4 , 1 , 104 , (3, 0, None, None) , 0 , )),
    (( 'GetReal' , 'Prompt' , 'Value' , ), 1610743815, (1610743815, (), [ (12, 17, None, None) , 
             (16389, 10, None, None) , ], 1 , 1 , 4 , 1 , 112 , (3, 0, None, None) , 0 , )),
    (( 'GetInput' , 'Value' , ), 1610743816, (1610743816, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'GetKeyword' , 'Prompt' , 'bstrKeyword' , ), 1610743817, (1610743817, (), [ (12, 17, None, None) , 
             (16392, 10, None, None) , ], 1 , 1 , 4 , 1 , 128 , (3, 0, None, None) , 0 , )),
    (( 'GetString' , 'HasSpaces' , 'Prompt' , 'bstrValue' , ), 1610743818, (1610743818, (), [ 
             (3, 1, None, None) , (12, 17, None, None) , (16392, 10, None, None) , ], 1 , 1 , 4 , 1 , 136 , (3, 0, None, None) , 0 , )),
    (( 'GetAngle' , 'Point' , 'Prompt' , 'Angle' , ), 1610743819, (1610743819, (), [ 
             (12, 17, None, None) , (12, 17, None, None) , (16389, 10, None, None) , ], 1 , 1 , 4 , 2 , 144 , (3, 0, None, None) , 0 , )),
    (( 'AngleFromXAxis' , 'StartPoint' , 'EndPoint' , 'Angle' , ), 1610743820, (1610743820, (), [ 
             (12, 1, None, None) , (12, 1, None, None) , (16389, 10, None, None) , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'GetCorner' , 'Point' , 'Prompt' , 'corner' , ), 1610743821, (1610743821, (), [ 
             (12, 1, None, None) , (12, 17, None, None) , (16396, 10, None, None) , ], 1 , 1 , 4 , 1 , 160 , (3, 0, None, None) , 0 , )),
    (( 'GetDistance' , 'Point' , 'Prompt' , 'dist' , ), 1610743822, (1610743822, (), [ 
             (12, 17, None, None) , (12, 17, None, None) , (16389, 10, None, None) , ], 1 , 1 , 4 , 2 , 168 , (3, 0, None, None) , 0 , )),
    (( 'GetOrientation' , 'Point' , 'Prompt' , 'Angle' , ), 1610743823, (1610743823, (), [ 
             (12, 17, None, None) , (12, 17, None, None) , (16389, 10, None, None) , ], 1 , 1 , 4 , 2 , 176 , (3, 0, None, None) , 0 , )),
    (( 'GetPoint' , 'Point' , 'Prompt' , 'inputPoint' , ), 1610743824, (1610743824, (), [ 
             (12, 17, None, None) , (12, 17, None, None) , (16396, 10, None, None) , ], 1 , 1 , 4 , 2 , 184 , (3, 0, None, None) , 0 , )),
    (( 'PolarPoint' , 'Point' , 'Angle' , 'Distance' , 'inputPoint' , 
             ), 1610743825, (1610743825, (), [ (12, 1, None, None) , (5, 1, None, None) , (5, 1, None, None) , (16396, 10, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'CreateTypedArray' , 'varArr' , 'Type' , 'inArgs' , ), 1610743826, (1610743826, (), [ 
             (16396, 2, None, None) , (3, 1, None, None) , (8204, 1, None, None) , ], 1 , 1 , 4 , -1 , 200 , (3, 0, None, None) , 0 , )),
    (( 'GetEntity' , 'Object' , 'PickedPoint' , 'Prompt' , ), 1610743827, (1610743827, (), [ 
             (16393, 2, None, None) , (16396, 2, None, None) , (12, 17, None, None) , ], 1 , 1 , 4 , 1 , 208 , (3, 0, None, None) , 0 , )),
    (( 'Prompt' , 'Message' , ), 1610743828, (1610743828, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'GetSubEntity' , 'Object' , 'PickedPoint' , 'transMatrix' , 'ContextData' , 
             'Prompt' , ), 1610743829, (1610743829, (), [ (16393, 2, None, None) , (16396, 2, None, None) , (16396, 2, None, None) , 
             (16396, 2, None, None) , (12, 17, None, None) , ], 1 , 1 , 4 , 1 , 224 , (3, 0, None, None) , 0 , )),
    (( 'IsURL' , 'URL' , 'IsValidURL' , ), 1610743830, (1610743830, (), [ (8, 1, None, None) , 
             (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'GetRemoteFile' , 'URL' , 'LocalFile' , 'IgnoreCache' , ), 1610743831, (1610743831, (), [ 
             (8, 1, None, None) , (16392, 2, None, None) , (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'PutRemoteFile' , 'URL' , 'LocalFile' , ), 1610743832, (1610743832, (), [ (8, 1, None, None) , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'IsRemoteFile' , 'LocalFile' , 'URL' , 'IsDownloadedFile' , ), 1610743833, (1610743833, (), [ 
             (8, 1, None, None) , (16392, 2, None, None) , (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'LaunchBrowserDialog' , 'SelectedURL' , 'DialogTitle' , 'OpenButtonCaption' , 'StartPageURL' , 
             'RegistryRootKey' , 'OpenButtonAlwaysEnabled' , 'success' , ), 1610743834, (1610743834, (), [ (16392, 2, None, None) , 
             (8, 1, None, None) , (8, 1, None, None) , (8, 1, None, None) , (8, 1, None, None) , (11, 1, None, None) , 
             (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
    (( 'SendModelessOperationStart' , 'operation' , ), 1610743835, (1610743835, (), [ (8, 0, None, None) , ], 1 , 1 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
    (( 'SendModelessOperationEnded' , 'operation' , ), 1610743836, (1610743836, (), [ (8, 0, None, None) , ], 1 , 1 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
    (( 'ObjectId32ToObjectIdString' , 'objectId32' , 'idString' , ), 1610743838, (1610743838, (), [ (3, 1, None, None) , 
             (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
    (( 'GetObjectIdString' , 'Object' , 'asHex' , 'idString' , ), 1610743839, (1610743839, (), [ 
             (9, 1, None, None) , (11, 1, None, None) , (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
    (( 'LogMessage' , 'msg' , ), 1610743856, (1610743856, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
]

IOdaAuditInfo_vtables_dispatch_ = 1
IOdaAuditInfo_vtables_ = [
    (( 'numFixes' , 'pVal' , ), 1, (1, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'numErrors' , 'pVal' , ), 2, (2, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'fixErrors' , 'pVal' , ), 3, (3, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
]

IOdaBagFiler_vtables_dispatch_ = 1
IOdaBagFiler_vtables_ = [
    (( 'ObjectToBuffer' , 'pObj' , 'ResType' , 'ResValue' , ), 1, (1, (), [ 
             (9, 1, None, "IID('{153A7BFD-AB55-48D4-81C7-22252D635ECE}')") , (16396, 2, None, None) , (16396, 2, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'BufferToObject' , 'pObj' , 'ResType' , 'ResValue' , ), 2, (2, (), [ 
             (9, 1, None, "IID('{153A7BFD-AB55-48D4-81C7-22252D635ECE}')") , (12, 1, None, None) , (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

IOdaBmpOut_vtables_dispatch_ = 1
IOdaBmpOut_vtables_ = [
    (( 'WriteFile' , 'database' , 'BitmapName' , ), 1, (1, (), [ (9, 1, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Background' , 'pVal' , ), 2, (2, (), [ (16393, 10, None, "IID('{6F2B458D-6232-4085-AA60-BD5E8A967722}')") , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Background' , 'pVal' , ), 2, (2, (), [ (9, 1, None, "IID('{6F2B458D-6232-4085-AA60-BD5E8A967722}')") , ], 1 , 4 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Palette' , 'pVal' , ), 3, (3, (), [ (16396, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Palette' , 'pVal' , ), 3, (3, (), [ (12, 1, None, None) , ], 1 , 4 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'pVal' , ), 4, (4, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Height' , 'pVal' , ), 4, (4, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'pVal' , ), 5, (5, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Width' , 'pVal' , ), 5, (5, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'BitPerPixel' , 'pVal' , ), 6, (6, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'BitPerPixel' , 'pVal' , ), 6, (6, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
]

IOdaConsole_vtables_dispatch_ = 1
IOdaConsole_vtables_ = [
    (( 'PutString' , 'text' , ), 1, (1, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'GetString' , 'bAllowSpaces' , 'result' , ), 2, (2, (), [ (11, 1, None, None) , 
             (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

IOdaDwf3dExport_vtables_dispatch_ = 1
IOdaDwf3dExport_vtables_ = [
    (( 'Export3dDwf' , 'database' , 'FileName' , ), 1, (1, (), [ (9, 1, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Background' , 'pVal' , ), 2, (2, (), [ (16393, 10, None, "IID('{6F2B458D-6232-4085-AA60-BD5E8A967722}')") , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Background' , 'pVal' , ), 2, (2, (), [ (9, 1, None, "IID('{6F2B458D-6232-4085-AA60-BD5E8A967722}')") , ], 1 , 4 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Title' , 'pVal' , ), 3, (3, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Title' , 'pVal' , ), 3, (3, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Palette' , 'pVal' , ), 4, (4, (), [ (16396, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Palette' , 'pVal' , ), 4, (4, (), [ (12, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'xSize' , 'pVal' , ), 5, (5, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'xSize' , 'pVal' , ), 5, (5, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'ySize' , 'pVal' , ), 6, (6, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'ySize' , 'pVal' , ), 6, (6, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
]

IOdaDwfImporter_vtables_dispatch_ = 1
IOdaDwfImporter_vtables_ = [
    (( 'Import' , 'database' , 'FileName' , 'Password' , 'wPaper' , 
             'hPaper' , ), 1, (1, (), [ (9, 1, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , (8, 1, None, None) , (8, 49, "'0'", None) , 
             (5, 49, '297.0', None) , (5, 49, '210.0', None) , ], 1 , 1 , 4 , 0 , 56 , (3, 32, None, None) , 0 , )),
]

IOdaDwfImporter2_vtables_dispatch_ = 1
IOdaDwfImporter2_vtables_ = [
    (( 'Properties' , 'Name' , 'pVal' , ), 2, (2, (), [ (8, 1, None, None) , 
             (16396, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Properties' , 'Name' , 'pVal' , ), 2, (2, (), [ (8, 1, None, None) , 
             (12, 1, None, None) , ], 1 , 4 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Close' , ), 3, (3, (), [ ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
]

IOdaDwfPageData_vtables_dispatch_ = 1
IOdaDwfPageData_vtables_ = [
    (( 'LayoutName' , 'pVal' , ), 1, (1, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Author' , 'pVal' , ), 2, (2, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Author' , 'pVal' , ), 2, (2, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Title' , 'pVal' , ), 3, (3, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'Title' , 'pVal' , ), 3, (3, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Subject' , 'pVal' , ), 4, (4, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Subject' , 'pVal' , ), 4, (4, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Company' , 'pVal' , ), 5, (5, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'Company' , 'pVal' , ), 5, (5, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Comments' , 'pVal' , ), 6, (6, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'Comments' , 'pVal' , ), 6, (6, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'Reviewers' , 'pVal' , ), 7, (7, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'Reviewers' , 'pVal' , ), 7, (7, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'Keywords' , 'pVal' , ), 8, (8, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'Keywords' , 'pVal' , ), 8, (8, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'Description' , 'pVal' , ), 9, (9, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'Description' , 'pVal' , ), 9, (9, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'Copyright' , 'pVal' , ), 10, (10, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'Copyright' , 'pVal' , ), 10, (10, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
]

IOdaDwfTemplate_vtables_dispatch_ = 1
IOdaDwfTemplate_vtables_ = [
    (( 'WriteFile' , 'database' , 'FileName' , 'FileType' , 'version' , 
             ), 1, (1, (), [ (9, 1, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , (8, 1, None, None) , (3, 1, None, None) , (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'AddPage' , 'LayoutName' , 'PageIndex' , ), 2, (2, (), [ (8, 1, None, None) , 
             (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'PageCount' , 'pCount' , ), 3, (3, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'Page' , 'Index' , 'PageData' , ), 4, (4, (), [ (12, 1, None, None) , 
             (16393, 10, None, "IID('{6C2751B5-A21F-46D8-8EBE-59F0A15288D9}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'RemovePage' , 'Index' , ), 5, (5, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'RemoveAllPages' , ), 6, (6, (), [ ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'Background' , 'pVal' , ), 11, (11, (), [ (16393, 10, None, "IID('{6F2B458D-6232-4085-AA60-BD5E8A967722}')") , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'Background' , 'pVal' , ), 11, (11, (), [ (9, 1, None, "IID('{6F2B458D-6232-4085-AA60-BD5E8A967722}')") , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'ExportInvisibleLayers' , 'pVal' , ), 12, (12, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'ExportInvisibleLayers' , 'pVal' , ), 12, (12, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'ForceInitialViewToExtents' , 'pVal' , ), 13, (13, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'ForceInitialViewToExtents' , 'pVal' , ), 13, (13, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'SkipLayerInfo' , 'pVal' , ), 15, (15, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'SkipLayerInfo' , 'pVal' , ), 15, (15, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'SkipNamedViewsInfo' , 'pVal' , ), 16, (16, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'SkipNamedViewsInfo' , 'pVal' , ), 16, (16, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'Password' , 'pVal' , ), 17, (17, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'Password' , 'pVal' , ), 17, (17, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'Publisher' , 'pVal' , ), 18, (18, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'Publisher' , 'pVal' , ), 18, (18, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'WideComments' , 'pVal' , ), 19, (19, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'WideComments' , 'pVal' , ), 19, (19, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'SourceProductName' , 'pVal' , ), 20, (20, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'SourceProductName' , 'pVal' , ), 20, (20, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'Palette' , 'pVal' , ), 21, (21, (), [ (16396, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'Palette' , 'pVal' , ), 21, (21, (), [ (12, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
    (( 'xSize' , 'pVal' , ), 22, (22, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
    (( 'xSize' , 'pVal' , ), 22, (22, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
    (( 'ySize' , 'pVal' , ), 23, (23, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
    (( 'ySize' , 'pVal' , ), 23, (23, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
]

IOdaHostApp_vtables_dispatch_ = 1
IOdaHostApp_vtables_ = [
    (( 'Application' , 'pVal' , ), 1, (1, (), [ (16393, 10, None, "IID('{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}')") , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'BrowseForOpenFileName' , 'rootFolder' , 'fileFilter' , 'bOk' , 'FileName' , 
             ), 2, (2, (), [ (8, 0, None, None) , (8, 0, None, None) , (16395, 0, None, None) , (16392, 0, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'AuditDatabase' , 'pDoc' , 'bFixErrors' , ), 3, (3, (), [ (9, 0, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , 
             (11, 0, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'AuditInfo' , 'pVal' , ), 4, (4, (), [ (16393, 10, None, "IID('{56B202FE-BE71-43B4-B504-1902EDE89644}')") , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'OriginalFileType' , 'pDoc' , 'FileType' , ), 5, (5, (), [ (9, 0, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , 
             (16396, 0, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'Recover' , 'FileName' , 'Password' , 'pDoc' , ), 6, (6, (), [ 
             (8, 1, None, None) , (12, 17, None, None) , (16393, 10, None, "IID('{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}')") , ], 1 , 1 , 4 , 1 , 96 , (3, 0, None, None) , 0 , )),
    (( 'OpenDbPartially' , 'pVal' , ), 7, (7, (), [ (16395, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'OpenDbPartially' , 'pVal' , ), 7, (7, (), [ (11, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
]

IOdaHostApp2_vtables_dispatch_ = 1
IOdaHostApp2_vtables_ = [
    (( 'Console' , 'pVal' , ), 8, (8, (), [ (16393, 10, None, "IID('{9DFDB619-A15D-43CD-92D5-7987D452B9F1}')") , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'Console' , 'pVal' , ), 8, (8, (), [ (9, 1, None, "IID('{9DFDB619-A15D-43CD-92D5-7987D452B9F1}')") , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
]

IOdaSvgExporter_vtables_dispatch_ = 1
IOdaSvgExporter_vtables_ = [
    (( 'Properties' , 'Name' , 'pVal' , ), 2, (2, (), [ (8, 1, None, None) , 
             (16396, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'Properties' , 'Name' , 'pVal' , ), 2, (2, (), [ (8, 1, None, None) , 
             (12, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'Export' , 'database' , 'FilePath' , ), 3, (3, (), [ (9, 1, None, "IID('{236374B2-E248-484D-91D4-C13FA726645D}')") , 
             (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
]

ITransmittalFile_vtables_dispatch_ = 1
ITransmittalFile_vtables_ = [
    (( 'sourcePath' , 'pVal' , ), 1, (1, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'fileExists' , 'pVal' , ), 2, (2, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'version' , 'pVal' , ), 3, (3, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'fileSize' , 'pVal' , ), 4, (4, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'lastModifiedTime' , 'pVal' , ), 5, (5, (), [ (16391, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'FileType' , 'pVal' , ), 7, (7, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'includeInTransmittal' , 'pVal' , ), 8, (8, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'includeInTransmittal' , 'pVal' , ), 8, (8, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'numberOfDependents' , 'pVal' , ), 9, (9, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'numberOfDependees' , 'pVal' , ), 10, (10, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'database' , 'ppDatabase' , ), 11, (11, (), [ (16393, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'getDependent' , 'nIndex' , 'ppFile' , ), 12, (12, (), [ (3, 1, None, None) , 
             (16393, 10, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'getDependee' , 'nIndex' , 'ppFile' , ), 13, (13, (), [ (3, 1, None, None) , 
             (16393, 10, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
]

ITransmittalFilesGraph_vtables_dispatch_ = 1
ITransmittalFilesGraph_vtables_ = [
    (( 'getRoot' , 'ppFile' , ), 1, (1, (), [ (16393, 10, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'addEdge' , 'pTransmitFileFrom' , 'pTransmitFileTo' , ), 2, (2, (), [ (9, 1, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , 
             (9, 1, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'removeEdge' , 'pTransmitFile' , 'pParentFile' , ), 3, (3, (), [ (9, 1, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , 
             (9, 1, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'getNumberOfFiles' , 'bIncludeMissingFiles' , 'bIncludeUnselectedFiles' , 'pnSize' , ), 4, (4, (), [ 
             (3, 1, None, None) , (3, 1, None, None) , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'getAt' , 'nIndex' , 'ppFile' , ), 5, (5, (), [ (3, 1, None, None) , 
             (16393, 10, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'reset' , ), 6, (6, (), [ ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'totalBytes' , 'bIncludedFilesOnly' , 'pVal' , ), 7, (7, (), [ (3, 1, None, None) , 
             (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
]

ITransmittalInfo_vtables_dispatch_ = 1
ITransmittalInfo_vtables_ = [
    (( 'destinationRoot' , 'pVal' , ), 1, (1, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'destinationRoot' , 'pVal' , ), 1, (1, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'saveVersion' , 'pVal' , ), 2, (2, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'saveVersion' , 'pVal' , ), 2, (2, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'preserveSubdirs' , 'pVal' , ), 3, (3, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'preserveSubdirs' , 'pVal' , ), 3, (3, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'defaultOverwriteValue' , 'pVal' , ), 4, (4, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
    (( 'defaultOverwriteValue' , 'pVal' , ), 4, (4, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
    (( 'xrefRelativePath' , 'pVal' , ), 6, (6, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
    (( 'xrefRelativePath' , 'pVal' , ), 6, (6, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
    (( 'imageRelativePath' , 'pVal' , ), 7, (7, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
    (( 'imageRelativePath' , 'pVal' , ), 7, (7, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
    (( 'includeXrefDwg' , 'pVal' , ), 8, (8, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
    (( 'includeXrefDwg' , 'pVal' , ), 8, (8, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
    (( 'includeImageFile' , 'pVal' , ), 9, (9, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
    (( 'includeImageFile' , 'pVal' , ), 9, (9, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
    (( 'includeFontFile' , 'pVal' , ), 10, (10, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
    (( 'includeFontFile' , 'pVal' , ), 10, (10, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
    (( 'includePlotFile' , 'pVal' , ), 11, (11, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
    (( 'includePlotFile' , 'pVal' , ), 11, (11, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
    (( 'relativePath' , 'pVal' , ), 15, (15, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
    (( 'relativePath' , 'pVal' , ), 15, (15, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
    (( 'organizedFolder' , 'pVal' , ), 16, (16, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
    (( 'organizedFolder' , 'pVal' , ), 16, (16, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
    (( 'includeMaterialTextureFile' , 'pVal' , ), 23, (23, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
    (( 'includeMaterialTextureFile' , 'pVal' , ), 23, (23, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
]

ITransmittalOperation_vtables_dispatch_ = 1
ITransmittalOperation_vtables_ = [
    (( 'addFile' , 'bstrFullPath' , 'pIParentFile' , 'bAddedBy3rdParty' , 'ppIAddedFile' , 
             'pRetVal' , ), 1, (1, (), [ (8, 1, None, None) , (9, 1, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , (3, 1, None, None) , 
             (16393, 2, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
    (( 'addToReport' , 'bstrTextToAdd' , 'nIndex' , 'pnIndex' , ), 2, (2, (), [ 
             (8, 1, None, None) , (3, 1, None, None) , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
    (( 'addDrawingFile' , 'fullpathname' , 'ppIAddedFile' , 'pRetVal' , ), 3, (3, (), [ 
             (8, 1, None, None) , (16393, 2, None, "IID('{0A107B59-34CE-4F40-9AF2-26060A3C2099}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
    (( 'createTransmittalPackage' , ), 4, (4, (), [ ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
    (( 'getTransmittalReport' , 'bstrReport' , ), 5, (5, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
    (( 'getTransmittalInfoInterface' , 'ppIInfo' , ), 6, (6, (), [ (16393, 10, None, "IID('{122D84E7-A507-414C-A517-C33B19AF6BA5}')") , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
    (( 'getTransmittalGraphInterface' , 'ppIGraph' , ), 7, (7, (), [ (16393, 10, None, "IID('{DE88EA7C-176A-42C7-BF1A-CFCCDEAB3EDB}')") , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
]

RecordMap = {
}

CLSIDToClassMap = {
    '{7EFB484A-0280-4ED6-A73F-6DBE663DB79D}' : ITransmittalOperation,
    '{0A107B59-34CE-4F40-9AF2-26060A3C2099}' : ITransmittalFile,
    '{122D84E7-A507-414C-A517-C33B19AF6BA5}' : ITransmittalInfo,
    '{DE88EA7C-176A-42C7-BF1A-CFCCDEAB3EDB}' : ITransmittalFilesGraph,
    '{798225D3-984D-471E-84F3-D1EC56FA05EA}' : IAcadMenuGroups,
    '{DF14CB14-CDC6-463F-B71C-356149D1F935}' : IAcadMenuGroup,
    '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}' : IAcadApplication,
    '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}' : IAcadDocument,
    '{445545BB-394E-481A-AC4F-F073E53030E8}' : IAcadPlot,
    '{37E34D42-8CD8-4E25-83BF-80C791AFEADE}' : IAcadSelectionSets,
    '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}' : IAcadSelectionSet,
    '{5046A00A-7C22-4D39-ADE0-FB1AE3709B4D}' : IAcadUtility,
    '{03CE46C1-93A9-4E5C-B7F5-7AC7E2D48948}' : IAcadPreferences,
    '{125FA500-9ABC-4F98-87AD-869AEFA4AD72}' : IAcadPreferencesFiles,
    '{0D71BC3C-9854-4076-BD32-D545259AB752}' : IAcadPreferencesDisplay,
    '{5E24ED87-DC43-4771-B7E6-7FE35C21CAB1}' : IAcadPreferencesOpenSave,
    '{1560A14A-D97B-4B3B-BF95-D0F703723442}' : IAcadPreferencesOutput,
    '{21F2EB66-F27E-40AF-A3F5-7F2E7D6F6AA6}' : IAcadPreferencesPdfOutput,
    '{408546BA-FF59-4AA8-98C5-A1DBA4B730F8}' : IAcadPreferencesSystem,
    '{689AE380-B75C-430E-8A70-D116D8B4FA63}' : IAcadPreferencesUser,
    '{35D9C296-C2E9-4DAB-93CA-4A62F71C9FC1}' : IAcadPreferencesDrafting,
    '{CE512178-E98E-4225-800E-0A29DEE39BCD}' : IAcadPreferencesSelection,
    '{52F0656B-9D63-4C67-ADBF-E9C732ED271B}' : IAcadPreferencesProfiles,
    '{A174CCC8-D19F-421F-8F4E-65C2E4F43167}' : IAcadMenuBar,
    '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}' : IAcadPopupMenu,
    '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}' : IAcadPopupMenuItem,
    '{CFFD1390-466A-49D9-9EE0-1884E930DFF9}' : IAcadDocuments,
    '{C2016470-443B-40D0-AD93-231ACFDCF594}' : IAcadState,
    '{3305CB53-F955-41F3-A47B-B7AA53B22D48}' : IAcadPopupMenus,
    '{F7DF12AA-4EF4-4EEE-8D00-68BB80D7F092}' : IAcadToolbars,
    '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}' : IAcadToolbar,
    '{EBCED992-0BB7-4165-B4D6-44261F377565}' : IAcadToolbarItem,
    '{65CDCC9F-F651-4DC4-A361-A8307F08AEE3}' : IAcadLayerStateManager,
    '{A058E098-4DCF-4E3B-93BC-EF0FA19B718A}' : IAcadSecurityParams,
    '{8F2A46C2-4D8A-46D5-8BBE-B06A4027BE10}' : IOdaDwfTemplate,
    '{6C2751B5-A21F-46D8-8EBE-59F0A15288D9}' : IOdaDwfPageData,
    '{C5631279-833D-4FE0-8965-B06E2FEC0E9C}' : IOdaDwfImporter,
    '{7E8D21F1-6343-4CCC-9F7D-0B270A05DC12}' : IOdaDwfImporter2,
    '{FDAF1115-5A20-4D16-A509-01012B71E4F7}' : IOdaSvgExporter,
    '{56B202FE-BE71-43B4-B504-1902EDE89644}' : IOdaAuditInfo,
    '{11C4F7AA-D8CC-4762-8C7C-3064E65EEDBD}' : IOdaBmpOut,
    '{4E99C4A8-AFC0-45E9-B312-61D7DB4F2EE6}' : IOdaDwf3dExport,
    '{9A61E0FC-4311-457B-8C65-2AD3531DC5DD}' : TransmittalOperation,
    '{658E0EA9-97D8-4D44-AFF0-A0F01094750D}' : TransmittalFilesGraph,
    '{D944169D-A83B-4A9E-B543-5C66F52E3D35}' : TransmittalFile,
    '{AD47B265-C3D5-437C-AA75-527C7A7793C6}' : TransmittalInfo,
    '{FE3FC546-AF40-4A2E-9C5C-14B7B4B8A54D}' : AcadMenuGroups,
    '{A07E5142-51E0-441E-B442-1F46F53F3888}' : AcadMenuGroup,
    '{DE927728-3684-4835-8255-54350D951307}' : AcadMenuBar,
    '{18B24243-321E-4980-9351-57C02F246EC9}' : AcadPopupMenus,
    '{62AB6B80-D12D-40C8-8970-9915E69E05E0}' : AcadPopupMenu,
    '{E24D7979-088A-435B-B939-D8E18AD4BE1D}' : AcadPopupMenuItem,
    '{6625C943-4F9E-4FCD-B847-454FCDC56C19}' : AcadToolbars,
    '{A8D0AE76-640B-44AA-BB5C-6986706CA9F6}' : AcadToolbar,
    '{C9F46D28-7AEE-48F1-B8B7-6F8E7EC40625}' : AcadToolbarItem,
    '{93E291E9-BB72-429B-B4DE-DF76B88603EB}' : _DAcadApplicationEvents,
    '{63A90E32-CB8B-4A3B-ADFF-EF94A35278B2}' : _DAcadDocumentEvents,
    '{E789E253-BEDC-44FF-B228-AD3A17D9AB3A}' : IOdaHostApp,
    '{9DFDB619-A15D-43CD-92D5-7987D452B9F1}' : IOdaConsole,
    '{CFE29DD1-2A1B-49F9-853E-11918A789C6D}' : IOdaHostApp2,
    '{6EBA6B5A-1D9F-4B21-BC0B-35EFDBAB543D}' : IOdaBagFiler,
    '{61F2A9AB-8A44-4C20-953A-735508C1CA85}' : AcPePropertyEditorColor,
    '{4B61C84D-A730-4760-A409-4023DD1D8E57}' : AcPePropertyEditorTextStyle,
    '{8C9F3B98-30E9-45CE-9F07-63955326E8D4}' : AcPePropertyEditorLType,
    '{96F57653-F913-4CAB-B511-2F14AF9138D3}' : AcPePropertyEditorLayer,
    '{4F19983F-AB24-4FB9-ADC0-0B6026080239}' : AcPePropertyEditorLWeight,
    '{7507B465-281A-465C-A724-A72D09327153}' : AcPePropertyEditorEllipses,
    '{4735C83D-5F58-4963-8571-A4424C619D7F}' : AcPePick2PointsCtrl,
    '{0E86524E-1812-426A-9A63-2C2B51B0D0E4}' : AcadApplication,
    '{5F5D38B7-C56C-4250-B088-2B06EEEC1EE9}' : AcadDocuments,
    '{3975E80C-5EC5-4EE0-B432-E9EC7BBB9A5A}' : AcadDocument,
    '{5FA75E80-D112-4186-AD8E-0992D7F13475}' : _IOdaHostAppEvents,
    '{D81CF9E5-4C85-435B-876B-C706E2D5F00E}' : OdaHostApp,
    '{AB480185-F159-4B5D-BC9E-AEA9AB722DF1}' : AcadUtility,
    '{A3EAF524-D893-4F6F-8D07-7F9416F7EBB9}' : AcadPreferences,
    '{354D8744-81E2-4BB0-AC00-2C2471F3BEBE}' : AcadPreferencesFiles,
    '{100E11DA-6700-452D-B6BE-0B65FDB2E17A}' : AcadPreferencesDisplay,
    '{E21FACEF-E6A4-4DE1-8315-7F0F07EB877E}' : AcadPreferencesOpenSave,
    '{46B6BEE0-DA5A-4089-AC8A-70A254F31659}' : AcadPreferencesOutput,
    '{CB5F57D2-535C-4550-BDAC-FBFDB8778294}' : AcadPreferencesPdfOutput,
    '{8A48E79C-D378-4111-82D9-A25F84F5B6DC}' : AcadPreferencesSystem,
    '{DD509194-682F-49FE-9984-C7F0EE819A45}' : AcadPreferencesUser,
    '{F6B948E8-500C-4305-A2EA-71FA28A35530}' : AcadPreferencesDrafting,
    '{469FB7EC-09CF-4D1D-BAC8-4553F5098ADD}' : AcadPreferencesSelection,
    '{71AE8036-20F2-4439-BF71-F27400E3291D}' : AcadPreferencesProfiles,
    '{5696C1B9-643B-4E6E-B711-DB897137424E}' : AcadState,
    '{F3862E27-3753-44F7-BDB0-24468C8E8CF6}' : AcadSelectionSet,
    '{2F021E6D-67B2-4955-9135-A28F93BCEE6D}' : AcadSelectionSets,
    '{126D4FCB-3E3D-491B-9F0B-D6C9D362116A}' : AcadPlot,
    '{81186CAF-6BAC-4DD6-B470-3C7930A28DD5}' : OdaDwfTemplate,
    '{7CCF62DE-076C-4ED9-9ED2-3D4A5AC9E4DE}' : OdaDwf3dExport,
    '{46901A1D-C99C-45E0-B2F5-D99C07CD8BBB}' : OdaDwfImporter,
    '{2F38A4F0-DDE8-488C-B53C-5E364C267B53}' : AcadLayerStateManager,
    '{06F4FD5D-DBD9-4B44-B464-6683CC541EDD}' : AcadSecurityParams,
    '{C0F35882-6A8B-426C-8787-001E1073197A}' : OdaSvgExporter,
    '{97B88F76-4023-412F-8C23-607C526E4E7D}' : OdaBmpOut,
    '{DF962AF5-E3C8-4552-B65D-698F48DE2759}' : OdaBagFiler,
}
CLSIDToPackageMap = {}
win32com.client.CLSIDToClass.RegisterCLSIDsFromDict( CLSIDToClassMap )
VTablesToPackageMap = {}
VTablesToClassMap = {
    '{7EFB484A-0280-4ED6-A73F-6DBE663DB79D}' : 'ITransmittalOperation',
    '{0A107B59-34CE-4F40-9AF2-26060A3C2099}' : 'ITransmittalFile',
    '{122D84E7-A507-414C-A517-C33B19AF6BA5}' : 'ITransmittalInfo',
    '{DE88EA7C-176A-42C7-BF1A-CFCCDEAB3EDB}' : 'ITransmittalFilesGraph',
    '{798225D3-984D-471E-84F3-D1EC56FA05EA}' : 'IAcadMenuGroups',
    '{DF14CB14-CDC6-463F-B71C-356149D1F935}' : 'IAcadMenuGroup',
    '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}' : 'IAcadApplication',
    '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}' : 'IAcadDocument',
    '{445545BB-394E-481A-AC4F-F073E53030E8}' : 'IAcadPlot',
    '{37E34D42-8CD8-4E25-83BF-80C791AFEADE}' : 'IAcadSelectionSets',
    '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}' : 'IAcadSelectionSet',
    '{5046A00A-7C22-4D39-ADE0-FB1AE3709B4D}' : 'IAcadUtility',
    '{03CE46C1-93A9-4E5C-B7F5-7AC7E2D48948}' : 'IAcadPreferences',
    '{125FA500-9ABC-4F98-87AD-869AEFA4AD72}' : 'IAcadPreferencesFiles',
    '{0D71BC3C-9854-4076-BD32-D545259AB752}' : 'IAcadPreferencesDisplay',
    '{5E24ED87-DC43-4771-B7E6-7FE35C21CAB1}' : 'IAcadPreferencesOpenSave',
    '{1560A14A-D97B-4B3B-BF95-D0F703723442}' : 'IAcadPreferencesOutput',
    '{21F2EB66-F27E-40AF-A3F5-7F2E7D6F6AA6}' : 'IAcadPreferencesPdfOutput',
    '{408546BA-FF59-4AA8-98C5-A1DBA4B730F8}' : 'IAcadPreferencesSystem',
    '{689AE380-B75C-430E-8A70-D116D8B4FA63}' : 'IAcadPreferencesUser',
    '{35D9C296-C2E9-4DAB-93CA-4A62F71C9FC1}' : 'IAcadPreferencesDrafting',
    '{CE512178-E98E-4225-800E-0A29DEE39BCD}' : 'IAcadPreferencesSelection',
    '{52F0656B-9D63-4C67-ADBF-E9C732ED271B}' : 'IAcadPreferencesProfiles',
    '{A174CCC8-D19F-421F-8F4E-65C2E4F43167}' : 'IAcadMenuBar',
    '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}' : 'IAcadPopupMenu',
    '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}' : 'IAcadPopupMenuItem',
    '{CFFD1390-466A-49D9-9EE0-1884E930DFF9}' : 'IAcadDocuments',
    '{C2016470-443B-40D0-AD93-231ACFDCF594}' : 'IAcadState',
    '{3305CB53-F955-41F3-A47B-B7AA53B22D48}' : 'IAcadPopupMenus',
    '{F7DF12AA-4EF4-4EEE-8D00-68BB80D7F092}' : 'IAcadToolbars',
    '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}' : 'IAcadToolbar',
    '{EBCED992-0BB7-4165-B4D6-44261F377565}' : 'IAcadToolbarItem',
    '{65CDCC9F-F651-4DC4-A361-A8307F08AEE3}' : 'IAcadLayerStateManager',
    '{A058E098-4DCF-4E3B-93BC-EF0FA19B718A}' : 'IAcadSecurityParams',
    '{8F2A46C2-4D8A-46D5-8BBE-B06A4027BE10}' : 'IOdaDwfTemplate',
    '{6C2751B5-A21F-46D8-8EBE-59F0A15288D9}' : 'IOdaDwfPageData',
    '{C5631279-833D-4FE0-8965-B06E2FEC0E9C}' : 'IOdaDwfImporter',
    '{7E8D21F1-6343-4CCC-9F7D-0B270A05DC12}' : 'IOdaDwfImporter2',
    '{FDAF1115-5A20-4D16-A509-01012B71E4F7}' : 'IOdaSvgExporter',
    '{56B202FE-BE71-43B4-B504-1902EDE89644}' : 'IOdaAuditInfo',
    '{11C4F7AA-D8CC-4762-8C7C-3064E65EEDBD}' : 'IOdaBmpOut',
    '{4E99C4A8-AFC0-45E9-B312-61D7DB4F2EE6}' : 'IOdaDwf3dExport',
    '{E789E253-BEDC-44FF-B228-AD3A17D9AB3A}' : 'IOdaHostApp',
    '{9DFDB619-A15D-43CD-92D5-7987D452B9F1}' : 'IOdaConsole',
    '{CFE29DD1-2A1B-49F9-853E-11918A789C6D}' : 'IOdaHostApp2',
    '{6EBA6B5A-1D9F-4B21-BC0B-35EFDBAB543D}' : 'IOdaBagFiler',
}


NamesToIIDMap = {
    'ITransmittalOperation' : '{7EFB484A-0280-4ED6-A73F-6DBE663DB79D}',
    'ITransmittalFile' : '{0A107B59-34CE-4F40-9AF2-26060A3C2099}',
    'ITransmittalInfo' : '{122D84E7-A507-414C-A517-C33B19AF6BA5}',
    'ITransmittalFilesGraph' : '{DE88EA7C-176A-42C7-BF1A-CFCCDEAB3EDB}',
    'IAcadMenuGroups' : '{798225D3-984D-471E-84F3-D1EC56FA05EA}',
    'IAcadMenuGroup' : '{DF14CB14-CDC6-463F-B71C-356149D1F935}',
    'IAcadApplication' : '{D48F17B7-773E-4238-A6C6-B2BBEBAA9A1E}',
    'IAcadDocument' : '{5896DFEB-2488-49F7-8A9D-CF0DEA5AC6FB}',
    'IAcadPlot' : '{445545BB-394E-481A-AC4F-F073E53030E8}',
    'IAcadSelectionSets' : '{37E34D42-8CD8-4E25-83BF-80C791AFEADE}',
    'IAcadSelectionSet' : '{01374CB7-5D3B-4556-800C-9BFC71BBEC42}',
    'IAcadUtility' : '{5046A00A-7C22-4D39-ADE0-FB1AE3709B4D}',
    'IAcadPreferences' : '{03CE46C1-93A9-4E5C-B7F5-7AC7E2D48948}',
    'IAcadPreferencesFiles' : '{125FA500-9ABC-4F98-87AD-869AEFA4AD72}',
    'IAcadPreferencesDisplay' : '{0D71BC3C-9854-4076-BD32-D545259AB752}',
    'IAcadPreferencesOpenSave' : '{5E24ED87-DC43-4771-B7E6-7FE35C21CAB1}',
    'IAcadPreferencesOutput' : '{1560A14A-D97B-4B3B-BF95-D0F703723442}',
    'IAcadPreferencesPdfOutput' : '{21F2EB66-F27E-40AF-A3F5-7F2E7D6F6AA6}',
    'IAcadPreferencesSystem' : '{408546BA-FF59-4AA8-98C5-A1DBA4B730F8}',
    'IAcadPreferencesUser' : '{689AE380-B75C-430E-8A70-D116D8B4FA63}',
    'IAcadPreferencesDrafting' : '{35D9C296-C2E9-4DAB-93CA-4A62F71C9FC1}',
    'IAcadPreferencesSelection' : '{CE512178-E98E-4225-800E-0A29DEE39BCD}',
    'IAcadPreferencesProfiles' : '{52F0656B-9D63-4C67-ADBF-E9C732ED271B}',
    'IAcadMenuBar' : '{A174CCC8-D19F-421F-8F4E-65C2E4F43167}',
    'IAcadPopupMenu' : '{E63FD651-4B1B-40BE-B7FA-CBAE74D97FE5}',
    'IAcadPopupMenuItem' : '{5B5C5A15-81D2-4360-937A-4F2FA18FB266}',
    'IAcadDocuments' : '{CFFD1390-466A-49D9-9EE0-1884E930DFF9}',
    'IAcadState' : '{C2016470-443B-40D0-AD93-231ACFDCF594}',
    'IAcadPopupMenus' : '{3305CB53-F955-41F3-A47B-B7AA53B22D48}',
    'IAcadToolbars' : '{F7DF12AA-4EF4-4EEE-8D00-68BB80D7F092}',
    'IAcadToolbar' : '{618F1FE3-4CF9-41D4-A070-387C8560D4EC}',
    'IAcadToolbarItem' : '{EBCED992-0BB7-4165-B4D6-44261F377565}',
    'IAcadLayerStateManager' : '{65CDCC9F-F651-4DC4-A361-A8307F08AEE3}',
    'IAcadSecurityParams' : '{A058E098-4DCF-4E3B-93BC-EF0FA19B718A}',
    'IOdaDwfTemplate' : '{8F2A46C2-4D8A-46D5-8BBE-B06A4027BE10}',
    'IOdaDwfPageData' : '{6C2751B5-A21F-46D8-8EBE-59F0A15288D9}',
    'IOdaDwfImporter' : '{C5631279-833D-4FE0-8965-B06E2FEC0E9C}',
    'IOdaDwfImporter2' : '{7E8D21F1-6343-4CCC-9F7D-0B270A05DC12}',
    'IOdaSvgExporter' : '{FDAF1115-5A20-4D16-A509-01012B71E4F7}',
    'IOdaAuditInfo' : '{56B202FE-BE71-43B4-B504-1902EDE89644}',
    'IOdaBmpOut' : '{11C4F7AA-D8CC-4762-8C7C-3064E65EEDBD}',
    'IOdaDwf3dExport' : '{4E99C4A8-AFC0-45E9-B312-61D7DB4F2EE6}',
    '_DAcadApplicationEvents' : '{93E291E9-BB72-429B-B4DE-DF76B88603EB}',
    '_DAcadDocumentEvents' : '{63A90E32-CB8B-4A3B-ADFF-EF94A35278B2}',
    'IOdaHostApp' : '{E789E253-BEDC-44FF-B228-AD3A17D9AB3A}',
    'IOdaConsole' : '{9DFDB619-A15D-43CD-92D5-7987D452B9F1}',
    'IOdaHostApp2' : '{CFE29DD1-2A1B-49F9-853E-11918A789C6D}',
    'IOdaBagFiler' : '{6EBA6B5A-1D9F-4B21-BC0B-35EFDBAB543D}',
    '_IOdaHostAppEvents' : '{5FA75E80-D112-4186-AD8E-0992D7F13475}',
}

win32com.client.constants.__dicts__.append(constants.__dict__)


def getApp() -> IAcadApplication:
    id = AcadApplication.CLSID
    return  win32com.client.Dispatch(id)

def createEventObject(obj, eventclass):
    win32com.client.WithEvents(obj,eventclass)
