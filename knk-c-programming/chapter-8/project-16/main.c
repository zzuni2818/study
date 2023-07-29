#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_SIZE 20
#define LETTER_SIZE 26

int main()
{
	char ch, first_word[WORD_SIZE], second_word[WORD_SIZE];
	int i, letters[LETTER_SIZE] = {0};
	bool is_anagram;

	printf("Enter first word: ");
	i = 0;
	while((ch = getchar()) != '\n') {
		first_word[i] = ch;
		if(isalpha(ch)) {
			++letters[tolower(ch) - 'a'];
		}
		++i;
	}
	first_word[i] = '\0';

	printf("Enter second word: ");
	i = 0;
	while((ch = getchar()) != '\n') {
		second_word[i] = ch;
		if(isalpha(ch)) {
			--letters[tolower(ch) - 'a'];
		}
		++i;
	}
	second_word[i] = '\0';

	is_anagram = true;
	for(i = 0; i < LETTER_SIZE; i++) {
		if(letters[i] > 0 || letters[i] < 0) {
			is_anagram = false;
			break;
		}
	}

	
	printf("The words are %s.\n", is_anagram ? "anagrams" : "not anagrams");
	return 0;
}
