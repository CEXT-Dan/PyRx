
class LispDataType:

class Overrule:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def addOverrule (self, *args, **kwargs):
      '''
addOverrule( (RxClass)arg1, (Overrule)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus addOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def addOverruleLast (self, *args, **kwargs):
      '''
addOverruleLast( (RxClass)arg1, (Overrule)arg2, (bool)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus addOverruleLast(class PyRxClass {lvalue},class PyRxOverrule {lvalue},bool)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def hasOverrule (self, *args, **kwargs):
      '''
hasOverrule( (RxObject)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool hasOverrule(class PyRxObject {lvalue},class PyRxClass {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def isOverruling (self, *args, **kwargs):
      '''
isOverruling() -> bool :

    C++ signature :
        bool isOverruling()'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def removeOverrule (self, *args, **kwargs):
      '''
removeOverrule( (RxClass)arg1, (Overrule)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus removeOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def setIsOverruling (self, *args, **kwargs):
      '''
setIsOverruling( (bool)arg1) -> None :

    C++ signature :
        void setIsOverruling(bool)'''
    ...

class RxClass:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isDerivedFrom (self, *args, **kwargs):
      '''
isDerivedFrom( (RxClass)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool isDerivedFrom(class PyRxClass {lvalue},class PyRxClass)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def name (self, *args, **kwargs):
      '''
name( (RxClass)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > name(class PyRxClass {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...

class RxObject:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
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
    def __class__ (self, *args, **kwargs):
      '''type(object) -> the object's type
type(name, bases, dict, **kwds) -> a new type'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
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
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, /):
      '''Helper for pickle.'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''list of weak references to the object (if defined)'''
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

class stderr:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def flush (self, *args, **kwargs):
      '''
flush( (stderr)arg1) -> None :

    C++ signature :
        void flush(class py_redirector<2> {lvalue})'''
    ...
    def write (self, *args, **kwargs):
      '''
write( (stderr)arg1, (str)arg2) -> None :

    C++ signature :
        void write(class py_redirector<2> {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...

class stdout:
    def __class__ (self, *args, **kwargs):
      '''None'''
    ...
    def __delattr__ (self, name, /):
      '''Implement delattr(self, name).'''
    ...
    def __dict__ (self, *args, **kwargs):
      '''None'''
    ...
    def __dir__ (self, /):
      '''Default dir() implementation.'''
    ...
    def __doc__ (self, *args, **kwargs):
      '''None'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __format__ (self, format_spec, /):
      '''Default object formatter.'''
    ...
    def __ge__ (self, value, /):
      '''Return self>=value.'''
    ...
    def __getattribute__ (self, name, /):
      '''Return getattr(self, name).'''
    ...
    def __gt__ (self, value, /):
      '''Return self>value.'''
    ...
    def __hash__ (self, /):
      '''Return hash(self).'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object)'''
    ...
    def __init_subclass__ (self, *args, **kwargs):
      '''This method is called when a class is subclassed.

The default implementation does nothing. It may be
overridden to extend subclasses.
'''
    ...
    def __instance_size__ (self, *args, **kwargs):
      '''int([x]) -> integer
int(x, base=10) -> integer

Convert a number or string to an integer, or return 0 if no arguments
are given.  If x is a number, return x.__int__().  For floating point
numbers, this truncates towards zero.

If x is not a number or if base is given, then x must be a string,
bytes, or bytearray instance representing an integer literal in the
given base.  The literal can be preceded by '+' or '-' and be surrounded
by whitespace.  The base defaults to 10.  Valid bases are 0 and 2-36.
Base 0 means to interpret the base from the string as an integer literal.
>>> int('0b100', base=0)
4'''
    ...
    def __le__ (self, value, /):
      '''Return self<=value.'''
    ...
    def __lt__ (self, value, /):
      '''Return self<value.'''
    ...
    def __module__ (self, *args, **kwargs):
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
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __new__ (*args, **kwargs):
      '''Create and return a new object.  See help(type) for accurate signature.'''
    ...
    def __reduce__ (self, *args, **kwargs):
      '''None'''
    ...
    def __reduce_ex__ (self, protocol, /):
      '''Helper for pickle.'''
    ...
    def __repr__ (self, /):
      '''Return repr(self).'''
    ...
    def __setattr__ (self, name, value, /):
      '''Implement setattr(self, name, value).'''
    ...
    def __sizeof__ (self, /):
      '''Size of object in memory, in bytes.'''
    ...
    def __str__ (self, /):
      '''Return str(self).'''
    ...
    def __subclasshook__ (self, *args, **kwargs):
      '''Abstract classes can override this to customize issubclass().

This is invoked early on by abc.ABCMeta.__subclasscheck__().
It should return True, False or NotImplemented.  If it returns
NotImplemented, the normal algorithm is used.  Otherwise, it
overrides the normal algorithm (and the outcome is cached).
'''
    ...
    def __weakref__ (self, *args, **kwargs):
      '''None'''
    ...
    def flush (self, *args, **kwargs):
      '''
flush( (stdout)arg1) -> None :

    C++ signature :
        void flush(class py_redirector<1> {lvalue})'''
    ...
    def write (self, *args, **kwargs):
      '''
write( (stdout)arg1, (str)arg2) -> None :

    C++ signature :
        void write(class py_redirector<1> {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
