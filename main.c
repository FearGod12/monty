#include "monty.h"

/**
 * main - monty scripting language interpreter
 *
 * @argc: arguements count
 * @argv: arguements list
 *
 * Return: EXIT_SUCCESS on success
 * or EXIT_FAILURE if otherwise
 */
int main(int argc, char **argv)
{
	FILE *fd;
	ssize_t bytes_read;
	size_t len = 0;
	char *token = NULL;
	char *line = NULL;
	stack_t *head = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((bytes_read = getline(&line, &len, fd)) != -1)
	{
		line_number++;
		token = get_strtok(line, line_number);
		if (token != NULL)
			get_command(token, &head, line_number);
	}
	free(line);
	free_stack(head);
	fclose(fd);
	return (0);
}
