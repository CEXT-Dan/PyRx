
from timeit import default_timer as timer

import AxApp24 as Ax

start = timer()
comMat = [[1.0, 0.0, 0.0, 100.0],
          [0.0, 1.0, 0.0, 100.0],
          [0.0, 0.0, 1.0, 0.0],
          [0.0, 0.0, 0.0, 1.0]]

acad = Ax.getApp()
model = acad.ActiveDocument.ModelSpace

for ent in model:
    if ent.ObjectName == "AcDbPoint":
        ent.TransformBy(comMat)
        
end = timer()
print(end - start)
