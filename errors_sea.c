#include "main.h"

/*
* err_env - error msg for environment error
* @data: data struct
* return: nothing
*/
char *env_err(my_shell *data)
{
    int len;
    char *error, *count, *msg;

    count = _itoa(data->counter);
    msg = " UNABLE TO ADD/REMOVE ENVIRONMENT\n";
    length = _strlen(data->av[0]) + _strlen(count);
    length += _strlen(data->args[0]) + _strlen(msg) + 4;
    error = malloc(sizeof(char) * (length + 1));
    if (error == 0)
    {
        free(error);
        free(count);
        return (NULL);
    }

    _strcpy(error, data->av[0]);
    _strcat(error, ": ");
    _strcat(error, count);
    _strcat(error, ": ");
    _strcat(error, data->args[0]);
    _strcat(error, msg);
    _strcat(error, "\0");
    free(count);

    return (error);
}

/*
* err_path - err message for path failure and permissions
* @data: data struct
* return: err msg
*/
char *path_err(my_shell *data)
{
    int length;
    char *count, *error;

    count = _itoa(data->counter);
    length = _strlen(data->av[0] + _strlen(count));
    length += _strlen(data->args[0]) + 24;
    error = malloc(sizeof(char) * (length + 1));
    if (error == 0)
    {
        free(error);
        free(count);
        return (NULL);
    }
    _strcpy(error, data->av[0]);
    _strcat(error, ": ");
    _strcat(error, count);
    _strcat(error, ": ");
    _strcat(error, data->args[0]);
    _strcat(error, "\0");
    free(count);
    return (error);
}
