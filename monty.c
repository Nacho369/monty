#include "monty.h"

/**
 * main - Entry function to the monty program
 *
 * @argv: Argument Count
 * @argc: List of arguments
 *
 * Return: EXIT_SUCCESS on succeess and
 * EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_file(file);

	return (EXIT_SUCCESS);
}
