#include <stdio.h>
#include <complex.h>
#include <math.h>

#define PI (3.141592)

void print_complex(double complex z);

int main()
{
	double complex result;
	int n, k;

	printf("Enter n: ");
	scanf("%d", &n);

	for(k = 0; k < n; k++) {
		result = cexp((2 * PI * I * k) / n);
		print_complex(result);
	}

	return 0;
}

void print_complex(double complex z)
{
	if(cimag(z) != 0.0) {
		printf("%g %c %gi\n", creal(z), (cimag(z) < 0 ? '-' : '+'), fabs(cimag(z)));
	} else {
		printf("%g\n", creal(z));
	}
}
