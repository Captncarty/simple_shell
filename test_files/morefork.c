#include <stdio.h>
#include <unistd.h>

/**
* @brief: messing with fork
* Return: favorable outcomes
*/

int main(void)
{
	fork();
	fork();

	printf("enigma\n");

	return 0;
}
