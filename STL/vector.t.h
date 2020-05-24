#pragma once
#include <stdlib.h>

typedef struct Vector_TYPE Vector_TYPE;

Vector_TYPE *vector_TYPE_init_default(void);

Vector_TYPE *vector_TYPE_create_dummy(void);

void vector_TYPE_destroy(Vector_TYPE **ppVec);

size_t vector_TYPE_get_size(Vector_TYPE *pVec);

size_t vector_TYPE_get_capacity(Vector_TYPE *pVec);

_Bool vector_TYPE_push_back(Vector_TYPE *pVec, TYPE item);

_Bool vector_TYPE_pop_back(Vector_TYPE *pVec, TYPE *pRemoved);

TYPE *vector_TYPE_at(Vector_TYPE *pVec, size_t index);
