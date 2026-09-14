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
#define numNames 8
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
	const IntArray *a;
	ia_init(a);
	for(int i=0; i<50; i++){
		printf("push %2d: size=%2zu cap=%2zu data=%p\n", i, ia_size(a),ia_capacity(a) (void *) a->data);	
	}


    /* ---- 2. Names: the two-level ownership -----------------------------
     * TODO: build an array of my_strdup'd names (a char** you malloc, or a
     * fixed char *nacmes[N]), sort it with my_strcmp (your own insertion
     * sort is fine), print the sorted names -- then free EVERY string AND
     * (if malloc'd) the array of pointers. Two levels, two kinds of free.
     */

	//Creating array of my_strdup'd names
	const char *names[numNames] = { "Lili", "Jin", "Kazuya", "Lidia", "King", "Lee", "Bryan", "Asuka"};
	char **ptrArray = (char**)malloc(numNames*sizeof(char*));
	if(ptrArray == NULL){
		return 1;
	}
	for(int i=0;, i< numNames; i++){
	*(ptrArray+i) = my_strdup(names[i]);
	if(*(ptrArray+i) == NULL){
		return 1;
	}
	}

	//Sorting names with my_strcmp
	for(int i=1; i< numNames; i++){
	int temp = (*ptrArray+i);
	int j = i;
	while( j>0 && my_strcmp(*ptrArray+(j-1),temp) > 0){
		*ptrArray+j = *ptrArray+(j-1)
		j--;
	}
	*ptrArray+j = temp;
	}
	printf("Sorted Names:");
	for(int i=0; i<numNames; i++){
	printf("%s, ", *ptrArray+i);
	}

	//Free every String AND the array of pointers
	for(int i=0; i<numNames; i++){
		free(*(ptrArray+i));
		*(ptrArray+i) = NULL;
	}
	free(ptrArray);
	ptrArray = NULL;
    /* ---- 3. Failure paths ----------------------------------------------
     * TODO, each printed so the grader can see it happened:
     *   - ia_pop_back on an empty array          (expect return 0)
     *   - ia_get / ia_set out of range           (expect ia_set -> 0)
     *   - ia_destroy called twice                (expect: no crash)
     *   - my_strcpy_safe into a too-small buffer (expect return 0, dst "")
     */

	//ia_pop_back TEST
	int *out;
	ia_clear(a);
	int result = ia_pop_back(a,out);
	printf("ia_pop_back on empty array Result: %d", result);

	//ia_get / ia_set TEST
	size_t index = 1000;
	ia_init(a);
	ia_push_back(a,10);
	int getTest = ia_get(a,index);
	int setTest = ia_set(a,index,67);
	printf("get/set Test Results: get-%d set-%d", getTest, setTest);

	//ia_destroy twice
	ia_destroy(a);
	ia_destroy(a);

	//strcpy_safe Test
	char buffer[5];
	char string[7] = "Testing";
	int safeTest = my_strcpy_safe(buffer, sizeof(buffer), string[0]);
	printf("strcpy_safe Results: return - %d, dst - %s",safeTest, string );
    printf("lab1 driver: TODO\n");
    return 0;
}
