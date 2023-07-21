#include <stdio.h>

int main()
{
	int x;

	printf("Enter x: ");
	scanf("%d", &x);

	printf("result is %d\n", ((3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6));
	return 0;
}
