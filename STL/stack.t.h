#pragma once
typedef struct stack_TYPE Stack_TYPE;

Stack_TYPE *stack_TYPE_init_default(void);

void stack_TYPE_destroy(Stack_TYPE **ppStk);

_Bool stack_TYPE_empty(Stack_TYPE *pStk);

_Bool stack_TYPE_push(Stack_TYPE *pStk, TYPE item);

_Bool stack_TYPE_pop(Stack_TYPE *pStk, TYPE *pRemoved);

TYPE *stack_TYPE_top(Stack_TYPE *pStk);
