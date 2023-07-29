#include <stdio.h>
#include <ctype.h>

#define LAST_NAME_SIZE 20

int main()
{
	char ch, first_name, last_name[LAST_NAME_SIZE];
	int i;

	printf("Enter a first and last name: ");

	scanf(" %c", &first_name);
	while(isalpha(getchar()));

	scanf(" %c", &ch);
	last_name[0] = ch;

	for(i = 1; i < LAST_NAME_SIZE; i++) {
		ch = getchar();
		if(!isalpha(ch)) {
			last_name[i] = '\0';
			break;
		}
		last_name[i] = ch;
	}

	printf("%s, %c. \n", last_name, first_name);

	return 0;
}
