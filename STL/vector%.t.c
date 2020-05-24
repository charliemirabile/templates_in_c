#include <stdlib.h>
typedef struct Vector_p_TYPE
{
	size_t size,capacity;
	void (*destructor)(TYPE**);
	TYPE **data;
}
Vector_p_TYPE;

void double_ptr_free(TYPE** ppItem)
{
	free(*ppItem);
	*ppItem=NULL;
}

Vector_p_TYPE *vector_p_TYPE_init_default(void (*destructor)(TYPE**))
{
	Vector_p_TYPE *pVec;
	if((pVec = malloc(sizeof(Vector_p_TYPE))))
	{
		pVec->size = 0;
		pVec->capacity = 1;
		//if they pass in a NULL ptr for the destructor
		if(!(pVec->destructor=destructor))
			//we just use the default action of freeing the pointer and NULLing it.
			pVec->destructor=&double_ptr_free;
		if(!(pVec->data = malloc(sizeof(TYPE*) * pVec->capacity)))
		{
			free(pVec);
			pVec =  NULL;
		}
	}
	return pVec;
}

Vector_p_TYPE *vector_p_TYPE_create_dummy(void)
{
	return calloc(sizeof(Vector_p_TYPE),1);
}

void vector_p_TYPE_destroy(Vector_p_TYPE **ppVec)
{
	for(size_t i = 0; i < (*ppVec)->size; ++i)
		(*(*ppVec)->destructor)((*ppVec)->data+i);
	free((*ppVec)->data);
	free(*ppVec);
	*ppVec=NULL;
}

size_t vector_p_TYPE_get_size(Vector_p_TYPE *pVec)
{
	return pVec->size;
}

size_t vector_p_TYPE_get_capacity(Vector_p_TYPE *pVec)
{
	return pVec->capacity;
}


_Bool vector_p_TYPE_push_back(Vector_p_TYPE *pVec, TYPE **item)
{
	if(*item==NULL||pVec->data==NULL)
		return 0;
	TYPE **temp;
	if(pVec->size >= pVec->capacity)
	{
		if(!(temp = realloc(pVec->data,sizeof(TYPE*)*2*pVec->capacity)))
		{
			return 0;
		}
		else
		{
			pVec->data = temp;
			pVec->capacity *= 2;
		}
	}
	pVec->data[pVec->size++]=*item;
	*item=NULL;
	return 1;
}

_Bool vector_p_TYPE_pop_back(Vector_p_TYPE *pVec, TYPE **removed_item)
{
	if(pVec->size==0)
		return 0;
	if(removed_item)*removed_item=pVec->data[pVec->size];
	--pVec->size;
	return 1;
}

TYPE *vector_p_TYPE_at(Vector_p_TYPE *pVec, size_t index)
{
	return pVec->size > index ? pVec->data[index] : NULL;
}

_Bool vector_p_TYPE_swap_with(Vector_p_TYPE *pVec, size_t index, TYPE **pItem)
{
	if(*pItem==NULL || index >= pVec->size)
		return 0;
	TYPE* temp = pVec->data[index];
	pVec->data[index]=*pItem;
	*pItem = temp;
	return 1;
}
