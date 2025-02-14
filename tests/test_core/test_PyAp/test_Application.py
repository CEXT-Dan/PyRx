from __future__ import annotations

from tests import MEDIA_DIR
from pyrx import Ap

class TestApplication:
    
    def test_loadPythonModule(self):
        moddict = Ap.Application.loadPythonModule(str(MEDIA_DIR/'loadtest.py'))
        assert moddict['GLOBAL_VAL'] == 1
        func = moddict['loadtestfunc']
        assert func() == 'YIPPIE'
        
