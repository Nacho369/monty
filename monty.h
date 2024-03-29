#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


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


/**
 * struct arg_s - argument representation.
 * @arg: integer.
 * @flag: option that corresponds to a specific command.
 *
 * Description: structure fr argument parameters
 * passed to monty.
 */
typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

/**
 * struct file_content - contents of file and buffer data.
 *
 * @buff: pointer to array of data read from buffer.
 * @stack: pointer to top of stack.
 * @file: pointer to file.
 */
typedef struct file_content
{
	char *buff;
	stack_t *stack;
	FILE *file;
} file_c;

/**
 * struct file_line - contents of a line and number.
 *
 * @content: array of tokens read from line.
 * @number: line number.
 *
 * Description: structure for data in a line.
 */
typedef struct file_line
{
	char **content;
	unsigned int number;
} file_l;

/* PROTOTYPES */      
/* PARSER FUNCS */
void parse_file(FILE *file);
void parse_line(file_l *line, char *buffer);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* UTILS FUNCS */
void free_stack(stack_t **stack);
void (*get_opcode_func(file_l line, file_c *buffer))(stack_t **, unsigned int);
void push_check(file_l line, file_c *buffer, char *opcode);
bool argument_check(char *token);
bool comment_check(file_l line);

/* OPCODES FUNCS */
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);


#endif /* MONTY_H */
