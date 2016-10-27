#include "lib.h"
#include <limits.h>

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
