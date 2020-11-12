#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compute_lcs(char* A, char* B)
{
    int n,m;
    int i,j,k;

    int count;
    int max;
    int max_i;
    char* lcs = NULL;

    n = strlen(A);
    m = strlen(B);

    max = 0;
    max_i = 0;
    // compute max, max_i
    for( i = 0; i < n; i++ ) {
        k = i;
        count = 0;
        for( j = 0; j < m; j++ ) {
            if( k < n && A[k] == B[j] ) {
                count += 1;
                if( max < count ) {
                    max = count;
                    max_i = k;
                    fprintf(stderr, "A[%d] = %c, B[%d] = %c\n", k, A[k], j, B[j]);
                }
                k += 1;
            } else {
                k = i;
                count = 0;
            }
        }
    }

    fprintf(stderr, "max, max_i = %d, %d\n", max, max_i);

    // get lcs
    if( max == 0 ) {
        lcs = NULL;
    } else {
        lcs = (char*)malloc(max + 1); // max + 1
        memcpy(lcs, &A[max_i - max + 1], max);
        lcs[max] = '\0';
    }

    return lcs;
}

int main(int argc, char** argv)
{
    char* A = "abcdefg";
    //char* A = "1234567";
    //char* A = "";
    char* B = "xzubcdkko";
    char* lcs;

    lcs = compute_lcs(A, B);

    fprintf(stdout, "lcs(%s, %s) = %s\n", A, B, lcs); 

    if( lcs ) free(lcs);

    return 0;
}
