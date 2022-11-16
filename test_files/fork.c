#include <stdio.h>
#include <unistd.h>

/**
 * main - using fork
 * Description: creating new process
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork\n");
	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	my_pid = getpid();
	printf("After fork\n");
	printf("My pid is %u\n", my_pid);
	return (0);
}

