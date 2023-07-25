#include <stdio.h>

int main()
{
	int i, j, denominator;
	float epsilon, e, temp;

	printf("Enter the epsilon: ");
	scanf("%f", &epsilon);

	e = 1.0f;
	for(i = 1; ;i++) {
		denominator = 1;
		for(j = i; j > 1; j--) {
			denominator *= j;
		}

		temp = (1.0f / denominator);
		if(temp < epsilon) {
			break;
		}
		
		e += temp;
	}

	printf("e: %f\n", e);

	return 0;
}
