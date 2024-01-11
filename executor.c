#include "main.h"

/**
 * executor - runs envc command
 * @my_args: char that holds env arguments
 *
 * Return: exit status 0 for success, 1 has errored, -1 is failure
 **/

/** Function to execute a command **/
int executor(char *my_args[]);

int executor(char *my_args[])
{
	pid_t zs_pid, zchild_pid;
	int z_int_status;

	(void)zchild_pid;
	z_int_status = 0;
	zs_pid = fork();

	if (zs_pid == -1)
	{
		perror("shell: fork fatal error");
		/** printf("executor error: zpi is -1..\n"); */
		z_int_status = -1;
		return (z_int_status);
	}

	if (zs_pid == 0)
	{
		/** Creates a fork if process exists **/

		char *envp[] = { "PATH=/bin", NULL };

	if (execve(my_args[0], my_args, envp) == -1)
	{
		perror("shell process doesn't exist");
		/** printf("executor error: zpid is 0 && execve is -1..\n"); */
		z_int_status = 1;
		/**		exit(EXIT_FAILURE); */
		return (z_int_status);
	}

	}

	else if (zs_pid < 0)
	{
		perror("shell: fork env incorrect process group");
		/** printf("executor error: zpid is 0..\n"); */
		z_int_status = -1;
	}

	/***********************************************************/
	else
	{

	do {
	/** printf("executor error: zwpid do..while \n"); */
		zchild_pid = waitpid(zs_pid, &z_int_status, WUNTRACED);
	} while (!WIFEXITED(z_int_status) && !WIFSIGNALED(z_int_status));
	}

	/**	if(args) */
		/**		free(args); */

	return (z_int_status);
}
