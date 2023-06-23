#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <string.h>

montyglob mglob;

/**
 * exit_true - free things and exit the program. Print error message as needed
 * @exitcode: exit code
 * @exitstring: error string to print, if any
 * @front: topmost of stack (for freeing)
 */
void exit_true(int exitcode, char *exitstring, stack_t *front)
{
	stack_t *ptr = front;

	if (exitstring != NULL)
		fprintf(stderr, "L%lu: %s\n", mglob.linenum, exitstring);
	while (front != NULL)
	{
		ptr = front->prev;
		free(front);
		front = ptr;
	}
	free(mglob.buffer);
	fclose(mglob.script);
	exit(exitcode);
}

/**
 * is_num - checks if a string is a number
 * @s: string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_num(char *s)
{
	if (*s == '-')
	{
		s++;
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	while (*s != 0)
		if (*s < '0' || *s++ > '9')
			return (0);
	return (1);
}
