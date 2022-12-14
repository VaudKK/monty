#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


/**
 * main - the main function
 * @argc: argument count
 * @argv: argument variables
 *
 * Return: integer
 */
int main(int argc, char **argv)
{
	stack_t *mystack = NULL;
	FILE *f;
	char *token, *line = malloc(sizeof(char) * 1024);
	int operand, line_number = 1;
	(void)argc;

	if (argv[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, 1024, f) != NULL)
	{
		token = strtok(line, " ");
		if (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				operand = atoi(strtok(NULL, " "));
				if (operand == 0)
				{
					fprintf(stderr, "L%d: usage: push integer", line_number);
					return (EXIT_FAILURE);
				}
				push(operand, &mystack);
			}
			else if (strcmp(token, "pall"))
			{
				pall(mystack);
			}
		}
		line_number += 1;
	}
	return (0);
}
