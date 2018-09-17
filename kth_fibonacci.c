#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int recursive_fib(int n)
{
    if( n == 1 || n == 2 ) return 1;
    return n = recursive_fib(n-1) + recursive_fib(n-2);
}

int dp_fib(int n)
{
    int sub[n+1];
    int i;
    sub[0] = 0; // undefined
    sub[1] = sub[2] = 1;
    
    for( i = 2; i <= n; i++ ) {
        sub[i] = sub[i-2] + sub[i-1];
    }
    return sub[n];
}

int main(int argc, char** argv)
{
	int n = 10;

	fprintf(stdout, "%d-th fibonacci number is %d\n", n, recursive_fib(n));
	fprintf(stdout, "%d-th fibonacci number is %d\n", n, dp_fib(n));

	return 0;
}

