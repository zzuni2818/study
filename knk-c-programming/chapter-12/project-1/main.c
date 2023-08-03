#include <stdio.h>

#define MESSAGE_SIZE 50

int main()
{
	char ch, message[MESSAGE_SIZE];
	int i;

	printf("Enter a message: ");

	for(i = 0; i < MESSAGE_SIZE; i++) {
		ch = getchar();
		if(ch == '\n') {
			break;
		}
		message[i] = ch;
	}

	printf("Reversal is: ");
	for(--i; i >= 0; i--) {
		putchar(message[i]);
	}
	putchar('\n');

	return 0;
}
