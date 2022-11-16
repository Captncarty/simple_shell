#include <stdio.h>

/**
* main - Entry point
* @num: integer to print to
* Return: Always 0 (success)
*/

void compare(int num);
void decimalToBinary(int num);

int main(void)
{
	int num;

	printf("Enter decimal: ");
	scanf("%d", &num);
	decimalToBinary(num);

	compare(num);

	return (0);
}

/**
* decimalToBinary - To convert decimal to binary number
* @num: integer number to print
* Return: binary number
*/

void decimalToBinary(int num)
{
	int binNum[32], i, j;

	if (num == 0)
	{
		printf("0");
		return;
	}

	while (num > 0)
	{
		binNum[i++] = num % 2;
		num /= 2;
	}

	for (j = i - 1; j >= 0; j--)
		printf("%d", binNum[j]);
	putchar('\n');
}

/**
* compare - checking for the powers of 2
* @num: integer to compare
* Return: 1 for true and -1 for fail
*/

void compare(int num)
{
	/* an int to compare with */
	unsigned int n;
	
	if (num == 0)
	{
		printf("NULL");
	}
	n = num << 2;
	
	printf("%d\n", n);
}


