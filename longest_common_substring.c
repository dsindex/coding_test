#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compute_lcs(char* A, char* B)
{
	int n,m,i,j;

	int max;
	int max_i;
	char* lcs = NULL;

	n = strlen(A) + 1; // with start symbol
	m = strlen(B) + 1; // with start symbol

	int matrix[n][m];

	// initialize matrix
	for( i = 0; i < n; i++ ) {
		matrix[i][0] = 0;
	}
	for( j = 0; j < m; j++ ) {
		matrix[0][j] = 0;
	}

	// compute lcs matrix
	max = 0;
	max_i = 0;
	for( i = 1; i < n; i++ ) {
		for( j = 1; j < m; j++ ) {
			if( A[i] == B[j] ) {
				matrix[i][j] = matrix[i-1][j-1] + 1;
				if( max < matrix[i][j] ) {
					max = matrix[i][j];
					max_i = i;
				}
			} else {
				matrix[i][j] = 0;
			}
		}
	}

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
