/*
 * ================================================================
 * Filename:    mystr.cpp
 * Description: ECE 412 Lab 1, Part A -- C string utilities,
 *              implemented from scratch. No <cstring> anywhere.
 * Created:     09/12/2026
 * EID:         Jrp5528
 * Email:       jrp5528@my.utexas.edu
 * Author:      Jericho Perez
 * Provenance:  I certify that all code contained herein is mine
 *              alone except where otherwise noted.
 * ================================================================
 */

#include <stdlib.h>    /* malloc, free -- NOT <cstring>! */

#include "mystr.h"

size_t my_strlen(const char *s) {
    /* TODO: walk to the '\0'. my_strlen("") must be 0. */
    size_t count = 0;
    while(*s != '\0'){
	count++;
	s++;
    }
    return count;
}

char *my_strdup(const char *s) {
    /* TODO: malloc exactly the right number of bytes (how many?),
     * copy s including the terminator, return the new buffer.
     * Return NULL if malloc fails. Remember: in C++, malloc's
     * void* must be cast: (char *)malloc(...). */
   size_t length = my_strlen(s);
   char *ptr = (char*)malloc(length+1);
   if(ptr==NULL){return NULL;}
   for(size_t i =0;i<my_strlen(s)+1;i++){
	*(ptr+i)= *(s+i);
   }
   free(ptr);
    return ptr;
}

int my_strcmp(const char *a, const char *b) {
    /* TODO: the strcmp contract. Compare as UNSIGNED CHAR --
     * plain char is signed on mario, and "\xFF" vs "a" will
     * come out with the wrong sign if you compare as char. */	
    const unsigned char *ptra = (const unsigned char*)a;
    const unsigned char *ptrb = (const unsigned char*)b;
    while(*ptra != '\0' && *ptrb != '\0' ){
	if((int)*ptra-(int)*ptrb != 0){return (int)*ptra-(int)*ptrb;}
	ptra++;
	ptrb++;
    }
    return(int)*ptra - (int)*ptrb  ;
}

int my_strcpy_safe(char *dst, size_t dstsize, const char *src) {
    /* TODO: copy src into dst, never writing more than dstsize
     * bytes INCLUDING the terminator. On success return 1.
     * If src does not fit, leave dst a valid empty string and
     * return 0. Think about dstsize == 0 before you write. */
   size_t length = my_strlen(s);	
    if(dstsize == 0){return 0;}
    if(dstsize >=  length+1){
    for(size_t i=0; i< length+1; i++){
	*(dst+i) = *(src+i);
    }
    return 1;
    }else{
	*dst = '\0';
	return 0;
    }
}
