#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int divisible(int n, int m)
{
    while( n % m == 0 ) {
        n = n / m;
    }
    return n;
}
int divisibles(int n)
{
    // check n is divisible by 2 or 3 or 5
    n = divisible(n, 2);
    n = divisible(n, 3);
    n = divisible(n, 5);
    if( n == 1 ) return 1; // divisible
    return 0; // indivisible
}

int main(int argc, int** argv)
{
    int  n = 1;
    int  k = 10;
    int  number_of_found= 0;

    while( 1 ) {
        if( n > INT_MAX ) break;
        if( divisibles(n) )  {
            number_of_found++;
            fprintf(stdout, "%d-th integer %d found\n", number_of_found, n);
            if( k == number_of_found ) {
                // found kth interger
                fprintf(stdout, "%d-th integer %d found\n", k, n);
                break;
            }
        }
        n += 1;
    }
    return 0;
}
