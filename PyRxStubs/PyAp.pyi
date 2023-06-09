
class AdUiTitleBarLocation:
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
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
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kLeft (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kRight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def applyHostIcon (self, *args, **kwargs)-> None :
      '''applyHostIcon( (int)arg1) -> None :

    C++ signature :
        void applyHostIcon(unsigned __int64)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def docManager (self, *args, **kwargs)-> DocManager :
      '''docManager( (Application)arg1) -> DocManager :

    C++ signature :
        class PyApDocManager docManager(class PyApApplication {lvalue})'''
    ...
    def mainWnd (self, *args, **kwargs)-> int :
      '''mainWnd() -> int :

    C++ signature :
        __int64 mainWnd()'''
    ...
    def setTitleThemeDark (self, *args, **kwargs)-> None :
      '''setTitleThemeDark( (int)arg1) -> None :

    C++ signature :
        void setTitleThemeDark(unsigned __int64)'''
    ...

class AutoDocLock:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
>>> int('0b100', base=0)
:
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
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
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
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def kAutoWrite (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNone (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kRead (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kWrite (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def activateDocument (self, *args, **kwargs)-> ErrorStatus :
      '''activateDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus activateDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue})

activateDocument( (DocManager)arg1, (Document)arg2, (bool)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus activateDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue},bool)'''
    ...
    def appContextCloseDocument (self, *args, **kwargs)-> ErrorStatus :
      '''appContextCloseDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus appContextCloseDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue})'''
    ...
    def appContextNewDocument (self, *args, **kwargs)-> ErrorStatus :
      '''appContextNewDocument( (DocManager)arg1, (str)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus appContextNewDocument(class PyApDocManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def appContextOpenDocument (self, *args, **kwargs)-> ErrorStatus :
      '''appContextOpenDocument( (DocManager)arg1, (str)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus appContextOpenDocument(class PyApDocManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def appContextPromptOpenDocument (self, *args, **kwargs)-> ErrorStatus :
      '''appContextPromptOpenDocument( (DocManager)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus appContextPromptOpenDocument(class PyApDocManager {lvalue})'''
    ...
    def appContextRecoverDocument (self, *args, **kwargs)-> ErrorStatus :
      '''appContextRecoverDocument( (DocManager)arg1, (str)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus appContextRecoverDocument(class PyApDocManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def autoLock (self, *args, **kwargs)-> AutoDocLock :
      '''autoLock() -> AutoDocLock :

    C++ signature :
        class PyAutoDocLock autoLock()'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closeDocument (self, *args, **kwargs)-> ErrorStatus :
      '''closeDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus closeDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue})'''
    ...
    def curDocument (self, *args, **kwargs)-> Document :
      '''curDocument( (DocManager)arg1) -> Document :

    C++ signature :
        class PyApDocument curDocument(class PyApDocManager {lvalue})'''
    ...
    def defaultFormatForSave (self, *args, **kwargs)-> SaveFormat :
      '''defaultFormatForSave( (DocManager)arg1) -> SaveFormat :

    C++ signature :
        enum AcApDocument::SaveFormat defaultFormatForSave(class PyApDocManager {lvalue})'''
    ...
    def disableDocumentActivation (self, *args, **kwargs)-> ErrorStatus :
      '''disableDocumentActivation( (DocManager)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus disableDocumentActivation(class PyApDocManager {lvalue})'''
    ...
    def document (self, *args, **kwargs)-> Document :
      '''document( (DocManager)arg1, (Database)arg2) -> Document :

    C++ signature :
        class PyApDocument document(class PyApDocManager {lvalue},class PyDbDatabase)'''
    ...
    def documentCount (self, *args, **kwargs)-> int :
      '''documentCount( (DocManager)arg1) -> int :

    C++ signature :
        int documentCount(class PyApDocManager {lvalue})'''
    ...
    def enableDocumentActivation (self, *args, **kwargs)-> ErrorStatus :
      '''enableDocumentActivation( (DocManager)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus enableDocumentActivation(class PyApDocManager {lvalue})'''
    ...
    def inputPending (self, *args, **kwargs)-> int :
      '''inputPending( (DocManager)arg1, (Document)arg2) -> int :

    C++ signature :
        int inputPending(class PyApDocManager {lvalue},class PyApDocument {lvalue})'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isApplicationContext (self, *args, **kwargs)-> bool :
      '''isApplicationContext( (DocManager)arg1) -> bool :

    C++ signature :
        bool isApplicationContext(class PyApDocManager {lvalue})'''
    ...
    def isDocumentActivationEnabled (self, *args, **kwargs)-> bool :
      '''isDocumentActivationEnabled( (DocManager)arg1) -> bool :

    C++ signature :
        bool isDocumentActivationEnabled(class PyApDocManager {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def lockDocument (self, *args, **kwargs)-> ErrorStatus :
      '''lockDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus lockDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue})

lockDocument( (DocManager)arg1, (Document)arg2, (DocLockMode)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus lockDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue},enum AcAp::DocLockMode)

lockDocument( (DocManager)arg1, (Document)arg2, (DocLockMode)arg3, (str)arg4, (str)arg5, (bool)arg6) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus lockDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue},enum AcAp::DocLockMode,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
    ...
    def mdiActiveDocument (self, *args, **kwargs)-> Document :
      '''mdiActiveDocument( (DocManager)arg1) -> Document :

    C++ signature :
        class PyApDocument mdiActiveDocument(class PyApDocManager {lvalue})'''
    ...
    def newAcApDocumentIterator (self, *args, **kwargs)-> list :
      '''newAcApDocumentIterator( (DocManager)arg1) -> list :

    C++ signature :
        class boost::python::list newAcApDocumentIterator(class PyApDocManager {lvalue})'''
    ...
    def newDocument (self, *args, **kwargs)-> ErrorStatus :
      '''newDocument( (DocManager)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus newDocument(class PyApDocManager {lvalue})'''
    ...
    def openDocument (self, *args, **kwargs)-> ErrorStatus :
      '''openDocument( (DocManager)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus openDocument(class PyApDocManager {lvalue})'''
    ...
    def popResourceHandle (self, *args, **kwargs)-> None :
      '''popResourceHandle( (DocManager)arg1) -> None :

    C++ signature :
        void popResourceHandle(class PyApDocManager {lvalue})'''
    ...
    def pushAcadResourceHandle (self, *args, **kwargs)-> None :
      '''pushAcadResourceHandle( (DocManager)arg1) -> None :

    C++ signature :
        void pushAcadResourceHandle(class PyApDocManager {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def sendModelessInterrupt (self, *args, **kwargs)-> ErrorStatus :
      '''sendModelessInterrupt( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus sendModelessInterrupt(class PyApDocManager {lvalue},class PyApDocument {lvalue})'''
    ...
    def sendStringToExecute (self, *args, **kwargs)-> ErrorStatus :
      '''sendStringToExecute( (DocManager)arg1, (Document)arg2, (str)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus sendStringToExecute(class PyApDocManager {lvalue},class PyApDocument {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

sendStringToExecute( (DocManager)arg1, (Document)arg2, (str)arg3, (bool)arg4, (bool)arg5, (bool)arg6) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus sendStringToExecute(class PyApDocManager {lvalue},class PyApDocument {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool,bool,bool)'''
    ...
    def setCurDocument (self, *args, **kwargs)-> ErrorStatus :
      '''setCurDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue})

setCurDocument( (DocManager)arg1, (Document)arg2, (DocLockMode)arg3, (bool)arg4) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue},enum AcAp::DocLockMode,bool)'''
    ...
    def setDefaultFormatForSave (self, *args, **kwargs)-> ErrorStatus :
      '''setDefaultFormatForSave( (DocManager)arg1, (SaveFormat)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setDefaultFormatForSave(class PyApDocManager {lvalue},enum AcApDocument::SaveFormat)'''
    ...
    def unlockDocument (self, *args, **kwargs)-> ErrorStatus :
      '''unlockDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus unlockDocument(class PyApDocManager {lvalue},class PyApDocument {lvalue})'''
    ...

class DocManagerReactor:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addReactor (self, *args, **kwargs)-> None :
      '''addReactor( (DocManagerReactor)arg1) -> None :

    C++ signature :
        void addReactor(class PyApDocManagerReactor {lvalue})'''
    ...
    def documentActivated (self, *args, **kwargs)-> None :
      '''documentActivated( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentActivated(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentActivationModified (self, *args, **kwargs)-> None :
      '''documentActivationModified( (DocManagerReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void documentActivationModified(class PyApDocManagerReactor {lvalue},bool)'''
    ...
    def documentBecameCurrent (self, *args, **kwargs)-> None :
      '''documentBecameCurrent( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentBecameCurrent(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentCreateCanceled (self, *args, **kwargs)-> None :
      '''documentCreateCanceled( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentCreateCanceled(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentCreateStarted (self, *args, **kwargs)-> None :
      '''documentCreateStarted( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentCreateStarted(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentCreated (self, *args, **kwargs)-> None :
      '''documentCreated( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentCreated(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentDestroyed (self, *args, **kwargs)-> None :
      '''documentDestroyed( (DocManagerReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void documentDestroyed(class PyApDocManagerReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def documentLockModeChangeVetoed (self, *args, **kwargs)-> None :
      '''documentLockModeChangeVetoed( (DocManagerReactor)arg1, (Document)arg2, (str)arg3) -> None :

    C++ signature :
        void documentLockModeChangeVetoed(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def documentLockModeChanged (self, *args, **kwargs)-> None :
      '''documentLockModeChanged( (DocManagerReactor)arg1, (Document)arg2, (DocLockMode)arg3, (DocLockMode)arg4, (DocLockMode)arg5, (str)arg6) -> None :

    C++ signature :
        void documentLockModeChanged(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue},enum AcAp::DocLockMode,enum AcAp::DocLockMode,enum AcAp::DocLockMode,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def documentLockModeWillChange (self, *args, **kwargs)-> None :
      '''documentLockModeWillChange( (DocManagerReactor)arg1, (Document)arg2, (DocLockMode)arg3, (DocLockMode)arg4, (DocLockMode)arg5, (str)arg6) -> None :

    C++ signature :
        void documentLockModeWillChange(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue},enum AcAp::DocLockMode,enum AcAp::DocLockMode,enum AcAp::DocLockMode,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def documentToBeActivated (self, *args, **kwargs)-> None :
      '''documentToBeActivated( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentToBeActivated(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentToBeDeactivated (self, *args, **kwargs)-> None :
      '''documentToBeDeactivated( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentToBeDeactivated(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def documentToBeDestroyed (self, *args, **kwargs)-> None :
      '''documentToBeDestroyed( (DocManagerReactor)arg1, (Document)arg2) -> None :

    C++ signature :
        void documentToBeDestroyed(class PyApDocManagerReactor {lvalue},class PyApDocument {lvalue})'''
    ...
    def removeReactor (self, *args, **kwargs)-> None :
      '''removeReactor( (DocManagerReactor)arg1) -> None :

    C++ signature :
        void removeReactor(class PyApDocManagerReactor {lvalue})'''
    ...

class Document:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def database (self, *args, **kwargs)-> Database :
      '''database( (Document)arg1) -> Database :

    C++ signature :
        class PyDbDatabase database(class PyApDocument {lvalue})'''
    ...
    def docTitle (self, *args, **kwargs)-> str :
      '''docTitle( (Document)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > docTitle(class PyApDocument {lvalue})'''
    ...
    def docWnd (self, *args, **kwargs)-> int :
      '''docWnd() -> int :

    C++ signature :
        __int64 docWnd()'''
    ...
    def downgradeDocOpen (self, *args, **kwargs)-> ErrorStatus :
      '''downgradeDocOpen( (Document)arg1, (bool)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus downgradeDocOpen(class PyApDocument {lvalue},bool)'''
    ...
    def editor (self, *args, **kwargs)-> Editor :
      '''editor( (Document)arg1) -> Editor :

    C++ signature :
        class PyAcEditor editor(class PyApDocument {lvalue})'''
    ...
    def fileName (self, *args, **kwargs)-> str :
      '''fileName( (Document)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > fileName(class PyApDocument {lvalue})'''
    ...
    def formatForSave (self, *args, **kwargs)-> SaveFormat :
      '''formatForSave( (Document)arg1) -> SaveFormat :

    C++ signature :
        enum AcApDocument::SaveFormat formatForSave(class PyApDocument {lvalue})'''
    ...
    def getCountOfLispList (self, *args, **kwargs)-> int :
      '''getCountOfLispList( (Document)arg1) -> int :

    C++ signature :
        int getCountOfLispList(class PyApDocument {lvalue})'''
    ...
    def getItemOfLispList (self, *args, **kwargs)-> tuple :
      '''getItemOfLispList( (Document)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getItemOfLispList(class PyApDocument {lvalue},int)'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isCommandInputInactive (self, *args, **kwargs)-> bool :
      '''isCommandInputInactive( (Document)arg1) -> bool :

    C++ signature :
        bool isCommandInputInactive(class PyApDocument {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def isQuiescent (self, *args, **kwargs)-> bool :
      '''isQuiescent( (Document)arg1) -> bool :

    C++ signature :
        bool isQuiescent(class PyApDocument {lvalue})'''
    ...
    def lockMode (self, *args, **kwargs)-> DocLockMode :
      '''lockMode( (Document)arg1) -> DocLockMode :

    C++ signature :
        enum AcAp::DocLockMode lockMode(class PyApDocument {lvalue})

lockMode( (Document)arg1, (bool)arg2) -> DocLockMode :

    C++ signature :
        enum AcAp::DocLockMode lockMode(class PyApDocument {lvalue},bool)'''
    ...
    def myLockMode (self, *args, **kwargs)-> DocLockMode :
      '''myLockMode( (Document)arg1) -> DocLockMode :

    C++ signature :
        enum AcAp::DocLockMode myLockMode(class PyApDocument {lvalue})'''
    ...
    def popDbmod (self, *args, **kwargs)-> ErrorStatus :
      '''popDbmod( (Document)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus popDbmod(class PyApDocument {lvalue})'''
    ...
    def pushDbmod (self, *args, **kwargs)-> None :
      '''pushDbmod( (Document)arg1) -> None :

    C++ signature :
        void pushDbmod(class PyApDocument {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def setDocTitle (self, *args, **kwargs)-> None :
      '''setDocTitle( (Document)arg1, (str)arg2) -> None :

    C++ signature :
        void setDocTitle(class PyApDocument {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def transactionManager (self, *args, **kwargs)-> TransactionManager :
      '''transactionManager( (Document)arg1) -> TransactionManager :

    C++ signature :
        class PyTransactionManager transactionManager(class PyApDocument {lvalue})'''
    ...
    def upgradeDocOpen (self, *args, **kwargs)-> ErrorStatus :
      '''upgradeDocOpen( (Document)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus upgradeDocOpen(class PyApDocument {lvalue})'''
    ...

class LayoutManager:
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
    def clearSetupForLayouts (self, *args, **kwargs)-> ErrorStatus :
      '''clearSetupForLayouts( (int)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus clearSetupForLayouts(unsigned __int64)'''
    ...
    def cloneLayout (self, *args, **kwargs)-> ErrorStatus :
      '''cloneLayout( (LayoutManager)arg1, (Layout)arg2, (str)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus cloneLayout(class PyDbLayoutManager {lvalue},class PyDbLayout {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

cloneLayout( (LayoutManager)arg1, (Layout)arg2, (str)arg3, (int)arg4, (Database)arg5) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus cloneLayout(class PyDbLayoutManager {lvalue},class PyDbLayout {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int,class PyDbDatabase {lvalue})'''
    ...
    def copyLayout (self, *args, **kwargs)-> ErrorStatus :
      '''copyLayout( (LayoutManager)arg1, (str)arg2, (str)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus copyLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

copyLayout( (LayoutManager)arg1, (str)arg2, (str)arg3, (Database)arg4) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus copyLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase)'''
    ...
    def countLayouts (self, *args, **kwargs)-> int :
      '''countLayouts( (LayoutManager)arg1) -> int :

    C++ signature :
        int countLayouts(class PyDbLayoutManager {lvalue})

countLayouts( (LayoutManager)arg1, (Database)arg2) -> int :

    C++ signature :
        int countLayouts(class PyDbLayoutManager {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def createLayout (self, *args, **kwargs)-> ErrorStatus :
      '''createLayout( (LayoutManager)arg1, (str)arg2, (ObjectId)arg3, (ObjectId)arg4) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus createLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbObjectId {lvalue},class PyDbObjectId {lvalue})

createLayout( (LayoutManager)arg1, (str)arg2, (ObjectId)arg3, (ObjectId)arg4, (Database)arg5) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus createLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbObjectId {lvalue},class PyDbObjectId {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def createLayoutFromTemplate (self, *args, **kwargs)-> ObjectId :
      '''createLayoutFromTemplate( (LayoutManager)arg1, (str)arg2, (str)arg3, (str)arg4) -> ObjectId :

    C++ signature :
        class PyDbObjectId createLayoutFromTemplate(class PyApLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

createLayoutFromTemplate( (LayoutManager)arg1, (str)arg2, (str)arg3, (str)arg4, (Database)arg5) -> ObjectId :

    C++ signature :
        class PyDbObjectId createLayoutFromTemplate(class PyApLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def createViewports (self, *args, **kwargs)-> bool :
      '''createViewports( (LayoutManager)arg1) -> bool :

    C++ signature :
        bool createViewports(class PyApLayoutManager {lvalue})'''
    ...
    def deleteLayout (self, *args, **kwargs)-> ErrorStatus :
      '''deleteLayout( (LayoutManager)arg1, (str)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus deleteLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

deleteLayout( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus deleteLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def desc (self, *args, **kwargs)-> RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def findLayoutNamed (self, *args, **kwargs)-> ObjectId :
      '''findLayoutNamed( (LayoutManager)arg1, (str)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId findLayoutNamed(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

findLayoutNamed( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> ObjectId :

    C++ signature :
        class PyDbObjectId findLayoutNamed(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase)'''
    ...
    def generateNextNewLayoutName (self, *args, **kwargs)-> str :
      '''generateNextNewLayoutName( (LayoutManager)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > generateNextNewLayoutName(class PyApLayoutManager {lvalue})

generateNextNewLayoutName( (LayoutManager)arg1, (Database)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > generateNextNewLayoutName(class PyApLayoutManager {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def getActiveLayoutBTRId (self, *args, **kwargs)-> ObjectId :
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
    def getActiveTab (self, *args, **kwargs)-> str :
      '''getActiveTab( (LayoutManager)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getActiveTab(class PyApLayoutManager {lvalue})'''
    ...
    def getClipBoundaryElabration (self, *args, **kwargs)-> list :
      '''getClipBoundaryElabration( (LayoutManager)arg1, (ObjectId)arg2) -> list :

    C++ signature :
        class boost::python::list getClipBoundaryElabration(class PyApLayoutManager {lvalue},class PyDbObjectId)'''
    ...
    def getNonRectVPIdFromClipId (self, *args, **kwargs)-> ObjectId :
      '''getNonRectVPIdFromClipId( (LayoutManager)arg1, (ObjectId)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId getNonRectVPIdFromClipId(class PyDbLayoutManager {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def isVpnumClipped (self, *args, **kwargs)-> bool :
      '''isVpnumClipped( (LayoutManager)arg1, (int)arg2) -> bool :

    C++ signature :
        bool isVpnumClipped(class PyDbLayoutManager {lvalue},int)

isVpnumClipped( (LayoutManager)arg1, (int)arg2, (Database)arg3) -> bool :

    C++ signature :
        bool isVpnumClipped(class PyDbLayoutManager {lvalue},int,class PyDbDatabase)'''
    ...
    def layoutExists (self, *args, **kwargs)-> bool :
      '''layoutExists( (LayoutManager)arg1, (str)arg2) -> bool :

    C++ signature :
        bool layoutExists(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

layoutExists( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> bool :

    C++ signature :
        bool layoutExists(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase)'''
    ...
    def pageSetup (self, *args, **kwargs)-> int :
      '''pageSetup( (LayoutManager)arg1) -> int :

    C++ signature :
        int pageSetup(class PyApLayoutManager {lvalue})

pageSetup( (LayoutManager)arg1, (ObjectId)arg2) -> int :

    C++ signature :
        int pageSetup(class PyApLayoutManager {lvalue},class PyDbObjectId)

pageSetup( (LayoutManager)arg1, (ObjectId)arg2, (int)arg3, (bool)arg4) -> int :

    C++ signature :
        int pageSetup(class PyApLayoutManager {lvalue},class PyDbObjectId,unsigned __int64,bool)'''
    ...
    def pointInViewports (self, *args, **kwargs)-> list :
      '''pointInViewports( (LayoutManager)arg1, (Point3d)arg2) -> list :

    C++ signature :
        class boost::python::list pointInViewports(class PyApLayoutManager {lvalue},class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def renameLayout (self, *args, **kwargs)-> ErrorStatus :
      '''renameLayout( (LayoutManager)arg1, (str)arg2, (str)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus renameLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

renameLayout( (LayoutManager)arg1, (str)arg2, (str)arg3, (Database)arg4) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus renameLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def setCaptureOnLayoutSwitch (self, *args, **kwargs)-> None :
      '''setCaptureOnLayoutSwitch( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setCaptureOnLayoutSwitch(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setCreateViewports (self, *args, **kwargs)-> None :
      '''setCreateViewports( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setCreateViewports(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setCurrentLayout (self, *args, **kwargs)-> ErrorStatus :
      '''setCurrentLayout( (LayoutManager)arg1, (str)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurrentLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

setCurrentLayout( (LayoutManager)arg1, (str)arg2, (Database)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurrentLayout(class PyDbLayoutManager {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def setCurrentLayoutId (self, *args, **kwargs)-> ErrorStatus :
      '''setCurrentLayoutId( (LayoutManager)arg1, (ObjectId)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setCurrentLayoutId(class PyDbLayoutManager {lvalue},class PyDbObjectId)'''
    ...
    def setDefaultPlotConfig (self, *args, **kwargs)-> None :
      '''setDefaultPlotConfig( (LayoutManager)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setDefaultPlotConfig(class PyApLayoutManager {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def setShowPageSetup (self, *args, **kwargs)-> None :
      '''setShowPageSetup( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setShowPageSetup(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setShowPaperBackground (self, *args, **kwargs)-> None :
      '''setShowPaperBackground( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setShowPaperBackground(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setShowPaperMargins (self, *args, **kwargs)-> None :
      '''setShowPaperMargins( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setShowPaperMargins(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setShowPrintBorder (self, *args, **kwargs)-> None :
      '''setShowPrintBorder( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setShowPrintBorder(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setShowTabs (self, *args, **kwargs)-> None :
      '''setShowTabs( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void setShowTabs(class PyApLayoutManager {lvalue},bool)'''
    ...
    def setupForLayouts (self, *args, **kwargs)-> int :
      '''setupForLayouts( (Database)arg1) -> int :

    C++ signature :
        unsigned __int64 setupForLayouts(class PyDbDatabase {lvalue})'''
    ...
    def showPageSetup (self, *args, **kwargs)-> bool :
      '''showPageSetup( (LayoutManager)arg1) -> bool :

    C++ signature :
        bool showPageSetup(class PyApLayoutManager {lvalue})'''
    ...
    def showPaperBackground (self, *args, **kwargs)-> bool :
      '''showPaperBackground( (LayoutManager)arg1) -> bool :

    C++ signature :
        bool showPaperBackground(class PyApLayoutManager {lvalue})'''
    ...
    def showPaperMargins (self, *args, **kwargs)-> bool :
      '''showPaperMargins( (LayoutManager)arg1) -> bool :

    C++ signature :
        bool showPaperMargins(class PyApLayoutManager {lvalue})'''
    ...
    def showPrintBorder (self, *args, **kwargs)-> bool :
      '''showPrintBorder( (LayoutManager)arg1) -> bool :

    C++ signature :
        bool showPrintBorder(class PyApLayoutManager {lvalue})'''
    ...
    def showTabs (self, *args, **kwargs)-> bool :
      '''showTabs( (LayoutManager)arg1) -> bool :

    C++ signature :
        bool showTabs(class PyApLayoutManager {lvalue})'''
    ...
    def updateCurrentPaper (self, *args, **kwargs)-> None :
      '''updateCurrentPaper( (LayoutManager)arg1) -> None :

    C++ signature :
        void updateCurrentPaper(class PyApLayoutManager {lvalue})

updateCurrentPaper( (LayoutManager)arg1, (bool)arg2) -> None :

    C++ signature :
        void updateCurrentPaper(class PyApLayoutManager {lvalue},bool)'''
    ...
    def updateLayoutTabs (self, *args, **kwargs)-> None :
      '''updateLayoutTabs( (LayoutManager)arg1) -> None :

    C++ signature :
        void updateLayoutTabs(class PyApLayoutManager {lvalue})'''
    ...

class PaletteSet:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (str)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

__init__( (object)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def add (self, *args, **kwargs)-> int :
      '''add( (PaletteSet)arg1, (str)arg2, (object)arg3) -> int :

    C++ signature :
        int add(class PyCAdUiPaletteSet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class boost::python::api::object {lvalue})'''
    ...
    def autoRollupStyle (self, *args, **kwargs)-> bool :
      '''autoRollupStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool autoRollupStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def closeButtonStyle (self, *args, **kwargs)-> bool :
      '''closeButtonStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool closeButtonStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def editNameStyle (self, *args, **kwargs)-> bool :
      '''editNameStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool editNameStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getActivePaletteTabIndex (self, *args, **kwargs)-> int :
      '''getActivePaletteTabIndex( (PaletteSet)arg1) -> int :

    C++ signature :
        int getActivePaletteTabIndex(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getAutoRollup (self, *args, **kwargs)-> bool :
      '''getAutoRollup( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool getAutoRollup(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getFullRect (self, *args, **kwargs)-> object :
      '''getFullRect( (PaletteSet)arg1) -> object :

    C++ signature :
        struct _object * __ptr64 getFullRect(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getName (self, *args, **kwargs)-> str :
      '''getName( (PaletteSet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getName(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getOpacity (self, *args, **kwargs)-> int :
      '''getOpacity( (PaletteSet)arg1) -> int :

    C++ signature :
        int getOpacity(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getPaletteCount (self, *args, **kwargs)-> int :
      '''getPaletteCount( (PaletteSet)arg1) -> int :

    C++ signature :
        int getPaletteCount(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getPaletteSetStyle (self, *args, **kwargs)-> int :
      '''getPaletteSetStyle( (PaletteSet)arg1) -> int :

    C++ signature :
        unsigned long getPaletteSetStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def getRolloverOpacity (self, *args, **kwargs)-> int :
      '''getRolloverOpacity( (PaletteSet)arg1) -> int :

    C++ signature :
        int getRolloverOpacity(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def paletteBackgroundColor (self, *args, **kwargs)-> int :
      '''paletteBackgroundColor( (PaletteSet)arg1) -> int :

    C++ signature :
        unsigned long paletteBackgroundColor(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def paletteTabTextColor (self, *args, **kwargs)-> int :
      '''paletteTabTextColor( (PaletteSet)arg1) -> int :

    C++ signature :
        unsigned long paletteTabTextColor(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def propertiesMenuStyle (self, *args, **kwargs)-> bool :
      '''propertiesMenuStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool propertiesMenuStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def removePalette (self, *args, **kwargs)-> bool :
      '''removePalette( (PaletteSet)arg1, (int)arg2) -> bool :

    C++ signature :
        bool removePalette(class PyCAdUiPaletteSet {lvalue},int)'''
    ...
    def rollOut (self, *args, **kwargs)-> None :
      '''rollOut( (PaletteSet)arg1) -> None :

    C++ signature :
        void rollOut(class PyCAdUiPaletteSet {lvalue})

rollOut( (PaletteSet)arg1, (bool)arg2) -> None :

    C++ signature :
        void rollOut(class PyCAdUiPaletteSet {lvalue},bool)'''
    ...
    def rollUp (self, *args, **kwargs)-> None :
      '''rollUp( (PaletteSet)arg1) -> None :

    C++ signature :
        void rollUp(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def rolledUp (self, *args, **kwargs)-> bool :
      '''rolledUp( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool rolledUp(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def setActivePalette (self, *args, **kwargs)-> bool :
      '''setActivePalette( (PaletteSet)arg1, (int)arg2) -> bool :

    C++ signature :
        bool setActivePalette(class PyCAdUiPaletteSet {lvalue},int)'''
    ...
    def setAutoRollup (self, *args, **kwargs)-> bool :
      '''setAutoRollup( (PaletteSet)arg1, (bool)arg2) -> bool :

    C++ signature :
        bool setAutoRollup(class PyCAdUiPaletteSet {lvalue},bool)'''
    ...
    def setName (self, *args, **kwargs)-> bool :
      '''setName( (PaletteSet)arg1, (str)arg2) -> bool :

    C++ signature :
        bool setName(class PyCAdUiPaletteSet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setOpacity (self, *args, **kwargs)-> bool :
      '''setOpacity( (PaletteSet)arg1, (int)arg2) -> bool :

    C++ signature :
        bool setOpacity(class PyCAdUiPaletteSet {lvalue},int)'''
    ...
    def setPaletteSetStyle (self, *args, **kwargs)-> None :
      '''setPaletteSetStyle( (PaletteSet)arg1, (int)arg2) -> None :

    C++ signature :
        void setPaletteSetStyle(class PyCAdUiPaletteSet {lvalue},unsigned long)'''
    ...
    def setRolloverOpacity (self, *args, **kwargs)-> bool :
      '''setRolloverOpacity( (PaletteSet)arg1, (int)arg2) -> bool :

    C++ signature :
        bool setRolloverOpacity(class PyCAdUiPaletteSet {lvalue},int)'''
    ...
    def setTitleBarLocation (self, *args, **kwargs)-> None :
      '''setTitleBarLocation( (PaletteSet)arg1, (AdUiTitleBarLocation)arg2) -> None :

    C++ signature :
        void setTitleBarLocation(class PyCAdUiPaletteSet {lvalue},enum CAdUiPaletteSet::AdUiTitleBarLocation)'''
    ...
    def setVisible (self, *args, **kwargs)-> None :
      '''setVisible( (PaletteSet)arg1, (bool)arg2) -> None :

    C++ signature :
        void setVisible(class PyCAdUiPaletteSet {lvalue},bool)'''
    ...
    def showIconStyle (self, *args, **kwargs)-> bool :
      '''showIconStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool showIconStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def showRollupButtonStyle (self, *args, **kwargs)-> bool :
      '''showRollupButtonStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool showRollupButtonStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def singlePaletteTabStyle (self, *args, **kwargs)-> bool :
      '''singlePaletteTabStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool singlePaletteTabStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def snapStyle (self, *args, **kwargs)-> bool :
      '''snapStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool snapStyle(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def titleBarLocation (self, *args, **kwargs)-> AdUiTitleBarLocation :
      '''titleBarLocation( (PaletteSet)arg1) -> AdUiTitleBarLocation :

    C++ signature :
        enum CAdUiPaletteSet::AdUiTitleBarLocation titleBarLocation(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def updateTabs (self, *args, **kwargs)-> None :
      '''updateTabs( (PaletteSet)arg1) -> None :

    C++ signature :
        void updateTabs(class PyCAdUiPaletteSet {lvalue})'''
    ...
    def useSinglePaletteTabNameStyle (self, *args, **kwargs)-> bool :
      '''useSinglePaletteTabNameStyle( (PaletteSet)arg1) -> bool :

    C++ signature :
        bool useSinglePaletteTabNameStyle(class PyCAdUiPaletteSet {lvalue})'''
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
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None:
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None:
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
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
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs)-> None:
      '''the imaginary part of a complex number'''
    ...
    def k2000_Standard (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNative (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def numerator (self, *args, **kwargs)-> None:
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None:
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
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
    def abortTransaction (self: TransactionManager)-> ErrorStatus :
      '''                             '''
    ...
    def addNewlyCreatedDBRObject (self: TransactionManager,obj: DbObject,add: bool=True)-> ErrorStatus :
      '''                             '''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs)-> RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def enableGraphicsFlush (self, *args, **kwargs)-> ErrorStatus :
      '''enableGraphicsFlush( (TransactionManager)arg1, (bool)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus enableGraphicsFlush(class PyTransactionManager {lvalue},bool)'''
    ...
    def endTransaction (self: TransactionManager)-> ErrorStatus :
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
    def getObject (self: TransactionManager,id: ObjectId,mode: OpenMode=OpenMode.kForRead,openErasedObject: bool=False)-> DbObject :
      '''                             '''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def numActiveTransactions (self: TransactionManager)-> int :
      '''                             '''
    ...
    def numOpenedObjects (self: TransactionManager)-> int :
      '''                             '''
    ...
    def queueForGraphicsFlush (self: TransactionManager)-> ErrorStatus :
      '''                             '''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def startTransaction (self: TransactionManager)-> Transaction :
      '''                             '''
    ...
    def topTransaction (self: TransactionManager)-> Transaction :
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
errors defaults to 'strict':
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
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def create_module (spec):
      '''Create a built-in module'''
    ...
    def exec_module (module):
      '''Exec a built-in module'''
    ...
    def find_module (fullname, path=None):
      '''Find the built-in module.

        If 'path' is ever specified then the search is considered a failure.

        This method is deprecated.  Use find_spec() instead.

        '''
    ...
    def find_spec (fullname, path=None, target=None):
      '''None'''
    ...
    def get_code (fullname):
      '''Return None as built-in modules do not have code objects.'''
    ...
    def get_source (fullname):
      '''Return None as built-in modules do not have source code.'''
    ...
    def is_package (fullname):
      '''Return False as built-in modules are never packages.'''
    ...
    def load_module (fullname):
      '''Load the specified module into sys.modules and return it.

    This method is deprecated.  Use loader.exec_module() instead.

    '''
    ...
    def module_repr (module):
      '''Return repr for the module.

        The method is deprecated.  The import machinery does the job itself.

        '''
    ...

function curDoc:
    def curDoc (*args, **kwargs)-> Document :
      '''curDoc() -> Document :

    C++ signature :
        class PyApDocument curDoc()'''
    ...
