#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define STACKMODE 0
#define QUEUEMODE 1

/**
 * struct stack_s - doubly linked list representation of a stack or queue
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
        void (*toponly)(stack_t **front);
        void (*pushmode)(stack_t **front, stack_t **rear, int element, int mode);
        void (*topbot)(stack_t **front, stack_t **rear);
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


void exit_true(int exitcode, char *existring, stack_t *front);
int is_num(char *s);

void add(stack_t **front);
void sub(stack_t **front);
void mul(stack_t **front);
void _div(stack_t **front);
void mod(stack_t **front);

void push(stack_t **front, stack_t **rear, int element, int mode);
void pop(stack_t **front);
void swap(stack_t **front, stack_t **rear);
void rotl(stack_t **front, stack_t **rear);
void rotr(stack_t **front, stack_t **rear);

void pall(stack_t **front);
void pint(stack_t **front);
void pchar(stack_t **front);
void pstr(stack_t **front);

#endif /* MONTY_H */
