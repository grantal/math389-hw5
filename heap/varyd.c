// varyd.c
// n remains constant, d changes
#include <stdio.h>
#include "heap.h"
#include <time.h>
#include <stdlib.h>

// number of insersion tests to average
const int ACCURACY = 1000;
// how big to make the heaps
const int SIZE = 100000;
// how many children at max
const int MAX_KIDS = 100;


int main () {
    // generate ACCURACY arrays of SIZE random numbers so that the
    // random numbers are the same for each heap
    int **randlists = (int **)malloc(ACCURACY*sizeof(int *));
    srand(time(NULL));
    int i;
    int j;
    for (j = 0; j < ACCURACY; j++){
        randlists[j] = (int *)malloc(SIZE*sizeof(int));
        for (i = 0; i < SIZE; i++){
            // random numbers will be capped at SIZE*10 so that 
            // theres more diversity than if we capped it at SIZE
            int r = rand() % (SIZE*10);   
            randlists[j][i] = r;
        }
    }

    // format
    printf("# number of children\tcycles,\n");
    int d; // number of kids per node
    for (d = 2; d <= MAX_KIDS; d++) {
        // test each array of random numbers
        long timesum = 0l;
        for (j = 0; j < ACCURACY; j++){
            heap *h = new_heap(d, SIZE);
            clock_t start;
            clock_t diff;
            start = clock();
            for (i = 0; i < SIZE; i++){
                int r = randlists[j][i];
                heap_insert(h, r);
            }
            diff = clock() - start;
            timesum += diff;
            // cleaning up
            free(h->array);
            free(h);
        }
        // print the average of the tests
        printf("%d\t%ld\n", d, timesum/ACCURACY);
    }
    
}
