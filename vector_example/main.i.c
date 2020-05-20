#include "vector.int.h"
#include <stdio.h>

int main(void)
{
	Vector_int *myVec = vector_int_init_default();
	for(int i=0; i<10; ++i)
		vector_int_push_back(myVec,i);
	for(size_t i=0; i < vector_int_get_size(myVec); ++i)
		printf("%d\n",*vector_int_at(myVec,i));
	vector_int_destroy(&myVec);
	return 0;
}