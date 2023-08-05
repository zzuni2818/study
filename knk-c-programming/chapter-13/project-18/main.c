#include <stdio.h>


int main()
{
	const char *month_names[] = {"January", "February", "March", 
							"April", "May", "June", "July", 
							"August", "September", "October", 
							"November", "December"};
	int year, month, day;
	
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("You entered the date %s %d, %d\n", month_names[month - 1], day, year);

	return 0;
}
