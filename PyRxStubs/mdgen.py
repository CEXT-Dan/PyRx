import traceback
from typing import no_type_check
from pyrx import Ap, Ed, Db

src_path = "../pyrx/"
all_modules = [
    ("PyRx", "PyRx.pyi"),
    ("PyGe", "PyGe.pyi"),
    ("PyGi", "PyGi.pyi"),
    ("PyGs", "PyGs.pyi"),
    ("PyDb", "PyDb.pyi"),
    ("PyAp", "PyAp.pyi"),
    ("PyEd", "PyEd.pyi"),
    ("PyPl", "PyPl.pyi"),
    ("PySm", "PySm.pyi"),
    ("PyBr", "PyBr.pyi"),
    ("PyAx", "PyAx.pyi"),
]


def generate_md(moduleName, moduleFile):
    src_file = "{}{}".format(src_path,moduleFile)
    dst_file = "../Doc/Classes/{}{}".format(moduleName,".md")
    
    ignore = False
    with open(src_file, 'r') as infile:
        with open(dst_file, 'w') as outfile:
            outfile.write('# {}\n'.format(moduleName))
            outfile.write('\n```PY\n')
            for line in infile:
                if '"""' in line:
                    ignore = not ignore
                    continue
                if ignore:
                    continue
                if 'import' in line:
                    continue
                outfile.write(line.replace('...',' '))
            outfile.write('```\n')
                    
                      
@Ap.Command()
def mdgen() -> None:
    try:
        for name, module in all_modules:
            generate_md(name, module)

    except Exception as err:
        traceback.print_exception(err)
