

import importlib.util
if importlib.util.find_spec("PyBrxCv") is not None:
    pass
    
if importlib.util.find_spec("PyBrxBim") is not None:
    pass
    
if importlib.util.find_spec("PyBrx") is not None:
    pass

# this module is to hide Pylance 'module not found' warnings
# Pylance cant read Python embedded in C++
