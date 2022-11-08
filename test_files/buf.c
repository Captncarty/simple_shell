#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *main - writing command in newline and splitting strings
 *Return: 0
 */
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;
	char *token;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("getline: %s", buffer);
		
		putchar('\n');

		token = strtok(buffer, " ");
		while (token)
		{
			printf("parsing string: %s\n", token);
			token = strtok(NULL, " ");
		}
	}
	free(buffer);
	free(token);
	return (0);
}
