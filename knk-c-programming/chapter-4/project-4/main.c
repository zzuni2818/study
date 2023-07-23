#include <stdio.h>

int main()
{
	int number;

	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &number);

	//answer 1
	/*
	printf("In octal, your number is: %d%d%d%d%d\n", 
	(number / 8 / 8 / 8 / 8) % 8,
	(number / 8 / 8 / 8) % 8,
	(number / 8 / 8) % 8,
	(number / 8) % 8,
	number % 8);
	*/

	//answer 2
	int result;

	result = number % 8;
	number /= 8;

	result += (number % 8) * 10;
	number /= 8;

	result += (number % 8) * 100;
	number /= 8;

	result += (number % 8) * 1000;
	number /= 8;

	result += (number % 8) * 10000;

	printf("In octal, your number is: %.5d\n", result);

	return 0;
}
