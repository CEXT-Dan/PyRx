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

class Application(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def acadGetIDispatch ()-> int :
        '''                             '''
        ...

    @staticmethod
    def applyHostIcon (wnd : int)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def docManager ()-> PyAp.DocManager :
        '''                             '''
        ...

    @staticmethod
    def getLoadedModuleNames ()-> list[str] :
        '''                             '''
        ...

    @staticmethod
    def getLoadedModules ()-> list[str] :
        '''                             '''
        ...

    @staticmethod
    def getPyRxModulePath ()-> str :
        '''                             '''
        ...

    @staticmethod
    def hostAPI ()-> str :
        '''                             '''
        ...

    @staticmethod
    def hostAPIVER ()-> str :
        '''                             '''
        ...

    @staticmethod
    def loadPythonModule (fullpath: str)-> bool :
        '''                             '''
        ...

    @staticmethod
    def mainWnd ()-> int :
        '''                             '''
        ...

    @staticmethod
    def registerOnIdleWinMsg (func: Any)-> None :
        '''                             '''
        ...

    @staticmethod
    def registerWatchWinMsg (func: Any)-> bool :
        '''                             '''
        ...

    @staticmethod
    def reloadPythonModule (fullpath: str)-> bool :
        '''                             '''
        ...

    @staticmethod
    def removeOnIdleWinMsg (func: Any)-> None :
        '''                             '''
        ...

    @staticmethod
    def removeWatchWinMsg (func: Any)-> bool :
        '''                             '''
        ...

    @staticmethod
    def setTitleThemeDark (wnd : int)-> None :
        '''                             '''
        ...

    @staticmethod
    def showModalDialog (window: wx.Dialog)-> int :
        '''                             '''
        ...

    @staticmethod
    def wxApp ()-> object :
        '''                             '''
        ...

class AutoDocLock(object):
    def __init__ (self)-> None :
        '''This function is used for locking documents in order to access their resources. Resources include all AcDbDatabases objects associated with a document, and AcDbObject objects in those databases, and all AcDbDatabase resident system variables. It also includes all document based system variables, and the Transaction Manager associated with a document. The document does not need to be locked to open an AcDbObject in AcDb::kForRead, nor to get system variables.Applications should normally never have to lock or unlock the current document. Commands registered with addCommand() or aceddefun() will have the current document locked before starting, and unlocked after ending. This can be controlled using the addCommand() function tags.'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class CmdFlags(object):
    def DEFUN (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def DOCREADLOCK (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def INPROGRESS (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def INTERRUPTIBLE (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def MODAL (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOBEDIT (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOHISTORY (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOINTERNALLOCK (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOMULTIPLE (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOOEM (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOPAPERSPACE (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOPERSPECTIVE (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NOTILEMODE (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def NO_UNDO_MARKER (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def REDRAW (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def SESSION (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def TRANSPARENT (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def UNDEFINED (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def USEPICKSET (self, *args, **kwargs)-> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0) :
        '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

class DocLockMode(object):
    def kAutoWrite (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNotLocked (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kProtectedAutoWrite (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRead (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kWrite (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXWrite (self, *args, **kwargs)-> None :
        '''None'''
        ...

class DocManager(PyRx.RxObject):
    def __init__ (self)-> None :
        '''The AcApDocumentManager object is the container for all the document objects (there is one document object for each drawing that is open and being edited). There is only one instance, which can be obtained using the macro named acDocManager.'''
        ...
    def activateDocument (self, doc: PyAp.Document, bPassScript: bool = False)-> None :
        '''This function will switch from the current document to another document. The function will NOT suspend execution of the code running under the application context. The caller is suspended if it is a normal or nomadic context. If the bPassScript is Adesk::kTrue, then the script that has called the command that is performing a document change will continue to run. This argument allows a script to continue running across documents.'''
        ...
    def appContextCloseDocument (self, doc: PyAp.Document)-> None :
        '''Immediately destroys the active document and a lot of related data.Caution: Since the document is destroyed, beware of what you reference after the call.'''
        ...
    def appContextNewDocument (self, templateName : str)-> None :
        '''This function allows synchronous access to the NEW drawing operation. It can only be called from the application context.'''
        ...
    def appContextOpenDocument (self, dwgName : str)-> None :
        '''This function allows synchronous access to the OPEN drawing operation. It can only be called from the application context.Based pParams, you can switch to a layout or view after the opening of the drawing.'''
        ...
    def appContextPromptOpenDocument (self)-> None :
        '''This function allows synchronous access to the OPEN drawing operation. It can only be called from the application context.Similar to appContextOpenDocument(), expect it prompts for a drawing name.'''
        ...
    def appContextRecoverDocument (self, dwgName : str)-> None :
        '''This function allows synchronous access to the RECOVER drawing operation. It can only be called from the application context. When running, no dialogs or prompts requiring user interaction will be required.'''
        ...

    @staticmethod
    def autoLock ()-> PyAp.AutoDocLock :
        '''This function is used for locking documents in order to access their resources. Resources include all AcDbDatabases objects associated with a document, and AcDbObject objects in those databases, and all AcDbDatabase resident system variables. It also includes all document based system variables, and the Transaction Manager associated with a document. The document does not need to be locked to open an AcDbObject in AcDb::kForRead, nor to get system variables.Applications should normally never have to lock or unlock the current document. Commands registered with addCommand() or aceddefun() will have the current document locked before starting, and unlocked after ending. This can be controlled using the addCommand() function tags.'''
        ...
    def beginExecuteInApplicationContext (self, func: Any, data: Any)-> PyBr.ErrorStatus :
        '''Allows anonymous code execution in command context (same as registering a command and calling sendStringToExecute to invoke it.). The command will be executed in the context of the MDI active document. The callback function will be called when the system has a chance to execute a command. This, at minimum, means that the caller of beginExecuteInCommandContext (i.e. your code) must return to its caller. All outstanding commands will be cancelled before the callback function is invoked.'''
        ...
    def beginExecuteInCommandContext (self, func: Any, data: Any)-> PyBr.ErrorStatus :
        '''Allows anonymous code execution in command context (same as registering a command and calling endStringToExecute to invoke it.). The command will be executed in the context of the MDI active document. The callback function will be called when the system has a chance to execute a command. This, at minimum, means that the caller of beginExecuteInCommandContext (i.e. your code) must return to its caller. All outstanding commands will be cancelled before the callback function is invoked.'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def closeDocument (self, doc: PyAp.Document)-> None :
        '''This function closes the document specified by pAcTargetDocument. If the input document is not the current document, current document retains control. If input document is the current document, the document execution context is terminated before this function returns, terminating normal commands.'''
        ...
    def curDocument (self)-> PyAp.Document :
        '''This function returns the document having current context. The associated function, mdiActiveDocument(), returns the MDI active document. curDocument() and mdiActiveDocument() can be different. You can call curDocument() to make a document "current" without actually activating it. After finish your AcDbDatabase operation under the temporary current document, call setCurDocument(acDocManager->mdiActiveDocument()) to reset the MDI active document as the current document.'''
        ...
    def defaultFormatForSave (self)-> PyAp.SaveFormat :
        '''This function returns the current default save format.'''
        ...
    def disableDocumentActivation (self)-> None :
        '''This function will disable the ability for the user to switch to another document. Applications must be sure to restore activation (using AcApDocManager::enableDocumentActivation) when complete. An example use might be when an application command is processing for long periods of time.Returns an error when already in a disabled mode; otherwise, returns Acad::eOk.'''
        ...
    def document (self, db: PyDb.Database)-> PyAp.Document :
        '''This function returns the document that the input database belongs to. All databases created in ObjectARX, the current database, and any loaded Xref databases will have a document that they are associated with. Databases created by ObjectARX applications will be automatically associated with the document of the context in which they were created. This is then the document that the database will have its Undo recorded. It is also the document whose Transaction Manager must be used for objects from the database.'''
        ...
    def documentCount (self)-> int :
        '''This function returns the number of documents currently open.'''
        ...
    def documents (self)-> list[PyAp.Document] :
        '''                             '''
        ...
    def enableDocumentActivation (self)-> None :
        '''This function will enable the ability for the user to switch to another document. This function is used to re-enable activation after a call to AcApDocManager::disableDocumentActivation.Returns an error when already in an enabled mode; otherwise, returns Acad::eOk.'''
        ...
    def executeInApplicationContext (self, func: Any, data: Any)-> None :
        '''Allows a void function to be called from the application context.'''
        ...
    def inputPending (self, doc: PyAp.Document)-> int :
        '''This function will determine the state of the document's input buffer. Used only in conjunction with the AcApDocManager::sendStringToExecute function.Returns the number of characters waiting to be processed. A value of 0 indicates no pending input. A return value of -1 indicates an error.'''
        ...
    def isApplicationContext (self)-> bool :
        '''This function is called by an executing function to determine if it is executing in the application context.'''
        ...
    def isDocumentActivationEnabled (self)-> bool :
        '''This function indicates whether document activation is enabled.Returns true if enabled or false otherwise.'''
        ...
    def lockDocument (self, doc: PyAp.Document, mode: PyAp.DocLockMode = kWrite, gcmd: str = None, lcmd: str = None, prmt: bool = True)-> None :
        '''This function is used for locking documents in order to access their resources. Resources include all AcDbDatabases objects associated with a document, and AcDbObject objects in those databases, and all AcDbDatabase resident system variables. It also includes all document based system variables, and the Transaction Manager associated with a document. The document does not need to be locked to open an AcDbObject in AcDb::kForRead, nor to get system variables.Applications should normally never have to lock or unlock the current document. Commands registered with addCommand() or aceddefun() will have the current document locked before starting, and unlocked after ending. This can be controlled using the addCommand() function tags.'''
        ...
    def mdiActiveDocument (self)-> PyAp.Document :
        '''This function returns the MDI active document. The associated function, curDocument(), returns the document having current context. curDocument() and mdiActiveDocument() can be different. You can call curDocument() to make a document "current" without actually activating it. After finish your AcDbDatabase operation under the temporary current document, call setCurDocument(acDocManager->mdiActiveDocument()) to reset the MDI active document as the current document.'''
        ...
    def newDocument (self)-> None :
        '''This function creates a new document using standard user interface interaction.'''
        ...
    def openDocument (self)-> None :
        '''This function opens a document using standard user interface interaction.'''
        ...
    def popResourceHandle (self)-> None :
        '''This function makes the resource file handle on top of the stack current and removes it from the stack.'''
        ...
    def pushAcadResourceHandle (self)-> None :
        '''This function pushes the current resource handle onto the current document's resource handle stack and makes the AutoCAD resource file current.'''
        ...
    def sendModelessInterrupt (self, doc: PyAp.Document)-> None :
        '''This function causes the current command in the specified document to be interrupted if it is prompting for input using one of the acedGetxxx functions and was registered with the ACRX_CMD_INTERRUPTIBLE flag.Returns Acad::eOk if successful and Acad:eNoDocument if the target document is not accessible.'''
        ...
    def sendStringToExecute (self, doc: PyAp.Document, script: str, bActivate: bool = True, bWrapUpInactiveDoc: bool = False, bEchoString: bool = True)-> None :
        '''Send string to target document to execute. By default, the string is executed in the activate document. The string is executed as soon as possible when bActivate is false and bWrapUpInactiveDoc is true.bEchoString determines whether the sent string is echoed on the command line.'''
        ...
    def setCurDocument (self, doc: PyAp.Document, mode: PyAp.DocLockMode = kNone, activate: bool = False)-> None :
        '''This function allows an external application running under the Application context to make a document "current" without actually activating it. This current state is only valid during the context of the function calling this API. This enables safe manipulation of a document's data without the document actually being the top most or active document. The default parameters lockMode and activate allow document locking and activation to occur. These are shortcuts to allow several steps to be accomplished with a single API and can also be accomplished with the individual API calls.If you call acDocManager->setCurDocument(pDoc, AcAp::kWrite), you effectively set the current document and lock it. You will need to unlock this document once you are done with it. You can do this by calling acDocManager->unlockDocument(pDoc).'''
        ...
    def setDefaultFormatForSave (self, fmt : PyAp.SaveFormat)-> None :
        '''This method uses one of the SaveFormat values to set the file format to use when saving a drawing with the SAVEAS, SAVE, and QSAVE commands. This sets the session-wide default, which the user may choose to override temporarily for an individual document.This method directly sets the file format for interactive commands entered by the user. If you want your application to use the current save format, every time you wish to save the database, you will first need to call AcApDocument::formatForSave(), and then use the returned SaveFormat value to determine which function to call. For example, if formatForSave() returned kR12_dxf, you would call acdbDxfOutAsR12() to write the database as a Release 12 DXF file.In summary:Either you or your user may set a persistent session-wide default format for save that will be honored by all save commands except AUTOSAVE.Only the user can temporarily (not persistently between sessions) override this setting for a particular document.The formatForSave() method returns the format in which the user wishes an individual document to be saved, which will be either the session-wide default or the temporary override, as appropriate.'''
        ...
    def unlockDocument (self, doc: PyAp.Document)-> None :
        '''This function unlocks a previously locked document. Except for the kAutoWrite lock mode, all locks applied with lockDocument() MUST be paired with an unlockDocument() call. Never call unlockDocument() unless you have first had a successful lockDocument() call. kAutoWrite should never be unlocked with unlockDocument().'''
        ...

class DocManagerReactor(object):
    def __init__ (self)-> None :
        '''This class provides notification for a variety of document management events.'''
        ...
    def addReactor (self)-> None :
        '''This function adds an AcApDocManagerReactor object to the document manager.'''
        ...
    def documentActivated (self, val : Document)-> None :
        '''This notification is sent once a document has been activated and its context has been successfully switched.'''
        ...
    def documentActivationModified (self, val : bool)-> None :
        '''This notification is sent for changes caused by disableDocumentActivation() or enableDocumentActivation().'''
        ...
    def documentBecameCurrent (self, val : Document)-> None :
        '''This notification is sent whenever the current document changes. It should not be confused with a document getting focus, or becoming active. It is possible for the same document to go in and out of focus, or become active and inactive. This notification is only sent when a document becomes active, and is different than the last active document.'''
        ...
    def documentCreateCanceled (self, val : Document)-> None :
        '''This notification is sent when a user action has canceled a document's creation. This notification is only sent in MDI mode and after a documentCreateStarted() notification.'''
        ...
    def documentCreateStarted (self, val : Document)-> None :
        '''This notification is sent when a document is first instantiated and no database is yet available.'''
        ...
    def documentCreated (self, val : Document)-> None :
        '''This notification is sent when a new AcApDocument has been constructed. A new message in acrxEntryPoint() can also be used by applications to monitor when a new document has been started, but this method provides a pointer to the new AcApDocument.'''
        ...
    def documentDestroyed (self, val : str)-> None :
        '''This notification is sent when a document is completely destroyed and the underlying database corresponding to this document has also been deleted.'''
        ...
    def documentLockModeChangeVetoed (self, doc : Document, globalCmdName : str)-> None :
        '''Requests to established locks on a document can be vetoed by reactors receiving the documentLockModeChanged() callback. If this happens, then all reactors will receive this callback so that all will know the request was vetoed, even though not all the reactors may have received the documentLockModeChanged() callback before the veto occurred.'''
        ...
    def documentLockModeChanged (self, doc : Document, myPrevMode : DocLockMode, myCurMode : DocLockMode, currentMode : DocLockMode, globalCmdName : str)-> None :
        '''This callback is given every time a lock is established or removed on a document. You can distinguish between a lock or an unlock call. Unlock calls will always have a command name prefixed with a '#' character. Lock calls can be vetoed, but unlock calls cannot.'''
        ...
    def documentLockModeWillChange (self, myCurMode : DocLockMode, myNewMode : DocLockMode, curMode : DocLockMode, globalCmdName : str)-> None :
        '''This callback is given before all lock changes are made on documents. It cannot be vetoed.'''
        ...
    def documentToBeActivated (self, val : Document)-> None :
        '''This notification is sent when a document is about to be activated.'''
        ...
    def documentToBeDeactivated (self, val : Document)-> None :
        '''This notification is sent when a document is about to be deactivated.'''
        ...
    def documentToBeDestroyed (self, val : Document)-> None :
        '''This notification is sent at the beginning of document destruction.'''
        ...
    def removeReactor (self)-> None :
        '''This function removes the specified AcApDocManagerReactor object from the document manager.'''
        ...

class Document(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def database (self)-> PyDb.Database :
        '''Returns the database object (AcDbDatabase) being used by this AcApDocument.'''
        ...
    def docTitle (self)-> str :
        '''Returns the window title of the document.'''
        ...

    @staticmethod
    def docWnd ()-> int :
        '''                             '''
        ...
    def downgradeDocOpen (self, promptForSave : bool)-> None :
        '''Converts the document status from writeable to read only.If bPromptForSave is true and the drawing is modified (based on dbmod), the user is prompted to save the drawing. If bPromptForSave is false and the drawing has been modified, an error is returned.'''
        ...
    def editor (self)-> PyEd.Editor :
        '''                             '''
        ...
    def fileName (self)-> str :
        '''Returns the full path and file name of the database being used by this AcApDocument.'''
        ...
    def formatForSave (self)-> PyAp.SaveFormat :
        '''This method returns the current save format that is being used by the SAVEAS, SAVE, and QSAVE commands. The value returned may be either the session-wide default setting, or a different setting that the user has selected for this document. If it is an override for this document, it will not persist across sessions.This method directly returns the file format for interactive commands entered by the user. If you want your application to use the current save format, every time you wish to save the database, you will first need to call formatForSave(), and then use the returned SaveFormat value to determine which function to call. For example, if formatForSave() returned kR12_dxf, you would call acdbDxfOutAsR12() to write the database as a Release 12 DXF file.In summary:Either you or your user may set a persistent session-wide default format for save that will be honored by all save commands except AUTOSAVE.Only the user can temporarily (not persistently between sessions) override this setting for a particular document.The formatForSave() method returns the format in which the user wishes an individual document to be saved, which will be either the session-wide default or the temporary override, as appropriate.'''
        ...
    def getCountOfLispList (self)-> int :
        '''Returns number of loaded LISP applications.'''
        ...
    def getItemOfLispList (self, index : int)-> tuple[str,bool] :
        '''Accesses the list of loaded LISP applications and returns information corresponding to the specified index.'''
        ...
    def getUserData (self)-> object :
        '''                             '''
        ...
    def inputPointManager (self)-> PyEd.InputPointManager :
        '''This function will return this AcApDocument object's input point manager object.'''
        ...
    def isCommandInputInactive (self)-> bool :
        '''This is isCommandInputInactive, a member of class AcApDocument.'''
        ...
    def isQuiescent (self)-> bool :
        '''This function determines if there is a command, LISP script, or ARX command active.Returns true if there is no command, LISP script, or ARX command active; otherwise, it returns false.'''
        ...
    def lockMode (self, bIncludeMyLocks : bool=False)-> PyAp.DocLockMode :
        '''This function provides a way for an application to determine if it could have permission to set a lock on a document. One rule about locking is that an execution context can override any of its own locks. If this application's context has an Exclusive Write lock, it can still apply another lock to the document. Returns the highest level lock set by other execution contexts if bIncludeMyLocks = false. If bIncludeMyLocks = true, then the function will return the highest level lock set by any execution context, include this application.'''
        ...
    def myLockMode (self)-> PyAp.DocLockMode :
        '''This function returns the current lock status that the current execution has on the document, and can be either stronger or weaker than that returned by AcApDocument::lockMode().'''
        ...
    def popDbmod (self)-> None :
        '''This method pops the top value off of the DBMOD system variable stack and copies that value into the document's DBMOD system variable. popDbmod() will return eOk if successful, eIllegalReplacement if the stack was empty, and eInvalidContext if the document is not fully operational. eInvalidContext should only occur during early edit session initialization, before the DBMOD value has been initialized.'''
        ...
    def pushDbmod (self)-> None :
        '''This method copies the current value of the DBMOD system variable onto a stack. This allows you to save the current value of the DBMOD read-only system variable for subsequent restoration through the popDbmod() method.pushDbmod() and its counterpart popDbmod() allow your application to modify a database without having it marked as modified, as is commonly done by applications during edit session initialization. This includes modification of database header variables or adding to and modifying objects in the database being edited, which all cause flags in the document system variable DBMOD to be set. When DBMOD is non-zero, the 'Save your drawing?' prompt is posted when a user attempts to quit out of a drawing. To avoid this prompt in your application, stack the current DBMOD value with pushDbmod() before beginning to modify the database in a manner that should not cause this query, restore DBMOD with popDbmod() when such modifications are complete.'''
        ...
    def setDocTitle (self, title : str)-> None :
        '''Sets the title of the document.'''
        ...
    def setUserData (self, data : object)-> None :
        '''                             '''
        ...
    def transactionManager (self)-> PyAp.TransactionManager :
        '''This function returns the AcTransactionManager object for this AcApDocument. The global function actrTransactionManager() will return a pointer to the current document's transaction manager. This function is important because an application cannot mix objects from different documents in the same transaction. If an application is opening objects from more than one document at a time, and are using transactions, they must start a separate transaction for each document, using the transaction manager from each document.'''
        ...
    def upgradeDocOpen (self)-> None :
        '''Converts the document status from read only to write, if possible.'''
        ...

class LayerFilter(PyRx.RxObject):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def addNested (self, val : PyLy.LayerFilter)-> None :
        '''Adds the filter to this filter as a nested filter.Returns Acad::eNotApplicable when allowNested() is false. Returns Acad::eInvalidInput when filter is null. Returns Acad::eOk when successful.'''
        ...
    def allowDelete (self)-> bool :
        '''Returns true if this filter can be removed.'''
        ...
    def allowNested (self)-> bool :
        '''Returns true if this filter allows nested filters.'''
        ...
    def allowRename (self)-> bool :
        '''Returns a Boolean value indicating whether or not renaming this filter is allowed.'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def compareTo (self, other : PyLy.LayerFilter)-> bool :
        '''Returns true if this filter and pOther allow the same layers.'''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def dynamicallyGenerated (self)-> bool :
        '''When implemented in a derived class, this function should return true if the filter is dynamically generated by its parent and should not be persisted on its own.'''
        ...
    def filter (self, val : PyDb.LayerTableRecord)-> bool :
        '''Returns true if the given AcDbLayerTableRecord is visible with this filter. '''
        ...
    def filterExpression (self)-> str :
        '''Returns a filter expression of this form:    /*    BNF for the valid boolean expression we evaluate    <bool_expr>::= <bool_expr> or <and_expr> | <and_expr>    <and_expr>::=<and_expr> and <rel_expr> | <rel_expr>    <rel_expr>::=<variable><rel_op><constant>     <rel_op>::= == | !=    <constant>::=A-Z0-9*?~@.,-    <variable>::=#A-Z0-9    */This function may return null if the filter cannot be described this way.'''
        ...
    def generateNested (self)-> None :
        '''Called by the ObjectDBX framework after a filter is loaded from persistent storage. This is an opportunity for the filter to generate nested filters. Should return Acad::eOk if successful. Any other return value will abort the loading of this filter and the filter will not be added to the filter tree.'''
        ...
    def getNestedFilters (self)-> list[PyAp.LayerFilter] :
        '''Returns an array containing the nested filters of this filter. The returned array is const; clients should not remove or add filters to this array.'''
        ...
    def isIdFilter (self)-> bool :
        '''Returns true if this filter only filters for the object ID property of a layer. These filters are also known as layer groups.'''
        ...
    def isProxy (self)-> bool :
        '''Returns true if this is a proxy filter. A filter becomes a proxy when ObjectDBX does not find the code (ObjectARX or ObjectDBX application) behind the filter. Proxy filters are not shown to the user by AutoCAD, but their persistent data is round tripped.'''
        ...
    def name (self)-> str :
        '''Returns the name of the filter. This usually what is entered by the user when filter is created. However, for some filters such as the Xref or All filter, this is a localized constant.'''
        ...
    def parent (self)-> PyAp.LayerFilter :
        '''Returns the parent filter for this filter. All filters except the top level ("All") filter have a parent. The top level filter returns null.'''
        ...
    def removeNested (self, val : PyLy.LayerFilter)-> None :
        '''Removes the given filter from the list of nested filters for this filter. Returns Acad::eOk when successful. Returns Acad::eNotApplicable when filter->allowDelete() is false. Returns Acad::eInvalidInput when filter is null. '''
        ...
    def setFilterExpression (self, val : str)-> None :
        '''Sets a new filter expression. See filterExpression() for valid filter expressions. Returns eNotApplicable if the filter is not expression-based. Returns eInvalidInput if the expression is invalid. Returns eOk otherwise.'''
        ...
    def setName (self, val : str)-> None :
        '''Sets the name of the filter.If renaming is not allowed, this function returns Acad::eNotApplicable. If the name is null, then it returns Acad::eInvalidInput. Returns Acad::eOk when successful.'''
        ...
    def showEditor (self)-> int :
        '''Called by the host application to show an editor window for the filter. The editor is displayed as a child of the active popup window.Return kUseDefault if you want to instruct the host application to display the default filter dialog.'''
        ...

class LayerFilterManager(object):
    def __init__ (self, db: PyDb.Database=None)-> None :
        '''                             '''
        ...
    def getFilters (self)-> tuple[PyAp.LayerFilter,PyAp.LayerFilter] :
        '''                             '''
        ...

    @overload
    def setFilters (self, root: PyLy.LayerFilter, current: PyLy.LayerFilter)-> None : ...
    @overload
    def setFilters (self, rootCurrent : tuple[PyLy.LayerFilter,PyLy.LayerFilter])-> None : ...
    def setFilters (self, *args, **kwargs)-> None :
        '''Overloads:
    - root: PyLy.LayerFilter, current: PyLy.LayerFilter
    - rootCurrent : tuple[PyLy.LayerFilter,PyLy.LayerFilter]
    '''
        ...

class LayerGroup(LayerFilter):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def addLayerId (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def layerIds (self)-> list[PyDb.ObjectId] :
        '''                             '''
        ...
    def removeLayerId (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

class LayoutManager(PyDb.LayoutManager):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def createLayoutFromTemplate (self, newLayoutName : str, templatePath : str, layoutName : str, db : PyDb.Database='current')-> PyDb.ObjectId :
        '''Creates a new layout from an existing layout that is stored in a drawing or drawing template file.'''
        ...
    def createViewports (self)-> bool :
        '''This function returns kTrue if a viewport will be created by default in a paper space layout, and kFalse otherwise.'''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def generateNextNewLayoutName (self, val : PyDb.Database='current')-> str :
        '''This function scans the existing layouts (included deleted ones) for name matches of the type "Layout#" where # is a number starting at 1 and increasing. The function starts with Layout1 and keeps trying to find one that isn't already used in this format and then returns it.'''
        ...
    def getActiveTab (self)-> str :
        '''This function returns the name of the currently selected layout tab which is also the name of the current AcDbLayout object.'''
        ...
    def getClipBoundaryElabration (self, val : PyDb.ObjectId)-> list[PyGe.Point2d] :
        '''                             '''
        ...
    def pageSetup (self, layoutBTRId : PyDb.ObjectId=PyDb.ObjectId.kNull, parent : int=0, isPageSetupDlg : bool=True)-> int :
        '''By default, this function launches the Page Setup dialog with the current AcDbLayout object. Optionally, this function takes arguments to initialize it with a different AcDbLayout object, a pointer to a different parent window, and whether to bring up the shared Plot dialog instead of the Page Setup dialog.The function returns O if the Page Setup dialog has been canceled; 1 if the the Page Setup dialog has succeeded; and -1 for any error conditions.'''
        ...
    def pointInViewports (self, val : PyGe.Point3d)-> list[PyDb.ObjectId] :
        '''This function takes a Paperspace pick point, and passes back a list, in the form of an AcDbObjectIdArray, of the AcDbObjectId entities of every AcDbViewport that overlays the pick point, including non-rectangular viewports.If viewports overlap each other at the pick point, all of them will be returned, but the first AcDbViewport Id in the array will be the viewport that would be selected if the user double-clicked at the point. The PaperSpace viewport will never be included in the array. If no viewports are at the pick point, ePointNotOnEntity will be returned, and the AcDbObjectIdArray will not be created. If at least one viewport is in the array, eOk will be returned. The caller must delete the returned AcDbObjectIdArray when finished with it. This routine allows an application to easily determine if a given point lies within a non-rectangular (clipped) viewport.'''
        ...
    def setCaptureOnLayoutSwitch (self, val : bool)-> None :
        '''Controls whether a thumbnail is generated for a layout after it has been set active. An argument of kTrue enables the generation of the thumbnail; kFalse disables the generation of the thumbnail.'''
        ...
    def setCreateViewports (self, val : bool)-> None :
        '''This function establishes whether a viewport is created by default on initial entry into a paper space layout.'''
        ...
    def setDefaultPlotConfig (self, val : PyDb.ObjectId)-> None :
        '''This function sets appropriate defaults for the AcDbLayout associated with the given AcDbBlockTableRecord.'''
        ...
    def setShowPageSetup (self, val : bool)-> None :
        '''This function sets whether the Page Setup dialog is launched upon initial entry into a paper space layout tab.'''
        ...
    def setShowPaperBackground (self, val : bool)-> None :
        '''This function sets whether the paper shadow is visible for the current or active AcDbLayout object. An argument of kTrue sets the paper shadow visible; kFalse makes it invisible.'''
        ...
    def setShowPaperMargins (self, val : bool)-> None :
        '''This function sets whether the printable area or paper margin (the dashed rectangle) is visible for the current or active AcDbLayout object. An argument of kTrue sets the paper margin visible; kFalse makes it invisible.'''
        ...
    def setShowPrintBorder (self, val : bool)-> None :
        '''This function sets whether the print border (paper boundary) is visible for the current or active AcDbLayout object. An argument of kTrue sets the print border visible; kFalse makes it invisible.'''
        ...
    def setShowTabs (self, val : bool)-> None :
        '''This function sets whether the layout tabs are visible. An argument of kTrue sets the layout tabs to be visible; kFalse makes them invisible.'''
        ...
    def showPageSetup (self)-> bool :
        '''This function returns whether the Page Setup dialog is automatically launched upon initial entry into a paper space layout. A return of 1 indicates it is launched; 0, it isn't.'''
        ...
    def showPaperBackground (self)-> bool :
        '''This function sets whether the Page Setup dialog is launched upon initial entry into a paper space layout tab.'''
        ...
    def showPaperMargins (self)-> bool :
        '''This function returns whether the current AcDbLayout object's paper margins are visible. A return of 1 indicates it's visible; 0, invisible.'''
        ...
    def showPrintBorder (self)-> bool :
        '''This function returns whether the current AcDbLayout object's print border is visible. A return of 1 indicates it's visible; 0, invisible.'''
        ...
    def showTabs (self)-> bool :
        '''This function returns whether the layout tabs are visible. A return of 1 indicates they're visible; 0, invisible.'''
        ...
    def updateCurrentPaper (self, zoomToPaper : bool=False)-> None :
        '''This function updates the paper space paper image to reflect the current state of the active AcDbLayout object. Optionally, an argument of kTrue can be passed in to perform a zoom to change the view to the extents of the paper image boundary.'''
        ...
    def updateLayoutTabs (self)-> None :
        '''This function regenerates the layout tabs to update them to the current state of the AcDbLayout objects they represent.'''
        ...

class Palette(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def getWxWindow (self)-> object :
        '''                             '''
        ...

class PaletteDockStyle(object):
    def kAny (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kBottom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kTop (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PaletteSet(object):
    def __init__ (self, name : str, guid : str=None)-> None :
        '''                             '''
        ...
    def add (self, name : str)-> int :
        '''                             '''
        ...
    def anchored (self)-> bool :
        '''                             '''
        ...
    def autoRollupStyle (self)-> bool :
        '''Returns true if the palette set has the PSS_AUTO_ROLLUP style set; otherwise, returns false.'''
        ...
    def closeButtonStyle (self)-> bool :
        '''Returns true if the palette set has the PSS_CLOSE_BUTTON style set; otherwise, returns false.'''
        ...
    def dockControlBar (self, style: PyAp.PaletteDockStyle, rect: tuple[int,int,int,int])-> None :
        '''                             '''
        ...
    def editNameStyle (self)-> bool :
        '''Returns true if the palette has the PS_EDIT_NAME style set; otherwise, returns false.'''
        ...
    def enableDocking (self, style : PyAp.PaletteDockStyle)-> None :
        '''                             '''
        ...
    def getActivePaletteTabIndex (self)-> int :
        '''Returns the zero-based tab index of the currently active palette.'''
        ...
    def getAutoRollup (self)-> bool :
        '''Returns true if auto rollup is enabled. Returns false if it is disabled or if the the auto-rollup style is not set for the palette set.'''
        ...
    def getDockState (self)-> PyAp.PaletteDockStyle :
        '''                             '''
        ...
    def getFloatingRect (self)-> tuple[int,int,int,int] :
        '''                             '''
        ...
    def getFullRect (self)-> object :
        '''Gets the full window rectangle of the palette set. This function retrieves the rectangle of the unrolled palette set even if the palette set is currently rolled up.'''
        ...
    def getName (self)-> str :
        '''Returns the name of the palette set.'''
        ...
    def getOpacity (self)-> int :
        '''Returns the current opacity for the palette set.Valid values are in the range 0 to 100, where 0 is completely transparent and 100 is completely opaque.'''
        ...
    def getPaletteCount (self)-> int :
        '''Returns the number of palettes in the palette set.'''
        ...
    def getPaletteSetStyle (self)-> int :
        '''Returns the palette set style, which is a combination of the CAdUiPaletteSet palette style constants.'''
        ...
    def getRolloverOpacity (self)-> int :
        '''Returns the rollover opacity value.'''
        ...
    def getWxWindow (self)-> object :
        '''                             '''
        ...

    @staticmethod
    def hidePalettes ()-> bool :
        '''                             '''
        ...
    def initFloatingPosition (self, rect: tuple[int,int,int,int])-> None :
        '''                             '''
        ...
    def isFloating (self)-> bool :
        '''                             '''
        ...
    def paletteBackgroundColor (self)-> int :
        '''                             '''
        ...
    def paletteTabTextColor (self)-> int :
        '''                             '''
        ...
    def propertiesMenuStyle (self)-> bool :
        '''Returns true if the palette set has the PSS_PROPERTIES_MENU style set; otherwise, returns false.'''
        ...
    def removePalette (self, val : int)-> bool :
        '''Removes the palette specified by nPaletteIndex from the palette set. Returns true if the palette was successfuly removed; otherwise, returns false.'''
        ...

    @overload
    def restoreControlBar (self, /)-> None : ...
    @overload
    def restoreControlBar (self, style: PyAp.PaletteDockStyle, rect: tuple[int,int,int,int])-> None : ...
    def restoreControlBar (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - style: PyAp.PaletteDockStyle, rect: tuple[int,int,int,int]
    '''
        ...
    def rollOut (self, delay : bool=False)-> None :
        '''Triggers a roll out of the palette set if auto-rollup is on and the palette set is not docked.If bDelay is true, the palette set will use an extended rollup delay time. When the parameter is false, the palette set will use the normal delay time for rolling up.'''
        ...
    def rollUp (self)-> None :
        '''Triggers a roll up of the palette set if auto-rollup is on and the palette set is not docked.'''
        ...
    def rolledUp (self)-> bool :
        '''Returns true if the palette set is rolled up; returns false if it is unrolled.'''
        ...
    def setActivePalette (self, val : int)-> bool :
        '''Sets the palette specified by nPaletteIndex to be the currently active palette.'''
        ...
    def setAutoRollup (self, val : bool)-> bool :
        '''Enables and disables auto rollup for the palette set.Setting the auto-rollup state also causes the palette set to react as necessary. For example, it will roll out if auto rollup is disabled and may roll up, depending on the cursor position, if auto rollup is enabled.'''
        ...
    def setDockState (self, style : PyAp.PaletteDockStyle)-> None :
        '''                             '''
        ...
    def setLocation (self, x : int, y : int)-> None :
        '''                             '''
        ...
    def setName (self, name : str)-> bool :
        '''Sets the name of the palette set.Returns true if the palette set name is successfully set to pszName; otherwise, returns false. '''
        ...
    def setOpacity (self, val : int)-> bool :
        '''Sets the opacity for the palette set. the opacity must be in the range 0 to 100, where 0 is completely transparent and 100 is completely opaque.'''
        ...
    def setPaletteSetStyle (self, val : int)-> None :
        '''Sets the palette set style.'''
        ...
    def setRolloverOpacity (self, val : int)-> bool :
        '''Sets the value of the rollover opacity.Returns true if successful.'''
        ...
    def setSize (self, x : int, y : int)-> None :
        '''                             '''
        ...
    def setTitleBarLocation (self, val : PyAp.PaletteTitleBarLocation)-> None :
        '''Sets the title bar orientation (left or right) for the palette set. '''
        ...
    def setToolId (self, guid : str)-> bool :
        '''Sets the identifier associated with a control bar. Since a control identifier needs to be unique, class IDs are used for that purpose. You can generate a class ID using the system utility GUIDGEN.A good place to call this method is right after you called the Create() method. It must be called before RestoreControlBar() because the persistency system relies on the control bar IDs.'''
        ...
    def setVisible (self, val : bool)-> None :
        '''                             '''
        ...
    def showIconStyle (self)-> bool :
        '''This is ShowIconStyle, a member of class CAdUiPaletteSet.'''
        ...

    @staticmethod
    def showPalettes ()-> bool :
        '''                             '''
        ...
    def showRollupButtonStyle (self)-> bool :
        '''This is ShowRollupButtonStyle, a member of class CAdUiPaletteSet.'''
        ...
    def singlePaletteTabStyle (self)-> bool :
        '''Returns true if the palette set has the PSS_SINGLE_PALETTE_TAB style set; otherwise, returns false.'''
        ...
    def snapStyle (self)-> bool :
        '''Returns true if the palette set has the PSS_SNAP style set; otherwise, returns false.'''
        ...
    def titleBarLocation (self)-> PyAp.PaletteTitleBarLocation :
        '''Returns the current location of the palette set title bar, either kRight or kLeft.'''
        ...
    def updateTabs (self)-> None :
        '''Updates the palette set's tab display.The base palette implementation calls this function when a palette name changes.'''
        ...
    def useSinglePaletteTabNameStyle (self)-> bool :
        '''Returns true if the palette set has the PSS_USE_SINGLE_PALETTE_TAB_NAME style set.'''
        ...

class PaletteTitleBarLocation(object):
    def kLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRight (self, *args, **kwargs)-> None :
        '''None'''
        ...

class ResourceOverride(object):
    def __init__ (self)-> None :
        '''Use an instance of this class to switch between default and module's resources. When the object is constructed, a new resource provider will be switched in. Upon destruction the original resource provider will be restored. For example:void MyFunc()    {        CAcModuleResourceOverride myResources;        .        .    }Upon entry to this function, the module's resources will be selected. When the function returns, the default resources will be restored. A resource override can be used in any of three ways:Use the default constructor (no arguments) to switch to the module's resources. The default resources will be restored by the destructor. The module/default resources are those maintained by the DLL's CAcExtensionModule.Pass NULL (or 0) to the constructor. The DLL's resources will be selected and the resources that were in effect will be restored when the override object is destroyed.Pass a non-NULL handle to the constructor. The associated module's resources will be selected and the resources that were in effect will be restored when the override object is destroyed.'''
        ...
    def className (self, *args, **kwargs)-> str :
        '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
        ...

class SaveFormat(object):
    def k2000_Standard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2000_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2000_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2000_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2000_xml (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2004_Standard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2004_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2004_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2004_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2007_Standard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2007_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2007_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2007_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2010_Standard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2010_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2010_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2010_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2013_Standard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2013_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2013_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2013_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2018_Standard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2018_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2018_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def k2018_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNative (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNative_Template (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kR12_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kR13_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kR13_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kR14_dwg (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kR14_dxf (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUnknown (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TransactionManager(PyDb.TransactionManager):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def enableGraphicsFlush (self, val: bool)-> None :
        '''                             '''
        ...
    def flushGraphics (self)-> None :
        '''                             '''
        ...

def curDoc (*args, **kwargs)-> PyAp.Document :
    '''curDoc() -> Document :

    C++ signature :
        class PyApDocument curDoc()'''
    ...
