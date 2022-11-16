#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* main - splitting strings into newlines
* return: always 0
*/

int main(void)
{
	char *token;
	char cum[50] = "house hold items";

	token = strtok(cum, " ");
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
