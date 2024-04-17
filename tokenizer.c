#include "s_shell.h"
/**
 * tokenize_path - fct that extract specific paths to work with
 * @path: path to analyze
 * Return: nothing
 */
void *tokenize_path(char *path)
{
	char **tokens = 0;
	char *tok = 0;
	int i = 0;
	char *path1 = 0;
	char *path2 = 0;
	char *path3 = 0;

	tokens = malloc(1024);

	if (tokens == NULL)
		exit(0);

	tok = strtok(path, ":");

	while (tok != NULL)
	{
		tokens[i++] = tok;
		tok = strtok(NULL, ":");
	}

	tokens[i] = NULL;

	path1 = tokens[2];
	path2 = tokens[4];
	path3 = tokens[6];

	free(tokens);
}
