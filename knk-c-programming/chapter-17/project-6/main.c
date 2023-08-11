#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define WORD_SIZE 20

int read_line(char str[], int n);

int compare(const void *p, const void *q);

int main()
{
	char *words[MAX_WORDS];
	int i, read_count, num_words = 0;

	//input word and store into words
	for(;;) {
		if(num_words == MAX_WORDS) {
			printf("--No space left--\n");
			break;
		}

		char *new_word = malloc(WORD_SIZE + 1);
		if(new_word == NULL) {
			printf("Failed to allocate new word\n\n");
			break;
		}

		printf("Enter word: ");
		read_count = read_line(new_word, WORD_SIZE);
		if(read_count == 0) {
			free(new_word);
			break;
		}

		words[num_words++] = new_word;
	}

	//sort words
	qsort(words, num_words, sizeof(char *), compare);

	//print sorted words
	printf("\nIn sorted order: ");
	for(i = 0; i < num_words; i++) {
		printf("%s ", words[i]);
	}
	printf("\n");


	//deallocate words
	for(i = 0; i < num_words; i++) {
		free(words[i]);
		num_words--;
	}

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while((ch = getchar()) != '\n') {
		if(i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';

	return i;
}

int compare(const void *p, const void *q)
{
	return strcmp(*(char **) p, *(char **) q);
}
