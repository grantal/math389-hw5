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
const int ACCURACY = 10; 
// max memory to count up to (in bytes)
const unsigned long MAX_MEMORY = 2147483648;


// gets an array size and makes an array of that size and then uses
// that array by placing items in it and getting items out
void reck_it(int arraysize){
    // using a char array since a char takes up 1 byte
    unsigned char *list = (unsigned char *)malloc(arraysize*sizeof(unsigned char)); 
    unsigned long i;
    for (i = 0; i < arraysize; i++){
        list[i] = (unsigned char)(i % UCHAR_MAX);
    }
    unsigned char y;
    unsigned char k;
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
    for ( mem_size = 2; mem_size < MAX_MEMORY; mem_size = mem_size*2){ 
        // run test 'ACCURACY' times and then average the time
        int i;
        long timesum;
        for (i = 0; i < ACCURACY; i++){
            start = clock();
            reck_it(mem_size);
            diff = clock() - start;
            timesum += diff;
        }
        printf("reck_it, %lu, %ld,\n", mem_size, timesum/ACCURACY);
    }
}







