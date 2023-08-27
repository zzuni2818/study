#include <stdio.h>
#include <time.h>

#define TIME_SIZE 50

int main()
{
	time_t cur_time = time(NULL);
	struct tm *t_ptr;
	char stime[TIME_SIZE];

	t_ptr = localtime(&cur_time);
	strftime(stime, TIME_SIZE, "%A, %B %d, %Y   %I:%M", t_ptr);

	printf("%s%c\n", stime, t_ptr->tm_hour <= 11 ? 'a' : 'p');

	return 0;
}
