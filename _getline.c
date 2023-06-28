#include "main.h"

/**
* new_line - assigns the line variable to _getline
* @lptr: buff to store input
* @buff: buff to store str input
* @n: size of line
* @j: size of buff
*/
void new_line(char **lptr, size_t *n, char *buff, size_t j)
{
    if (*lptr == NULL)
    {
        if (j > SIZE)
            *n = j;
        else
            *n = SIZE;
        *lptr = buff;
    }
    else if (*n < j)
    {
        if (j > SIZE)
            *n = j;
        else
            *n = SIZE;
        *lptr = buff;
    }
    else
    {
        _strcpy(*lptr, buff);
        free(buff);
    }
}
/**
* _getline - reads stream input 
*@lptr: buffer to store line input
*@n: size
*@
*/
_getline(char **lptr, size_t *n, FILE *streams)
{
    int i;
    char *buff;
    char j = 'z';
    ssize_t value;
    static ssize_t in;

    if (in == 0)
    {
        fflush(stream);
    }
    else
        return (-1);
    in = 0;

    buff = malloc(sizeof(char) * SIZE);
    if (buff == 0)
            return (-1);
    while (j != '\n')
    {
        i = read(STDIN_FILENO, &j, 1);
        if (i == -1 || (i == 0 && in == 0))
        {
            free(buff);
            return(-1);
        }
        if (i == 0 && in != 0)
        {
            in++;
            break;
        }
        if (in >= SIZE)
            buff = _realloc(buff, in, in + 1);
        buff[in] = j;
        in++;
    }
    buff[in] = '\0';
    new_line(lptr, n, buff, in);
    value = in;
    if (i != 0)
        in = 0;
    return (value);
}
