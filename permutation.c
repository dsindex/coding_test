#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* list, int idx, int pidx)
{
    int tmp;
    tmp = list[idx];
    list[idx] = list[pidx];
    list[pidx] = tmp;
}

void permute(int* list, int begin, int end, int r)
{
    int i, j;

    if( begin == r ) {
        for( j = 0; j < r ; j++ ) { 
            fprintf(stdout, "%d ", list[j]);
        }
        fprintf(stdout, "\n");
    } else {
        for( i = begin; i < end; i++ ) {
            swap(list, begin, i);
            permute(list, begin+1, end, r);
            swap(list, begin, i);
        }
    }
}

int main(int argc, char** argv)
{
    int list[5] = {1,2,3,4,5};
    int n, r;

    n = 5;
    r = 3;

    // 5P3
    permute(list, 0, 5, 3);

    return 0;
}
