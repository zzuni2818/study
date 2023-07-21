#include <stdio.h>

#define PI 3.141592f

int main()
{
	float volume, radius = 10;

	volume = (4.0f / 3.0f) * PI * radius * radius * radius;

	// try (4/3) instead of (4.0f/3.0f)
	//volume = (4 / 3) * PI * radius * radius * radius;
	
	printf("%f\n", volume);
	return 0;
}
