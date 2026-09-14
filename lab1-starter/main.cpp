/*
 * ================================================================
 * Filename:    main.cpp
 * Description: ECE 412 Lab 1, Part C -- driver. Exercises Parts A
 *              and B, including every failure path you can reach.
 *              This whole program must be valgrind-clean.
 * Created:     9/13/2026
 * EID:         jrp5528
 * Email:       jrp5528@my.utexas.edu
 * Author:      Jericho Perez
 * Provenance:  I certify that all code contained herein is mine
 *              alone except where otherwise noted.
 * ================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "mystr.h"

int main(void) {
    /* ---- 1. Growth demo ------------------------------------------------
     * TODO: push at least 40 values so the array doubles at least three
     * times (4 -> 8 -> 16 -> 32 -> 64). After EACH push print size, cap,
     * and the buffer address, so the doublings -- and any address change --
     * are visible:
     *
     *     printf("push %2d: size=%2zu cap=%2zu data=%p\n",
     *            v, ia_size(&a), ia_capacity(&a), (void *)a.data);
     *
     * Circle in your output where the address changed (or did not) and
     * connect it to your WRITEUP's realloc-vs-manual answer.
     */
	

    /* ---- 2. Names: the two-level ownership -----------------------------
     * TODO: build an array of my_strdup'd names (a char** you malloc, or a
     * fixed char *names[N]), sort it with my_strcmp (your own insertion
     * sort is fine), print the sorted names -- then free EVERY string AND
     * (if malloc'd) the array of pointers. Two levels, two kinds of free.
     */

    /* ---- 3. Failure paths ----------------------------------------------
     * TODO, each printed so the grader can see it happened:
     *   - ia_pop_back on an empty array          (expect return 0)
     *   - ia_get / ia_set out of range           (expect ia_set -> 0)
     *   - ia_destroy called twice                (expect: no crash)
     *   - my_strcpy_safe into a too-small buffer (expect return 0, dst "")
     */

    printf("lab1 driver: TODO\n");
    return 0;
}
