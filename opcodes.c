#include "monty.h"

/**
 * swap - swap top two values on stack and update top/bottom
 * @front: topmost of stack
 * @rear: rear of stack
 */
void swap(stack_t **front, stack_t **rear)
{
	stack_t *ptr = *front;

	if (ptr == NULL || ptr->prev == NULL)
		exit_true(EXIT_FAILURE, "can't swap, stack too short", *front);
	ptr = ptr->prev;
	(*front)->prev = ptr->prev;
	ptr->next = (*front)->next;
	ptr->prev = *front;
	(*front)->next = ptr;
	*front = ptr;
	if ((*rear)->prev != NULL)
		*rear = (*rear)->prev;
}


/**
 * pop - pop top element of stack
 * @front: topmost of stack
 */
void pop(stack_t **front)
{
	stack_t *ptr = *front;

	if (ptr == NULL)
		exit_true(EXIT_FAILURE, "can't pop an empty stack", *front);
	if (ptr->prev == NULL)
	{
		free(*front);
		*front = NULL;
	}
	else
	{
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*front);
		*front = ptr;
	}
}


/**
 * pint - print top of stack as an integer
 * @front: topmost of stack
 */
void pint(stack_t **front)
{
	if (*front == NULL)
		exit_true(EXIT_FAILURE, "can't pint, stack empty", *front);
	printf("%d\n", (*front)->n);
}
