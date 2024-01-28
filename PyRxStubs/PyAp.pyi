import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl

class AdUiTitleBarLocation:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
      '''Return a pair of integers, whose ratio is equal to the original int.

The ratio is in lowest terms and has a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder='big', *, signed=False) :
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.  Default is to use 'big'.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length=1, byteorder='big', *, signed=False) :
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.  Default
    is length 1.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.  Default is to use 'big'.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class Application:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def acadGetIDispatch ()-> int :
      '''                             '''
    ...
    def applyHostIcon (wnd : int)-> None :
      '''                             '''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def docManager ()-> PyAp.DocManager :
      '''                             '''
    ...
    def hostAPI ()-> str :
      '''                             '''
    ...
    def hostAPIVER ()-> str :
      '''                             '''
    ...
    def mainWnd ()-> int :
      '''                             '''
    ...
    def setTitleThemeDark (wnd : int)-> None :
      '''                             '''
    ...
    def wxApp ()-> object :
      '''                             '''
    ...

class AutoDocLock:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def className ()-> str :
      '''                             '''
    ...

class CmdFlags:
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

class DocLockMode:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
      '''Return a pair of integers, whose ratio is equal to the original int.

The ratio is in lowest terms and has a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder='big', *, signed=False) :
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.  Default is to use 'big'.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length=1, byteorder='big', *, signed=False) :
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.  Default
    is length 1.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.  Default is to use 'big'.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class DocManager:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def activateDocument (self: DocManager,doc: PyAp.Document,bPassScript: bool = False)-> None :
      '''                             '''
    ...
    def appContextCloseDocument (self: DocManager,doc: PyAp.Document)-> None :
      '''                             '''
    ...
    def appContextNewDocument (self: DocManager,templateName : str)-> None :
      '''                             '''
    ...
    def appContextOpenDocument (self: DocManager,dwgName : str)-> None :
      '''                             '''
    ...
    def appContextPromptOpenDocument (self: DocManager)-> None :
      '''                             '''
    ...
    def appContextRecoverDocument (self: DocManager,dwgName : str)-> None :
      '''                             '''
    ...
    def autoLock ()-> PyAp.AutoDocLock :
      '''                             '''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def closeDocument (self: DocManager,doc: PyAp.Document)-> None :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other:PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def curDocument (self: DocManager)-> PyAp.Document :
      '''                             '''
    ...
    def defaultFormatForSave (self: DocManager)-> PyAp.SaveFormat :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def disableDocumentActivation (self: DocManager)-> None :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def document (self: DocManager,db: PyDb.Database)-> PyAp.Document :
      '''                             '''
    ...
    def documentCount (self: DocManager)-> int :
      '''                             '''
    ...
    def documents (self: DocManager)-> list :
      '''                             '''
    ...
    def enableDocumentActivation (self: DocManager)-> None :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def inputPending (self: DocManager,doc: PyAp.Document)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isApplicationContext (self: DocManager)-> bool :
      '''                             '''
    ...
    def isDocumentActivationEnabled (self: DocManager)-> bool :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def lockDocument (self: DocManager,doc: PyAp.Document,mode: PyAp.DocLockMode = kWrite,gcmd: str = None,lcmd: str = None,prmt: bool = True)-> None :
      '''                             '''
    ...
    def mdiActiveDocument (self: DocManager)-> PyAp.Document :
      '''                             '''
    ...
    def newDocument (self: DocManager)-> None :
      '''                             '''
    ...
    def openDocument (self: DocManager)-> None :
      '''                             '''
    ...
    def popResourceHandle (self: DocManager)-> None :
      '''                             '''
    ...
    def pushAcadResourceHandle (self: DocManager)-> None :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def sendModelessInterrupt (self: DocManager,doc: PyAp.Document)-> None :
      '''                             '''
    ...
    def sendStringToExecute (self: DocManager,doc: PyAp.Document,script: str,bActivate: bool = True,bWrapUpInactiveDoc: bool = False,bEchoString: bool = True)-> None :
      '''                             '''
    ...
    def setCurDocument (self: DocManager,doc: PyAp.Document,mode: PyAp.DocLockMode = kNone,activate: bool = False)-> None :
      '''                             '''
    ...
    def setDefaultFormatForSave (self: DocManager,fmt : PyAp.SaveFormat)-> None :
      '''                             '''
    ...
    def unlockDocument (self: DocManager,doc: PyAp.Document)-> None :
      '''                             '''
    ...

class DocManagerReactor:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addReactor (self: DocManagerReactor)-> None :
      '''                             '''
    ...
    def documentActivated (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentActivationModified (self: DocManagerReactor,val : bool)-> None :
      '''                             '''
    ...
    def documentBecameCurrent (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentCreateCanceled (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentCreateStarted (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentCreated (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentDestroyed (self: DocManagerReactor,val : str)-> None :
      '''                             '''
    ...
    def documentLockModeChangeVetoed (self: DocManagerReactor,doc : Document,globalCmdName : str)-> None :
      '''                             '''
    ...
    def documentLockModeChanged (self: DocManagerReactor,doc : Document,myPrevMode : DocLockMode,myCurMode : DocLockMode,currentMode : DocLockMode,globalCmdName : str)-> None :
      '''                             '''
    ...
    def documentLockModeWillChange (self: DocManagerReactor,myCurMode : DocLockMode,myNewMode : DocLockMode,curMode : DocLockMode,globalCmdName : str)-> None :
      '''                             '''
    ...
    def documentToBeActivated (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentToBeDeactivated (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def documentToBeDestroyed (self: DocManagerReactor,val : Document)-> None :
      '''                             '''
    ...
    def removeReactor (self: DocManagerReactor)-> None :
      '''                             '''
    ...

class Document:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other:PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def database (self: Document)-> PyDb.Database :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def docTitle (self: Document)-> str :
      '''                             '''
    ...
    def docWnd ()-> int :
      '''                             '''
    ...
    def downgradeDocOpen (self: Document,promptForSave : bool)-> None :
      '''                             '''
    ...
    def editor (self: Document)-> PyEd.Editor :
      '''                             '''
    ...
    def fileName (self: Document)-> str :
      '''                             '''
    ...
    def formatForSave (self: Document)-> PyAp.SaveFormat :
      '''                             '''
    ...
    def getCountOfLispList (self: Document)-> int :
      '''                             '''
    ...
    def getItemOfLispList (self: Document,index : int)-> tuple :
      '''                             '''
    ...
    def getUserData (self: Document)-> object :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def inputPointManager (self: Document)-> PyEd.InputPointManager :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isCommandInputInactive (self: Document)-> bool :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isQuiescent (self: Document)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def lockMode (self: Document,bIncludeMyLocks : bool=False)-> PyAp.DocLockMode :
      '''                             '''
    ...
    def myLockMode (self: Document)-> PyAp.DocLockMode :
      '''                             '''
    ...
    def popDbmod (self: Document)-> None :
      '''                             '''
    ...
    def pushDbmod (self: Document)-> None :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDocTitle (self: Document,title : str)-> None :
      '''                             '''
    ...
    def setUserData (self: Document,data : any)-> None :
      '''                             '''
    ...
    def transactionManager (self: Document)-> PyAp.TransactionManager :
      '''                             '''
    ...
    def upgradeDocOpen (self: Document)-> None :
      '''                             '''
    ...

class LayerFilter:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addNested (self: LayerFilter,val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def allowDelete (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def allowNested (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def allowRename (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def compareTo (self: LayerFilter,other : PyLy.LayerFilter)-> bool :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other:PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def dynamicallyGenerated (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def filter (self: LayerFilter,val : PyDb.LayerTableRecord)-> bool :
      '''                             '''
    ...
    def filterExpression (self: LayerFilter)-> str :
      '''                             '''
    ...
    def generateNested (self: LayerFilter)-> None :
      '''                             '''
    ...
    def getNestedFilters (self: LayerFilter)-> list :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isIdFilter (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isProxy (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def name (self: LayerFilter)-> str :
      '''                             '''
    ...
    def parent (self: LayerFilter)-> PyAp.LayerFilter :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def removeNested (self: LayerFilter,val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def setFilterExpression (self: LayerFilter,val : str)-> None :
      '''                             '''
    ...
    def setName (self: LayerFilter,val : str)-> None :
      '''                             '''
    ...
    def showEditor (self: LayerFilter)-> int :
      '''                             '''
    ...

class LayerFilterManager:
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

class LayerGroup:
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
    def addNested (self: LayerFilter,val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def allowDelete (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def allowNested (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def allowRename (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def compareTo (self: LayerFilter,other : PyLy.LayerFilter)-> bool :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other:PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def dynamicallyGenerated (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def filter (self: LayerFilter,val : PyDb.LayerTableRecord)-> bool :
      '''                             '''
    ...
    def filterExpression (self: LayerFilter)-> str :
      '''                             '''
    ...
    def generateNested (self: LayerFilter)-> None :
      '''                             '''
    ...
    def getNestedFilters (self: LayerFilter)-> list :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isIdFilter (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isProxy (self: LayerFilter)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def layerIds (self, *args, **kwargs)-> list :
      '''layerIds( (LayerGroup)arg1) -> list :

    C++ signature :
        class boost::python::list layerIds(class PyLyLayerGroup {lvalue})'''
    ...
    def name (self: LayerFilter)-> str :
      '''                             '''
    ...
    def parent (self: LayerFilter)-> PyAp.LayerFilter :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def removeLayerId (self, *args, **kwargs)-> None :
      '''removeLayerId( (LayerGroup)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void removeLayerId(class PyLyLayerGroup {lvalue},class PyDbObjectId)'''
    ...
    def removeNested (self: LayerFilter,val : PyLy.LayerFilter)-> None :
      '''                             '''
    ...
    def setFilterExpression (self: LayerFilter,val : str)-> None :
      '''                             '''
    ...
    def setName (self: LayerFilter,val : str)-> None :
      '''                             '''
    ...
    def showEditor (self: LayerFilter)-> int :
      '''                             '''
    ...

class LayoutManager:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
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
    def comparedTo (self: RxObject,other:PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
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
    def createLayoutFromTemplate (self: LayoutManager,newLayoutName : str,templatePath : str,layoutName : str,db : PyDb.Database=current)-> PyDb.ObjectId :
      '''                             '''
    ...
    def createViewports (self: LayoutManager)-> bool :
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
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
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
    def generateNextNewLayoutName (self: LayoutManager,val : PyDb.Database=current)-> str :
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
    def getActiveTab (self: LayoutManager)-> str :
      '''                             '''
    ...
    def getClipBoundaryElabration (self: LayoutManager,val : PyDb.ObjectId)-> list :
      '''                             '''
    ...
    def getNonRectVPIdFromClipId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''getNonRectVPIdFromClipId( (LayoutManager)arg1, (ObjectId)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId getNonRectVPIdFromClipId(class PyDbLayoutManager {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
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
    def keepAlive (self: RxObject,flag:bool)-> None :
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
    def pageSetup (self: LayoutManager,layoutBTRId : PyDb.ObjectId=kNull,parent : int=kNull,isPageSetupDlg : bool=True)-> int :
      '''                             '''
    ...
    def pointInViewports (self: LayoutManager,val : PyGe.Point3d)-> list :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def renameLayout (self, *args, **kwargs)-> None :
      '''renameLayout( (LayoutManager)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void renameLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

renameLayout( (LayoutManager)arg1, (str)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void renameLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def setCaptureOnLayoutSwitch (self: LayoutManager,val : bool)-> None :
      '''                             '''
    ...
    def setCreateViewports (self: LayoutManager,val : bool)-> None :
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
    def setDefaultPlotConfig (self: LayoutManager,val : PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setShowPageSetup (self: LayoutManager,val : bool)-> None :
      '''                             '''
    ...
    def setShowPaperBackground (self: LayoutManager,val : bool)-> None :
      '''                             '''
    ...
    def setShowPaperMargins (self: LayoutManager,val : bool)-> None :
      '''                             '''
    ...
    def setShowPrintBorder (self: LayoutManager,val : bool)-> None :
      '''                             '''
    ...
    def setShowTabs (self: LayoutManager,val : bool)-> None :
      '''                             '''
    ...
    def setupForLayouts (self, *args, **kwargs)-> int :
      '''setupForLayouts( (Database)arg1) -> int :

    C++ signature :
        unsigned __int64 setupForLayouts(class PyDbDatabase {lvalue})'''
    ...
    def showPageSetup (self: LayoutManager)-> bool :
      '''                             '''
    ...
    def showPaperBackground (self: LayoutManager)-> bool :
      '''                             '''
    ...
    def showPaperMargins (self: LayoutManager)-> bool :
      '''                             '''
    ...
    def showPrintBorder (self: LayoutManager)-> bool :
      '''                             '''
    ...
    def showTabs (self: LayoutManager)-> bool :
      '''                             '''
    ...
    def updateCurrentPaper (self: LayoutManager,zoomToPaper : bool=False)-> None :
      '''                             '''
    ...
    def updateLayoutTabs (self: LayoutManager)-> None :
      '''                             '''
    ...

class PaletteSet:
    def __init__ (self: PaletteSet,name : str,guid : str=None)-> None :
      '''                             '''
    ...
    def add (self: PaletteSet,name : str)-> int :
      '''                             '''
    ...
    def autoRollupStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def closeButtonStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def editNameStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def getActivePaletteTabIndex (self: PaletteSet)-> int :
      '''                             '''
    ...
    def getAutoRollup (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def getFullRect (self: PaletteSet)-> object :
      '''                             '''
    ...
    def getName (self: PaletteSet)-> str :
      '''                             '''
    ...
    def getOpacity (self: PaletteSet)-> int :
      '''                             '''
    ...
    def getPaletteCount (self: PaletteSet)-> int :
      '''                             '''
    ...
    def getPaletteSetStyle (self: PaletteSet)-> int :
      '''                             '''
    ...
    def getRolloverOpacity (self: PaletteSet)-> int :
      '''                             '''
    ...
    def paletteBackgroundColor (self: PaletteSet)-> int :
      '''                             '''
    ...
    def paletteTabTextColor (self: PaletteSet)-> int :
      '''                             '''
    ...
    def propertiesMenuStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def removePalette (self: PaletteSet,val : int)-> bool :
      '''                             '''
    ...
    def rollOut (self: PaletteSet,delay : bool=False)-> None :
      '''                             '''
    ...
    def rollUp (self: PaletteSet)-> None :
      '''                             '''
    ...
    def rolledUp (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def setActivePalette (self: PaletteSet,val : int)-> bool :
      '''                             '''
    ...
    def setAutoRollup (self: PaletteSet,val : bool)-> bool :
      '''                             '''
    ...
    def setName (self: PaletteSet,name : str)-> bool :
      '''                             '''
    ...
    def setOpacity (self: PaletteSet,val : int)-> bool :
      '''                             '''
    ...
    def setPaletteSetStyle (self: PaletteSet,val : int)-> None :
      '''                             '''
    ...
    def setRolloverOpacity (self: PaletteSet,val : int)-> bool :
      '''                             '''
    ...
    def setTitleBarLocation (self: PaletteSet,val : AdUiTitleBarLocation)-> None :
      '''                             '''
    ...
    def setToolId (self: PaletteSet,guid : str)-> bool :
      '''                             '''
    ...
    def setVisible (self: PaletteSet,val : bool)-> None :
      '''                             '''
    ...
    def showIconStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def showRollupButtonStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def singlePaletteTabStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def snapStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...
    def titleBarLocation (self: PaletteSet)-> PyAp.AdUiTitleBarLocation :
      '''                             '''
    ...
    def updateTabs (self: PaletteSet)-> None :
      '''                             '''
    ...
    def useSinglePaletteTabNameStyle (self: PaletteSet)-> bool :
      '''                             '''
    ...

class ResourceOverride:
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

class SaveFormat:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
      '''Return a pair of integers, whose ratio is equal to the original int.

The ratio is in lowest terms and has a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder='big', *, signed=False) :
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.  Default is to use 'big'.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length=1, byteorder='big', *, signed=False) :
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.  Default
    is length 1.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.  Default is to use 'big'.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class TransactionManager:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def abortTransaction (self: TransactionManager)-> None :
      '''                             '''
    ...
    def addNewlyCreatedDBRObject (self: TransactionManager,obj: DbObject,add: bool=True)-> None :
      '''                             '''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def comparedTo (self: RxObject,other:PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc (self, *args, **kwargs)-> PyRx.RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def enableGraphicsFlush (self, *args, **kwargs)-> None :
      '''enableGraphicsFlush( (TransactionManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void enableGraphicsFlush(class PyTransactionManager {lvalue},bool)'''
    ...
    def endTransaction (self: TransactionManager)-> None :
      '''                             '''
    ...
    def flushGraphics (self, *args, **kwargs)-> None :
      '''flushGraphics( (TransactionManager)arg1) -> None :

    C++ signature :
        void flushGraphics(class PyTransactionManager {lvalue})'''
    ...
    def getAllObjects (self: TransactionManager)-> list :
      '''                             '''
    ...
    def getObject (self: TransactionManager,id: ObjectId,mode: OpenMode=OpenMode.kForRead,openErasedObject: bool=False)-> PyDb.DbObject :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def numActiveTransactions (self: TransactionManager)-> int :
      '''                             '''
    ...
    def numOpenedObjects (self: TransactionManager)-> int :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def queueForGraphicsFlush (self: TransactionManager)-> None :
      '''                             '''
    ...
    def startTransaction (self: TransactionManager)-> PyDb.Transaction :
      '''                             '''
    ...
    def topTransaction (self: TransactionManager)-> PyDb.Transaction :
      '''                             '''
    ...

class __loader__:
    def _ORIGIN (self, *args, **kwargs)-> str
str(bytes_or_buffer[, encoding[, errors]]) -> str

Create a new string object from the given object. If encoding or
errors is specified, then the object must expose a data buffer
that will be decoded using the given encoding and error handler.
Otherwise, returns the result of object.__str__() (if defined)
or repr(object).
encoding defaults to sys.getdefaultencoding().
errors defaults to 'strict' :
      '''str(object='') -> str
str(bytes_or_buffer[, encoding[, errors]]) -> str

Create a new string object from the given object. If encoding or
errors is specified, then the object must expose a data buffer
that will be decoded using the given encoding and error handler.
Otherwise, returns the result of object.__str__() (if defined)
or repr(object).
encoding defaults to sys.getdefaultencoding().
errors defaults to 'strict'.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def create_module (spec) :
      '''Create a built-in module'''
    ...
    def exec_module (module) :
      '''Exec a built-in module'''
    ...
    def find_spec (fullname, path=None, target=None) :
      '''None'''
    ...
    def get_code (fullname) :
      '''Return None as built-in modules do not have code objects.'''
    ...
    def get_source (fullname) :
      '''Return None as built-in modules do not have source code.'''
    ...
    def is_package (fullname) :
      '''Return False as built-in modules are never packages.'''
    ...
    def load_module (fullname) :
      '''Load the specified module into sys.modules and return it.

    This method is deprecated.  Use loader.exec_module() instead.

    '''
    ...

function curDoc:
    def curDoc (*args, **kwargs)-> PyAp.Document :
      '''curDoc() -> Document :

    C++ signature :
        class PyApDocument curDoc()'''
    ...
