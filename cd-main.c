#include "main.h"

/*
* _cd - changes current directory
* @data: data struct
* return: 1 on success
*/
int _cd(my_shell *data)
{
    char *dir;
    int home, tilde, dash;

    dir = data->args[1];

    if (dir != NULL)
    {
        home = _strcmp("$HOME", dir);
        tilde = _strcmp("~", dir);
        dash = _strcmp("--", dir);
    }

    if (dir == NULL || !home || !tilde || !dash)
    {
        cdhome(data);
        return (1);
    }

    if (_strcmp("-", dir) == 0)
    {
        cd_prev(data);
        return (1);
    }

    if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
    {
        cd_parent(data);
        return (1);
    }

    cd_in(data);

    return (1);
}
