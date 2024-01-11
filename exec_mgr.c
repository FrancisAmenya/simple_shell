#include "main.h"
/**
 * exec_mgr - Entry Point
 * @my_argv: command arguments typed by user
 *
 * Return: status 0 if success, -1 if failed, 1 if error
 */
int exec_mgr(char **my_argv);

int exec_mgr(char **my_argv)
{
	char *c_command = NULL, *c_actual_command = NULL;
	int a_status = 0;

	if (my_argv && my_argv[0])
	{
		c_command = my_argv[0];

		c_actual_command = find_cmd(c_command);

		if (c_actual_command)
		{
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("fork failed:");
				return (0);
			}

			if (child_pid == 0)
			{

				if (execve(c_actual_command, my_argv, NULL) == -1)
				{
					perror("Hsh: wrong user group, please retry");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(child_pid, &a_status, 0);
				if (WIFEXITED(a_status))
				{
					return (WEXITSTATUS(a_status));
				}
			}
		}
		else
		{
			printf("%s: not found \n", c_command);
			return (0);
		}
	}

	if (c_command != NULL)
	{
		printf("exec_mgr: attempting to free ccommand");
		free_me(c_command);
	}
	return (0);
}
