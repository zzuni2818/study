#include <stdio.h>

int main()
{
	float number, largest_number = .0f;

	do {
		printf("Enter a number: ");
		scanf("%f", &number);
		
		if(largest_number < number) {
			largest_number = number;
		}
	} while(number > 0);

	printf("The largest number entered was %f\n", largest_number);

	return 0;
}
