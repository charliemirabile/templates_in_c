#include "vector.TYPE.h"

typedef struct Vector_TYPE
{
	size_t size,capacity;
	TYPE *data;
}
Vector_TYPE;

Vector_TYPE *vector_TYPE_init_default(void)
{
	Vector_TYPE *pVec;
	if((pVec = malloc(sizeof(Vector_TYPE))))
	{
		pVec->size = 0;
		pVec->capacity = 1;
		if(!(pVec->data = malloc(sizeof(TYPE) * pVec->capacity)))
		{
			free(pVec);
			pVec =  NULL;
		}
	}
	return pVec;
}

size_t vector_TYPE_get_size(Vector_TYPE *pVec)
{
	return pVec->size;
}

size_t vector_TYPE_get_capacity(Vector_TYPE *pVec)
{
	return pVec->capacity;
}

void vector_TYPE_destroy(Vector_TYPE **ppVec)
{
	free((*ppVec)->data);
	free(*ppVec);
	*ppVec=NULL;
}

_Bool vector_TYPE_push_back(Vector_TYPE *pVec, TYPE item)
{
	TYPE *temp;
	if(pVec->size >= pVec->capacity)
	{
		if(!(temp = realloc(pVec->data,sizeof(TYPE)*2*pVec->capacity)))
		{
			return 0;
		}
		else
		{
			pVec->data = temp;
			pVec->capacity *= 2;
		}
	}
	pVec->data[pVec->size++]=item;
	return 1;
}

_Bool vector_TYPE_pop_back(Vector_TYPE *pVec, TYPE *removed_item)
{
	if(pVec->size==0)
		return 0;
	if(removed_item)*removed_item=pVec->data[pVec->size];
	--pVec->size;
	return 1;
}

TYPE *vector_TYPE_at(Vector_TYPE *pVec, size_t index)
{
	return pVec->size > index ? &(pVec->data[index]) : NULL;
}
