from pyrx.utils.reload import Reloader


def on_reload():
    raise RuntimeError("Reload exception")


Reloader(func=on_reload).register()
