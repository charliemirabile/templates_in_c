#pragma once
#include <stdlib.h>

typedef struct Vector_p_TYPE Vector_p_TYPE;

Vector_p_TYPE *vector_p_TYPE_init_default(void (*destructor)(TYPE**));

Vector_p_TYPE *vector_p_TYPE_create_dummy(void);

void vector_p_TYPE_destroy(Vector_p_TYPE **ppVec);

size_t vector_p_TYPE_get_size(Vector_p_TYPE *pVec);

size_t vector_p_TYPE_get_capacity(Vector_p_TYPE *pVec);

_Bool vector_p_TYPE_push_back(Vector_p_TYPE *pVec, TYPE **item);

_Bool vector_p_TYPE_pop_back(Vector_p_TYPE *pVec, TYPE **pRemoved);

TYPE *vector_p_TYPE_at(Vector_p_TYPE *pVec, size_t index);

void vector_p_TYPE_swap_with(Vector_p_TYPE *pVec, size_t index, TYPE **pItem);
