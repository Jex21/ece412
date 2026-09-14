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

Realloc advances addresses only after the first growth while malloc+copy+free advances addresses after every single growth.

Realloc(Buffer only moved at first doubling):
push  3: size= 4 cap= 4 data=0xedbeb0
push  4: size= 5 cap= 8 data=0xedc2e0
push  8: size= 9 cap=16 data=0xedc2e0

malloc(Buffer moved at every doubling):
push  3: size= 4 cap= 4 data=0x1c21eb0
push  4: size= 5 cap= 8 data=0x1c222e0
push  8: size= 9 cap=16 data=0x1c22310

## W3. The `realloc` trap

`a->data = (int *)realloc(a->data, n);` is a memory leak whenever `realloc` fails. Explain exactly what is lost, and why assigning to a temporary first fixes it. (Your `ia_grow` must also *do* it correctly — this question is the "say why.")

The block of memory allocated to a->data is lost because if the realloc call fails then it returns NULL and since there is no NULL check between the realloc return and assigned the value to a->data, the pointer to your memory block of data is now NULL meaning you can no longer refer to the block of memory allocated for data. Assigning the realloc return to a temp variable fixes this because you are able to perform a NULL check to see if the reallocation worked or not and if it does work, then you can assign the new pointer to a->data, if it does return NULL, then you don't touch the data pointer at all.  

## W4. The stale pointer after growth

Why is holding `int *p = &a->data[0];` across an `ia_push_back` a use-after-free? Two or three sentences. 
Holding int *p = &a->data[0] across an ia_push_back is a use-after free because inside of ia_push_back, after the first doubling, the buffer moves to a new address for both methods and the previous buffer pointer, which is equal to the pointer p, is NULL and the actual block of data is freed. Since it is freed by realloc or a free call after a malloc, the pointer p holds onto a pointer to the old buffer that is already been freed, thus it is a use-after-free.

## W5. Two-level ownership

Your driver builds an array of `my_strdup`'d strings. Describe the two levels of ownership and the order you freed them in. What does valgrind report if you free the array of pointers but not the strings — which leak category?

The top level is ptrArray which was allocated by one malloc call and is the second to be freed. The 2nd level is *(ptrArray+i) which is allocated by my_strdup calls and this is the first level that is freed. When i free the array of pointers and no the strings, Valgrind reports *(ptrArray+i) as definitely lost memory because we lost the pointer to our array of pointers to our char arrays (strings) (the addresses in our top layer). 

## W6. The `+1`, and the cast

Why does `my_strdup` allocate `my_strlen(s) + 1` bytes — what goes wrong with exactly `my_strlen(s)`, and which tool catches it? And note the C/C++ difference on `malloc`'s return value (quiz material).
my_strdup allocates my_strlen(s) +1 because it is including the string's null terminator '\0'. When you don't include the +1, a heap overflow occurs because you will write one extra char to your memory block that was only allocated for the char array without the null terminator. Valgrind is the tool that catches this mistake. 

## W7. Unsigned comparison

Why must `my_strcmp` compare as `unsigned char`? Give the concrete example from the handout (`"\xFF"` vs `"a"`) and say what plain signed `char` gets wrong on the ECE Linux server machines. 
my_strcmp uses unsigned char to compare char's because with higher values, such as "\xFF", the value may be interpreted as a negative number rather than a large number since plain char is interpreted as signed char on the ECE linux server machines. That means when you compare two char's, the returned value may be wrong. For example, in signed char, \xFF is -1 and "a" is 65, so it would return a negative number saying that the char 0xFF comes before "a" lexicographically when in reality 0xFF comes after "a" lexicographically which can be seen when using unsigned char where 0xFF is 255 and "a" is 65 and since we can see 255 > 65, we get the correct answer that 0xFF comes after "a"/

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
