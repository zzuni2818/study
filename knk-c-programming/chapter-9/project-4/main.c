#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LETTER_SIZE 26

void read_word(int counts[LETTER_SIZE]);
bool equal_array(int counts1[LETTER_SIZE], int counts2[LETTER_SIZE]);

int main()
{
	int first_word[LETTER_SIZE] = {0}, second_word[LETTER_SIZE] = {0};

	printf("Enter first word: ");
	read_word(first_word);
	printf("Enter second word: ");
	read_word(second_word);

	printf("The words are %s.\n", equal_array(first_word, second_word) ? "anagrams" : "not anagrams");

	return 0;
}

void read_word(int counts[LETTER_SIZE])
{
	char ch;

	while((ch = getchar()) != '\n') {
		ch = toupper(ch);
		++counts[ch - 'A'];
	}
}
bool equal_array(int counts1[LETTER_SIZE], int counts2[LETTER_SIZE])
{
	int i;

	for(i = 0; i < LETTER_SIZE; i++) {
		if(counts1[i] != counts2[i]) {
			return false;
		}
	}

	return true;
}
