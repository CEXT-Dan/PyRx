    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
    ...
    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
    ...
    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
    ...
    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
    ...
    def __add__ (value, /):
      '''Return self+value.'''
    ...
    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (value, /):
      '''Return self*value.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
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
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
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
    def __add__ (value, /):
      '''Return self+value.'''
    ...
    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (value, /):
      '''Return self*value.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
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
    def __add__ (value, /):
      '''Return self+value.'''
    ...
    def __eq__ (value, /):
      '''Return self==value.'''
    ...
    def __init__ (*args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (value, /):
      '''Return self*value.'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
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
    def __eq__ (other):
      '''None'''
    ...
    def __init__ (name, loader, *, origin=None, loader_state=None, is_package=None):
      '''None'''
    ...
    def __ne__ (value, /):
      '''Return self!=value.'''
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
