#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* list, int aidx, int bidx)
{
    int tmp;
    tmp = list[aidx];
    list[aidx] = list[bidx];
    list[bidx] = tmp;
}

int partition(int* list, int begin, int end, int pivot_index)
{
	int store_index;
	int pivot_value;
	int i;

	pivot_value = list[pivot_index];

	// move pivot value to the end
	swap(list, pivot_index, end);
	store_index = 0;
	for( i = begin; i < end; i++ ) {
		if( list[i] > pivot_value ) { // descending order
			swap(list, i, store_index);
			store_index += 1;
		}
	}
	// swap store_index and end(hold pivot)
	swap(list, store_index, end);
	// all value in list[0:store_index-1] are smaller than list[store_index]
	// that is, list[store_index] is 'store_index'-th largest value
	return store_index;
}

int main(int argc, char** argv)
{
    int list[11] = {8, 9, 1, 7, 5, 6, 2, 10, 3, 5, 8}; // -> store_index = 5, 8 9 7 8 10
    int topk = 5;
	int pivot_index;
	int store_index;
	int left, right;
	int i;

	left = 0;
	right = 10;
	pivot_index = (left + right)/2; // initial pivot

	store_index = partition(list, left, right, pivot_index);
	while( store_index != topk ) {
		if( store_index < topk ) {  // find right
			left = store_index+1;
			pivot_index = (left + right)/2;
		} else {                    // find left
			right = store_index-1;
			pivot_index = (left + right)/2;
		}
		store_index = partition(list, left, right, pivot_index);
	}

	fprintf(stdout, "store_index = %d\n", store_index);
	for( i = 0; i < store_index; i++ ) {
		fprintf(stdout, "%d ", list[i]);
	}
	fprintf(stdout, "\n");
	
	return 0;
}
