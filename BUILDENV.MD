# Build Environment

This is **not** a how-to for building — it's a reference for the environment
variables you need to point at your SDKs before you can compile. Each CAD
host has its own SDK, and each project references its SDK through a single
environment variable. You only need to set the variables for the CAD
version(s) you actually want to build.

The shared dependencies (wxWidgets, Boost, Python, wxPython) are used by
every project, so those are always required.

## Environments (per CAD host)

One environment variable per CAD host + version. Set it to the root of that
SDK installation. The sub-folders (`inc`, `lib`, `arxport`, `BrxSpecific`, …)
differ per host and are handled inside the project file — you only set the
root.

| CAD host  | Version | Project    | Env var  | Points to                | Target ext |
|-----------|---------|------------|----------|--------------------------|------------|
| AutoCAD   | 2022    | PyRx24.1   | `ARX2022`| ObjectARX 2022 SDK       | `.arx`     |
| AutoCAD   | 2023    | PyRx24.2   | `ARX2023`| ObjectARX 2023 SDK       | `.arx`     |
| AutoCAD   | 2024    | PyRx24.3   | `ARX2024`| ObjectARX 2024 SDK       | `.arx`     |
| AutoCAD   | 2025    | PyRx25.0   | `ARX2025`| ObjectARX 2025 SDK       | `.arx`     |
| AutoCAD   | 2026    | PyRx25.1   | `ARX2026`| ObjectARX 2026 SDK       | `.arx`     |
| AutoCAD   | 2027    | PyRx26.0   | `ARX2027`| ObjectARX 2027 SDK       | `.arx`     |
| BricsCAD  | V24     | PyRxV24.0  | `BRX24`  | BRX 24 SDK               | `.brx`     |
| BricsCAD  | V25     | PyRxV25.0  | `BRX25`  | BRX 25 SDK               | `.brx`     |
| BricsCAD  | V26     | PyRxV26.0  | `BRX26`  | BRX 26 SDK               | `.brx`     |
| BricsCAD  | V27     | PyRxV27.0  | `BRX27`  | BRX 27 SDK               | `.brx`     |
| ZWCAD     | 2024    | PyRxZ24.0  | `ZRX2024`| ZRX 2024 SDK             | `.zrx`     |
| ZWCAD     | 2025    | PyRxZ25.0  | `ZRX2025`| ZRX 2025 SDK             | `.zrx`     |
| ZWCAD     | 2026    | PyRxZ26.0  | `ZRX2026`| ZRX 2026 SDK             | `.zrx`     |
| ZWCAD     | 2027    | PyRxZ27.0  | `ZRX2027`| ZRX 2027 SDK             | `.zrx`     |
| GstarCAD  | 2024    | PyRxG24.0  | `GRX24`  | GRX 24 SDK               | `.grx`     |
| GstarCAD  | 2025    | PyRxG25.0  | `GRX25`  | GRX 25 SDK               | `.grx`     |
| GstarCAD  | 2026    | PyRxG26.0  | `GRX26`  | GRX 26 SDK               | `.grx`     |
| GstarCAD  | 2027    | PyRxG27.0  | `GRX27`  | GRX 27 SDK               | `.grx`     |

### Project-name → host legend

| Prefix | CAD host | SDK family |
|--------|----------|------------|
| (none) | AutoCAD  | ARX        |
| `V`    | BricsCAD | BRX        |
| `Z`    | ZWCAD    | ZRX        |
| `G`    | GstarCAD | GRX        |

## Shared dependencies (required by every project)

| Env var     | Points to                                   |
|-------------|---------------------------------------------|
| `WXWIN`     | wxWidgets 3.3.4 install root                |
| `BOOST`     | Boost 1.92.0 (prebuilt) — see Boost note    |
| `PYTHON_LIB`| Python 3.14.x (headers + libs)              |
| `WXPYWIN`   | wxPython 4.3.2 `...\Lib\site-packages\wx`  |

Prebuilt Boost binaries: <https://sourceforge.net/projects/boost/files/boost-binaries/1.92.0/>

## Toolset / Boost note

Each project pins a platform toolset, and the Boost lib folder must match the
toolset's MSVC runtime:

| Toolset | Boost lib folder     |
|---------|----------------------|
| `v142`  | `$(BOOST)\lib64-msvc-14.2` |
| `v143`  | `$(BOOST)\lib64-msvc-14.3` |

So if you build across both `v142` and `v143` projects, your Boost install
needs both `lib64-msvc-14.2` and `lib64-msvc-14.3` folders (i.e. prebuilt
binaries for both MSVC 14.2 and 14.3).

## Misc

- The `\External` folder may hold additional dependencies (e.g. CDT).
- Discussion #120 has some extra tips.
