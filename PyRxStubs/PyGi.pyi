import PyRx
import PyGe
import PyGi
import PyDb
import PyAp
import PyEd

class AcGiArcType:
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
    def kAcGiArcChord (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiArcSector (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiArcSimple (self, *args, **kwargs)-> None:
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

class AcGiFillType:
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
    def kAcGiFillAlways (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiFillNever (self, *args, **kwargs)-> None:
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

class AcGiOrientationTransformBehavior:
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
    def kAcGiScreenOrientation (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiWorldOrientation (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiZAxisOrientation (self, *args, **kwargs)-> None:
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

class AcGiOrientationType:
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
    def kAcGiClockwise (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiCounterClockwise (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiNoOrientation (self, *args, **kwargs)-> None:
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

class AcGiPositionTransformBehavior:
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
    def kAcGiScreenLocalOriginPosition (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiScreenPosition (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiViewportPosition (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiWorldPosition (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiWorldWithScreenOffsetPosition (self, *args, **kwargs)-> None:
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

class AcGiRegenType:
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
    def eAcGiRegenTypeInvalid (self, *args, **kwargs)-> None:
      '''None'''
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
    def kAcGiForExplode (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiHideOrShadeCommand (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiSaveWorldDrawForProxy (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiShadedDisplay (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiStandardDisplay (self, *args, **kwargs)-> None:
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

class AcGiScaleTransformBehavior:
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
    def kAcGiScreenLocalOriginScale (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiScreenScale (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiViewportLocalOriginScale (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiViewportScale (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiWorldScale (self, *args, **kwargs)-> None:
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

class AcGiVisibility:
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
    def kAcGiInvisible (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiSilhouette (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kAcGiVisible (self, *args, **kwargs)-> None:
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

class CommonDraw:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
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
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isDragging (self, *args, **kwargs)-> bool :
      '''isDragging( (CommonDraw)arg1) -> bool :

    C++ signature :
        bool isDragging(class PyGiCommonDraw {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def regenAbort (self, *args, **kwargs)-> bool :
      '''regenAbort( (CommonDraw)arg1) -> bool :

    C++ signature :
        bool regenAbort(class PyGiCommonDraw {lvalue})'''
    ...
    def regenType (self, *args, **kwargs)-> AcGiRegenType :
      '''regenType( (CommonDraw)arg1) -> AcGiRegenType :

    C++ signature :
        enum AcGiRegenType regenType(class PyGiCommonDraw {lvalue})'''
    ...
    def subEntityTraits (self, *args, **kwargs)-> SubEntityTraits :
      '''subEntityTraits( (CommonDraw)arg1) -> SubEntityTraits :

    C++ signature :
        class PyGiSubEntityTraits subEntityTraits(class PyGiCommonDraw {lvalue})'''
    ...

class DrawFlags:
    def KDrawIsInWCS (self, *args, **kwargs)-> None:
      '''None'''
    ...
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
    def kDrawFillSelectionWindow (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawFillTextBoundaryEnd (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawFillTextBoundaryStart (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawFrontfacesOnly (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawGradientFill (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawHatchGroup (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawNoForceByLayer (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawNoLineWeight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawNoOptimization (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawSolidFill (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawUseAcGiEntityForDgnLineType (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kNoDrawFlags (self, *args, **kwargs)-> None:
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

class Drawable:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def bounds (self, *args, **kwargs)-> bool :
      '''bounds( (Drawable)arg1, (Extents)arg2) -> bool :

    C++ signature :
        bool bounds(class PyGiDrawable {lvalue},class AcDbExtents {lvalue})'''
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
    def drawableType (self, *args, **kwargs)-> GiDrawableType :
      '''drawableType( (Drawable)arg1) -> GiDrawableType :

    C++ signature :
        enum AcGiDrawable::DrawableType drawableType(class PyGiDrawable {lvalue})'''
    ...
    def id (self, *args, **kwargs)-> ObjectId :
      '''id( (Drawable)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId id(class PyGiDrawable {lvalue})'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (Drawable)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyGiDrawable {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def isPersistent (self, *args, **kwargs)-> bool :
      '''isPersistent( (Drawable)arg1) -> bool :

    C++ signature :
        bool isPersistent(class PyGiDrawable {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rolloverHit (self, *args, **kwargs)-> bool :
      '''rolloverHit( (Drawable)arg1, (int)arg2, (int)arg3, (bool)arg4) -> bool :

    C++ signature :
        bool rolloverHit(class PyGiDrawable {lvalue},unsigned __int64,unsigned __int64,bool)'''
    ...
    def setAttributes (self, *args, **kwargs)-> int :
      '''setAttributes( (Drawable)arg1, (DrawableTraits)arg2) -> int :

    C++ signature :
        unsigned int setAttributes(class PyGiDrawable {lvalue},class PyGiDrawableTraits {lvalue})'''
    ...
    def viewportDraw (self, *args, **kwargs)-> None :
      '''viewportDraw( (Drawable)arg1, (ViewportDraw)arg2) -> None :

    C++ signature :
        void viewportDraw(class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def viewportDrawLogicalFlags (self, *args, **kwargs)-> int :
      '''viewportDrawLogicalFlags( (Drawable)arg1, (ViewportDraw)arg2) -> int :

    C++ signature :
        unsigned int viewportDrawLogicalFlags(class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def worldDraw (self, *args, **kwargs)-> bool :
      '''worldDraw( (Drawable)arg1, (WorldDraw)arg2) -> bool :

    C++ signature :
        bool worldDraw(class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
    ...

class DrawableOverrule:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addOverrule (self, *args, **kwargs)-> None :
      '''addOverrule( (RxClass)arg1, (Overrule)arg2) -> None :

    C++ signature :
        void addOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def addOverruleLast (self, *args, **kwargs)-> None :
      '''addOverruleLast( (RxClass)arg1, (Overrule)arg2, (bool)arg3) -> None :

    C++ signature :
        void addOverruleLast(class PyRxClass {lvalue},class PyRxOverrule {lvalue},bool)'''
    ...
    def baseViewportDraw (self, *args, **kwargs)-> None :
      '''baseViewportDraw( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void baseViewportDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def baseViewportDrawLogicalFlags (self, *args, **kwargs)-> int :
      '''baseViewportDrawLogicalFlags( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> int :

    C++ signature :
        unsigned int baseViewportDrawLogicalFlags(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def baseWorldDraw (self, *args, **kwargs)-> bool :
      '''baseWorldDraw( (DrawableOverrule)arg1, (Drawable)arg2, (WorldDraw)arg3) -> bool :

    C++ signature :
        bool baseWorldDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
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
    def hasOverrule (self, *args, **kwargs)-> bool :
      '''hasOverrule( (RxObject)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool hasOverrule(class PyRxObject {lvalue},class PyRxClass {lvalue})'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isApplicable (self, *args, **kwargs)-> bool :
      '''isApplicable( (DrawableOverrule)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool isApplicable(class PyGiDrawableOverrule {lvalue},class PyRxObject {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def isOverruling (self, *args, **kwargs)-> bool :
      '''isOverruling() -> bool :

    C++ signature :
        bool isOverruling()'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def removeOverrule (self, *args, **kwargs)-> None :
      '''removeOverrule( (RxClass)arg1, (Overrule)arg2) -> None :

    C++ signature :
        void removeOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def setAttributes (self, *args, **kwargs)-> int :
      '''setAttributes( (DrawableOverrule)arg1, (Drawable)arg2, (DrawableTraits)arg3) -> int :

    C++ signature :
        unsigned int setAttributes(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiDrawableTraits {lvalue})'''
    ...
    def setIsOverruling (self, *args, **kwargs)-> None :
      '''setIsOverruling( (bool)arg1) -> None :

    C++ signature :
        void setIsOverruling(bool)'''
    ...
    def viewportDraw (self, *args, **kwargs)-> None :
      '''viewportDraw( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> None :

    C++ signature :
        void viewportDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def viewportDrawLogicalFlags (self, *args, **kwargs)-> int :
      '''viewportDrawLogicalFlags( (DrawableOverrule)arg1, (Drawable)arg2, (ViewportDraw)arg3) -> int :

    C++ signature :
        unsigned int viewportDrawLogicalFlags(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiViewportDraw {lvalue})'''
    ...
    def worldDraw (self, *args, **kwargs)-> bool :
      '''worldDraw( (DrawableOverrule)arg1, (Drawable)arg2, (WorldDraw)arg3) -> bool :

    C++ signature :
        bool worldDraw(class PyGiDrawableOverrule {lvalue},class PyGiDrawable {lvalue},class PyGiWorldDraw {lvalue})'''
    ...

class DrawableTraits:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def color (self, *args, **kwargs)-> int :
      '''color( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned short color(class PyGiSubEntityTraits {lvalue})'''
    ...
    def desc (self, *args, **kwargs)-> RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def drawFlags (self, *args, **kwargs)-> int :
      '''drawFlags( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned int drawFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def fillType (self, *args, **kwargs)-> AcGiFillType :
      '''fillType( (SubEntityTraits)arg1) -> AcGiFillType :

    C++ signature :
        enum AcGiFillType fillType(class PyGiSubEntityTraits {lvalue})'''
    ...
    def getPlotStyleNameId (self, *args, **kwargs)-> ObjectId :
      '''getPlotStyleNameId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getPlotStyleNameId(class PyGiSubEntityTraits {lvalue})'''
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
    def layerId (self, *args, **kwargs)-> ObjectId :
      '''layerId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layerId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeId (self, *args, **kwargs)-> ObjectId :
      '''lineTypeId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId lineTypeId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeScale (self, *args, **kwargs)-> float :
      '''lineTypeScale( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double lineTypeScale(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineWeight (self, *args, **kwargs)-> LineWeight :
      '''lineWeight( (SubEntityTraits)arg1) -> LineWeight :

    C++ signature :
        enum AcDb::LineWeight lineWeight(class PyGiSubEntityTraits {lvalue})'''
    ...
    def materialId (self, *args, **kwargs)-> ObjectId :
      '''materialId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId materialId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def sectionable (self, *args, **kwargs)-> bool :
      '''sectionable( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool sectionable(class PyGiSubEntityTraits {lvalue})'''
    ...
    def selectionGeom (self, *args, **kwargs)-> bool :
      '''selectionGeom( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool selectionGeom(class PyGiSubEntityTraits {lvalue})'''
    ...
    def setColor (self, *args, **kwargs)-> None :
      '''setColor( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setColor(class PyGiSubEntityTraits {lvalue},unsigned short)'''
    ...
    def setDrawFlags (self, *args, **kwargs)-> None :
      '''setDrawFlags( (SubEntityTraits)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setDrawFlags(class PyGiSubEntityTraits {lvalue},unsigned int)'''
    ...
    def setFillType (self, *args, **kwargs)-> None :
      '''setFillType( (SubEntityTraits)arg1, (AcGiFillType)arg2) -> None :

    C++ signature :
        void setFillType(class PyGiSubEntityTraits {lvalue},enum AcGiFillType)'''
    ...
    def setLayer (self, *args, **kwargs)-> None :
      '''setLayer( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayer(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineType (self, *args, **kwargs)-> None :
      '''setLineType( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLineType(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineTypeScale (self, *args, **kwargs)-> None :
      '''setLineTypeScale( (SubEntityTraits)arg1) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue})

setLineTypeScale( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setLineWeight (self, *args, **kwargs)-> None :
      '''setLineWeight( (SubEntityTraits)arg1, (LineWeight)arg2) -> None :

    C++ signature :
        void setLineWeight(class PyGiSubEntityTraits {lvalue},enum AcDb::LineWeight)'''
    ...
    def setMaterial (self, *args, **kwargs)-> None :
      '''setMaterial( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setMaterial(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType)

setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId)'''
    ...
    def setSectionable (self, *args, **kwargs)-> None :
      '''setSectionable( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSectionable(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionGeom (self, *args, **kwargs)-> None :
      '''setSelectionGeom( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSelectionGeom(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionMarker (self, *args, **kwargs)-> None :
      '''setSelectionMarker( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setSelectionMarker(class PyGiSubEntityTraits {lvalue},__int64)'''
    ...
    def setShadowFlags (self, *args, **kwargs)-> None :
      '''setShadowFlags( (SubEntityTraits)arg1, (ShadowFlags)arg2) -> None :

    C++ signature :
        void setShadowFlags(class PyGiSubEntityTraits {lvalue},enum AcGiSubEntityTraits::ShadowFlags)'''
    ...
    def setThickness (self, *args, **kwargs)-> None :
      '''setThickness( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setThickness(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setTransparency (self, *args, **kwargs)-> None :
      '''setTransparency( (SubEntityTraits)arg1, (Transparency)arg2) -> None :

    C++ signature :
        void setTransparency(class PyGiSubEntityTraits {lvalue},class AcCmTransparency)'''
    ...
    def setTrueColor (self, *args, **kwargs)-> None :
      '''setTrueColor( (SubEntityTraits)arg1, (EntityColor)arg2) -> None :

    C++ signature :
        void setTrueColor(class PyGiSubEntityTraits {lvalue},class AcCmEntityColor)'''
    ...
    def setVisualStyle (self, *args, **kwargs)-> None :
      '''setVisualStyle( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setVisualStyle(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def shadowFlags (self, *args, **kwargs)-> ShadowFlags :
      '''shadowFlags( (SubEntityTraits)arg1) -> ShadowFlags :

    C++ signature :
        enum AcGiSubEntityTraits::ShadowFlags shadowFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def thickness (self, *args, **kwargs)-> float :
      '''thickness( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double thickness(class PyGiSubEntityTraits {lvalue})'''
    ...
    def transparency (self, *args, **kwargs)-> Transparency :
      '''transparency( (SubEntityTraits)arg1) -> Transparency :

    C++ signature :
        class AcCmTransparency transparency(class PyGiSubEntityTraits {lvalue})'''
    ...
    def trueColor (self, *args, **kwargs)-> EntityColor :
      '''trueColor( (SubEntityTraits)arg1) -> EntityColor :

    C++ signature :
        class AcCmEntityColor trueColor(class PyGiSubEntityTraits {lvalue})'''
    ...
    def visualStyle (self, *args, **kwargs)-> ObjectId :
      '''visualStyle( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId visualStyle(class PyGiSubEntityTraits {lvalue})'''
    ...

class Geometry:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def circle (self, *args, **kwargs)-> bool :
      '''circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (AcGiArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (AcGiArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
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
    def draw (self, *args, **kwargs)-> bool :
      '''draw( (Geometry)arg1, (Drawable)arg2) -> bool :

    C++ signature :
        bool draw(class PyGiGeometry {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def edge (self, *args, **kwargs)-> bool :
      '''edge( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool edge(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def ellipticalArc (self, *args, **kwargs)-> bool :
      '''ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double)

ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8, (AcGiArcType)arg9) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double,enum AcGiArcType)'''
    ...
    def getModelToWorldTransform (self, *args, **kwargs)-> Matrix3d :
      '''getModelToWorldTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getModelToWorldTransform(class PyGiGeometry {lvalue})'''
    ...
    def getWorldToModelTransform (self, *args, **kwargs)-> Matrix3d :
      '''getWorldToModelTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getWorldToModelTransform(class PyGiGeometry {lvalue})'''
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
    def pline (self, *args, **kwargs)-> bool :
      '''pline( (Geometry)arg1, (Polyline)arg2) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline)

pline( (Geometry)arg1, (Polyline)arg2, (SubentType)arg3, (SubentType)arg4) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline,unsigned int,unsigned int)'''
    ...
    def polygon (self, *args, **kwargs)-> bool :
      '''polygon( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polygon(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def polyline (self, *args, **kwargs)-> bool :
      '''polyline( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list)

polyline( (Geometry)arg1, (list)arg2, (Vector3d)arg3, (int)arg4) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list,class AcGeVector3d,__int64)'''
    ...
    def popModelTransform (self, *args, **kwargs)-> bool :
      '''popModelTransform( (Geometry)arg1) -> bool :

    C++ signature :
        bool popModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def pushModelTransform (self, *args, **kwargs)-> bool :
      '''pushModelTransform( (Geometry)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeVector3d)

pushModelTransform( (Geometry)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeMatrix3d)'''
    ...
    def pushOrientationTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushOrientationTransform( (Geometry)arg1, (AcGiOrientationTransformBehavior)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushOrientationTransform(class PyGiGeometry {lvalue},enum AcGiOrientationTransformBehavior)'''
    ...
    def pushPositionTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint3d)

pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint2d)'''
    ...
    def pushScaleTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint3d)

pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint2d)'''
    ...
    def ray (self, *args, **kwargs)-> bool :
      '''ray( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool ray(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rowOfDots (self, *args, **kwargs)-> bool :
      '''rowOfDots( (Geometry)arg1, (int)arg2, (Point3d)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool rowOfDots(class PyGiGeometry {lvalue},int,class AcGePoint3d,class AcGeVector3d)'''
    ...
    def text (self, *args, **kwargs)-> bool :
      '''text( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (str)arg8) -> bool :

    C++ signature :
        bool text(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def worldLine (self, *args, **kwargs)-> bool :
      '''worldLine( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool worldLine(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def xline (self, *args, **kwargs)-> bool :
      '''xline( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool xline(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...

class GiAttributesFlags:
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
    def kDrawableBlockDependentViewportDraw (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableHasAttributes (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableIsAnEntity (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableIsCompoundObject (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableIsDimension (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableIsExternalReference (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableIsInvisible (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableMergeControlOff (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableNone (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableNotAllowLCS (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableNotPlottable (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableRegenDraw (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableRegenTypeDependentGeometry (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableShadedDisplaySingleLOD (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableStandardDisplaySingleLOD (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableUsesNesting (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableViewDependentViewportDraw (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDrawableViewIndependentViewportDraw (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kThreadedWorldDrawViewportDraw (self, *args, **kwargs)-> None:
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

class GiDrawableType:
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
    def kAmbientLight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kDistantLight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kGeometry (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kGradientBackground (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kGroundPlaneBackground (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kImageBackground (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kImageBasedLightingBackground (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kPointLight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kSkyBackground (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kSolidBackground (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kSpotLight (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kViewport (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kWebLight (self, *args, **kwargs)-> None:
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

class SelectionFlags:
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
    def kNoSelectionFlags (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kSelectionIgnore (self, *args, **kwargs)-> None:
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

class ShadowFlags:
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
    def kNoDrawFlags (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kShadowsDoesNotCast (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kShadowsDoesNotReceive (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kShadowsIgnore (self, *args, **kwargs)-> None:
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

class SubEntityTraits:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def color (self, *args, **kwargs)-> int :
      '''color( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned short color(class PyGiSubEntityTraits {lvalue})'''
    ...
    def desc (self, *args, **kwargs)-> RxClass :
      '''desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def drawFlags (self, *args, **kwargs)-> int :
      '''drawFlags( (SubEntityTraits)arg1) -> int :

    C++ signature :
        unsigned int drawFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def fillType (self, *args, **kwargs)-> AcGiFillType :
      '''fillType( (SubEntityTraits)arg1) -> AcGiFillType :

    C++ signature :
        enum AcGiFillType fillType(class PyGiSubEntityTraits {lvalue})'''
    ...
    def getPlotStyleNameId (self, *args, **kwargs)-> ObjectId :
      '''getPlotStyleNameId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId getPlotStyleNameId(class PyGiSubEntityTraits {lvalue})'''
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
    def layerId (self, *args, **kwargs)-> ObjectId :
      '''layerId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layerId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeId (self, *args, **kwargs)-> ObjectId :
      '''lineTypeId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId lineTypeId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineTypeScale (self, *args, **kwargs)-> float :
      '''lineTypeScale( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double lineTypeScale(class PyGiSubEntityTraits {lvalue})'''
    ...
    def lineWeight (self, *args, **kwargs)-> LineWeight :
      '''lineWeight( (SubEntityTraits)arg1) -> LineWeight :

    C++ signature :
        enum AcDb::LineWeight lineWeight(class PyGiSubEntityTraits {lvalue})'''
    ...
    def materialId (self, *args, **kwargs)-> ObjectId :
      '''materialId( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId materialId(class PyGiSubEntityTraits {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def sectionable (self, *args, **kwargs)-> bool :
      '''sectionable( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool sectionable(class PyGiSubEntityTraits {lvalue})'''
    ...
    def selectionGeom (self, *args, **kwargs)-> bool :
      '''selectionGeom( (SubEntityTraits)arg1) -> bool :

    C++ signature :
        bool selectionGeom(class PyGiSubEntityTraits {lvalue})'''
    ...
    def setColor (self, *args, **kwargs)-> None :
      '''setColor( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setColor(class PyGiSubEntityTraits {lvalue},unsigned short)'''
    ...
    def setDrawFlags (self, *args, **kwargs)-> None :
      '''setDrawFlags( (SubEntityTraits)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setDrawFlags(class PyGiSubEntityTraits {lvalue},unsigned int)'''
    ...
    def setFillType (self, *args, **kwargs)-> None :
      '''setFillType( (SubEntityTraits)arg1, (AcGiFillType)arg2) -> None :

    C++ signature :
        void setFillType(class PyGiSubEntityTraits {lvalue},enum AcGiFillType)'''
    ...
    def setLayer (self, *args, **kwargs)-> None :
      '''setLayer( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayer(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineType (self, *args, **kwargs)-> None :
      '''setLineType( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLineType(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setLineTypeScale (self, *args, **kwargs)-> None :
      '''setLineTypeScale( (SubEntityTraits)arg1) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue})

setLineTypeScale( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setLineTypeScale(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setLineWeight (self, *args, **kwargs)-> None :
      '''setLineWeight( (SubEntityTraits)arg1, (LineWeight)arg2) -> None :

    C++ signature :
        void setLineWeight(class PyGiSubEntityTraits {lvalue},enum AcDb::LineWeight)'''
    ...
    def setMaterial (self, *args, **kwargs)-> None :
      '''setMaterial( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setMaterial(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType)

setPlotStyleName( (SubEntityTraits)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyGiSubEntityTraits {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId)'''
    ...
    def setSectionable (self, *args, **kwargs)-> None :
      '''setSectionable( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSectionable(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionGeom (self, *args, **kwargs)-> None :
      '''setSelectionGeom( (SubEntityTraits)arg1, (bool)arg2) -> None :

    C++ signature :
        void setSelectionGeom(class PyGiSubEntityTraits {lvalue},bool)'''
    ...
    def setSelectionMarker (self, *args, **kwargs)-> None :
      '''setSelectionMarker( (SubEntityTraits)arg1, (int)arg2) -> None :

    C++ signature :
        void setSelectionMarker(class PyGiSubEntityTraits {lvalue},__int64)'''
    ...
    def setShadowFlags (self, *args, **kwargs)-> None :
      '''setShadowFlags( (SubEntityTraits)arg1, (ShadowFlags)arg2) -> None :

    C++ signature :
        void setShadowFlags(class PyGiSubEntityTraits {lvalue},enum AcGiSubEntityTraits::ShadowFlags)'''
    ...
    def setThickness (self, *args, **kwargs)-> None :
      '''setThickness( (SubEntityTraits)arg1, (float)arg2) -> None :

    C++ signature :
        void setThickness(class PyGiSubEntityTraits {lvalue},double)'''
    ...
    def setTransparency (self, *args, **kwargs)-> None :
      '''setTransparency( (SubEntityTraits)arg1, (Transparency)arg2) -> None :

    C++ signature :
        void setTransparency(class PyGiSubEntityTraits {lvalue},class AcCmTransparency)'''
    ...
    def setTrueColor (self, *args, **kwargs)-> None :
      '''setTrueColor( (SubEntityTraits)arg1, (EntityColor)arg2) -> None :

    C++ signature :
        void setTrueColor(class PyGiSubEntityTraits {lvalue},class AcCmEntityColor)'''
    ...
    def setVisualStyle (self, *args, **kwargs)-> None :
      '''setVisualStyle( (SubEntityTraits)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setVisualStyle(class PyGiSubEntityTraits {lvalue},class PyDbObjectId)'''
    ...
    def shadowFlags (self, *args, **kwargs)-> ShadowFlags :
      '''shadowFlags( (SubEntityTraits)arg1) -> ShadowFlags :

    C++ signature :
        enum AcGiSubEntityTraits::ShadowFlags shadowFlags(class PyGiSubEntityTraits {lvalue})'''
    ...
    def thickness (self, *args, **kwargs)-> float :
      '''thickness( (SubEntityTraits)arg1) -> float :

    C++ signature :
        double thickness(class PyGiSubEntityTraits {lvalue})'''
    ...
    def transparency (self, *args, **kwargs)-> Transparency :
      '''transparency( (SubEntityTraits)arg1) -> Transparency :

    C++ signature :
        class AcCmTransparency transparency(class PyGiSubEntityTraits {lvalue})'''
    ...
    def trueColor (self, *args, **kwargs)-> EntityColor :
      '''trueColor( (SubEntityTraits)arg1) -> EntityColor :

    C++ signature :
        class AcCmEntityColor trueColor(class PyGiSubEntityTraits {lvalue})'''
    ...
    def visualStyle (self, *args, **kwargs)-> ObjectId :
      '''visualStyle( (SubEntityTraits)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId visualStyle(class PyGiSubEntityTraits {lvalue})'''
    ...

class TransparencyMode:
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
    def kTransparency1Bit (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kTransparency8Bit (self, *args, **kwargs)-> None:
      '''None'''
    ...
    def kTransparencyOff (self, *args, **kwargs)-> None:
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

class ViewportDraw:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
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
    def geometry (self, *args, **kwargs)-> ViewportGeometry :
      '''geometry( (ViewportDraw)arg1) -> ViewportGeometry :

    C++ signature :
        class PyGiViewportGeometry geometry(class PyGiViewportDraw {lvalue})'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isDragging (self, *args, **kwargs)-> bool :
      '''isDragging( (CommonDraw)arg1) -> bool :

    C++ signature :
        bool isDragging(class PyGiCommonDraw {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def regenAbort (self, *args, **kwargs)-> bool :
      '''regenAbort( (CommonDraw)arg1) -> bool :

    C++ signature :
        bool regenAbort(class PyGiCommonDraw {lvalue})'''
    ...
    def regenType (self, *args, **kwargs)-> AcGiRegenType :
      '''regenType( (CommonDraw)arg1) -> AcGiRegenType :

    C++ signature :
        enum AcGiRegenType regenType(class PyGiCommonDraw {lvalue})'''
    ...
    def subEntityTraits (self, *args, **kwargs)-> SubEntityTraits :
      '''subEntityTraits( (CommonDraw)arg1) -> SubEntityTraits :

    C++ signature :
        class PyGiSubEntityTraits subEntityTraits(class PyGiCommonDraw {lvalue})'''
    ...

class ViewportGeometry:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def circle (self, *args, **kwargs)-> bool :
      '''circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (AcGiArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (AcGiArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
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
    def draw (self, *args, **kwargs)-> bool :
      '''draw( (Geometry)arg1, (Drawable)arg2) -> bool :

    C++ signature :
        bool draw(class PyGiGeometry {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def edge (self, *args, **kwargs)-> bool :
      '''edge( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool edge(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def ellipticalArc (self, *args, **kwargs)-> bool :
      '''ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double)

ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8, (AcGiArcType)arg9) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double,enum AcGiArcType)'''
    ...
    def getModelToWorldTransform (self, *args, **kwargs)-> Matrix3d :
      '''getModelToWorldTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getModelToWorldTransform(class PyGiGeometry {lvalue})'''
    ...
    def getWorldToModelTransform (self, *args, **kwargs)-> Matrix3d :
      '''getWorldToModelTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getWorldToModelTransform(class PyGiGeometry {lvalue})'''
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
    def pline (self, *args, **kwargs)-> bool :
      '''pline( (Geometry)arg1, (Polyline)arg2) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline)

pline( (Geometry)arg1, (Polyline)arg2, (SubentType)arg3, (SubentType)arg4) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline,unsigned int,unsigned int)'''
    ...
    def polygon (self, *args, **kwargs)-> bool :
      '''polygon( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polygon(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def polyline (self, *args, **kwargs)-> bool :
      '''polyline( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list)

polyline( (Geometry)arg1, (list)arg2, (Vector3d)arg3, (int)arg4) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list,class AcGeVector3d,__int64)'''
    ...
    def popModelTransform (self, *args, **kwargs)-> bool :
      '''popModelTransform( (Geometry)arg1) -> bool :

    C++ signature :
        bool popModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def pushModelTransform (self, *args, **kwargs)-> bool :
      '''pushModelTransform( (Geometry)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeVector3d)

pushModelTransform( (Geometry)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeMatrix3d)'''
    ...
    def pushOrientationTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushOrientationTransform( (Geometry)arg1, (AcGiOrientationTransformBehavior)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushOrientationTransform(class PyGiGeometry {lvalue},enum AcGiOrientationTransformBehavior)'''
    ...
    def pushPositionTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint3d)

pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint2d)'''
    ...
    def pushScaleTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint3d)

pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint2d)'''
    ...
    def ray (self, *args, **kwargs)-> bool :
      '''ray( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool ray(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rowOfDots (self, *args, **kwargs)-> bool :
      '''rowOfDots( (Geometry)arg1, (int)arg2, (Point3d)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool rowOfDots(class PyGiGeometry {lvalue},int,class AcGePoint3d,class AcGeVector3d)'''
    ...
    def text (self, *args, **kwargs)-> bool :
      '''text( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (str)arg8) -> bool :

    C++ signature :
        bool text(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def worldLine (self, *args, **kwargs)-> bool :
      '''worldLine( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool worldLine(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def xline (self, *args, **kwargs)-> bool :
      '''xline( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool xline(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...

class WorldDraw:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
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
    def geometry (self, *args, **kwargs)-> WorldGeometry :
      '''geometry( (WorldDraw)arg1) -> WorldGeometry :

    C++ signature :
        class PyGiWorldGeometry geometry(class PyGiWorldDraw {lvalue})'''
    ...
    def isA (self, *args, **kwargs)-> RxClass :
      '''isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isDragging (self, *args, **kwargs)-> bool :
      '''isDragging( (CommonDraw)arg1) -> bool :

    C++ signature :
        bool isDragging(class PyGiCommonDraw {lvalue})'''
    ...
    def isNullObj (self, *args, **kwargs)-> bool :
      '''isNullObj( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNullObj(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def regenAbort (self, *args, **kwargs)-> bool :
      '''regenAbort( (CommonDraw)arg1) -> bool :

    C++ signature :
        bool regenAbort(class PyGiCommonDraw {lvalue})'''
    ...
    def regenType (self, *args, **kwargs)-> AcGiRegenType :
      '''regenType( (CommonDraw)arg1) -> AcGiRegenType :

    C++ signature :
        enum AcGiRegenType regenType(class PyGiCommonDraw {lvalue})'''
    ...
    def subEntityTraits (self, *args, **kwargs)-> SubEntityTraits :
      '''subEntityTraits( (CommonDraw)arg1) -> SubEntityTraits :

    C++ signature :
        class PyGiSubEntityTraits subEntityTraits(class PyGiCommonDraw {lvalue})'''
    ...

class WorldGeometry:
    def __init__ (self, *args, **kwargs)-> None:
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def circle (self, *args, **kwargs)-> bool :
      '''circle( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d)

circle( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circle(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def circularArc (self, *args, **kwargs)-> bool :
      '''circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double)

circularArc( (Geometry)arg1, (Point3d)arg2, (float)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (AcGiArcType)arg7) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,double,enum AcGiArcType)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

circularArc( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4, (AcGiArcType)arg5) -> bool :

    C++ signature :
        bool circularArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d,enum AcGiArcType)'''
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
    def draw (self, *args, **kwargs)-> bool :
      '''draw( (Geometry)arg1, (Drawable)arg2) -> bool :

    C++ signature :
        bool draw(class PyGiGeometry {lvalue},class PyGiDrawable {lvalue})'''
    ...
    def edge (self, *args, **kwargs)-> bool :
      '''edge( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool edge(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def ellipticalArc (self, *args, **kwargs)-> bool :
      '''ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double)

ellipticalArc( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8, (AcGiArcType)arg9) -> bool :

    C++ signature :
        bool ellipticalArc(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,double,double,double,double,double,enum AcGiArcType)'''
    ...
    def getModelToWorldTransform (self, *args, **kwargs)-> Matrix3d :
      '''getModelToWorldTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getModelToWorldTransform(class PyGiGeometry {lvalue})'''
    ...
    def getWorldToModelTransform (self, *args, **kwargs)-> Matrix3d :
      '''getWorldToModelTransform( (Geometry)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d getWorldToModelTransform(class PyGiGeometry {lvalue})'''
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
    def pline (self, *args, **kwargs)-> bool :
      '''pline( (Geometry)arg1, (Polyline)arg2) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline)

pline( (Geometry)arg1, (Polyline)arg2, (SubentType)arg3, (SubentType)arg4) -> bool :

    C++ signature :
        bool pline(class PyGiGeometry {lvalue},class PyDbPolyline,unsigned int,unsigned int)'''
    ...
    def polygon (self, *args, **kwargs)-> bool :
      '''polygon( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polygon(class PyGiGeometry {lvalue},class boost::python::list)'''
    ...
    def polyline (self, *args, **kwargs)-> bool :
      '''polyline( (Geometry)arg1, (list)arg2) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list)

polyline( (Geometry)arg1, (list)arg2, (Vector3d)arg3, (int)arg4) -> bool :

    C++ signature :
        bool polyline(class PyGiGeometry {lvalue},class boost::python::list,class AcGeVector3d,__int64)'''
    ...
    def popModelTransform (self, *args, **kwargs)-> bool :
      '''popModelTransform( (Geometry)arg1) -> bool :

    C++ signature :
        bool popModelTransform(class PyGiGeometry {lvalue})'''
    ...
    def pushModelTransform (self, *args, **kwargs)-> bool :
      '''pushModelTransform( (Geometry)arg1, (Vector3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeVector3d)

pushModelTransform( (Geometry)arg1, (Matrix3d)arg2) -> bool :

    C++ signature :
        bool pushModelTransform(class PyGiGeometry {lvalue},class AcGeMatrix3d)'''
    ...
    def pushOrientationTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushOrientationTransform( (Geometry)arg1, (AcGiOrientationTransformBehavior)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushOrientationTransform(class PyGiGeometry {lvalue},enum AcGiOrientationTransformBehavior)'''
    ...
    def pushPositionTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint3d)

pushPositionTransform( (Geometry)arg1, (AcGiPositionTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushPositionTransform(class PyGiGeometry {lvalue},enum AcGiPositionTransformBehavior,class AcGePoint2d)'''
    ...
    def pushScaleTransform (self, *args, **kwargs)-> Matrix3d :
      '''pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint3d)

pushScaleTransform( (Geometry)arg1, (AcGiScaleTransformBehavior)arg2, (Point2d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d pushScaleTransform(class PyGiGeometry {lvalue},enum AcGiScaleTransformBehavior,class AcGePoint2d)'''
    ...
    def ray (self, *args, **kwargs)-> bool :
      '''ray( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool ray(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def refCount (self, *args, **kwargs)-> int :
      '''refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def rowOfDots (self, *args, **kwargs)-> bool :
      '''rowOfDots( (Geometry)arg1, (int)arg2, (Point3d)arg3, (Vector3d)arg4) -> bool :

    C++ signature :
        bool rowOfDots(class PyGiGeometry {lvalue},int,class AcGePoint3d,class AcGeVector3d)'''
    ...
    def text (self, *args, **kwargs)-> bool :
      '''text( (Geometry)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (str)arg8) -> bool :

    C++ signature :
        bool text(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def worldLine (self, *args, **kwargs)-> bool :
      '''worldLine( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool worldLine(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def xline (self, *args, **kwargs)-> bool :
      '''xline( (Geometry)arg1, (Point3d)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool xline(class PyGiGeometry {lvalue},class AcGePoint3d,class AcGePoint3d)'''
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
