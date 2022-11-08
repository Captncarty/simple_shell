#include <unistd.h>
#include <stdio.h>

/**
* main - entry point
* Return: child and parent process
*/

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();

	printf("child process: %u\n", my_pid);

	return 0;
}
