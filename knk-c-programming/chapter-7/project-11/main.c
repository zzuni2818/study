#include <stdio.h>
#include <ctype.h>

int main()
{
	char first_name, last_name;

	printf("Enter a first and last name: ");

	scanf(" %c", &first_name);
	while(isalpha(getchar()));

	scanf(" %c", &last_name);
	putchar(last_name);
	while(isalpha(last_name = getchar())) {
		putchar(last_name);
	}
	printf(", %c. \n", first_name);

	return 0;
}
