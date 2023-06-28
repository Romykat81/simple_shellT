#include "main.h"

/*
* cd_parent - changes dir to parent
* @data: data struct
* return: nothing
*/
void cd_parent(my_shell *data)
{
    char pwd[PATH_MAX];
    char *dir, *cd_pwd, *pwd2;

    getcwd(pwd, sizeof(pwd));
    cd_pwd = _strdup(pwd);
    _setenv("OLDPWD", cd_pwd, data);
    dir = data->args[1];
    if (_strcmp(".", dir) == 0)
    {
        _setenv("PWD", cd_pwd, data);
        free(cd_pwd);
        return;
    }
    if (_strcmp("/", cd_pwd) == 0)
    {
        free(cd_pwd);
        return;
    }
    pwd2 = cd_pwd;
    rev_string(pwd2);
    pwd2 = _strtok(pwd2, "/");
    if (pwd2 != NULL)
    {
        pwd2 = _strtok(NULL, "\0");

        if (pwd2 != NULL)
            rev_string(pwd2);
    }
    if (pwd2 != NULL)
    {
        chdir(pwd2);
        _setenv("PWD", pwd2, data);
    }
    else
    {
        chdir("/");
        _setenv("PWD", "/", data);
    }
    data->status = 0;
    free(cd_pwd)
}

/*
* cd_in - changes dir to input dir
* @data: data struct
* return: nothing
*/
void cd_in(my_shell *data)
{
    char pwd[PATH_MAX];
    char *dir, cd_pwd, cp;

    getcwd(pwd, sizeof(pwd));

    dir = data->args[1];
    if (chdir(dir) == -1)
    {
        error_cd(data, 2);
        return;
    }

    cd_pwd = _strdup(pwd);
    _setenv("OLDPWD", cd_pwd, data);

    cp = _strdup(dir);
    _setenv("PWD", cp, data);

    free(cp);
    free(cd_pwd);

    data->status = 0;

    chdir(dir);
}

/*
* cd_prev - changes dir to prev dir
* @data: data struct
* return: nothing
*/
void cd_prev(my_shell *data)
{
    char pwd[PATH_MAX];
    char *prev, old, cd_pwd, cd_old;

    getcwd(pwd, sizeof(pwd));
    cd_pwd = _strdup(pwd);

    old = _getenv("OLDPWD", data->_env);

    if (old == NULL)
        cd_old = cp;
    else
        cd_old = _strdup(old);
    
    _setenv("OLDPWD", cp, data);

    if (chdir(cd_old) == -1)
        _setenv("PWD", cp, data);
    else
        _setenv("PWD", cd_old, data);
    
    prev = _getenv("PWD", data->_env);

    write(STDOUT_FILENO, prev, _strlen(prev));
    write(STDOUT_FILENO, "\n", 1);

    free(cp);
    if (prev)
        free(cd_old);
    
    data->status = 0;

    chdir(prev);
}

/*
*
* cdhome - change dir to home directory
* @data: data struct
* return: nothing
*/
void cdhome(my_shell *data)
{
    char *prev, *home;
    char pwd[PATH_MAX];

    getcwd(pwd, sizeof(pwd));
    prev = _strdup(pwd);

    home = _getenv("HOME", data->_environ);

    if (home == NULL)
    {
        _setenv("OLDPWD", prev, data);
        free(prev);
        return;
    }

    if (chdir(home) == -1)
    {
        error_cd(data, 2);
        free(prev);
        return;
    }

    _setenv("OLDPWD", prev, data);
    _setenv("PWD", home, data);
    free(prev);
    data->status = 0;
}
