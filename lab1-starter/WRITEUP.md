# ECE 412 — Lab 1 Writeup

**Name:**
**EID:**
**Machine used (hostname):**

*Answer in your own words — two to four sentences each unless noted. These are the explanation points of the rubric; code alone does not earn them.*

---

## W1. The growth policy

State your growth policy (starting capacity, growth factor, when growth triggers), and give the capacity sequence your 40-push driver actually produced.

## W2. `realloc` vs. the manual version

You implemented growth both ways. What did `realloc` do that your malloc+copy+free version did not (or vice versa)? Include the **addresses you observed**: paste two or three `data=` lines from your driver output for each version and say whether the buffer moved at each doubling.

## W3. The `realloc` trap

`a->data = (int *)realloc(a->data, n);` is a memory leak whenever `realloc` fails. Explain exactly what is lost, and why assigning to a temporary first fixes it. (Your `ia_grow` must also *do* it correctly — this question is the "say why.")

## W4. The stale pointer after growth

Why is holding `int *p = &a->data[0];` across an `ia_push_back` a use-after-free? Two or three sentences. 

## W5. Two-level ownership

Your driver builds an array of `my_strdup`'d strings. Describe the two levels of ownership and the order you freed them in. What does valgrind report if you free the array of pointers but not the strings — which leak category?

## W6. The `+1`, and the cast

Why does `my_strdup` allocate `my_strlen(s) + 1` bytes — what goes wrong with exactly `my_strlen(s)`, and which tool catches it? And note the C/C++ difference on `malloc`'s return value (quiz material).

## W7. Unsigned comparison

Why must `my_strcmp` compare as `unsigned char`? Give the concrete example from the handout (`"\xFF"` vs `"a"`) and say what plain signed `char` gets wrong on the ECE Linux server machines. 

## W8. The valgrind summary (paste)

Paste the full summary block of

`valgrind --leak-check=full --show-leak-kinds=all ./toolkit`

— the lines from `HEAP SUMMARY` through `ERROR SUMMARY`. It must show 0 errors, 0 bytes definitely lost, 0 bytes indirectly lost.

```
(paste here)
```

## W9. AI assistance

Name **one specific bug you had to fix in AI-suggested code** on this lab (what the assistant wrote, why it was wrong, how you fixed it) — or state plainly that you wrote the lab unaided. AI-assisted lines in your source carry the syllabus citation comment.

## W10. Anything that fought you *(optional, genuinely useful)*
