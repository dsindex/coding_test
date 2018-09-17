#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* heap, int idx, int pidx)
{
    int tmp;
    tmp = heap[idx];
    heap[idx] = heap[pidx];
    heap[pidx] = tmp;
}

void push_heap(int* heap, int hsize, int* htop, int item)
{
    int cidx, pidx;
    int lcidx, rcidx;

    if( hsize > *htop ) {
        // construct min heap
        heap[*htop] = item;
        // go through parent links
        cidx = *htop;
        while( cidx != 0 ) {
            pidx = (cidx-1)/2; // parent
            if( heap[cidx] < heap[pidx] ) {
                swap(heap, cidx, pidx);
            }
            cidx = pidx;
        }
        *htop += 1;
    } else {
        // heap[0] < item
        // pop heap[0] and replace it with item
        heap[0] = item;
        // go through child links
        pidx = 0;
        while( pidx < hsize ) {
            lcidx = pidx*2 + 1;  // left child
            rcidx = pidx*2 + 2;  // right child
            if( lcidx >= hsize ) break;
            if( rcidx >= hsize ) { // no right child
                cidx = lcidx;
            } else {
                if( heap[lcidx] > heap[rcidx] ) cidx = rcidx;
                else cidx = lcidx;
            }
            if( heap[pidx] > heap[cidx] ) {
                swap(heap, pidx, cidx);
            }
            pidx = cidx;
        }
    }
}

int main(int argc, char** argv)
{
    //int stream[11] = {8, 9, 1, 7, 5, 6, 2, 10, 3, 5, 8}; // -> 7 8 8 9 10
    int stream[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // -> 7 8 11 9 10
    int topk = 5;
    int* heap;
    int hsize;
    int htop;
    int i;

    // create min heap
    hsize = topk; // heap size
    heap = (int*)malloc(hsize * sizeof(int));
    htop = 0;     // number of items in heap

    for( i = 0; i < 11; i++ ) {
        if( htop < hsize || heap[0] < stream[i] ) {
            push_heap(heap, hsize, &htop, stream[i]);
        }
    }

    for( i = 0; i < hsize; i++ ) {
        fprintf(stdout, "%d ", heap[i]);
    }
    fprintf(stdout, "\n");

    if( heap ) free(heap);
    return 0;
}
