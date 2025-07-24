from __future__ import annotations

from pathlib import Path
from pyrx import Db
from pyrx.db.block import add_block_definition, BlockAlreadyExistsError
import re
import pytest
from unittest.mock import patch
import typing as t
import collections.abc as c

if t.TYPE_CHECKING:
    from unittest.mock import MagicMock


class Test_add_block_definition:
    @pytest.fixture
    def db(self) -> Db.Database:
        db = Db.Database()
        bt = Db.BlockTable(db.blockTableId(), Db.OpenMode.kForWrite)
        btr = Db.BlockTableRecord()
        btr.setName("TestBlock")
        bt.add(btr)
        assert bt.has("TestBlock")
        return db

    @pytest.fixture
    def temp_block_dwg(self, tmp_path: Path) -> c.Generator[tuple[Path, MagicMock], None, None]:
        """Create a temporary DWG file with a block definition."""
        block_path = tmp_path / "TestBlock.dwg"
        block_db = Db.Database()
        block_db.addToModelspace(Db.Line())
        block_db.saveAs(str(block_path))
        with patch("pyrx.db.block.Ed.Core.findFile") as mock_find_file:
            mock_find_file.return_value = str(block_path)
            yield block_path, mock_find_file

    @pytest.fixture
    def temp_block_dxf(self, tmp_path: Path) -> c.Generator[tuple[Path, MagicMock], None, None]:
        """Create a temporary DXF file with a block definition."""
        block_path = tmp_path / "TestBlock.dxf"
        block_db = Db.Database()
        block_db.addToModelspace(Db.Line())
        block_db.dxfOut(str(block_path))
        with patch("pyrx.db.block.Ed.Core.findFile") as mock_find_file:
            mock_find_file.return_value = str(block_path)
            yield block_path, mock_find_file

    def test_skip_if_exists(self, db: Db.Database):
        """Test that existing block is skipped when if_exists='skip'."""
        btr_id = Db.BlockTable(db.blockTableId()).getAt("TestBlock")
        btr = Db.BlockTableRecord(btr_id)
        try:
            assert btr.name() == "TestBlock"
            assert not btr.objectIds()
        finally:
            btr.dispose()

        res = add_block_definition("TestBlock", if_exists="skip", db=db)
        assert res == btr_id

        # Verify original block is unchanged (empty)
        btr_result = Db.BlockTableRecord(res)
        try:
            assert btr_result.name() == "TestBlock"
            assert not btr_result.objectIds()
        finally:
            btr_result.dispose()

    def test_replace_if_exists(
        self,
        db: Db.Database,
        temp_block_dwg: tuple[Path, MagicMock],
    ):
        """Test that existing block is replaced when if_exists='replace'."""
        btr_id = Db.BlockTable(db.blockTableId()).getAt("TestBlock")
        base_btr = Db.BlockTableRecord(btr_id)
        try:
            assert base_btr.name() == "TestBlock"
            assert not base_btr.objectIds()  # Original block is empty
        finally:
            base_btr.dispose()

        res = add_block_definition("TestBlock", if_exists="replace", db=db)
        assert isinstance(res, Db.ObjectId)

        new_btr = Db.BlockTableRecord(res)
        try:
            assert len(new_btr.objectIds()) == 1  # Replaced block has content
            assert new_btr.name() == "TestBlock"
        finally:
            new_btr.dispose()

    def test_error_if_exists(self, db: Db.Database):
        """Test that exception is raised when block exists and if_exists='raise'."""
        btr_id = Db.BlockTable(db.blockTableId()).getAt("TestBlock")
        btr = Db.BlockTableRecord(btr_id)
        try:
            assert not btr.objectIds()
        finally:
            btr.dispose()

        with pytest.raises(
            BlockAlreadyExistsError, match=re.escape("Block definition 'TestBlock' already exists")
        ):
            add_block_definition("TestBlock", if_exists="raise", db=db)

        # Ensure the original block is still there and unchanged
        btr_id_2 = Db.BlockTable(db.blockTableId()).getAt("TestBlock")
        btr_2 = Db.BlockTableRecord(btr_id_2)
        try:
            assert not btr_2.objectIds()
        finally:
            btr_2.dispose()

    def test_from_name(self, temp_block_dwg: tuple[Path, MagicMock]):
        """Test adding block definition from file name (searches in paths)."""
        db = Db.Database()
        btr_id = add_block_definition("TestBlock", db=db)
        assert isinstance(btr_id, Db.ObjectId)

        btr = Db.BlockTableRecord(btr_id)
        try:
            assert btr.name() == "TestBlock"
            assert len(btr.objectIds()) == 1
        finally:
            btr.dispose()

    def test_from_rel_path(self, temp_block_dwg: tuple[Path, MagicMock]):
        """Test adding block definition from relative file path."""
        db = Db.Database()
        mock_find_file = temp_block_dwg[1]
        btr_id = add_block_definition("TestBlock.dwg", db=db)
        mock_find_file.assert_called_once_with("TestBlock.dwg")
        assert isinstance(btr_id, Db.ObjectId)

        btr = Db.BlockTableRecord(btr_id)
        try:
            assert btr.name() == "TestBlock"
            assert len(btr.objectIds()) == 1
        finally:
            btr.dispose()

    def test_from_abs_path(self, temp_block_dwg: tuple[Path, MagicMock]):
        """Test adding block definition from absolute file path."""
        db = Db.Database()
        block_dwg, mock_find_file = temp_block_dwg
        btr_id = add_block_definition(str(block_dwg), db=db)
        mock_find_file.assert_not_called()  # Should not search when absolute path is given
        assert isinstance(btr_id, Db.ObjectId)

        btr = Db.BlockTableRecord(btr_id)
        try:
            assert btr.name() == "TestBlock"
            assert len(btr.objectIds()) == 1
        finally:
            btr.dispose()

    def test_from_dxf(self, temp_block_dxf: tuple[Path, MagicMock]):
        """Test adding block definition from DXF file."""
        db = Db.Database()
        _, mock_find_file = temp_block_dxf
        btr_id = add_block_definition("TestBlock.dxf", db=db)
        mock_find_file.assert_called_once_with("TestBlock.dxf")
        assert isinstance(btr_id, Db.ObjectId)

        btr = Db.BlockTableRecord(btr_id)
        try:
            assert btr.name() == "TestBlock"
            assert len(btr.objectIds()) == 1
        finally:
            btr.dispose()

    def test_file_not_found(self, db: Db.Database):
        """Test that FileNotFoundError is raised when block file is not found."""
        with patch("pyrx.db.block.Ed.Core.findFile") as mock_find_file:
            mock_find_file.return_value = ""
            with pytest.raises(
                FileNotFoundError,
                match=re.escape("Block file 'MissingBlock.dwg' not found in search paths"),
            ):
                add_block_definition("MissingBlock", db=db)
