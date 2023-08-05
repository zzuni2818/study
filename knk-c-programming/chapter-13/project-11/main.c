#include <stdio.h>
#include <ctype.h>

#define SENTENCE_SIZE 1024

double compute_average_word_length(const char *sentence);

int main()
{
	char sentence[SENTENCE_SIZE];

	printf("Enter a sentence: ");
	fgets(sentence, SENTENCE_SIZE, stdin);

	printf("Average word length: %.1f\n", compute_average_word_length(sentence));

	return 0;
}

double compute_average_word_length(const char *sentence)
{
	int length = 0, count = 0;

	while(*sentence != '\0') {
		if(isalpha(*sentence)) {
			++length;
		} else {
			if(*sentence == '.') {
				++length;
			} else if(*sentence == '\n') {
				sentence++;
				continue;
			}
			++count;
		}
		sentence++;
	}

	return (double) length / count;
}
