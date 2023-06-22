#include "monty.h"

/**
 * push - pushes a value onto the stack and updates pointers
 * @front: front of stack
 * @rear: rear of stack
 * @val: value to push
 * @mode: stack or queue mode (put on top or bottom)
 */
void push(stack_t **front, stack_t **rear, int val, int mode)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		printf("Error: malloc failed\n");
		exitwrap(EXIT_FAILURE, NULL, *front);
	}
	ptr->n = val;
	if (*front == NULL)
	{
		ptr->prev = NULL;
		ptr->next = NULL;
		*front = ptr;
		*rear = ptr;
	}
	else if (mode == STACKMODE)
	{
		ptr->next = NULL;
		ptr->prev = *front;
		(*front)->next = ptr;
		*front = ptr;
	}
	else if (mode == QUEUEMODE)
	{
		ptr->prev = NULL;
		ptr->next = *rear;
		(*rear)->prev = ptr;
		*rear = ptr;
	}
}

/**
 * pall - print all values in the stack as integers
 * @front: topmost of stack
 */
void pall(stack_t **front)
{
	stack_t *ptr = *front;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}
