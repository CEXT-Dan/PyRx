"""
PyRx Hello World Command Module

This module demonstrates the most basic example of creating a custom AutoCAD command
using PyRx. It serves as an introductory example for developers learning how to
extend AutoCAD functionality with Python.

Features:
- Simple "Hello World" style command implementation
- Basic error handling with traceback support
- Minimal code structure showing essential PyRx command pattern

Usage:
    Load this script into AutoCAD's Python environment.
    Run 'helloworld' from the AutoCAD command line to see output.

Requirements:
    - Active AutoCAD installation with Python support enabled
    - No additional dependencies required beyond standard PyRx

Example Output:
    When executed, prints "whats up!: " to the AutoCAD command line console.

This is intended as a starting point for beginners learning PyRx command development.
"""

import traceback

from pyrx import Ap

# --- Registering Commands ---
print("Added new command helloworld, type helloworld at the prompt: ")


# === Command: helloworld ===
@Ap.Command()
def helloworld() -> None:
    """
    Simple hello world style command for AutoCAD.
    
    This is the most basic example of a PyRx command implementation. It demonstrates:
    1. How to register a new command using @Ap.Command() decorator
    2. Basic function structure with proper typing annotation
    3. Simple console output functionality
    4. Error handling pattern using try/except and traceback
    
    Usage:
        Type 'helloworld' at the AutoCAD command prompt.
        
    Side Effects:
        - Prints "whats up!: " to the AutoCAD command line console
        - No modifications to drawing database
        - No external file operations
        
    Error Handling:
        - Catches any exceptions that might occur during execution
        - Prints full exception traceback for debugging purposes
        
    Example Output:
        whats up!: 
        
    This command serves as a minimal working example for beginners learning
    PyRx command development. It shows the essential structure without any 
    complex operations or external dependencies.
    """
    try:
        # Simple console output to demonstrate basic functionality
        print("whats up!: ")
        
    except Exception as err:
        # Handle and display any errors that occur during execution
        traceback.print_exception(err)
