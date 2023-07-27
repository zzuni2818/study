#include <stdio.h>
#include <ctype.h>

int main()
{
	int hour, minute;
	char am_pm;

	printf("Enter a 12-hour time: ");
	scanf("%d:%d", &hour, &minute);
	scanf(" %c", &am_pm);

	am_pm = toupper(am_pm);

	if(am_pm == 'P') {
		hour += 12;
	}

	printf("Equivalent 24-hour time: %d:%d\n", hour, minute);

	return 0;
}
