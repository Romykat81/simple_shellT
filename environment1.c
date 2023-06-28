#include "main.h"

/**
* _env - prints environment variables
* @data: data store
* return: 1 on success
*/
int _env(my_shell *data)
{
    int i, j;

    for (i = 0; data->environ[i]; i++)
    {
        for (j = 0; data->environ[i][j]; j++)
            ;

        write(STDOUT_FILENO, data->environ[i], j);
        write(STDOUT_FILENO, "\n", 1);
    }
    data->stat = 0;

    return (1);
}

/**
* _getenv - gets environment variable
* @name: name of env
* @environ: env variable
* return: value of env var or NULL
*/
char *_getenv(const char *name, char **_environ)
{
    char *ptr;
    int i, j;

    ptr = NULL;
    j = 0;

    for (i = 0; _environ[i]; i++)
    {
        j = compare_env(_environ[i], name);
        if (j)
        {
            ptr = _environ[i];
            break;
        }
    }

    return (ptr + j);
}

/**
* compare_env - compares environment variables
* @name: name
* @envn: environment var name
* return: 0 if not equal
*/
int compare_env(const char *envn, const char *name)
{
    int i;

    for (i = 0; envn[i] != '='; i++)
    {
        if (envn[i] != name[i])
        {
            return (0);
        }
    }
    return (i + 1);
}
