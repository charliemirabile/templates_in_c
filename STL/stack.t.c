#include <stdlib.h>
struct node_TYPE
{
	struct node_TYPE *next;
	TYPE value;
};

typedef struct
{
	struct node_TYPE *head;
}
Stack_TYPE;

Stack_TYPE *stack_TYPE_init_default(void)
{
	return calloc(sizeof(Stack_TYPE),1);
}

void stack_TYPE_destroy(Stack_TYPE **ppStk)
{
	struct node_TYPE *ptr = (*ppStk)->head;
	while(ptr)
	{
		struct node_TYPE *temp=ptr->next;
		free(ptr);
		ptr=temp;
	}
	free(*ppStk);
	*ppStk=NULL;
}

_Bool stack_TYPE_empty(Stack_TYPE *pStk)
{
	return !pStk->head;
}

_Bool stack_TYPE_push(Stack_TYPE *pStk, TYPE item)
{
	struct node_TYPE *temp;
	if(!(temp=malloc(sizeof(struct node_TYPE))))
		return 0;
	temp->value=item;
	temp->next=pStk->head;
	pStk->head=temp;
	return 1;
}

_Bool stack_TYPE_pop(Stack_TYPE *pStk, TYPE *pRemoved)
{
	if(!pStk->head)
		return 0;
	struct node_TYPE *temp=pStk->head;
	pStk->head=temp->next;
	if(pRemoved)
		*pRemoved=temp->value;
	free(temp);
	return 1;
}

TYPE *stack_TYPE_top(Stack_TYPE *pStk)
{
	return pStk->head ? &(pStk->head->value) : NULL;
}
