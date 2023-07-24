#include <stdio.h>
#include <stdbool.h>

int main()
{
	int first_year, first_month, first_day,
		second_year, second_month, second_day;

	bool is_first_early, is_same = false;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &first_month, &first_day, &first_year);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &second_month, &second_day, &second_year);

	if(first_year < second_year) {
		is_first_early = true;
	} else if(first_year == second_year) {
		if(first_month < second_month) {
			is_first_early = true;
		} else if(first_month == second_month) {
			if(first_day < first_day) {
				is_first_early = true;
			} else if(first_day == second_day) {
				is_same = true;
			} else {
				is_first_early = false;
			}
		} else {
			is_first_early = false;
		}
	} else {
		is_first_early = false;
	}

	if(is_same) {
		printf("same date\n");
		return 0;
	}

	if(is_first_early) {
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", 
			first_month, first_day, first_year,
			second_month, second_day, second_year);
	} else {
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", 
			second_month, second_day, second_year,
			first_month, first_day, first_year);
	}

	return 0;
}
