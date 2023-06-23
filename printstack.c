#include "monty.h"

/**
 * pstr - print stack as string starting from the top
 * @front: topmost of stack
 */
void pstr(stack_t **front)
{
	stack_t *ptr = *front;

	while (ptr != NULL && ptr->n <= 127 && ptr->n > 0)
	{
		printf("%c", ptr->n);
		ptr = ptr->prev;
	}
	printf("\n");
}

/**
 * pchar - print top of stack as a char
 * @front: topmost of stack
 */
void pchar(stack_t **front)
{
	stack_t *ptr = *front;

	if (ptr == NULL)
		exit_true(EXIT_FAILURE, "can't pchar, stack empty", *front);
	if (ptr->n > 127 || ptr->n < 0)
		exit_true(EXIT_FAILURE, "can't pchar, value out of range", *front);
	printf("%c\n", ptr->n);
}
