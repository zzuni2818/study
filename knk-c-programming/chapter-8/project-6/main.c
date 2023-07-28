#include <stdio.h>
#include <ctype.h>

#define N 50

int main()
{
	char ch, message[N] = {0};
	int i;

	printf("Enter message: ");
	i = 0;
	while((ch = getchar()) != '\n') {
		message[i] = ch;
		++i;
	}

	for(i = 0; i < N; i++) {
		if(isalpha(message[i])) {
			message[i] = toupper(message[i]);
		
			switch(message[i]) {
			case 'A':
				message[i] = '4';
				break;
			case 'B':
				message[i] = '8';
				break;
			case 'E':
				message[i] = '3';
				break;
			case 'I':
				message[i] = '1';
				break;
			case 'O':
				message[i] = '0';
				break;
			case 'S':
				message[i] = '5';
				break;
			}
		}
	}

	printf("In B1FF-speak: %s!!!!!!!!!!\n", message);

	return 0;
}
