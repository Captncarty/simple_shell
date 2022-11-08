#include <stdio.h>
#include <unistd.h>

/**
* @info - breaking the shell
* @1: system calls
*/

int main(void)
{
	pid_t sys;
	pid_t syt;
	pid_t pid;

	syt = getppid();
	pid = fork();
	sys = getpid();

	printf("calling process / child\'s ID: %u\n", sys);
	printf("parent\'s ID: %u\n", syt);

	return (0);
}
