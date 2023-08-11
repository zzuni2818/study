#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define WORD_SIZE 20

int read_line(char str[], int n);

int main()
{
	char *words[MAX_WORDS], *temp;
	int i, j, minimum, read_count, num_words = 0;

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
	for(i = 0; i < num_words - 1; i++) {
		minimum = i;
		for(j = i + 1; j < num_words; j++) {
			if(strcmp(words[j], words[minimum]) < 0) {
				minimum = j;
			}
		}

		temp = words[i];
		words[i] = words[minimum];
		words[minimum] = temp;
	}

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
