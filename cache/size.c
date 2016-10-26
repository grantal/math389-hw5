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
const unsigned long MAX_MEMORY = 5000000;


// gets an array size and an array then uses
// that array by placing items in it and getting items out
void reck_it(int arraysize, unsigned char* list){
    // using a char array since a char takes up 1 byte
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
}



int main(){
    
    unsigned long mem_size;
    printf("function, input, cycles,\n");
    for ( mem_size = 1000; mem_size < MAX_MEMORY; mem_size += 1000){ 
        // run test 'ACCURACY' times and then average the time
        int i;
        long timesum;
        for (i = 0; i < ACCURACY; i++){
            unsigned char *list = (unsigned char *)malloc(mem_size*sizeof(unsigned char)); 
            clock_t start;
            clock_t end;
            clock_t diff;
            start = clock();
            reck_it(mem_size, list);
            end = clock();
            diff = end - start;
            timesum += diff;
            free(list);
        }
        printf("reck_it, %lu, %ld,\n", mem_size, timesum/ACCURACY);
    }
}







