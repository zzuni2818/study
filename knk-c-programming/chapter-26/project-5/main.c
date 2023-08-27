#include <stdio.h>
#include <time.h>

struct tm get_date();

int main()
{
	struct tm t1, t2;

	t1 = get_date();
	t2 = get_date();

	printf("Difference in days: %d\n", (int) difftime(mktime(&t1), mktime(&t2)) / (24 * 60 * 60));

	return 0;
}

struct tm get_date()
{
	struct tm t;

	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;	
	t.tm_isdst = -1;

	printf("Enter month (1-12): ");
	scanf("%d", &t.tm_mon);
	t.tm_mon--;

	printf("Enter day (1-31): ");
	scanf("%d", &t.tm_mday);

	printf("Enter year: ");
	scanf("%d", &t.tm_year);
	t.tm_year -= 1900;

	return t;
}
