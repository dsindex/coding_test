#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char* string)
{
    int length = strlen(string);
    int i;
	int mid = length / 2; // 5 -> 2, 4 -> 2
    for( i = 0; i < mid; i++ ) {
        // swap
        swap(&string[i], &string[length - 1 - i]);
    }
}

int main(int argc, char** argv)
{
	char string[] = "hello world";

	reverse(string);

	// dlrow olleh
	fprintf(stdout, "reverse = %s\n", string);

	return 0;
}
