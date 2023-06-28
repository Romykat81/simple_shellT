#include "main.h"

/*
* _isdir - checks if curr directory
* @path: ptr to char
* @i: int ptr
* return: 1 
*/
int _isdir(char *path, int *i)
{
    if (path[*i] == ':')
        return (1);

    while (path[*i] != ':' && path[*i])
    {
        *i += 1;
    }

    if (path[*i])
        *i += 1;

    return (0);
}

/**
* _locate - locates cmd
* @cmd: command line
* @_environ: environment variable
* return: location of cmd
*/
char *_locate(char *cmd, char **_environ)
{
    char *path, *ptr, *token, *dir;
    int len, cmd_len, i;
    struct stat st;

    path = _getenv("PATH", _environ);
    if (path)
    {
        ptr = _strdup(path);
        cmdlen  = _strlen(cmd);
        token = _strtok(ptr, ":");
        i = 0;
        while (token != NULL)
        {
            if (_isdir(path, &i))
                if (stat(cmd, &st) == 0)
                        return (cmd);
            len = _strlen(token);
            dir = malloc(len, + cmdlen + 2);
            _strcpy(dir, token);
            _strcat(dir, "/");
            _strcat(dir, cmd);
            _strcat(dir, "\0");
            if (stat(dir, &st) == 0)
            {
                free(ptr);
                return (dir);
            }
            free(dir);
            token = _strok(NULL, ":");
        }
        free(ptr);
        if (stat(cmd, &st) == 0)
            return (cmd);
        return (NULL);
    }
    if (cmd[0] == '/')
        if (stat(cmd, &st) == 0)
            return (cmd);
        return (NULL);
}

/*
* is_exec - determines if cmd is executable
* @data: data struct
* return : 0 if not or other on success
*/
int is_exec(my_shell *data)
{
    int i;
    char *in;
    struct stat st;

    in = data->args[0];
    for (i = 0; in[i]; i++)
    {
        if (in[i] == '.')
        {
            if (in[i + 1] == '.')
                return (0);
            if (in[i + 1] == '/')
                continue;
            else
                break;
        }
        else if (in[i] == '/' && i != 0)
        {
            if (in[i + 1] == '.')
                continue;
            i++;
            break;
        }
        else
            break;
    }
    if (i == 0)
        return (0);

    if (stat(in + i, &st) == 0)
    {
        return (i);
    }
    _error(data, 127);
    return (-1);
}
