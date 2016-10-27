/*
assoc.c
this will try to find the degree of associativity in the cache
I will do this by making a bunch of arrays of size CACHE_SIZE
and accessing them all and timing that
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lib.h"

const int CACHE_SIZE = 256000;
// max number of arrays to build per step
const int ASSOC_MAX = 20;
const int ACCURACY = 1;


int main() {
    printf("# number of arrays\ttime to access one\n"); 
    int n; // number of arrays
    unsigned char *arrays[ASSOC_MAX]; //list to hold arrays
    for (n = 1; n <= ASSOC_MAX; n++){
        // allocate an array and use all the arrays so that they're
        // in the cache
        unsigned char *list = (unsigned char *)malloc(CACHE_SIZE*sizeof(unsigned char)); 
        arrays[n-1] = list;
        long timesum = 0l;
        int j; 
        // run test ACCURACY times
        for (j = 0; j < ACCURACY; j++){
            int i;
            for(i = 0; i < n; i++){
                reck_it(CACHE_SIZE, arrays[i]);
            }
            // time access to arrays in the same order so the ones used
            // most recently will be accessed last
            clock_t start;
            clock_t diff;
            start = clock();
            for(i = 0; i < n; i++){
                reck_it(CACHE_SIZE, arrays[i]);
            }
            diff = clock() - start;
            // want to print time per array
            timesum += diff/n;
        }
        printf("%d\t%ld\n",n,timesum/ACCURACY);
        
    }
    // cleanup
    int i;
    for (i = 0; i < ASSOC_MAX; i++){
        free(arrays[i]);
    }

}
