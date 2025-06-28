# /* This block
#      should be ignored by the generator */

# /* Even if the lines between the comment merkers are not a python
# comment (line not starting with #),

class ThisClass:
    def should_be_ignored(self) -> None:
        pass

    # and this line also would be ignored...

#     they should be ignored by the generator. */

# /*
# So the ``.iter_lines()`` method should should returns only empty
# lines for this file.
# */

# /* Also this line should be ignored by the generator */
