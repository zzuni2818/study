#include <stdio.h>
#include <complex.h>
#include <math.h>

int main()
{
	double a, b, r, theta;

	printf("Enter a and b: ");
	scanf("%lf %lf", &a, &b);

	r = cabs(a + b * I);
	theta = carg(a + b * I);

	printf("r: %f\n", r);
	printf("theta: %f\n", theta);

	return 0;
}

