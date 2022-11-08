#include "mac.h"


/**
* @brief: Playing with wait + fork
* return: 0 on success
*/

int main(void)
{
	pid_t my_pid;

/*	if (fork() == 0)
		exit(0); */  //returns -1 if no child process
	/*else*/
		my_pid = wait(NULL); // reaping parent
	
	printf("parent\'s :%d\n", getpid());
	printf("child\'s :%d\n", my_pid);

	return 0;
}

