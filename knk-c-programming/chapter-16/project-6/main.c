#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

int get_total_day(struct date d);
int compare_dates(struct date d1, struct date d2);

int main()
{
	struct date first_date, second_date;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &first_date.month, &first_date.day, &first_date.year);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &second_date.month, &second_date.day, &second_date.year);

	int result = compare_dates(first_date, second_date);
	if(result < 0) {
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", 
			first_date.month, first_date.day, first_date.year,
			second_date.month, second_date.day, second_date.year);
	} else if(result == 0) {
		printf("same date\n");
	} else {
		printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", 
			second_date.month, second_date.day, second_date.year,
			first_date.month, first_date.day, first_date.year);
	}

	return 0;
}

int get_total_day(struct date d)
{
	return (d.year * 365) + (d.month * 30) + d.day;
}
int compare_dates(struct date d1, struct date d2)
{
	int day1 = get_total_day(d1), 
		day2 = get_total_day(d2);

	return (day1 == day2) ? 0 :	(day1 < day2) ? -1 : 1;
}
