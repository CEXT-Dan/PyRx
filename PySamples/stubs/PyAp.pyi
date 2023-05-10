    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def className (self, *args, **kwargs):
      '''
className() -> str'''
    ...
    def docManager (self, *args, **kwargs):
      '''
docManager( (Application)arg1) -> DocManager'''
    ...

class CmdFlags:
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
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
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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

class DocLockMode:
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
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
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
    def values (self, *args, **kwargs):
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
    def activateDocument (self, *args, **kwargs):
      '''
activateDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus

activateDocument( (DocManager)arg1, (Document)arg2, (bool)arg3) -> ErrorStatus'''
    ...
    def appContextCloseDocument (self, *args, **kwargs):
      '''
appContextCloseDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus'''
    ...
    def appContextNewDocument (self, *args, **kwargs):
      '''
appContextNewDocument( (DocManager)arg1, (str)arg2) -> ErrorStatus'''
    ...
    def appContextOpenDocument (self, *args, **kwargs):
      '''
appContextOpenDocument( (DocManager)arg1, (str)arg2) -> ErrorStatus'''
    ...
    def appContextPromptOpenDocument (self, *args, **kwargs):
      '''
appContextPromptOpenDocument( (DocManager)arg1) -> ErrorStatus'''
    ...
    def appContextRecoverDocument (self, *args, **kwargs):
      '''
appContextRecoverDocument( (DocManager)arg1, (str)arg2) -> ErrorStatus'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str'''
    ...
    def closeDocument (self, *args, **kwargs):
      '''
closeDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus'''
    ...
    def curDocument (self, *args, **kwargs):
      '''
curDocument( (DocManager)arg1) -> Document'''
    ...
    def defaultFormatForSave (self, *args, **kwargs):
      '''
defaultFormatForSave( (DocManager)arg1) -> SaveFormat'''
    ...
    def disableDocumentActivation (self, *args, **kwargs):
      '''
disableDocumentActivation( (DocManager)arg1) -> ErrorStatus'''
    ...
    def document (self, *args, **kwargs):
      '''
document( (DocManager)arg1, (Database)arg2) -> Document'''
    ...
    def documentCount (self, *args, **kwargs):
      '''
documentCount( (DocManager)arg1) -> int'''
    ...
    def enableDocumentActivation (self, *args, **kwargs):
      '''
enableDocumentActivation( (DocManager)arg1) -> ErrorStatus'''
    ...
    def inputPending (self, *args, **kwargs):
      '''
inputPending( (DocManager)arg1, (Document)arg2) -> int'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass'''
    ...
    def isApplicationContext (self, *args, **kwargs):
      '''
isApplicationContext( (DocManager)arg1) -> bool'''
    ...
    def isDocumentActivationEnabled (self, *args, **kwargs):
      '''
isDocumentActivationEnabled( (DocManager)arg1) -> bool'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool'''
    ...
    def lockDocument (self, *args, **kwargs):
      '''
lockDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus

lockDocument( (DocManager)arg1, (Document)arg2, (DocLockMode)arg3) -> ErrorStatus

lockDocument( (DocManager)arg1, (Document)arg2, (DocLockMode)arg3, (str)arg4, (str)arg5, (bool)arg6) -> ErrorStatus'''
    ...
    def mdiActiveDocument (self, *args, **kwargs):
      '''
mdiActiveDocument( (DocManager)arg1) -> Document'''
    ...
    def newAcApDocumentIterator (self, *args, **kwargs):
      '''
newAcApDocumentIterator( (DocManager)arg1) -> list'''
    ...
    def newDocument (self, *args, **kwargs):
      '''
newDocument( (DocManager)arg1) -> ErrorStatus'''
    ...
    def openDocument (self, *args, **kwargs):
      '''
openDocument( (DocManager)arg1) -> ErrorStatus'''
    ...
    def popResourceHandle (self, *args, **kwargs):
      '''
popResourceHandle( (DocManager)arg1) -> None'''
    ...
    def pushAcadResourceHandle (self, *args, **kwargs):
      '''
pushAcadResourceHandle( (DocManager)arg1) -> None'''
    ...
    def sendModelessInterrupt (self, *args, **kwargs):
      '''
sendModelessInterrupt( (DocManager)arg1, (Document)arg2) -> ErrorStatus'''
    ...
    def sendStringToExecute (self, *args, **kwargs):
      '''
sendStringToExecute( (DocManager)arg1, (Document)arg2, (str)arg3) -> ErrorStatus

sendStringToExecute( (DocManager)arg1, (Document)arg2, (str)arg3, (bool)arg4, (bool)arg5, (bool)arg6) -> ErrorStatus'''
    ...
    def setCurDocument (self, *args, **kwargs):
      '''
setCurDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus

setCurDocument( (DocManager)arg1, (Document)arg2, (DocLockMode)arg3, (bool)arg4) -> ErrorStatus'''
    ...
    def setDefaultFormatForSave (self, *args, **kwargs):
      '''
setDefaultFormatForSave( (DocManager)arg1, (SaveFormat)arg2) -> ErrorStatus'''
    ...
    def unlockDocument (self, *args, **kwargs):
      '''
unlockDocument( (DocManager)arg1, (Document)arg2) -> ErrorStatus'''
    ...

class DocManagerReactor:
    def addReactor (self, *args, **kwargs):
      '''
addReactor( (DocManagerReactor)arg1) -> None'''
    ...
    def documentActivated (self, *args, **kwargs):
      '''
documentActivated( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentActivationModified (self, *args, **kwargs):
      '''
documentActivationModified( (DocManagerReactor)arg1, (bool)arg2) -> None'''
    ...
    def documentBecameCurrent (self, *args, **kwargs):
      '''
documentBecameCurrent( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentCreateCanceled (self, *args, **kwargs):
      '''
documentCreateCanceled( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentCreateStarted (self, *args, **kwargs):
      '''
documentCreateStarted( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentCreated (self, *args, **kwargs):
      '''
documentCreated( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentDestroyed (self, *args, **kwargs):
      '''
documentDestroyed( (DocManagerReactor)arg1, (str)arg2) -> None'''
    ...
    def documentLockModeChangeVetoed (self, *args, **kwargs):
      '''
documentLockModeChangeVetoed( (DocManagerReactor)arg1, (Document)arg2, (str)arg3) -> None'''
    ...
    def documentLockModeChanged (self, *args, **kwargs):
      '''
documentLockModeChanged( (DocManagerReactor)arg1, (Document)arg2, (DocLockMode)arg3, (DocLockMode)arg4, (DocLockMode)arg5, (str)arg6) -> None'''
    ...
    def documentLockModeWillChange (self, *args, **kwargs):
      '''
documentLockModeWillChange( (DocManagerReactor)arg1, (Document)arg2, (DocLockMode)arg3, (DocLockMode)arg4, (DocLockMode)arg5, (str)arg6) -> None'''
    ...
    def documentToBeActivated (self, *args, **kwargs):
      '''
documentToBeActivated( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentToBeDeactivated (self, *args, **kwargs):
      '''
documentToBeDeactivated( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def documentToBeDestroyed (self, *args, **kwargs):
      '''
documentToBeDestroyed( (DocManagerReactor)arg1, (Document)arg2) -> None'''
    ...
    def removeReactor (self, *args, **kwargs):
      '''
removeReactor( (DocManagerReactor)arg1) -> None'''
    ...

class Document:
    def className (self, *args, **kwargs):
      '''
className() -> str'''
    ...
    def database (self, *args, **kwargs):
      '''
database( (Document)arg1) -> Database'''
    ...
    def docTitle (self, *args, **kwargs):
      '''
docTitle( (Document)arg1) -> str'''
    ...
    def downgradeDocOpen (self, *args, **kwargs):
      '''
downgradeDocOpen( (Document)arg1, (bool)arg2) -> ErrorStatus'''
    ...
    def editor (self, *args, **kwargs):
      '''
editor( (Document)arg1) -> Editor'''
    ...
    def fileName (self, *args, **kwargs):
      '''
fileName( (Document)arg1) -> str'''
    ...
    def formatForSave (self, *args, **kwargs):
      '''
formatForSave( (Document)arg1) -> SaveFormat'''
    ...
    def getCountOfLispList (self, *args, **kwargs):
      '''
getCountOfLispList( (Document)arg1) -> int'''
    ...
    def getItemOfLispList (self, *args, **kwargs):
      '''
getItemOfLispList( (Document)arg1, (CmdFlags)arg2) -> tuple'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass'''
    ...
    def isCommandInputInactive (self, *args, **kwargs):
      '''
isCommandInputInactive( (Document)arg1) -> bool'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool'''
    ...
    def isQuiescent (self, *args, **kwargs):
      '''
isQuiescent( (Document)arg1) -> bool'''
    ...
    def lockMode (self, *args, **kwargs):
      '''
lockMode( (Document)arg1) -> DocLockMode

lockMode( (Document)arg1, (bool)arg2) -> DocLockMode'''
    ...
    def myLockMode (self, *args, **kwargs):
      '''
myLockMode( (Document)arg1) -> DocLockMode'''
    ...
    def popDbmod (self, *args, **kwargs):
      '''
popDbmod( (Document)arg1) -> ErrorStatus'''
    ...
    def pushDbmod (self, *args, **kwargs):
      '''
pushDbmod( (Document)arg1) -> None'''
    ...
    def setDocTitle (self, *args, **kwargs):
      '''
setDocTitle( (Document)arg1, (str)arg2) -> None'''
    ...
    def upgradeDocOpen (self, *args, **kwargs):
      '''
upgradeDocOpen( (Document)arg1) -> ErrorStatus'''
    ...
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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

class SaveFormat:
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
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def ACTIONMACRO (self, *args, **kwargs):
      '''None'''
    ...
    def DEFUN (self, *args, **kwargs):
      '''None'''
    ...
    def DEPRECATED (self, *args, **kwargs):
      '''None'''
    ...
    def DOCEXCLUSIVELOCK (self, *args, **kwargs):
      '''None'''
    ...
    def DOCREADLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def INPROGRESS (self, *args, **kwargs):
      '''None'''
    ...
    def INTERRUPTIBLE (self, *args, **kwargs):
      '''None'''
    ...
    def MODAL (self, *args, **kwargs):
      '''None'''
    ...
    def NOACTIONRECORDING (self, *args, **kwargs):
      '''None'''
    ...
    def NOBEDIT (self, *args, **kwargs):
      '''None'''
    ...
    def NOHISTORY (self, *args, **kwargs):
      '''None'''
    ...
    def NOINFERCONSTRAINT (self, *args, **kwargs):
      '''None'''
    ...
    def NOINTERNALLOCK (self, *args, **kwargs):
      '''None'''
    ...
    def NOMULTIPLE (self, *args, **kwargs):
      '''None'''
    ...
    def NOOEM (self, *args, **kwargs):
      '''None'''
    ...
    def NOPAPERSPACE (self, *args, **kwargs):
      '''None'''
    ...
    def NOPERSPECTIVE (self, *args, **kwargs):
      '''None'''
    ...
    def NOTILEMODE (self, *args, **kwargs):
      '''None'''
    ...
    def NO_UNDO_MARKER (self, *args, **kwargs):
      '''None'''
    ...
    def REDRAW (self, *args, **kwargs):
      '''None'''
    ...
    def RELAXASSOC (self, *args, **kwargs):
      '''None'''
    ...
    def SESSION (self, *args, **kwargs):
      '''None'''
    ...
    def TEMPSHOWDYNDIM (self, *args, **kwargs):
      '''None'''
    ...
    def TRANSPARENT (self, *args, **kwargs):
      '''None'''
    ...
    def UNDEFINED (self, *args, **kwargs):
      '''None'''
    ...
    def USEPICKSET (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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

class __loader__:
    def _ORIGIN (self, *args, **kwargs):
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
    def capitalize ():
      '''Return a capitalized version of the string.

More specifically, make the first character have upper case and the rest lower
case.'''
    ...
    def casefold ():
      '''Return a version of the string suitable for caseless comparisons.'''
    ...
    def center (width, fillchar=' ', /):
      '''Return a centered string of length width.

Padding is done using the specified fill character (default is a space).'''
    ...
    def count (self, *args, **kwargs):
      '''S.count(sub[, start[, end]]) -> int

Return the number of non-overlapping occurrences of substring sub in
string S[start:end].  Optional arguments start and end are
interpreted as in slice notation.'''
    ...
    def encode (encoding='utf-8', errors='strict'):
      '''Encode the string using the codec registered for encoding.

  encoding
    The encoding in which to encode the string.
  errors
    The error handling scheme to use for encoding errors.
    The default is 'strict' meaning that encoding errors raise a
    UnicodeEncodeError.  Other possible values are 'ignore', 'replace' and
    'xmlcharrefreplace' as well as any other name registered with
    codecs.register_error that can handle UnicodeEncodeErrors.'''
    ...
    def endswith (self, *args, **kwargs):
      '''S.endswith(suffix[, start[, end]]) -> bool

Return True if S ends with the specified suffix, False otherwise.
With optional start, test S beginning at that position.
With optional end, stop comparing S at that position.
suffix can also be a tuple of strings to try.'''
    ...
    def expandtabs (tabsize=8):
      '''Return a copy where all tab characters are expanded using spaces.

If tabsize is not given, a tab size of 8 characters is assumed.'''
    ...
    def find (self, *args, **kwargs):
      '''S.find(sub[, start[, end]]) -> int

Return the lowest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Return -1 on failure.'''
    ...
    def format (self, *args, **kwargs):
      '''S.format(*args, **kwargs) -> str

Return a formatted version of S, using substitutions from args and kwargs.
The substitutions are identified by braces ('{' and '}').'''
    ...
    def format_map (self, *args, **kwargs):
      '''S.format_map(mapping) -> str

Return a formatted version of S, using substitutions from mapping.
The substitutions are identified by braces ('{' and '}').'''
    ...
    def index (self, *args, **kwargs):
      '''S.index(sub[, start[, end]]) -> int

Return the lowest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Raises ValueError when the substring is not found.'''
    ...
    def isalnum ():
      '''Return True if the string is an alpha-numeric string, False otherwise.

A string is alpha-numeric if all characters in the string are alpha-numeric and
there is at least one character in the string.'''
    ...
    def isalpha ():
      '''Return True if the string is an alphabetic string, False otherwise.

A string is alphabetic if all characters in the string are alphabetic and there
is at least one character in the string.'''
    ...
    def isascii ():
      '''Return True if all characters in the string are ASCII, False otherwise.

ASCII characters have code points in the range U+0000-U+007F.
Empty string is ASCII too.'''
    ...
    def isdecimal ():
      '''Return True if the string is a decimal string, False otherwise.

A string is a decimal string if all characters in the string are decimal and
there is at least one character in the string.'''
    ...
    def isdigit ():
      '''Return True if the string is a digit string, False otherwise.

A string is a digit string if all characters in the string are digits and there
is at least one character in the string.'''
    ...
    def isidentifier ():
      '''Return True if the string is a valid Python identifier, False otherwise.

Call keyword.iskeyword(s) to test whether string s is a reserved identifier,
such as "def" or "class".'''
    ...
    def islower ():
      '''Return True if the string is a lowercase string, False otherwise.

A string is lowercase if all cased characters in the string are lowercase and
there is at least one cased character in the string.'''
    ...
    def isnumeric ():
      '''Return True if the string is a numeric string, False otherwise.

A string is numeric if all characters in the string are numeric and there is at
least one character in the string.'''
    ...
    def isprintable ():
      '''Return True if the string is printable, False otherwise.

A string is printable if all of its characters are considered printable in
repr() or if it is empty.'''
    ...
    def isspace ():
      '''Return True if the string is a whitespace string, False otherwise.

A string is whitespace if all characters in the string are whitespace and there
is at least one character in the string.'''
    ...
    def istitle ():
      '''Return True if the string is a title-cased string, False otherwise.

In a title-cased string, upper- and title-case characters may only
follow uncased characters and lowercase characters only cased ones.'''
    ...
    def isupper ():
      '''Return True if the string is an uppercase string, False otherwise.

A string is uppercase if all cased characters in the string are uppercase and
there is at least one cased character in the string.'''
    ...
    def join (iterable, /):
      '''Concatenate any number of strings.

The string whose method is called is inserted in between each given string.
The result is returned as a new string.

Example: '.'.join(['ab', 'pq', 'rs']) -> 'ab.pq.rs''''
    ...
    def ljust (width, fillchar=' ', /):
      '''Return a left-justified string of length width.

Padding is done using the specified fill character (default is a space).'''
    ...
    def lower ():
      '''Return a copy of the string converted to lowercase.'''
    ...
    def lstrip (chars=None, /):
      '''Return a copy of the string with leading whitespace removed.

If chars is given and not None, remove characters in chars instead.'''
    ...
    def maketrans (self, *args, **kwargs):
      '''Return a translation table usable for str.translate().

If there is only one argument, it must be a dictionary mapping Unicode
ordinals (integers) or characters to Unicode ordinals, strings or None.
Character keys will be then converted to ordinals.
If there are two arguments, they must be strings of equal length, and
in the resulting dictionary, each character in x will be mapped to the
character at the same position in y. If there is a third argument, it
must be a string, whose characters will be mapped to None in the result.'''
    ...
    def partition (sep, /):
      '''Partition the string into three parts using the given separator.

This will search for the separator in the string.  If the separator is found,
returns a 3-tuple containing the part before the separator, the separator
itself, and the part after it.

If the separator is not found, returns a 3-tuple containing the original string
and two empty strings.'''
    ...
    def removeprefix (prefix, /):
      '''Return a str with the given prefix string removed if present.

If the string starts with the prefix string, return string[len(prefix):].
Otherwise, return a copy of the original string.'''
    ...
    def removesuffix (suffix, /):
      '''Return a str with the given suffix string removed if present.

If the string ends with the suffix string and that suffix is not empty,
return string[:-len(suffix)]. Otherwise, return a copy of the original
string.'''
    ...
    def replace (old, new, count=-1, /):
      '''Return a copy with all occurrences of substring old replaced by new.

  count
    Maximum number of occurrences to replace.
    -1 (the default value) means replace all occurrences.

If the optional argument count is given, only the first count occurrences are
replaced.'''
    ...
    def rfind (self, *args, **kwargs):
      '''S.rfind(sub[, start[, end]]) -> int

Return the highest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Return -1 on failure.'''
    ...
    def rindex (self, *args, **kwargs):
      '''S.rindex(sub[, start[, end]]) -> int

Return the highest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Raises ValueError when the substring is not found.'''
    ...
    def rjust (width, fillchar=' ', /):
      '''Return a right-justified string of length width.

Padding is done using the specified fill character (default is a space).'''
    ...
    def rpartition (sep, /):
      '''Partition the string into three parts using the given separator.

This will search for the separator in the string, starting at the end. If
the separator is found, returns a 3-tuple containing the part before the
separator, the separator itself, and the part after it.

If the separator is not found, returns a 3-tuple containing two empty strings
and the original string.'''
    ...
    def rsplit (sep=None, maxsplit=-1):
      '''Return a list of the substrings in the string, using sep as the separator string.

  sep
    The separator used to split the string.

    When set to None (the default value), will split on any whitespace
    character (including \\n \\r \\t \\f and spaces) and will discard
    empty strings from the result.
  maxsplit
    Maximum number of splits (starting from the left).
    -1 (the default value) means no limit.

Splitting starts at the end of the string and works to the front.'''
    ...
    def rstrip (chars=None, /):
      '''Return a copy of the string with trailing whitespace removed.

If chars is given and not None, remove characters in chars instead.'''
    ...
    def split (sep=None, maxsplit=-1):
      '''Return a list of the substrings in the string, using sep as the separator string.

  sep
    The separator used to split the string.

    When set to None (the default value), will split on any whitespace
    character (including \\n \\r \\t \\f and spaces) and will discard
    empty strings from the result.
  maxsplit
    Maximum number of splits (starting from the left).
    -1 (the default value) means no limit.

Note, str.split() is mainly useful for data that has been intentionally
delimited.  With natural text that includes punctuation, consider using
the regular expression module.'''
    ...
    def splitlines (keepends=False):
      '''Return a list of the lines in the string, breaking at line boundaries.

Line breaks are not included in the resulting list unless keepends is given and
true.'''
    ...
    def startswith (self, *args, **kwargs):
      '''S.startswith(prefix[, start[, end]]) -> bool

Return True if S starts with the specified prefix, False otherwise.
With optional start, test S beginning at that position.
With optional end, stop comparing S at that position.
prefix can also be a tuple of strings to try.'''
    ...
    def strip (chars=None, /):
      '''Return a copy of the string with leading and trailing whitespace removed.

If chars is given and not None, remove characters in chars instead.'''
    ...
    def swapcase ():
      '''Convert uppercase characters to lowercase and lowercase characters to uppercase.'''
    ...
    def title ():
      '''Return a version of the string where each word is titlecased.

More specifically, words start with uppercased characters and all remaining
cased characters have lower case.'''
    ...
    def translate (table, /):
      '''Replace each character in the string using the given translation table.

  table
    Translation table, which must be a mapping of Unicode ordinals to
    Unicode ordinals, strings, or None.

The table must implement lookup/indexing via __getitem__, for instance a
dictionary or list.  If this operation raises LookupError, the character is
left untouched.  Characters mapped to None are deleted.'''
    ...
    def upper ():
      '''Return a copy of the string converted to uppercase.'''
    ...
    def zfill (width, /):
      '''Pad a numeric string with zeros on the left, to fill a field of the given width.

The string is never truncated.'''
    ...
    def capitalize ():
      '''Return a capitalized version of the string.

More specifically, make the first character have upper case and the rest lower
case.'''
    ...
    def casefold ():
      '''Return a version of the string suitable for caseless comparisons.'''
    ...
    def center (width, fillchar=' ', /):
      '''Return a centered string of length width.

Padding is done using the specified fill character (default is a space).'''
    ...
    def count (self, *args, **kwargs):
      '''S.count(sub[, start[, end]]) -> int

Return the number of non-overlapping occurrences of substring sub in
string S[start:end].  Optional arguments start and end are
interpreted as in slice notation.'''
    ...
    def encode (encoding='utf-8', errors='strict'):
      '''Encode the string using the codec registered for encoding.

  encoding
    The encoding in which to encode the string.
  errors
    The error handling scheme to use for encoding errors.
    The default is 'strict' meaning that encoding errors raise a
    UnicodeEncodeError.  Other possible values are 'ignore', 'replace' and
    'xmlcharrefreplace' as well as any other name registered with
    codecs.register_error that can handle UnicodeEncodeErrors.'''
    ...
    def endswith (self, *args, **kwargs):
      '''S.endswith(suffix[, start[, end]]) -> bool

Return True if S ends with the specified suffix, False otherwise.
With optional start, test S beginning at that position.
With optional end, stop comparing S at that position.
suffix can also be a tuple of strings to try.'''
    ...
    def expandtabs (tabsize=8):
      '''Return a copy where all tab characters are expanded using spaces.

If tabsize is not given, a tab size of 8 characters is assumed.'''
    ...
    def find (self, *args, **kwargs):
      '''S.find(sub[, start[, end]]) -> int

Return the lowest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Return -1 on failure.'''
    ...
    def format (self, *args, **kwargs):
      '''S.format(*args, **kwargs) -> str

Return a formatted version of S, using substitutions from args and kwargs.
The substitutions are identified by braces ('{' and '}').'''
    ...
    def format_map (self, *args, **kwargs):
      '''S.format_map(mapping) -> str

Return a formatted version of S, using substitutions from mapping.
The substitutions are identified by braces ('{' and '}').'''
    ...
    def index (self, *args, **kwargs):
      '''S.index(sub[, start[, end]]) -> int

Return the lowest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Raises ValueError when the substring is not found.'''
    ...
    def isalnum ():
      '''Return True if the string is an alpha-numeric string, False otherwise.

A string is alpha-numeric if all characters in the string are alpha-numeric and
there is at least one character in the string.'''
    ...
    def isalpha ():
      '''Return True if the string is an alphabetic string, False otherwise.

A string is alphabetic if all characters in the string are alphabetic and there
is at least one character in the string.'''
    ...
    def isascii ():
      '''Return True if all characters in the string are ASCII, False otherwise.

ASCII characters have code points in the range U+0000-U+007F.
Empty string is ASCII too.'''
    ...
    def isdecimal ():
      '''Return True if the string is a decimal string, False otherwise.

A string is a decimal string if all characters in the string are decimal and
there is at least one character in the string.'''
    ...
    def isdigit ():
      '''Return True if the string is a digit string, False otherwise.

A string is a digit string if all characters in the string are digits and there
is at least one character in the string.'''
    ...
    def isidentifier ():
      '''Return True if the string is a valid Python identifier, False otherwise.

Call keyword.iskeyword(s) to test whether string s is a reserved identifier,
such as "def" or "class".'''
    ...
    def islower ():
      '''Return True if the string is a lowercase string, False otherwise.

A string is lowercase if all cased characters in the string are lowercase and
there is at least one cased character in the string.'''
    ...
    def isnumeric ():
      '''Return True if the string is a numeric string, False otherwise.

A string is numeric if all characters in the string are numeric and there is at
least one character in the string.'''
    ...
    def isprintable ():
      '''Return True if the string is printable, False otherwise.

A string is printable if all of its characters are considered printable in
repr() or if it is empty.'''
    ...
    def isspace ():
      '''Return True if the string is a whitespace string, False otherwise.

A string is whitespace if all characters in the string are whitespace and there
is at least one character in the string.'''
    ...
    def istitle ():
      '''Return True if the string is a title-cased string, False otherwise.

In a title-cased string, upper- and title-case characters may only
follow uncased characters and lowercase characters only cased ones.'''
    ...
    def isupper ():
      '''Return True if the string is an uppercase string, False otherwise.

A string is uppercase if all cased characters in the string are uppercase and
there is at least one cased character in the string.'''
    ...
    def join (iterable, /):
      '''Concatenate any number of strings.

The string whose method is called is inserted in between each given string.
The result is returned as a new string.

Example: '.'.join(['ab', 'pq', 'rs']) -> 'ab.pq.rs''''
    ...
    def ljust (width, fillchar=' ', /):
      '''Return a left-justified string of length width.

Padding is done using the specified fill character (default is a space).'''
    ...
    def lower ():
      '''Return a copy of the string converted to lowercase.'''
    ...
    def lstrip (chars=None, /):
      '''Return a copy of the string with leading whitespace removed.

If chars is given and not None, remove characters in chars instead.'''
    ...
    def maketrans (self, *args, **kwargs):
      '''Return a translation table usable for str.translate().

If there is only one argument, it must be a dictionary mapping Unicode
ordinals (integers) or characters to Unicode ordinals, strings or None.
Character keys will be then converted to ordinals.
If there are two arguments, they must be strings of equal length, and
in the resulting dictionary, each character in x will be mapped to the
character at the same position in y. If there is a third argument, it
must be a string, whose characters will be mapped to None in the result.'''
    ...
    def partition (sep, /):
      '''Partition the string into three parts using the given separator.

This will search for the separator in the string.  If the separator is found,
returns a 3-tuple containing the part before the separator, the separator
itself, and the part after it.

If the separator is not found, returns a 3-tuple containing the original string
and two empty strings.'''
    ...
    def removeprefix (prefix, /):
      '''Return a str with the given prefix string removed if present.

If the string starts with the prefix string, return string[len(prefix):].
Otherwise, return a copy of the original string.'''
    ...
    def removesuffix (suffix, /):
      '''Return a str with the given suffix string removed if present.

If the string ends with the suffix string and that suffix is not empty,
return string[:-len(suffix)]. Otherwise, return a copy of the original
string.'''
    ...
    def replace (old, new, count=-1, /):
      '''Return a copy with all occurrences of substring old replaced by new.

  count
    Maximum number of occurrences to replace.
    -1 (the default value) means replace all occurrences.

If the optional argument count is given, only the first count occurrences are
replaced.'''
    ...
    def rfind (self, *args, **kwargs):
      '''S.rfind(sub[, start[, end]]) -> int

Return the highest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Return -1 on failure.'''
    ...
    def rindex (self, *args, **kwargs):
      '''S.rindex(sub[, start[, end]]) -> int

Return the highest index in S where substring sub is found,
such that sub is contained within S[start:end].  Optional
arguments start and end are interpreted as in slice notation.

Raises ValueError when the substring is not found.'''
    ...
    def rjust (width, fillchar=' ', /):
      '''Return a right-justified string of length width.

Padding is done using the specified fill character (default is a space).'''
    ...
    def rpartition (sep, /):
      '''Partition the string into three parts using the given separator.

This will search for the separator in the string, starting at the end. If
the separator is found, returns a 3-tuple containing the part before the
separator, the separator itself, and the part after it.

If the separator is not found, returns a 3-tuple containing two empty strings
and the original string.'''
    ...
    def rsplit (sep=None, maxsplit=-1):
      '''Return a list of the substrings in the string, using sep as the separator string.

  sep
    The separator used to split the string.

    When set to None (the default value), will split on any whitespace
    character (including \\n \\r \\t \\f and spaces) and will discard
    empty strings from the result.
  maxsplit
    Maximum number of splits (starting from the left).
    -1 (the default value) means no limit.

Splitting starts at the end of the string and works to the front.'''
    ...
    def rstrip (chars=None, /):
      '''Return a copy of the string with trailing whitespace removed.

If chars is given and not None, remove characters in chars instead.'''
    ...
    def split (sep=None, maxsplit=-1):
      '''Return a list of the substrings in the string, using sep as the separator string.

  sep
    The separator used to split the string.

    When set to None (the default value), will split on any whitespace
    character (including \\n \\r \\t \\f and spaces) and will discard
    empty strings from the result.
  maxsplit
    Maximum number of splits (starting from the left).
    -1 (the default value) means no limit.

Note, str.split() is mainly useful for data that has been intentionally
delimited.  With natural text that includes punctuation, consider using
the regular expression module.'''
    ...
    def splitlines (keepends=False):
      '''Return a list of the lines in the string, breaking at line boundaries.

Line breaks are not included in the resulting list unless keepends is given and
true.'''
    ...
    def startswith (self, *args, **kwargs):
      '''S.startswith(prefix[, start[, end]]) -> bool

Return True if S starts with the specified prefix, False otherwise.
With optional start, test S beginning at that position.
With optional end, stop comparing S at that position.
prefix can also be a tuple of strings to try.'''
    ...
    def strip (chars=None, /):
      '''Return a copy of the string with leading and trailing whitespace removed.

If chars is given and not None, remove characters in chars instead.'''
    ...
    def swapcase ():
      '''Convert uppercase characters to lowercase and lowercase characters to uppercase.'''
    ...
    def title ():
      '''Return a version of the string where each word is titlecased.

More specifically, words start with uppercased characters and all remaining
cased characters have lower case.'''
    ...
    def translate (table, /):
      '''Replace each character in the string using the given translation table.

  table
    Translation table, which must be a mapping of Unicode ordinals to
    Unicode ordinals, strings, or None.

The table must implement lookup/indexing via __getitem__, for instance a
dictionary or list.  If this operation raises LookupError, the character is
left untouched.  Characters mapped to None are deleted.'''
    ...
    def upper ():
      '''Return a copy of the string converted to uppercase.'''
    ...
    def zfill (width, /):
      '''Pad a numeric string with zeros on the left, to fill a field of the given width.

The string is never truncated.'''
    ...
    def _cached (self, *args, **kwargs):
      '''None'''
    ...
    def _initializing (self, *args, **kwargs):
      '''bool(x) -> bool

Returns True when the argument x is true, False otherwise.
The builtins True and False are the only two instances of the class bool.
The class bool is a subclass of the class int, and cannot be subclassed.'''
    ...
    def _set_fileattr (self, *args, **kwargs):
      '''bool(x) -> bool

Returns True when the argument x is true, False otherwise.
The builtins True and False are the only two instances of the class bool.
The class bool is a subclass of the class int, and cannot be subclassed.'''
    ...
    def cached (self, *args, **kwargs):
      '''None'''
    ...
    def has_location (self, *args, **kwargs):
      '''bool(x) -> bool

Returns True when the argument x is true, False otherwise.
The builtins True and False are the only two instances of the class bool.
The class bool is a subclass of the class int, and cannot be subclassed.'''
    ...
    def loader ():
      '''Meta path import for built-in modules.

    All methods are either class or static methods to avoid the need to
    instantiate the class.

    '''
    ...
    def loader_state (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def origin (self, *args, **kwargs):
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
    def parent (self, *args, **kwargs):
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
    def submodule_search_locations (self, *args, **kwargs):
      '''None'''
    ...
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def k2000_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2000_xml (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2004_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2007_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2010_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2013_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Standard (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_Template (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def k2018_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kNative (self, *args, **kwargs):
      '''None'''
    ...
    def kNative_Template (self, *args, **kwargs):
      '''None'''
    ...
    def kR12_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR13_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dwg (self, *args, **kwargs):
      '''None'''
    ...
    def kR14_dxf (self, *args, **kwargs):
      '''None'''
    ...
    def kUnknown (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
    def as_integer_ratio ():
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
    def bit_count ():
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length ():
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
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
    def imag (self, *args, **kwargs):
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
    def kAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kNotLocked (self, *args, **kwargs):
      '''None'''
    ...
    def kProtectedAutoWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kRead (self, *args, **kwargs):
      '''None'''
    ...
    def kWrite (self, *args, **kwargs):
      '''None'''
    ...
    def kXWrite (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
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
    def names (self, *args, **kwargs):
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
    def numerator (self, *args, **kwargs):
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
    def real (self, *args, **kwargs):
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
    def to_bytes (length, byteorder, *, signed=False):
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
    def values (self, *args, **kwargs):
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
