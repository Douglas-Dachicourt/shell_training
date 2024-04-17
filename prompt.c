#include "s_shell.h"
/**
 * shell - fct that launch the prompt for our custom shell
 * Return: nothing
 */
void shell(void)
{
	char *command = NULL;
	size_t bufsize = 1024;
	ssize_t bytes_read;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&command, &bufsize, stdin);

		if (bytes_read == -1)
			break;

		if (command[bytes_read - 1] == '\n')
			command[bytes_read - 1] = '\0';

		char *token = strtok(command, " ");
		char *args[32];
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		execute_command(args);
	}
	printf("\n");
	free(command);
}
