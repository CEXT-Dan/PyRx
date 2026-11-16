# AI Tools — Natural-Language AutoCAD Assistant

A small [PyRx](https://pyrx.dev) app script that turns plain English into real AutoCAD
drawing commands. It exposes a set of CAD "tools" (layer, circle, line, polyline, arc, dimension,
text, 3D cylinder, 3D cuboid, and a drawing inspector) as OpenAI-style function schemas, lets an LLM
decide which tool to call, and executes the call safely inside the AutoCAD application
context.

By default it talks to a local [LM Studio](https://lmstudio.ai) server, but it will work
with any OpenAI-compatible endpoint.

---

## What is `ai_tools.py`?

`ai_tools.py` is the **tool catalog**. It does two jobs:

1. **Implements the CAD operations.** Each function creates real AutoCAD entities in the
   active document's model space using the `pyrx` `Db` and `Ge` namespaces.
2. **Describes them to the LLM.** `TOOL_SCHEMAS` is a list of OpenAI tool definitions
   (name, description, JSON parameters) that the model reads to learn what it can do and
   how to call it. `TOOL_FUNCTIONS` maps each tool name to its Python implementation.

The file itself is model-agnostic — it contains no HTTP calls and no loop logic. That
lives in the companion driver script (`OpenAI.py`), which wires the schemas to a chat
model and dispatches the resulting calls into AutoCAD.

```
ai_tools.py   →  tool implementations + LLM tool schemas (this catalog)
OpenAI.py     →  LM Studio agent loop, threading, and the LMAI command
```

---

## How it works

```
You type a prompt (LMAI)
        │
        ▼
OpenAI.py sends the prompt + TOOL_SCHEMAS to the LLM (LM Studio / OpenAI)
        │
        ▼
LLM responds with a tool call, e.g.  create_circle(cx=50, cy=50, radius=25)
        │
        ▼
OpenAI.py looks the name up in TOOL_FUNCTIONS
        │
        ▼
dispatch_to_acad() queues the call onto the AutoCAD main thread (onIdle)
        │
        ▼
ai_tools.py runs the function in the AutoCAD application context → entity is created
        │
        ▼
The result (handle, status) is fed back to the LLM, which can continue or finish
```

The round-trip to the main thread matters: AutoCAD entities can only be created on the
application's main thread, so the driver script marshals every tool call across a
thread-safe queue and waits for completion. This keeps the LLM call off the main thread
while the drawing work stays on it.

---

## Available tools

| Tool               | What it does                                            | Key parameters                                        |
| ------------------ | ------------------------------------------------------- | ----------------------------------------------------- |
| `get_drawing_info` | Inspect entity counts in the active model space          | —                                                     |
| `create_layer`     | Create a named layer (safe to call if it already exists)  | `layer`, `color`                                      |
| `create_circle`    | Draw a 2D circle                                          | `cx`, `cy`, `radius`, `layer`                         |
| `create_line`      | Draw a 2D line segment                                    | `x1`, `y1`, `x2`, `y2`, `layer`                       |
| `create_polyline`  | Draw a 2D polyline through a list of points              | `points`, `closed`, `layer`                           |
| `create_arc`       | Draw a 2D circular arc                                    | `cx`, `cy`, `radius`, `start_angle`, `end_angle`, `layer` |
| `create_dimension` | Add an aligned linear dimension between two points        | `x1`, `y1`, `x2`, `y2`, `dim_line_point_x`, `dim_line_point_y`, `layer` |
| `create_text`      | Add a single-line text entity                             | `x`, `y`, `text`, `height`, `rotation`, `layer`       |
| `create_cylinder`  | Create a Z-axis-aligned 3D solid cylinder                 | `cx`, `cy`, `cz`, `radius`, `height`, `layer`         |
| `create_cuboid`    | Create a 3D box (cuboid) solid                            | `cx`, `cy`, `cz`, `x_len`, `y_len`, `z_len`, `layer`  |

> **Cylinder coordinates are the *center*.** `create_cylinder` places the solid so that
> `(cx, cy, cz)` is its geometric **center**, not its base. A cylinder of height `h`
> therefore spans `cz − h/2` to `cz + h/2`. To make a cylinder "rest on" the Z=0 plane,
> set `cz = height / 2`.

> **Cuboid coordinates are the *center*.** `create_cuboid` places the box so that
> `(cx, cy, cz)` is its geometric **center**. A box of dimensions `x_len × y_len × z_len`
> therefore spans `cz − z_len/2` to `cz + z_len/2` along Z (and likewise for X and Y). To
> make a box "rest on" the Z=0 plane, set `cz = z_len / 2`.

Every tool accepts a `layer` argument (defaults to `"0"`) and returns a JSON object with
the creation status and the entity's AutoCAD handle.

---

## Setup

**Prerequisites**

- [AutoCAD](https://www.autodesk.com/products/autocad) with [PyRx](https://pyrx.dev) installed.
- [LM Studio](https://lmstudio.ai) running a local model, **or** any OpenAI-compatible server.
- Python `openai` package for the driver script.

```bash
pip install openai
```

**Load the app**

In AutoCAD's Python console (or via your usual PyRx app-loading flow), load the driver
script so it registers the `LMAI` command:

```python
import sys, os
app_dir = r"M:\Dev\Projects\PyRxGit\PySamples\Play\AI_Tools"
if app_dir not in sys.path:
    sys.path.insert(0, app_dir)
import OpenAI   # runs OnPyInitApp() and registers the LMAI command
```

**Point it at your model (optional)**

The defaults in `OpenAI.py` target LM Studio:

```python
client = OpenAI(base_url="http://localhost:1234/v1", api_key="lm-studio")
LM_STUDIO_MODEL = "local-model"
```

Swap `base_url`, `api_key`, and the model name to target any other OpenAI-compatible
backend.

---

## Usage

Run the `LMAI` command and type a natural-language prompt:

```
Command: LMAI
Ask LM Studio:  Check what is currently in the drawing, then draw a circle of
                radius 25 at (50, 50) and a line from (0,0) to (50,50).
```

The LLM will plan the work, invoke the tools one at a time, and report each result back
to the console. Typical output looks like:

```
[AI Tool Call] get_drawing_info({})
[AI Tool Output] {"modelspace_entity_counts": {"AcDbLine": 3, "AcDbCircle": 1}}
[AI Tool Call] create_circle({'cx': 50, 'cy': 50, 'radius': 25, 'layer': '0'})
[AI Tool Output] {"status": "created", "type": "Circle", "handle": "12AB"}
[AI Tool Call] create_line({'x1': 0, 'y1': 0, 'x2': 50, 'y2': 50, 'layer': '0'})
[AI Tool Output] {"status": "created", "type": "Line", "handle": "12AC"}
```

### Example 2 — stacked 3D cylinders

```
Command: LMAI
Ask LM Studio:  Create a 3D cylinder base with radius 40 and height 10 resting on Z=0
                at (0, 0), then stack a narrower cylinder of radius 15 and height 50
                centered right on top of it.
```

Because the tool uses the **center**, the model translates the intent into coordinates:

| Part    | radius | height | center `cz` (height/2 offset) | spans               |
| ------- | ------ | ------ | ----------------------------- | ------------------- |
| Base    | 40     | 10     | `5`  (rests on Z=0)          | Z = 0 → 10          |
| Top     | 15     | 50     | `35` (starts at base top Z=10) | Z = 10 → 60         |

```
[AI Tool Call] create_cylinder({'cx': 0, 'cy': 0, 'cz': 5,  'radius': 40, 'height': 10})
[AI Tool Output] {"status": "created", "type": "Solid3d", "handle": "12AD", "is_null": false}
[AI Tool Call] create_cylinder({'cx': 0, 'cy': 0, 'cz': 35, 'radius': 15, 'height': 50})
[AI Tool Output] {"status": "created", "type": "Solid3d", "handle": "12AE", "is_null": false}
```

---

## Project structure

```
AI_Tools/
├── ai_tools.py    # Tool implementations + LM Studio / OpenAI tool schemas
├── OpenAI.py      # LM Studio agent loop, threading, and the LMAI command
└── README.md      # This file
```

---

## Notes & tips

- **Prompt in plain language.** The model reads the tool descriptions, so phrasing like
  "resting on Z=0" or "stacked on top" is understood and converted into the right
  coordinates for you.
- **Layers.** Ask for a layer to keep things organized, e.g. *"…on layer `WALL`."*
- **The agent loop is capped** at a few tool-call rounds to avoid runaway loops; each
  round feeds the previous tool's output back to the model.
- **Errors are reported back** to the LLM (e.g. an invalid coordinate count), so it can
  retry with corrected arguments.
