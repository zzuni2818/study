#include <stdio.h>

int main()
{
	int number_of_days_in_month, start_day_of_week, i;

	printf("Enter number of days in month: ");
	scanf("%d", &number_of_days_in_month);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start_day_of_week);


	for(i = 1; i < start_day_of_week; i++) {
		printf("   ");
	}

	for(i = 1; i < number_of_days_in_month; i++) {
		printf("%3d", i);
		if((start_day_of_week + i - 1) % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
