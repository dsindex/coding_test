#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// recursively
int recursive_catalan(int n)
{
    int i;
    int sum = 0;
    if( n == 0 || n == 1 ) return 1;
    for( i = 0; i < n; i++ ) {
        sum += recursive_catalan(i) * recursive_catalan(n-i-1);
    }
    return sum;
}

// dynamic programming
int dynamic_catalan(int n)
{
   int i, j;
   int C[n+1];

   C[0] = C[1] = 1;
   for( i = 2; i <= n; i++ ) {
       C[i] = 0;
       for( j = 0; j < i; j++ ) {
           C[i] += C[j]*C[i-j-1];
       }
   }
   return C[n];
}



int main(int argc, char** argv)
{
    int n = 4;
    int catalan;
    
    catalan = recursive_catalan(n);
    fprintf(stdout, "catalan(%d) = %d\n", n, catalan);
    catalan = dynamic_catalan(n);
    fprintf(stdout, "catalan(%d) = %d\n", n, catalan);

    return 0;
}
