#include "mac.h"

/**
* main - more on wait call
* return: 0 on suceess
*/

int main(void)
{
	if (fork() == 0)
		printf("HC: hello from child\n");
	else
	{
		printf("HP: hello from parent\n");
		wait(NULL);
		printf("CT: child has terminated\n");
	}

	printf("Bye\n");

	return (0);
}

