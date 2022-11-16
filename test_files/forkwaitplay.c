#include "mac.h"

/**
* main - more on fork + wait
* return: 0 on success
*/

int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	/* skips this if no child */
	{
		printf("Wait for me, wait for me\n");
		sleep(5);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}

