I don't feel like working on anything right now, so I'm typing it all out anyway.

For starters, the exercise asks you to merge some number `<k>` ***sorted*** lists. When you create your test lists, they are given random values, so they won't serve as good tests. Also, just as a note, it strikes me as a bit odd to create the lists backwards. It's not wrong by any means. It looks like it works fine. Just seems odd to me, since creating them backwards is only really going to be useful for creating test cases like these.

Next, in `merge-k-sorted-lists()`:
* Line 92: What if `array->size == 1`? What should be the return value in that case?
* Line 94: What is the purpose of this `malloc()`? What is the result of lines 94 and 95?
* Line 98: `<=`? If `array->size = 8` and `i = 8`, what happens?

In `lstmrg()`:
* Lines 54 & 84: Creating a head node for the merged list is not a bad idea, but remember that the final result does not include the node that you created. (Your comment on 84 is spot on.)
* Line 60: Similar to line 94 in `merge-k-sorted-lists()`, what is the purpose of this malloc? And how does this line interact with lines 63, 69, 74, & 79?
* Lines 61 - 71: Here you detect when one of the lists is empty, and you prevent the loop from happening again with `t = 0`. But, you don't stop _that iteration_ of the loop. Meaning that on line 72 both pointer get dereferenced even though you've already determined that one of them is `NULL`. Consider using `break;` or `continue;` statements.