import traceback

from pyrx import Ap

print("Added new command helloworld, type helloworld at the prompt: ")


@Ap.Command()
def helloworld() -> None:
    try:
        print("whats up!: ")
    except Exception as err:
        traceback.print_exception(err)
