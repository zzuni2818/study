#include <stdio.h>

int power(int x, int n);

int main()
{
	int x, n;

	printf("Enter x and n: ");
	scanf("%d %d", &x, &n);

	printf("result of %d poser of %d: %d\n", x, n, power(x, n));

	return 0;
}

int power(int x, int n)
{
	if(n <= 0) {
		return 1;
	}

	if(n % 2 == 0) {
		return power(x, n / 2) * power(x, n / 2);
	} else {
		return x * power(x, n - 1);
	}
}
