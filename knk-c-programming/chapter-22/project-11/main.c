#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	const char *str_months[] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	int year, month, day;

	if(argc < 2) {
		fprintf(stderr, "usage: date [month/day/year] or [month-day-year]\n");
		exit(EXIT_FAILURE);
	}

	if(sscanf(argv[1], "%d/%d/%d", &month, &day, &year) != 3 && sscanf(argv[1], "%d-%d-%d", &month, &day, &year) != 3) {
		fprintf(stderr, "usage: date [month/day/year] or [month-day-year]\n");
		exit(EXIT_FAILURE);
	}
	
	if(month < 1 || month > 12) {
		fprintf(stderr, "month must be 1 ~ 12\n");
		exit(EXIT_FAILURE);
	}
	if(day < 1 || day > 32) {
		fprintf(stderr, "day must be 1 ~ 32\n");
		exit(EXIT_FAILURE);
	}

	printf("%s %d, %d\n", str_months[month - 1], day, year);

	return 0;
}
