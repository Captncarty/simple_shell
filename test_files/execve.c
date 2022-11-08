#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-la", "/usr/", NULL};
	char *env[] = {
		"HOME=/",
		"PATH=/bin/usr/bin",
		"TZ=UTC0",
		"USER=Captncarty",
		"LOGNAME=Carty",
		0
	};
    printf("Before execve\n");
    if (execve(argv[0], argv, env) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}


