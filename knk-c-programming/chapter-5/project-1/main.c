#include <stdio.h>

int main()
{
	int number, digit_count;

	printf("Enter a number: ");
	scanf("%d", &number);

	if(number < 10){
		digit_count = 1;
	} else if(number < 100) {
		digit_count = 2;
	} else if(number < 1000) {
		digit_count = 3;
	} else {
		digit_count = 4;
	}
	
	printf("The number %d has %d digits\n", number, digit_count);

	return 0;
}
