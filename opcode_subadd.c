#include "monty.h"


/**
 * sub - subtract top two stack elements. error if < 2 elements
 * @front: topmost of stack
 */
void sub(stack_t **front)
{
	stack_t *ptr = *front;
	long number;

	if (ptr == NULL || ptr->prev == NULL)
		exit_true(EXIT_FAILURE, "can't sub, stack too short", *front);
	else
	{
		number = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*front);
		*front = ptr;
		ptr->n -= number;
	}
}


/**
 * add - add top two stack elements. error if < 2 elements
 * @front: topmost of stack
 */
void add(stack_t **front)
{
	stack_t *ptr = *front;
	long number;

	if (ptr == NULL || ptr->prev == NULL)
		exit_true(EXIT_FAILURE, "can't add, stack too short", *front);
	else
	{
		number = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*front);
		*front = ptr;
		ptr->n += number;
	}
}
