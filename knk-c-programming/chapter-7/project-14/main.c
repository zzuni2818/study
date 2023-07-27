#include <stdio.h>
#include <math.h>

int main()
{
	double x, y, x_y, average;

	printf("Enter a positive number: ");
	scanf("%lf", &x);

	y = 1.0;
	x_y = x / y;
	average = (y + x_y) / 2.0;
	while(fabs(average - y) >= 0.00001) {
		y = average;
		x_y = x / y;
		average = (y + x_y) / 2.0;
	}

	printf("Square root: %f\n", average);

	return 0;
}
