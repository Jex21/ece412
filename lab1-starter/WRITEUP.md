# ECE 412 — Lab 1 Writeup

**Name:Jericho Perez**
**EID:jrp5528**
**Machine used (hostname):mario.ece.utexas.edu**

*Answer in your own words — two to four sentences each unless noted. These are the explanation points of the rubric; code alone does not earn them.*

---

## W1. The growth policy

State your growth policy (starting capacity, growth factor, when growth triggers), and give the capacity sequence your 40-push driver actually produced.

The starting capacity is 4, the growth factor is 2 as it doubles on the growth trigger which occurs when the size of the array is equal to the capacity of the array. The capacity sequence by 40-push driver actually produced was 4 -> 8 -> 16 -> 32 -> 64.

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
my_strdup allocates my_strlen(s) +1 because it is including the string's null terminator '\0'. When you don't include the +1, your string will never be terminated and it will continue to read the addresses after the last char of the char array. This is caught by 

## W7. Unsigned comparison

Why must `my_strcmp` compare as `unsigned char`? Give the concrete example from the handout (`"\xFF"` vs `"a"`) and say what plain signed `char` gets wrong on the ECE Linux server machines. 


## W8. The valgrind summary (paste)

Paste the full summary block of

`valgrind --leak-check=full --show-leak-kinds=all ./toolkit`

— the lines from `HEAP SUMMARY` through `ERROR SUMMARY`. It must show 0 errors, 0 bytes definitely lost, 0 bytes indirectly lost.

```
==2973239== HEAP SUMMARY:
==2973239==     in use at exit: 0 bytes in 0 blocks
==2973239==   total heap usage: 17 allocs, 17 frees, 74,347 bytes allocated
==2973239==
==2973239== All heap blocks were freed -- no leaks are possible
==2973239==
==2973239== For lists of detected and suppressed errors, rerun with: -s
==2973239== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## W9. AI assistance

Name **one specific bug you had to fix in AI-suggested code** on this lab (what the assistant wrote, why it was wrong, how you fixed it) — or state plainly that you wrote the lab unaided. AI-assisted lines in your source carry the syllabus citation comment.
I wrote my lab unaided without Ai-generated code.

## W10. Anything that fought you *(optional, genuinely useful)*
