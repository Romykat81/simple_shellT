#include "main.h"

/*
*_help - information for help function
*
* return: nothing
*/
void _help(void)
{
    char *help = "help [-dms] [pattern ...] \n"

    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tDisplay information about builtin cmds\n";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tDisplays summary of builtin cmds\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/*
* help_alias - help for alias function
* return: nothing
*/
void help_alias(void)
{
    char *help = "alias: alias [-p] [namee[=value]...]\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tDefine or display alias";
    write(STDOUT, help, _strlen(help));
}

/*
* cd_help - help function for changing directory
*
* return: nothing
*/
void cd_help(void)
{
    char *help = "cd: cd [-L|-P [-e]] [-@] [dir]\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "\tChange shell directory\n";
    write(STDOUT_FILENO, help, _strlen(help));
}
