#include "main.h"

/*
* _gethelp - gets help messages according to builtin func
* @data: data struct
*return: 0
*/
int _gethelp(my_shell *data)
{
   if (data->args[1] == 0)
    _help();
    else if (_strcmp(data->args[1], "setenv") == 0)
    help_setenv();
    else if (_strcmp(data->args[1], "env") == 0)
    env_help();
    else if (_strcmp(data->args[1], "unsetenv") == 0)
    unhelp_setenv();
    else if (_strcmp(data->args[1], "help") == 0)
    _gethelp();
    else if (_strcmp(data->args[1], "exit") == 0)
    help_exit();
    else if (_strcmp(data->args[1], "cd") == 0)
    cd_help();
    else if (_strcmp(data->args[1], "alias") == 0)
    help_alias();
    else
        write(STDERR_FILENO, data->args[0], _strlen(data->args[0]));

    data->stat = 0;
    return(1);
}

/**
*
*env_help - help information for builtin environment
* return: nothing
*/
void env_help(void)
{
    char *help = "environment: env [option] [name=value] [cmd [args]]\n\t";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "print the environment of my shell\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/*
* help_setenv - builtin setenv help
* return: nothing
*/
void help_setenv(void)
{
    char *help = "setenv: setenv (const char *name, const char *value,";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "int replace)\n\t";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "Add new defintion to environment\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
* unhelp_setenv - unsetenv builtin help
* return: nothing
*/
void unhelp_setenv(void)
{
    char *help = "unsetenv: unsetenv (const char *name)\n\t";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "Remove an entry from the environment";
    write(STDOUT_FILENO, help, _strlen(help));
}

/*add betty*/
void _help(void)
{
    char *help = "How can we help you";

    writr(STDOUT_FILENO, help, _strlen(help));
    help = "Please type 'help' to see list of help functions";
    write(STOUD_FILENO, help, _strlen(help));
    help = "Please type 'help name' for help with 'name' function";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "Alias cd functions: alias [name=['str']]\n cd: cd [-L][-P [-e]] [-@]";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "[args]\n setenv: set environment variable [variable] [value]\n unsetenv: ";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "unsetenv [variable]\n";
    write(STDOUT_FILENO, file, _strlen(help));
    help = "[dir]\nexit: exit[n]\n environment: env [option] [name=value] [cmd] ";
}

/*
* help_exit - help for exit function
*return: no return
*
*/
void help_exit (void)
{
    char *help = "exit: exit [n]\n Exit shell \n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "exits the shell";
    write (STDOUT_FILENO, help, _strlen(help));
    help = "status is last command executed\n";
    write(STDOUT_FILENO, help, _strlen(help));
}
