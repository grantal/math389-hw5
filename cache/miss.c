/*
miss.c
Alex Grant
Math 389
this will compute the miss penalties
it will try to access some parts of memory after the cache is full
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "lib.h"

// number of times we'll run the test
const int ACCURACY = 100;
// memory size to be used before test
const unsigned long MEMORY = 8000000;
// memory size of array that estimates miss penalty

int main(){
    
    // run test 'ACCURACY' times and then average the time
    int i;
    long timesum = 0l;
    for (i = 0; i < ACCURACY; i++){
        unsigned char *list = (unsigned char *)malloc(MEMORY*sizeof(unsigned char)); 
        // just space for one element
        unsigned char *element = (unsigned char *)malloc(sizeof(unsigned char)); 
        element[0] = (i % CHAR_MAX);
        //gets the element out of the cache
        reck_it(MEMORY, list);
        //timing
        clock_t start;
        clock_t diff;
        int foo;
        start = clock();
        foo = element[0];
        diff = clock() - start;
        timesum += diff;
        free(element);
        free(list);
    }
    printf("estimated miss penalty: %ld\n", timesum/ACCURACY);
}







