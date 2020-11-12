#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursive_bc(int n, int k)
{
    if( n == k || k == 0 ) return 1;
    return recursive_bc(n-1, k-1) + recursive_bc(n-1, k);
}

int dp_bc(int n, int k)
{
    int C[n+1][k+1]; // for saving precomputed value
    int i, j;
    for( i = 0; i <= n; i++ ) {
        for( j = 0; j <= k && j <= i; j++ ) {
            if( i == j || j == 0 ) C[i][j] = 1;
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
            fprintf(stdout, "C[%d][%d] = %d\n", i, j, C[i][j]);
        }
    }
    return C[n][k];
}

int main(int argc, int** argv)
{
    int n, k, ret;

    n = 5;
    k = 3;
    ret = recursive_bc(n, k);
    fprintf(stdout, "(%d, %d) -> %d\n", n, k, ret);
    ret = dp_bc(n, k);
    fprintf(stdout, "(%d, %d) -> %d\n", n, k, ret);

    return 0;
}
