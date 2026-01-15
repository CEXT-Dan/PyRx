"""
PyRx Command Module for Adding Raster Images to AutoCAD.

This module provides a command to insert a raster image (JPEG) into the current drawing.
It demonstrates how to create and manage raster image definitions, add them to the 
named objects dictionary, and associate them with image entities in model space.

Commands:
    do_raster - Inserts a JPEG image into the current drawing's model space

Functions:
    do_raster() -> None
        Main command function that creates and inserts a raster image entity

Example usage:
    Run 'do_raster' command in AutoCAD to insert a sample JPEG image 
    from M:/Dev/Projects/PyRxGit/tests/media/rastertest.jpg into the current drawing.
"""

from pyrx import Ap, Db

print("added command do_raster")


@Ap.Command()
def do_raster() -> None:
    """
    Insert a raster image (JPEG) into the current drawing's model space.

    This function performs the following steps:
    1. Gets the working database
    2. Creates or retrieves the raster image dictionary from named objects
    3. Creates a new RasterImageDef from a specified JPEG file
    4. Loads the image data into memory
    5. Adds the image definition to the dictionary with a specific name
    6. Creates a RasterImage entity and associates it with the image definition
    7. Adds the image to model space
    8. Sets up reactor functionality for image management

    The raster image is loaded from "M:/Dev/Projects/PyRxGit/tests/media/rastertest.jpg"
    and added to the current drawing's model space at its default position.

    Example usage:
        In AutoCAD command line, type 'do_raster' then press Enter
        
    Features demonstrated:
        - Creating raster image definitions from files
        - Managing named object dictionaries for images
        - Associating image entities with their definitions
        - Setting up reactors for image management and updates
        - Proper resource management through proper open/downgrade patterns

    Note:
        This command assumes the specified JPEG file exists at the hardcoded path.
        The image will be displayed in the current drawing's model space.
    """
    try:
        # Define the dictionary key name for our raster image
        dictName = "MY_IMAGE_NAME"
        
        # Get the working database
        db = Db.HostApplicationServices().workingDatabase()
        
        # Get or create the raster image dictionary in named objects
        imageDictId = Db.RasterImageDef.imageDictionary(db)
        if imageDictId.isNull():
            imageDictId = Db.RasterImageDef.createImageDictionary(db)

        # Create a new raster image definition from file
        imageDef = Db.RasterImageDef()
        imageDef.setSourceFileName("M:/Dev/Projects/PyRxGit/tests/media/rastertest.jpg")
        imageDef.load()  # Load the actual image data into memory

        # Open the image dictionary for writing and add our image definition
        imageDict = Db.Dictionary(imageDictId, Db.OpenMode.kForWrite)
        imageDefId = imageDict.setAt(dictName, imageDef)
        imageDict.downgradeOpen()  # Release write lock on dictionary
        imageDef.downgradeOpen()   # Release write lock on image definition

        # Create a raster image entity and set its properties
        image = Db.RasterImage()
        image.setDatabaseDefaults()
        image.setImageDefId(imageDefId)  # Associate with our loaded image definition

        # Add the image to model space
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(image)

        # Enable raster image reactor functionality and set up reactors
        Db.RasterImageDefReactor.setEnable(True)
        reactor = Db.RasterImageDefReactor()
        reactor.setOwnerId(image.objectId())

        # Add the reactor to the database and associate it with the image
        reactorid = db.addObject(reactor)
        image.setReactorId(reactorid)
        imageDef.upgradeOpen()  # Upgrade to write access for adding persistent reactor
        imageDef.addPersistentReactor(reactorid)

    except Exception as err:
        print(err)
