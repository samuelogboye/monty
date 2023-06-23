#include "monty.h"

/**
 * rotr - "rotate right" put bottom of stack on top
 * @front: topmost of stack
 * @rear: rear of stack
 */
void rotr(stack_t **front, stack_t **rear)
{
	stack_t *ptrf = *front, *ptrr = *rear;

	if (ptrf == NULL || ptrf->prev == NULL)
		return;
	ptrf->next = ptrr;
	ptrr->prev = ptrf;
	*rear = ptrr->next;
	(*rear)->prev = NULL;
	*front = ptrr;
	ptrr->next = NULL;
}

/**
 * rotl - "rotate left" put top of stack on bottom
 * @front: topmost of stack
 * @rear: rear of stack
 */
void rotl(stack_t **front, stack_t **rear)
{
	stack_t *ptrf = *front, *ptrr = *rear;

	if (ptrf == NULL || ptrf->prev == NULL)
		return;
	ptrf->next = ptrr;
	ptrr->prev = ptrf;
	*front = ptrf->prev;
	(*front)->next = NULL;
	*rear = ptrf;
	ptrf->prev = NULL;
}
