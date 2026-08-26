#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_INPUT 1024

// Function declarations - Parser
char** parse_input(char* input);
void free_tokens(char** tokens);

// Function declarations - Built-ins
int command_cd(char** args, char* initial_directory);
int command_pwd(void);
int command_echo(char** args, char** env);
int command_env(char** env);
int command_which(char** args, char** env);
int shell_builts(char** args, char** env, char* initial_directory);

// Function declarations - Helpers
int my_strcmp(const char* str1, const char* str2);
int my_strncmp(const char * str1, const char* str2 , size_t n);
char* my_getenv(const char* name, char** env);
int my_strlen(const char* str);

// Main shell loop
void shell_loop(char** env);

#endif // MY_SHELL_H