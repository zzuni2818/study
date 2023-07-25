#include <stdio.h>
#include <stdbool.h>

int main()
{
	int year, month, day,
		earliest_year, earliest_month, earliest_day;

	bool is_early, is_first = true;

	while(1) {
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &month, &day, &year);

		if(month == 0 && day == 0 && year == 0) {
			break;
		}

		if(month == 0 || day == 0 || year == 0) {
			continue;
		}

		if(is_first) {
			earliest_year = year;
			earliest_month = month;
			earliest_day = day;
			is_first = false;
			continue;
		}

		//compare logic 1
		if(year < earliest_year) {
			is_early = true;
		} else if(year == earliest_year) {
			if(month < earliest_month) {
				is_early = true;
			} else if(month == earliest_month) {
				if(day < earliest_day) {
					is_early = true;
				} else if(day == earliest_day) {
					is_early = false;
				} else {
					is_early = true;
				}
			} else {
				is_early = false;
			}
		} else {
			is_early = false;
		}

		//compare logic 2
		/*
		int compare_days_1, compare_days_2;
		compare_days_1 = (year * 365) + (month * 30) + day;
		compare_days_2 = (earliest_year * 365) + (earliest_month * 30) + earliest_day;
		if(compare_days_1 < compare_days_2) {
			is_early = true;
		} else {
			is_early = false;
		}
		*/

		if(is_early) {
			earliest_year = year;
			earliest_month = month;
			earliest_day = day;
		}
	}

	printf("%d/%d/%.2d is the earliest date\n", earliest_month, earliest_day, earliest_year);

	return 0;
}
