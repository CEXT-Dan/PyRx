from __future__ import annotations

from tests import MEDIA_DIR
from pyrx import Ap

class TestApplication:
    
    def test_loadPythonModule(self):
        moddict = Ap.Application.loadPythonModule(str(MEDIA_DIR/'loadtest.py'))
        assert moddict['GLOBAL_VAL'] == 1
        func = moddict['loadtestfunc']
        assert func() == 'YIPPIE'
         
        dummydict = Ap.Application.loadPythonModule(str(MEDIA_DIR/'submedia/dummy.py'))
        assert dummydict['test253']() == True
        
        
    def test_getPyRxAppDataPath(self):
        path = Ap.Application.getPyRxAppDataPath()
        assert path.find("PyRx") != -1
        assert path.find("Programs") != -1
        assert path.find("Local") != -1
        assert path.find("AppData") != -1
        
        


