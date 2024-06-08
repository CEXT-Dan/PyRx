import inspect
import pydoc
import traceback
import json

import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyGs  # = editor
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor
import PyPl  # = plot

#! move along nothing to see here
#! its smells like code smell, like, victory!

if  "BRX" in  PyAp.Application.hostAPI():
    import PyBrxCv
      
# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

class_types = {}

all_modules = [("PyRx", PyRx), ("PyGe", PyGe), ("PyGi", PyGi),("PyGs", PyGs), 
               ("PyDb", PyDb), ("PyAp", PyAp), ("PyEd", PyEd), ("PyPl", PyPl)]

all_modules_names = ["PyRx", "PyGe", "PyGi", "PyGs", "PyDb", "PyAp", "PyEd", "PyPl"]

#add brx modules only 
if  "BRX" in  PyAp.Application.hostAPI():
    all_modules.append(("PyBrxCv", PyBrxCv))
    all_modules_names.append("PyBrxCv")

# TODO iterate all the above modules, and add imports ant type aliasing
# to each

# just some ideas on getting stubs and help, work in progress

def include_attr(name) -> bool:
    try:
        if name == '__init__':
            return True
        elif name ==  '__mul__':
            return True
        elif name ==  '__imul__':
            return True
        elif name ==  '__rmul__':
            return True
        elif name ==  '__truediv__':
            return True
        elif name ==  '__itruediv__':
            return True
        elif name ==  '__add__':
            return True
        elif name ==  '__sub__':
            return True
        elif name ==  '__isub__':
            return True
        elif name ==  '__getitem__':
            return True
        elif name ==  '__setitem__':
            return True
        elif name.startswith('__'):
            return False
        elif name == 'names':
            return False
        elif name == 'values': #these emit a ton of junk with enums
            return False
        elif name == 'as_integer_ratio':
            return False
        elif name == 'bit_count':
            return False
        elif name == 'bit_length':
            return False
        elif name == 'to_bytes':
            return False
        elif name == 'from_bytes':
            return False
        elif name == 'conjugate':
            return False
        elif name == 'denominator':
            return False
        elif name == 'numerator':
            return False
        elif name == 'real':
            return False
        elif name == 'imag':
            return False
        elif name == 'is_integer':
            return False
        return True
    except:
        return True

def removeArgStr(sig):
    try:
        argb = sig.find('![(')
        arge = sig.find(')]!')
        if argb != -1:
            argstr = sig[argb:arge+3]
            newDocString = sig.replace(argstr, "")
            return newDocString.strip('\n')
        return sig.strip('\n')
    except:
        return sig


def findArgs(sig):
    try:
        argb = sig.find('![(')
        arge = sig.find(')]!')
        if argb != -1:
            return sig[argb+2:arge+1]
        return ""
    except:
        return ""
    
def findDocStringKey(sig):
    try:
        argb = sig.find('<[{')
        arge = sig.find('}]>')
        if argb != -1:
            return sig[argb+3:arge]
        return "-1"
    except:
        return "-1"
    
def lookupDocString(docstringkey, conn):
    try:
        key = int(docstringkey)
        if key in conn:
            ds = conn[key]
            if len(ds) != 0:
                return ds.replace(u'\xa0', u'')#oops
        return ''
    except:
        return ''

def findOverload(sig):
    argb = sig.find('<[(')
    arge = sig.find(')]>')
    if argb != -1:
        return "{}".format(sig[argb+3:arge])
    return None

def parseOverLoads(overstr : str):
    res = []
    if overstr is None:
        return res
    if not '-' in overstr:
        return res
    overloads = [s.strip() for s in overstr.split('-')]
    for overload in overloads[1:]:#skip the description
        if len(overload):
            if 'None:' in overload:
                res.append('(self, /)'.format(overload))
            else:
                res.append('(self, {})'.format(overload))
        else:
            res.append('(self)')
    return res

def parseStaticOverLoads(overstr : str):
    res = []
    if overstr is None:
        return res
    if not '-' in overstr:
        return res
    overloads = [s.strip() for s in overstr.split('-')]
    for overload in overloads[1:]:#skip the description
        if len(overload):
            if 'None:' in overload:
                res.append('(/)'.format(overload))
            else:
                res.append('({})'.format(overload))
        else:
            res.append('()')
    return res

def findOverloadAsComment(sig, docstring):
    try:
        argb = sig.find('<[(')
        arge = sig.find(')]>')
        if argb != -1:
            if len(docstring) != 0:
                return "      '''{}\n\t-{}-'''".format(sig[argb+3:arge],docstring)
            else:
                return "      '''{}'''".format(sig[argb+3:arge])
        return "      '''                             '''"
    except:
        return "      '''                             '''"

def findReturnTypeModlue(sig):
    if sig in class_types:
        return class_types[sig]+"."+sig
    else:
        return sig
    
def resolverParseSig(sig: str) -> None:
    endsig = sig.find("(")
    return sig[0:endsig].strip()

# I don't want to write for every derived sig like xData, getGripPoints
# see if there's conflits with this
def tryResolveTupleType(moduleName: str, className: str, sig: str,rtTypes) -> str | None:
    psig = "{}::{}::{}".format(moduleName,className, resolverParseSig(sig))
    if psig in rtTypes:
        return rtTypes[psig]
    
    psig = "{}::{}".format(moduleName,resolverParseSig(sig))
    if psig in rtTypes:
        return rtTypes[psig]
    
    psig = "{}".format(resolverParseSig(sig))
    if psig in rtTypes:
        return rtTypes[psig]
    
    print("{}::{}::{}".format(moduleName,className, resolverParseSig(sig)))
    return "tuple[Any,...]"

def tryResolveListType(moduleName: str,className: str, sig: str,rtTypes) -> str | None:
    
    psig = "{}::{}::{}".format(moduleName,className, resolverParseSig(sig))
    if psig in rtTypes:
        return rtTypes[psig]
    
    psig = "{}::{}".format(moduleName,resolverParseSig(sig))
    if psig in rtTypes:
        return rtTypes[psig]
    
    psig = "{}".format(resolverParseSig(sig))
    if psig in rtTypes:
        return rtTypes[psig]
    
    print("{}::{}::{}".format(moduleName,className, resolverParseSig(sig)))
    return "list"

def findReturnType(moduleName,name,sig,rtTypes):
    try:
        mName = moduleName[0:4]
        ib = sig.find('->')
        ie = sig.find(':')
        if ib != -1:
            rtType = findReturnTypeModlue(sig[ib+2:ie].strip())
            #Type hinting work around for tuples #63 
            if rtType == 'tuple':
                return '-> ' + tryResolveTupleType(mName,name,sig,rtTypes)
            elif rtType == 'list':
                 return '-> ' + tryResolveListType(mName,name,sig,rtTypes)
            
            return '-> ' + rtType
        return "-> None"
    except:
        return "-> None"
    
def buildClassDict(moduleName, module):
    for name, obj in inspect.getmembers(module):
        if inspect.isclass(obj):
            class_types[name] = moduleName
            
def isStatic(ags : str) -> bool:
    try:
        return 'self' not in str(ags)
    except:
        return False
    
# todo: boost generates a doc string that has the function signature
# it should be able to parse this, or add something in the doc user string
def generate_pyi(moduleName, module, dsdict,rtTypes):
    with open(moduleName, 'w') as f:
        
        #write the base module names to the stub file
        for mname in all_modules_names:
            f.write(f'import {mname}\n')
        f.write('from typing import overload\n')
        f.write('from typing import Any\n')

        for name, obj in inspect.getmembers(module):
            if inspect.isclass(obj):
                if name == '__loader__':
                    continue
                f.write('\n')
                
                basesname = ''
                objbases = obj.__bases__
                if len(objbases):
                    if objbases[0].__module__ == module.__name__:#no circular reference
                        basesname = "{}".format(objbases[0].__name__)
                    else:
                        basesname = "{}.{}".format(objbases[0].__module__,objbases[0].__name__)
                    if 'Boost' in basesname:
                        basesname = ''
                        
                if len(basesname):
                    f.write(f'class {name}({basesname}):\n')
                else:
                    f.write(f'class {name}(object):\n')
                
                for func_name, func in inspect.getmembers(obj):
                    if include_attr(func_name):
                        sig = "{0}".format(func.__doc__)
                        
                        args = findArgs(sig)
                        returnType = findReturnType(moduleName,name,sig,rtTypes)
                        newDocString = removeArgStr(sig)
                        
                        docstringkey = findDocStringKey(sig)
                        docstring = lookupDocString(docstringkey, dsdict)
                        overloadAsComment = findOverloadAsComment(sig,docstring)
        
                        try:
                            f.write(f'    def {func_name} {inspect.signature(func)} :\n')
                            f.write(f"      '''{newDocString}'''")
                        except:
                            if len(args) != 0:
                                
                                if isStatic(args):
                                    overloads = parseStaticOverLoads(findOverload(sig))
                                    if len(overloads):
                                        for overload in overloads:
                                            overload = overload.strip(',')
                                            f.write('\n    @overload')
                                            f.write('\n    @staticmethod\n')
                                            f.write(f'    def {func_name} {overload}{returnType} : ...')
                                            
                                        f.write('\n    @staticmethod')
                                        f.write(f'\n    def {func_name} (self, *args, **kwargs){returnType} :\n')
                                        f.write(overloadAsComment)
                                        f.write('\n    ...\n')
                                        continue
                                    else:
                                        f.write('\n    @staticmethod\n')

                                else:  
                                    overloads = parseOverLoads(findOverload(sig))
                                    if len(overloads):
                                        for overload in overloads:
                                            overload = overload.strip(',')
                                            f.write('\n    @overload\n')
                                            f.write(f'    def {func_name} {overload}{returnType} : ...')
                                        f.write(f'\n    def {func_name} (self, *args, **kwargs){returnType} :\n')
                                        f.write(overloadAsComment)
                                        f.write('\n    ...\n')
                                        continue
                                            
                                args = args.strip(',')
                                f.write(f'    def {func_name} {args}{returnType} :\n')
                                if len(docstring):
                                    f.write(f"      '''{docstring}'''")
                                else:
                                    f.write(overloadAsComment)
                            else:
                                f.write(f'    def {func_name} (self, *args, **kwargs){returnType} :\n')
                                f.write(f"      '''{newDocString}'''")

                        f.write('\n    ...\n')

            elif inspect.isbuiltin(obj):
                f.write('\n')
                # f.write(f'function {name}:\n')
                try:
                    sig = "{0}".format(obj.__doc__)
                    returnType = findReturnType(moduleName,name,sig,rtTypes)
                    newDocString = removeArgStr(sig)
                    f.write(f'def {name} (*args, **kwargs){returnType} :\n')
                    f.write(f"    '''{newDocString}'''")
                    f.write('\n    ...\n')
                except Exception as err:
                    print(err)

def generate_html_help(moduleName, module):
    str = pydoc.html.docmodule(module)
    with open(moduleName, mode='w') as f:
	    print(str, file=f)

def PyRxCmd_pygenpyi():
    try:
        dsdict = {}
        rtTypes = {}
        
        dsPath = "./DocStrings.json"
        with open(dsPath) as json_file:
            data = json.load(json_file)
            rows = data['rows']
            for row in rows:
                dsdict[row[0]] = row[2]
        print(len(dsdict))
        
        reTypesPath = "./ReturnTypes.json"
        with open(reTypesPath) as json_file:
            data = json.load(json_file)
            rows = data['rows']
            for row in rows:
                rtTypes[row[0]] = row[1]
        print(len(rtTypes))
        
        for module in all_modules:
            buildClassDict(module[0], module[1])
        for module in all_modules:
            generate_pyi(module[0] + ".pyi", module[1],dsdict,rtTypes)
    except Exception as err:
        traceback.print_exception(err)

        