#include "main.h"
/**
 * find_cmd - Entry Point
 * @in_command: the argument passed
 * Return: Null
 */
char *find_cmd(char *in_command);

char *find_cmd(char *in_command)
{
	char *c_env_path, *c_path_copy, *c_path_token, *c_file_path;
	int i_cmd_length, i_dir_length;
	struct stat s_buffer;

	c_env_path = getenv("PATH");

	if (c_env_path)
	{
	c_path_copy = strdup(c_env_path);
	i_cmd_length = strlen(in_command);
	c_path_token = strtok(c_path_copy, ":");

	while (c_path_token != NULL)
	{
	i_dir_length = strlen(c_path_token);
	c_file_path = malloc(i_cmd_length + i_dir_length + 2);

	if (c_file_path == NULL)
	{
	/** printf("find_cmd: file search error"); */
	free_me(c_path_copy);
	return (NULL);
	}

	strcpy(c_file_path, c_path_token);
	strcat(c_file_path, "/");
	strcat(c_file_path, in_command);
	strcat(c_file_path, "\0");

	if (stat(c_file_path, &s_buffer) == 0)
	{
	/** printf("find_cmd: file search success"); */
		free_me(c_path_copy);
		return (c_file_path);
	}
	else
	{
	/** printf("find_cmd: file search halt"); */
		free_me(c_file_path);
		c_path_token = strtok(NULL, ":");
	}
	}

	if (c_path_copy != NULL)
	{
	/** printf("find_cmd: c_path_copy is NULL"); */
		free(c_path_copy);
	}

	if (c_file_path != NULL)
	{
	/**	printf("find_cmd: c_file_path is NULL"); */
		free_me(c_file_path);
	}

	}

	if (stat(in_command, &s_buffer) == 0)
	{
	/**	printf("find_cmd: returning cmd"); */
		return (strdup(in_command));
	}

	return (NULL);
}
