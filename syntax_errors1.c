#include "main.h"

/*
* repchar - finds char repitition
* @in: input
* @i: index
* return: repitition
*/
int repchar(char *in, int i)
{
    if (*(in - 1) == *in)
        return (repchar(in - 1, i + 1));
    
    return (i);
}

/*
* _first - finds index for first char
* @in: input
* @i: index
* return: 1 or 0
*/
int _first(char *in, int *i)
{
    for (*i = 0; in[*i]; *i += 1)
    {
        if (in[*i] == ' ' || in[*i] == '\t')
            continue;
        
        if (in[*i] == ';' || in[*i] == || in[*i] == '&')
            return (-1);
        
        break;
    }
    return (0);
}

/*
* _find - finds syntax errors
* @i: index in
* @in: input
* @last: last char
* return: index
*/
int _find(char *in, int i, char *last)
{
    int count;

    count = 0;
    if (*in == '\0')
        return (0);
    
    if (*in == ' ' || *in == '\t')
        return (_find(in + 1, i + 1, last));

    if (*in == ';')
        if (last == '|' || last == '&' || last == ';')
            return (i);
    
    if (*in == '|')
    {
        if (last == ';' || last == '&')
            return (i);

        if (last == '|')
        {
            count = repchar(in, 0);
            if (count == 0 || count > 1)
                return (i);
        }
    }

    if (*in == '&')
    {
        if (last == '&')
        {
            count = repchar(in, 0);
            if (count == 0 || count > 1)
                return (i);
        }
    }
    return (_find(in + 1, i + 1, *in));
}

/*
* syntax_err- checks and prints syntax errors
* @data: data struct
* @in: input
* return 1 on error or  NULL
*/
int syntax_err(my_shell *data, char *in)
{
    int start = 0, first = 0, i = 0;

    first = _first(in, &start);
    if (first == -1)
    {
        print_syntax_error(data, in, start, 0);
        return (1);
    }

    i = _find(in + start, 0, *(in + start));
    if (i != 0)
    {
        print_syntax_error(data, in, start + i, 1);
        return (1);
    }

    return (0);
}

/*
* print_syntax_error - prints error 
* @data: data struct
* @in: input
* @i: index
* @j: ctrl msg err
*/
void syntax_error(my_shell *data, char *in, int i, int j)
{
    char *msg, *msg2, *msg3, *err, *count;
    int length;

    if (in[i] == ';')
    {
        if (j == 0)
        {
            msg = (in[i + 1] == ';' ? ";;" : ";");
            else
            msg = (in[i - 1] == ';' ? ";;" : ";");
        }

        if (in[i] == '|')
            msg = (in[i + 1] == '|' ? "||" : "|");
        
        if (in[i] == '&')
            msg = (in[i + 1] == '&' ? "&&" : "&");

        msg2 = ": Syntax error: \"";
        msg3 = "\" unexpected\n";

        count = _itoa(data->count);
        length = _strlen(data->av[0]) + _strlen(count);
        length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

        err = malloc(sizeof(char) * (length + 1));
        if (err == 0)
        {
            free(count);
            return;
        }
        _strcpy(err, data->av[0]);
        _strcat(err, ": ");
        _strcat(err, count);
        _strcat(err, msg2);
        _strcat(err, msg);
        _strcat(err, msg3);
        _strcat(err, "\0");

        write(STDERR_FILENO, err, length);
        free(err);
        free(count);
    }
}
