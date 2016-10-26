#include <stdio.h>
#include "heap.h"
#include <time.h>
#include <stdlib.h>

// number of insersion tests to average
const int ACCURACY = 10;
// how big to make the heaps
const int SIZE = 100000;


int main () {
    // generate ACCURACY arrays of SIZE random numbers so that the
    // random numbers are the same for each heap
    int randlists[ACCURACY][SIZE];
    srand(time(NULL));
    int i;
    int j;
    for (j = 0; j < ACCURACY; j++){
        for (i = 0; i < SIZE; i++){
            // random numbers will be capped at SIZE*10 so that 
            // theres more diversity than if we capped it at SIZE
            int r = rand() % (SIZE*10);   
            randlists[j][i] = r;
        }
    }

    // format
    printf("number of children, cycles,\n");
    int d; // number of kids per node
    for (d = 2; d <= 10; d++) {
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
        printf("%d, %ld,\n", d, timesum/ACCURACY);
    }
    
}
