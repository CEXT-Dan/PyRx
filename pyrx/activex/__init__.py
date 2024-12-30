import importlib
import importlib.util

if importlib.util.find_spec("win32com") is not None:
    from pyrx import Ap

    host = Ap.Application.hostAPI()
    ax_module_name = {
        "BRX24": "BxApp24",
        "BRX25": "BxApp25",
        "GRX24": "GxApp24",
        "GRX25": "GxApp25",
        "ZRX24": "ZxApp24",
        "ZRX25": "ZxApp25",
        "ARX24": "AxApp24",
        "ARX25": "AxApp25",
    }.get(host, None)
    if ax_module_name is not None:
        Ax = importlib.import_module(ax_module_name)
    else:
        raise RuntimeError(f"Unrecognized host API: {host}")
else:
    Ax = None

# TODO: TEST (Ax is ModuleType or None)
