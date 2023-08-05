#include <stdio.h>
#include <ctype.h>

#define MESSAGE_SIZE 80

void encrypt(char *message, int shift);

int main()
{
	char ch, message[MESSAGE_SIZE];
	int shift_amount, i = 0;

	printf("Enter message to be encrypted: ");
	while((ch = getchar()) != '\n') {
		message[i++] = ch;
	}
	message[i] = '\0';

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift_amount);

	encrypt(message, shift_amount);

	printf("Encrypted message: %s\n", message);

	return 0;
}

void encrypt(char *message, int shift)
{
	while(*message) {
		if(isalpha(*message)) {
			if(islower(*message)) {
				*message = ((*message - 'a') + shift) % 26 + 'a';
			} else {
				*message = ((*message - 'A') + shift) % 26 + 'A';
			}
		}
		message++;
	}
}
