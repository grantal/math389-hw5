/*
size.c
Alex Grant
Math 389
This will make data on the time a function takes relative to how
much memeory it uses in order to extimate the cache size
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


// gets an array size and uses all of it
void reck_it(int arraysize){
    int *list = (int *)malloc(arraysize*sizeof(int));
    int i;
    for (i = 0; i < arraysize; i++){
        list[i] = i;
    }
    int y;
    int k;
    for (i = 0; i < arraysize; i++){
        y = list[i]; 
        k = y + 10;
    }
}



int main(){
    
    clock_t start;
    clock_t diff;
    unsigned long mem_size = 100000000;
    printf("function, input, cycles,\n");
    for ( mem_size = 100000; mem_size < ULONG_MAX; mem_size = mem_size*10){ 
        start = clock();
        reck_it(mem_size);
        diff = clock() - start;
    
        printf("reck_it, %lu, %ld,\n", mem_size, diff);
    }
}







