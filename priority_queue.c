#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char*    value;
    int      priority;
} element_t;

void swap(element_t** heap, int aidx, int bidx)
{
    element_t* tmp;
    tmp = heap[aidx];
    heap[aidx] = heap[bidx];
    heap[bidx] = tmp;
}

int push_heap(element_t** heap, int hsize, int* htop, element_t* element)
{
    int cidx, pidx;

    if( hsize > *htop ) {
        // construct max heap
        heap[*htop] = element;
        // go through parent links
        cidx = *htop;
        while( cidx != 0 ) {
            pidx = (cidx-1)/2; // parent
            if( heap[cidx]->priority > heap[pidx]->priority ) {
                swap(heap, cidx, pidx);
            }
            cidx = pidx;
        }
        *htop += 1;
        return 1;
    } else {
        return 0;
    }
}

element_t* pop_heap(element_t** heap, int hsize, int* htop)
{
    int cidx, pidx;
    int lcidx, rcidx;
    element_t* element;

    if( *htop == 0 ) return NULL;
    // pop heap[0]
    element = heap[0];
    // move last to root
    swap(heap, 0, *htop - 1);
    *htop -= 1;
    // construct max heap
    // go through child links
    pidx = 0;
    while( pidx < hsize ) {
        lcidx = pidx*2 + 1;  // left child
        rcidx = pidx*2 + 2;  // right child
        if( lcidx >= *htop ) break;
        if( rcidx >= *htop ) { // no right child
            cidx = lcidx;
        } else {
            if( heap[lcidx]->priority > heap[rcidx]->priority ) cidx = lcidx;
            else cidx = rcidx;
        }
        if( heap[cidx]->priority > heap[pidx]->priority ) {
            swap(heap, cidx, pidx);
        }
        pidx = cidx;
    }
    return element;
}

void print_heap(element_t** heap, int htop)
{
    int i;
    for( i = 0; i < htop; i++ ) {
        fprintf(stdout, "(%s, %d) ", heap[i]->value, heap[i]->priority);
    }
    fprintf(stdout, "\n");
}

int main(int argc, char** argv)
{
    element_t    stream[11] = {
        {"a", 8},
        {"b", 9},
        {"c", 1},
        {"d", 7},
        {"e", 5},
        {"f", 6},
        {"g", 2},
        {"h", 10},
        {"i", 3},
        {"j", 5},
        {"k", 8},
    };

    element_t**    heap;
    int            hsize, htop;
    int            i;
    int            ret;
    element_t*     element;

    hsize = 8; // heap size
    heap = (element_t**)malloc( hsize * sizeof(element_t*));
    htop = 0;  // number of items in heap

    for( i = 0; i < 11; i++ ) {
        ret = push_heap(heap, hsize, &htop, &stream[i]);
        if( ret ) {
            fprintf(stdout, "[%d] (%s, %d) item pushed\n", i, stream[i].value, stream[i].priority);
            print_heap(heap, htop);
        } else {
            element = pop_heap(heap, hsize, &htop);
            fprintf(stdout, "[%d] (%s, %d) item popped\n", i, element->value, element->priority);
            print_heap(heap, htop);
            ret = push_heap(heap, hsize, &htop, &stream[i]);
            if( ret ) {
                fprintf(stdout, "[%d] (%s, %d) item pushed\n", i, stream[i].value, stream[i].priority);
                print_heap(heap, htop);
            }
        }
    }

    if( heap ) free(heap);
    return 0;
}
