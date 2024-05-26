pyrx_rt_type = {
    'Editor::getKword':             "tuple[int, str]",
    "Editor::getCorner":            "tuple[PyEd.PromptStatus, PyGe.Point3d]",
    "Editor::getInteger":           "tuple[PyEd.PromptStatus, int]",
    "Editor::getDouble":            "tuple[PyEd.PromptStatus, float]",
    "Editor::getAngle":             "tuple[PyEd.PromptStatus, float]",
    "Editor::getPoint":             "tuple[PyEd.PromptStatus, PyGe.Point3d]",
    "Editor::getDist":              "tuple[PyEd.PromptStatus, float]",
    "Editor::getString":            "tuple[PyEd.PromptStatus, str]",
    "Editor::select":               "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectFence":          "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectLast":           "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectPrevious":       "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectPrompt":         "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectWindow":         "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectWindowPolygon":  "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::ssget":                "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::selectAll":            "tuple[PyEd.PromptStatus, PyEd.SelectionSet]",
    "Editor::entSel":               "tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]",
}

def parsesig(sig: str) -> None:
    endsig = sig.find("(")
    return sig[0:endsig].strip()


def tryResolveTupleType(name: str, sig: str) -> str | None:
    psig = "{}::{}".format(name, parsesig(sig))
    if psig in pyrx_rt_type:
        return pyrx_rt_type[psig]
    print(psig)
    return "tuple[Any,...]"
