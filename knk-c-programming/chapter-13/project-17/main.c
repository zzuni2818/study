#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MESSAGE_SIZE 50

bool is_palindrome(const char *message);

int main()
{
	char message[MESSAGE_SIZE];

	printf("Enter a message: ");
	fgets(message, MESSAGE_SIZE, stdin);
	message[strlen(message) - 1] = '\0';

	printf("%s\n", is_palindrome(message) ? "Palindrome" : "Not a palindrome");

	return 0;
}

bool is_palindrome(const char *message)
{
	const char *start = message, *end = message + strlen(message) - 1;

	while(start < end) {
		if(!isalpha(*start)) {
			start++;
			continue;
		}
		if(!isalpha(*end)) {
			end--;
			continue;
		}
		if(toupper(*start) != toupper(*end)) {
			return false;
		}

		start++;
		end--;
	}

	return true;
}
