Install python python3.10.10 with PATH checkbox set to true.
https://www.python.org/downloads/release/python-31010/

install wxPython 4.2.0 from https://pypi.org/project/wxPython/
pip install wxPython==4.2.0

Run the PyRxSetup installer
This setup writes two values to the registry, adds wxPython to PATH, adds autocomplete stubs path to PYTHONPATH.
The stub files are for intellisense in Visual studio code

in autocad, run the appload command, navigate to .\Users\XXX\AppData\Local\PyRx
and load the ARX module.

Add to the startup suite to auto load. 
TODO, create a bundle