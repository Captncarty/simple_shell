#include <stdio.h>
#include <unistd.h>

/**
* main - parent and child
* ppid - parent
* pid - child
* return: 0 on success
*/

int main(void)
{
	pid_t pid;

	pid = getpid();

	printf("%d\n", pid);

	return (0);
}
