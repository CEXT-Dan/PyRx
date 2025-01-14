# Testing

The main module responsible for running tests for all hosts is [runner.py](./runner.py). This module launches individual applications and loads the [host_runner.py](./host_runner.py) module into them. After loading, the host's CWD changes to the parent directory of this file, which is [tests](.). Therefore, the [tests](.) directory is treated as the root, and this is why files like [pytest.ini](./pytest.ini) are stored there.

## Running

It is recommended to run tests using the [run_tests.bat](../run_tests.bat) script.
This script assumes the use of `dotenv` (`pip install python-dotenv`).
In the [tests](.) directory, create a `.env` file and define variables for the executable files of individual hosts:

```ini
ACAD_EXE = ...
BCAD_EXE = ...
GCAD_EXE = ...
ZCAD_EXE = ...
```

You can also run the tests directly. The CWD must be set to the [root directory](..) (parent of the tests directory).

```bash
python -m tests.runner
```

By default, tests for known failures are not executed. To enable these tests:

```bash
run_tests --known-failures
```

To skip slow tests:

```bash
run_tests --no-slow
```

To select hosts to test:

```bash
run_tests --hosts acad zcad
```

To enable debug mode:

```bash
run_tests --debug
```

Passing pytest cmd options:

```bash
run_tests <other_args> --pytest <only_pytest_marks>
```

Passing embedded python config flags:

```bash
run_tests --pyinit 0xFFFFFFFF
```

Complex example:

```bash
run_tests --pyinit 0xFFFFFFFF --hosts acad zcad --debug --known-failures --pytest --co
```
