from datetime import datetime

print(f"\nModule {__name__} loaded at {datetime.now()}\n")


def func_a():
    return 1


def func_b():
    raise ValueError("This is a test exception")
