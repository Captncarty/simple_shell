#include <stdio.h>
/**
* main - environment
* @argc: argument count
* @argv: argument vector
* @envp: environment
*/

void main(int argc, char *argv[], char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("\n%s\n", envp[i]);
		}
}

