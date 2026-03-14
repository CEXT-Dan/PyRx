from __future__ import annotations

import pytest

from pyrx import Cv, Db, Bim


@pytest.mark.known_failure_IRX
@pytest.mark.known_failure_ARX
@pytest.mark.known_failure_GRX
@pytest.mark.known_failure_ZRX
class TestBCadBim:

    def test_allObjectBuildings(self, db_bim_main: Db.Database):
        buldings = Bim.BimBuilding.allObjectBuildings(db_bim_main)
        assert len(buldings) != 0
        assert isinstance(buldings[0], Bim.BimBuilding)


       