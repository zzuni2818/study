#include <stdio.h>

int main()
{
	int number, result, i;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	result = 1;
	for(i = number; i > 0; i--) {
		result *= i;
	}

	printf("Factorial of %d: %d\n", number, result);

	return 0;
}
