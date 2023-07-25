#include <stdio.h>

int main()
{
	int n, i, j, denominator;
	float e;

	printf("Enter the number: ");
	scanf("%d", &n);

	e = 1.0f;
	for(i = 1; i <= n; i++) {
		denominator = 1;
		for(j = i; j > 1; j--) {
			denominator *= j;
		}
		e += (1.0f / denominator);
	}

	printf("e: %f\n", e);

	return 0;
}
