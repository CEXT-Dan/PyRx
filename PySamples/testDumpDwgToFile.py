from timeit import default_timer as timer

from pyrx import Db


def writealltofile(ids):
    f = open("E:/snooparx2.txt", "w")
    pylist = []
    for id in ids:
        o = Db.DbObject(id)
        s = Db.SnoopDwgFiler()
        o.snoop(s)
        pylist.append((o.isA().name(), s.buffer().__str__()))

    pylist.sort(key=lambda x: x[0])
    for item in pylist:
        f.write(item.__str__())
        f.write("\n")
    f.close()


def writetoTypesfile(ids):
    f = open("E:/snooparx2.txt", "w")
    pydict = {}
    for id in ids:
        o = Db.DbObject(id)
        s = o.isA().name()
        if s not in pydict:
            pydict[s] = 0
        else:
            pydict[s] += 1

    for item in sorted(pydict.keys()):
        f.write((item, pydict[item]).__str__())
        f.write("\n")
    f.close()


def PyRxCmd_dodump():
    try:
        start = timer()
        db = Db.Database(False, True)
        db.readDwgFile("M:/Dev/Projects/PyRxGit/unit tests/testmedia/06457.dwg")
        db.closeInput(True)
        ids = db.objectIds()
        writetoTypesfile(ids)
        end = timer()
        print("Number of objects = {}, in {} seconds: ".format(len(ids), end - start))
    except Exception as err:
        print(err)
