#include <stdio.h>
#include <time.h>

#define TIME_SIZE 50

int main()
{
	time_t cur_time = time(NULL);
	struct tm *t_ptr;
	char stime[TIME_SIZE];

	t_ptr = localtime(&cur_time);
	strftime(stime, TIME_SIZE, "%x  %I:%M:%S %p", t_ptr);

	printf("%s\n", stime);

	return 0;
}
