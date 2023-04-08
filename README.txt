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
