#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MESSAGE_SIZE 50

int main()
{
	char ch, message[MESSAGE_SIZE];
	char *p = message, *q = message;
	bool is_palindrome = true;

	printf("Enter a message: ");
	while((ch = getchar()) != '\n') {
		if(p >= (message + MESSAGE_SIZE)) {
			break;
		}
		*p++ = ch;
	}

	while(q < p) {
		if(!isalpha(*p)) {
			p--;
			continue;
		}
		if(!isalpha(*q)) {
			q++;
			continue;
		}
		if(toupper(*p) != toupper(*q)) {
			is_palindrome = false;
			break;
		}

		p--;
		q++;
	}

	printf("%s\n", is_palindrome ? "Palindrome" : "Not a palindrome");

	return 0;
}
