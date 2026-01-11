# Import the PyRx database module for AutoCAD database operations
from pyrx import Ap, Db

# Print confirmation that the command has been registered
print("added command pyreaddwg")

# Python disposes of objects in reverse order of creation
# To ensure proper cleanup, we'll define a separate function as a scope
# This ensures modelspace is closed before the database object is destroyed
# (This helps prevent memory leaks and access violations)

def iterateDatabase(db: Db.Database, entities):
    """
    Iterate through all objects in the model space of a database and count entity types.
    
    Args:
        db: Database object to analyze
        entities: Dictionary to store entity type counts
    """
    # Open the model space block table record for reading
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForRead)
    
    # Iterate through all object IDs in the model space
    for id in model.objectIds():
        # Get the class name of the current object
        classname = id.objectClass().name()
        
        # If this entity type already exists in our dictionary, increment count
        if classname in entities:
            entities[classname] = entities[classname] + 1
        else:
            # If this is a new entity type, initialize its count to 1
            entities[classname] = 1

@Ap.Command()
def pyreaddwg():
    """
    Main command function that reads a DWG file and reports entity counts.
    
    This function demonstrates how to:
    1. Create a database object
    2. Read a DWG file
    3. Access model space objects
    4. Count different entity types
    5. Handle exceptions properly
    """
    try:
        # Create a new database instance
        # False = don't build default drawing (creates empty database)
        # True = no document association (database not tied to current AutoCAD document)
        db = Db.Database(False, True)
        
        # Read the specified DWG file from the relative path
        # This will throw an exception if the file doesn't exist or is invalid
        db.readDwgFile("..\\dwg\\Floor Plan Sample.dwg")
        
        # Close the input file properly to release resources
        db.closeInput(True)
        
        # Initialize empty dictionary to store entity counts
        entities = {}

        # Call our iterate function within this scope to ensure proper cleanup
        # This creates a logical boundary where model space is processed before database disposal
        iterateDatabase(db, entities)

        # Print the final results showing count of each entity type
        print(entities)
        
    except Exception as err:
        # Handle any errors that occur during processing
        # This could include file not found, invalid DWG format, etc.
        print(err)
