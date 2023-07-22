#include <stdio.h>

int main()
{
	int area_code, telephone_prefix, line_number;

	printf("Enter phone number[(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &area_code, &telephone_prefix, &line_number);

	printf("%3d.%3d.%4d\n", area_code, telephone_prefix, line_number);

	return 0;
}
