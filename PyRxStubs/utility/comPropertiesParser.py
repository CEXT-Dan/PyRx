
with open("M:\\Dev\\Projects\\PyRxGit\\PyRxStubs\\dump.txt", "w") as outFile:
    with open("M:\\Dev\\Projects\\PyRxGit\\PyRxStubs\\GxApp24.py", "r") as inFile:
        inclass = False
        inPropGet = False
        inPropPut = False
        line = inFile.readline()
        while line:
            line = inFile.readline()
            line = line.strip()
            if line.startswith('#'):
                continue
            if line.startswith('class'):
                inclass = True
                outFile.write(line+'\n')
                continue
            if line.startswith('_prop_map_get_'):
                inPropGet = True
                inPropPut = False
                continue
            if line.startswith('_prop_map_put_'):
                inPropGet = False
                inPropPut = True
                continue
            if line.startswith('}'):
                inPropGet = False
                inPropPut = False
                outFile.write('\n')
                continue
            if line.startswith('def __iter__(self):'):
                inPropGet = False
                inPropPut = False
                inclass = False
                continue
            if inPropGet:
                func = line.split(':')[0]
                func = func.strip("\"")
                outFile.write('    @property\n')
                outFile.write('    def {}(self): ...\n'.format(func))
                continue
            if inPropPut:
                func = line.split(':')[0]
                func = func.strip("\"")
                outFile.write('    @{}.setter\n'.format(func))
                outFile.write('    def {}(self, value) -> None: ...\n'.format(func))
                continue
            line = ' '








