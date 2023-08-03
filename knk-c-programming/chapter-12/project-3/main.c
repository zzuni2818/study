#include <stdio.h>

#define MESSAGE_SIZE 50

int main()
{
	char ch, message[MESSAGE_SIZE];
	char *p;

	printf("Enter a message: ");

	for(p = message; p < (message + MESSAGE_SIZE); p++) {
		ch = getchar();
		if(ch == '\n') {
			break;
		}
		*p = ch;
	}

	printf("Reversal is: ");
	for(--p; p >= message; p--) {
		putchar(*p);
	}
	putchar('\n');

	return 0;
}
