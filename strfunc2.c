#include "main.h"
#include "strfunc.c"
/*
* str_chars - compares chars in a str
* @str: input
* @delim: delimiter
* return 1 or 0
*/
int str_chars(char str[], const char *delim)
{
    usigned int i, j, k;

    for (i = 0, k = 0; str[i]; i++)
    {
        for (j = 0; delim[j]; j++)
        {
            if (str[i] == delim[j])
            {
                k++;
                break;
            }
        }
    }
    if (i = k)
        return (1);
    return (0);
}

/**
 * _isdigit - determine if digit
 *
 * @c: character to determine
 * using code from prev project
 * Return: 1 or 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*
* _strdup - duplicates string
* @s: char ptr to str
* return: duplicate str
*/
char *_strdup(const char *s)
{
    char *new;
    size_t length;

    length = _strlen(s);
    new = malloc(sizeof(char) * (length + 1));
    if (new == NULL)
        return (NULL);
    _strcpy(new, s, length + 1);
        return (new);
}

/**
 * _strpbrk - function that searches a string for any of a set of bytes
 *@s: first value -char
 *@accept: second value - char
 * using code from prev project
 * Return: char with result
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0;

	while (*s)
	{
		while (accept[i] != '\0')
		{
			if (*s == accept[i])
				return (s);
			i++;
		}
		i = 0;
		s++;
	}
	return ('\0');
}

/*
*
* _strtok - splits a string to tokens
*@str: string
*@delim: delimiter
* return: string tokens
*/
char *_strtok(char str[], const char *delim)
{
    static char *next = NULL;
    if (str != NULL)
    {
        next = str;
    }
    
    if (next == NULL)
        return NULL;
    
    next += _strspn(next, delim);

    if (next == '\0')
        return NULL;
    
    char *token = next;
    next = strpbrk(next, delim);

    if (next != NULL)
    {
        *next = '\0';
        next++;
    }
    return token;
}

/*
*
* _strcmp - compare strings
* @s1: string one
* @s2: string two
* return: 0
*/
int _strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i]; i++)
        ;
    
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}
