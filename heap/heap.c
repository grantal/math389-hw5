#include "heap.h"

//size is size of the array
heap *new_heap(int nokids, int size){
    heap *n = (heap *)malloc(sizeof(heap));
    n->nokids = nokids;
    n->array = (int *)malloc(size*sizeof(int));
}

void heap_insert(heap *self, int value){
    
}
