#include "monty.h"

/**
 * mul - multiply top two stack elements. error if < 2 elements
 * @front: topmost of stack
 */
void mul(stack_t **front)
{
	stack_t *ptr = *front;
	long number;

	if (ptr == NULL || ptr->prev == NULL)
		exit_true(EXIT_FAILURE, "can't mul, stack too short", *front);
	else
	{
		number = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*front);
		*front = ptr;
		ptr->n *= number;
	}
}

/**
 * mod - get remainder top two stack elements. error if < 2 elements or divby0
 * @front: topmost of stack
 */
void mod(stack_t **front)
{
	stack_t *ptr = *front;
	long number;

	if (ptr == NULL || ptr->prev == NULL)
		exit_true(EXIT_FAILURE, "can't mod, stack too short", *front);
	else
	{
		number = ptr->n;
		if (number == 0)
			exit_true(EXIT_FAILURE, "division by zero", *front);
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*front);
		*front = ptr;
		ptr->n %= number;
	}
}

/**
 * _div - divide top two stack elements. error if < 2 elements or divby0
 * @front: topmost of stack
 */
void _div(stack_t **front)
{
	stack_t *ptr = *front;
	long number;

	if (ptr == NULL || ptr->prev == NULL)
		exit_true(EXIT_FAILURE, "can't div, stack too short", *front);
	else
	{
		number = ptr->n;
		if (number == 0)
			exit_true(EXIT_FAILURE, "division by zero", *front);
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*front);
		*front = ptr;
		ptr->n /= number;
	}
}
