#include "heap.h"
#include <limits.h>
#include <stdlib.h>

//size is size of the array
heap *new_heap(int nokids, int size){
    heap *n = (heap *)malloc(sizeof(heap));
    n->nokids = nokids;
    n->array = (int *)malloc(size*sizeof(int));
    // where to put new numbers 
    n->current_index = 1;
}

void heap_insert(heap *self, int value){
    //insert
    self->array[self->current_index] = value;
    //restore heap property
    int heap_property = 0;
    int i = self->current_index;
    while (!heap_property && i > 0){
        int currval = self->array[i];
        int parent = self->array[i/self->nokids];

        if (parent > currval){
            heap_property = 1;
        }
        // if parent is less than child, swap em
        else{
            self->array[i] = parent;
            self->array[i/self->nokids] = currval;
            i = i/self->nokids;
        }
    }
    self->current_index++;
}

