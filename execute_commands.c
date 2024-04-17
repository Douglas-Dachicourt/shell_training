#include "s_shell.h"
/**
 * execute_command - fct that search commands in PATH
 * @args: command to find
 * Return: nothing
 */
void execute_command(char *args[])
{
	int j;
	char executable_path[256];

	sprintf(executable_path, "/usr/bin/%s", args[0]);

	pid_t child = fork();

	if (child == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	} else if (child == 0)
	{
		if (execve(executable_path, args, environ) == -1)
		{
			perror("Error");

			char *path = getenv("PATH"); /* remplacer par la fonction de MAX */
			char **tokens = tokenize_path(path);

			for (j = 0; tokens[j] != NULL; j++)
			{
				sprintf(executable_path, "%s%s", tokens[j], args[0]);

				if (execve(executable_path, args, environ) != -1)
					break;
			}
		free(tokens);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
}
