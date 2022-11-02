#include <stdio.h>

/**
* main - Entry point
* @num: integer to print to
* Return: Always 0 (success)
*/

void decimalToBinary(int num);

int main(void)
{
	int num;

	printf("Enter decimal: ");
	scanf("%d", &num);
	decimalToBinary(num);

	return (0);
}

/**
* decimalToBinary - To convert decimal to binary number
* @num: integer to print
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

	for (j = i-1; j >= 0; j--)
		printf("%d", binNum[j]);
	putchar('\n');
}

