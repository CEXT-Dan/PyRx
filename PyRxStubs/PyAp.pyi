import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class AdUiTitleBarLocation(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kLeft (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kRight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

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
    def getLoadedModuleNames ()-> list :
      '''                             '''
    ...

    @staticmethod
    def getLoadedModules ()-> list :
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
    def reloadPythonModule (fullpath: str)-> bool :
      '''                             '''
    ...

    @staticmethod
    def removeOnIdleWinMsg (func: Any)-> None :
      '''                             '''
    ...

    @staticmethod
    def setTitleThemeDark (wnd : int)-> None :
      '''                             '''
    ...

    @staticmethod
    def wxApp ()-> object :
      '''                             '''
    ...

class AutoDocLock(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class DocManager(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def activateDocument (self, doc: PyAp.Document, bPassScript: bool = False)-> None :
      '''                             '''
    ...
    def appContextCloseDocument (self, doc: PyAp.Document)-> None :
      '''                             '''
    ...
    def appContextNewDocument (self, templateName : str)-> None :
      '''                             '''
    ...
    def appContextOpenDocument (self, dwgName : str)-> None :
      '''                             '''
    ...
    def appContextPromptOpenDocument (self)-> None :
      '''                             '''
    ...
    def appContextRecoverDocument (self, dwgName : str)-> None :
      '''                             '''
    ...

    @staticmethod
    def autoLock ()-> PyAp.AutoDocLock :
      '''                             '''
    ...
    def beginExecuteInApplicationContext (self, func: Any, data: Any)-> PyDb.ErrorStatus :
      '''                             '''
    ...
    def beginExecuteInCommandContext (self, func: Any, data: Any)-> PyDb.ErrorStatus :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closeDocument (self, doc: PyAp.Document)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...
    def curDocument (self)-> PyAp.Document :
      '''                             '''
    ...
    def defaultFormatForSave (self)-> PyAp.SaveFormat :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def disableDocumentActivation (self)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def document (self, db: PyDb.Database)-> PyAp.Document :
      '''                             '''
    ...
    def documentCount (self)-> int :
      '''                             '''
    ...
    def documents (self)-> list :
      '''                             '''
    ...
    def enableDocumentActivation (self)-> None :
      '''                             '''
    ...
    def executeInApplicationContext (self, func: Any, data: Any)-> None :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def inputPending (self, doc: PyAp.Document)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isApplicationContext (self)-> bool :
      '''                             '''
    ...
    def isDocumentActivationEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def lockDocument (self, doc: PyAp.Document, mode: PyAp.DocLockMode = kWrite, gcmd: str = None, lcmd: str = None, prmt: bool = True)-> None :
      '''                             '''
    ...
    def mdiActiveDocument (self)-> PyAp.Document :
      '''                             '''
    ...
    def newDocument (self)-> None :
      '''                             '''
    ...
    def openDocument (self)-> None :
      '''                             '''
    ...
    def popResourceHandle (self)-> None :
      '''                             '''
    ...
    def pushAcadResourceHandle (self)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def sendModelessInterrupt (self, doc: PyAp.Document)-> None :
      '''                             '''
    ...
    def sendStringToExecute (self, doc: PyAp.Document, script: str, bActivate: bool = True, bWrapUpInactiveDoc: bool = False, bEchoString: bool = True)-> None :
      '''                             '''
    ...
    def setCurDocument (self, doc: PyAp.Document, mode: PyAp.DocLockMode = kNone, activate: bool = False)-> None :
      '''                             '''
    ...
    def setDefaultFormatForSave (self, fmt : PyAp.SaveFormat)-> None :
      '''                             '''
    ...
    def unlockDocument (self, doc: PyAp.Document)-> None :
      '''                             '''
    ...

class DocManagerReactor(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addReactor (self)-> None :
      '''                             '''
    ...
    def documentActivated (self, val : Document)-> None :
      '''                             '''
    ...
    def documentActivationModified (self, val : bool)-> None :
      '''                             '''
    ...
    def documentBecameCurrent (self, val : Document)-> None :
      '''                             '''
    ...
    def documentCreateCanceled (self, val : Document)-> None :
      '''                             '''
    ...
    def documentCreateStarted (self, val : Document)-> None :
      '''                             '''
    ...
    def documentCreated (self, val : Document)-> None :
      '''                             '''
    ...
    def documentDestroyed (self, val : str)-> None :
      '''                             '''
    ...
    def documentLockModeChangeVetoed (self, doc : Document, globalCmdName : str)-> None :
      '''                             '''
    ...
    def documentLockModeChanged (self, doc : Document, myPrevMode : DocLockMode, myCurMode : DocLockMode, currentMode : DocLockMode, globalCmdName : str)-> None :
      '''                             '''
    ...
    def documentLockModeWillChange (self, myCurMode : DocLockMode, myNewMode : DocLockMode, curMode : DocLockMode, globalCmdName : str)-> None :
      '''                             '''
    ...
    def documentToBeActivated (self, val : Document)-> None :
      '''                             '''
    ...
    def documentToBeDeactivated (self, val : Document)-> None :
      '''                             '''
    ...
    def documentToBeDestroyed (self, val : Document)-> None :
      '''                             '''
    ...
    def removeReactor (self)-> None :
      '''                             '''
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def docTitle (self)-> str :
      '''                             '''
    ...

    @staticmethod
    def docWnd ()-> int :
      '''                             '''
    ...
    def downgradeDocOpen (self, promptForSave : bool)-> None :
      '''                             '''
    ...
    def editor (self)-> PyEd.Editor :
      '''                             '''
    ...
    def fileName (self)-> str :
      '''                             '''
    ...
    def formatForSave (self)-> PyAp.SaveFormat :
      '''                             '''
    ...
    def getCountOfLispList (self)-> int :
      '''                             '''
    ...
    def getItemOfLispList (self, index : int)-> tuple :
      '''                             '''
    ...
    def getUserData (self)-> object :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def inputPointManager (self)-> PyEd.InputPointManager :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isCommandInputInactive (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isQuiescent (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def lockMode (self, bIncludeMyLocks : bool=False)-> PyAp.DocLockMode :
      '''                             '''
    ...
    def myLockMode (self)-> PyAp.DocLockMode :
      '''                             '''
    ...
    def popDbmod (self)-> None :
      '''                             '''
    ...
    def pushDbmod (self)-> None :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def setDocTitle (self, title : str)-> None :
      '''                             '''
    ...
    def setUserData (self, data : any)-> None :
      '''                             '''
    ...
    def transactionManager (self)-> PyAp.TransactionManager :
      '''                             '''
    ...
    def upgradeDocOpen (self)-> None :
      '''                             '''
    ...

class LayerFilter(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addNested (self, val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def allowDelete (self)-> bool :
      '''                             '''
    ...
    def allowNested (self)-> bool :
      '''                             '''
    ...
    def allowRename (self)-> bool :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def compareTo (self, other : PyLy.LayerFilter)-> bool :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def dynamicallyGenerated (self)-> bool :
      '''                             '''
    ...
    def filter (self, val : PyDb.LayerTableRecord)-> bool :
      '''                             '''
    ...
    def filterExpression (self)-> str :
      '''                             '''
    ...
    def generateNested (self)-> None :
      '''                             '''
    ...
    def getNestedFilters (self)-> list :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isIdFilter (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isProxy (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def parent (self)-> PyAp.LayerFilter :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def removeNested (self, val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def setFilterExpression (self, val : str)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> None :
      '''                             '''
    ...
    def showEditor (self)-> int :
      '''                             '''
    ...

class LayerFilterManager(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Database)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyDbDatabase {lvalue})'''
    ...
    def getFilters (self, *args, **kwargs)-> tuple :
      '''getFilters( (LayerFilterManager)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFilters(class PyLayerFilterManager {lvalue})'''
    ...
    def setFilters (self, *args, **kwargs)-> None :
      '''setFilters( (LayerFilterManager)arg1, (tuple)arg2) -> None :

    C++ signature :
        void setFilters(class PyLayerFilterManager {lvalue},class boost::python::tuple {lvalue})

setFilters( (LayerFilterManager)arg1, (LayerFilter)arg2, (LayerFilter)arg3) -> None :

    C++ signature :
        void setFilters(class PyLayerFilterManager {lvalue},class PyLyLayerFilter {lvalue},class PyLyLayerFilter {lvalue})'''
    ...

class LayerGroup(LayerFilter):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addLayerId (self, *args, **kwargs)-> None :
      '''addLayerId( (LayerGroup)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void addLayerId(class PyLyLayerGroup {lvalue},class PyDbObjectId)'''
    ...
    def addNested (self, val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def allowDelete (self)-> bool :
      '''                             '''
    ...
    def allowNested (self)-> bool :
      '''                             '''
    ...
    def allowRename (self)-> bool :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def compareTo (self, other : PyLy.LayerFilter)-> bool :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def dynamicallyGenerated (self)-> bool :
      '''                             '''
    ...
    def filter (self, val : PyDb.LayerTableRecord)-> bool :
      '''                             '''
    ...
    def filterExpression (self)-> str :
      '''                             '''
    ...
    def generateNested (self)-> None :
      '''                             '''
    ...
    def getNestedFilters (self)-> list :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isIdFilter (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isProxy (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layerIds (self, *args, **kwargs)-> list :
      '''layerIds( (LayerGroup)arg1) -> list :

    C++ signature :
        class boost::python::list layerIds(class PyLyLayerGroup {lvalue})'''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def parent (self)-> PyAp.LayerFilter :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def removeLayerId (self, *args, **kwargs)-> None :
      '''removeLayerId( (LayerGroup)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void removeLayerId(class PyLyLayerGroup {lvalue},class PyDbObjectId)'''
    ...
    def removeNested (self, val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def setFilterExpression (self, val : str)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> None :
      '''                             '''
    ...
    def showEditor (self)-> int :
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
    def clearSetupForLayouts (self, *args, **kwargs)-> None :
      '''clearSetupForLayouts( (int)arg1) -> None :

    C++ signature :
        void clearSetupForLayouts(unsigned __int64)'''
    ...
    def cloneLayout (self, *args, **kwargs)-> None :
      '''cloneLayout( (LayoutManager)arg1, (Layout)arg2, (str)arg3) -> None :

    C++ signature :
        void cloneLayout(class PyDbLayoutManager {lvalue},class PyDbLayout {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

cloneLayout( (LayoutManager)arg1, (Layout)arg2, (str)arg3, (int)arg4, (Database)arg5) -> None :

    C++ signature :
        void cloneLayout(class PyDbLayoutManager {lvalue},class PyDbLayout {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int,class PyDbDatabase {lvalue})'''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...
    def copyLayout (self, *args, **kwargs)-> None :
      '''copyLayout( (LayoutManager)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void copyLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

copyLayout( (LayoutManager)arg1, (str)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void copyLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase)'''
    ...
    def countLayouts (self, *args, **kwargs)-> int :
      '''countLayouts( (LayoutManager)arg1) -> int :

    C++ signature :
        int countLayouts(class PyDbLayoutManager {lvalue})

countLayouts( (LayoutManager)arg1, (Database)arg2) -> int :

    C++ signature :
        int countLayouts(class PyDbLayoutManager {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def createLayout (self, *args, **kwargs)-> None :
      '''createLayout( (LayoutManager)arg1, (str)arg2, (ObjectId)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void createLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbObjectId {lvalue},class PyDbObjectId {lvalue})

createLayout( (LayoutManager)arg1, (str)arg2, (ObjectId)arg3, (ObjectId)arg4, (Database)arg5) -> None :

    C++ signature :
        void createLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbObjectId {lvalue},class PyDbObjectId {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def createLayoutFromTemplate (self, newLayoutName : str, templatePath : str, layoutName : str, db : PyDb.Database='current')-> PyDb.ObjectId :
      '''                             '''
    ...
    def createViewports (self)-> bool :
      '''                             '''
    ...
    def deleteLayout (self, *args, **kwargs)-> None :
      '''deleteLayout( (LayoutManager)arg1, (str)arg2) -> None :

    C++ signature :
        void deleteLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

deleteLayout( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> None :

    C++ signature :
        void deleteLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def findLayoutNamed (self, *args, **kwargs)-> PyDb.ObjectId :
      '''findLayoutNamed( (LayoutManager)arg1, (str)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId findLayoutNamed(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

findLayoutNamed( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> ObjectId :

    C++ signature :
        class PyDbObjectId findLayoutNamed(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase)'''
    ...
    def generateNextNewLayoutName (self, val : PyDb.Database='current')-> str :
      '''                             '''
    ...
    def getActiveLayoutBTRId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''getActiveLayoutBTRId( (LayoutManager)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getActiveLayoutBTRId(class PyDbLayoutManager {lvalue})

getActiveLayoutBTRId( (LayoutManager)arg1, (Database)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId getActiveLayoutBTRId(class PyDbLayoutManager {lvalue},class PyDbDatabase)'''
    ...
    def getActiveLayoutName (self, *args, **kwargs)-> str :
      '''getActiveLayoutName( (LayoutManager)arg1, (bool)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getActiveLayoutName(class PyDbLayoutManager {lvalue},bool)

getActiveLayoutName( (LayoutManager)arg1, (bool)arg2, (Database)arg3) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getActiveLayoutName(class PyDbLayoutManager {lvalue},bool,class PyDbDatabase {lvalue})'''
    ...
    def getActiveTab (self)-> str :
      '''                             '''
    ...
    def getClipBoundaryElabration (self, val : PyDb.ObjectId)-> list :
      '''                             '''
    ...
    def getNonRectVPIdFromClipId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''getNonRectVPIdFromClipId( (LayoutManager)arg1, (ObjectId)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId getNonRectVPIdFromClipId(class PyDbLayoutManager {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isVpnumClipped (self, *args, **kwargs)-> bool :
      '''isVpnumClipped( (LayoutManager)arg1, (int)arg2) -> bool :

    C++ signature :
        bool isVpnumClipped(class PyDbLayoutManager {lvalue},int)

isVpnumClipped( (LayoutManager)arg1, (int)arg2, (Database)arg3) -> bool :

    C++ signature :
        bool isVpnumClipped(class PyDbLayoutManager {lvalue},int,class PyDbDatabase)'''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layoutExists (self, *args, **kwargs)-> bool :
      '''layoutExists( (LayoutManager)arg1, (str)arg2) -> bool :

    C++ signature :
        bool layoutExists(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

layoutExists( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> bool :

    C++ signature :
        bool layoutExists(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase)'''
    ...
    def pageSetup (self, layoutBTRId : PyDb.ObjectId=PyDb.ObjectId.kNull, parent : int=0, isPageSetupDlg : bool=True)-> int :
      '''                             '''
    ...
    def pointInViewports (self, val : PyGe.Point3d)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def renameLayout (self, *args, **kwargs)-> None :
      '''renameLayout( (LayoutManager)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void renameLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

renameLayout( (LayoutManager)arg1, (str)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void renameLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def setCaptureOnLayoutSwitch (self, val : bool)-> None :
      '''                             '''
    ...
    def setCreateViewports (self, val : bool)-> None :
      '''                             '''
    ...
    def setCurrentLayout (self, *args, **kwargs)-> None :
      '''setCurrentLayout( (LayoutManager)arg1, (str)arg2) -> None :

    C++ signature :
        void setCurrentLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

setCurrentLayout( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> None :

    C++ signature :
        void setCurrentLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def setCurrentLayoutId (self, *args, **kwargs)-> None :
      '''setCurrentLayoutId( (LayoutManager)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setCurrentLayoutId(class PyDbLayoutManager {lvalue},class PyDbObjectId)'''
    ...
    def setDefaultPlotConfig (self, val : PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setShowPageSetup (self, val : bool)-> None :
      '''                             '''
    ...
    def setShowPaperBackground (self, val : bool)-> None :
      '''                             '''
    ...
    def setShowPaperMargins (self, val : bool)-> None :
      '''                             '''
    ...
    def setShowPrintBorder (self, val : bool)-> None :
      '''                             '''
    ...
    def setShowTabs (self, val : bool)-> None :
      '''                             '''
    ...
    def setupForLayouts (self, *args, **kwargs)-> int :
      '''setupForLayouts( (Database)arg1) -> int :

    C++ signature :
        unsigned __int64 setupForLayouts(class PyDbDatabase {lvalue})'''
    ...
    def showPageSetup (self)-> bool :
      '''                             '''
    ...
    def showPaperBackground (self)-> bool :
      '''                             '''
    ...
    def showPaperMargins (self)-> bool :
      '''                             '''
    ...
    def showPrintBorder (self)-> bool :
      '''                             '''
    ...
    def showTabs (self)-> bool :
      '''                             '''
    ...
    def updateCurrentPaper (self, zoomToPaper : bool=False)-> None :
      '''                             '''
    ...
    def updateLayoutTabs (self)-> None :
      '''                             '''
    ...

class PaletteSet(object):
    def __init__ (self, name : str, guid : str=None)-> None :
      '''                             '''
    ...
    def add (self, name : str)-> int :
      '''                             '''
    ...
    def autoRollupStyle (self)-> bool :
      '''                             '''
    ...
    def closeButtonStyle (self)-> bool :
      '''                             '''
    ...
    def editNameStyle (self)-> bool :
      '''                             '''
    ...
    def getActivePaletteTabIndex (self)-> int :
      '''                             '''
    ...
    def getAutoRollup (self)-> bool :
      '''                             '''
    ...
    def getFullRect (self)-> object :
      '''                             '''
    ...
    def getName (self)-> str :
      '''                             '''
    ...
    def getOpacity (self)-> int :
      '''                             '''
    ...
    def getPaletteCount (self)-> int :
      '''                             '''
    ...
    def getPaletteSetStyle (self)-> int :
      '''                             '''
    ...
    def getRolloverOpacity (self)-> int :
      '''                             '''
    ...
    def paletteBackgroundColor (self)-> int :
      '''                             '''
    ...
    def paletteTabTextColor (self)-> int :
      '''                             '''
    ...
    def propertiesMenuStyle (self)-> bool :
      '''                             '''
    ...
    def removePalette (self, val : int)-> bool :
      '''                             '''
    ...
    def rollOut (self, delay : bool=False)-> None :
      '''                             '''
    ...
    def rollUp (self)-> None :
      '''                             '''
    ...
    def rolledUp (self)-> bool :
      '''                             '''
    ...
    def setActivePalette (self, val : int)-> bool :
      '''                             '''
    ...
    def setAutoRollup (self, val : bool)-> bool :
      '''                             '''
    ...
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setOpacity (self, val : int)-> bool :
      '''                             '''
    ...
    def setPaletteSetStyle (self, val : int)-> None :
      '''                             '''
    ...
    def setRolloverOpacity (self, val : int)-> bool :
      '''                             '''
    ...
    def setTitleBarLocation (self, val : AdUiTitleBarLocation)-> None :
      '''                             '''
    ...
    def setToolId (self, guid : str)-> bool :
      '''                             '''
    ...
    def setVisible (self, val : bool)-> None :
      '''                             '''
    ...
    def showIconStyle (self)-> bool :
      '''                             '''
    ...
    def showRollupButtonStyle (self)-> bool :
      '''                             '''
    ...
    def singlePaletteTabStyle (self)-> bool :
      '''                             '''
    ...
    def snapStyle (self)-> bool :
      '''                             '''
    ...
    def titleBarLocation (self)-> PyAp.AdUiTitleBarLocation :
      '''                             '''
    ...
    def updateTabs (self)-> None :
      '''                             '''
    ...
    def useSinglePaletteTabNameStyle (self)-> bool :
      '''                             '''
    ...

class ResourceOverride(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...

class SaveFormat(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TransactionManager(PyDb.TransactionManager):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def abortTransaction (self)-> None :
      '''                             '''
    ...
    def addNewlyCreatedDBRObject (self, obj: DbObject, add: bool=True)-> None :
      '''                             '''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''Function usage:This function is intended to allow classes to provide a means to compare class objects much the way strcmp() compares character strings.The object pointed to by other is compared with this object. The result of the comparison is returned.The possible AcRx::Ordering types are:AcRx::kLessThanAcRx::kEqualAcRx::kGreaterThanAcRx::kNotOrderableThe AcRx::kNotOrderable type is there because C++ classes often cannot support object value comparison.Function implementation in derived classes:There are no restrictions or expectations on how this function is implemented. Each class will have its own requirements for comparison.Default implementation:Simply returns AcRx::kNotOrderable since many C++ classes cannot support object value comparison.'''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''Function usage:Copies the contents of other into the messaged object, whenever feasible. Function implementation in derived classes:If implemented, this function needs to be able to read the data in the object pointed to by other and copy any or all data as appropriate into this object. There is no requirement that the object pointed to by other and this object be of the same class, but that is the generally assumed condition.Default implementation: Because this function must be overridden to have any meaning, a fatal error will be caused when calling the default implementation. '''
    ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def enableGraphicsFlush (self, *args, **kwargs)-> None :
      '''enableGraphicsFlush( (TransactionManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void enableGraphicsFlush(class PyTransactionManager {lvalue},bool)'''
    ...
    def endTransaction (self)-> None :
      '''                             '''
    ...
    def flushGraphics (self, *args, **kwargs)-> None :
      '''flushGraphics( (TransactionManager)arg1) -> None :

    C++ signature :
        void flushGraphics(class PyTransactionManager {lvalue})'''
    ...
    def getAllObjects (self)-> list :
      '''                             '''
    ...
    def getObject (self, id: ObjectId, mode: OpenMode=OpenMode.kForRead, openErasedObject: bool=False)-> PyDb.DbObject :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''Function usage:For each class registered with ObjectARX, the implementation of this function is to return a pointer to the AcRxClass object for the class of the object in which this method is called. For classes not registered with ObjectARX, this method has no meaning.Function implementation in derived classes:This function is overridden in all derived classes. The AcRx macros declare and define this function, so that the override is taken care of as part of using the macros. The implementation of this function is simply to return ::desc(). For example. the implementation for AcDbLine would be:return AcDbLine::desc();Default implementation for AcRxObject:  { return AcRxObject::desc(); }'''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''Returns true if "this" object is of a member of either the class represented by aClass, or a class derived from aClass. '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def numActiveTransactions (self)-> int :
      '''                             '''
    ...
    def numOpenedObjects (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''This method searches for a protocol extension object associated with this object.The method begins the search by examining the AcRxClass object associated with this object, and if no protocol extension object is found, the search continues in the base class of the object's class and so on up the inheritance tree for the class. This procedure provides a form of protocol extension inheritance. An object's AcRxClass member may be found by using the class's isA() method.If the search for a protocol extension object is unsuccessful, then NULL is returned.'''
    ...
    def queueForGraphicsFlush (self)-> None :
      '''                             '''
    ...
    def startTransaction (self)-> PyDb.Transaction :
      '''                             '''
    ...
    def topTransaction (self)-> PyDb.Transaction :
      '''                             '''
    ...

def curDoc (*args, **kwargs)-> PyAp.Document :
    '''curDoc() -> Document :

    C++ signature :
        class PyApDocument curDoc()'''
    ...
