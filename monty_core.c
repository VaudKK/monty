#include "monty.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	stack_t *mystack = NULL;
	int fd;
	int bytes;
	char c;

	top = mystack;

	if (argv[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		return (EXIT_FAILURE);
	}


	while ((bytes = read(fd, &c, sizeof(c))) > 0)
	{
		if (c != ' ' && c != '\n')
		{
		}
	}

	return (0);
}
