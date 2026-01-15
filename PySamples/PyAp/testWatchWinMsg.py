"""
PyRx Command Module for Windows Message Watching.

This module provides functionality to monitor Windows messages, specifically 
mouse movement events, in AutoCAD. It allows users to start and stop watching 
for window messages, which can be useful for debugging or monitoring user interactions.

Commands:
    startWatch - Begins monitoring Windows messages (specifically mouse movements)
    endWatch - Stops monitoring Windows messages

Functions:
    winMessage(msg) -> None
        Callback function that processes received Windows messages
        
    PyRxCmd_startWatch() -> None
        Command function to start watching Windows messages
        
    PyRxCmd_endWatch() -> None
        Command function to stop watching Windows messages

Example usage:
    Run 'startWatch' command to begin monitoring mouse movements, then 
    run 'endWatch' command to stop monitoring.
"""

from pyrx import Ap

# WatchWinMsg
print("command = startWatch")
print("command = endWatch")

WM_MOUSEMOVE = 512


def winMessage(msg):
    """
    Callback function that processes received Windows messages.

    This function is called whenever a Windows message is intercepted by 
    the AutoCAD application. It specifically checks for mouse movement events
    and prints the coordinates of the mouse cursor when detected.

    Args:
        msg (tuple): A tuple containing message information in the format:
                     (messageId, hwnd, lParam, wParam, pt.x, pt.y, time)
                     where messageId is the Windows message identifier

    Example usage:
        Automatically called by Ap.Application.registerWatchWinMsg() when 
        a Windows message is received.
        
    Note:
        Only processes WM_MOUSEMOVE messages (message ID 512).
        Prints mouse coordinates (pt.x, pt.y) when movement occurs.
    """
    if msg[0] == WM_MOUSEMOVE:
        print(msg[4], msg[5])

@Ap.Command()
def startWatch() -> None:
    """
    Start monitoring Windows messages for mouse movements.

    This command registers the winMessage callback function with AutoCAD's 
    window message watcher system. Once registered, all Windows messages 
    (specifically mouse movements) will be passed to the winMessage function
    where they can be processed or logged.

    Example usage:
        In AutoCAD command line, type 'startWatch' then press Enter
        
    Side effects:
        - Registers winMessage as a message handler via Ap.Application.registerWatchWinMsg()
        - Starts logging mouse coordinates when mouse moves over AutoCAD window
        - May impact performance slightly due to continuous message processing

    Raises:
        Exception: Any errors during registration are caught and printed to console
    """
    try:
        Ap.Application.registerWatchWinMsg(winMessage)
    except Exception as err:
        print(err)

@Ap.Command()
def endWatch() -> None:
    """
    Stop monitoring Windows messages.

    This command removes the winMessage callback function from AutoCAD's 
    window message watcher system, effectively stopping the monitoring of
    Windows messages and mouse movements.

    Example usage:
        In AutoCAD command line, type 'endWatch' then press Enter
        
    Side effects:
        - Unregisters winMessage as a message handler via Ap.Application.removeWatchWinMsg()
        - Stops logging mouse coordinates from this point forward
        - Frees up resources previously allocated for message handling

    Raises:
        Exception: Any errors during removal are caught and printed to console
    """
    try:
        Ap.Application.removeWatchWinMsg(winMessage)
    except Exception as err:
        print(err)
