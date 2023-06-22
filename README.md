# MONTY - PROJECT

*Monty* is a language that aims to close the gap between scripting and programming languages.

## Learning Objectives
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## Usage / Installation
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
### Command Required
* ```push``` Pushes an integer onto the stack.
* ```pall``` Prints all integers on the stack, starting at the top..
* ```pint``` Prints the integer at the top of the stack.
* ```pop``` Removes top element of stack.
* ```swap``` Swaps top two elements of the stack.
* ```add``` Add top two elements of the stack, remove them, and push result onto stack.
* ```sub``` Subtract top two elements of the stack, remove them, and push result onto stack.
* ```div``` Integer divide top two elements of the stack, remove them, and push result onto stack.
* ```mul``` Multiply top two elements of the stack, remove them, and push result onto stack.
* ```mod``` Integer division remainder top two elements, remove them, push result onto stack.
* ```pchar``` Print the ascii character based on top integer in stack.
* ```pstr``` Print the ascii characters related to integers in stack until 0 or >255.
* ```rotl``` Rotate stack. Top element becomes last. Second from top becomes top.
* ```rotr``` Rotate stack. Last element becomes top, Top element becomes second from top.
* ```stack``` Changes mode to first in first out (the default behavior). Front of queue becomes top of stack.
* ```queue``` Changes mode to last in first out. Top of stack becomes front of queue.
## Terminal
```
vagrant@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
push 3$
pall$
push 4$
push 5$
push 6$
pall$
vagrant@ubuntu:~/monty$
```

