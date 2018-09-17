#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int x1;  // (x1, y1)
	int y1;
	int x2;  // (x2, y2)
	int y2;
} rect_t;

int is_overlap(rect_t* A, rect_t*B)
{
	int x_overlap;
	int y_overlap;
	
	x_overlap = 1;
	y_overlap = 1;
	if( A->x1 > B->x2 || A->x2 < B->x1 ) {
		x_overlap = 0;
	}
	if( A->y1 > B->y2 || A->y2 < B->y1 ) {
		y_overlap = 0;
	}
	// x축 혹은 y축으로 둘중 하나라도 overlap이 아니면
	// 전체는 overlap이 아니게 됨
	if( !x_overlap || !y_overlap ) return 0;
	return 1;
}

int main(int argc, char** argv)
{
	int ret;

	rect_t A = {0, 0, 2, 2};
	rect_t B1 = {3, 3, 4, 4};
	rect_t B2 = {3, 0, 4, 2};
	rect_t B3 = {3, -2, 4, -1};
	rect_t B4 = {0, -2, 1, -1};
	rect_t B5 = {-4, -2, -3, -1};
	rect_t B6 = {-4, -0, -3, 2};
	rect_t B7 = {-4, -3, -3, 4};
	rect_t B8 = {0, 3, 1, 4};

	rect_t C1 = {1, 0, 3, 1};

	ret = is_overlap(&A, &B1);
	fprintf(stdout, "B1 = %d\n", ret);

	ret = is_overlap(&A, &B1);
	fprintf(stdout, "B1 = %d\n", ret);

	ret = is_overlap(&A, &B2);
	fprintf(stdout, "B2 = %d\n", ret);

	ret = is_overlap(&A, &B3);
	fprintf(stdout, "B3 = %d\n", ret);

	ret = is_overlap(&A, &B4);
	fprintf(stdout, "B4 = %d\n", ret);

	ret = is_overlap(&A, &B5);
	fprintf(stdout, "B5 = %d\n", ret);

	ret = is_overlap(&A, &B6);
	fprintf(stdout, "B6 = %d\n", ret);

	ret = is_overlap(&A, &B7);
	fprintf(stdout, "B7 = %d\n", ret);

	ret = is_overlap(&A, &B8);
	fprintf(stdout, "B8 = %d\n", ret);

	ret = is_overlap(&A, &C1);
	fprintf(stdout, "C1 = %d\n", ret);

	return 0;
}
