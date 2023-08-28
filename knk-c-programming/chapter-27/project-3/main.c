#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, r, theta;

	printf("Enter r and theta: ");
	scanf("%lf %lf", &r, &theta);

	a = r * cos(theta);
	b = r * sin(theta);

	printf("%g + %gi\n", a, b);

	return 0;
}

