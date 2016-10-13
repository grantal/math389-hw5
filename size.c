/*
size.c
Alex Grant
Math 389
This will make data on the time a function takes relative to how
much memeory it uses in order to extimate the cache size
Output should be in csv format but you'll have to use a '>' to capture it
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// number of times we'll run the test for each arraysize
const int accuracy = 10; 


// gets an array size and uses all of it
void reck_it(int arraysize){
    int *list = (int *)malloc(arraysize*sizeof(int)); 
    unsigned long i;
    for (i = 0; i < arraysize; i++){
        list[i] = i;
    }
    int y;
    int k;
    for (i = 0; i < arraysize; i++){
        y = list[i]; 
        k = y + 10;
    }
    free(list);
}



int main(){
    
    clock_t start;
    clock_t diff;
    unsigned long mem_size;
    printf("function, input, cycles,\n");
    for ( mem_size = 2; mem_size < ULONG_MAX; mem_size = mem_size*2){ 
        // run test 'accuracy' times and then average the time
        int i;
        long timesum;
        for (i = 0; i < accuracy; i++){
            start = clock();
            reck_it(mem_size);
            diff = clock() - start;
            timesum += diff;
        }
        printf("reck_it, %lu, %ld,\n", mem_size, timesum/accuracy);
    }
}







