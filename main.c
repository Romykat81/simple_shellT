#include "main.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(my_shell *datash)
{
	unsigned int i;

	for (i = 0; data->_environ[i]; i++)
	{
		free(data->_environ[i]);
	}

	free(data->_environ);
	free(data->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @data: data structureus
 * @av: argument vector
 * Return: no return
 */
void set_data(my_shell *data, char **av)
{
	unsigned int i;

	data->av = av;
	data->input = NULL;
	data->args = NULL;
	data->status = 0;
	data->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	data->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->_environ[i] = _strdup(environ[i]);
	}

	data->_environ[i] = NULL;
	data->pid = _itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	my_shell data;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&data, av);
	shell_loop(&data);
	free_data(&data);
	if (data.status < 0)
		return (255);
	return (data.status);
}
