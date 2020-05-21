#include "templates/vector.float.t.h"
#include <stdio.h>

int main(void)
{
	Vector_float *myVec = vector_float_init_default();
	for(int i=0; i<10; ++i)
		vector_float_push_back(myVec,i);
	for(size_t i=0; i < vector_float_get_size(myVec); ++i)
		printf("%g\n",*vector_float_at(myVec,i));
	vector_float_destroy(&myVec);
	return 0;
}
