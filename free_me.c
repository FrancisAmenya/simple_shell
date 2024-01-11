#include "main.h"
/**
 * free_me - frees char memory
 * @argv: char of user string,
 *
 * Return: exit status, 0 if success, 1 if error, -1 if fail
 */
int free_me(char *argv)
{

while (argv)
{
free(argv);
argv = NULL;
}

return (0);
}
