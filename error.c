#include "main.h"

/*
* _error - calls errors for cde funcs, syntax, permissions
* @data: data struct
* @e: error value
*/
int _error(my_shell *data, int e)
{
    char *error;

    switch (e)
    {
        case -1:
            error = env_err(data);
            break;
        case 126:
            error = path_err(data);
            break;
        case 127:
            error = err_not_found(data);
            break;
        case 2:
            if (_strcmp("exit", data->args[0]) == 0)
                error = err_exit(data);
            else if (_strcmp("cd", data->args[0]) == 0)
                error = error_cd;
            break;
    }

    if (error)
    {
        write(STDERR_FILENO, error, _strlen(error));
        free(error);
    }

    data->status = e;
    free(e);
}
