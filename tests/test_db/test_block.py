from __future__ import annotations

import collections.abc as c
import re
import typing as t
from datetime import datetime
from pathlib import Path
from unittest.mock import MagicMock, patch

import pytest

from pyrx import Db, Ge
from pyrx.db.block import (
    BlockAlreadyExistsError,
    BlockNotFoundError,
    add_block_definition,
    get_block_by_name,
    get_block_reference,
)

if t.TYPE_CHECKING:
    from unittest.mock import MagicMock
    
    
pytest.skip(allow_module_level=True)

@pytest.fixture
def db_with_block() -> Db.Database:
    db = Db.Database()
    bt = Db.BlockTable(db.blockTableId(), Db.OpenMode.kForWrite)
    btr = Db.BlockTableRecord()
    btr.setName("TestBlock")
    bt.add(btr)
    assert bt.has("TestBlock")
    return db


@pytest.fixture
def temp_block_dwg(tmp_path: Path) -> c.Generator[tuple[Path, MagicMock], None, None]:
    """Create a temporary DWG file with a block definition."""
    block_path = tmp_path / "TestBlock.dwg"
    block_db = Db.Database()
    block_db.addToModelspace(Db.Line())
    block_db.saveAs(str(block_path))
    with patch("pyrx.db.block.Ed.Core.findFile") as mock_find_file:
        mock_find_file.return_value = str(block_path)
        yield block_path, mock_find_file


@pytest.fixture
def temp_block_dxf(tmp_path: Path) -> c.Generator[tuple[Path, MagicMock], None, None]:
    """Create a temporary DXF file with a block definition."""
    block_path = tmp_path / "TestBlock.dxf"
    block_db = Db.Database()
    block_db.addToModelspace(Db.Line())
    block_db.dxfOut(str(block_path))
    with patch("pyrx.db.block.Ed.Core.findFile") as mock_find_file:
        mock_find_file.return_value = str(block_path)
        yield block_path, mock_find_file


class Test_add_block_definition:
    def test_skip_if_exists(self, db_with_block: Db.Database):
        """Test that existing block is skipped when if_exists='skip'."""
        btr_id = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
        btr = Db.BlockTableRecord(btr_id)
        try:
            assert btr.name() == "TestBlock"
            assert not btr.objectIds()
        finally:
            btr.dispose()

        res = add_block_definition("TestBlock", if_exists="skip", db=db_with_block)
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
        db_with_block: Db.Database,
        temp_block_dwg: tuple[Path, MagicMock],
    ):
        """Test that existing block is replaced when if_exists='replace'."""
        btr_id = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
        base_btr = Db.BlockTableRecord(btr_id)
        try:
            assert base_btr.name() == "TestBlock"
            assert not base_btr.objectIds()  # Original block is empty
        finally:
            base_btr.dispose()

        res = add_block_definition("TestBlock", if_exists="replace", db=db_with_block)
        assert isinstance(res, Db.ObjectId)

        new_btr = Db.BlockTableRecord(res)
        try:
            assert len(new_btr.objectIds()) == 1  # Replaced block has content
            assert new_btr.name() == "TestBlock"
        finally:
            new_btr.dispose()

    def test_error_if_exists(self, db_with_block: Db.Database):
        """Test that exception is raised when block exists and if_exists='raise'."""
        btr_id = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
        btr = Db.BlockTableRecord(btr_id)
        try:
            assert not btr.objectIds()
        finally:
            btr.dispose()

        with pytest.raises(
            BlockAlreadyExistsError, match=re.escape("Block definition 'TestBlock' already exists")
        ):
            add_block_definition("TestBlock", if_exists="raise", db=db_with_block)

        # Ensure the original block is still there and unchanged
        btr_id_2 = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
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

    def test_file_not_found(self, db_with_block: Db.Database):
        """Test that FileNotFoundError is raised when block file is not found."""
        with patch("pyrx.db.block.Ed.Core.findFile") as mock_find_file:
            mock_find_file.return_value = ""
            with pytest.raises(
                FileNotFoundError,
                match=re.escape("Block file 'MissingBlock.dwg' not found in search paths"),
            ):
                add_block_definition("MissingBlock", db=db_with_block)


class Test_get_block_by_name:
    def test_returns_existing_block(self, db_with_block: Db.Database):
        btr_id = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
        assert get_block_by_name("TestBlock", db=db_with_block) == btr_id

    def test_adds_block_if_not_exists(self, temp_block_dwg: tuple[Path, MagicMock]):
        db = Db.Database()
        btr_id = get_block_by_name("TestBlock", db=db)
        assert isinstance(btr_id, Db.ObjectId)
        btr = Db.BlockTableRecord(btr_id)
        assert btr.name() == "TestBlock"
        assert len(btr.objectIds()) == 1

    def test_raises_if_not_exists_and_must_exists(self):
        db = Db.Database()
        with pytest.raises(BlockNotFoundError, match="Block definition 'DoesNotExist' not found"):
            get_block_by_name("DoesNotExist", must_exists=True, db=db)

    def test_raises_if_file_not_found(self, db_with_block: Db.Database):
        db = Db.Database()
        with patch("pyrx.db.block.add_block_definition") as mock_add_block_definition:
            mock_add_block_definition.side_effect = FileNotFoundError
            with pytest.raises(
                BlockNotFoundError, match="Block definition 'MissingBlock' not found"
            ):
                get_block_by_name("MissingBlock", db=db)


class Test_get_block_reference:
    def test_get_block_reference_by_name(self, db_with_block: Db.Database):
        btr_id = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
        res = get_block_reference("TestBlock", db=db_with_block)
        assert isinstance(res, Db.ObjectId)
        bref = Db.BlockReference(res)
        assert bref.blockTableRecord() == btr_id
        assert bref.getBlockName() == "TestBlock"

    def test_get_block_reference_by_id(self, db_with_block: Db.Database):
        btr_id = Db.BlockTable(db_with_block.blockTableId()).getAt("TestBlock")
        res = get_block_reference(btr_id, db=db_with_block)
        assert isinstance(res, Db.ObjectId)
        bref = Db.BlockReference(res)
        assert bref.blockTableRecord() == btr_id
        assert bref.getBlockName() == "TestBlock"

    def test_raises_if_block_not_found(self, db_with_block: Db.Database):
        with pytest.raises(BlockNotFoundError, match="Block definition 'MissingBlock' not found"):
            get_block_reference("MissingBlock", db=db_with_block)

    def test_position_rotation_scale(self, db_with_block: Db.Database):
        bref_id = get_block_reference(
            "TestBlock", db=db_with_block, position=(10, 20, 30), rotation=1.57, scale=2
        )
        bref = Db.BlockReference(bref_id)
        assert bref.position() == Ge.Point3d(10, 20, 30)
        assert bref.rotation() == 1.57
        assert bref.scaleFactors() == Ge.Scale3d(2, 2, 2)

    def test_invalid_btr_id_or_name(self):
        with pytest.raises(
            TypeError, match="btr_id_or_name must be a string or Db.ObjectId, not int"
        ):
            get_block_reference(123)

    def test_scale_dyn_properties_with_non_uniform_scale(self, db_with_block: Db.Database):
        with pytest.raises(ValueError, match="scale_dyn_properties requires uniform scale"):
            get_block_reference(
                "TestBlock", db=db_with_block, scale=Ge.Scale3d(2, 3, 4), scale_dyn_properties=True
            )

    def test_transaction_success(self, db_with_block: Db.Database):
        obj_ids_before = db_with_block.objectIds(Db.BlockReference.desc())
        get_block_reference("TestBlock", db=db_with_block)
        obj_ids_after = db_with_block.objectIds(Db.BlockReference.desc())
        assert len(obj_ids_after) == len(obj_ids_before) + 1

    def test_transaction_error(self, db_with_block: Db.Database):
        obj_ids_before = db_with_block.objectIds(Db.BlockReference.desc())
        with patch.object(Db.BlockTableRecord, "hasAttributeDefinitions") as mock_btr:
            mock_btr.side_effect = Exception("Simulated error")
            with pytest.raises(Exception, match="Simulated error"):
                get_block_reference("TestBlock", db=db_with_block)
        obj_ids_after = db_with_block.objectIds(Db.BlockReference.desc())
        assert len(obj_ids_after) == len(obj_ids_before)

    def test_complex(self, db_dyn_block_ref: Db.Database):
        bref_id = get_block_reference(
            "TEST DYN BLOCK REF",
            position=(10, 20, 30),
            rotation=1.57,
            scale=2,
            attributes={
                "ATTR_1": "Value 1",
            },
            dyn_properties={
                "Distance1": 200.0,  # should be scaled to 400.0
                "Distance2": 300.0,  # should be scaled to 600.0
                "Angle1": Db.EvalVariant(1.0),  # should be 1
                "Visibility1": "VisibilityState1",
            },
            scale_dyn_properties=True,
            db=db_dyn_block_ref,
        )
        bref = Db.BlockReference(bref_id)

        assert bref.position() == Ge.Point3d(10, 20, 30)
        assert bref.rotation() == 1.57
        assert bref.scaleFactors() == Ge.Scale3d(2, 2, 2)
        assert bref.getBlockName() == "TEST DYN BLOCK REF"

        attrs = {
            attr.tag(): attr
            for attr in (Db.AttributeReference(attr_id) for attr_id in bref.attributeIds())
        }
        assert len(attrs) == 4  # ATTR_2 is constant
        assert not set(attrs).symmetric_difference({"ATTR_1", "ATTR_3", "ATTR_4", "ATTR_5"})

        tst = Db.TextStyleTable(db_dyn_block_ref.textStyleTableId())
        tst_standard = tst.getAt("STANDARD")
        tst_1 = tst.getAt("TEXT_STYLE_1")
        tst_2 = tst.getAt("TEXT_STYLE_2")
        tst.dispose()

        attr_1 = attrs["ATTR_1"]
        assert attr_1.textString() == "Value 1"
        assert attr_1.isInvisible() is True
        assert attr_1.isConstant() is False
        assert attr_1.isVerifiable() is False
        assert attr_1.lockPositionInBlock() is False
        assert attr_1.isPreset() is False
        assert attr_1.height() == pytest.approx(11.0, abs=0.01)
        assert attr_1.rotation() == pytest.approx(1.57, abs=0.01)
        assert attr_1.textStyle() == tst_1
        assert attr_1.verticalMode() == Db.TextVertMode.kTextTop
        assert attr_1.horizontalMode() == Db.TextHorzMode.kTextCenter
        assert attr_1.isMTextAttribute() is False

        attr_3 = attrs["ATTR_3"]
        assert attr_3.isInvisible() is False
        assert attr_3.isConstant() is False
        assert attr_3.isVerifiable() is True
        assert attr_3.lockPositionInBlock() is True
        assert attr_3.isPreset() is False
        assert attr_3.height() == pytest.approx(15.0, abs=0.01)
        attr_3_rotation = (
            0.785  # base
            + 1.57  # bref rotation
            + 1.0  # Angle1 rotation
        )
        assert attr_3.rotation() == pytest.approx(attr_3_rotation, abs=0.01)
        assert attr_3.textStyle() == tst_1
        assert attr_3.verticalMode() == Db.TextVertMode.kTextTop
        assert attr_3.horizontalMode() == Db.TextHorzMode.kTextRight
        assert attr_3.isMTextAttribute() is True
        attr_3_mtext = attr_3.getMTextAttribute()
        assert attr_3_mtext.text() == "ATTR\r\n3\r\nvalue"

        attr_4 = attrs["ATTR_4"]
        assert attr_4.isInvisible() is False
        assert attr_4.isConstant() is False
        assert attr_4.isVerifiable() is False
        assert attr_4.lockPositionInBlock() is False
        assert attr_4.isPreset() is True
        assert attr_4.height() == pytest.approx(16.6, abs=0.01)
        assert attr_4.rotation() == pytest.approx(3.14, abs=0.01)
        assert attr_4.textStyle() == tst_2
        assert attr_4.verticalMode() == Db.TextVertMode.kTextBottom
        assert attr_4.horizontalMode() == Db.TextHorzMode.kTextLeft
        assert attr_4.isMTextAttribute() is False
        assert attr_4.textString() == "Block location: 10.0000, 20.0000, 30.0000"

        attr_5 = attrs["ATTR_5"]
        assert attr_5.isInvisible() is False
        assert attr_5.isConstant() is False
        assert attr_5.isVerifiable() is False
        assert attr_5.lockPositionInBlock() is True
        assert attr_5.isPreset() is False
        assert attr_5.height() == pytest.approx(30.0, abs=0.01)
        assert attr_5.rotation() == pytest.approx(1.57, abs=0.01)
        assert attr_5.textStyle() == tst_standard
        assert attr_5.verticalMode() == Db.TextVertMode.kTextVertMid
        assert attr_5.horizontalMode() == Db.TextHorzMode.kTextCenter
        assert attr_5.isMTextAttribute() is True
        attr_5_mtext = attr_5.getMTextAttribute()
        datetime_str = datetime.now().strftime("%Y%m%d")
        expr_value = f"Expr: {datetime_str}"
        assert attr_5_mtext.text().startswith(expr_value)

        bref.dispose()
        dyn_bref = Db.DynBlockReference(bref_id)
        props = {prop.propertyName(): prop for prop in dyn_bref.getBlockProperties()}
        assert len(props) >= 3
        distance_1 = props["Distance1"]
        assert distance_1.value().getDouble() == pytest.approx(400.0, abs=0.01)
        distance_2 = props["Distance2"]
        assert distance_2.value().getDouble() == pytest.approx(600.0, abs=0.01)
        angle_1 = props["Angle1"]
        assert angle_1.value().getDouble() == pytest.approx(1.0, abs=0.01)
        visibility_1 = props["Visibility1"]
        assert visibility_1.value().getString() == "VisibilityState1"
        circle = Db.Circle(db_dyn_block_ref.objectIds(Db.Circle.desc())[0])
        arc = Db.Arc(db_dyn_block_ref.objectIds(Db.Arc.desc())[0])
        assert circle.visibility() == Db.Visibility.kVisible
        assert arc.visibility() == Db.Visibility.kInvisible

    def test_attr_position(self, db_dyn_block_ref: Db.Database):
        bref_id = get_block_reference(
            "SIMPLE_BLOCK",
            position=(10, 20, 30),
            rotation=1.57,
            scale=2,
            dyn_properties={
                "Distance1": 10.0,  # should be scaled to 20.0
            },
            scale_dyn_properties=True,
            db=db_dyn_block_ref,
        )
        bref = Db.BlockReference(bref_id)
        attrs = {
            attr.tag(): attr
            for attr in (Db.AttributeReference(attr_id) for attr_id in bref.attributeIds())
        }
        assert len(attrs) == 1
        attr_1 = attrs["ATTR_1"]
        # att_def position is (0, 0, 0), the attribute is moved by
        # "Distance1" parameter (base length 5.0), the reference
        # insertion point is (10, 20, 30) and the rotation is 90 degrees
        # (relative to the insertion point), therefore the final
        # position of the attribute should be (10, 30, 30)
        assert attr_1.position() == pytest.approx((10, 30, 30), abs=0.01)
