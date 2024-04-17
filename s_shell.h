#ifndef S_SIMPLE_H
#define S_SIMPLE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void *tokenize_path(char *path);
void shell(void);
void execute_command(char *args[]);

#endif
