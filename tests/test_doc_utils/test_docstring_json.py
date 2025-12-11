import json


class TestDocStringJson:
    def setup_class(self):
        self._path = "../pyrx/doc_utils/resources/docstrings.json"
        self.json_data = {}
        with open(self._path, "r") as file:
            data = json.load(file)
            for item in data["rows"]:
                self.json_data[item[0]] = item[1:]

    def lookupDocString(self, row: int):
        return self.json_data[row][-1]

    def lookupId(self, row: int):
        return self.json_data[row][0]

    def test_datebase_valid(self):
        assert self.lookupDocString(12) == "Description"
        assert self.lookupDocString(1035) == "Destructor."
        assert self.lookupDocString(2024) == "Description"
        assert self.lookupDocString(4025) == "Destructor."
        assert self.lookupDocString(5033) == "Destructor."
        assert self.lookupDocString(6026) == "Destructor."
        assert self.lookupDocString(7069) == "Destructor."
        assert self.lookupDocString(8030) == "Destructor."
        assert self.lookupDocString(9079) == "Destructor."
        assert self.lookupDocString(10187) == "Destructor."
        assert self.lookupDocString(10187) == "Destructor."
        assert self.lookupDocString(12056) == "Destructor."
        assert self.lookupDocString(14117) == "Destructor."
        assert self.lookupDocString(16123) == "Destructor."
        assert self.lookupDocString(18573) == "Destructor."
        assert self.lookupDocString(19132) == "Description"
        assert self.lookupDocString(19139) == "TEST19139"

    def test_datebase_unique(self):
        json_data = {}
        rownum = 0
        with open(self._path, "r") as file:
            data = json.load(file)
            for item in data["rows"]:
                rownum += 1
                assert not item[0] in json_data
                assert rownum == item[0]
        assert rownum != 0
