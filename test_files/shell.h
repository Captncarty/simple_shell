#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/*=====================*/
/*  Global variables   */
/*=====================*/
extern char **environ;
int hist;
char *name;

/*=====================*/
/*      Structures     */
/*=====================*/

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

alias_t *aliases;


/*====================*/
/*  Helper Functions  */
/*====================*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
int execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

/*===================*/
/*   Input Helpers   */
/*===================*/
void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);

/*===================*/
/*  String functions */
/*===================*/
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/*==================*/
/*     Builtins     */
/*==================*/
int (*get_builtin(char *command))(char **args, char **front);
int shell_exit(char **args, char **front);
int shell_env(char **args, char __attribute__((__unused__)) **front);
int shell_setenv(char **args, char __attribute__((__unused__)) **front);
int shell_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shell_cd(char **args, char __attribute__((__unused__)) **front);
int shell_alias(char **args, char __attribute__((__unused__)) **front);
int shell_help(char **args, char __attribute__((__unused__)) **front);

/*===================*/
/*  Builtin Helpers  */
/*===================*/
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/*===================*/
/*   Error Handling  */
/*===================*/
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/*====================*/
/* Linkedlist Helpers */
/*====================*/
void free_alias_list(alias_t *head);
void free_list(list_t *head);

/*====================*/
/*  Helper functions  */
/*====================*/
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

/*====================*/
/*        PROC        */
/*====================*/
int proc_fc(char *file_path, int *exe_ret);
int cant_open(char *file_path);

/*====================*/
/*       ALiases      */
/*====================*/
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
list_t *add_node_end(list_t **head, char *dir);


#endif /* _SHELL_H_ */