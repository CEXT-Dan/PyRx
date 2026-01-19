"""
Python implementation of ObjectxARX's Acedjig with custom graphics drawing capabilities.
This module demonstrates how to create a custom jig that allows users to pick points 
and draw geometric shapes in real-time during command execution.

The code implements a custom DrawJig class that inherits from Ed.DrawJig, enabling
interactive drawing operations within AutoCAD using Python (PyRx).
"""

from pyrx import Ap, Ed, Ge, Gi

# Print startup message to indicate the command is loaded
print("command = pydrawjig")


class MyDrawJig(Ed.DrawJig):
    """
    Custom DrawJig class that implements interactive drawing functionality.
    
    This class inherits from Ed.DrawJig and overrides key methods to provide:
    - Point acquisition through mouse input
    - Real-time geometric drawing updates
    - Custom graphics rendering using WorldDraw interface
    
    Attributes:
        ds (Ed.DragStatus): Current drag status for tracking interaction state
        basepoint (Ge.Point3d): Starting point for the jig operation
        curpoint (Ge.Point3d): Current mouse position during dragging
        tri (list): Triangle vertices defining a simple geometric shape to draw
    """
    
    def __init__(self, basepoint):
        """
        Initialize the MyDrawJig instance.
        
        Args:
            basepoint (Ge.Point3d): The starting point for the jig operation
        """
        # Call parent class constructor
        Ed.DrawJig.__init__(self)
        
        # Initialize drag status and points
        self.ds = Ed.DragStatus.kNormal  # Current drag status
        self.basepoint = basepoint       # Starting reference point
        self.curpoint = basepoint        # Current mouse position
        
        # Define triangle vertices (closed polygon with 4 points including closure)
        # Points: (-1,0,0) -> (1,0,0) -> (0,1,0) -> (-1,0,0) [closing point]
        self.tri = [
            Ge.Point3d(-1, 0, 0),   # Base left vertex
            Ge.Point3d(1, 0, 0),    # Base right vertex  
            Ge.Point3d(0, 1, 0),    # Top vertex
            Ge.Point3d(-1, 0, 0),   # Closing point to complete triangle
        ]

    def sampler(self):
        """
        Sample user input and acquire mouse coordinates.
        
        This method sets up the user interaction controls and acquires 
        point input from the user. It handles both relative and absolute
        coordinate picking based on user preferences.
        
        Returns:
            Ed.DragStatus: The drag status after acquiring the point
        """
        # Configure user input controls to accept 3D coordinates
        self.setUserInputControls(Ed.UserInputControls.kAccept3dCoordinates)
        
        # Acquire a single point from user input, using basepoint as default if needed
        self.ds, self.curpoint = self.acquirePoint(self.basepoint)
        return self.ds

    def update(self):
        """
        Update method called during dragging operation.
        
        This method determines whether to continue the drag operation based 
        on changes in mouse position or user interaction status.
        
        Returns:
            bool: True if the jig should continue updating, False otherwise
        """
        # If no change from previous state, don't update (optimization)
        if self.ds == Ed.DragStatus.kNoChange:
            return False
            
        # Continue with updates when there are changes
        return True

    def worldDraw(self, wd: Gi.WorldDraw):
        """
        Draw method called during real-time rendering of the jig.
        
        This is where custom graphics are rendered to screen. It transforms 
        and draws geometric primitives in 3D space relative to user interaction.
        
        Args:
            wd (Gi.WorldDraw): World draw context for rendering operations
            
        Returns:
            bool: True if drawing completed successfully, False otherwise
        """
        # Skip drawing if no change occurred (prevents unnecessary redraws)
        if self.ds == Ed.DragStatus.kNoChange:
            return True
            
        try:
            # Create transformation matrix to move triangle from base position to current point
            mat = Ge.Matrix3d.translation(self.curpoint - self.basepoint)
            
            # Get the geometry context for drawing operations
            geo = wd.geometry()
            
            # Apply transformation to model space (translate triangle)
            geo.pushModelTransform(mat)
            
            # Draw the triangle as a polyline with z-axis normal
            # This creates a filled or outlined 2D triangle in 3D space
            geo.polyline(self.tri, Ge.Vector3d.kZAxis)
            
            # Restore original model transformation (cleanup)
            geo.popModelTransform()
            
            return True
            
        except Exception as err:
            # Handle any drawing errors gracefully
            print(f"Error during worldDraw: {err}")
            return False


@Ap.Command()
def pydrawjig():
    """
    Main command function that executes the draw jig operation.
    
    This is the entry point for AutoCAD command execution. It creates an instance 
    of MyDrawJig, sets up user prompts, and manages the interactive drawing session.
    
    Example usage in AutoCAD:
        Command: pydrawjig
        Prompt: Pick point:
        
    Side Effects:
        - Opens interactive drawing mode in AutoCAD
        - Displays real-time triangle graphics following mouse cursor
        - Prints completion status to console
    """
    try:
        # Create new instance of our custom jig starting at origin (0,0,0)
        jig = MyDrawJig(Ge.Point3d(0, 0, 0))
        
        # Set user prompt for command interaction
        jig.setDispPrompt("\nPick point:\n")
        
        # Start the drag operation and wait for completion
        res = jig.drag()
        
        # Print final result to console
        print("done", res)
        
    except Exception as err:
        # Handle any exceptions during command execution
        print(f"Error in pydrawjig: {err}")
