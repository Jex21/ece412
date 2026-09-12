/*
 * ================================================================
 * Filename:    mystr.cpp
 * Description: ECE 412 Lab 1, Part A -- C string utilities,
 *              implemented from scratch. No <cstring> anywhere.
 * Created:     TODO
 * EID:         TODO
 * Email:       TODO
 * Author:      TODO
 * Provenance:  I certify that all code contained herein is mine
 *              alone except where otherwise noted.
 * ================================================================
 */

#include <stdlib.h>    /* malloc, free -- NOT <cstring>! */

#include "mystr.h"

size_t my_strlen(const char *s) {
    /* TODO: walk to the '\0'. my_strlen("") must be 0. */
    (void)s;
    return 0;
}

char *my_strdup(const char *s) {
    /* TODO: malloc exactly the right number of bytes (how many?),
     * copy s including the terminator, return the new buffer.
     * Return NULL if malloc fails. Remember: in C++, malloc's
     * void* must be cast: (char *)malloc(...). */
    (void)s;
    return NULL;
}

int my_strcmp(const char *a, const char *b) {
    /* TODO: the strcmp contract. Compare as UNSIGNED CHAR --
     * plain char is signed on mario, and "\xFF" vs "a" will
     * come out with the wrong sign if you compare as char. */
    (void)a;
    (void)b;
    return 0;
}

int my_strcpy_safe(char *dst, size_t dstsize, const char *src) {
    /* TODO: copy src into dst, never writing more than dstsize
     * bytes INCLUDING the terminator. On success return 1.
     * If src does not fit, leave dst a valid empty string and
     * return 0. Think about dstsize == 0 before you write. */
    (void)dst;
    (void)dstsize;
    (void)src;
    return 0;
}
