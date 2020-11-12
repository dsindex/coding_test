#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    int m;
    if( a < b ) m = a;
    else m = b;
    if( c < m ) m = c;
    return m;
}

int edit_distance(char* src, char* dst)
{
    int n,m,i,j;
    int distance;

    n = strlen(src) + 1; // with start symbol
    m = strlen(dst) + 1; // with start symbol

    int matrix[n][m];

    // initialize matrix
    for( i = 0; i < n; i++ ) {
        matrix[i][0] = i;
    }
    for( j = 0; j < m; j++ ) {
        matrix[0][j] = j;
    }

    // compute distance matrix
    for( i = 1; i < n; i++ ) {
        for( j = 1; j < m; j++ ) {
            if( src[i] == dst[j] ) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = min(matrix[i][j-1], matrix[i-1][j-1], matrix[i-1][j]) + 1;
            }
        }
    }

    distance = matrix[n-1][m-1];

    return distance;
}

int main(int argc, char** arg)
{
    char* src = "azced";
    //char* src = "";
    char* dst = "abcdef";
    int distance;

    distance = edit_distance(src, dst);

    fprintf(stdout, "distance(%s, %s) = %d\n", src, dst, distance); 

    return 0;
}
