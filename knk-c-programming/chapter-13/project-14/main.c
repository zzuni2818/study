#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_SIZE 20
#define LETTER_SIZE 26

bool are_anagrams(const char *word1, const char *word2);

int main()
{
	char first_word[WORD_SIZE], second_word[WORD_SIZE];

	printf("Enter first word: ");
	scanf("%s", first_word);
	printf("Enter second word: ");
	scanf("%s", second_word);

	printf("The words are %s.\n", are_anagrams(first_word, second_word) ? "anagrams" : "not anagrams");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int i, letters[LETTER_SIZE] = {0};

	for(; *word1; word1++) {
		if(isalpha(*word1)) {
			++letters[tolower(*word1) - 'a'];
		}
	}

	for(; *word2; word2++) {
		if(isalpha(*word2)) {
			--letters[tolower(*word2) - 'a'];
		}
	}

	for(i = 0; i < LETTER_SIZE; i++) {
		if(letters[i] > 0 || letters[i] < 0) {
			return false;
		}
	}
	return true;
}
