#include "main.h"

/**
 * _strlen - gets character string
 * using code from prev project
 * @s: character to getstring
 * Return: returns length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{}
	return (i);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 * using code from prev projects
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: copy to
 * @src: copy from
 * Return: two concat strings
 * using code from prev project
 */
char *_strcat(char *dest, char *src)
{

	int i, n;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (n = 0; (dest[i + n] = *src++) != '\0'; n++)
	{
	}
	return (dest);
}

/**
 * _strspn - function that gets the length of a prefix substring
 *@s: first value
 *@accept: second value
 * using code from prev project
 * Return: char with result
 */
unsigned int _strspn(char *s, char *accept)
{
	int j = 0;
	int i = 0;
	unsigned int a = 0;

	while (s[i] != ' ' && s[i] != '\0')
	{
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				a++;
			j++;
		}
		i++;
		j = 0;
	}
	return (a);
}

/**
 * _strchr - function that locates a char in a string
 *@s: first value
 *@c: second value
 * using code from prev projects
 *  Return: char
 */
char *_strchr(char *s, char c)
{
	if (*s == '\0')
		return (s);
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
		return (s);
	return ('\0');
}
