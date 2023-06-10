import os
import inspect
import io
import pydoc
import enum

import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

# just some ideas on getting help, work in progress

def include_attr(obj, name):
    try:
        str = "{0}".format(obj.__repr__)
        if "enum" in str:
            return False
        return True
    except:
        return True

   
def generate_pyi(moduleName, module):
    with open(moduleName, 'w') as f:

        for name, obj in inspect.getmembers(module):
            if inspect.isclass(obj):
                f.write('\n')
                f.write(f'class {name}:\n')

                for func_name, func in inspect.getmembers(obj):
                    if include_attr(obj,func_name):
                        try:
                            f.write(f'    def {func_name} {inspect.signature(func)}:\n')
                        except:
                            f.write(f'    def {func_name} (self, *args, **kwargs):\n')
                        f.write(f"      '''{func.__doc__}'''")
                        f.write('\n    ...\n')
                        
            elif inspect.isbuiltin(obj):
                f.write('\n')
                f.write(f'function {name}:\n')
                try:
                    f.write(f'    def {name} (self, *args, **kwargs):\n')
                    f.write(f"      '''{obj.__doc__}'''")
                    f.write('\n    ...\n')
                except Exception as err:
                    print(err)

            
            
                
def generate_html_help(moduleName, module):
    str = pydoc.html.docmodule(module)
    with open(moduleName, mode='w') as f:
	    print(str, file=f)
     
def generate_txt_help(moduleName, module):
    doc_content = io.StringIO()
    helper = pydoc.Helper(output=doc_content)
    helper.help(module)
    with open(moduleName, mode='w') as f:
	    print(str, file=f)

                        
def PyRxCmd_pygenpyi():
    generate_pyi('PyRxApp.pyi',PyRxApp)
    generate_pyi('PyRx.pyi',PyRx)
    generate_pyi('PyGe.pyi',PyGe)
    generate_pyi('PyGi.pyi',PyGi)
    generate_pyi('PyDb.pyi',PyDb)
    generate_pyi('PyAp.pyi',PyAp)
    generate_pyi('PyEd.pyi',PyEd)
    
def PyRxCmd_pygenhtmlhelp():
    generate_html_help('PyRxApp.html',PyRxApp)
    generate_html_help('PyRx.html',PyRx)
    generate_html_help('PyGe.html',PyGe)
    generate_html_help('PyGi.html',PyGi)
    generate_html_help('PyDb.html',PyDb)
    generate_html_help('PyAp.html',PyAp)
    generate_html_help('PyEd.html',PyEd)
    
def PyRxCmd_pygentxthelp():
    generate_txt_help('PyRxApp.txt',PyRxApp)
    generate_txt_help('PyRx.txt',PyRx)
    generate_txt_help('PyGe.txt',PyGe)
    generate_txt_help('PyGi.txt',PyGi)
    generate_txt_help('PyDb.txt',PyDb)
    generate_txt_help('PyAp.txt',PyAp)
    generate_txt_help('PyEd.txt',PyEd)

    
