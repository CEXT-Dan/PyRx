import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
import PyBr
from typing import overload
from typing import Any

class Core(object):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def processPlotState ()-> PyPl.ProcessPlotState :
        '''                             '''
        ...

    @staticmethod
    def publishExecute (dsdDataObj: PyPl.DSDData,pConfig: PyPl.PlotConfig,bShowPlotProgress: bool)-> None :
        '''                             '''
        ...

class CustomSizeResult(object):
    def eDeviceLoadFailed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eException (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMustCreatePC3 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePC3DirReadOnly (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePC3FileReadOnly (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePMPDirMissing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePMPDirReadOnly (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePMPFileReadOnly (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePossible (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRotationRequired (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSizeTooBig (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnknownErrPC3File (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnknownErrPMPDir (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnknownErrPMPFile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eWidthAndHeightMustBePositive (self, *args, **kwargs)-> None :
        '''None'''
        ...

class DSDData(PlObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def categoryName (self, *args, **kwargs)-> str :
        '''categoryName( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > categoryName(class PyPlDSDData {lvalue})'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def currentPrecision (self, *args, **kwargs)-> str :
        '''currentPrecision( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > currentPrecision(class PyPlDSDData {lvalue})'''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def destinationName (self, *args, **kwargs)-> str :
        '''destinationName( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > destinationName(class PyPlDSDData {lvalue})'''
        ...
    def get3dDwfOptions (self, *args, **kwargs)-> tuple[bool,bool] :
        '''get3dDwfOptions( (DSDData)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple get3dDwfOptions(class PyPlDSDData {lvalue})'''
        ...
    def getDSDEntries (self, *args, **kwargs)-> list[PyPl.DSDEntry] :
        '''getDSDEntries( (DSDData)arg1) -> list :

    C++ signature :
        class boost::python::list getDSDEntries(class PyPlDSDData {lvalue})'''
        ...
    def getPrecisionEntries (self, *args, **kwargs)-> list[PyPl.PrecisionEntry] :
        '''getPrecisionEntries( (DSDData)arg1) -> list :

    C++ signature :
        class boost::python::list getPrecisionEntries(class PyPlDSDData {lvalue})'''
        ...
    def getUnrecognizedData (self, *args, **kwargs)-> None :
        '''getUnrecognizedData( (DSDData)arg1, (list)arg2, (list)arg3) -> None :

    C++ signature :
        void getUnrecognizedData(class PyPlDSDData {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
        ...
    def includeLayerInfo (self, *args, **kwargs)-> bool :
        '''includeLayerInfo( (DSDData)arg1) -> bool :

    C++ signature :
        bool includeLayerInfo(class PyPlDSDData {lvalue})'''
        ...
    def initializeLayouts (self, *args, **kwargs)-> bool :
        '''initializeLayouts( (DSDData)arg1) -> bool :

    C++ signature :
        bool initializeLayouts(class PyPlDSDData {lvalue})'''
        ...
    def isHomogeneous (self, *args, **kwargs)-> bool :
        '''isHomogeneous( (DSDData)arg1) -> bool :

    C++ signature :
        bool isHomogeneous(class PyPlDSDData {lvalue})'''
        ...
    def isSheetSet (self, *args, **kwargs)-> bool :
        '''isSheetSet( (DSDData)arg1) -> bool :

    C++ signature :
        bool isSheetSet(class PyPlDSDData {lvalue})'''
        ...
    def lineMerge (self, *args, **kwargs)-> bool :
        '''lineMerge( (DSDData)arg1) -> bool :

    C++ signature :
        bool lineMerge(class PyPlDSDData {lvalue})'''
        ...
    def logFilePath (self, *args, **kwargs)-> str :
        '''logFilePath( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > logFilePath(class PyPlDSDData {lvalue})'''
        ...
    def majorVersion (self, *args, **kwargs)-> int :
        '''majorVersion( (DSDData)arg1) -> int :

    C++ signature :
        unsigned int majorVersion(class PyPlDSDData {lvalue})'''
        ...
    def minorVersion (self, *args, **kwargs)-> int :
        '''minorVersion( (DSDData)arg1) -> int :

    C++ signature :
        unsigned int minorVersion(class PyPlDSDData {lvalue})'''
        ...
    def noOfCopies (self, *args, **kwargs)-> int :
        '''noOfCopies( (DSDData)arg1) -> int :

    C++ signature :
        unsigned int noOfCopies(class PyPlDSDData {lvalue})'''
        ...
    def numberOfDSDEntries (self, *args, **kwargs)-> int :
        '''numberOfDSDEntries( (DSDData)arg1) -> int :

    C++ signature :
        int numberOfDSDEntries(class PyPlDSDData {lvalue})'''
        ...
    def password (self, *args, **kwargs)-> str :
        '''password( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > password(class PyPlDSDData {lvalue})'''
        ...
    def plotStampOn (self, *args, **kwargs)-> bool :
        '''plotStampOn( (DSDData)arg1) -> bool :

    C++ signature :
        bool plotStampOn(class PyPlDSDData {lvalue})'''
        ...
    def projectPath (self, *args, **kwargs)-> str :
        '''projectPath( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > projectPath(class PyPlDSDData {lvalue})'''
        ...
    def promptForDwfName (self, *args, **kwargs)-> bool :
        '''promptForDwfName( (DSDData)arg1) -> bool :

    C++ signature :
        bool promptForDwfName(class PyPlDSDData {lvalue})'''
        ...
    def promptForPassword (self, *args, **kwargs)-> bool :
        '''promptForPassword( (DSDData)arg1) -> bool :

    C++ signature :
        bool promptForPassword(class PyPlDSDData {lvalue})'''
        ...
    def pwdProtectPublishedDWF (self, *args, **kwargs)-> bool :
        '''pwdProtectPublishedDWF( (DSDData)arg1) -> bool :

    C++ signature :
        bool pwdProtectPublishedDWF(class PyPlDSDData {lvalue})'''
        ...
    def selectionSetName (self, *args, **kwargs)-> str :
        '''selectionSetName( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > selectionSetName(class PyPlDSDData {lvalue})'''
        ...
    def set3dDwfOptions (self, *args, **kwargs)-> None :
        '''set3dDwfOptions( (DSDData)arg1, (bool)arg2, (bool)arg3) -> None :

    C++ signature :
        void set3dDwfOptions(class PyPlDSDData {lvalue},bool,bool)'''
        ...
    def setCategoryName (self, *args, **kwargs)-> None :
        '''setCategoryName( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setCategoryName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setCurrentPrecision (self, *args, **kwargs)-> None :
        '''setCurrentPrecision( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setCurrentPrecision(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setDSDEntries (self, *args, **kwargs)-> None :
        '''setDSDEntries( (DSDData)arg1, (list)arg2) -> None :

    C++ signature :
        void setDSDEntries(class PyPlDSDData {lvalue},class boost::python::list)'''
        ...
    def setDestinationName (self, *args, **kwargs)-> None :
        '''setDestinationName( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setDestinationName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setIncludeLayerInfo (self, *args, **kwargs)-> None :
        '''setIncludeLayerInfo( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setIncludeLayerInfo(class PyPlDSDData {lvalue},bool)'''
        ...
    def setInitializeLayouts (self, *args, **kwargs)-> None :
        '''setInitializeLayouts( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setInitializeLayouts(class PyPlDSDData {lvalue},bool)'''
        ...
    def setIsHomogeneous (self, *args, **kwargs)-> None :
        '''setIsHomogeneous( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setIsHomogeneous(class PyPlDSDData {lvalue},bool)'''
        ...
    def setIsSheetSet (self, *args, **kwargs)-> None :
        '''setIsSheetSet( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setIsSheetSet(class PyPlDSDData {lvalue},bool)'''
        ...
    def setLineMerge (self, *args, **kwargs)-> None :
        '''setLineMerge( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setLineMerge(class PyPlDSDData {lvalue},bool)'''
        ...
    def setLogFilePath (self, *args, **kwargs)-> None :
        '''setLogFilePath( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setLogFilePath(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setMajorVersion (self, *args, **kwargs)-> None :
        '''setMajorVersion( (DSDData)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMajorVersion(class PyPlDSDData {lvalue},unsigned int)'''
        ...
    def setMinorVersion (self, *args, **kwargs)-> None :
        '''setMinorVersion( (DSDData)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMinorVersion(class PyPlDSDData {lvalue},unsigned int)'''
        ...
    def setNoOfCopies (self, *args, **kwargs)-> None :
        '''setNoOfCopies( (DSDData)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setNoOfCopies(class PyPlDSDData {lvalue},unsigned int)'''
        ...
    def setPassword (self, *args, **kwargs)-> None :
        '''setPassword( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setPassword(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setPlotStampOn (self, *args, **kwargs)-> None :
        '''setPlotStampOn( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPlotStampOn(class PyPlDSDData {lvalue},bool)'''
        ...
    def setPrecisionEntries (self, *args, **kwargs)-> None :
        '''setPrecisionEntries( (DSDData)arg1, (list)arg2) -> None :

    C++ signature :
        void setPrecisionEntries(class PyPlDSDData {lvalue},class boost::python::list)'''
        ...
    def setProjectPath (self, *args, **kwargs)-> None :
        '''setProjectPath( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setProjectPath(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setPromptForDwfName (self, *args, **kwargs)-> None :
        '''setPromptForDwfName( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPromptForDwfName(class PyPlDSDData {lvalue},bool)'''
        ...
    def setPromptForPassword (self, *args, **kwargs)-> None :
        '''setPromptForPassword( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPromptForPassword(class PyPlDSDData {lvalue},bool)'''
        ...
    def setPwdProtectPublishedDWF (self, *args, **kwargs)-> None :
        '''setPwdProtectPublishedDWF( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPwdProtectPublishedDWF(class PyPlDSDData {lvalue},bool)'''
        ...
    def setSelectionSetName (self, *args, **kwargs)-> None :
        '''setSelectionSetName( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setSelectionSetName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setSheetSetName (self, *args, **kwargs)-> None :
        '''setSheetSetName( (DSDData)arg1, (str)arg2) -> None :

    C++ signature :
        void setSheetSetName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setSheetType (self, *args, **kwargs)-> None :
        '''setSheetType( (DSDData)arg1, (SheetType)arg2) -> None :

    C++ signature :
        void setSheetType(class PyPlDSDData {lvalue},enum AcPlDSDEntry::SheetType)'''
        ...
    def setUnrecognizedData (self, *args, **kwargs)-> None :
        '''setUnrecognizedData( (DSDData)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void setUnrecognizedData(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

setUnrecognizedData( (DSDData)arg1, (list)arg2, (list)arg3) -> None :

    C++ signature :
        void setUnrecognizedData(class PyPlDSDData {lvalue},class boost::python::list,class boost::python::list)'''
        ...
    def setViewFile (self, *args, **kwargs)-> None :
        '''setViewFile( (DSDData)arg1, (bool)arg2) -> None :

    C++ signature :
        void setViewFile(class PyPlDSDData {lvalue},bool)'''
        ...
    def sheetSetName (self, *args, **kwargs)-> str :
        '''sheetSetName( (DSDData)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > sheetSetName(class PyPlDSDData {lvalue})'''
        ...
    def sheetType (self, *args, **kwargs)-> PyPl.SheetType :
        '''sheetType( (DSDData)arg1) -> SheetType :

    C++ signature :
        enum AcPlDSDEntry::SheetType sheetType(class PyPlDSDData {lvalue})'''
        ...
    def viewFile (self, *args, **kwargs)-> bool :
        '''viewFile( (DSDData)arg1) -> bool :

    C++ signature :
        bool viewFile(class PyPlDSDData {lvalue})'''
        ...

class DSDEntry(PlObject):
    def NPS (self, *args, **kwargs)-> str :
        '''NPS( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > NPS(class PyPlDSDEntry {lvalue})'''
        ...
    def NPSSourceDWG (self, *args, **kwargs)-> str :
        '''NPSSourceDWG( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > NPSSourceDWG(class PyPlDSDEntry {lvalue})'''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def dwgName (self, *args, **kwargs)-> str :
        '''dwgName( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > dwgName(class PyPlDSDEntry {lvalue})'''
        ...
    def has3dDwfSetup (self, *args, **kwargs)-> bool :
        '''has3dDwfSetup( (DSDEntry)arg1) -> bool :

    C++ signature :
        bool has3dDwfSetup(class PyPlDSDEntry {lvalue})'''
        ...
    def layout (self, *args, **kwargs)-> str :
        '''layout( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > layout(class PyPlDSDEntry {lvalue})'''
        ...
    def orgSheetPath (self, *args, **kwargs)-> str :
        '''orgSheetPath( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > orgSheetPath(class PyPlDSDEntry {lvalue})'''
        ...
    def setDwgName (self, *args, **kwargs)-> None :
        '''setDwgName( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setDwgName(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setHas3dDwfSetup (self, *args, **kwargs)-> None :
        '''setHas3dDwfSetup( (DSDEntry)arg1, (bool)arg2) -> None :

    C++ signature :
        void setHas3dDwfSetup(class PyPlDSDEntry {lvalue},bool)'''
        ...
    def setLayout (self, *args, **kwargs)-> None :
        '''setLayout( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setLayout(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setNPS (self, *args, **kwargs)-> None :
        '''setNPS( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setNPS(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setNPSSourceDWG (self, *args, **kwargs)-> None :
        '''setNPSSourceDWG( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setNPSSourceDWG(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setSetupType (self, *args, **kwargs)-> None :
        '''setSetupType( (DSDEntry)arg1, (SetupType)arg2) -> None :

    C++ signature :
        void setSetupType(class PyPlDSDEntry {lvalue},enum AcPlDSDEntry::SetupType)'''
        ...
    def setTitle (self, *args, **kwargs)-> None :
        '''setTitle( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setTitle(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setTraceSession (self, *args, **kwargs)-> None :
        '''setTraceSession( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setTraceSession(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setupType (self, *args, **kwargs)-> PyPl.SetupType :
        '''setupType( (DSDEntry)arg1) -> SetupType :

    C++ signature :
        enum AcPlDSDEntry::SetupType setupType(class PyPlDSDEntry {lvalue})'''
        ...
    def title (self, *args, **kwargs)-> str :
        '''title( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > title(class PyPlDSDEntry {lvalue})'''
        ...
    def traceSession (self, *args, **kwargs)-> str :
        '''traceSession( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > traceSession(class PyPlDSDEntry {lvalue})'''
        ...

class DeviceType(object):
    def kOneOffConfig (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPC3File (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSystemPrinter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUninitialized (self, *args, **kwargs)-> None :
        '''None'''
        ...

class MatchingPolicy(object):
    def kMatchDisabled (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMatchEnabled (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMatchEnabledCustom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMatchEnabledTmpCustom (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PlObject(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class PlotCancelStatus(object):
    def kPlotCancelStatusCount (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPlotCanceledByCaller (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPlotCanceledByCancelAllButton (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPlotContinue (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PlotConfig(PlObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def deviceName (self, *args, **kwargs)-> str :
        '''deviceName( (PlotConfig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > deviceName(class PyPlPlotConfig {lvalue})'''
        ...
    def deviceType (self, *args, **kwargs)-> int :
        '''deviceType( (PlotConfig)arg1) -> int :

    C++ signature :
        unsigned long deviceType(class PyPlPlotConfig {lvalue})'''
        ...
    def fullPath (self, *args, **kwargs)-> str :
        '''fullPath( (PlotConfig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > fullPath(class PyPlPlotConfig {lvalue})'''
        ...
    def getCanonicalMediaNameList (self, *args, **kwargs)-> list[str] :
        '''getCanonicalMediaNameList( (PlotConfig)arg1) -> list :

    C++ signature :
        class boost::python::list getCanonicalMediaNameList(class PyPlPlotConfig {lvalue})'''
        ...
    def getDefaultFileExtension (self, *args, **kwargs)-> str :
        '''getDefaultFileExtension( (PlotConfig)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getDefaultFileExtension(class PyPlPlotConfig {lvalue})'''
        ...
    def getDescriptionFields (self, *args, **kwargs)-> tuple[str,...] :
        '''getDescriptionFields( (PlotConfig)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getDescriptionFields(class PyPlPlotConfig {lvalue})'''
        ...
    def getLocalMediaName (self, *args, **kwargs)-> str :
        '''getLocalMediaName( (PlotConfig)arg1, (str)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getLocalMediaName(class PyPlPlotConfig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def getMediaBounds (self, *args, **kwargs)-> None :
        '''getMediaBounds( (PlotConfig)arg1, (str)arg2, (Point2d)arg3, (BoundBlock2d)arg4) -> None :

    C++ signature :
        void getMediaBounds(class PyPlPlotConfig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class AcGePoint2d {lvalue},class PyGeBoundBlock2d {lvalue})'''
        ...
    def isPlotToFile (self, *args, **kwargs)-> bool :
        '''isPlotToFile( (PlotConfig)arg1) -> bool :

    C++ signature :
        bool isPlotToFile(class PyPlPlotConfig {lvalue})'''
        ...
    def maxDeviceDPI (self, *args, **kwargs)-> int :
        '''maxDeviceDPI( (PlotConfig)arg1) -> int :

    C++ signature :
        unsigned int maxDeviceDPI(class PyPlPlotConfig {lvalue})'''
        ...
    def plotToFileCapability (self, *args, **kwargs)-> PyPl.PlotToFileCapability :
        '''plotToFileCapability( (PlotConfig)arg1) -> PlotToFileCapability :

    C++ signature :
        enum AcPlPlotConfig::PlotToFileCapability plotToFileCapability(class PyPlPlotConfig {lvalue})'''
        ...
    def refreshMediaNameList (self, *args, **kwargs)-> None :
        '''refreshMediaNameList( (PlotConfig)arg1) -> None :

    C++ signature :
        void refreshMediaNameList(class PyPlPlotConfig {lvalue})'''
        ...
    def saveToPC3 (self, *args, **kwargs)-> bool :
        '''saveToPC3( (PlotConfig)arg1, (str)arg2) -> bool :

    C++ signature :
        bool saveToPC3(class PyPlPlotConfig {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setPlotToFile (self, *args, **kwargs)-> None :
        '''setPlotToFile( (PlotConfig)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPlotToFile(class PyPlPlotConfig {lvalue},bool)'''
        ...

class PlotConfigInfo(PlObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (str)arg2, (str)arg3, (DeviceType)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,enum DeviceType)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def deviceId (self, *args, **kwargs)-> str :
        '''deviceId( (PlotConfigInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > deviceId(class PyPlPlotConfigInfo {lvalue})'''
        ...
    def deviceName (self, *args, **kwargs)-> str :
        '''deviceName( (PlotConfigInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > deviceName(class PyPlPlotConfigInfo {lvalue})'''
        ...
    def deviceType (self, *args, **kwargs)-> PyPl.DeviceType :
        '''deviceType( (PlotConfigInfo)arg1) -> DeviceType :

    C++ signature :
        enum DeviceType deviceType(class PyPlPlotConfigInfo {lvalue})'''
        ...
    def fullPath (self, *args, **kwargs)-> str :
        '''fullPath( (PlotConfigInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > fullPath(class PyPlPlotConfigInfo {lvalue})'''
        ...
    def setDeviceId (self, *args, **kwargs)-> None :
        '''setDeviceId( (PlotConfigInfo)arg1, (str)arg2) -> None :

    C++ signature :
        void setDeviceId(class PyPlPlotConfigInfo {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setDeviceName (self, *args, **kwargs)-> None :
        '''setDeviceName( (PlotConfigInfo)arg1, (str)arg2) -> None :

    C++ signature :
        void setDeviceName(class PyPlPlotConfigInfo {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setDeviceType (self, *args, **kwargs)-> None :
        '''setDeviceType( (PlotConfigInfo)arg1, (DeviceType)arg2) -> None :

    C++ signature :
        void setDeviceType(class PyPlPlotConfigInfo {lvalue},enum DeviceType)'''
        ...
    def setFullPath (self, *args, **kwargs)-> None :
        '''setFullPath( (PlotConfigInfo)arg1, (str)arg2) -> None :

    C++ signature :
        void setFullPath(class PyPlPlotConfigInfo {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

class PlotConfigManager(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getCurrentConfig (self, *args, **kwargs)-> PyPl.PlotConfig :
        '''getCurrentConfig( (PlotConfigManager)arg1) -> PlotConfig :

    C++ signature :
        class PyPlPlotConfig getCurrentConfig(class PyPlPlotConfigManager {lvalue})'''
        ...
    def getDevicesList (self, *args, **kwargs)-> list[PyPl.PlotConfigInfo] :
        '''getDevicesList( (PlotConfigManager)arg1) -> list :

    C++ signature :
        class boost::python::list getDevicesList(class PyPlPlotConfigManager {lvalue})'''
        ...
    def getStdConfigName (self, *args, **kwargs)-> str :
        '''getStdConfigName( (PlotConfigManager)arg1, (StdConfigs)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getStdConfigName(class PyPlPlotConfigManager {lvalue},enum AcPlPlotConfigManager::StdConfigs)'''
        ...
    def getStyleList (self, *args, **kwargs)-> list[str] :
        '''getStyleList( (PlotConfigManager)arg1) -> list :

    C++ signature :
        class boost::python::list getStyleList(class PyPlPlotConfigManager {lvalue})'''
        ...
    def refreshList (self, *args, **kwargs)-> None :
        '''refreshList( (PlotConfigManager)arg1) -> None :

    C++ signature :
        void refreshList(class PyPlPlotConfigManager {lvalue})

refreshList( (PlotConfigManager)arg1, (RefreshCode)arg2) -> None :

    C++ signature :
        void refreshList(class PyPlPlotConfigManager {lvalue},enum AcPlPlotConfigManager::RefreshCode)'''
        ...
    def setCurrentConfig (self, *args, **kwargs)-> PyPl.PlotConfig :
        '''setCurrentConfig( (PlotConfigManager)arg1, (str)arg2) -> PlotConfig :

    C++ signature :
        class PyPlPlotConfig setCurrentConfig(class PyPlPlotConfigManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

class PlotEngine(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def beginDocument (self, *args, **kwargs)-> None :
        '''beginDocument( (PlotEngine)arg1, (PlotInfo)arg2, (str)arg3, (int)arg4, (bool)arg5, (str)arg6) -> None :

    C++ signature :
        void beginDocument(class PyPlPlotEngine {lvalue},class PyPlPlotInfo {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int,bool,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def beginGenerateGraphics (self, *args, **kwargs)-> None :
        '''beginGenerateGraphics( (PlotEngine)arg1) -> None :

    C++ signature :
        void beginGenerateGraphics(class PyPlPlotEngine {lvalue})'''
        ...
    def beginPage (self, *args, **kwargs)-> None :
        '''beginPage( (PlotEngine)arg1, (PlotPageInfo)arg2, (PlotInfo)arg3, (bool)arg4) -> None :

    C++ signature :
        void beginPage(class PyPlPlotEngine {lvalue},class PyPlPlotPageInfo {lvalue},class PyPlPlotInfo {lvalue},bool)'''
        ...
    def beginPlot (self, *args, **kwargs)-> None :
        '''beginPlot( (PlotEngine)arg1, (PlotProgressDialog)arg2) -> None :

    C++ signature :
        void beginPlot(class PyPlPlotEngine {lvalue},class PyPlPlotProgressDialog {lvalue})'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def destroy (self, *args, **kwargs)-> None :
        '''destroy( (PlotEngine)arg1) -> None :

    C++ signature :
        void destroy(class PyPlPlotEngine {lvalue})'''
        ...
    def endDocument (self, *args, **kwargs)-> None :
        '''endDocument( (PlotEngine)arg1) -> None :

    C++ signature :
        void endDocument(class PyPlPlotEngine {lvalue})'''
        ...
    def endGenerateGraphics (self, *args, **kwargs)-> None :
        '''endGenerateGraphics( (PlotEngine)arg1) -> None :

    C++ signature :
        void endGenerateGraphics(class PyPlPlotEngine {lvalue})'''
        ...
    def endPage (self, *args, **kwargs)-> None :
        '''endPage( (PlotEngine)arg1) -> None :

    C++ signature :
        void endPage(class PyPlPlotEngine {lvalue})'''
        ...
    def endPlot (self, *args, **kwargs)-> None :
        '''endPlot( (PlotEngine)arg1) -> None :

    C++ signature :
        void endPlot(class PyPlPlotEngine {lvalue})'''
        ...
    def isBackgroundPackaging (self, *args, **kwargs)-> bool :
        '''isBackgroundPackaging( (PlotEngine)arg1) -> bool :

    C++ signature :
        bool isBackgroundPackaging(class PyPlPlotEngine {lvalue})'''
        ...

class PlotFactory(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def createPreviewEngine (flags : int = 1)-> PyPl.PlotEngine :
        '''                             '''
        ...

    @staticmethod
    def createPublishEngine ()-> PyPl.PlotEngine :
        '''                             '''
        ...

    @staticmethod
    def processPlotState ()-> PyPl.ProcessPlotState :
        '''                             '''
        ...

class PlotInfo(PlObject):
    def OrgFilePath (self, *args, **kwargs)-> str :
        '''OrgFilePath( (PlotInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > OrgFilePath(class PyPlPlotInfo {lvalue})'''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def copyFrom (self, *args, **kwargs)-> None :
        '''copyFrom( (PlotInfo)arg1, (RxObject)arg2) -> None :

    C++ signature :
        void copyFrom(class PyPlPlotInfo {lvalue},class PyRxObject)'''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def deviceOverride (self, *args, **kwargs)-> PyPl.PlotConfig :
        '''deviceOverride( (PlotInfo)arg1) -> PlotConfig :

    C++ signature :
        class PyPlPlotConfig deviceOverride(class PyPlPlotInfo {lvalue})'''
        ...
    def isCompatibleDocument (self, *args, **kwargs)-> bool :
        '''isCompatibleDocument( (PlotInfo)arg1, (PlotInfo)arg2) -> bool :

    C++ signature :
        bool isCompatibleDocument(class PyPlPlotInfo {lvalue},class PyPlPlotInfo)'''
        ...
    def isValidated (self, *args, **kwargs)-> bool :
        '''isValidated( (PlotInfo)arg1) -> bool :

    C++ signature :
        bool isValidated(class PyPlPlotInfo {lvalue})'''
        ...
    def layout (self, *args, **kwargs)-> PyDb.ObjectId :
        '''layout( (PlotInfo)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layout(class PyPlPlotInfo {lvalue})'''
        ...
    def mergeStatus (self, *args, **kwargs)-> int :
        '''mergeStatus( (PlotInfo)arg1) -> int :

    C++ signature :
        unsigned long mergeStatus(class PyPlPlotInfo {lvalue})'''
        ...
    def overrideSettings (self, *args, **kwargs)-> PyDb.PlotSettings :
        '''overrideSettings( (PlotInfo)arg1) -> PlotSettings :

    C++ signature :
        class PyDbPlotSettings overrideSettings(class PyPlPlotInfo {lvalue})'''
        ...
    def setDeviceOverride (self, *args, **kwargs)-> None :
        '''setDeviceOverride( (PlotInfo)arg1, (PlotConfig)arg2) -> None :

    C++ signature :
        void setDeviceOverride(class PyPlPlotInfo {lvalue},class PyPlPlotConfig)'''
        ...
    def setLayout (self, *args, **kwargs)-> None :
        '''setLayout( (PlotInfo)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayout(class PyPlPlotInfo {lvalue},class PyDbObjectId {lvalue})'''
        ...
    def setOverrideSettings (self, *args, **kwargs)-> None :
        '''setOverrideSettings( (PlotInfo)arg1, (PlotSettings)arg2) -> None :

    C++ signature :
        void setOverrideSettings(class PyPlPlotInfo {lvalue},class PyDbPlotSettings)'''
        ...
    def setValidatedConfig (self, *args, **kwargs)-> None :
        '''setValidatedConfig( (PlotInfo)arg1, (PlotConfig)arg2) -> None :

    C++ signature :
        void setValidatedConfig(class PyPlPlotInfo {lvalue},class PyPlPlotConfig)'''
        ...
    def setValidatedSettings (self, *args, **kwargs)-> None :
        '''setValidatedSettings( (PlotInfo)arg1, (PlotSettings)arg2) -> None :

    C++ signature :
        void setValidatedSettings(class PyPlPlotInfo {lvalue},class PyDbPlotSettings)'''
        ...
    def validatedConfig (self, *args, **kwargs)-> PyPl.PlotConfig :
        '''validatedConfig( (PlotInfo)arg1) -> PlotConfig :

    C++ signature :
        class PyPlPlotConfig validatedConfig(class PyPlPlotInfo {lvalue})'''
        ...
    def validatedSettings (self, *args, **kwargs)-> PyDb.PlotSettings :
        '''validatedSettings( (PlotInfo)arg1) -> PlotSettings :

    C++ signature :
        class PyDbPlotSettings validatedSettings(class PyPlPlotInfo {lvalue})'''
        ...

class PlotInfoValidator(PlObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def dimensionalWeight (self, *args, **kwargs)-> int :
        '''dimensionalWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int dimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def isCustomPossible (self, *args, **kwargs)-> PyPl.CustomSizeResult :
        '''isCustomPossible( (PlotInfoValidator)arg1, (PlotInfo)arg2) -> CustomSizeResult :

    C++ signature :
        enum AcPlPlotInfoValidator::eCustomSizeResult isCustomPossible(class PyPlPlotInfoValidator {lvalue},class PyPlPlotInfo {lvalue})'''
        ...
    def matchingPolicy (self, *args, **kwargs)-> PyPl.MatchingPolicy :
        '''matchingPolicy( (PlotInfoValidator)arg1) -> MatchingPolicy :

    C++ signature :
        enum AcPlPlotInfoValidator::MatchingPolicy matchingPolicy(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def mediaBoundsWeight (self, *args, **kwargs)-> int :
        '''mediaBoundsWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int mediaBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def mediaGroupWeight (self, *args, **kwargs)-> int :
        '''mediaGroupWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int mediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def mediaMatchingThreshold (self, *args, **kwargs)-> int :
        '''mediaMatchingThreshold( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int mediaMatchingThreshold(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def printableBoundsWeight (self, *args, **kwargs)-> int :
        '''printableBoundsWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int printableBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefDimensionalWeight (self, *args, **kwargs)-> None :
        '''setDefDimensionalWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefDimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefMediaBoundsWeight (self, *args, **kwargs)-> None :
        '''setDefMediaBoundsWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefMediaBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefMediaGroupWeight (self, *args, **kwargs)-> None :
        '''setDefMediaGroupWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefMediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefMediaMatchingThreshold (self, *args, **kwargs)-> None :
        '''setDefMediaMatchingThreshold( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefMediaMatchingThreshold(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefPrintableBoundsWeight (self, *args, **kwargs)-> None :
        '''setDefPrintableBoundsWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefPrintableBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefSheetDimensionalWeight (self, *args, **kwargs)-> None :
        '''setDefSheetDimensionalWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefSheetDimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDefSheetMediaGroupWeight (self, *args, **kwargs)-> None :
        '''setDefSheetMediaGroupWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefSheetMediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def setDimensionalWeight (self, *args, **kwargs)-> None :
        '''setDimensionalWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setDimensionalWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def setMediaBoundsWeight (self, *args, **kwargs)-> None :
        '''setMediaBoundsWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMediaBoundsWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def setMediaGroupWeight (self, *args, **kwargs)-> None :
        '''setMediaGroupWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMediaGroupWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def setMediaMatchingPolicy (self, *args, **kwargs)-> None :
        '''setMediaMatchingPolicy( (PlotInfoValidator)arg1, (MatchingPolicy)arg2) -> None :

    C++ signature :
        void setMediaMatchingPolicy(class PyPlPlotInfoValidator {lvalue},enum AcPlPlotInfoValidator::MatchingPolicy)'''
        ...
    def setMediaMatchingThreshold (self, *args, **kwargs)-> None :
        '''setMediaMatchingThreshold( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMediaMatchingThreshold(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def setPrintableBoundsWeight (self, *args, **kwargs)-> None :
        '''setPrintableBoundsWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setPrintableBoundsWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def setSheetDimensionalWeight (self, *args, **kwargs)-> None :
        '''setSheetDimensionalWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setSheetDimensionalWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def setSheetMediaGroupWeight (self, *args, **kwargs)-> None :
        '''setSheetMediaGroupWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setSheetMediaGroupWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
        ...
    def sheetDimensionalWeight (self, *args, **kwargs)-> int :
        '''sheetDimensionalWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int sheetDimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def sheetMediaGroupWeight (self, *args, **kwargs)-> int :
        '''sheetMediaGroupWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int sheetMediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
        ...
    def validate (self, *args, **kwargs)-> None :
        '''validate( (PlotInfoValidator)arg1, (PlotInfo)arg2) -> None :

    C++ signature :
        void validate(class PyPlPlotInfoValidator {lvalue},class PyPlPlotInfo {lvalue})'''
        ...

class PlotMSGIndex(object):
    def kCancelJobBtnMsg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kCancelSheetBtnMsg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kDialogTitle (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMsgCancelling (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMsgCancellingCurrent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMsgCount (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetName (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetNameToolTip (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetProgressCaption (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetSetProgressCaption (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kStatus (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PlotPageInfo(PlObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

    @staticmethod
    def entityCount ()-> int :
        '''                             '''
        ...

    @staticmethod
    def gradientCount ()-> int :
        '''                             '''
        ...

    @staticmethod
    def oleObjectCount ()-> int :
        '''                             '''
        ...

    @staticmethod
    def rasterCount ()-> int :
        '''                             '''
        ...

    @staticmethod
    def shadedViewportType ()-> int :
        '''                             '''
        ...

class PlotProgressDialog(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (bool)arg2, (int)arg3, (bool)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,bool,int,bool)

__init__( (object)arg1, (int)arg2, (bool)arg3, (int)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,unsigned __int64,bool,int,bool)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def destroy (self, *args, **kwargs)-> None :
        '''destroy( (PlotProgressDialog)arg1) -> None :

    C++ signature :
        void destroy(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def getPlotMsgString (self, *args, **kwargs)-> str :
        '''getPlotMsgString( (PlotProgressDialog)arg1, (PlotMSGIndex)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getPlotMsgString(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgressDialog::PlotMSGIndex)'''
        ...
    def getPlotProgressRange (self, *args, **kwargs)-> tuple[int,int] :
        '''getPlotProgressRange( (PlotProgressDialog)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getPlotProgressRange(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def getSheetProgressRange (self, *args, **kwargs)-> tuple[int,int] :
        '''getSheetProgressRange( (PlotProgressDialog)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getSheetProgressRange(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def getStatusMsgString (self, *args, **kwargs)-> str :
        '''getStatusMsgString( (PlotProgressDialog)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getStatusMsgString(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def heartbeat (self, *args, **kwargs)-> None :
        '''heartbeat( (PlotProgressDialog)arg1) -> None :

    C++ signature :
        void heartbeat(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def isPlotCancelled (self, *args, **kwargs)-> bool :
        '''isPlotCancelled( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isPlotCancelled(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def isSheetCancelled (self, *args, **kwargs)-> bool :
        '''isSheetCancelled( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isSheetCancelled(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def isSingleSheetPlot (self, *args, **kwargs)-> bool :
        '''isSingleSheetPlot( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isSingleSheetPlot(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def isVisible (self, *args, **kwargs)-> bool :
        '''isVisible( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isVisible(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def onBeginPlot (self, *args, **kwargs)-> bool :
        '''onBeginPlot( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onBeginPlot(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def onBeginSheet (self, *args, **kwargs)-> bool :
        '''onBeginSheet( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onBeginSheet(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def onEndPlot (self, *args, **kwargs)-> bool :
        '''onEndPlot( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onEndPlot(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def onEndSheet (self, *args, **kwargs)-> bool :
        '''onEndSheet( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onEndSheet(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def plotCancelStatus (self, *args, **kwargs)-> PyPl.PlotCancelStatus :
        '''plotCancelStatus( (PlotProgressDialog)arg1) -> PlotCancelStatus :

    C++ signature :
        enum AcPlPlotProgress::PlotCancelStatus plotCancelStatus(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def plotProgressPos (self, *args, **kwargs)-> int :
        '''plotProgressPos( (PlotProgressDialog)arg1) -> int :

    C++ signature :
        int plotProgressPos(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def setIsVisible (self, *args, **kwargs)-> bool :
        '''setIsVisible( (PlotProgressDialog)arg1, (bool)arg2) -> bool :

    C++ signature :
        bool setIsVisible(class PyPlPlotProgressDialog {lvalue},bool)'''
        ...
    def setPlotCancelStatus (self, *args, **kwargs)-> None :
        '''setPlotCancelStatus( (PlotProgressDialog)arg1, (PlotCancelStatus)arg2) -> None :

    C++ signature :
        void setPlotCancelStatus(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgress::PlotCancelStatus)'''
        ...
    def setPlotMsgString (self, *args, **kwargs)-> bool :
        '''setPlotMsgString( (PlotProgressDialog)arg1, (PlotMSGIndex)arg2, (str)arg3) -> bool :

    C++ signature :
        bool setPlotMsgString(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgressDialog::PlotMSGIndex,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setPlotProgressPos (self, *args, **kwargs)-> None :
        '''setPlotProgressPos( (PlotProgressDialog)arg1, (int)arg2) -> None :

    C++ signature :
        void setPlotProgressPos(class PyPlPlotProgressDialog {lvalue},int)'''
        ...
    def setPlotProgressRange (self, *args, **kwargs)-> None :
        '''setPlotProgressRange( (PlotProgressDialog)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotProgressRange(class PyPlPlotProgressDialog {lvalue},int,int)'''
        ...
    def setSheetCancelStatus (self, *args, **kwargs)-> None :
        '''setSheetCancelStatus( (PlotProgressDialog)arg1, (SheetCancelStatus)arg2) -> None :

    C++ signature :
        void setSheetCancelStatus(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgress::SheetCancelStatus)'''
        ...
    def setSheetProgressPos (self, *args, **kwargs)-> None :
        '''setSheetProgressPos( (PlotProgressDialog)arg1, (int)arg2) -> None :

    C++ signature :
        void setSheetProgressPos(class PyPlPlotProgressDialog {lvalue},int)'''
        ...
    def setSheetProgressRange (self, *args, **kwargs)-> None :
        '''setSheetProgressRange( (PlotProgressDialog)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void setSheetProgressRange(class PyPlPlotProgressDialog {lvalue},int,int)'''
        ...
    def setStatusMsgString (self, *args, **kwargs)-> bool :
        '''setStatusMsgString( (PlotProgressDialog)arg1, (str)arg2) -> bool :

    C++ signature :
        bool setStatusMsgString(class PyPlPlotProgressDialog {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def sheetCancelStatus (self, *args, **kwargs)-> PyPl.SheetCancelStatus :
        '''sheetCancelStatus( (PlotProgressDialog)arg1) -> SheetCancelStatus :

    C++ signature :
        enum AcPlPlotProgress::SheetCancelStatus sheetCancelStatus(class PyPlPlotProgressDialog {lvalue})'''
        ...
    def sheetProgressPos (self, *args, **kwargs)-> int :
        '''sheetProgressPos( (PlotProgressDialog)arg1) -> int :

    C++ signature :
        int sheetProgressPos(class PyPlPlotProgressDialog {lvalue})'''
        ...

class PlotToFileCapability(object):
    def kMustPlotToFile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNoPlotToFile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPlotToFileAllowed (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PrecisionEntry(PlObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def colorResolution (self, *args, **kwargs)-> int :
        '''colorResolution( (PrecisionEntry)arg1) -> int :

    C++ signature :
        int colorResolution(class PyPlPrecisionEntry {lvalue})'''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def description (self, *args, **kwargs)-> str :
        '''description( (PrecisionEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > description(class PyPlPrecisionEntry {lvalue})'''
        ...
    def desiredPrecision (self, *args, **kwargs)-> float :
        '''desiredPrecision( (PrecisionEntry)arg1) -> float :

    C++ signature :
        double desiredPrecision(class PyPlPrecisionEntry {lvalue})'''
        ...
    def gradientResolution (self, *args, **kwargs)-> int :
        '''gradientResolution( (PrecisionEntry)arg1) -> int :

    C++ signature :
        int gradientResolution(class PyPlPrecisionEntry {lvalue})'''
        ...
    def monoResolution (self, *args, **kwargs)-> int :
        '''monoResolution( (PrecisionEntry)arg1) -> int :

    C++ signature :
        int monoResolution(class PyPlPrecisionEntry {lvalue})'''
        ...
    def setColorResolution (self, *args, **kwargs)-> None :
        '''setColorResolution( (PrecisionEntry)arg1, (int)arg2) -> None :

    C++ signature :
        void setColorResolution(class PyPlPrecisionEntry {lvalue},int)'''
        ...
    def setDescription (self, *args, **kwargs)-> None :
        '''setDescription( (PrecisionEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setDescription(class PyPlPrecisionEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setDesiredPrecision (self, *args, **kwargs)-> None :
        '''setDesiredPrecision( (PrecisionEntry)arg1, (float)arg2) -> None :

    C++ signature :
        void setDesiredPrecision(class PyPlPrecisionEntry {lvalue},double)'''
        ...
    def setGradientResolution (self, *args, **kwargs)-> None :
        '''setGradientResolution( (PrecisionEntry)arg1, (int)arg2) -> None :

    C++ signature :
        void setGradientResolution(class PyPlPrecisionEntry {lvalue},int)'''
        ...
    def setMonoResolution (self, *args, **kwargs)-> None :
        '''setMonoResolution( (PrecisionEntry)arg1, (int)arg2) -> None :

    C++ signature :
        void setMonoResolution(class PyPlPrecisionEntry {lvalue},int)'''
        ...
    def setTitle (self, *args, **kwargs)-> None :
        '''setTitle( (PrecisionEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setTitle(class PyPlPrecisionEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setUnitScale (self, *args, **kwargs)-> None :
        '''setUnitScale( (PrecisionEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setUnitScale(class PyPlPrecisionEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setUnitType (self, *args, **kwargs)-> None :
        '''setUnitType( (PrecisionEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setUnitType(class PyPlPrecisionEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def title (self, *args, **kwargs)-> str :
        '''title( (PrecisionEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > title(class PyPlPrecisionEntry {lvalue})'''
        ...
    def unitScale (self, *args, **kwargs)-> str :
        '''unitScale( (PrecisionEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > unitScale(class PyPlPrecisionEntry {lvalue})'''
        ...
    def unitType (self, *args, **kwargs)-> str :
        '''unitType( (PrecisionEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > unitType(class PyPlPrecisionEntry {lvalue})'''
        ...

class ProcessPlotState(object):
    def kBackgroundPlotting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kForegroundPlotting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNotPlotting (self, *args, **kwargs)-> None :
        '''None'''
        ...

class RefreshCode(object):
    def kAll (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRefreshDevicesList (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRefreshPC3DevicesList (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRefreshStyleList (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRefreshSystemDevicesList (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SetupType(object):
    def k3dDwf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNPSOtherDWG (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNPSSameDWG (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOriginalPS (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOverridePS (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SheetCancelStatus(object):
    def kSheetCancelStatusCount (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetCanceledByCaller (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetCanceledByCancelAllButton (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetCanceledByCancelButton (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetContinue (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SheetType(object):
    def kMultiDWF (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMultiDWFx (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMultiPDF (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kMultiSVF (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOriginalDevice (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSingleDWF (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSingleDWFx (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSinglePDF (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSingleSVF (self, *args, **kwargs)-> None :
        '''None'''
        ...

class StdConfigs(object):
    def kDWF6ePlot (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kDWFePlotOptForPlotting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kDWFePlotOptForViewing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kDWFxePlot (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kDefaultWindowsSysPrinter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNoneDevice (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPDFePlot (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPDFePlotGeneralDocs (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPDFePlotHighQuality (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPDFePlotSmallerFile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPDFePlotWebMobile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPublishToWebDWF (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPublishToWebDWFx (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPublishToWebJPG (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPublishToWebPNG (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSVFePlot (self, *args, **kwargs)-> None :
        '''None'''
        ...

class StyTypes(object):
    def kAllTypes (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kColorDep (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRegular (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kTranslation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...
