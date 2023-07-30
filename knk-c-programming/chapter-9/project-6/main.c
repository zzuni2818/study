#include <stdio.h>

int calculate_polynomial(int x);

int main()
{
	int x;

	printf("Enter x: ");
	scanf("%d", &x);

	printf("result is %d\n", calculate_polynomial(x));

	return 0;
}

int calculate_polynomial(int x)
{
	return (((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);
}
