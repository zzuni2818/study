#include <stdio.h>
#include <string.h>

#define MESSAGE_SIZE 50

void reverse(char *message);

int main()
{
	char message[MESSAGE_SIZE];

	printf("Enter a message: ");
	fgets(message, MESSAGE_SIZE, stdin);
	message[strlen(message) - 1] = '\0';

	reverse(message);

	printf("Reversal is: ");
	printf("%s\n", message);

	return 0;
}

void reverse(char *message)
{
	char temp, *start = message, *end = message + strlen(message) - 1;

	for(; start < end; start++, end--) {
		temp = *start;
		*start = *end;
		*end = temp;
	}
}
