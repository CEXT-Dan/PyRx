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


def PyRxCmd_pydoit(cmdFlags=PyAp.CmdFlags.NOPAPERSPACE):
    try:
        module = inspect.getmodule(PyGe)
        for members_1 in inspect.getmembers(module):
            PyRxApp.Printf("\n{}".format(members_1[0]))
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pydoit2(cmdFlags=PyAp.CmdFlags.TRANSPARENT|PyAp.CmdFlags.NOPAPERSPACE):
    try:
        members = inspect.getmembers(PyGe.Curve2d)
        for x in members:
            PyRxApp.Printf("\n{} ".format(x[0]))
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pydoit3():
    try:
        PyRxApp.Printf(PyGe.Curve2d.__doc__)
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pydoit4():
    try:
        members = inspect.getmembers(PyEd.DragStatus)
        for member in members:
            if not member[0].startswith("__"):
                PyRxApp.Printf("\n{}, {}".format(member[0], member[1].__doc__))
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pydoit5():
    try:
        module = inspect.getmodule(PyDb)
        for members_1 in inspect.getmembers(module):
            PyRxApp.Printf("\n{}\n".format(members_1[0]))
            if inspect.isclass(members_1[1]):
                members_2 = inspect.getmembers(members_1[1])
                for x in members_2:
                    if not x[0].startswith("__"):
                        PyRxApp.Printf("{} ".format(x[1].__doc__))
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pydoit6():
    try:
       print(dir(PyDb))
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pydoit7():
    try:
        print(inspect.signature(PyRxCmd_pydoit))

    except Exception as err:
        PyRxApp.Printf(err)
        
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
    generate_doc('PyRx.pyi',PyRx)
    generate_doc('PyGe.pyi',PyGe)
    generate_doc('PyGi.pyi',PyGi)
    generate_doc('PyDb.pyi',PyDb)
    generate_doc('PyAp.pyi',PyAp)
    generate_doc('PyEd.pyi',PyEd)
    
