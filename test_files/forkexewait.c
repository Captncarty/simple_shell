#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * @brief: fork + wait + execve
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid = 1;
	int i = 0;
	int status;
	char *argv[] = {"bin/ls", "-l", "/tmp/", NULL};
	char *env[] = {
		"HOME=/usr/home", "LOGNAME=home", NULL
		};

	my_pid = getpid();
	while (i <= 6 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("error");
			return (1);
		}
		wait(&status);
		i++;
	}
	if (child_pid == 0)
	{
		printf("--------------------------------\n\n");
		printf("CHILD ID: %u\n\nFATHER ID: %u\n\n", getpid(), getppid());
		printf("--------------------------------\n\n");

	}
	else
	{
		printf("I am the father: %u and this is my child: %u\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, env))
	{
		perror("Error: ");
	}
	return (0);
}
