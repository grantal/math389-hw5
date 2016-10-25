#ifndef __heap_h
#define __heap_h

typedef struct _heap {
    int *array;
    int nokids; //number of children of each node
} heap;

heap *new_heap(int nokids, int size);
void heap_insert(heap *self, int value);
