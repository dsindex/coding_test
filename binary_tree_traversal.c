#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inorder(int* list, int parent, int size)
{
	int left, right;

	left = 2*parent + 1;
	right = 2*parent + 2;
	if( left < size ) {
		inorder(list, left, size);
	}
	fprintf(stdout, "%d ", list[parent]);
	if( right < size ) {
		inorder(list, right, size);
	}
}

void preorder(int* list, int parent, int size)
{
	int left, right;

	left = 2*parent + 1;
	right = 2*parent + 2;
	fprintf(stdout, "%d ", list[parent]);
	if( left < size ) {
		preorder(list, left, size);
	}
	if( right < size ) {
		preorder(list, right, size);
	}
}

void postorder(int* list, int parent, int size)
{
	int left, right;

	left = 2*parent + 1;
	right = 2*parent + 2;
	if( left < size ) {
		postorder(list, left, size);
	}
	if( right < size ) {
		postorder(list, right, size);
	}
	fprintf(stdout, "%d ", list[parent]);
}


typedef struct {
	int idx;
	int value;
} element_t;

int enqueue(element_t** queue, int qsize, int* rear, int* front, element_t* element)
{
	// push element to rear
	if( *rear >= qsize ) return 0;

	queue[*rear] = element;
	*rear += 1;
	if( *front == -1 ) *front = 0;
	return 1;
}

element_t* dequeue(element_t** queue, int qsize, int* rear, int* front)
{
	element_t* element;

	if( *front == -1 ) return NULL;
	
	// pop element from front
	element = queue[*front];
	*front += 1;
	if( *front > *rear ) {
		*front = -1;
		*rear = 0;
	}
	return element;
}

void levelorder(element_t* elements, int parent, int size)
{
	int qsize = size;
	int front = -1;
	int rear = 0;
	element_t** queue = (element_t**)malloc(qsize * sizeof(element_t*));
	element_t* element;
	int left;
	int right;

	// enqueue root
	enqueue(queue, qsize, &rear, &front, &elements[parent]);
	while( (element = dequeue(queue, qsize, &rear, &front)) != NULL ) {
		fprintf(stdout, "%d ", element->value);
		left = (element->idx)*2 + 1;
		right = (element->idx)*2 + 2;
		if( left < size ) {
			enqueue(queue, qsize, &rear, &front, &elements[left]);
		}
		if( right < size ) {
			enqueue(queue, qsize, &rear, &front, &elements[right]);
		}
	}
	if( queue ) free(queue);
}

int main(int argc, char** argv)
{
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// 8 4 9 2 10 5 1 6 3 7
	inorder(list, 0, 10);
	fprintf(stdout, "\n");

	// 1 2 4 8 9 5 10 3 6 7
	preorder(list, 0, 10);
	fprintf(stdout, "\n");

	// 8 9 4 10 5 2 6 7 3 1
	postorder(list, 0, 10);
	fprintf(stdout, "\n");

	// copy list -> elements
	element_t elements[10] = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10} };
	levelorder(elements, 0, 10);
	// 1 2 3 4 5 6 7 8 9 10
	fprintf(stdout, "\n");

	return 0;
}
