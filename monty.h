#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define STACKMODE 0
#define QUEUEMODE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

union montyfunctype
{
        void (*toponly)(stack_t **top);
        void (*pushmode)(stack_t **top, stack_t **bot, int val, int mode);
        void (*topbot)(stack_t **top, stack_t **bot);
};

typedef struct optype
{
        char *opcode;
        union montyfunctype func;
} optype;

typedef struct montyglob
{
        char *buffer;
        unsigned long linenum;
        FILE* script;
} montyglob;

/* from montyparse.c */
void exitwrap(int exitcode, char *existring, stack_t *top);

/* opmath.c */
void add(stack_t **top);
void sub(stack_t **top);
void mul(stack_t **top);
void _div(stack_t **top);
void mod(stack_t **top);

/* opstack.c */
void push(stack_t **top, stack_t **bot, int val, int mode);
void pop(stack_t **top);
void swap(stack_t **top, stack_t **bot);
void rotl(stack_t **top, stack_t **bot);
void rotr(stack_t **top, stack_t **bot);

/* opprint.c */
void pall(stack_t **top);
void pint(stack_t **top);
void pchar(stack_t **top);
void pstr(stack_t **top);

#endif /* MONTY_H */
