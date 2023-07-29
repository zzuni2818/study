#include <stdio.h>
#include <ctype.h>

#define MESSAGE_SIZE 80

int main()
{
	char ch, message[MESSAGE_SIZE];
	int shift_amount, i = 0;

	printf("Enter message to be encrypted: ");
	while((ch = getchar()) != '\n') {
		message[i] = ch;
		++i;
	}
	message[i] = '\0';

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift_amount);

	printf("Encrypted message: ");

	i = 0;
	while(message[i] != '\0') {
		if(isalpha(message[i])) {
			if(islower(message[i])) {
				ch = ((message[i] - 'a') + shift_amount) % 26 + 'a';
			} else {
				ch = ((message[i] - 'A') + shift_amount) % 26 + 'A';
			}
		} else {
			ch = message[i];
		}
		putchar(ch);
		++i;
	}
	putchar('\n');

	return 0;
}
