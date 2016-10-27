/*
varyn.c
File to run tests where the size of the heap changes but 
the d value does not
*/
#include <stdio.h>
#include "heap.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// number of insersion tests to average
const int ACCURACY = 10;
// how big to make the heaps
const int MAX_SIZE = 10000000;


int main (int argc, char *argv[]) {
    srand(time(NULL));
    // get d from args    
    int d = atoi(argv[1]);
    // format
    printf("n\tcycles per element\n");
    int n; // size of the heap
    for (n = 100000; n <= MAX_SIZE; n += 100000) {
        // time 
        long timesum = 0l;
        int j;
        for (j = 0; j < ACCURACY; j++){
            heap *h = new_heap(d, n+1);
            clock_t start;
            clock_t diff;
            int i;
            start = clock();
            for (i = 0; i < n; i++){
                int r = rand() % INT_MAX; 
                heap_insert(h, r);
            }
            diff = clock() - start;
            timesum += diff;
            // cleaning up
            free(h->array);
            free(h);
        }
        // print the sum time per element of the tests
        printf("%d\t%ld\n", n, timesum/(n*ACCURACY));
    }
    
}
