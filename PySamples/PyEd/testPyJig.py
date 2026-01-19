"""
Python implementation of standard Acedjig functionality using PyRx.
This module demonstrates how to create interactive jigs for AutoCAD command operations,
allowing users to draw geometric entities with real-time preview during command execution.

The code implements two different approaches to Jig usage:
1. Standard Jig without custom drag styling
2. Jig with custom drag style visualization
"""

from pyrx import Ap, Db, Ed

# Print startup messages to indicate commands are loaded
print("command = pyjigstyle")
print("command = pyjig")


class MyJig(Ed.Jig):
    """
    Custom Jig class that extends Ed.Jig for interactive drawing operations.
    
    This class implements the core jig functionality by overriding:
    - sampler(): Handles user input acquisition and point updates
    - update(): Controls when to continue updating during drag operation
    
    The jig is designed to draw a line that updates in real-time as the user moves 
    their mouse, with visual feedback showing the current position.
    
    Attributes:
        line (Db.Line): The database line entity being manipulated
        lastPoint (Ge.Point3d): Previous point for distance comparison and tracking
        curPoint (Ge.Point3d): Current mouse position during dragging
    """
    
    def __init__(self, line, basepoint):
        """
        Initialize the MyJig instance.
        
        Args:
            line (Db.Line): The database Line entity to be manipulated by this jig
            basepoint (Ge.Point3d): Starting point for the jig operation
        """
        # Call parent class constructor with the line entity
        Ed.Jig.__init__(self, line)
        
        # Store references to the line and initial points
        self.line = line              # The line being drawn/modified
        self.lastPoint = basepoint    # Previous point for comparison
        self.curPoint = basepoint     # Current mouse position

    def sampler(self):
        """
        Sample user input and update the line entity during dragging.
        
        This method handles user interaction by:
        1. Setting up appropriate user input controls
        2. Acquiring points from user input (mouse coordinates)
        3. Updating the line endpoint when significant movement occurs
        4. Returning appropriate drag status for operation control
        
        Returns:
            Ed.DragStatus: Current drag status indicating operation state
        """
        # Configure user input controls to accept 3D coordinates and allow null responses
        self.setUserInputControls(
            Ed.UserInputControls(
                Ed.UserInputControls.kAccept3dCoordinates
                | Ed.UserInputControls.kNullResponseAccepted
            )
        )

        # Acquire point from user, using lastPoint as starting reference
        ds, self.curPoint = self.acquirePoint(self.lastPoint)

        # Optimization: Only update line if significant movement occurred
        # This prevents excessive updates for minor mouse movements
        if self.curPoint.distanceTo(self.lastPoint) < 1:
            return Ed.DragStatus.kNoChange
            
        # Update the line's endpoint with current point and track new last position
        self.line.setEndPoint(self.curPoint)
        self.lastPoint = self.curPoint
        
        return ds

    def update(self):
        """
        Update method called during dragging operation.
        
        This method determines whether to continue updating the jig. In this 
        implementation, it always returns True, meaning the jig will continuously
        update while being dragged.
        
        Returns:
            bool: Always returns True to indicate continuous updates should occur
        """
        return True


@Ap.Command()
def pyjigstyle():
    """
    Command function that creates a line with custom drag style visualization.
    
    This command demonstrates how to use Jig with custom DragStyle for enhanced 
    visual feedback during interactive drawing operations. It:
    1. Creates a new drag style with transparency
    2. Prompts user for start point
    3. Initializes a line entity in model space
    4. Uses the jig with custom styling to draw the final result
    
    Usage in AutoCAD:
        Command: pyjigstyle
        Steps: 
        1. Pick startPoint (where line should begin)
        2. Drag mouse to set end point (with visual feedback)
        
    Side Effects:
        - Creates a new line entity in current document's model space
        - Displays transparent drag visualization during operation
        - Prints error messages if operations fail
    """
    try:
        # Get current document and database references
        doc = Ap.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        # Create a custom drag style with 75% transparency for better visual feedback
        style = Ed.DragStyle()
        style.setStyleTypeForDragged(Ed.DragStyleType.kTransparent75)

        # Get starting point from user
        ps, pnt = ed.getPoint("\nPick startPoint")
        if ps != Ed.PromptStatus.eNormal:
            print("oops")
            return

        # Open model space for writing and create a new line entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        line = Db.Line(pnt, pnt)  # Initialize with start point as endpoint
        line.setDatabaseDefaults()  # Apply default properties from database

        # Create jig instance and set up prompt
        jig = MyJig(line, pnt)
        jig.setDispPrompt("\nPick endPoint")

        # Execute drag operation using the custom style
        if jig.drag(style) != Ed.DragStatus.kNormal:
            print("oops")
            return

        # Finalize line by setting its endpoint to the final cursor position
        line.setEndPoint(jig.curPoint)
        
        # Add the completed line to model space
        model.appendAcDbEntity(line)

    except Exception as err:
        # Handle any exceptions during command execution
        print(f"Error in pyjigstyle: {err}")


@Ap.Command()
def pyjig():
    """
    Command function that creates a line with standard drag visualization.
    
    This command demonstrates the basic Jig functionality without custom styling. 
    It:
    1. Prompts user for start point
    2. Initializes a line entity in model space  
    3. Uses the jig to draw the final result with default visual feedback
    
    Usage in AutoCAD:
        Command: pyjig
        Steps:
        1. Pick startPoint (where line should begin)
        2. Drag mouse to set end point (with standard visual feedback)
        
    Side Effects:
        - Creates a new line entity in current document's model space
        - Displays default drag visualization during operation
        - Prints error messages if operations fail
    """
    try:
        # Get current document and database references
        doc = Ap.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        # Get starting point from user
        ps, pnt = ed.getPoint("\nPick startPoint")
        if ps != Ed.PromptStatus.eNormal:
            print("oops")
            return

        # Open model space for writing and create a new line entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        line = Db.Line(pnt, pnt)  # Initialize with start point as endpoint
        line.setDatabaseDefaults()  # Apply default properties from database

        # Create jig instance and set up prompt
        jig = MyJig(line, pnt)
        jig.setDispPrompt("\nPick end Point")
        
        # Execute drag operation using standard styling
        if jig.drag() != Ed.DragStatus.kNormal:
            print("oops")
            return

        # Finalize line by setting its endpoint to the final cursor position
        line.setEndPoint(jig.curPoint)
        
        # Add the completed line to model space
        model.appendAcDbEntity(line)

    except Exception as err:
        # Handle any exceptions during command execution
        print(f"Error in pyjig: {err}")
