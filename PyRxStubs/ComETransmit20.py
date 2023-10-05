# -*- coding: mbcs -*-
# Created by makepy.py version 0.5.01
# By python version 3.10.10 (tags/v3.10.10:aad5f6a, Feb  7 2023, 17:20:36) [MSC v.1929 64 bit (AMD64)]
# From type library 'AcETransmit20.tlb'
# On Thu Oct  5 13:51:02 2023
'transmittal 20.0 Type Library'
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

CLSID = IID('{8D5FE9A6-03E9-4728-876E-432AC39A71EF}')
MajorVersion = 20
MinorVersion = 0
LibraryFlags = 8
LCID = 0x0

class constants:
	e3rdPartyAddedFile            =14         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eAltFontFile                  =7          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDGNUnderlay                  =20         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDGNUnderlayDependent         =25         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDWFUnderlay                  =21         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDataLinkFile                 =24         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDwgFile                      =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDwsFile                      =26         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eFontFile                     =3          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eFontMapFile                  =13         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eImageFile                    =2          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eMaterialTextureFile          =22         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eNoType                       =-1         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	ePDFUnderlay                  =27         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	ePfbAltFontFile               =9          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	ePfbFontFile                  =5          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	ePhotometricWebFile           =23         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	ePlotCfgFile                  =11         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	ePlotStyleTableFile           =12         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eSheetSetFile                 =18         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eSheetSetSupportFile          =19         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eShxAltFontFile               =8          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eShxFontFile                  =4          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eTtfAltFontFile               =10         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eTtfFontFile                  =6          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eUserAddedFile                =15         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eXrefAttachFile               =16         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eXrefFile                     =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eXrefOverlayFile              =17         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0001
	eDwgTrusted                   =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0002
	eDwgUnTrusted                 =-1         # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0002
	eTrustInfoUnavailable         =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0002
	eFileAdded                    =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0003
	eFileAlreadyAdded             =5          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0003
	eFileNotAdded                 =2          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0003
	eFileNotAddedBadArg           =4          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0003
	eFileNotAddedToPreventCycle   =3          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0003
	eRelationshipAdded            =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0003
	eAutoCAD14                    =3          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eAutoCAD2000                  =2          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eAutoCADR18                   =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eAutoCADR21                   =4          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eAutoCADR24                   =5          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eAutoCADR27                   =6          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eAutoCADR32                   =7          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eNoConversion                 =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0004
	eOverwriteCancel              =3          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0005
	eOverwriteNo                  =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0005
	eOverwriteYes                 =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0005
	eOverwriteYesToAll            =2          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0005
	eOverwriteYesToAllReadOnly    =4          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0005
	eConverted                    =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eMissingFiles                 =5          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eNotUsed                      =3          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eRecovered                    =2          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eSaveError                    =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eShareViolationError          =4          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eSignedFileError              =6          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0006
	eBind                         =0          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0007
	eInsert                       =1          # from enum __MIDL___MIDL_itf_transmittal_0000_0000_0007

from win32com.client import DispatchBaseClass
class IRelocateDrawing(DispatchBaseClass):
	'Autodesk internal use only -- IRelocateDrawing Interface'
	CLSID = IID('{4255FEF5-5AE5-4F7D-98EA-75853819A684}')
	coclass_clsid = None

	def addDatabase(self, db=defaultNamedNotOptArg):
		'Autodesk internal use only -- method addDatabase'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1),),db
			)

	_prop_map_get_ = {
		"repathExcludedDGNUnderlay": (5, 2, (3, 0), (), "repathExcludedDGNUnderlay", None),
		"repathExcludedDWFUnderlay": (6, 2, (3, 0), (), "repathExcludedDWFUnderlay", None),
		"repathExcludedImage": (4, 2, (3, 0), (), "repathExcludedImage", None),
		"repathExcludedXref": (3, 2, (3, 0), (), "repathExcludedXref", None),
		"supressNotification": (2, 2, (3, 0), (), "supressNotification", None),
	}
	_prop_map_put_ = {
		"repathExcludedDGNUnderlay": ((5, LCID, 4, 0),()),
		"repathExcludedDWFUnderlay": ((6, LCID, 4, 0),()),
		"repathExcludedImage": ((4, LCID, 4, 0),()),
		"repathExcludedXref": ((3, LCID, 4, 0),()),
		"supressNotification": ((2, LCID, 4, 0),()),
	}
	def __iter__(self):
		"Return a Python iterator for this object"
		try:
			ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
		except pythoncom.error:
			raise TypeError("This object does not support enumeration")
		return win32com.client.util.Iterator(ob, None)

class IRelocateDrawing2(DispatchBaseClass):
	'Autodesk internal use only -- IRelocateDrawing2 Interface'
	CLSID = IID('{214CCC0F-968A-47FB-B625-FB014C73311F}')
	coclass_clsid = None

	def addDatabase(self, db=defaultNamedNotOptArg):
		'Autodesk internal use only -- method addDatabase'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1),),db
			)

	_prop_map_get_ = {
		"repathExcludedDGNUnderlay": (5, 2, (3, 0), (), "repathExcludedDGNUnderlay", None),
		"repathExcludedDWFUnderlay": (6, 2, (3, 0), (), "repathExcludedDWFUnderlay", None),
		"repathExcludedDataLink": (7, 2, (3, 0), (), "repathExcludedDataLink", None),
		"repathExcludedImage": (4, 2, (3, 0), (), "repathExcludedImage", None),
		"repathExcludedXref": (3, 2, (3, 0), (), "repathExcludedXref", None),
		"supressNotification": (2, 2, (3, 0), (), "supressNotification", None),
	}
	_prop_map_put_ = {
		"repathExcludedDGNUnderlay": ((5, LCID, 4, 0),()),
		"repathExcludedDWFUnderlay": ((6, LCID, 4, 0),()),
		"repathExcludedDataLink": ((7, LCID, 4, 0),()),
		"repathExcludedImage": ((4, LCID, 4, 0),()),
		"repathExcludedXref": ((3, LCID, 4, 0),()),
		"supressNotification": ((2, LCID, 4, 0),()),
	}
	def __iter__(self):
		"Return a Python iterator for this object"
		try:
			ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
		except pythoncom.error:
			raise TypeError("This object does not support enumeration")
		return win32com.client.util.Iterator(ob, None)

class IRelocateDrawing3(DispatchBaseClass):
	'Autodesk internal use only -- IRelocateDrawing3 Interface'
	CLSID = IID('{2F8EE550-B6BD-4144-ACB2-7633B0A905C2}')
	coclass_clsid = None

	def addDatabase(self, db=defaultNamedNotOptArg):
		'Autodesk internal use only -- method addDatabase'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1),),db
			)

	_prop_map_get_ = {
		"repathExcludedDGNUnderlay": (5, 2, (3, 0), (), "repathExcludedDGNUnderlay", None),
		"repathExcludedDWFUnderlay": (6, 2, (3, 0), (), "repathExcludedDWFUnderlay", None),
		"repathExcludedDataLink": (7, 2, (3, 0), (), "repathExcludedDataLink", None),
		"repathExcludedImage": (4, 2, (3, 0), (), "repathExcludedImage", None),
		"repathExcludedPDFUnderlay": (8, 2, (3, 0), (), "repathExcludedPDFUnderlay", None),
		"repathExcludedXref": (3, 2, (3, 0), (), "repathExcludedXref", None),
		"supressNotification": (2, 2, (3, 0), (), "supressNotification", None),
	}
	_prop_map_put_ = {
		"repathExcludedDGNUnderlay": ((5, LCID, 4, 0),()),
		"repathExcludedDWFUnderlay": ((6, LCID, 4, 0),()),
		"repathExcludedDataLink": ((7, LCID, 4, 0),()),
		"repathExcludedImage": ((4, LCID, 4, 0),()),
		"repathExcludedPDFUnderlay": ((8, LCID, 4, 0),()),
		"repathExcludedXref": ((3, LCID, 4, 0),()),
		"supressNotification": ((2, LCID, 4, 0),()),
	}
	def __iter__(self):
		"Return a Python iterator for this object"
		try:
			ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
		except pythoncom.error:
			raise TypeError("This object does not support enumeration")
		return win32com.client.util.Iterator(ob, None)

class ITransmittalAddFileNotificationHandler(DispatchBaseClass):
	'ITransmittalAddFileNotificationHandler Interface'
	CLSID = IID('{DBFC8126-EB2A-43A6-A6C9-5A65F26256AF}')
	coclass_clsid = IID('{6BC47508-D5EF-4DD5-9A59-376B92DCFE7A}')

	def addFileNotificationHandler(self, pFile=defaultNamedNotOptArg, pTransmit=defaultNamedNotOptArg):
		'method addFileNotificationHandler'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1), (9, 1)),pFile
			, pTransmit)

	def beginFilesGraphCreation(self, pTransmit=defaultNamedNotOptArg):
		'method beginFilesGraphCreation'
		return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((9, 1),),pTransmit
			)

	def endFilesGraphCreation(self, pTransmit=defaultNamedNotOptArg):
		'method endFilesGraphCreation'
		return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 1),),pTransmit
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

class ITransmittalDatabaseNotificationHandler(DispatchBaseClass):
	'ITransmittalDatabaseNotificationHandler Interface'
	CLSID = IID('{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}')
	coclass_clsid = IID('{11AA8559-7D9A-4B26-B550-23E6D62EE9C6}')

	def convertDatabase(self, pDatabase=defaultNamedNotOptArg, pFile=defaultNamedNotOptArg, pTransmit=defaultNamedNotOptArg):
		'method convertDatabase'
		return self._oleobj_.InvokeTypes(3, LCID, 1, (3, 0), ((9, 1), (9, 1), (9, 1)),pDatabase
			, pFile, pTransmit)

	def postDatabaseProcessing(self, pDatabase=defaultNamedNotOptArg, pFile=defaultNamedNotOptArg, pTransmit=defaultNamedNotOptArg):
		'method postDatabaseProcessing'
		return self._oleobj_.InvokeTypes(2, LCID, 1, (3, 0), ((9, 1), (9, 1), (9, 1)),pDatabase
			, pFile, pTransmit)

	def preDatabaseProcessing(self, pDatabase=defaultNamedNotOptArg, pFile=defaultNamedNotOptArg, pTransmit=defaultNamedNotOptArg):
		'method preDatabaseProcessing'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (3, 0), ((9, 1), (9, 1), (9, 1)),pDatabase
			, pFile, pTransmit)

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
	CLSID = IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')
	coclass_clsid = IID('{BC573B3C-4123-4F95-8DD4-DF3BEC317D67}')

	# Result is of type ITransmittalFile
	def getDependee(self, nIndex=defaultNamedNotOptArg):
		'method getDependee'
		ret = self._oleobj_.InvokeTypes(15, LCID, 1, (9, 0), ((3, 1),),nIndex
			)
		if ret is not None:
			ret = Dispatch(ret, 'getDependee', '{494F6723-CCB2-43EC-8A32-4854E5B63430}')
		return ret

	# Result is of type ITransmittalFile
	def getDependent(self, nIndex=defaultNamedNotOptArg):
		'method getDependent'
		ret = self._oleobj_.InvokeTypes(14, LCID, 1, (9, 0), ((3, 1),),nIndex
			)
		if ret is not None:
			ret = Dispatch(ret, 'getDependent', '{494F6723-CCB2-43EC-8A32-4854E5B63430}')
		return ret

	_prop_map_get_ = {
		"DwgTrustInfo": (1610743825, 2, (3, 0), (), "DwgTrustInfo", None),
		"FileType": (10, 2, (3, 0), (), "FileType", None),
		"customData": (1610743837, 2, (3, 0), (), "customData", None),
		"database": (13, 2, (9, 0), (), "database", None),
		"fileExists": (2, 2, (3, 0), (), "fileExists", None),
		"fileRecovered": (1610743830, 2, (3, 0), (), "fileRecovered", None),
		"fileSize": (4, 2, (3, 0), (), "fileSize", None),
		"fullPathForTarget": (9, 2, (8, 0), (), "fullPathForTarget", None),
		"includeInTransmittal": (8, 2, (3, 0), (), "includeInTransmittal", None),
		"isEncrypted": (1610743829, 2, (3, 0), (), "isEncrypted", None),
		"isReaderror": (1610743828, 2, (3, 0), (), "isReaderror", None),
		"isReadonly": (1610743827, 2, (3, 0), (), "isReadonly", None),
		"isSigned": (1610743826, 2, (3, 0), (), "isSigned", None),
		"isUnloadedReference": (1610743839, 2, (3, 0), (), "isUnloadedReference", None),
		"lastModifiedTime": (5, 2, (7, 0), (), "lastModifiedTime", None),
		"numberOfDependees": (12, 2, (3, 0), (), "numberOfDependees", None),
		"numberOfDependents": (11, 2, (3, 0), (), "numberOfDependents", None),
		"originalFileMaintenanceVersion": (1610743833, 2, (3, 0), (), "originalFileMaintenanceVersion", None),
		"originalFileVersion": (1610743832, 2, (3, 0), (), "originalFileVersion", None),
		"shouldProcessFile": (1610743834, 2, (3, 0), (), "shouldProcessFile", None),
		"sourcePath": (1, 2, (8, 0), (), "sourcePath", None),
		"targetSubPath": (6, 2, (8, 0), (), "targetSubPath", None),
		"type": (7, 2, (3, 0), (), "type", None),
		"version": (3, 2, (8, 0), (), "version", None),
	}
	_prop_map_put_ = {
		"customData": ((1610743837, LCID, 4, 0),()),
		"fileRecovered": ((1610743830, LCID, 4, 0),()),
		"includeInTransmittal": ((8, LCID, 4, 0),()),
		"isUnloadedReference": ((1610743839, LCID, 4, 0),()),
		"shouldProcessFile": ((1610743834, LCID, 4, 0),()),
		"targetSubPath": ((6, LCID, 4, 0),()),
		"version": ((3, LCID, 4, 0),()),
	}
	def __iter__(self):
		"Return a Python iterator for this object"
		try:
			ob = self._oleobj_.InvokeTypes(-4,LCID,3,(13, 10),())
		except pythoncom.error:
			raise TypeError("This object does not support enumeration")
		return win32com.client.util.Iterator(ob, None)

class ITransmittalFileOverwriteHandler(DispatchBaseClass):
	'Autodesk internal use only -- ITransmittalFileOverwriteHandler Interface'
	CLSID = IID('{A5A24764-DD5D-43C0-B720-E48C386C9CC9}')
	coclass_clsid = IID('{16A847C9-8BA2-403D-98BC-1FEA67C0A8CC}')

	def overwriteHandler(self, pFile=defaultNamedNotOptArg, bstrDest=defaultNamedNotOptArg):
		'Autodesk internal use only -- method overwriteHandler'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (3, 0), ((9, 1), (8, 1)),pFile
			, bstrDest)

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

class ITransmittalFilesGraph(DispatchBaseClass):
	'Autodesk internal use only -- ITransmittalFilesGraph Interface'
	CLSID = IID('{61603FA1-F460-4DFA-9180-449AC4637A22}')
	coclass_clsid = IID('{5A6B063C-3DD0-4B58-AB43-B5844E57912F}')

	def addEdge(self, pTransmitFileFrom=defaultNamedNotOptArg, pTransmitFileTo=defaultNamedNotOptArg):
		'method addEdge'
		return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((9, 1), (9, 1)),pTransmitFileFrom
			, pTransmitFileTo)

	# Result is of type ITransmittalFile
	def getAt(self, nIndex=defaultNamedNotOptArg):
		'method getAt'
		ret = self._oleobj_.InvokeTypes(5, LCID, 1, (9, 0), ((3, 1),),nIndex
			)
		if ret is not None:
			ret = Dispatch(ret, 'getAt', '{494F6723-CCB2-43EC-8A32-4854E5B63430}')
		return ret

	def getNumberOfFiles(self, bIncludeMissingFiles=defaultNamedNotOptArg, bIncludeUnselectedFiles=defaultNamedNotOptArg):
		'method getNumberOfFiles'
		return self._oleobj_.InvokeTypes(4, LCID, 1, (3, 0), ((3, 1), (3, 1)),bIncludeMissingFiles
			, bIncludeUnselectedFiles)

	# Result is of type ITransmittalFile
	def getRoot(self):
		'method getRoot'
		ret = self._oleobj_.InvokeTypes(1, LCID, 1, (9, 0), (),)
		if ret is not None:
			ret = Dispatch(ret, 'getRoot', '{494F6723-CCB2-43EC-8A32-4854E5B63430}')
		return ret

	def removeEdge(self, pTransmitFile=defaultNamedNotOptArg, pParentFile=defaultNamedNotOptArg):
		'method remove'
		return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 1), (9, 1)),pTransmitFile
			, pParentFile)

	def reset(self):
		'method reset'
		return self._oleobj_.InvokeTypes(6, LCID, 1, (24, 0), (),)

	# The method totalBytes is actually a property, but must be used as a method to correctly pass the arguments
	def totalBytes(self, bIncludedFilesOnly=defaultNamedNotOptArg):
		'property totalBytes'
		return self._oleobj_.InvokeTypes(7, LCID, 2, (19, 0), ((3, 1),),bIncludedFilesOnly
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

class ITransmittalFilesGraphPrivate(DispatchBaseClass):
	'Autodesk internal use only -- ITransmittalFilesGraphPrivate Interface'
	CLSID = IID('{FB1A140E-0DA9-4595-B64B-397CE59E41F1}')
	coclass_clsid = IID('{37A751D5-EEF1-485F-ABD0-02C8B636C218}')

	def add(self, pGraphNode=defaultNamedNotOptArg, pParentFile=defaultNamedNotOptArg):
		'Autodesk internal use only -- method add'
		return self._oleobj_.InvokeTypes(2, LCID, 1, (3, 0), ((20, 1), (9, 1)),pGraphNode
			, pParentFile)

	def nodeAt(self, nIndex=defaultNamedNotOptArg):
		'Autodesk internal use only -- method nodeAt'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (20, 0), ((3, 1),),nIndex
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
	'Autodesk internal use only -- ITransmittalInfo Interface'
	CLSID = IID('{4E95DC11-225E-46B8-A647-FBB50DB3AB45}')
	coclass_clsid = IID('{FD1AF231-C232-42BD-AD6A-F3E1CA076972}')

	_prop_map_get_ = {
		"BindType": (30, 2, (3, 0), (), "BindType", None),
		"DGNUnderlayRelativePath": (21, 2, (3, 0), (), "DGNUnderlayRelativePath", None),
		"DWFUnderlayRelativePath": (22, 2, (3, 0), (), "DWFUnderlayRelativePath", None),
		"PDFUnderlayRelativePath": (41, 2, (3, 0), (), "PDFUnderlayRelativePath", None),
		"checkAndfixErrors": (34, 2, (3, 0), (), "checkAndfixErrors", None),
		"convertSignedFiles": (33, 2, (3, 0), (), "convertSignedFiles", None),
		"createBackupFiles": (32, 2, (3, 0), (), "createBackupFiles", None),
		"dataLinkRelativePath": (26, 2, (3, 0), (), "dataLinkRelativePath", None),
		"defaultOverwriteValue": (4, 2, (3, 0), (), "defaultOverwriteValue", None),
		"depathXrefs": (29, 2, (3, 0), (), "depathXrefs", None),
		"destinationRoot": (1, 2, (8, 0), (), "destinationRoot", None),
		"imageRelativePath": (7, 2, (3, 0), (), "imageRelativePath", None),
		"inConvertMode": (37, 2, (3, 0), (), "inConvertMode", None),
		"includeDGNUnderlay": (19, 2, (3, 0), (), "includeDGNUnderlay", None),
		"includeDWFUnderlay": (20, 2, (3, 0), (), "includeDWFUnderlay", None),
		"includeDataLinkFile": (25, 2, (3, 0), (), "includeDataLinkFile", None),
		"includeFontFile": (10, 2, (3, 0), (), "includeFontFile", None),
		"includeImageFile": (9, 2, (3, 0), (), "includeImageFile", None),
		"includeInventorProjectFile": (43, 2, (3, 0), (), "includeInventorProjectFile", None),
		"includeInventorReferences": (42, 2, (3, 0), (), "includeInventorReferences", None),
		"includeMaterialTextureFile": (23, 2, (3, 0), (), "includeMaterialTextureFile", None),
		"includeNestedOverlayXrefDwg": (18, 2, (3, 0), (), "includeNestedOverlayXrefDwg", None),
		"includePDFUnderlay": (40, 2, (3, 0), (), "includePDFUnderlay", None),
		"includePhotometricWebFile": (24, 2, (3, 0), (), "includePhotometricWebFile", None),
		"includePlotFile": (11, 2, (3, 0), (), "includePlotFile", None),
		"includeUnloadedReferences": (31, 2, (3, 0), (), "includeUnloadedReferences", None),
		"includeUnloadedXrefDwg": (17, 2, (3, 0), (), "includeUnloadedXrefDwg", None),
		"includeXrefDwg": (8, 2, (3, 0), (), "includeXrefDwg", None),
		"organizedFolder": (16, 2, (3, 0), (), "organizedFolder", None),
		# Method 'overwriteFileHandler' returns object of type 'ITransmittalFileOverwriteHandler'
		"overwriteFileHandler": (39, 2, (9, 0), (), "overwriteFileHandler", '{A5A24764-DD5D-43C0-B720-E48C386C9CC9}'),
		"plotConfigFilePath": (14, 2, (8, 0), (), "plotConfigFilePath", None),
		"plotStyleTablePath": (13, 2, (8, 0), (), "plotStyleTablePath", None),
		"preserveSubdirs": (3, 2, (3, 0), (), "preserveSubdirs", None),
		"proxifyAEC": (38, 2, (3, 0), (), "proxifyAEC", None),
		"purgeDatabase": (28, 2, (3, 0), (), "purgeDatabase", None),
		"relativePath": (15, 2, (8, 0), (), "relativePath", None),
		"replacePageSetups": (35, 2, (3, 0), (), "replacePageSetups", None),
		"replacePageSetupsWith": (36, 2, (8, 0), (), "replacePageSetupsWith", None),
		"resetPlotter": (12, 2, (3, 0), (), "resetPlotter", None),
		"saveVersion": (2, 2, (3, 0), (), "saveVersion", None),
		"visualFidelity": (27, 2, (3, 0), (), "visualFidelity", None),
		"xrefRelativePath": (6, 2, (3, 0), (), "xrefRelativePath", None),
	}
	_prop_map_put_ = {
		"BindType": ((30, LCID, 4, 0),()),
		"DGNUnderlayRelativePath": ((21, LCID, 4, 0),()),
		"DWFUnderlayRelativePath": ((22, LCID, 4, 0),()),
		"PDFUnderlayRelativePath": ((41, LCID, 4, 0),()),
		"checkAndfixErrors": ((34, LCID, 4, 0),()),
		"convertSignedFiles": ((33, LCID, 4, 0),()),
		"createBackupFiles": ((32, LCID, 4, 0),()),
		"dataLinkRelativePath": ((26, LCID, 4, 0),()),
		"defaultOverwriteValue": ((4, LCID, 4, 0),()),
		"depathXrefs": ((29, LCID, 4, 0),()),
		"destinationRoot": ((1, LCID, 4, 0),()),
		"imageRelativePath": ((7, LCID, 4, 0),()),
		"inConvertMode": ((37, LCID, 4, 0),()),
		"includeDGNUnderlay": ((19, LCID, 4, 0),()),
		"includeDWFUnderlay": ((20, LCID, 4, 0),()),
		"includeDataLinkFile": ((25, LCID, 4, 0),()),
		"includeFontFile": ((10, LCID, 4, 0),()),
		"includeImageFile": ((9, LCID, 4, 0),()),
		"includeInventorProjectFile": ((43, LCID, 4, 0),()),
		"includeInventorReferences": ((42, LCID, 4, 0),()),
		"includeMaterialTextureFile": ((23, LCID, 4, 0),()),
		"includeNestedOverlayXrefDwg": ((18, LCID, 4, 0),()),
		"includePDFUnderlay": ((40, LCID, 4, 0),()),
		"includePhotometricWebFile": ((24, LCID, 4, 0),()),
		"includePlotFile": ((11, LCID, 4, 0),()),
		"includeUnloadedReferences": ((31, LCID, 4, 0),()),
		"includeUnloadedXrefDwg": ((17, LCID, 4, 0),()),
		"includeXrefDwg": ((8, LCID, 4, 0),()),
		"organizedFolder": ((16, LCID, 4, 0),()),
		"overwriteFileHandler": ((39, LCID, 4, 0),()),
		"plotConfigFilePath": ((14, LCID, 4, 0),()),
		"plotStyleTablePath": ((13, LCID, 4, 0),()),
		"preserveSubdirs": ((3, LCID, 4, 0),()),
		"proxifyAEC": ((38, LCID, 4, 0),()),
		"purgeDatabase": ((28, LCID, 4, 0),()),
		"relativePath": ((15, LCID, 4, 0),()),
		"replacePageSetups": ((35, LCID, 4, 0),()),
		"replacePageSetupsWith": ((36, LCID, 4, 0),()),
		"resetPlotter": ((12, LCID, 4, 0),()),
		"saveVersion": ((2, LCID, 4, 0),()),
		"visualFidelity": ((27, LCID, 4, 0),()),
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
	CLSID = IID('{AA41166A-7FED-4700-80DD-653857913ECE}')
	coclass_clsid = IID('{A994CA23-17EB-4C43-8345-EDEE893F2186}')

	def OpenDrawingInEditor(self, Val=defaultNamedNotOptArg):
		'Autodesk internal use only -- method addFile'
		return self._oleobj_.InvokeTypes(33, LCID, 1, (24, 0), ((3, 1),),Val
			)

	def addDrawingFile(self, fullpathname=defaultNamedNotOptArg, ppIAddedFile=pythoncom.Missing):
		'method addDrawingFile'
		return self._ApplyTypes_(7, 1, (3, 0), ((8, 1), (16393, 2)), 'addDrawingFile', None,fullpathname
			, ppIAddedFile)

	def addFile(self, bstrFullPath=defaultNamedNotOptArg, pIParentFile=defaultNamedNotOptArg, bAddedBy3rdParty=defaultNamedNotOptArg, ppIAddedFile=pythoncom.Missing):
		'method addFile'
		return self._ApplyTypes_(5, 1, (3, 0), ((8, 1), (9, 1), (3, 1), (16393, 2)), 'addFile', None,bstrFullPath
			, pIParentFile, bAddedBy3rdParty, ppIAddedFile)

	def addFileWithVersioning(self, bstrFullPath=defaultNamedNotOptArg, bstrVersion=defaultNamedNotOptArg, pIParentFile=defaultNamedNotOptArg, bAddedBy3rdParty=defaultNamedNotOptArg
			, ppIAddedFile=pythoncom.Missing):
		'Autodesk internal use only -- method addFile'
		return self._ApplyTypes_(32, 1, (3, 0), ((8, 1), (8, 1), (9, 1), (3, 1), (16393, 2)), 'addFileWithVersioning', None,bstrFullPath
			, bstrVersion, pIParentFile, bAddedBy3rdParty, ppIAddedFile)

	def addSheetSelset(self, pISheetSelset=defaultNamedNotOptArg, includeSSFiles=defaultNamedNotOptArg):
		'method addSheetSelset'
		ret = self._oleobj_.InvokeTypes(9, LCID, 1, (13, 0), ((13, 1), (3, 1)),pISheetSelset
			, includeSSFiles)
		if ret is not None:
			# See if this IUnknown is really an IDispatch
			try:
				ret = ret.QueryInterface(pythoncom.IID_IDispatch)
			except pythoncom.error:
				return ret
			ret = Dispatch(ret, 'addSheetSelset', None)
		return ret

	def addSheets(self, sheets=defaultNamedNotOptArg, includeSSFiles=defaultNamedNotOptArg):
		'method addSheets'
		ret = self._oleobj_.InvokeTypes(8, LCID, 1, (13, 0), ((8205, 1), (3, 1)),sheets
			, includeSSFiles)
		if ret is not None:
			# See if this IUnknown is really an IDispatch
			try:
				ret = ret.QueryInterface(pythoncom.IID_IDispatch)
			except pythoncom.error:
				return ret
			ret = Dispatch(ret, 'addSheets', None)
		return ret

	def addToReport(self, bstrTextToAdd=defaultNamedNotOptArg, nIndex=defaultNamedNotOptArg):
		'method addToReport'
		return self._oleobj_.InvokeTypes(6, LCID, 1, (3, 0), ((8, 1), (3, 1)),bstrTextToAdd
			, nIndex)

	def addUserNotesToReport(self, bstrUserNotes=defaultNamedNotOptArg):
		'Autodesk internal use only -- method addUserNotesToReport'
		return self._oleobj_.InvokeTypes(27, LCID, 1, (24, 0), ((8, 0),),bstrUserNotes
			)

	def archiveSheetSet(self, pISheetSet=defaultNamedNotOptArg, includeSSFiles=defaultNamedNotOptArg):
		'method archiveSheetSet'
		ret = self._oleobj_.InvokeTypes(10, LCID, 1, (13, 0), ((13, 1), (3, 1)),pISheetSet
			, includeSSFiles)
		if ret is not None:
			# See if this IUnknown is really an IDispatch
			try:
				ret = ret.QueryInterface(pythoncom.IID_IDispatch)
			except pythoncom.error:
				return ret
			ret = Dispatch(ret, 'archiveSheetSet', None)
		return ret

	def bindXrefHook(self, pHandler=defaultNamedNotOptArg, add=defaultNamedNotOptArg):
		'Autodesk internal use only -- method bindXrefHook'
		return self._oleobj_.InvokeTypes(19, LCID, 1, (24, 0), ((9, 1), (3, 1)),pHandler
			, add)

	def cancelDatabaseNotification(self, pHandler=defaultNamedNotOptArg):
		'method cancelDatabaseNotification'
		return self._oleobj_.InvokeTypes(4, LCID, 1, (24, 0), ((9, 1),),pHandler
			)

	def cancelSheetSetNotification(self, pHandler=defaultNamedNotOptArg):
		'method cancelSheetSetNotification'
		return self._oleobj_.InvokeTypes(18, LCID, 1, (24, 0), ((9, 1),),pHandler
			)

	def cancelSubscriptionToAddFileNotification(self, pHandler=defaultNamedNotOptArg):
		'method cancelSubscriptionToAddFileNotification'
		return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((9, 1),),pHandler
			)

	def copyFiles(self):
		'Autodesk internal use only -- method copyFiles'
		return self._oleobj_.InvokeTypes(29, LCID, 1, (24, 0), (),)

	def createTransmittalPackage(self):
		'method createTransmittalPackage'
		return self._oleobj_.InvokeTypes(11, LCID, 1, (24, 0), (),)

	def getConvertReport(self, bFullVersion=defaultNamedNotOptArg, bMarkup=defaultNamedNotOptArg):
		'Autodesk internal use only -- method getConvertReport'
		# Result is a Unicode object
		return self._oleobj_.InvokeTypes(21, LCID, 1, (8, 0), ((3, 1), (3, 1)),bFullVersion
			, bMarkup)

	def getConvertStatusFileBag(self, status=defaultNamedNotOptArg):
		'Autodesk internal use only -- method getConvertStatusFileBag'
		return self._ApplyTypes_(22, 1, (8205, 0), ((3, 1),), 'getConvertStatusFileBag', None,status
			)

	def getDwgDependencies(self, bstrDwgName=defaultNamedNotOptArg, bstrPlotStyleTablePath=defaultNamedNotOptArg, bstrPlotConfigFilePath=defaultNamedNotOptArg):
		'Autodesk internal use only -- method getDwgDependencies'
		return self._oleobj_.InvokeTypes(30, LCID, 1, (24, 0), ((8, 1), (8, 1), (8, 1)),bstrDwgName
			, bstrPlotStyleTablePath, bstrPlotConfigFilePath)

	def getLargeFiles(self):
		'Autodesk internal use only -- method getLargeFiles'
		# Result is a Unicode object
		return self._oleobj_.InvokeTypes(34, LCID, 1, (8, 0), (),)

	def getReport(self):
		'Autodesk internal use only -- method getReport'
		# Result is a Unicode object
		return self._oleobj_.InvokeTypes(31, LCID, 1, (8, 0), (),)

	# Result is of type ITransmittalFilesGraph
	def getTransmittalGraphInterface(self):
		'method getTransmittalGraphInterface'
		ret = self._oleobj_.InvokeTypes(14, LCID, 1, (9, 0), (),)
		if ret is not None:
			ret = Dispatch(ret, 'getTransmittalGraphInterface', '{61603FA1-F460-4DFA-9180-449AC4637A22}')
		return ret

	# Result is of type ITransmittalInfo
	def getTransmittalInfoInterface(self):
		'method getTransmittalInfoInterface'
		ret = self._oleobj_.InvokeTypes(13, LCID, 1, (9, 0), (),)
		if ret is not None:
			ret = Dispatch(ret, 'getTransmittalInfoInterface', '{4E95DC11-225E-46B8-A647-FBB50DB3AB45}')
		return ret

	def getTransmittalReport(self):
		'method getTransmittalReport'
		# Result is a Unicode object
		return self._oleobj_.InvokeTypes(12, LCID, 1, (8, 0), (),)

	# Result is of type ITransmittalFilesGraph
	def graphInterfacePtr(self):
		'Autodesk internal use only -- method graphInterfacePtr'
		ret = self._oleobj_.InvokeTypes(28, LCID, 1, (9, 0), (),)
		if ret is not None:
			ret = Dispatch(ret, 'graphInterfacePtr', '{61603FA1-F460-4DFA-9180-449AC4637A22}')
		return ret

	# Result is of type ITransmittalInfo
	def infoInterfacePtr(self):
		'Autodesk internal use only -- method infoInterfacePtr'
		ret = self._oleobj_.InvokeTypes(26, LCID, 1, (9, 0), (),)
		if ret is not None:
			ret = Dispatch(ret, 'infoInterfacePtr', '{4E95DC11-225E-46B8-A647-FBB50DB3AB45}')
		return ret

	def putConversionFormatForReport(self, bstrFormat=defaultNamedNotOptArg):
		'Autodesk internal use only -- method putConversionFormatForReport'
		return self._oleobj_.InvokeTypes(23, LCID, 1, (24, 0), ((8, 1),),bstrFormat
			)

	def putConversionLocationForReport(self, bstrLocation=defaultNamedNotOptArg):
		'Autodesk internal use only -- method putConversionLocationForReport'
		return self._oleobj_.InvokeTypes(25, LCID, 1, (24, 0), ((8, 1),),bstrLocation
			)

	def putConversionPackageTypeForReport(self, bstrPackType=defaultNamedNotOptArg):
		'Autodesk internal use only -- method putConversionPackageTypeForReport'
		return self._oleobj_.InvokeTypes(24, LCID, 1, (24, 0), ((8, 1),),bstrPackType
			)

	def recalcTargetSubPath(self):
		'method recalcTargetSubPath'
		return self._oleobj_.InvokeTypes(15, LCID, 1, (24, 0), (),)

	def setProgressMeter(self, meter=defaultNamedNotOptArg, add=defaultNamedNotOptArg):
		'method setProgressMeter'
		return self._oleobj_.InvokeTypes(16, LCID, 1, (24, 0), ((9, 1), (3, 1)),meter
			, add)

	def subscribeDatabaseNotification(self, pHandler=defaultNamedNotOptArg):
		'method subscribeDatabaseNotification'
		return self._oleobj_.InvokeTypes(3, LCID, 1, (24, 0), ((9, 1),),pHandler
			)

	def subscribeSheetSetNotification(self, pHandler=defaultNamedNotOptArg):
		'method subscribeSheetSetNotification'
		return self._oleobj_.InvokeTypes(17, LCID, 1, (24, 0), ((9, 1),),pHandler
			)

	def subscribeToAddFileNotification(self, pHandler=defaultNamedNotOptArg):
		'method subscribeToAddFileNotification'
		return self._oleobj_.InvokeTypes(1, LCID, 1, (24, 0), ((9, 1),),pHandler
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

class ITransmittalProgressHandler(DispatchBaseClass):
	'ITransmittalProgressHandler Interface'
	CLSID = IID('{0D6FB8D0-D89F-4080-B392-0EAA048B82D4}')
	coclass_clsid = IID('{48FBD5ED-7C0A-43CA-9D29-99FB782A0D38}')

	def isCanceled(self, cancelled=pythoncom.Missing):
		'method isCanceled'
		return self._ApplyTypes_(1, 1, (24, 0), ((16387, 2),), 'isCanceled', None,cancelled
			)

	def processingFile(self, fname=defaultNamedNotOptArg):
		'method processingFile'
		return self._oleobj_.InvokeTypes(2, LCID, 1, (24, 0), ((8, 1),),fname
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

class ITransmittalSheetSetNotification(DispatchBaseClass):
	'ITransmittalSheetSetNotification Interface'
	CLSID = IID('{B236E67D-CFC4-4C4D-852D-5EC56DA574DC}')
	coclass_clsid = None

	def postSheetSetProcessing(self, pISheetSet=defaultNamedNotOptArg, pFile=defaultNamedNotOptArg, pTransmit=defaultNamedNotOptArg):
		return self._oleobj_.InvokeTypes(1610743809, LCID, 1, (24, 0), ((13, 1), (9, 1), (9, 1)),pISheetSet
			, pFile, pTransmit)

	def preSheetSetProcessing(self, pISheetSet=defaultNamedNotOptArg, pFile=defaultNamedNotOptArg, pTransmit=defaultNamedNotOptArg):
		return self._oleobj_.InvokeTypes(1610743808, LCID, 1, (24, 0), ((13, 1), (9, 1), (9, 1)),pISheetSet
			, pFile, pTransmit)

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

from win32com.client import CoClassBaseClass
class TransmittalAddFileNotificationHandler(CoClassBaseClass): # A CoClass
	# TransmittalAddFileNotificationHandler Class
	CLSID = IID('{6BC47508-D5EF-4DD5-9A59-376B92DCFE7A}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalAddFileNotificationHandler,
	]
	default_interface = ITransmittalAddFileNotificationHandler

class TransmittalDatabaseNotificationHandler(CoClassBaseClass): # A CoClass
	# TransmittalDatabaseNotificationHandler Class
	CLSID = IID('{11AA8559-7D9A-4B26-B550-23E6D62EE9C6}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalDatabaseNotificationHandler,
	]
	default_interface = ITransmittalDatabaseNotificationHandler

# This CoClass is known by the name 'Transmittal.TransmittalFile.19'
class TransmittalFile(CoClassBaseClass): # A CoClass
	# TransmittalFile Class
	CLSID = IID('{BC573B3C-4123-4F95-8DD4-DF3BEC317D67}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalFile,
	]
	default_interface = ITransmittalFile

class TransmittalFileOverwriteHandler(CoClassBaseClass): # A CoClass
	# Autodesk internal use only -- TransmittalFileOverwriteHandler Class
	CLSID = IID('{16A847C9-8BA2-403D-98BC-1FEA67C0A8CC}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalFileOverwriteHandler,
	]
	default_interface = ITransmittalFileOverwriteHandler

# This CoClass is known by the name 'Transmittal.TransmittalFilesGraph.19'
class TransmittalFilesGraph(CoClassBaseClass): # A CoClass
	# Autodesk internal use only -- TransmittalFilesGraph Class
	CLSID = IID('{5A6B063C-3DD0-4B58-AB43-B5844E57912F}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalFilesGraph,
	]
	default_interface = ITransmittalFilesGraph

class TransmittalFilesGraphPrivate(CoClassBaseClass): # A CoClass
	# Autodesk internal use only -- TransmittalFilesGraphPrivate Class
	CLSID = IID('{37A751D5-EEF1-485F-ABD0-02C8B636C218}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalFilesGraphPrivate,
	]
	default_interface = ITransmittalFilesGraphPrivate

# This CoClass is known by the name 'Transmittal.TransmittalInfo.19'
class TransmittalInfo(CoClassBaseClass): # A CoClass
	# Autodesk internal use only -- TransmittalInfo Class
	CLSID = IID('{FD1AF231-C232-42BD-AD6A-F3E1CA076972}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalInfo,
	]
	default_interface = ITransmittalInfo

# This CoClass is known by the name 'Transmittal.TransmittalOperation.19'
class TransmittalOperation(CoClassBaseClass): # A CoClass
	# TransmittalOperation Class
	CLSID = IID('{A994CA23-17EB-4C43-8345-EDEE893F2186}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalOperation,
	]
	default_interface = ITransmittalOperation

class TransmittalProgressHandler(CoClassBaseClass): # A CoClass
	# TransmittalProgressHandler Class
	CLSID = IID('{48FBD5ED-7C0A-43CA-9D29-99FB782A0D38}')
	coclass_sources = [
	]
	coclass_interfaces = [
		ITransmittalProgressHandler,
	]
	default_interface = ITransmittalProgressHandler

IRelocateDrawing_vtables_dispatch_ = 1
IRelocateDrawing_vtables_ = [
	(( 'addDatabase' , 'db' , ), 1, (1, (), [ (9, 1, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 64 , )),
	(( 'supressNotification' , 'pVal' , ), 2, (2, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 64 , )),
	(( 'supressNotification' , 'pVal' , ), 2, (2, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 72 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedXref' , 'pVal' , ), 3, (3, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedXref' , 'pVal' , ), 3, (3, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 88 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedImage' , 'pVal' , ), 4, (4, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedImage' , 'pVal' , ), 4, (4, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedDGNUnderlay' , 'pVal' , ), 5, (5, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedDGNUnderlay' , 'pVal' , ), 5, (5, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 120 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedDWFUnderlay' , 'pVal' , ), 6, (6, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 128 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedDWFUnderlay' , 'pVal' , ), 6, (6, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 136 , (3, 0, None, None) , 64 , )),
]

IRelocateDrawing2_vtables_dispatch_ = 1
IRelocateDrawing2_vtables_ = [
	(( 'repathExcludedDataLink' , 'pVal' , ), 7, (7, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedDataLink' , 'pVal' , ), 7, (7, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 152 , (3, 0, None, None) , 64 , )),
]

IRelocateDrawing3_vtables_dispatch_ = 1
IRelocateDrawing3_vtables_ = [
	(( 'repathExcludedPDFUnderlay' , 'pVal' , ), 8, (8, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 160 , (3, 0, None, None) , 64 , )),
	(( 'repathExcludedPDFUnderlay' , 'pVal' , ), 8, (8, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 168 , (3, 0, None, None) , 64 , )),
]

ITransmittalAddFileNotificationHandler_vtables_dispatch_ = 1
ITransmittalAddFileNotificationHandler_vtables_ = [
	(( 'addFileNotificationHandler' , 'pFile' , 'pTransmit' , ), 1, (1, (), [ (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , 
			 (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'beginFilesGraphCreation' , 'pTransmit' , ), 2, (2, (), [ (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'endFilesGraphCreation' , 'pTransmit' , ), 3, (3, (), [ (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
]

ITransmittalDatabaseNotificationHandler_vtables_dispatch_ = 1
ITransmittalDatabaseNotificationHandler_vtables_ = [
	(( 'preDatabaseProcessing' , 'pDatabase' , 'pFile' , 'pTransmit' , 'mod' , 
			 ), 1, (1, (), [ (9, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'postDatabaseProcessing' , 'pDatabase' , 'pFile' , 'pTransmit' , 'mod' , 
			 ), 2, (2, (), [ (9, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'convertDatabase' , 'pDatabase' , 'pFile' , 'pTransmit' , 'mod' , 
			 ), 3, (3, (), [ (9, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
]

ITransmittalFile_vtables_dispatch_ = 1
ITransmittalFile_vtables_ = [
	(( 'sourcePath' , 'pVal' , ), 1, (1, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'fileExists' , 'pVal' , ), 2, (2, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'version' , 'pVal' , ), 3, (3, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'fileSize' , 'pVal' , ), 4, (4, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'lastModifiedTime' , 'pVal' , ), 5, (5, (), [ (16391, 10, None, None) , ], 1 , 2 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'targetSubPath' , 'pVal' , ), 6, (6, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
	(( 'targetSubPath' , 'pVal' , ), 6, (6, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
	(( 'type' , 'pVal' , ), 7, (7, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
	(( 'includeInTransmittal' , 'pVal' , ), 8, (8, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'includeInTransmittal' , 'pVal' , ), 8, (8, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'fullPathForTarget' , 'pVal' , ), 9, (9, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'FileType' , 'pVal' , ), 10, (10, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'numberOfDependents' , 'pVal' , ), 11, (11, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
	(( 'numberOfDependees' , 'pVal' , ), 12, (12, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'database' , 'ppDatabase' , ), 13, (13, (), [ (16393, 10, None, None) , ], 1 , 2 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'getDependent' , 'nIndex' , 'ppFile' , ), 14, (14, (), [ (3, 1, None, None) , 
			 (16393, 10, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'getDependee' , 'nIndex' , 'ppFile' , ), 15, (15, (), [ (3, 1, None, None) , 
			 (16393, 10, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'DwgTrustInfo' , 'pVal' , ), 1610743825, (1610743825, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 192 , (3, 0, None, None) , 64 , )),
	(( 'isSigned' , 'pVal' , ), 1610743826, (1610743826, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 200 , (3, 0, None, None) , 64 , )),
	(( 'isReadonly' , 'pVal' , ), 1610743827, (1610743827, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 208 , (3, 0, None, None) , 64 , )),
	(( 'isReaderror' , 'pVal' , ), 1610743828, (1610743828, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 64 , )),
	(( 'isEncrypted' , 'pVal' , ), 1610743829, (1610743829, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 224 , (3, 0, None, None) , 64 , )),
	(( 'fileRecovered' , 'pVal' , ), 1610743830, (1610743830, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 64 , )),
	(( 'fileRecovered' , 'pVal' , ), 1610743830, (1610743830, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 64 , )),
	(( 'originalFileVersion' , 'pVal' , ), 1610743832, (1610743832, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 64 , )),
	(( 'originalFileMaintenanceVersion' , 'pVal' , ), 1610743833, (1610743833, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 256 , (3, 0, None, None) , 64 , )),
	(( 'shouldProcessFile' , 'newVal' , ), 1610743834, (1610743834, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 264 , (3, 0, None, None) , 64 , )),
	(( 'shouldProcessFile' , 'newVal' , ), 1610743834, (1610743834, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 272 , (3, 0, None, None) , 64 , )),
	(( 'version' , 'pVal' , ), 3, (3, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 280 , (3, 0, None, None) , 64 , )),
	(( 'customData' , 'Val' , ), 1610743837, (1610743837, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 288 , (3, 0, None, None) , 64 , )),
	(( 'customData' , 'Val' , ), 1610743837, (1610743837, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 296 , (3, 0, None, None) , 64 , )),
	(( 'isUnloadedReference' , 'pVal' , ), 1610743839, (1610743839, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 304 , (3, 0, None, None) , 64 , )),
	(( 'isUnloadedReference' , 'pVal' , ), 1610743839, (1610743839, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 312 , (3, 0, None, None) , 64 , )),
]

ITransmittalFileOperationOverride_vtables_dispatch_ = 0
ITransmittalFileOperationOverride_vtables_ = [
	(( 'Open' , 'fileName' , 'attemptToRecover' , 'ppDb' , ), 1610678272, (1610678272, (), [ 
			 (16402, 1, None, None) , (3, 0, None, None) , (16408, 0, None, None) , ], 1 , 1 , 4 , 0 , 24 , (3, 0, None, None) , 0 , )),
	(( 'Close' , 'pDb' , ), 1610678273, (1610678273, (), [ (16408, 1, None, None) , ], 1 , 1 , 4 , 0 , 32 , (3, 0, None, None) , 0 , )),
	(( 'PreProcessHandling' , 'digitalSignedFiles' , 'cancelled' , ), 1610678274, (1610678274, (), [ (8205, 1, None, None) , 
			 (16387, 2, None, None) , ], 1 , 1 , 4 , 0 , 40 , (3, 0, None, None) , 0 , )),
]

ITransmittalFileOverwriteHandler_vtables_dispatch_ = 1
ITransmittalFileOverwriteHandler_vtables_ = [
	(( 'overwriteHandler' , 'pFile' , 'bstrDest' , 'pReturnedResponse' , ), 1, (1, (), [ 
			 (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (8, 1, None, None) , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
]

ITransmittalFilesGraph_vtables_dispatch_ = 1
ITransmittalFilesGraph_vtables_ = [
	(( 'getRoot' , 'ppFile' , ), 1, (1, (), [ (16393, 10, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'addEdge' , 'pTransmitFileFrom' , 'pTransmitFileTo' , ), 2, (2, (), [ (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , 
			 (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'removeEdge' , 'pTransmitFile' , 'pParentFile' , ), 3, (3, (), [ (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , 
			 (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'getNumberOfFiles' , 'bIncludeMissingFiles' , 'bIncludeUnselectedFiles' , 'pnSize' , ), 4, (4, (), [ 
			 (3, 1, None, None) , (3, 1, None, None) , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'getAt' , 'nIndex' , 'ppFile' , ), 5, (5, (), [ (3, 1, None, None) , 
			 (16393, 10, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'reset' , ), 6, (6, (), [ ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
	(( 'totalBytes' , 'bIncludedFilesOnly' , 'pVal' , ), 7, (7, (), [ (3, 1, None, None) , 
			 (16403, 10, None, None) , ], 1 , 2 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
]

ITransmittalFilesGraphPrivate_vtables_dispatch_ = 1
ITransmittalFilesGraphPrivate_vtables_ = [
	(( 'nodeAt' , 'nIndex' , 'ppGraphNode' , ), 1, (1, (), [ (3, 1, None, None) , 
			 (16404, 10, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 64 , )),
	(( 'add' , 'pGraphNode' , 'pParentFile' , 'pRV' , ), 2, (2, (), [ 
			 (20, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 64 , )),
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
	(( 'resetPlotter' , 'pVal' , ), 12, (12, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 216 , (3, 0, None, None) , 0 , )),
	(( 'resetPlotter' , 'pVal' , ), 12, (12, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 224 , (3, 0, None, None) , 0 , )),
	(( 'plotStyleTablePath' , 'pVal' , ), 13, (13, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 232 , (3, 0, None, None) , 0 , )),
	(( 'plotStyleTablePath' , 'pVal' , ), 13, (13, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 240 , (3, 0, None, None) , 0 , )),
	(( 'plotConfigFilePath' , 'pVal' , ), 14, (14, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 248 , (3, 0, None, None) , 0 , )),
	(( 'plotConfigFilePath' , 'pVal' , ), 14, (14, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 256 , (3, 0, None, None) , 0 , )),
	(( 'relativePath' , 'pVal' , ), 15, (15, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 264 , (3, 0, None, None) , 0 , )),
	(( 'relativePath' , 'pVal' , ), 15, (15, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 272 , (3, 0, None, None) , 0 , )),
	(( 'organizedFolder' , 'pVal' , ), 16, (16, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 280 , (3, 0, None, None) , 0 , )),
	(( 'organizedFolder' , 'pVal' , ), 16, (16, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 288 , (3, 0, None, None) , 0 , )),
	(( 'includeUnloadedXrefDwg' , 'pVal' , ), 17, (17, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 296 , (3, 0, None, None) , 0 , )),
	(( 'includeUnloadedXrefDwg' , 'pVal' , ), 17, (17, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 304 , (3, 0, None, None) , 0 , )),
	(( 'includeNestedOverlayXrefDwg' , 'pVal' , ), 18, (18, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 312 , (3, 0, None, None) , 0 , )),
	(( 'includeNestedOverlayXrefDwg' , 'pVal' , ), 18, (18, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 320 , (3, 0, None, None) , 0 , )),
	(( 'includeDGNUnderlay' , 'pVal' , ), 19, (19, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 328 , (3, 0, None, None) , 0 , )),
	(( 'includeDGNUnderlay' , 'pVal' , ), 19, (19, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 336 , (3, 0, None, None) , 0 , )),
	(( 'includeDWFUnderlay' , 'pVal' , ), 20, (20, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 344 , (3, 0, None, None) , 0 , )),
	(( 'includeDWFUnderlay' , 'pVal' , ), 20, (20, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 352 , (3, 0, None, None) , 0 , )),
	(( 'DGNUnderlayRelativePath' , 'pVal' , ), 21, (21, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 360 , (3, 0, None, None) , 0 , )),
	(( 'DGNUnderlayRelativePath' , 'pVal' , ), 21, (21, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 368 , (3, 0, None, None) , 0 , )),
	(( 'DWFUnderlayRelativePath' , 'pVal' , ), 22, (22, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 376 , (3, 0, None, None) , 0 , )),
	(( 'DWFUnderlayRelativePath' , 'pVal' , ), 22, (22, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 384 , (3, 0, None, None) , 0 , )),
	(( 'includeMaterialTextureFile' , 'pVal' , ), 23, (23, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 392 , (3, 0, None, None) , 0 , )),
	(( 'includeMaterialTextureFile' , 'pVal' , ), 23, (23, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 400 , (3, 0, None, None) , 0 , )),
	(( 'includePhotometricWebFile' , 'pVal' , ), 24, (24, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 408 , (3, 0, None, None) , 0 , )),
	(( 'includePhotometricWebFile' , 'pVal' , ), 24, (24, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 416 , (3, 0, None, None) , 0 , )),
	(( 'includeDataLinkFile' , 'pVal' , ), 25, (25, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 424 , (3, 0, None, None) , 0 , )),
	(( 'includeDataLinkFile' , 'pVal' , ), 25, (25, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 432 , (3, 0, None, None) , 0 , )),
	(( 'dataLinkRelativePath' , 'pVal' , ), 26, (26, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 440 , (3, 0, None, None) , 0 , )),
	(( 'dataLinkRelativePath' , 'pVal' , ), 26, (26, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 448 , (3, 0, None, None) , 0 , )),
	(( 'visualFidelity' , 'pVal' , ), 27, (27, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 456 , (3, 0, None, None) , 0 , )),
	(( 'visualFidelity' , 'pVal' , ), 27, (27, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 464 , (3, 0, None, None) , 0 , )),
	(( 'purgeDatabase' , 'pVal' , ), 28, (28, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 472 , (3, 0, None, None) , 0 , )),
	(( 'purgeDatabase' , 'pVal' , ), 28, (28, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 480 , (3, 0, None, None) , 0 , )),
	(( 'depathXrefs' , 'pVal' , ), 29, (29, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 488 , (3, 0, None, None) , 0 , )),
	(( 'depathXrefs' , 'pVal' , ), 29, (29, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 496 , (3, 0, None, None) , 0 , )),
	(( 'BindType' , 'pVal' , ), 30, (30, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 504 , (3, 0, None, None) , 0 , )),
	(( 'BindType' , 'pVal' , ), 30, (30, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 512 , (3, 0, None, None) , 0 , )),
	(( 'includeUnloadedReferences' , 'pVal' , ), 31, (31, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 520 , (3, 0, None, None) , 0 , )),
	(( 'includeUnloadedReferences' , 'pVal' , ), 31, (31, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 528 , (3, 0, None, None) , 0 , )),
	(( 'createBackupFiles' , 'pVal' , ), 32, (32, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 536 , (3, 0, None, None) , 64 , )),
	(( 'createBackupFiles' , 'pVal' , ), 32, (32, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 544 , (3, 0, None, None) , 64 , )),
	(( 'convertSignedFiles' , 'pVal' , ), 33, (33, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 552 , (3, 0, None, None) , 64 , )),
	(( 'convertSignedFiles' , 'pVal' , ), 33, (33, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 560 , (3, 0, None, None) , 64 , )),
	(( 'checkAndfixErrors' , 'pVal' , ), 34, (34, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 568 , (3, 0, None, None) , 64 , )),
	(( 'checkAndfixErrors' , 'pVal' , ), 34, (34, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 576 , (3, 0, None, None) , 64 , )),
	(( 'replacePageSetups' , 'pVal' , ), 35, (35, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 584 , (3, 0, None, None) , 64 , )),
	(( 'replacePageSetups' , 'pVal' , ), 35, (35, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 592 , (3, 0, None, None) , 64 , )),
	(( 'replacePageSetupsWith' , 'pVal' , ), 36, (36, (), [ (16392, 10, None, None) , ], 1 , 2 , 4 , 0 , 600 , (3, 0, None, None) , 64 , )),
	(( 'replacePageSetupsWith' , 'pVal' , ), 36, (36, (), [ (8, 1, None, None) , ], 1 , 4 , 4 , 0 , 608 , (3, 0, None, None) , 64 , )),
	(( 'inConvertMode' , 'pVal' , ), 37, (37, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 616 , (3, 0, None, None) , 64 , )),
	(( 'inConvertMode' , 'pVal' , ), 37, (37, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 624 , (3, 0, None, None) , 64 , )),
	(( 'proxifyAEC' , 'pVal' , ), 38, (38, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 632 , (3, 0, None, None) , 64 , )),
	(( 'proxifyAEC' , 'pVal' , ), 38, (38, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 640 , (3, 0, None, None) , 64 , )),
	(( 'overwriteFileHandler' , 'pVal' , ), 39, (39, (), [ (16393, 10, None, "IID('{A5A24764-DD5D-43C0-B720-E48C386C9CC9}')") , ], 1 , 2 , 4 , 0 , 648 , (3, 0, None, None) , 64 , )),
	(( 'overwriteFileHandler' , 'pVal' , ), 39, (39, (), [ (9, 1, None, "IID('{A5A24764-DD5D-43C0-B720-E48C386C9CC9}')") , ], 1 , 4 , 4 , 0 , 656 , (3, 0, None, None) , 64 , )),
	(( 'includePDFUnderlay' , 'pVal' , ), 40, (40, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 664 , (3, 0, None, None) , 0 , )),
	(( 'includePDFUnderlay' , 'pVal' , ), 40, (40, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 672 , (3, 0, None, None) , 0 , )),
	(( 'PDFUnderlayRelativePath' , 'pVal' , ), 41, (41, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 680 , (3, 0, None, None) , 0 , )),
	(( 'PDFUnderlayRelativePath' , 'pVal' , ), 41, (41, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 688 , (3, 0, None, None) , 0 , )),
	(( 'includeInventorReferences' , 'pVal' , ), 42, (42, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 696 , (3, 0, None, None) , 64 , )),
	(( 'includeInventorReferences' , 'pVal' , ), 42, (42, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 704 , (3, 0, None, None) , 64 , )),
	(( 'includeInventorProjectFile' , 'pVal' , ), 43, (43, (), [ (16387, 10, None, None) , ], 1 , 2 , 4 , 0 , 712 , (3, 0, None, None) , 64 , )),
	(( 'includeInventorProjectFile' , 'pVal' , ), 43, (43, (), [ (3, 1, None, None) , ], 1 , 4 , 4 , 0 , 720 , (3, 0, None, None) , 64 , )),
]

ITransmittalOperation_vtables_dispatch_ = 1
ITransmittalOperation_vtables_ = [
	(( 'subscribeToAddFileNotification' , 'pHandler' , ), 1, (1, (), [ (9, 1, None, "IID('{DBFC8126-EB2A-43A6-A6C9-5A65F26256AF}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'cancelSubscriptionToAddFileNotification' , 'pHandler' , ), 2, (2, (), [ (9, 1, None, "IID('{DBFC8126-EB2A-43A6-A6C9-5A65F26256AF}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
	(( 'subscribeDatabaseNotification' , 'pHandler' , ), 3, (3, (), [ (9, 1, None, "IID('{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}')") , ], 1 , 1 , 4 , 0 , 72 , (3, 0, None, None) , 0 , )),
	(( 'cancelDatabaseNotification' , 'pHandler' , ), 4, (4, (), [ (9, 1, None, "IID('{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}')") , ], 1 , 1 , 4 , 0 , 80 , (3, 0, None, None) , 0 , )),
	(( 'addFile' , 'bstrFullPath' , 'pIParentFile' , 'bAddedBy3rdParty' , 'ppIAddedFile' , 
			 'pRetVal' , ), 5, (5, (), [ (8, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (3, 1, None, None) , 
			 (16393, 2, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 88 , (3, 0, None, None) , 0 , )),
	(( 'addToReport' , 'bstrTextToAdd' , 'nIndex' , 'pnIndex' , ), 6, (6, (), [ 
			 (8, 1, None, None) , (3, 1, None, None) , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 96 , (3, 0, None, None) , 0 , )),
	(( 'addDrawingFile' , 'fullpathname' , 'ppIAddedFile' , 'pRetVal' , ), 7, (7, (), [ 
			 (8, 1, None, None) , (16393, 2, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 104 , (3, 0, None, None) , 0 , )),
	(( 'addSheets' , 'sheets' , 'includeSSFiles' , 'pIRetSheetSet' , ), 8, (8, (), [ 
			 (8205, 1, None, None) , (3, 1, None, None) , (16397, 10, None, None) , ], 1 , 1 , 4 , 0 , 112 , (3, 0, None, None) , 0 , )),
	(( 'addSheetSelset' , 'pISheetSelset' , 'includeSSFiles' , 'pIRetSheetSet' , ), 9, (9, (), [ 
			 (13, 1, None, None) , (3, 1, None, None) , (16397, 10, None, None) , ], 1 , 1 , 4 , 0 , 120 , (3, 0, None, None) , 0 , )),
	(( 'archiveSheetSet' , 'pISheetSet' , 'includeSSFiles' , 'pIRetSheetSet' , ), 10, (10, (), [ 
			 (13, 1, None, None) , (3, 1, None, None) , (16397, 10, None, None) , ], 1 , 1 , 4 , 0 , 128 , (3, 0, None, None) , 0 , )),
	(( 'createTransmittalPackage' , ), 11, (11, (), [ ], 1 , 1 , 4 , 0 , 136 , (3, 0, None, None) , 0 , )),
	(( 'getTransmittalReport' , 'bstrReport' , ), 12, (12, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 144 , (3, 0, None, None) , 0 , )),
	(( 'getTransmittalInfoInterface' , 'ppIInfo' , ), 13, (13, (), [ (16393, 10, None, "IID('{4E95DC11-225E-46B8-A647-FBB50DB3AB45}')") , ], 1 , 1 , 4 , 0 , 152 , (3, 0, None, None) , 0 , )),
	(( 'getTransmittalGraphInterface' , 'ppIGraph' , ), 14, (14, (), [ (16393, 10, None, "IID('{61603FA1-F460-4DFA-9180-449AC4637A22}')") , ], 1 , 1 , 4 , 0 , 160 , (3, 0, None, None) , 0 , )),
	(( 'recalcTargetSubPath' , ), 15, (15, (), [ ], 1 , 1 , 4 , 0 , 168 , (3, 0, None, None) , 0 , )),
	(( 'setProgressMeter' , 'meter' , 'add' , ), 16, (16, (), [ (9, 1, None, "IID('{0D6FB8D0-D89F-4080-B392-0EAA048B82D4}')") , 
			 (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 176 , (3, 0, None, None) , 0 , )),
	(( 'subscribeSheetSetNotification' , 'pHandler' , ), 17, (17, (), [ (9, 1, None, "IID('{B236E67D-CFC4-4C4D-852D-5EC56DA574DC}')") , ], 1 , 1 , 4 , 0 , 184 , (3, 0, None, None) , 0 , )),
	(( 'cancelSheetSetNotification' , 'pHandler' , ), 18, (18, (), [ (9, 1, None, "IID('{B236E67D-CFC4-4C4D-852D-5EC56DA574DC}')") , ], 1 , 1 , 4 , 0 , 192 , (3, 0, None, None) , 0 , )),
	(( 'bindXrefHook' , 'pHandler' , 'add' , ), 19, (19, (), [ (9, 1, None, "IID('{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}')") , 
			 (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 200 , (3, 0, None, None) , 64 , )),
	(( 'getConvertReport' , 'bFullVersion' , 'bMarkup' , 'bstrReport' , ), 21, (21, (), [ 
			 (3, 1, None, None) , (3, 1, None, None) , (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 208 , (3, 0, None, None) , 64 , )),
	(( 'getConvertStatusFileBag' , 'status' , 'ppsaConvertedFile' , ), 22, (22, (), [ (3, 1, None, None) , 
			 (24589, 10, None, None) , ], 1 , 1 , 4 , 0 , 216 , (3, 0, None, None) , 64 , )),
	(( 'putConversionFormatForReport' , 'bstrFormat' , ), 23, (23, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 224 , (3, 0, None, None) , 64 , )),
	(( 'putConversionPackageTypeForReport' , 'bstrPackType' , ), 24, (24, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 232 , (3, 0, None, None) , 64 , )),
	(( 'putConversionLocationForReport' , 'bstrLocation' , ), 25, (25, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 240 , (3, 0, None, None) , 64 , )),
	(( 'infoInterfacePtr' , 'ppIInfo' , ), 26, (26, (), [ (16393, 10, None, "IID('{4E95DC11-225E-46B8-A647-FBB50DB3AB45}')") , ], 1 , 1 , 4 , 0 , 248 , (3, 0, None, None) , 64 , )),
	(( 'addUserNotesToReport' , 'bstrUserNotes' , ), 27, (27, (), [ (8, 0, None, None) , ], 1 , 1 , 4 , 0 , 256 , (3, 0, None, None) , 64 , )),
	(( 'graphInterfacePtr' , 'ppIGraph' , ), 28, (28, (), [ (16393, 10, None, "IID('{61603FA1-F460-4DFA-9180-449AC4637A22}')") , ], 1 , 1 , 4 , 0 , 264 , (3, 0, None, None) , 64 , )),
	(( 'copyFiles' , ), 29, (29, (), [ ], 1 , 1 , 4 , 0 , 272 , (3, 0, None, None) , 64 , )),
	(( 'getDwgDependencies' , 'bstrDwgName' , 'bstrPlotStyleTablePath' , 'bstrPlotConfigFilePath' , ), 30, (30, (), [ 
			 (8, 1, None, None) , (8, 1, None, None) , (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 280 , (3, 0, None, None) , 64 , )),
	(( 'getReport' , 'bstrReport' , ), 31, (31, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 288 , (3, 0, None, None) , 64 , )),
	(( 'addFileWithVersioning' , 'bstrFullPath' , 'bstrVersion' , 'pIParentFile' , 'bAddedBy3rdParty' , 
			 'ppIAddedFile' , 'pRetVal' , ), 32, (32, (), [ (8, 1, None, None) , (8, 1, None, None) , 
			 (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (3, 1, None, None) , (16393, 2, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (16387, 10, None, None) , ], 1 , 1 , 4 , 0 , 296 , (3, 0, None, None) , 64 , )),
	(( 'OpenDrawingInEditor' , 'Val' , ), 33, (33, (), [ (3, 1, None, None) , ], 1 , 1 , 4 , 0 , 304 , (3, 0, None, None) , 64 , )),
	(( 'getLargeFiles' , 'bstrLargeFiles' , ), 34, (34, (), [ (16392, 10, None, None) , ], 1 , 1 , 4 , 0 , 312 , (3, 0, None, None) , 64 , )),
]

ITransmittalProgressHandler_vtables_dispatch_ = 1
ITransmittalProgressHandler_vtables_ = [
	(( 'isCanceled' , 'cancelled' , ), 1, (1, (), [ (16387, 2, None, None) , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'processingFile' , 'fname' , ), 2, (2, (), [ (8, 1, None, None) , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

ITransmittalSheetSetNotification_vtables_dispatch_ = 1
ITransmittalSheetSetNotification_vtables_ = [
	(( 'preSheetSetProcessing' , 'pISheetSet' , 'pFile' , 'pTransmit' , ), 1610743808, (1610743808, (), [ 
			 (13, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , ], 1 , 1 , 4 , 0 , 56 , (3, 0, None, None) , 0 , )),
	(( 'postSheetSetProcessing' , 'pISheetSet' , 'pFile' , 'pTransmit' , ), 1610743809, (1610743809, (), [ 
			 (13, 1, None, None) , (9, 1, None, "IID('{494F6723-CCB2-43EC-8A32-4854E5B63430}')") , (9, 1, None, "IID('{AA41166A-7FED-4700-80DD-653857913ECE}')") , ], 1 , 1 , 4 , 0 , 64 , (3, 0, None, None) , 0 , )),
]

RecordMap = {
}

CLSIDToClassMap = {
	'{494F6723-CCB2-43EC-8A32-4854E5B63430}' : ITransmittalFile,
	'{61603FA1-F460-4DFA-9180-449AC4637A22}' : ITransmittalFilesGraph,
	'{4E95DC11-225E-46B8-A647-FBB50DB3AB45}' : ITransmittalInfo,
	'{A5A24764-DD5D-43C0-B720-E48C386C9CC9}' : ITransmittalFileOverwriteHandler,
	'{DBFC8126-EB2A-43A6-A6C9-5A65F26256AF}' : ITransmittalAddFileNotificationHandler,
	'{AA41166A-7FED-4700-80DD-653857913ECE}' : ITransmittalOperation,
	'{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}' : ITransmittalDatabaseNotificationHandler,
	'{0D6FB8D0-D89F-4080-B392-0EAA048B82D4}' : ITransmittalProgressHandler,
	'{B236E67D-CFC4-4C4D-852D-5EC56DA574DC}' : ITransmittalSheetSetNotification,
	'{4255FEF5-5AE5-4F7D-98EA-75853819A684}' : IRelocateDrawing,
	'{214CCC0F-968A-47FB-B625-FB014C73311F}' : IRelocateDrawing2,
	'{2F8EE550-B6BD-4144-ACB2-7633B0A905C2}' : IRelocateDrawing3,
	'{FB1A140E-0DA9-4595-B64B-397CE59E41F1}' : ITransmittalFilesGraphPrivate,
	'{BC573B3C-4123-4F95-8DD4-DF3BEC317D67}' : TransmittalFile,
	'{5A6B063C-3DD0-4B58-AB43-B5844E57912F}' : TransmittalFilesGraph,
	'{A994CA23-17EB-4C43-8345-EDEE893F2186}' : TransmittalOperation,
	'{16A847C9-8BA2-403D-98BC-1FEA67C0A8CC}' : TransmittalFileOverwriteHandler,
	'{FD1AF231-C232-42BD-AD6A-F3E1CA076972}' : TransmittalInfo,
	'{6BC47508-D5EF-4DD5-9A59-376B92DCFE7A}' : TransmittalAddFileNotificationHandler,
	'{11AA8559-7D9A-4B26-B550-23E6D62EE9C6}' : TransmittalDatabaseNotificationHandler,
	'{37A751D5-EEF1-485F-ABD0-02C8B636C218}' : TransmittalFilesGraphPrivate,
	'{48FBD5ED-7C0A-43CA-9D29-99FB782A0D38}' : TransmittalProgressHandler,
}
CLSIDToPackageMap = {}
win32com.client.CLSIDToClass.RegisterCLSIDsFromDict( CLSIDToClassMap )
VTablesToPackageMap = {}
VTablesToClassMap = {
	'{494F6723-CCB2-43EC-8A32-4854E5B63430}' : 'ITransmittalFile',
	'{61603FA1-F460-4DFA-9180-449AC4637A22}' : 'ITransmittalFilesGraph',
	'{4E95DC11-225E-46B8-A647-FBB50DB3AB45}' : 'ITransmittalInfo',
	'{A5A24764-DD5D-43C0-B720-E48C386C9CC9}' : 'ITransmittalFileOverwriteHandler',
	'{DBFC8126-EB2A-43A6-A6C9-5A65F26256AF}' : 'ITransmittalAddFileNotificationHandler',
	'{AA41166A-7FED-4700-80DD-653857913ECE}' : 'ITransmittalOperation',
	'{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}' : 'ITransmittalDatabaseNotificationHandler',
	'{0D6FB8D0-D89F-4080-B392-0EAA048B82D4}' : 'ITransmittalProgressHandler',
	'{B236E67D-CFC4-4C4D-852D-5EC56DA574DC}' : 'ITransmittalSheetSetNotification',
	'{4255FEF5-5AE5-4F7D-98EA-75853819A684}' : 'IRelocateDrawing',
	'{214CCC0F-968A-47FB-B625-FB014C73311F}' : 'IRelocateDrawing2',
	'{2F8EE550-B6BD-4144-ACB2-7633B0A905C2}' : 'IRelocateDrawing3',
	'{FB1A140E-0DA9-4595-B64B-397CE59E41F1}' : 'ITransmittalFilesGraphPrivate',
	'{21FD8104-C4C6-41E1-96C2-E4A07747B702}' : 'ITransmittalFileOperationOverride',
}


NamesToIIDMap = {
	'ITransmittalFile' : '{494F6723-CCB2-43EC-8A32-4854E5B63430}',
	'ITransmittalFilesGraph' : '{61603FA1-F460-4DFA-9180-449AC4637A22}',
	'ITransmittalInfo' : '{4E95DC11-225E-46B8-A647-FBB50DB3AB45}',
	'ITransmittalFileOverwriteHandler' : '{A5A24764-DD5D-43C0-B720-E48C386C9CC9}',
	'ITransmittalAddFileNotificationHandler' : '{DBFC8126-EB2A-43A6-A6C9-5A65F26256AF}',
	'ITransmittalOperation' : '{AA41166A-7FED-4700-80DD-653857913ECE}',
	'ITransmittalDatabaseNotificationHandler' : '{2CB3267B-F52B-44B4-AD71-EF21823D8F5E}',
	'ITransmittalProgressHandler' : '{0D6FB8D0-D89F-4080-B392-0EAA048B82D4}',
	'ITransmittalSheetSetNotification' : '{B236E67D-CFC4-4C4D-852D-5EC56DA574DC}',
	'IRelocateDrawing' : '{4255FEF5-5AE5-4F7D-98EA-75853819A684}',
	'IRelocateDrawing2' : '{214CCC0F-968A-47FB-B625-FB014C73311F}',
	'IRelocateDrawing3' : '{2F8EE550-B6BD-4144-ACB2-7633B0A905C2}',
	'ITransmittalFilesGraphPrivate' : '{FB1A140E-0DA9-4595-B64B-397CE59E41F1}',
	'ITransmittalFileOperationOverride' : '{21FD8104-C4C6-41E1-96C2-E4A07747B702}',
}

win32com.client.constants.__dicts__.append(constants.__dict__)

