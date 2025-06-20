from __future__ import annotations

from pyrx import Ap


class TestAxSummaryInfo:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        axInfo = self.axDoc.summaryInfo()
        axInfo.addCustomInfo("key0", "val0")
        axInfo.addCustomInfo("key1", "val1")
        axInfo.addCustomInfo("key2", "val2")
        axInfo.addCustomInfo("key3", "val3")
        axInfo.addCustomInfo("key4", "val4")

    def test_author(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setAuthor("author")
        assert axInfo.author() == "author"

    def test_comments(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setComments("comments")
        assert axInfo.comments() == "comments"

    def test_hyperlinkBase(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setHyperlinkBase("hyperlinkBase")
        assert axInfo.hyperlinkBase() == "hyperlinkBase"

    def test_Keywords(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setKeywords("keywords")
        assert axInfo.keywords() == "keywords"

    def test_lastSavedBy(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setLastSavedBy("lastSavedBy")
        assert axInfo.lastSavedBy() == "lastSavedBy"

    def test_revisionNumber(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setRevisionNumber("revisionNumber")
        assert axInfo.revisionNumber() == "revisionNumber"

    def test_subject(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setSubject("subject")
        assert axInfo.subject() == "subject"

    def test_title(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setTitle("title")
        assert axInfo.title() == "title"

    def test_numCustomInfo(self):
        axInfo = self.axDoc.summaryInfo()
        assert axInfo.numCustomInfo() != 0

    def test_customByIndex(self):
        axInfo = self.axDoc.summaryInfo()
        assert axInfo.customByIndex(1) == ("key1", "val1")

    def test_customByKey(self):
        axInfo = self.axDoc.summaryInfo()
        assert axInfo.customByKey("key1") == "val1"

    def test_setCustomByKey(self):
        axInfo = self.axDoc.summaryInfo()
        axInfo.setCustomByKey("key0", "key99")
        assert axInfo.customByKey("key0") == "key99"
        assert axInfo.customByIndex(0) == ("key0", "key99")

    def test_removeCustomByIndex(self):
        axInfo = self.axDoc.summaryInfo()
        count = axInfo.numCustomInfo()
        axInfo.removeCustomByIndex(4)
        assert axInfo.numCustomInfo() == count - 1
        
    def test_removeCustomByKey(self):
        axInfo = self.axDoc.summaryInfo()
        count = axInfo.numCustomInfo()
        axInfo.removeCustomByKey("key3")
        assert axInfo.numCustomInfo() == count - 1
