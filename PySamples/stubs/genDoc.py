import os
import inspect

import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

# just some ideas on getting help, work in progress       
def generate_doc(moduleName, module):
    with open(moduleName, 'w') as f:
        for name, obj in inspect.getmembers(module):
            if inspect.isclass(obj):
                f.write('\n')
                f.write(f'class {name}:\n')

            for func_name, func in inspect.getmembers(obj):
                if not func_name.startswith('__'):
                    try:
                        f.write(f'    def {func_name} {inspect.signature(func)}:\n')
                    except:
                        f.write(f'    def {func_name} (self, *args, **kwargs):\n')
                    f.write(f"      '''{func.__doc__}'''")
                    f.write('\n    ...\n')

def PyRxCmd_pygendocs():
    generate_doc('PyRxApp.pyi',PyRxApp)
    generate_doc('PyRx.pyi',PyRx)
    generate_doc('PyGe.pyi',PyGe)
    generate_doc('PyGi.pyi',PyGi)
    generate_doc('PyDb.pyi',PyDb)
    generate_doc('PyAp.pyi',PyAp)
    generate_doc('PyEd.pyi',PyEd)
    
