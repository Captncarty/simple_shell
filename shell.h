#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int hist;
char *name;
extern char **environ;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;


/*======================*/
/*		shell_init		*/
/*======================*/

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);

/*======================*/
/*		  child		    */
/*======================*/
void create_child(char **command, char *name, char **env, int cicles);
int change_dir(const char *path);

/*======================*/
/*		 execve		    */
/*======================*/

void execute(char **command, char *name, char **env, int cicles);
char **_getPATH(char **env);
void msgerror(char *name, int cicles, char **command);

/*======================*/
/*		  token		    */
/*======================*/

char **tokening(char *buffer, const char *s);

/*======================*/
/*		   free		    */
/*======================*/

void free_dp(char **command);
void free_exit(char **command);

/*======================*/
/*	  Aux functions		*/
/*======================*/

int _strcmp(char *s1, char *s2);
unsigned int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);


/*=====================*/
/*   Ascii functions   */
/*=====================*/

int _atoi(char *s);
char *_itoa(int num);
int num_len(int num);

/*=====================*/
/*    Errors check     */
/*=====================*/

char *error_syntax(char **args);
char *error_cd(char **args);
char *error_exit(char **args);
char *error_1(char **args);
char *error_env(char **args);
int create_error(char **args, int err);
char *error_denied(char **args);
char *error_not(char **args);

/*=====================*/
/*    Env functions    */
/*=====================*/

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);
void print_env(char **env);

#endif  /* SHELL_H */
