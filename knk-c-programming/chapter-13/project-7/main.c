#include <stdio.h>

int main()
{
	const char *tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	const char *units[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const char *teen[] = {"eleven", "twelve", "thirteen", 
						"fourteen", "fifteen", "sixteen", 
						"seventeen", "eighteen", "nineteen"};
	const char *zero = "zero";
	int number;
	

	printf("Enter a two-digit number: ");
	scanf("%d", &number);

	if(number >= 11 && number <= 19) {
		printf("%s\n", teen[number % 10 - 1]);
	} else if(number >= 10) {
		if((number % 10) != 0) {
			printf("%s-%s\n", tens[number / 10 - 1], units[number % 10 - 1]);
		} else {
			printf("%s\n", tens[number / 10 - 1]);
		}
	} else if(number > 0) {
		printf("%s\n", units[number % 10 - 1]);
	} else {
		printf("%s\n", zero);
	}

	return 0;
}
