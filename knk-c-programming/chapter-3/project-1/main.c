#include <stdio.h>

int main()
{
	int year, month, day;

	printf("Enter a date (mm/dd/YYYY) : ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("You entered the date %d%.2d%.2d\n", year, month, day);
	return 0;
}
