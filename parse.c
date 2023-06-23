#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <string.h>

#define MONTYOPCT 14

static montyglob mglob;

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

/**
 * parse_eff - parser for monty script files
 * @ops: array of opcodes and pointers to functions for them
 * Return: 0 if successful
 */
int parse_eff(optype *ops)
{
	size_t len = 0, element, mode = STACKMODE;
	stack_t *front = NULL, *rear = NULL;
	char *tok;

	while (getline(&mglob.buffer, &len, mglob.script) > 0)
	{
		if (mglob.buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit_true(EXIT_FAILURE, NULL, front);
		}
		tok = strtok(mglob.buffer, "\n ");
		if (tok != NULL)
		{
			element = 0;
			if (*tok == '#' || !strcmp(tok, "nop"))
				;
			else if (!strcmp(tok, "queue"))
				mode = QUEUEMODE;
			else if (!strcmp(tok, "stack"))
				mode = STACKMODE;
			else
			{
				while (element < MONTYOPCT && strcmp(tok, ops[element].opcode))
					element++;
				if (element == 0)
				{
					tok = strtok(NULL, "\n ");
					if (tok == NULL || !is_num(tok))
						exit_true(EXIT_FAILURE, "usage: push integer", front);
					ops[0].func.pushmode(&front, &rear, atoi(tok), mode);
				}
				else if (element < 4)
					ops[element].func.topbot(&front, &rear);
				else if (element < MONTYOPCT)
					ops[element].func.toponly(&front);
				else
				{
					fprintf(stderr, "L%ld: unknown instruction %s\n", mglob.linenum, tok);
					exit_true(EXIT_FAILURE, NULL, front);
				}
			}
		}
		free(mglob.buffer);
		mglob.buffer = NULL;
		len = 0;
		mglob.linenum++;
	}
	exit_true(EXIT_SUCCESS, NULL, front);
	return (0);
}

/**
 * initops - initialize array of opcodes and functions for them
 * Return: array of optypes
 */
optype *initops()
{
	static optype head[14];

	head[0].opcode = "push";
	head[0].func.pushmode = push;
	head[1].opcode = "rotl";
	head[1].func.topbot = rotl;
	head[2].opcode = "rotr";
	head[2].func.topbot = rotr;
	head[3].opcode = "swap";
	head[3].func.topbot = swap;
	head[4].opcode = "pop";
	head[4].func.toponly = pop;
	head[5].opcode = "pall";
	head[5].func.toponly = pall;
	head[6].opcode = "pint";
	head[6].func.toponly = pint;
	head[7].opcode = "pchar";
	head[7].func.toponly = pchar;
	head[8].opcode = "pstr";
	head[8].func.toponly = pstr;
	head[9].opcode = "add";
	head[9].func.toponly = add;
	head[10].opcode = "sub";
	head[10].func.toponly = sub;
	head[11].opcode = "mul";
	head[11].func.toponly = mul;
	head[12].opcode = "div";
	head[12].func.toponly = _div;
	head[13].opcode = "mod";
	head[13].func.toponly = mod;

	return (head);
}

/**
 * main - parse a monty script file
 * @ac: number of arguments
 * @av: argument array
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int main(int ac, char *av[])
{
	optype *ops;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	mglob.script = fopen(av[1], "r");
	if (mglob.script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	ops = initops();
	mglob.linenum = 1;
	parse_eff(ops);
	return (0);
}

#undef MONTYOPCT
