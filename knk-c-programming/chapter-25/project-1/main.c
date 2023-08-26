#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
	char *lc1, *lc2;

	lc1 = setlocale(LC_ALL, NULL);
	lc2 = setlocale(LC_ALL, "");

	/*
	printf("Native locale: %s\n", lc1);
	printf("\"C\" locale: %s\n", lc2);
	*/

	if(strcmp(lc1, lc2) == 0) {
		printf("Native locale is same as the \"C\" locale\n");
	} else {
		printf("Native locale is not same as the \"C\" locale\n");
	}

	return 0;
}
