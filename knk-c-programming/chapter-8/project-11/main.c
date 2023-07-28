#include <stdio.h>

#define PHONE_NUMBER_LENGTH 15

int main()
{
	char phone_numbers[PHONE_NUMBER_LENGTH];
	char numeric_form[PHONE_NUMBER_LENGTH];

	char ch;
	int i = 0;

	printf("Enter phone number: ");
	while((ch = getchar()) != '\n') {
		phone_numbers[i] = ch;

		switch(ch) {
		case 'A':
		case 'B':
		case 'C':
			numeric_form[i] = '2';
			break;
		case 'D':
		case 'E':
		case 'F':
			numeric_form[i] = '3';
			break;
		case 'G':
		case 'H':
		case 'I':
			numeric_form[i] = '4';
			break;
		case 'J':
		case 'K':
		case 'L':
			numeric_form[i] = '5';
			break;
		case 'M':
		case 'N':
		case 'O':
			numeric_form[i] = '6';
			break;
		case 'P':
		case 'R':
		case 'S':
			numeric_form[i] = '7';
			break;
		case 'T':
		case 'U':
		case 'V':
			numeric_form[i] = '8';
			break;
		case 'W':
		case 'X':
		case 'Y':
			numeric_form[i] = '9';
			break;
		default:
			numeric_form[i] = ch;
		}
		++i;
	}

	printf("%s\n", numeric_form);

	return 0;
}
