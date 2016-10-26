#include <stdio.h>
#include "heap.h"
#include <time.h>
#include <stdlib.h>


int main () {
    heap *h = new_heap(2, 100);
    srand(time(NULL));
    int i;
    for (i = 0; i < 100; i++){
        int r = rand() % 1000;   
        heap_insert(h, r);
    }
    int nextparent = (h->current_index-1) / h->nokids;
    for (i = h->current_index - 1; i > 0 ; i--){
        if (nextparent == i){
            nextparent = i/h->nokids;
            printf("\n");
        }
        printf("%d ",h->array[i]);
    }
    printf("\n");
}
