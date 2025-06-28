# /*
# This is valid comment section
# */

class ThisClass:
    def should_not_be_ignored(self) -> None:
        """
        This method should not be ignored by the generator.
        """
        pass

# /*
# But this section is not ended, so the ``.iter_lines()`` method should
# raise an exception when trying to iterate over the lines.

def func(): ...
