# -*- coding: mbcs -*-
# Created by makepy.py version 0.5.01
# By python version 3.10.10 (tags/v3.10.10:aad5f6a, Feb  7 2023, 17:20:36) [MSC v.1929 64 bit (AMD64)]
# From type library 'acsmcomponents24.tlb'
# On Thu Oct  5 13:00:12 2023
'AcSmComponents24 1.0 Type Library'
makepy_version = '0.5.01'
python_version = 0x30a0af0

import win32com.client.CLSIDToClass, pythoncom, pywintypes
import win32com.client.util
from pywintypes import IID
from win32com.client import Dispatch

# The following 3 lines may need tweaking for the particular server
# Candidates are pythoncom.Missing, .Empty and .ArgNotFound
defaultNamedOptArg=pythoncom.Empty
defaultNamedNotOptArg=pythoncom.Empty
defaultUnnamedArg=pythoncom.Empty

CLSID = IID('{7CC328B4-EB05-4611-B602-D23EAEAD2B2E}')
MajorVersion = 1
MinorVersion = 0
LibraryFlags = 8
LCID = 0x0

class constants:
	AcSmLockStatus_Locked_AccessDenied=16         # from enum AcSmLockStatus
	AcSmLockStatus_Locked_Local   =1          # from enum AcSmLockStatus
	AcSmLockStatus_Locked_NotConnected=8          # from enum AcSmLockStatus
	AcSmLockStatus_Locked_ReadOnly=4          # from enum AcSmLockStatus
	AcSmLockStatus_Locked_Remote  =2          # from enum AcSmLockStatus
	AcSmLockStatus_UnLocked       =0          # from enum AcSmLockStatus
	AcSmObjectReference_HardPointer=2          # from enum AcSmObjectReferenceFlags
	AcSmObjectReference_SoftPointer=1          # from enum AcSmObjectReferenceFlags
	FileActionAdded               =1          # from enum FileNotifyAction
	FileActionModified            =3          # from enum FileNotifyAction
	FileActionRemoved             =2          # from enum FileNotifyAction
	FileActionRenamedNewName      =5          # from enum FileNotifyAction
	FileActionRenamedOldName      =4          # from enum FileNotifyAction
	FileNotifyChangeAttributes    =4          # from enum FileNotifyFlags
	FileNotifyChangeCreation      =64         # from enum FileNotifyFlags
	FileNotifyChangeDirName       =2          # from enum FileNotifyFlags
	FileNotifyChangeFileName      =1          # from enum FileNotifyFlags
	FileNotifyChangeLastAccess    =32         # from enum FileNotifyFlags
	FileNotifyChangeLastWrite     =16         # from enum FileNotifyFlags
	FileNotifyChangeSecurity      =256        # from enum FileNotifyFlags
	FileNotifyChangeSize          =8          # from enum FileNotifyFlags
	FileNotifyChangeSizeOrDate    =24         # from enum FileNotifyFlags
	FileNotifyDefault             =89         # from enum FileNotifyFlags
	ACSM_DATABASE_CHANGED         =21         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_CREATED         =15         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_INITNEW_BEGIN   =22         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_INITNEW_COMPLETE=24         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_INITNEW_FAILED  =23         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_IS_CLOSING      =17         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_LOAD_BEGIN      =25         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_LOAD_COMPLETE   =27         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_LOAD_FAILED     =26         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_LOCKED          =19         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_OPENED          =16         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_UNLOCKED        =20         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	ACSM_DATABASE_WATCH_ERROR     =18         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	CALLOUT_BLOCK_ADDED           =12         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	CALLOUT_BLOCK_DELETED         =13         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	MODEL_RESOURCE_ADDED          =10         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	MODEL_RESOURCE_DELETED        =11         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEETS_RENUMBERED             =14         # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_ADDED                   =0          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_DELETED                 =1          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_SELECTION_SET_CREATED   =4          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_SELECTION_SET_DELETED   =5          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_SUBSET_CREATED          =2          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_SUBSET_DELETED          =3          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_VIEW_CATEGORY_CREATED   =8          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_VIEW_CATEGORY_DELETED   =9          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_VIEW_CREATED            =6          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	SHEET_VIEW_DELETED            =7          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0009_0001
	CUSTOM_SHEETSET_PROP          =1          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0012_0001
	CUSTOM_SHEET_PROP             =2          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0012_0001
	CUSTOM_SUBSET_PROP            =4          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0012_0001
	EMPTY                         =0          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0012_0001
	IS_CHILD                      =8          # from enum __MIDL___MIDL_itf_AcSmComponents_0000_0012_0001

from win32com.client import CoClassBaseClass
# This CoClass is known by the name 'AcSmComponents.AcSmAcDbBlockRecordReference.24'
class AcSmAcDbBlockRecordReference(CoClassBaseClass): # A CoClass
	# Refers to a block table record within a dwg.
	CLSID = IID('{F2D3E572-5C41-415C-9CDD-5A4457F82263}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmAcDbDatabase.24'
class AcSmAcDbDatabase(CoClassBaseClass): # A CoClass
	# AcDbDatabase Wrapper.
	CLSID = IID('{4DD54885-C28D-4EF2-9CC1-CBC0189C73B4}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmAcDbLayoutReference.24'
class AcSmAcDbLayoutReference(CoClassBaseClass): # A CoClass
	# Refers to a layout within a dwg.
	CLSID = IID('{519093BC-CC09-4DBC-96C1-351AFA3484F5}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmAcDbObjectReference.24'
class AcSmAcDbObjectReference(CoClassBaseClass): # A CoClass
	# AcDbObject reference component.
	CLSID = IID('{0FF37EB8-721B-49ED-B404-21C6CFE38FC6}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmAcDbViewReference.24'
class AcSmAcDbViewReference(CoClassBaseClass): # A CoClass
	# Refers to a view within a dwg.
	CLSID = IID('{73A964AA-FB49-4B40-BDF3-1F8C52D830A3}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmCalloutBlockReferences.24'
class AcSmCalloutBlockReferences(CoClassBaseClass): # A CoClass
	# Callout block references collection.
	CLSID = IID('{27D14C8A-CD7E-4829-A185-6763A26F1474}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmCalloutBlocks.24'
class AcSmCalloutBlocks(CoClassBaseClass): # A CoClass
	# Callout blocks collection.
	CLSID = IID('{8DA06B57-6348-41FB-9731-E06A655EE15D}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmCustomPropertyBag.24'
class AcSmCustomPropertyBag(CoClassBaseClass): # A CoClass
	# Custom property bag component.
	CLSID = IID('{3D3C7AFB-DB98-4C7E-BE9C-66558A744966}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmCustomPropertyValue.24'
class AcSmCustomPropertyValue(CoClassBaseClass): # A CoClass
	# Custom property value object.
	CLSID = IID('{F1D59B7B-988B-4D30-9157-FF3A0D784093}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmDSTFiler.24'
class AcSmDSTFiler(CoClassBaseClass): # A CoClass
	# IAcSmFiler implementation for DST files.
	CLSID = IID('{5EC19FD3-79AB-4C05-9100-E3636F7676A2}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmDatabase.24'
class AcSmDatabase(CoClassBaseClass): # A CoClass
	# Database component.
	CLSID = IID('{3CE9998D-84A9-4E80-A9D4-94F612E0F4DA}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmFileReference.24'
class AcSmFileReference(CoClassBaseClass): # A CoClass
	# File reference component.
	CLSID = IID('{3B79C4C3-1CFB-42DD-AD98-47AFB9BC66C8}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmFileWatchReactor.24'
class AcSmFileWatchReactor(CoClassBaseClass): # A CoClass
	CLSID = IID('{2942ED61-730D-40BD-A7F9-11A9DC3AE351}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmNamedAcDbObjectReference.24'
class AcSmNamedAcDbObjectReference(CoClassBaseClass): # A CoClass
	# Named AcDbObject reference component.
	CLSID = IID('{F452DF8B-685B-4AC8-9A61-4D3FC6C36D85}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmObjectReference.24'
class AcSmObjectReference(CoClassBaseClass): # A CoClass
	# Object reference component.
	CLSID = IID('{5612BEDD-91A0-4552-BB68-B3E183DD62C3}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmPersistImpl_Internal.24'
class AcSmPersistImpl(CoClassBaseClass): # A CoClass
	CLSID = IID('{729D33D4-09FD-439F-B86C-2E127707A3C0}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmPersistProxy.24'
class AcSmPersistProxy(CoClassBaseClass): # A CoClass
	# Proxy component.
	CLSID = IID('{04E7D784-04AC-42E6-B289-98AFC9F56400}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmProjectPointLocation.24'
class AcSmProjectPointLocation(CoClassBaseClass): # A CoClass
	CLSID = IID('{2F666CD5-91F5-4467-B9C3-6B14E0633D18}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmProjectPointLocations.24'
class AcSmProjectPointLocations(CoClassBaseClass): # A CoClass
	CLSID = IID('{C3E338CA-20EE-4C48-869F-5BF434AD40D0}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmPublishOptions.24'
class AcSmPublishOptions(CoClassBaseClass): # A CoClass
	# Sheet set publish options object.
	CLSID = IID('{A3477229-7C55-4156-9A3F-49703D2F7EA3}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmResources.24'
class AcSmResources(CoClassBaseClass): # A CoClass
	# Resources collection.
	CLSID = IID('{FD5A339E-D976-4522-B8BA-5ACB06D2E8A7}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheet.24'
class AcSmSheet(CoClassBaseClass): # A CoClass
	# Sheet component.
	CLSID = IID('{3A810C7C-1F9A-47E6-AC67-88BF2D094453}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheetSelSet.24'
class AcSmSheetSelSet(CoClassBaseClass): # A CoClass
	# Selection set component.
	CLSID = IID('{83A10BEA-7DAB-4BC3-A038-531C8B3BC4D7}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheetSelSets.24'
class AcSmSheetSelSets(CoClassBaseClass): # A CoClass
	# Selection sets collection.
	CLSID = IID('{70A89F90-AC01-4011-B390-9104BE54A608}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheetSet.24'
class AcSmSheetSet(CoClassBaseClass): # A CoClass
	# Sheet set component.
	CLSID = IID('{14DA1BFA-BB31-4EC6-8AE7-1F0C2514D2D6}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheetSetMgr.24'
class AcSmSheetSetMgr(CoClassBaseClass): # A CoClass
	# Sheet set manager object.
	CLSID = IID('{1C3AEBB1-823D-4831-980F-C1481311B3A0}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheetView.24'
class AcSmSheetView(CoClassBaseClass): # A CoClass
	# Sheet view component.
	CLSID = IID('{54DD1BD6-BD8D-425A-934C-2121C901AC93}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSheetViews.24'
class AcSmSheetViews(CoClassBaseClass): # A CoClass
	# Sheet views collection.
	CLSID = IID('{B4D3F171-77E9-412C-A907-67EDA512DBDE}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSimpleFileReferece.24'
class AcSmSimpleFileReference(CoClassBaseClass): # A CoClass
	CLSID = IID('{62052FD8-7637-4F33-BB23-1C622E305506}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmSubset.24'
class AcSmSubset(CoClassBaseClass): # A CoClass
	# Subset component.
	CLSID = IID('{F8DFC187-DEE9-4BF9-945A-9897D60F6042}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmViewCategories.24'
class AcSmViewCategories(CoClassBaseClass): # A CoClass
	# View categories collection.
	CLSID = IID('{BD989BC7-F8EC-4570-A45E-0C92D6354AB8}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.AcSmViewCategory.24'
class AcSmViewCategory(CoClassBaseClass): # A CoClass
	# View category component.
	CLSID = IID('{FB00D547-2AAE-453C-BF36-4E353F46947D}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

# This CoClass is known by the name 'AcSmComponents.NameValueMap.24'
class NameValueMap(CoClassBaseClass): # A CoClass
	# NameValueMap Class
	CLSID = IID('{7A3E83C6-BFB8-46E6-98C5-8282C7F3A084}')
	coclass_sources = [
	]
	coclass_interfaces = [
	]

IAcSmAcDbBlockRecordReference_vtables_dispatch_ = 0
IAcSmAcDbBlockRecordReference_vtables_ = [
]

IAcSmAcDbDatabase_vtables_dispatch_ = 0
IAcSmAcDbDatabase_vtables_ = [
	(( 'GetIAcadDatabase' , 'pIAcadDatabase' , ), 1610678272, (1610678272, (), [ (16393, 10, None, "IID('{3280D375-1DE4-4DA2-89EE-591E860056DC}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'GetAcDbDatabase' , 'ppAcDbDatabase' , ), 1610678273, (1610678273, (), [ (16408, 10, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmAcDbLayoutReference_vtables_dispatch_ = 0
IAcSmAcDbLayoutReference_vtables_ = [
]

IAcSmAcDbObjectReference_vtables_dispatch_ = 0
IAcSmAcDbObjectReference_vtables_ = [
	(( 'SetAcDbHandle' , 'handle' , ), 1610809344, (1610809344, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'GetAcDbHandle' , 'phandle' , ), 1610809345, (1610809345, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
	(( 'GetAcSmAcDbDatabase' , 'ppAcSmAcDbDatabase' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{FFA44922-263E-4EF5-AC5C-17D45E34C856}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'SetAcDbObject' , 'pAcDbObject' , ), 1610809347, (1610809347, (), [ (9, 1, None, "IID('{C932C340-CE5D-442A-BC19-D35997549D4A}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'ResolveAcDbObject' , 'pAcDbDatabase' , 'phandle' , ), 1610809348, (1610809348, (), [ (9, 1, None, "IID('{3280D375-1DE4-4DA2-89EE-591E860056DC}')") , 
			 (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcSmAcDbViewReference_vtables_dispatch_ = 0
IAcSmAcDbViewReference_vtables_ = [
]

IAcSmCalloutBlocks_vtables_dispatch_ = 0
IAcSmCalloutBlocks_vtables_ = [
	(( 'Add' , 'pBlkRef' , ), 1610809344, (1610809344, (), [ (13, 1, None, "IID('{90D38457-4C19-4E05-A51E-3B8CF4252347}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'Remove' , 'pBlkRef' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{90D38457-4C19-4E05-A51E-3B8CF4252347}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetEnumerator' , 'enumerator' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{69520E4B-34A4-4E5F-A1A4-69362E818751}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcSmComponent_vtables_dispatch_ = 0
IAcSmComponent_vtables_ = [
	(( 'GetName' , 'name' , ), 1610743808, (1610743808, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'SetName' , 'name' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetDesc' , 'desc' , ), 1610743810, (1610743810, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'SetDesc' , 'desc' , ), 1610743811, (1610743811, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'GetCustomPropertyBag' , 'bag' , ), 1610743812, (1610743812, (), [ (16397, 10, None, "IID('{C263658F-EC23-4B2B-9AD1-5D591302589F}')") , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
]

IAcSmCustomPropertyBag_vtables_dispatch_ = 0
IAcSmCustomPropertyBag_vtables_ = [
	(( 'GetProperty' , 'name' , 'value' , ), 1610743808, (1610743808, (), [ (8, 1, None, None) , 
			 (16397, 10, None, "IID('{1D9EF28C-01EF-49CB-AFBF-4A26EABC4728}')") , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'SetProperty' , 'name' , 'value' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , 
			 (13, 1, None, "IID('{1D9EF28C-01EF-49CB-AFBF-4A26EABC4728}')") , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetPropertyEnumerator' , 'enumerator' , ), 1610743810, (1610743810, (), [ (16397, 10, None, "IID('{2EC24760-C507-4504-A035-90FE8A07E476}')") , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
]

IAcSmCustomPropertyValue_vtables_dispatch_ = 0
IAcSmCustomPropertyValue_vtables_ = [
	(( 'GetValue' , 'value' , ), 1610743808, (1610743808, (), [ (16396, 10, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'SetValue' , 'value' , ), 1610743809, (1610743809, (), [ (12, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetFlags' , 'value' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'SetFlags' , 'value' , ), 1610743811, (1610743811, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
]

IAcSmDatabase_vtables_dispatch_ = 0
IAcSmDatabase_vtables_ = [
	(( 'LoadFromFile' , 'templateDstFileName' , ), 1610809344, (1610809344, (), [ (8, 49, "'0'", None) , ], 1 , 1 , 4 , 0 , 160 , (3, 32, None, None) , 0 , )),
	(( 'GetFileName' , 'pVal' , ), 1610809345, (1610809345, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'SetFileName' , 'newVal' , ), 1610809346, (1610809346, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'GetTemplateDstFileName' , 'filename' , ), 1610809347, (1610809347, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'GetSheetSet' , 'pVal' , ), 1610809348, (1610809348, (), [ (16397, 10, None, "IID('{85AF8C40-BF76-4966-917A-B34739C5FFF3}')") , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'LockDb' , 'pObject' , ), 1610809349, (1610809349, (), [ (13, 1, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
	(( 'UnlockDb' , 'pObject' , 'bCommit' , ), 1610809350, (1610809350, (), [ (13, 1, None, None) , 
			 (11, 49, 'True', None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
	(( 'GetLockStatus' , 'pLockStatus' , ), 1610809351, (1610809351, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
	(( 'GetLockOwnerInfo' , 'pstrUserName' , 'pstrMachineName' , ), 1610809352, (1610809352, (), [ (16392, 2, None, None) , 
			 (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
	(( 'GetNewObjectId' , 'hand' , 'idcookie' , 'ppId' , ), 1610809353, (1610809353, (), [ 
			 (8, 1, None, None) , (16387, 2, None, None) , (16397, 10, None, "IID('{A1265F77-7F04-4C4D-91CF-740404156AB0}')") , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
	(( 'RegisterOwner' , 'idcookie' , 'pObject' , 'pOwner' , ), 1610809354, (1610809354, (), [ 
			 (3, 1, None, None) , (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
	(( 'GetEnumerator' , 'ppEnum' , ), 1610809355, (1610809355, (), [ (16397, 10, None, "IID('{8754C99A-C73A-4B82-9899-BE5965905042}')") , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
	(( 'Register' , 'eventHandler' , 'cookie' , ), 1610809356, (1610809356, (), [ (13, 1, None, "IID('{281DC0F8-F04D-42AE-8889-C7F2A8F18101}')") , 
			 (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
	(( 'Unregister' , 'cookie' , ), 1610809357, (1610809357, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
	(( 'NotifyRegisteredEventHandlers' , 'eventcode' , 'comp' , ), 1610809358, (1610809358, (), [ (3, 1, None, None) , 
			 (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
	(( 'FindObject' , 'hand' , 'ppObject' , ), 1610809359, (1610809359, (), [ (8, 1, None, None) , 
			 (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
	(( 'FindAcDbObjectReferences' , 'pAcDbObject' , 'ppObjects' , ), 1610809360, (1610809360, (), [ (9, 1, None, "IID('{C932C340-CE5D-442A-BC19-D35997549D4A}')") , 
			 (24589, 10, None, None) , ], 1 , 1 , 4 , 0 , 288 , (3, 0, None, None) , 64 , )),
	(( 'UpdateInMemoryDwgHints' , ), 1610809361, (1610809361, (), [ ], 1 , 1 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
	(( 'GetIsTemporary' , 'isTemporary' , ), 1610809362, (1610809362, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
	(( 'SetIsTemporary' , ), 1610809363, (1610809363, (), [ ], 1 , 1 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
	(( 'GetDbVersion' , 'bs' , ), 1610809364, (1610809364, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
]

IAcSmDatabase_Internal_vtables_dispatch_ = 0
IAcSmDatabase_Internal_vtables_ = [
	(( 'SaveToFileForced' , ), 1610678272, (1610678272, (), [ ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'GetFileRevision' , 'pfilerev' , ), 1610678273, (1610678273, (), [ (16387, 2, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'GetDbFingerPrint' , 'fingerprintguid' , ), 1610678274, (1610678274, (), [ (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
]

IAcSmDatabase_Internal2_vtables_dispatch_ = 0
IAcSmDatabase_Internal2_vtables_ = [
	(( 'InitializeSeparateDataFileInfo' , 'bUseSeparateDataFiles' , 'dataFileMap' , ), 1610743808, (1610743808, (), [ (11, 1, None, None) , 
			 (13, 1, None, "IID('{800CD668-B1B1-423E-86EF-E5C2C19D49F8}')") , ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'SetUseSeparateDataFiles' , 'bUseSeparateDataFiles' , 'mainDataFilePath' , 'dataFileMap' , 'bRestore' , 
			 ), 1610743809, (1610743809, (), [ (11, 1, None, None) , (8, 1, None, None) , (13, 1, None, "IID('{800CD668-B1B1-423E-86EF-E5C2C19D49F8}')") , (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'GetUseSeparateDataFiles' , 'useSeparateDataFiles' , ), 1610743810, (1610743810, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'GetDataFile' , 'objHandle' , 'dataFile' , ), 1610743811, (1610743811, (), [ (8, 1, None, None) , 
			 (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'AddOrSetDataFile' , 'objHandle' , 'dataFile' , ), 1610743812, (1610743812, (), [ (8, 1, None, None) , 
			 (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'RemoveDataFile' , 'objHandle' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'SaveToSingleDataFile' , 'dataFileName' , ), 1610743814, (1610743814, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
	(( 'HasAnyDataFileChanged' , 'dataFileChanged' , ), 1610743815, (1610743815, (), [ (16395, 2, None, None) , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumAcDbBlockRecordReference_vtables_dispatch_ = 0
IAcSmEnumAcDbBlockRecordReference_vtables_ = [
	(( 'Next' , 'ppRef' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{90D38457-4C19-4E05-A51E-3B8CF4252347}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumComponent_vtables_dispatch_ = 0
IAcSmEnumComponent_vtables_ = [
	(( 'Next' , 'comp' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumDatabase_vtables_dispatch_ = 0
IAcSmEnumDatabase_vtables_ = [
	(( 'Next' , 'db' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumFileReference_vtables_dispatch_ = 0
IAcSmEnumFileReference_vtables_ = [
	(( 'Next' , 'ppRef' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumPersist_vtables_dispatch_ = 0
IAcSmEnumPersist_vtables_ = [
	(( 'Next' , 'ppObject' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumProjectPointLocation_vtables_dispatch_ = 0
IAcSmEnumProjectPointLocation_vtables_ = [
	(( 'Next' , 'location' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{6AD56DB2-C3A0-4CDA-93F4-503D86BF6A82}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumProperty_vtables_dispatch_ = 0
IAcSmEnumProperty_vtables_ = [
	(( 'Next' , 'propname' , 'ppValue' , ), 1610678272, (1610678272, (), [ (16392, 2, None, None) , 
			 (16397, 2, None, "IID('{1D9EF28C-01EF-49CB-AFBF-4A26EABC4728}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumSheetSelSet_vtables_dispatch_ = 0
IAcSmEnumSheetSelSet_vtables_ = [
	(( 'Next' , 'selset' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{7455880E-E24E-4888-B2DD-C9A63F83546D}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumSheetView_vtables_dispatch_ = 0
IAcSmEnumSheetView_vtables_ = [
	(( 'Next' , 'sview' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{6B40FE38-CAB5-4C8E-8DF1-A6CD04B8EDF9}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEnumViewCategory_vtables_dispatch_ = 0
IAcSmEnumViewCategory_vtables_ = [
	(( 'Next' , 'viewCat' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{521B23CF-B54D-488B-B39E-3F85E1776BEA}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Reset' , ), 1610678273, (1610678273, (), [ ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmEvents_vtables_dispatch_ = 0
IAcSmEvents_vtables_ = [
	(( 'OnChanged' , 'eventcode' , 'comp' , ), 1610678272, (1610678272, (), [ (3, 1, None, None) , 
			 (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
]

IAcSmFileReference_vtables_dispatch_ = 0
IAcSmFileReference_vtables_ = [
	(( 'SetFileName' , 'pValue' , ), 1610743808, (1610743808, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'GetFileName' , 'ppValue' , ), 1610743809, (1610743809, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'ResolveFileName' , 'pResult' , ), 1610743810, (1610743810, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
]

IAcSmFileReference_Internal_vtables_dispatch_ = 0
IAcSmFileReference_Internal_vtables_ = [
	(( 'SetRelativeFileName' , 'pValue' , ), 1610678272, (1610678272, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'GetRelativeFileName' , 'ppValue' , ), 1610678273, (1610678273, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'GetAbsoluteFileName' , 'ppValue' , ), 1610678274, (1610678274, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
]

IAcSmFileWatchReactor_vtables_dispatch_ = 0
IAcSmFileWatchReactor_vtables_ = [
	(( 'Init' , 'pDb' , 'bIsForLock' , 'filename' , 'notifyflags' , 
			 ), 1610743808, (1610743808, (), [ (13, 1, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , (11, 1, None, None) , (8, 1, None, None) , (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'Attach' , ), 1610743809, (1610743809, (), [ ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'Detach' , ), 1610743810, (1610743810, (), [ ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'LastError' , 'pstatus' , ), 1610743811, (1610743811, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

IAcSmFiler_vtables_dispatch_ = 0
IAcSmFiler_vtables_ = [
	(( 'Init' , 'pUnk' , 'pDb' , 'bForWrite' , ), 1610678272, (1610678272, (), [ 
			 (13, 1, None, None) , (13, 1, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Close' , 'bSuccess' , ), 1610678273, (1610678273, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'GetDatabase' , 'ppDb' , ), 1610678274, (1610678274, (), [ (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'PushCurrentWriteObject' , 'pObj' , ), 1610678275, (1610678275, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'PopCurrentWriteObject' , 'bSuccess' , ), 1610678276, (1610678276, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'PushCurrentReadObject' , 'pObj' , ), 1610678277, (1610678277, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'PopCurrentReadObject' , 'bSuccess' , ), 1610678278, (1610678278, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'GetCurrentObject' , 'pVal' , ), 1610678279, (1610678279, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'GetCurrentObjectHeaderInfo' , 'names' , 'values' , ), 1610678280, (1610678280, (), [ (24584, 2, None, None) , 
			 (24584, 2, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'GetRevisionNumber' , 'pRevisionNum' , ), 1610678281, (1610678281, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
	(( 'ReadObject' , 'ppObj' , ), 1610678282, (1610678282, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
	(( 'ReadProperty' , 'ppPropname' , 'pVal' , ), 1610678283, (1610678283, (), [ (16392, 2, None, None) , 
			 (16396, 2, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
	(( 'ReadRawData' , 'p' , 'count' , ), 1610678284, (1610678284, (), [ (16401, 2, None, None) , 
			 (16387, 2, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'WriteObject' , 'pObj' , ), 1610678285, (1610678285, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'WriteProperty' , 'pPropname' , 'pVal' , ), 1610678286, (1610678286, (), [ (8, 1, None, None) , 
			 (16396, 1, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'WriteRawData' , 'p' , 'count' , ), 1610678287, (1610678287, (), [ (16401, 1, None, None) , 
			 (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'ReadGuid' , 'pGuid' , ), 1610678288, (1610678288, (), [ (36, 10, None, None) , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 65 , )),
	(( 'ReadInt' , 'pInt' , ), 1610678289, (1610678289, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 65 , )),
	(( 'ReadDouble' , 'pDbl' , ), 1610678290, (1610678290, (), [ (16389, 10, None, None) , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 65 , )),
	(( 'ReadString' , 'pStr' , ), 1610678291, (1610678291, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 65 , )),
	(( 'ReadBytes' , 'p' , 'count' , ), 1610678292, (1610678292, (), [ (16401, 2, None, None) , 
			 (16387, 3, None, None) , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 65 , )),
	(( 'WriteGuid' , 'id' , ), 1610678293, (1610678293, (), [ (36, 1, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 65 , )),
	(( 'WriteInt' , 'pInt' , ), 1610678294, (1610678294, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 65 , )),
	(( 'WriteDouble' , 'pDbl' , ), 1610678295, (1610678295, (), [ (5, 1, None, None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 65 , )),
	(( 'WriteString' , 's' , ), 1610678296, (1610678296, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 65 , )),
	(( 'WriteBytes' , 'p' , 'count' , ), 1610678297, (1610678297, (), [ (16401, 1, None, None) , 
			 (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 65 , )),
]

IAcSmFiler_Internal_vtables_dispatch_ = 0
IAcSmFiler_Internal_vtables_ = [
	(( 'GetOwnerObject' , 'pVal' , ), 1610678272, (1610678272, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
]

IAcSmNamedAcDbObjectReference_vtables_dispatch_ = 0
IAcSmNamedAcDbObjectReference_vtables_ = [
	(( 'SetName' , 'name' , ), 1610874880, (1610874880, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'GetName' , 'phandle' , ), 1610874881, (1610874881, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'SetOwnerAcDbHandle' , 'handle' , ), 1610874882, (1610874882, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
	(( 'GetOwnerAcDbHandle' , 'phandle' , ), 1610874883, (1610874883, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
]

IAcSmObjectId_vtables_dispatch_ = 0
IAcSmObjectId_vtables_ = [
	(( 'GetHandle' , 'hand' , ), 1610678272, (1610678272, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'GetDatabase' , 'ppDb' , ), 1610678273, (1610678273, (), [ (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'GetPersistObject' , 'ppObj' , ), 1610678274, (1610678274, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'GetOwner' , 'ppObj' , ), 1610678275, (1610678275, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'IsEqual' , 'pId' , 'pResult' , ), 1610678276, (1610678276, (), [ (13, 1, None, "IID('{A1265F77-7F04-4C4D-91CF-740404156AB0}')") , 
			 (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'IsValid' , 'pResult' , ), 1610678277, (1610678277, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

IAcSmObjectReference_vtables_dispatch_ = 0
IAcSmObjectReference_vtables_ = [
	(( 'SetReferencedObject' , 'pObject' , ), 1610743808, (1610743808, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'GetReferencedObject' , 'ppObject' , ), 1610743809, (1610743809, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetReferenceFlags' , 'value' , ), 1610743810, (1610743810, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'SetReferenceFlags' , 'value' , ), 1610743811, (1610743811, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
]

IAcSmPersist_vtables_dispatch_ = 0
IAcSmPersist_vtables_ = [
	(( 'GetClassID' , 'p' , ), 1610678272, (1610678272, (), [ (36, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 64 , )),
	(( 'GetIsDirty' , 'pVal' , ), 1610678273, (1610678273, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'Load' , 'pFiler' , ), 1610678274, (1610678274, (), [ (13, 1, None, "IID('{43CD9C50-C899-437F-8CCE-ED0A1F13E0E0}')") , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'Save' , 'pFiler' , ), 1610678275, (1610678275, (), [ (13, 1, None, "IID('{43CD9C50-C899-437F-8CCE-ED0A1F13E0E0}')") , ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'GetTypeName' , 'pVal' , ), 1610678276, (1610678276, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'InitNew' , 'pOwner' , ), 1610678277, (1610678277, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'GetOwner' , 'ppOwner' , ), 1610678278, (1610678278, (), [ (16397, 10, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'SetOwner' , 'pOwner' , ), 1610678279, (1610678279, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'GetDatabase' , 'ppDb' , ), 1610678280, (1610678280, (), [ (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'GetObjectId' , 'ppId' , ), 1610678281, (1610678281, (), [ (16397, 10, None, "IID('{A1265F77-7F04-4C4D-91CF-740404156AB0}')") , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
	(( 'Clear' , ), 1610678282, (1610678282, (), [ ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
	(( 'GetDirectlyOwnedObjects' , 'objects' , ), 1610678283, (1610678283, (), [ (24589, 2, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
]

IAcSmPersistImpl_Internal_vtables_dispatch_ = 0
IAcSmPersistImpl_Internal_vtables_ = [
	(( 'GetObjectValueFromHeader' , 'pFiler' , 'bsName' , 'bsValue' , ), 1610678272, (1610678272, (), [ 
			 (13, 1, None, "IID('{43CD9C50-C899-437F-8CCE-ED0A1F13E0E0}')") , (8, 1, None, None) , (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'SetIsDirty' , 'newVal' , ), 1610678273, (1610678273, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmPersistProxy_vtables_dispatch_ = 0
IAcSmPersistProxy_vtables_ = [
	(( 'SetClassID' , 'classID' , ), 1610743808, (1610743808, (), [ (36, 1, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 64 , )),
	(( 'SetTypeName' , 'value' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetRawData' , 'ppData' , 'pBufSize' , ), 1610743810, (1610743810, (), [ (16401, 2, None, None) , 
			 (16387, 2, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 64 , )),
]

IAcSmProjectPointLocation_vtables_dispatch_ = 0
IAcSmProjectPointLocation_vtables_ = [
	(( 'GetName' , 'name' , ), 1610743808, (1610743808, (), [ (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'SetName' , 'name' , ), 1610743809, (1610743809, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetURL' , 'url' , ), 1610743810, (1610743810, (), [ (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'SetURL' , 'url' , ), 1610743811, (1610743811, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'GetFolder' , 'folder' , ), 1610743812, (1610743812, (), [ (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
	(( 'SetFolder' , 'folder' , ), 1610743813, (1610743813, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'GetUsername' , 'username' , ), 1610743814, (1610743814, (), [ (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'SetUsername' , 'username' , ), 1610743815, (1610743815, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'GetPassword' , 'password' , ), 1610743816, (1610743816, (), [ (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'SetPassword' , 'password' , ), 1610743817, (1610743817, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
]

IAcSmProjectPointLocation2_vtables_dispatch_ = 0
IAcSmProjectPointLocation2_vtables_ = [
	(( 'GetResourceType' , 'type' , ), 1610678272, (1610678272, (), [ (16387, 2, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'SetResourceType' , 'type' , ), 1610678273, (1610678273, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmProjectPointLocations_vtables_dispatch_ = 0
IAcSmProjectPointLocations_vtables_ = [
	(( 'GetLocation' , 'locationName' , 'location' , ), 1610809344, (1610809344, (), [ (8, 1, None, None) , 
			 (16397, 2, None, "IID('{6AD56DB2-C3A0-4CDA-93F4-503D86BF6A82}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'RemoveLocation' , 'location' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{6AD56DB2-C3A0-4CDA-93F4-503D86BF6A82}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'AddNewLocation' , 'name' , 'url' , 'folder' , 'username' , 
			 'password' , 'location' , ), 1610809346, (1610809346, (), [ (8, 1, None, None) , (8, 1, None, None) , 
			 (8, 1, None, None) , (8, 1, None, None) , (8, 1, None, None) , (16397, 2, None, "IID('{6AD56DB2-C3A0-4CDA-93F4-503D86BF6A82}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'GetEnumerator' , 'enumerator' , ), 1610809347, (1610809347, (), [ (16397, 10, None, "IID('{414414C6-15AE-4795-A7DD-D2FB39A21FD2}')") , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
]

IAcSmPublishOptions_vtables_dispatch_ = 0
IAcSmPublishOptions_vtables_ = [
	(( 'GetDefaultOutputdir' , 'ppValue' , ), 1610743808, (1610743808, (), [ (16397, 10, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'SetDefaultOutputdir' , 'pValue' , ), 1610743809, (1610743809, (), [ (13, 1, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'GetDwfType' , 'pValue' , ), 1610743810, (1610743810, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'SetDwfType' , 'value' , ), 1610743811, (1610743811, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'GetPromptForName' , 'pValue' , ), 1610743812, (1610743812, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
	(( 'SetPromptForName' , 'value' , ), 1610743813, (1610743813, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'GetUsePassword' , 'pValue' , ), 1610743814, (1610743814, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'SetUsePassword' , 'value' , ), 1610743815, (1610743815, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'GetPromptForPassword' , 'pValue' , ), 1610743816, (1610743816, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'SetPromptForPassword' , 'value' , ), 1610743817, (1610743817, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'GetLayerInfo' , 'pValue' , ), 1610743818, (1610743818, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
	(( 'SetLayerInfo' , 'value' , ), 1610743819, (1610743819, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
	(( 'GetUnrecognizedData' , 'bag' , ), 1610743820, (1610743820, (), [ (16397, 10, None, "IID('{C263658F-EC23-4B2B-9AD1-5D591302589F}')") , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
	(( 'SetUnrecognizedData' , 'bag' , ), 1610743821, (1610743821, (), [ (13, 1, None, "IID('{C263658F-EC23-4B2B-9AD1-5D591302589F}')") , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
	(( 'GetUnrecognizedSections' , 'sectionArray' , ), 1610743822, (1610743822, (), [ (16397, 10, None, "IID('{C263658F-EC23-4B2B-9AD1-5D591302589F}')") , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
	(( 'SetUnrecognizedSections' , 'sectionArray' , ), 1610743823, (1610743823, (), [ (13, 1, None, "IID('{C263658F-EC23-4B2B-9AD1-5D591302589F}')") , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
]

IAcSmPublishOptions2_vtables_dispatch_ = 0
IAcSmPublishOptions2_vtables_ = [
	(( 'GetIncludeSheetSetData' , 'pValue' , ), 1610809344, (1610809344, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
	(( 'SetIncludeSheetSetData' , 'value' , ), 1610809345, (1610809345, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
	(( 'GetIncludeSheetData' , 'pValue' , ), 1610809346, (1610809346, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
	(( 'SetIncludeSheetData' , 'value' , ), 1610809347, (1610809347, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
]

IAcSmPublishOptions3_vtables_dispatch_ = 0
IAcSmPublishOptions3_vtables_ = [
	(( 'GetEplotFormat' , 'pValue' , ), 1610874880, (1610874880, (), [ (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
	(( 'SetEplotFormat' , 'value' , ), 1610874881, (1610874881, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
]

IAcSmPublishOptions4_vtables_dispatch_ = 0
IAcSmPublishOptions4_vtables_ = [
	(( 'GetLinesMerge' , 'linesMerge' , ), 1610940416, (1610940416, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
	(( 'SetLinesMerge' , 'linesMerge' , ), 1610940417, (1610940417, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
	(( 'GetDefaultFilename' , 'pVal' , ), 1610940418, (1610940418, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
	(( 'SetDefaultFilename' , 'newVal' , ), 1610940419, (1610940419, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
]

IAcSmResources_vtables_dispatch_ = 0
IAcSmResources_vtables_ = [
	(( 'Add' , 'pResource' , ), 1610809344, (1610809344, (), [ (13, 1, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'Remove' , 'pResource' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetEnumerator' , 'enumerator' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{1B49F4DC-20F0-4360-AAC9-4B26BADAF024}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcSmSheet_vtables_dispatch_ = 0
IAcSmSheet_vtables_ = [
	(( 'GetNumber' , 'num' , ), 1610809344, (1610809344, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'SetNumber' , 'num' , ), 1610809345, (1610809345, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetTitle' , 'title' , ), 1610809346, (1610809346, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'SetTitle' , 'title' , ), 1610809347, (1610809347, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'GetLayout' , 'ppLayoutRef' , ), 1610809348, (1610809348, (), [ (16397, 10, None, "IID('{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}')") , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'SetLayout' , 'pLayoutRef' , ), 1610809349, (1610809349, (), [ (13, 1, None, "IID('{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}')") , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
	(( 'GetDoNotPlot' , 'doNotPlot' , ), 1610809350, (1610809350, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
	(( 'SetDoNotPlot' , 'doNotPlot' , ), 1610809351, (1610809351, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
	(( 'GetSheetViews' , 'sheetviews' , ), 1610809352, (1610809352, (), [ (16397, 10, None, "IID('{36FB4FE8-FC93-493B-AE5B-685C3C5AC7FD}')") , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
]

IAcSmSheet2_vtables_dispatch_ = 0
IAcSmSheet2_vtables_ = [
	(( 'GetRevisionNumber' , 'pVal' , ), 1610678272, (1610678272, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'SetRevisionNumber' , 'newVal' , ), 1610678273, (1610678273, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'GetRevisionDate' , 'pVal' , ), 1610678274, (1610678274, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'SetRevisionDate' , 'newVal' , ), 1610678275, (1610678275, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'GetIssuePurpose' , 'pVal' , ), 1610678276, (1610678276, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'SetIssuePurpose' , 'newVal' , ), 1610678277, (1610678277, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'GetCategory' , 'pVal' , ), 1610678278, (1610678278, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'SetCategory' , 'newVal' , ), 1610678279, (1610678279, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetSelSet_vtables_dispatch_ = 0
IAcSmSheetSelSet_vtables_ = [
	(( 'Add' , 'comp' , ), 1610809344, (1610809344, (), [ (13, 1, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'Remove' , 'comp' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetEnumerator' , 'enumerator' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{18509CA0-169A-4554-B954-96179381382E}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetSelSets_vtables_dispatch_ = 0
IAcSmSheetSelSets_vtables_ = [
	(( 'Add' , 'name' , 'desc' , 'selset' , ), 1610809344, (1610809344, (), [ 
			 (8, 0, None, None) , (8, 0, None, None) , (16397, 0, None, "IID('{7455880E-E24E-4888-B2DD-C9A63F83546D}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'Remove' , 'selset' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{7455880E-E24E-4888-B2DD-C9A63F83546D}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetEnumerator' , 'enumerator' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{709B2AC1-146C-431D-8BB2-00DEF5161824}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetSet_vtables_dispatch_ = 0
IAcSmSheetSet_vtables_ = [
	(( 'GetAltPageSetups' , 'ppDwtRef' , ), 1610874880, (1610874880, (), [ (16397, 10, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
	(( 'SetAltPageSetups' , 'pDwtRef' , ), 1610874881, (1610874881, (), [ (13, 1, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
	(( 'GetDefAltPageSetup' , 'ppAltPageSetup' , ), 1610874882, (1610874882, (), [ (16397, 10, None, "IID('{0A5869A1-99D7-42A2-807B-34728B76D7C7}')") , ], 1 , 1 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
	(( 'SetDefAltPageSetup' , 'pAltPageSetup' , ), 1610874883, (1610874883, (), [ (13, 1, None, "IID('{0A5869A1-99D7-42A2-807B-34728B76D7C7}')") , ], 1 , 1 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
	(( 'GetPromptForDwgName' , 'askForName' , ), 1610874884, (1610874884, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
	(( 'SetPromptForDwgName' , 'askForName' , ), 1610874885, (1610874885, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 328 , (3, 0, None, None) , 0 , )),
	(( 'GetSheetSelSets' , 'ppSheetSelSets' , ), 1610874886, (1610874886, (), [ (16397, 10, None, "IID('{ADE935D5-3A62-4EEB-A896-0247C3928241}')") , ], 1 , 1 , 4 , 0 , 336 , (3, 0, None, None) , 0 , )),
	(( 'GetResources' , 'ppResources' , ), 1610874887, (1610874887, (), [ (16397, 10, None, "IID('{93E5CC05-D54D-4EF5-8874-8E0F417B3BA9}')") , ], 1 , 1 , 4 , 0 , 344 , (3, 0, None, None) , 0 , )),
	(( 'GetCalloutBlocks' , 'ppCalloutBlocks' , ), 1610874888, (1610874888, (), [ (16397, 10, None, "IID('{AC463E06-D37A-4BBF-BC79-3537C6795A1A}')") , ], 1 , 1 , 4 , 0 , 352 , (3, 0, None, None) , 0 , )),
	(( 'GetViewCategories' , 'ppViewCategories' , ), 1610874889, (1610874889, (), [ (16397, 10, None, "IID('{EE9727D6-279B-46C6-9211-D0C24006E9CD}')") , ], 1 , 1 , 4 , 0 , 360 , (3, 0, None, None) , 0 , )),
	(( 'GetDefLabelBlk' , 'ppLabelBlkRef' , ), 1610874890, (1610874890, (), [ (16397, 10, None, "IID('{90D38457-4C19-4E05-A51E-3B8CF4252347}')") , ], 1 , 1 , 4 , 0 , 368 , (3, 0, None, None) , 0 , )),
	(( 'SetDefLabelBlk' , 'pLabelBlkRef' , ), 1610874891, (1610874891, (), [ (13, 1, None, "IID('{90D38457-4C19-4E05-A51E-3B8CF4252347}')") , ], 1 , 1 , 4 , 0 , 376 , (3, 0, None, None) , 0 , )),
	(( 'GetPublishOptions' , 'ppPublishOptions' , ), 1610874892, (1610874892, (), [ (16397, 10, None, "IID('{864D2BEF-F11E-4EB9-9D9A-20DFA517072E}')") , ], 1 , 1 , 4 , 0 , 384 , (3, 0, None, None) , 0 , )),
	(( 'Sync' , 'pXDb' , ), 1610874893, (1610874893, (), [ (9, 1, None, "IID('{3280D375-1DE4-4DA2-89EE-591E860056DC}')") , ], 1 , 1 , 4 , 0 , 392 , (3, 0, None, None) , 0 , )),
	(( 'Register' , 'eventHandler' , 'cookie' , ), 1610874894, (1610874894, (), [ (13, 1, None, "IID('{281DC0F8-F04D-42AE-8889-C7F2A8F18101}')") , 
			 (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 400 , (3, 0, None, None) , 0 , )),
	(( 'Unregister' , 'cookie' , ), 1610874895, (1610874895, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 408 , (3, 0, None, None) , 0 , )),
	(( 'UpdateSheetCustomProps' , ), 1610874896, (1610874896, (), [ ], 1 , 1 , 4 , 0 , 416 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetSet2_vtables_dispatch_ = 0
IAcSmSheetSet2_vtables_ = [
	(( 'GetProjectNumber' , 'pVal' , ), 1610678272, (1610678272, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'SetProjectNumber' , 'newVal' , ), 1610678273, (1610678273, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'GetProjectName' , 'pVal' , ), 1610678274, (1610678274, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'SetProjectName' , 'newVal' , ), 1610678275, (1610678275, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'GetProjectPhase' , 'pVal' , ), 1610678276, (1610678276, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'SetProjectPhase' , 'newVal' , ), 1610678277, (1610678277, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'GetProjectMilestone' , 'pVal' , ), 1610678278, (1610678278, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'SetProjectMilestone' , 'newVal' , ), 1610678279, (1610678279, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetSetMgr_vtables_dispatch_ = 0
IAcSmSheetSetMgr_vtables_ = [
	(( 'CreateDatabase' , 'filename' , 'templatefilename' , 'bAlwaysCreate' , 'db' , 
			 ), 1610678272, (1610678272, (), [ (8, 1, None, None) , (8, 49, "'0'", None) , (11, 49, 'True', None) , (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 32, None, None) , 0 , )),
	(( 'OpenDatabase' , 'filename' , 'bFailIfAlreadyOpen' , 'db' , ), 1610678273, (1610678273, (), [ 
			 (8, 1, None, None) , (11, 49, 'True', None) , (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'FindOpenDatabase' , 'filename' , 'ppDb' , ), 1610678274, (1610678274, (), [ (8, 1, None, None) , 
			 (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'CloseAll' , ), 1610678275, (1610678275, (), [ ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'Close' , 'db' , ), 1610678276, (1610678276, (), [ (13, 1, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'Register' , 'eventHandler' , 'cookie' , ), 1610678277, (1610678277, (), [ (13, 1, None, "IID('{281DC0F8-F04D-42AE-8889-C7F2A8F18101}')") , 
			 (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'Unregister' , 'cookie' , ), 1610678278, (1610678278, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'GetParentSheetSet' , 'dwg' , 'layout' , 'sheetSet' , 'pSmDb' , 
			 ), 1610678279, (1610678279, (), [ (8, 1, None, None) , (8, 1, None, None) , (16397, 2, None, "IID('{85AF8C40-BF76-4966-917A-B34739C5FFF3}')") , (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'GetSheetFromLayout' , 'pAcDbLayout' , 'sheet' , 'pSmDb' , ), 1610678280, (1610678280, (), [ 
			 (9, 1, None, "IID('{C932C340-CE5D-442A-BC19-D35997549D4A}')") , (16397, 2, None, "IID('{0547B357-BD92-477C-A94D-63297F2B22E5}')") , (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'GetDatabaseEnumerator' , 'enumerator' , ), 1610678281, (1610678281, (), [ (16397, 10, None, "IID('{05F995EC-1FE5-4876-8581-EF49A9CEE7BD}')") , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetSetMgr_Internal_vtables_dispatch_ = 0
IAcSmSheetSetMgr_Internal_vtables_ = [
	(( 'OpenDatabase' , 'filename' , 'bFailIfAlreadyOpen' , 'bUseSparateDataFiles' , 'dataMapFile' , 
			 'db' , ), 1610678272, (1610678272, (), [ (8, 1, None, None) , (11, 1, None, None) , (11, 1, None, None) , 
			 (13, 1, None, "IID('{800CD668-B1B1-423E-86EF-E5C2C19D49F8}')") , (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'LoadFromSeparateDataFiles' , 'mainDataFilePath' , 'otherDataFilePaths' , 'pDb' , ), 1610678273, (1610678273, (), [ 
			 (8, 1, None, None) , (8200, 1, None, None) , (16397, 10, None, "IID('{D36738FC-9364-43E9-BE78-865E87B32661}')") , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetView_vtables_dispatch_ = 0
IAcSmSheetView_vtables_ = [
	(( 'GetNamedView' , 'ppViewRef' , ), 1610809344, (1610809344, (), [ (16397, 10, None, "IID('{0B66E84D-D0E5-4D55-BC59-32B63592A74A}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'SetNamedView' , 'pViewRef' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{0B66E84D-D0E5-4D55-BC59-32B63592A74A}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetCategory' , 'ppViewCat' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{521B23CF-B54D-488B-B39E-3F85E1776BEA}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'SetCategory' , 'pViewCat' , ), 1610809347, (1610809347, (), [ (13, 1, None, "IID('{521B23CF-B54D-488B-B39E-3F85E1776BEA}')") , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'GetNumber' , 'num' , ), 1610809348, (1610809348, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'SetNumber' , 'num' , ), 1610809349, (1610809349, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
	(( 'GetTitle' , 'title' , ), 1610809350, (1610809350, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
	(( 'SetTitle' , 'title' , ), 1610809351, (1610809351, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetView_Internal_vtables_dispatch_ = 0
IAcSmSheetView_Internal_vtables_ = [
	(( 'InitNew' , 'pOwner' , 'bsRequestedHandle' , ), 1610678272, (1610678272, (), [ (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , 
			 (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
]

IAcSmSheetViews_vtables_dispatch_ = 0
IAcSmSheetViews_vtables_ = [
	(( 'GetEnumerator' , 'enumerator' , ), 1610809344, (1610809344, (), [ (16397, 10, None, "IID('{24B9DF7E-CB5F-4646-B948-79ABAD3D36CA}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'Sync' , 'pLayout' , 'pXDb' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}')") , 
			 (9, 1, None, "IID('{3280D375-1DE4-4DA2-89EE-591E860056DC}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
]

IAcSmSubset_vtables_dispatch_ = 0
IAcSmSubset_vtables_ = [
	(( 'GetNewSheetLocation' , 'ppFileRef' , ), 1610809344, (1610809344, (), [ (16397, 10, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'SetNewSheetLocation' , 'pFileRef' , ), 1610809345, (1610809345, (), [ (13, 1, None, "IID('{3F245520-4A52-4761-A6D6-626D6C000B2A}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'GetDefDwtLayout' , 'ppLayoutRef' , ), 1610809346, (1610809346, (), [ (16397, 10, None, "IID('{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'SetDefDwtLayout' , 'pLayoutRef' , ), 1610809347, (1610809347, (), [ (13, 1, None, "IID('{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}')") , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'GetPromptForDwt' , 'askForDwt' , ), 1610809348, (1610809348, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'SetPromptForDwt' , 'askForDwt' , ), 1610809349, (1610809349, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 0 , )),
	(( 'GetSheetEnumerator' , 'enumerator' , ), 1610809350, (1610809350, (), [ (16397, 10, None, "IID('{18509CA0-169A-4554-B954-96179381382E}')") , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 0 , )),
	(( 'AddNewSheet' , 'name' , 'desc' , 'newSheet' , ), 1610809351, (1610809351, (), [ 
			 (8, 1, None, None) , (8, 1, None, None) , (16397, 10, None, "IID('{0547B357-BD92-477C-A94D-63297F2B22E5}')") , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
	(( 'InsertComponent' , 'newSheet' , 'beforeComp' , ), 1610809352, (1610809352, (), [ (13, 1, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , 
			 (13, 1, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
	(( 'InsertComponentAfter' , 'newSheet' , 'afterComp' , ), 1610809353, (1610809353, (), [ (13, 1, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , 
			 (13, 1, None, "IID('{50348BBF-D25A-4D6B-96AD-325E35219313}')") , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
	(( 'ImportSheet' , 'pLayoutRef' , 'newSheet' , ), 1610809354, (1610809354, (), [ (13, 1, None, "IID('{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}')") , 
			 (16397, 10, None, "IID('{0547B357-BD92-477C-A94D-63297F2B22E5}')") , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
	(( 'RemoveSheet' , 'sheet' , ), 1610809355, (1610809355, (), [ (13, 0, None, "IID('{0547B357-BD92-477C-A94D-63297F2B22E5}')") , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
	(( 'CreateSubset' , 'name' , 'desc' , 'subset' , ), 1610809356, (1610809356, (), [ 
			 (8, 1, None, None) , (8, 1, None, None) , (16397, 10, None, "IID('{3E020B92-D315-43CF-8CC2-101739158782}')") , ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
	(( 'RemoveSubset' , 'subset' , ), 1610809357, (1610809357, (), [ (13, 1, None, "IID('{3E020B92-D315-43CF-8CC2-101739158782}')") , ], 1 , 1 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
	(( 'NotifyRegisteredEventHandlers' , 'eventcode' , 'comp' , ), 1610809358, (1610809358, (), [ (3, 1, None, None) , 
			 (13, 1, None, "IID('{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}')") , ], 1 , 1 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
	(( 'UpdateInMemoryDwgHints' , ), 1610809359, (1610809359, (), [ ], 1 , 1 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
]

IAcSmSubset2_vtables_dispatch_ = 0
IAcSmSubset2_vtables_ = [
	(( 'GetOverrideSheetPublish' , 'overridePublish' , ), 1610678272, (1610678272, (), [ (16395, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'SetOverrideSheetPublish' , 'overridePublish' , ), 1610678273, (1610678273, (), [ (11, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

IAcSmViewCategories_vtables_dispatch_ = 0
IAcSmViewCategories_vtables_ = [
	(( 'GetEnumerator' , 'enumerator' , ), 1610809344, (1610809344, (), [ (16397, 10, None, "IID('{AC36D755-1390-4B33-84A0-897E3C2945EB}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'CreateViewCategory' , 'name' , 'desc' , 'id' , 'viewCat' , 
			 ), 1610809345, (1610809345, (), [ (8, 1, None, None) , (8, 1, None, None) , (8, 1, None, None) , (16397, 10, None, "IID('{521B23CF-B54D-488B-B39E-3F85E1776BEA}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'RemoveViewCategory' , 'viewCat' , ), 1610809346, (1610809346, (), [ (13, 1, None, "IID('{521B23CF-B54D-488B-B39E-3F85E1776BEA}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'GetDefaultViewCategory' , 'ppItem' , ), 1610809347, (1610809347, (), [ (16397, 10, None, "IID('{521B23CF-B54D-488B-B39E-3F85E1776BEA}')") , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
]

IAcSmViewCategory_vtables_dispatch_ = 0
IAcSmViewCategory_vtables_ = [
	(( 'GetSheetViewEnumerator' , 'enumerator' , ), 1610809344, (1610809344, (), [ (16397, 10, None, "IID('{24B9DF7E-CB5F-4646-B948-79ABAD3D36CA}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'GetCalloutBlocks' , 'ppCalloutBlocks' , ), 1610809345, (1610809345, (), [ (16397, 10, None, "IID('{AC463E06-D37A-4BBF-BC79-3537C6795A1A}')") , ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
]

IAdComFileWatchReactor_vtables_dispatch_ = 0
IAdComFileWatchReactor_vtables_ = [
	(( 'OnFileChange' , 'action' , ), 1610678272, (1610678272, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'OnError' , 'num' , 'description' , ), 1610678273, (1610678273, (), [ (3, 1, None, None) , 
			 (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
]

INameValueMap_Internal_vtables_dispatch_ = 0
INameValueMap_Internal_vtables_ = [
	(( 'Item' , 'key' , 'pValue' , ), 1610678272, (1610678272, (), [ (8, 1, None, None) , 
			 (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Add' , 'key' , 'value' , ), 1610678273, (1610678273, (), [ (8, 1, None, None) , 
			 (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'Remove' , 'key' , ), 1610678274, (1610678274, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
	(( 'Clear' , ), 1610678275, (1610678275, (), [ ], 1 , 1 , 4 , 0 , 48 , (3, 0, None, None) , 0 , )),
	(( 'StartIteration' , ), 1610678276, (1610678276, (), [ ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'GetNextElement' , 'key' , 'value' , ), 1610678277, (1610678277, (), [ (16392, 2, None, None) , 
			 (16392, 2, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

RecordMap = {
}

CLSIDToClassMap = {
	'{5EC19FD3-79AB-4C05-9100-E3636F7676A2}' : AcSmDSTFiler,
	'{3CE9998D-84A9-4E80-A9D4-94F612E0F4DA}' : AcSmDatabase,
	'{14DA1BFA-BB31-4EC6-8AE7-1F0C2514D2D6}' : AcSmSheetSet,
	'{F8DFC187-DEE9-4BF9-945A-9897D60F6042}' : AcSmSubset,
	'{FD5A339E-D976-4522-B8BA-5ACB06D2E8A7}' : AcSmResources,
	'{8DA06B57-6348-41FB-9731-E06A655EE15D}' : AcSmCalloutBlocks,
	'{27D14C8A-CD7E-4829-A185-6763A26F1474}' : AcSmCalloutBlockReferences,
	'{83A10BEA-7DAB-4BC3-A038-531C8B3BC4D7}' : AcSmSheetSelSet,
	'{70A89F90-AC01-4011-B390-9104BE54A608}' : AcSmSheetSelSets,
	'{3A810C7C-1F9A-47E6-AC67-88BF2D094453}' : AcSmSheet,
	'{54DD1BD6-BD8D-425A-934C-2121C901AC93}' : AcSmSheetView,
	'{B4D3F171-77E9-412C-A907-67EDA512DBDE}' : AcSmSheetViews,
	'{FB00D547-2AAE-453C-BF36-4E353F46947D}' : AcSmViewCategory,
	'{BD989BC7-F8EC-4570-A45E-0C92D6354AB8}' : AcSmViewCategories,
	'{1C3AEBB1-823D-4831-980F-C1481311B3A0}' : AcSmSheetSetMgr,
	'{3B79C4C3-1CFB-42DD-AD98-47AFB9BC66C8}' : AcSmFileReference,
	'{4DD54885-C28D-4EF2-9CC1-CBC0189C73B4}' : AcSmAcDbDatabase,
	'{0FF37EB8-721B-49ED-B404-21C6CFE38FC6}' : AcSmAcDbObjectReference,
	'{F452DF8B-685B-4AC8-9A61-4D3FC6C36D85}' : AcSmNamedAcDbObjectReference,
	'{519093BC-CC09-4DBC-96C1-351AFA3484F5}' : AcSmAcDbLayoutReference,
	'{73A964AA-FB49-4B40-BDF3-1F8C52D830A3}' : AcSmAcDbViewReference,
	'{F2D3E572-5C41-415C-9CDD-5A4457F82263}' : AcSmAcDbBlockRecordReference,
	'{F1D59B7B-988B-4D30-9157-FF3A0D784093}' : AcSmCustomPropertyValue,
	'{3D3C7AFB-DB98-4C7E-BE9C-66558A744966}' : AcSmCustomPropertyBag,
	'{04E7D784-04AC-42E6-B289-98AFC9F56400}' : AcSmPersistProxy,
	'{5612BEDD-91A0-4552-BB68-B3E183DD62C3}' : AcSmObjectReference,
	'{A3477229-7C55-4156-9A3F-49703D2F7EA3}' : AcSmPublishOptions,
	'{2942ED61-730D-40BD-A7F9-11A9DC3AE351}' : AcSmFileWatchReactor,
	'{2F666CD5-91F5-4467-B9C3-6B14E0633D18}' : AcSmProjectPointLocation,
	'{62052FD8-7637-4F33-BB23-1C622E305506}' : AcSmSimpleFileReference,
	'{C3E338CA-20EE-4C48-869F-5BF434AD40D0}' : AcSmProjectPointLocations,
	'{729D33D4-09FD-439F-B86C-2E127707A3C0}' : AcSmPersistImpl,
	'{7A3E83C6-BFB8-46E6-98C5-8282C7F3A084}' : NameValueMap,
}
CLSIDToPackageMap = {}
win32com.client.CLSIDToClass.RegisterCLSIDsFromDict( CLSIDToClassMap )
VTablesToPackageMap = {}
VTablesToClassMap = {
	'{26E53151-2219-43A6-ADA9-CC420C151740}' : 'IAcSmDatabase_Internal',
	'{800CD668-B1B1-423E-86EF-E5C2C19D49F8}' : 'INameValueMap_Internal',
	'{E3E12B17-7A0C-4323-B7EA-052A311E8446}' : 'IAcSmDatabase_Internal2',
	'{1515C28A-26E9-4CCD-A49F-AC84CAE1E74D}' : 'IAcSmFileReference_Internal',
	'{91900445-913B-49F8-A7A9-6691847B4C11}' : 'IAcSmFiler_Internal',
	'{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}' : 'IAcSmPersist',
	'{43CD9C50-C899-437F-8CCE-ED0A1F13E0E0}' : 'IAcSmFiler',
	'{D36738FC-9364-43E9-BE78-865E87B32661}' : 'IAcSmDatabase',
	'{50348BBF-D25A-4D6B-96AD-325E35219313}' : 'IAcSmComponent',
	'{C263658F-EC23-4B2B-9AD1-5D591302589F}' : 'IAcSmCustomPropertyBag',
	'{1D9EF28C-01EF-49CB-AFBF-4A26EABC4728}' : 'IAcSmCustomPropertyValue',
	'{2EC24760-C507-4504-A035-90FE8A07E476}' : 'IAcSmEnumProperty',
	'{85AF8C40-BF76-4966-917A-B34739C5FFF3}' : 'IAcSmSheetSet',
	'{3E020B92-D315-43CF-8CC2-101739158782}' : 'IAcSmSubset',
	'{3F245520-4A52-4761-A6D6-626D6C000B2A}' : 'IAcSmFileReference',
	'{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}' : 'IAcSmAcDbLayoutReference',
	'{0A5869A1-99D7-42A2-807B-34728B76D7C7}' : 'IAcSmNamedAcDbObjectReference',
	'{7E158634-6AA2-48F8-BABA-3BB754D42B95}' : 'IAcSmAcDbObjectReference',
	'{FFA44922-263E-4EF5-AC5C-17D45E34C856}' : 'IAcSmAcDbDatabase',
	'{18509CA0-169A-4554-B954-96179381382E}' : 'IAcSmEnumComponent',
	'{0547B357-BD92-477C-A94D-63297F2B22E5}' : 'IAcSmSheet',
	'{36FB4FE8-FC93-493B-AE5B-685C3C5AC7FD}' : 'IAcSmSheetViews',
	'{24B9DF7E-CB5F-4646-B948-79ABAD3D36CA}' : 'IAcSmEnumSheetView',
	'{6B40FE38-CAB5-4C8E-8DF1-A6CD04B8EDF9}' : 'IAcSmSheetView',
	'{0B66E84D-D0E5-4D55-BC59-32B63592A74A}' : 'IAcSmAcDbViewReference',
	'{521B23CF-B54D-488B-B39E-3F85E1776BEA}' : 'IAcSmViewCategory',
	'{AC463E06-D37A-4BBF-BC79-3537C6795A1A}' : 'IAcSmCalloutBlocks',
	'{90D38457-4C19-4E05-A51E-3B8CF4252347}' : 'IAcSmAcDbBlockRecordReference',
	'{69520E4B-34A4-4E5F-A1A4-69362E818751}' : 'IAcSmEnumAcDbBlockRecordReference',
	'{ADE935D5-3A62-4EEB-A896-0247C3928241}' : 'IAcSmSheetSelSets',
	'{7455880E-E24E-4888-B2DD-C9A63F83546D}' : 'IAcSmSheetSelSet',
	'{709B2AC1-146C-431D-8BB2-00DEF5161824}' : 'IAcSmEnumSheetSelSet',
	'{93E5CC05-D54D-4EF5-8874-8E0F417B3BA9}' : 'IAcSmResources',
	'{1B49F4DC-20F0-4360-AAC9-4B26BADAF024}' : 'IAcSmEnumFileReference',
	'{EE9727D6-279B-46C6-9211-D0C24006E9CD}' : 'IAcSmViewCategories',
	'{AC36D755-1390-4B33-84A0-897E3C2945EB}' : 'IAcSmEnumViewCategory',
	'{864D2BEF-F11E-4EB9-9D9A-20DFA517072E}' : 'IAcSmPublishOptions',
	'{281DC0F8-F04D-42AE-8889-C7F2A8F18101}' : 'IAcSmEvents',
	'{A1265F77-7F04-4C4D-91CF-740404156AB0}' : 'IAcSmObjectId',
	'{8754C99A-C73A-4B82-9899-BE5965905042}' : 'IAcSmEnumPersist',
	'{9BABCF36-B95E-41DE-9681-14096D2656B1}' : 'IAcSmSheetSetMgr_Internal',
	'{12C5456A-BB26-4099-989A-45CB844B1C07}' : 'IAcSmSheetSet2',
	'{615A3CCA-E1FF-4249-892F-F0C6FAF64D70}' : 'IAcSmSubset2',
	'{5F0B0EB8-D8CA-460B-9968-C83F84C22A0C}' : 'IAcSmSheet2',
	'{37B714F9-6E43-4B49-ADF5-2C2048DAF7C2}' : 'IAcSmSheetView_Internal',
	'{FF31D373-6F52-4E66-AFA3-2547DA803079}' : 'IAcSmSheetSetMgr',
	'{05F995EC-1FE5-4876-8581-EF49A9CEE7BD}' : 'IAcSmEnumDatabase',
	'{DBD3CF9A-C4DE-4492-A4FE-54A8464145C2}' : 'IAcSmPersistProxy',
	'{A480676B-36C6-44FE-A7C1-6E8A7D4BECE6}' : 'IAcSmObjectReference',
	'{AA8E3C88-2463-4BE4-A15E-7B1C4F8AD25F}' : 'IAcSmPublishOptions2',
	'{F0F89873-673F-4E2C-B782-83A386F064B9}' : 'IAcSmPublishOptions3',
	'{B3AC9C5D-9020-4B29-AFA0-5F2FD9FD2F78}' : 'IAcSmPublishOptions4',
	'{58458256-1747-4385-BDBA-A1229B523A37}' : 'IAcSmFileWatchReactor',
	'{883EBF09-533B-45E7-9EBF-4BA2F93F90C0}' : 'IAdComFileWatchReactor',
	'{6AD56DB2-C3A0-4CDA-93F4-503D86BF6A82}' : 'IAcSmProjectPointLocation',
	'{C33FC097-42B0-47AA-B762-24DAEB6A99DB}' : 'IAcSmProjectPointLocation2',
	'{1078B77D-8A20-4FF4-AF07-4F9F06C12B5D}' : 'IAcSmProjectPointLocations',
	'{414414C6-15AE-4795-A7DD-D2FB39A21FD2}' : 'IAcSmEnumProjectPointLocation',
	'{CE0273FF-94A2-4415-9100-5CE2D498961C}' : 'IAcSmPersistImpl_Internal',
}


NamesToIIDMap = {
	'IAcSmDatabase_Internal' : '{26E53151-2219-43A6-ADA9-CC420C151740}',
	'INameValueMap_Internal' : '{800CD668-B1B1-423E-86EF-E5C2C19D49F8}',
	'IAcSmDatabase_Internal2' : '{E3E12B17-7A0C-4323-B7EA-052A311E8446}',
	'IAcSmFileReference_Internal' : '{1515C28A-26E9-4CCD-A49F-AC84CAE1E74D}',
	'IAcSmFiler_Internal' : '{91900445-913B-49F8-A7A9-6691847B4C11}',
	'IAcSmPersist' : '{1A9F1E7F-3134-4B11-AB65-9CA5730EF89B}',
	'IAcSmFiler' : '{43CD9C50-C899-437F-8CCE-ED0A1F13E0E0}',
	'IAcSmDatabase' : '{D36738FC-9364-43E9-BE78-865E87B32661}',
	'IAcSmComponent' : '{50348BBF-D25A-4D6B-96AD-325E35219313}',
	'IAcSmCustomPropertyBag' : '{C263658F-EC23-4B2B-9AD1-5D591302589F}',
	'IAcSmCustomPropertyValue' : '{1D9EF28C-01EF-49CB-AFBF-4A26EABC4728}',
	'IAcSmEnumProperty' : '{2EC24760-C507-4504-A035-90FE8A07E476}',
	'IAcSmSheetSet' : '{85AF8C40-BF76-4966-917A-B34739C5FFF3}',
	'IAcSmSubset' : '{3E020B92-D315-43CF-8CC2-101739158782}',
	'IAcSmFileReference' : '{3F245520-4A52-4761-A6D6-626D6C000B2A}',
	'IAcSmAcDbLayoutReference' : '{CB75051A-A571-4BE1-B30A-BAFEEE2F825E}',
	'IAcSmNamedAcDbObjectReference' : '{0A5869A1-99D7-42A2-807B-34728B76D7C7}',
	'IAcSmAcDbObjectReference' : '{7E158634-6AA2-48F8-BABA-3BB754D42B95}',
	'IAcSmAcDbDatabase' : '{FFA44922-263E-4EF5-AC5C-17D45E34C856}',
	'IAcSmEnumComponent' : '{18509CA0-169A-4554-B954-96179381382E}',
	'IAcSmSheet' : '{0547B357-BD92-477C-A94D-63297F2B22E5}',
	'IAcSmSheetViews' : '{36FB4FE8-FC93-493B-AE5B-685C3C5AC7FD}',
	'IAcSmEnumSheetView' : '{24B9DF7E-CB5F-4646-B948-79ABAD3D36CA}',
	'IAcSmSheetView' : '{6B40FE38-CAB5-4C8E-8DF1-A6CD04B8EDF9}',
	'IAcSmAcDbViewReference' : '{0B66E84D-D0E5-4D55-BC59-32B63592A74A}',
	'IAcSmViewCategory' : '{521B23CF-B54D-488B-B39E-3F85E1776BEA}',
	'IAcSmCalloutBlocks' : '{AC463E06-D37A-4BBF-BC79-3537C6795A1A}',
	'IAcSmAcDbBlockRecordReference' : '{90D38457-4C19-4E05-A51E-3B8CF4252347}',
	'IAcSmEnumAcDbBlockRecordReference' : '{69520E4B-34A4-4E5F-A1A4-69362E818751}',
	'IAcSmSheetSelSets' : '{ADE935D5-3A62-4EEB-A896-0247C3928241}',
	'IAcSmSheetSelSet' : '{7455880E-E24E-4888-B2DD-C9A63F83546D}',
	'IAcSmEnumSheetSelSet' : '{709B2AC1-146C-431D-8BB2-00DEF5161824}',
	'IAcSmResources' : '{93E5CC05-D54D-4EF5-8874-8E0F417B3BA9}',
	'IAcSmEnumFileReference' : '{1B49F4DC-20F0-4360-AAC9-4B26BADAF024}',
	'IAcSmViewCategories' : '{EE9727D6-279B-46C6-9211-D0C24006E9CD}',
	'IAcSmEnumViewCategory' : '{AC36D755-1390-4B33-84A0-897E3C2945EB}',
	'IAcSmPublishOptions' : '{864D2BEF-F11E-4EB9-9D9A-20DFA517072E}',
	'IAcSmEvents' : '{281DC0F8-F04D-42AE-8889-C7F2A8F18101}',
	'IAcSmObjectId' : '{A1265F77-7F04-4C4D-91CF-740404156AB0}',
	'IAcSmEnumPersist' : '{8754C99A-C73A-4B82-9899-BE5965905042}',
	'IAcSmSheetSetMgr_Internal' : '{9BABCF36-B95E-41DE-9681-14096D2656B1}',
	'IAcSmSheetSet2' : '{12C5456A-BB26-4099-989A-45CB844B1C07}',
	'IAcSmSubset2' : '{615A3CCA-E1FF-4249-892F-F0C6FAF64D70}',
	'IAcSmSheet2' : '{5F0B0EB8-D8CA-460B-9968-C83F84C22A0C}',
	'IAcSmSheetView_Internal' : '{37B714F9-6E43-4B49-ADF5-2C2048DAF7C2}',
	'IAcSmSheetSetMgr' : '{FF31D373-6F52-4E66-AFA3-2547DA803079}',
	'IAcSmEnumDatabase' : '{05F995EC-1FE5-4876-8581-EF49A9CEE7BD}',
	'IAcSmPersistProxy' : '{DBD3CF9A-C4DE-4492-A4FE-54A8464145C2}',
	'IAcSmObjectReference' : '{A480676B-36C6-44FE-A7C1-6E8A7D4BECE6}',
	'IAcSmPublishOptions2' : '{AA8E3C88-2463-4BE4-A15E-7B1C4F8AD25F}',
	'IAcSmPublishOptions3' : '{F0F89873-673F-4E2C-B782-83A386F064B9}',
	'IAcSmPublishOptions4' : '{B3AC9C5D-9020-4B29-AFA0-5F2FD9FD2F78}',
	'IAcSmFileWatchReactor' : '{58458256-1747-4385-BDBA-A1229B523A37}',
	'IAdComFileWatchReactor' : '{883EBF09-533B-45E7-9EBF-4BA2F93F90C0}',
	'IAcSmProjectPointLocation' : '{6AD56DB2-C3A0-4CDA-93F4-503D86BF6A82}',
	'IAcSmProjectPointLocation2' : '{C33FC097-42B0-47AA-B762-24DAEB6A99DB}',
	'IAcSmProjectPointLocations' : '{1078B77D-8A20-4FF4-AF07-4F9F06C12B5D}',
	'IAcSmEnumProjectPointLocation' : '{414414C6-15AE-4795-A7DD-D2FB39A21FD2}',
	'IAcSmPersistImpl_Internal' : '{CE0273FF-94A2-4415-9100-5CE2D498961C}',
}

win32com.client.constants.__dicts__.append(constants.__dict__)

