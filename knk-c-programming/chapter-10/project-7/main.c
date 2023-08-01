#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define DIGIT_HEIGHT 4
#define DIGIT_WIDTH 4

void clear_digits_array();
void process_digit(int digit, int position);
void print_digits_array();

const int segments[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},	// 0
	{0, 1, 1, 0, 0, 0, 0},	// 1
	{1, 1, 0, 1, 1, 0, 1},	// 2
	{1, 1, 1, 1, 0, 0, 1},	// 3
	{0, 1, 1, 0, 0, 1, 1},	// 4
	{1, 0, 1, 1, 0, 1, 1},	// 5
	{1, 0, 1, 1, 1, 1, 1},	// 6
	{1, 1, 1, 0, 0, 0, 0},	// 7
	{1, 1, 1, 1, 1, 1, 1},	// 8
	{1, 1, 1, 1, 0, 1, 1},	// 9
};

char digits[DIGIT_HEIGHT][MAX_DIGITS * DIGIT_WIDTH];

int main()
{
	int digit, position = 0;
	char ch;
	
	clear_digits_array();

	printf("Enter a number: ");
	while((ch = getchar()) != '\n') {
		if(!isdigit(ch)) {
			continue;
		}

		digit = ch - '0';
		process_digit(digit, position);

		position++;
	}

	print_digits_array();

	return 0;
}

void clear_digits_array()
{
	for(int i = 0; i < DIGIT_HEIGHT; i++) {
		for(int j = 0; j < DIGIT_WIDTH * MAX_DIGITS; j++) {
			digits[i][j] = ' ';
		}
	}
}
void process_digit(int digit, int position)
{
	if(position < 0 || position > MAX_DIGITS - 1) {
		return;
	}

	for(int i = 0; i < 7; i++) {
		if(!segments[digit][i]) {
			continue;
		}
	
		int offset = position * DIGIT_WIDTH;
		switch (i) {
		case 0:
			digits[0][offset + 1] = '-';
			break;
		case 1:
			digits[1][offset + 2] = '|';
			break;
		case 2:
			digits[2][offset + 2] = '|';
			break;
		case 3:
			digits[3][offset + 1] = '-';
			break;
		case 4:
			digits[2][offset + 0] = '|';
			break;
		case 5:
			digits[1][offset + 0] = '|';
			break;
		case 6:
			digits[1][offset + 1] = '_';
			break;
		}
	}

}
void print_digits_array()
{
	for(int i = 0; i < DIGIT_HEIGHT; i++) {
		for(int j = 0; j < DIGIT_WIDTH * MAX_DIGITS; j++) {
			putchar(digits[i][j]);
		}
		putchar('\n');
	}
}
