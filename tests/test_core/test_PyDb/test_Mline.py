from __future__ import annotations

from pyrx import Db, Ge


class TestDbMline:

    def setup_method(self):
        """Setup method to initialize the database and the Mline with required properties."""
        self.db = Db.curDb()
        self.line = Db.Mline()
        # These are required for the entity to be visible/renderable
        self.line.setNormal(Ge.Vector3d.kZAxis)
        self.line.setStyle(self.db.cmlstyleID())

    def test_create_with_required_properties(self):
        """Test creating a new Mline with required Normal and Style."""
        # Setup is handled in self.setup_method()

        # Verify the line was created
        assert self.line is not None

        # Verify required properties are set
        assert self.line.normal().isEqualTo(Ge.Vector3d.kZAxis)
        assert self.line.style() == self.db.cmlstyleID()

        # Verify default state
        assert self.line.numVertices() == 0
        assert self.line.scale() == 1.0

    def test_append_and_remove_segments(self):
        """Test adding and removing vertices (segments)."""
        # Setup is handled in self.setup_method()

        # Add initial segment
        self.line.appendSeg(Ge.Point3d(0, 0, 0))
        assert self.line.numVertices() == 1

        # Add second segment
        self.line.appendSeg(Ge.Point3d(10, 0, 0))
        assert self.line.numVertices() == 2

        # Remove last segment
        self.line.removeLastSeg(Ge.Point3d(10, 0, 0))
        assert self.line.numVertices() == 1

    def test_modify_properties(self):
        """Test setting and getting properties like Normal, Scale, and Style."""
        # Setup is handled in self.setup_method()

        # Set Scale
        self.line.setScale(2.5)
        assert self.line.scale() == 2.5

        # Set Justification
        self.line.setJustification(Db.MlineJustification.kBottom)
        assert self.line.justification() == Db.MlineJustification.kBottom

    def test_closed_state(self):
        """Test closing and opening the Mline."""
        # Setup is handled in self.setup_method()

        self.line.appendSeg(Ge.Point3d(0, 0, 0))
        self.line.appendSeg(Ge.Point3d(10, 0, 0))
        self.line.appendSeg(Ge.Point3d(10, 10, 0))

        # Initially open
        assert self.line.closedMline() == False

        # Close the line
        self.line.setClosedMline(True)
        assert self.line.closedMline() == True

        # Open the line again
        self.line.setClosedMline(False)
        assert self.line.closedMline() == False

    def test_supress_caps(self):
        """Test suppressing start and end caps."""
        # Setup is handled in self.setup_method()

        # Suppress caps
        self.line.setSupressStartCaps(True)
        self.line.setSupressEndCaps(True)

        assert self.line.supressStartCaps() == True
        assert self.line.supressEndCaps() == True

    def test_vertex_manipulation(self):
        """Test moving vertices using index."""
        # Setup is handled in self.setup_method()
        self.line.appendSeg(Ge.Point3d(0, 0, 0))
        self.line.appendSeg(Ge.Point3d(10, 0, 0))

        # Move the first vertex
        new_pos = Ge.Point3d(5, 5, 0)
        self.line.moveVertexAt(0, new_pos)

        # Verify the vertex moved
        assert self.line.vertexAt(0).isEqualTo(new_pos)

    def test_get_closest_point_to(self):
        """Test finding the closest point on the Mline to a given point."""
        # Setup is handled in self.setup_method()

        # Create a simple line from (0,0) to (10,0)
        self.line.appendSeg(Ge.Point3d(0, 0, 0))
        self.line.appendSeg(Ge.Point3d(10, 0, 0))

        # Point on the line segment
        point_on_line = Ge.Point3d(0, 0, 0)
        closest = self.line.getClosestPointTo(point_on_line, False)

        assert isinstance(closest, Ge.Point3d)

        # Point off the line (should return the endpoint)
        point_off_line = Ge.Point3d(15, 0, 0)
        closest_off = self.line.getClosestPointTo(point_off_line, False)

        assert isinstance(closest_off, Ge.Point3d)
