#include <stdio.h>
#include <stdbool.h>

int main()
{
	int hour_24, hour_12, minute;
	bool is_pm;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour_24, &minute);


	if(hour_24 < 12) {
		is_pm = false;
		hour_12 = hour_24;
	} else if(hour_24 == 12) {
		is_pm = true;
		hour_12 = hour_24;
	} else {
		is_pm = true;
		hour_12 = hour_24 - 12;
	}

	printf("Equivalent 12-hour time: %d:%.2d %s\n", hour_12, minute, (is_pm ? "PM" : "AM"));

	return 0;
}
