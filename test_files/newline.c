#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints "$ "
 * wait for the user to enter a command,
 * prints it on the next line.
 * Return: Always 0 (success)
 */

int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1 && *buffer != EOF)
	{
		printf("hsh$ ");
		getline(&buffer, &len, stdin);
		printf("%s", buffer);
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}
