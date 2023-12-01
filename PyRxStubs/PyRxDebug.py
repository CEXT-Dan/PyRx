import sys
import debugpy


def startListener():
    oldpath = sys.executable
    try:
        # this needs to be set or python will launch autocad
        print("Now is a good time to run your debugger:")
        print(".....")
        sys.executable = sys.prefix + "\\python.exe"
        debugpy.listen(("localhost", 5678))
        debugpy.wait_for_client()
    except:
        pass
    finally:
        sys.executable = oldpath


def PyRxCmd_pystartdebuglistener():
    startListener()

    # sample config
    # {
    #     "name": "Remote Attach",
    #     "type": "python",
    #     "request": "attach",
    #     "debugServer": 5678,
    #     "justMyCode": false
    # }
