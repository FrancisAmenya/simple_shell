#include "main.h"
/**
 * main - main shell
 * @my_argc: int of char count, argument 1
 * @my_argv: char of user string, argument 2
 *
 * Return: exit status, 0 if success, 1 if error, -1 if fail
 */
int main(int my_argc, char **my_argv);

int main(int my_argc, char **my_argv)
{
	char *char_user_prompt = "$: ";
	char *char_line_printer = NULL;
	char *char_line_printer_cp = NULL;
	size_t ss_ccount = 0;
	ssize_t ss_ccharacters;
	const char *char_delims = " \n";
	int num_of_tokens = 0;
	char *chars_token;
	int i = 0;
	(void)my_argc;

	while (1)
	{
		printf("%s", char_user_prompt);
		fflush(stdout);
		i = 0;
		ss_ccharacters = getline(&char_line_printer, &ss_ccount, stdin);
		/** see if getline fail or user exit */
		if (ss_ccharacters == -1 && isatty(STDIN_FILENO))
		{
			printf("Ctrl+D Exiting shell..\n");
			/** if (char_lineptr) */
			/**	free(char_lineptr); */
			free_me(char_line_printer);
			char_user_prompt = NULL;
			char_delims = NULL;
			(void)&ss_ccount;
			(void)&num_of_tokens;
			(void)&i;
			return (0);
		}

		if (ss_ccharacters == 0)
		{
			printf("Nothing was typed.\n");
			/** if (char_lineptr) */
			/**	free(char_lineptr); */
			free_me(char_line_printer);
			return (0);
		}

		char_line_printer[strcspn(char_line_printer, "\n")] = '\0';

		if (strcmp(char_line_printer, "exit") == 0)
		{
			printf("User typed exit, exiting Shell..\n");
			/**if (char_lineptr) */
			/**free(char_lineptr); */
			free_me(char_line_printer);
			break;
		}

		if (strcmp(char_line_printer, "env") == 0)
		{
			/** execmd(char_lineptr); */
			printf("Not yet implemented, Exiting Shell..\n");
		}

		char_line_printer_cp = malloc(sizeof(char) * ss_ccharacters);
		if (char_line_printer_cp == NULL)
		{
			perror("tsh: memory allocation error");

			free_me(char_line_printer);
			free_me(char_line_printer_cp);
			return (-1);
		}

		strcpy(char_line_printer_cp, char_line_printer);
		chars_token = strtok(char_line_printer, char_delims);

		while (chars_token != NULL)
		{
			num_of_tokens++;
			chars_token = strtok(NULL, char_delims);
		}

		num_of_tokens++;

		my_argv = malloc(sizeof(char *) * num_of_tokens);
		chars_token = strtok(char_line_printer_cp, char_delims);


		for (i = 0; chars_token != NULL; i++)
		{

			my_argv[i] = malloc(sizeof(char) * (strlen(chars_token)) + 1);
			strcpy(my_argv[i], chars_token);
			chars_token = strtok(NULL, char_delims);
		}
		my_argv[i] = NULL;

		/**added to test env cmd*/
		if (my_argv)
		{
			exec_mgr(my_argv);
		}
		/**end *added to test env cmd*/
		for (i = 0; my_argv[i] != NULL; i++)
		{
			free_me(my_argv[i]);
		}

			free_me(char_line_printer);
			free_me(chars_token);
			free_me(char_line_printer_cp);
		/** if (char_lineptr_cp != NULL) */
		/** free_me(char_lineptr_cp); */

		/** if (char_lineptr != NULL) */
		/** free_me(char_lineptr); */

		printf("_________________2nd last:@ Main While\n");
	}

	printf("_________________last:@Main\n");
	return (0);
}
