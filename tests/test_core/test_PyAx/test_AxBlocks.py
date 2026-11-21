from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxBlocks:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_add(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin,"testblock")
        assert block.name() == "testblock"
        assert block.objectName() == "AcDbBlockTableRecord"

    def test_add_entity(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_ent")
        circle = block.addCircle(Ge.Point3d.kOrigin, 10)
        assert circle.objectName() == "AcDbCircle"
        assert block.count() == 1
        assert block.entities()[0].objectName() == "AcDbCircle"

    def test_count(self):
        blocks = self.axDoc.blocks()
        count = blocks.count()
        blocks.add(Ge.Point3d.kOrigin, "testblock_count")
        assert blocks.count() == count + 1

    def test_has(self):
        blocks = self.axDoc.blocks()
        blocks.add(Ge.Point3d.kOrigin, "testblock_has")
        assert blocks.has("testblock_has")
        assert not blocks.has("testblock_missing")

    def test_item(self):
        blocks = self.axDoc.blocks()
        count = blocks.count()
        _block = blocks.add(Ge.Point3d.kOrigin, "testblock_item")
        assert blocks.item(count).name() == "testblock_item"
        assert blocks[count].name() == "testblock_item"

    def test_items(self):
        blocks = self.axDoc.blocks()
        items = blocks.items()
        assert len(items) == blocks.count()
        assert all(b.objectName() == "AcDbBlockTableRecord" for b in items)

    def test_blocks(self):
        blocks = self.axDoc.blocks()
        assert len(blocks.blocks()) == blocks.count()

    def test_iter(self):
        blocks = self.axDoc.blocks()
        count = blocks.count()
        names = [b.name() for b in blocks]
        assert len(names) == count

    def test_name(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_name")
        assert block.name() == "testblock_name"
        block.setName("testblock_name2")
        assert block.name() == "testblock_name2"

    def test_origin(self):
        blocks = self.axDoc.blocks()
        pnt = Ge.Point3d(1, 2, 3)
        block = blocks.add(pnt, "testblock_origin")
        assert block.origin() == pnt
        pnt2 = Ge.Point3d(4, 5, 6)
        block.setOrigin(pnt2)
        assert block.origin() == pnt2

    def test_units(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_units")
        block.setUnits(Ax.AcInsertUnits.acInsertUnitsMeters)
        assert block.units() == Ax.AcInsertUnits.acInsertUnitsMeters

    def test_blockScaling(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_scaling")
        block.setBlockScaling(Ax.AcBlockScaling.acUniform)
        assert block.blockScaling() == Ax.AcBlockScaling.acUniform

    def test_comments(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_comments")
        block.setComments("hello")
        assert block.comments() == "hello"

    def test_explodable(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_explodable")
        assert block.isExplodable()
        block.setExplodable(False)
        assert not block.isExplodable()

    def test_flags(self):
        blocks = self.axDoc.blocks()
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_flags")
        assert not block.isDynamicBlock()
        assert not block.isLayout()
        assert not block.isXRef()

    def test_layout(self):
        layout = self.axDoc.modelSpace().layout()
        assert layout.objectName() == "AcDbLayout"
        assert layout.name() == "Model"

    def test_insertBlock(self):
        blocks = self.axDoc.blocks()
        blocks.add(Ge.Point3d.kOrigin, "testblock_ins_target")
        block = blocks.add(Ge.Point3d.kOrigin, "testblock_ins")
        ref = block.insertBlock(
            Ge.Point3d(10, 0, 0), "testblock_ins_target", Ge.Scale3d(1, 1, 1), 0
        )
        assert ref.objectName() == "AcDbBlockReference"
        assert ref.entityType() == Ax.AcEntityName.acBlockReference
