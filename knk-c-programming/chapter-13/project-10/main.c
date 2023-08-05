#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_SIZE 30

void reverse_name(char *name);

int main()
{
	char name[NAME_SIZE + 1];
	
	printf("Enter a first and last name: ");
	fgets(name, NAME_SIZE, stdin);

	reverse_name(name);

	printf("%s\n", name);

	return 0;
}

void reverse_name(char *name)
{
	char *p = name;
	char first_initial, last_name[NAME_SIZE / 2];
	int i;

	while(isspace(*p)) {
		p++;
	}
	first_initial = *p;

	while(isalpha(*p)) {
		p++;
	}
	while(isspace(*p)) {
		p++;
	}

	i = 0;
	while(isalpha(*p)) {
		last_name[i++] = *p++;
	}
	last_name[i] = '\0';

	sprintf(name, "%s, %c.", last_name, first_initial);
}
