import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl

class GsManager:
    def __init__ (self: GsManager)-> None :
      '''                             '''
    ...
    def className ()-> str :
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
    def find_module (fullname, path=None) :
      '''Find the built-in module.

        If 'path' is ever specified then the search is considered a failure.

        This method is deprecated.  Use find_spec() instead.

        '''
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
    def module_repr (module) :
      '''Return repr for the module.

        The method is deprecated.  The import machinery does the job itself.

        '''
    ...
