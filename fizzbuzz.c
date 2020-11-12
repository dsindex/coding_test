#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fizzbuzz(int begin, int end) 
{
    int i;
    for( i = begin; i <= end; i++ ) {
        if( i % 3 == 0 && i % 5 == 0 ) fprintf(stdout, "fizzbuzz ");
        else if( i % 3 == 0 ) fprintf(stdout, "fizz ");
        else if( i % 5 == 0 ) fprintf(stdout, "buzz ");
        else fprintf(stdout, "%d ", i);
    }
    fprintf(stdout, "\n");
}

int main(int argc, char** argv)
{
    fizzbuzz(1, 100);
    return 0;
}
