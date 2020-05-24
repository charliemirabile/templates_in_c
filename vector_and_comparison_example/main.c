#include "templates/vector.int@TYPE.t.h"
#include "templates/less.int@T.float@S.t.h"
#include "templates/vector%.int@TYPE.t.h"
#include <stdio.h>

int main(void)
{
	Vector_int *myVec = vector_int_init_default();
	for(int i=0; i<10; ++i)
		vector_int_push_back(myVec,i);
	for(size_t i=0; i < vector_int_get_size(myVec); ++i)
		printf("%d\n",*vector_int_at(myVec,i));
	vector_int_destroy(&myVec);

	Vector_p_int *myPVec = vector_p_int_init_default(NULL);
	int *pInt = NULL;
	for(int i=0; i<10; ++i)
	{
		pInt = malloc(sizeof(int));
		*pInt = i;
		vector_p_int_push_back(myPVec,&pInt);
	}
	for(size_t i=0; i < vector_p_int_get_size(myPVec); ++i)
		printf("%d\n",*vector_p_int_at(myPVec,i));
	vector_p_int_destroy(&myPVec);

	puts(less_int_float(1,0.5f)?"less":"not less");
	puts(less_int_float(0,0.5f)?"less":"not less");
	return 0;
}
