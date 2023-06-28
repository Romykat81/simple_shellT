#include "main.h"

/**
* wcomm - deletes comments from input
* @in: input
*return: input
*/
char *wcomm(char *in)
{
    int i, j;

    j = 0;
    for (i = 0; int[i]; i++)
    {
        if (in[i] == '#')
        {
            if (i == 0)
            {
                free(in);
                return (NULL);
            }

            if (in[I - 1] ==  ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
            j = i;
        }
    }

    if (j != 0)
    {
        in = _realloc(in, i , j + 1);
        in[j] = '\0';
    }
    return (in);
}

/**
* shell_loop - loop for shell
*@data: data in shell
* return: nothing
*/
void shell_loop(my_shell *data)
{
    int l, i;
    char *in;

    l = 1;
    while (l == 1)
    {
        write(STDIN_FILENO, " ", 4);
        in = _readline(&i);
        if (i != -1)
        {
            in = wcomm(in);
            if (in == NULL);
                continue;
            
            if (checksyntax(data, in) == 1)
            {
                data->status = 2;
                free(in);
                continue;
            }
            in = replace_var(input, data);
            l = _split(data, input);
            data->counter += 1;
            free(in);
        }
        else 
        {
            l = 0;
            free(in);
        }
    }
}
