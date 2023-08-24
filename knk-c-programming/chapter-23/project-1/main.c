#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a, b, c, x1, x2, value_in_root;

	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	printf("Enter c: ");
	scanf("%lf", &c);

	value_in_root = b * b - (4 * a * c);
	if(value_in_root < 0.0) {
		printf("Roots are complex.\n");
		exit(EXIT_FAILURE);
	}

	x1 = (-b + sqrt(value_in_root)) / (2 * a);
	x2 = (-b - sqrt(value_in_root)) / (2 * a);

	printf("x1: %f\n", x1);
	printf("x2: %f\n", x2);

	return 0;
}
