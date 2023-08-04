#include <stdio.h>
#include <string.h>

#define WORD_SIZE 20

void read_line(char str[], int n);

int main()
{
	char entered_word[WORD_SIZE + 1], smallest_word[WORD_SIZE + 1], largest_word[WORD_SIZE + 1];
	
	printf("Enter word: ");
	read_line(entered_word, WORD_SIZE);
	strcpy(smallest_word, entered_word);
	strcpy(largest_word, entered_word);

	while(strlen(entered_word) != 4) {
		printf("Enter word: ");
		read_line(entered_word, WORD_SIZE);
		if(strcmp(entered_word, smallest_word) < 0) {
			strcpy(smallest_word, entered_word);
		} else if(strcmp(entered_word, largest_word) > 0) {
			strcpy(largest_word, entered_word);
		}
	}

	printf("Smallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}

void read_line(char str[], int n)
{
	int ch, i = 0;

	while((ch = getchar()) != '\n') {
		if(i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';
}
