#include <stdio.h>
#include <ctype.h>

#define SENTENCE_SIZE 1024

int compute_vowel_count(const char *sentence);

int main()
{
	char sentence[SENTENCE_SIZE + 1];

	printf("Enter a sentence: ");
	fgets(sentence, SENTENCE_SIZE, stdin);

	printf("Your sentence contains %d vowels\n", compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int count = 0;

	while(*sentence) {
		switch(toupper(*sentence)) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			count++;
			break;
		}
		sentence++;
	}

	return count;
}
