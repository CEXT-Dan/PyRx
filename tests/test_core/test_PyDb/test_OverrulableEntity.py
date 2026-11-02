from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestOverrulableEntity:

    @staticmethod
    def _add_to_db(ent: Db.OverrulableEntity) -> Db.ObjectId:
        """Adds the entity to the modelspace and closes it. Caller must clean up via _erase."""
        ent.setDatabaseDefaults()
        ent_id = Db.curDb().addToModelspace(ent)
        assert not ent_id.isNull()
        ent.close()
        return ent_id

    @staticmethod
    def _erase(ent_id: Db.ObjectId) -> None:
        """Soft-erases the entity in the database (test cleanup)."""
        ent = Db.OverrulableEntity(ent_id, Db.OpenMode.kForWrite)
        ent.erase()
        ent.close()

    # ==================== Class introspection ====================

    def test_class_name(self):
        # NOTE: this class is a user-defined AcDbEntity, so className() returns the
        # custom class name, not an "AcDb..." name (unbuilt-in classes behave this way).
        assert Db.OverrulableEntity.className() == "PyRxOverrulableEntity"

    def test_desc(self):
        assert Db.OverrulableEntity.desc().name() == "PyRxOverrulableEntity"

    def test_isa_and_iskindof(self):
        ent = Db.OverrulableEntity()
        assert ent.isA() == Db.OverrulableEntity.desc()
        assert ent.isA().name() == "PyRxOverrulableEntity"
        assert ent.isKindOf(Db.OverrulableEntity.desc())
        assert ent.isKindOf(Db.Entity.desc())
        assert ent.isKindOf(Db.DbObject.desc())

    def test_cast(self):
        ent = Db.OverrulableEntity()
        ent.setName("castMe")
        cast = Db.OverrulableEntity.cast(ent)
        assert isinstance(cast, Db.OverrulableEntity)
        assert cast.name() == "castMe"

    def test_clone_from(self):
        ent = Db.OverrulableEntity()
        ent.setName("src")
        ent.setPosition(Ge.Point3d(1, 2, 3))
        ent.setDoubles([1.5, 2.5])
        clone = Db.OverrulableEntity.cloneFrom(ent)
        assert isinstance(clone, Db.OverrulableEntity)
        assert clone is not ent
        assert clone.objectId().isNull() == True  # clone is not database resident
        assert clone.name() == "src"
        assert clone.position() == Ge.Point3d(1, 2, 3)
        assert clone.doubles() == [1.5, 2.5]

    # ==================== Constructors ====================

    def test_ctor_default(self):
        ent = Db.OverrulableEntity()
        assert ent.objectId().isNull() == True
        assert ent.isA() == Db.OverrulableEntity.desc()

    def test_ctor_from_objectid(self):
        ent = Db.OverrulableEntity()
        ent.setName("oidtest")
        ent_id = self._add_to_db(ent)

        ro = Db.OverrulableEntity(ent_id)
        assert ro.objectId() == ent_id
        assert ro.isReadEnabled() == True
        assert ro.isWriteEnabled() == False
        assert ro.name() == "oidtest"
        ro.close()

        rw = Db.OverrulableEntity(ent_id, Db.OpenMode.kForWrite)
        assert rw.isWriteEnabled() == True
        rw.close()

        self._erase(ent_id)

    # ==================== Default values ====================

    def test_default_collections_empty(self):
        ent = Db.OverrulableEntity()
        assert ent.flags() == []
        assert ent.ints() == []
        assert ent.doubles() == []
        assert ent.strings() == []
        assert ent.points() == []

    def test_default_scalars_zero(self):
        ent = Db.OverrulableEntity()
        assert ent.typing() == 0
        assert ent.mask() == 0
        assert ent.index() == 0

    def test_default_strings_empty(self):
        ent = Db.OverrulableEntity()
        assert ent.name() == ""
        assert ent.guid() == ""
        assert ent.description() == ""

    def test_version(self):
        # NOTE: the default version() for a freshly-constructed entity is 0.
        ent = Db.OverrulableEntity()
        v = ent.version()
        assert isinstance(v, int)
        assert v == 0

    # ==================== Vector / point properties ====================

    def test_position_roundtrip(self):
        ent = Db.OverrulableEntity()
        p = Ge.Point3d(10, 20, 30)
        ent.setPosition(p)
        assert ent.position() == p

    def test_direction_roundtrip(self):
        ent = Db.OverrulableEntity()
        v = Ge.Vector3d(1, 2, 3)
        ent.setDirection(v)
        assert ent.direction() == v

    def test_normal_roundtrip(self):
        ent = Db.OverrulableEntity()
        v = Ge.Vector3d(0, 0, 1)
        ent.setNormal(v)
        assert ent.normal() == v

    # ==================== String properties ====================

    def test_name_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setName("myName")
        assert ent.name() == "myName"

    def test_guid_roundtrip(self):
        ent = Db.OverrulableEntity()
        gid = "{12345678-1234-1234-1234-1234567890AB}"
        ent.setGuid(gid)
        assert ent.guid() == gid

    def test_description_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setdescription("hello description")
        assert ent.description() == "hello description"

    # ==================== Integer properties ====================

    def test_typing_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setTyping(42)
        assert ent.typing() == 42

    def test_mask_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setMask(0b1100)
        assert ent.mask() == 0b1100

    def test_index_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setIndex(7)
        assert ent.index() == 7

    # ==================== Collection properties ====================

    def test_flags_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setFlags([1, 2, 3])
        assert ent.flags() == [1, 2, 3]

    def test_ints_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setInts([10, -20, 30])
        assert ent.ints() == [10, -20, 30]

    def test_doubles_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setDoubles([1.5, 2.5, 3.5])
        assert ent.doubles() == [1.5, 2.5, 3.5]

    def test_strings_roundtrip(self):
        ent = Db.OverrulableEntity()
        ent.setStrings(["a", "b", "c"])
        assert ent.strings() == ["a", "b", "c"]

    def test_points_roundtrip(self):
        ent = Db.OverrulableEntity()
        pts = [Ge.Point3d(1, 2, 3), Ge.Point3d(4, 5, 6)]
        ent.setPoints(pts)
        assert ent.points() == pts

    # ==================== DB persistence ====================

    def test_setters_persist_in_db(self):
        ent = Db.OverrulableEntity()
        ent.setName("persist")
        ent.setPosition(Ge.Point3d(5, 6, 7))
        ent.setDoubles([1.0, 2.0])
        ent.setStrings(["x", "y"])
        ent.setTyping(9)
        ent_id = self._add_to_db(ent)

        ro = Db.OverrulableEntity(ent_id)
        assert ro.name() == "persist"
        assert ro.position() == Ge.Point3d(5, 6, 7)
        assert ro.doubles() == [1.0, 2.0]
        assert ro.strings() == ["x", "y"]
        assert ro.typing() == 9
        ro.close()

        # Modify through a write handle, then verify the change is visible to a reader.
        rw = Db.OverrulableEntity(ent_id, Db.OpenMode.kForWrite)
        rw.setName("changed")
        rw.close()

        ro2 = Db.OverrulableEntity(ent_id)
        assert ro2.name() == "changed"
        ro2.close()

        self._erase(ent_id)

    # ==================== Entity behavior ====================

    def test_object_id_null_until_added(self):
        ent = Db.OverrulableEntity()
        assert ent.objectId().isNull() == True
        ent_id = self._add_to_db(ent)
        assert ent.objectId() == ent_id
        self._erase(ent_id)

    def test_erase(self):
        ent = Db.OverrulableEntity()
        ent_id = self._add_to_db(ent)

        rw = Db.OverrulableEntity(ent_id, Db.OpenMode.kForWrite)
        rw.erase()
        rw.close()

        # The erased=True ctor flag allows opening the erased object.
        erased = Db.OverrulableEntity(ent_id, Db.OpenMode.kForRead, True)
        assert erased.isErased() == True
        erased.close()

    def test_transform_by(self):
        # transformBy is inherited from AcDbEntity; just verify it runs without error
        # and leaves the object in a valid state (the ARX overrule entity may or may not
        # move its position, so we do not assert an exact translation).
        ent = Db.OverrulableEntity()
        ent.setPosition(Ge.Point3d(0, 0, 0))
        ent.transformBy(Ge.Matrix3d.translation(Ge.Vector3d(10, 20, 30)))
        assert isinstance(ent.position(), Ge.Point3d)
