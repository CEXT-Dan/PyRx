import traceback
from typing import no_type_check
from pyrx import Ap, Ed, Db

src_path = "../pyrx/"
all_modules = [
    ("PyRx", "PyRx.pyi"),
    ("PyGe", "PyGe.pyi"),
    ("PyGi", "PyGi.pyi"),
    ("PyGs", "PyGs.pyi"),
    ("PyDb", "PyDb.pyi"),
    ("PyAp", "PyAp.pyi"),
    ("PyEd", "PyEd.pyi"),
    ("PyPl", "PyPl.pyi"),
    ("PySm", "PySm.pyi"),
    ("PyBr", "PyBr.pyi"),
    ("PyAx", "PyAx.pyi"),
]

import ast
import os
from html import escape


def get_arg_str(arg):
    """Get a string representation of a function argument with optional type."""
    if arg.annotation:
        return f"{arg.arg}: {ast.unparse(arg.annotation)}"
    else:
        return arg.arg


def parse_pyi_file(filepath):
    with open(filepath, "r", encoding="utf-8") as f:
        tree = ast.parse(f.read(), filename=filepath)

    docs = []

    for node in tree.body:
        if isinstance(node, ast.ClassDef):
            class_name = node.name
            members = []

            for item in node.body:
                if isinstance(item, ast.FunctionDef):
                    args = []

                    # Positional arguments
                    #print(str(item.args.posonlyargs.))
                    for arg in item.args.posonlyargs:
                        args.append(get_arg_str(arg))

                    # *args
                    if item.args.vararg:
                        args.append(f"*{get_arg_str(item.args.vararg)}")

                    # Keyword-only arguments
                    for arg in item.args.kwonlyargs:
                        args.append(get_arg_str(arg))

                    # **kwargs
                    if item.args.kwarg:
                        args.append(f"**{get_arg_str(item.args.kwarg)}")

                    # Return type
                    ret_annotation = ""
                    if item.returns:
                        ret_annotation = f" -> {ast.unparse(item.returns)}"

                    signature = f"def {item.name}({', '.join(args)}){ret_annotation}"
                    members.append(signature)

                elif isinstance(item, ast.AnnAssign) and isinstance(item.target, ast.Name):
                    annotation = ast.unparse(item.annotation)
                    members.append(f"{item.target.id}: {annotation}")

            docs.append((class_name, members))

    return docs


def generate_html(doc_data, title="Stub Documentation"):
    html = f"""<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>{escape(title)}</title>
    <style>
        body {{
            background-color: #1e1e1e;
            color: #d4d4d4;
            font-family: Consolas, monospace;
            margin: 2em;
        }}
        a {{
            color: #569cd6;
        }}
        .class {{
            margin-bottom: 1em;
        }}
        summary {{
            font-weight: bold;
            font-size: 1.1em;
            cursor: pointer;
            padding: 0.2em 0.4em;
            border-radius: 4px;
        }}
        details {{
            margin-left: 0.5em;
            background-color: #252526;
            border: 1px solid #3c3c3c;
            border-radius: 6px;
            padding: 0.5em;
        }}
        code {{
            display: block;
            margin: 0.3em 0;
            white-space: pre;
            background-color: #1e1e1e;
            color: #dcdcdc;
            padding: 0.4em 0.6em;
            border-left: 4px solid #007acc;
        }}
        h1 {{
            color: #569cd6;
        }}
    </style>
</head>
<body>
    <h1>{escape(title)}</h1>
"""

    for class_name, members in doc_data:
        html += f"""
    <div class="class">
        <details>
            <summary>class {escape(class_name)}</summary>
"""
        for member in members:
            html += f"            <code>{escape(member)}</code>\n"

        html += "        </details>\n    </div>\n"

    html += "</body>\n</html>"
    return html


def generate_doc_from_pyi(pyi_path, output_path="documentation.html"):
    doc_data = parse_pyi_file(pyi_path)
    html = generate_html(doc_data, title=os.path.basename(pyi_path))
    with open(output_path, "w", encoding="utf-8") as f:
        f.write(html)
    print(f"Documentation written to {output_path}")


@Ap.Command()
def docgen() -> None:
    try:
        for name, module in all_modules:
            src_file = "{}{}".format(src_path, module)
            dst_file = "../Doc/Classes/{}{}".format(name, ".html")
            generate_doc_from_pyi(src_file, dst_file)

    except Exception as err:
        traceback.print_exception(err)
