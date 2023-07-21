#include <stdio.h>

#define PI 3.141592f

int main()
{
	float volume, radius;

	printf("Enter the radius: ");
	scanf("%f", &radius);

	volume = (4.0f / 3.0f) * PI * radius * radius * radius;

	printf("volume: %f of radius: %f\n", volume, radius);
	return 0;
}
