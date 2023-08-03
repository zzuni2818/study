#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MESSAGE_SIZE 50

int main()
{
	char ch, message[MESSAGE_SIZE];
	int i, j;
	bool is_palindrome = true;

	printf("Enter a message: ");
	for(i = 0; i < MESSAGE_SIZE; i++) {
		ch = getchar();
		if(ch == '\n') {
			break;
		}
		message[i] = ch;
	}

	i--;
	j = 0;
	while(j < i) {
		if(!isalpha(message[i])) {
			i--;
			continue;
		}
		if(!isalpha(message[j])) {
			j++;
			continue;
		}
		if(toupper(message[i]) != toupper(message[j])) {
			is_palindrome = false;
			break;
		}

		i--;
		j++;
	}

	printf("%s\n", is_palindrome ? "Palindrome" : "Not a palindrome");

	return 0;
}
