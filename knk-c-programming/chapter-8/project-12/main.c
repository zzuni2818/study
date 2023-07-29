#include <stdio.h>
#include <ctype.h>

#define LETTER_SIZE 26

int main()
{
	/*
		a, b, c, d, e,
		f, g, h, i, j,
		k, l, m, n, o,
		p, q, r, s, t,
		u, v, w, x, y,
		z
	 */
	int scrabble_values[LETTER_SIZE] = {
		1, 3, 3, 2, 1, 
		4, 2, 4, 1, 8, 
		5, 1, 3, 1, 1, 
		3, 10, 1, 1, 1,
		1, 4, 4, 8, 4, 
		10
	};
	int value = 0;
	char ch;

	printf("Enter a word: ");
	while((ch = getchar()) != '\n') {
		ch = toupper(ch);
		value += scrabble_values[ch - 'A'];
	}
	printf("Scrablle value: %d\n", value);

	return 0;
}
