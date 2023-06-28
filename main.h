#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <fcntl.h>

#define SIZE 1024
#define BUFFER 128
#define DELIM " \t\r\n\a"

extern char **environ;

/*environment.c - environment variables*/
char *_getenv(const char *name, char **_environ);
int _env(my_shell *data);
int compare_env(const char *envn, const char *name);

/* env1.c - environment variable manipulation*/
char *copy_info(char *name, char *val);
void set_env(char *name, char *val, my_shell *data);
int _setenv(my_shell *data);
int _unsetenv(my_shell *data);

/* replace_var.c - check and replace environment variables*/
void checkenv(_var **i, char **in, my_shell data);
int checkvar(_var **i, char *in, char *s, my_shell *data);
char *reinput(_var **head, char *in, char *new, int len);
char *replaced_var(char *in, my_shell *data);

/* strfunc.c - string functions*/
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *i, char j);
int _strcmp(char *s1, char *s2);
int _strlen(char s);

/* strfunc2.c - more string functions*/
char *_strdup(const char *s);
char *_strtok(char str[], const char *delim);
int str_chars(char str[], const char *delim);
int _isdigit(int *c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept)

/*str2.c - string function for reverse*/
void _rev(char *s);

/*lists.c - list functions*/
sep_list *add_sep_node_end(sep_list **head, char sep);
line_list *add_line_node_end(line_list **head, char *line);
void free_sep_list(sep_list **head);
void free_line_list(line_list **head);
_var *add_rv_node(_var **head, int lvar, char *var, int val);
void free_var_list(_var **head);

/**
* struct sep_lists - singly linked list to store seperators
* @sep: ; | &
* @next: next node
*/
typedef struct sep_lists
{
    char sep;
    struct sep_lists *next;
}  sep_list;

/*
* struct line_lists - list to store command lines
* @cmdl: command line
* @next: next node
*
*/
typedef struct line_lists
{
    char *cmdline;
    struct line_lists *next;
} line_list;

/**
*struct store_var_list - sll to store variables (r_var_list)
*@len: length of variable
*@value: value of variable
*@lv: length of value of variable
*@next: next node
*/
typedef struct store_var_list 
{
    int var_len;
    char *value;
    int lv;
    struct store_var_list *next;
}_var;

/**
* cde_functions - struct for cd, exit, env functions (builtin)
* @name: name of function
* @func: ptr function
*/
typedef struct cde_functions
{
    char *name;
    int (*func)(my_shell *data);
}cde_functions_t;

/*
*/
typedef struct data
{
    char **av;
    char **args;
    char **_environ;
    char *pid;
    char input;
    int count;
    int stat;
}my_shell;

/*mem.c - memory functions*/
void *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocc(char **ptr, unsigned int old_size, unsigned int new_size);

/*_readline function*/
char *_readline(int *i);

/* _getline() function*/
void new_line(char **lptr, size_t *n, char *buff, size_t j);
ssize_t _getline(char **lptr, size_t *n, FILE *streams);

/*execute line function*/
int exe_line(my_shell *data);

/*splitline.c - split line function*/
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void _next(sep_list, **line_list **list_l, my_shell *data);
char *swap(char *input, int b);
int split_cmd(my_shell *data, char *input);
char **split_line(char *input);

/*shell loop.c*/
char *wcomm(char *i);
void shell_loop(my_shell *data);

/* execline.c*/
int execline(my_shell *data);

/*execute_cmd.c*/
int _isdir(char *path, int *i);
int is_exec(my_shell *data);
int _checkcmderr(char *dir, my_shell *data);
int execute_cmd(my_shell *data);
char *_locate(char *cmd, char**_environ);

/*errors.c*//*_error.c*//*errors_sea.c*//*syntax_errors.c*/
char _strcat_cd(my_shell *data, char *msg, char *count, char *err);
char *error_cd(my_shell *data);
char *err_not_found(my_shell *data);
char *err_exit(my_shell *data);
char *env_err(my_shell *data);
char *path_err(my_shell *data);
int _error(my_shell *data, int e);
int syntax_err(my_shell *data, char *in);
char *alias_err(char **args);

/*exit.c*/
int exit_sh(my_shell *data);

/*cd-main.c*/
int _cd(my_shell *data);

/*cd.c*/
void *cd_parent(my_shell *data);
void cd_in(my_shell *data);
void cd_prev(my_shell *data);
void cdhome(my_shell *data);

/*stdlib.c*/
int _getlen(int i);
int *_atoi(char *str);
char _itoa(int i);

/*help.c*/
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void _help_ot(void);
void help_exit(void);
void _help(void);
void help_alias(void);
void help_cd(void);
int _gethelp(my_shell *data);

/*_syntax_err*/
int sep_err(char *in, int i, char l);
int rep_char(char *in, int i);
int charfirst(char *in, int *i);
int check_syntax_error(my_shell *data, char *in, int i, int j);
void print_syntax_error(my_shell *data, char *in, int i, int j);
