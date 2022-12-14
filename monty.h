#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


#define BUFF_SIZE 65


/**
 * Indicates that the stack is empty
 */
/* extern int top_stck = -1; */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Functions Prototypes */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void get_file_line(FILE *file_d);

/* Errors Prototype */
int usage_error(void);

int malloc_error(void);

int f_open_error(char *filename);

int unknown_op_error(char *opcode, unsigned int line_number);

int no_int_error(unsigned int line_number);

#endif
