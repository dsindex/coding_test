#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_number(int begin, int end)
{
    int i;
    for( i = begin; i <= end; i++ ) {
        // check odd number
        if( i % 2 == 1 ) fprintf(stdout, "%d\n", i);
    }
}

int main(int argc, char** argv)
{
    print_number(1, 99);
    return 0;
}
