**not ready, in production**
though COM sould work fine, see the COM samples

adds autocad commands, pyload and pyreload
see the samples on how to create a python based command 

the compiled modules are currently linked with python 3.10.10, 
I have not tested other versions. make sure the PATH is set when 
installing python! appload PyRx24.arx in autocad, then use the pyload
command to load your .py script, functions that are prefixed with PyRxCmd_ or PyRxLisp_
become commands/lisp functions in autocad, 
example def PyRxCmd_pycmd():, or def PyRxLisp_pylisp(args):

Inspiration from 

PyArx by Mick Duprez  
https://www.theswamp.org/index.php?topic=24262

PyAcad by Georg Mischler
https://pyacad.sourceforge.net/

pyautoacad by Roman Haritonov
https://github.com/reclosedev/pyautocad



Naming conventions. 
This project wraps ObjectARX® which is C++, a very large and complex API. in the interest of saving time, 
thin wrappers are generated, expect camel case naming.

Some functions in the C++ API return values by ref,  apparently this isn’t allowed in Python for immutable types. in this case
The wrapper will return by value, and throw a runtime warning into Python on error.

Object names, such as AcDbPolyline are now just Polyline, using import PyDb, the object may be declared as PyDb.Polyline
If removing the prefix caused a invalid name, such as AcDb2dPolyline, the wrapper is named PyDb.Polyline2d

Error handling. The C++ API uses Acad::ErrorStatus for errors, the wrappers also do this except where not possible.
In constructors, and functions the must return by value. Coders should always check the Acad::ErrorStatus.

All containers, such as AcDbObjectIdArray use a list on the python side
