
function Printf:
    def Printf (self, *args, **kwargs):
      '''Wraps acutPrintf 
Sends a string to the command line'''
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
