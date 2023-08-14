#include <stdio.h>

union ieee_float {
	float value;
	struct {
		unsigned int fraction: 23;
		unsigned int exponent: 8;
		unsigned int sign: 1;
	};
};

int main()
{
	union ieee_float f;

	f.sign = 1;
	f.exponent = 128;
	f.fraction = 0;

	printf("%.1f\n", f.value);

	return 0;
}
