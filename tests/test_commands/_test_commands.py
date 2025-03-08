from pyrx.commands import command


@command
def command_1(a=1):
    print(a)


@command(name="cmd_2")
def command_2():
    raise RuntimeError("Test cmd 2")
