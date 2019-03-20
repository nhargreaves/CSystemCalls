/*
 * Replace the following string of 0s with your student number
 * 000000000
 */
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arraylib.h"

/* error message format for fatalerror */
static const char *ERR_FMT = "%s:%d - %s, errno %d: %s\n";

/***************************************************************************/
/***** ARRAYLIB.H IMPLEMENTATIONS ******************************************/
/***************************************************************************/

/* In the following newarray function:
 *  - dynamically allocate an array struct
 *  - allocate an array of given length
 *  - assign length and pointer to fields of array struct
 *  - return pointer to array struct
 * The normal and error condition behaviour of newarray must comply with
 * the function's specification in the comments in arraylib.h
 */
array *newarray(int len) {
    /* Replace the following with function implementation */ 
   array *ai = malloc(len);
   
   if (len<1) {
	   delarray(ai);
	   errno = EINVAL;
	   return NULL;
   }
    
    return ai;
}

/* see get specification comments in arraylib.h */
int get(array *arr, int idx) {
    /* Replace the following with function implementation */ 
    fatalerror(__LINE__, "get not implemented");
    
    return INT_MIN;
}
                
/* see set specification comments in arraylib.h */
void set(array *arr, int idx, int value) {
    /* Replace the following with function implementation */ 
    fatalerror(__LINE__, "set not implemented");
}

/* see foreach specification comments in arraylib.h */
void foreach(array *arr, applyfunction applyf) { 
    /* Replace the following with function implementation */ 
    fatalerror(__LINE__, "foreach not implemented");
}

/* see print specification comments in arraylib.h */
void print(FILE *stream, array *arr) {
    /* Replace the following with function implementation */ 
    fatalerror(__LINE__, "print not implemented");
}
        
/***************************************************************************/
/***** THE FOLLOWING FUNCTIONS ARE IMPLEMENTED FOR YOU - DO NOT CHANGE *****/
/***************************************************************************/

/* see println comments in arraylib.h */
void println(FILE *stream, array *arr) {
    print(stream, arr);
    fprintf(stream, "\n");
}

/* see delearray comments in arraylib.h */
void delarray(array *arr) {
    if (arr) { 
        if (arr->ai) 
            free(arr->ai);
        free(arr);
    }
}

/* see fatalerror comments in arraylib.h */
void fatalerror(int line, char *msg) {
    fprintf(stderr, ERR_FMT, __FILE__, line, msg, errno, strerror(errno));
    exit(EXIT_FAILURE);
}

/* see newarray_e comments in arraylib.h */
array *newarray_e(int len) {
    array *arr = newarray(len);
    
    if (!arr)
        fatalerror(__LINE__, "array allocation failed");
        
    return arr;
}

/* see get_e comments in arraylib.h */
int get_e(array *arr, int idx) {
    int val = get(arr, idx);
    
    if (val == INT_MIN && errno == EINVAL)
        fatalerror(__LINE__, "null array or index out of bounds");
    
    return val;
}
        
        
/* see set_e comments in arraylib.h */
void set_e(array *arr, int idx, int value) {
    set(arr, idx, value);
    
    if (errno == EINVAL)
        fatalerror(__LINE__, "null array or index out of bounds");
}

/***************************************************************************/

