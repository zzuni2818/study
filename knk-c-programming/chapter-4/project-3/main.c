#include <stdio.h>

int main()
{
	int hundreds, tens, units;

	printf("Enter a three digit number: ");
	scanf("%1d%1d%1d", &hundreds, &tens, &units);

	printf("The reversal is: %d%d%d\n", units, tens, hundreds);

	return 0;
}
