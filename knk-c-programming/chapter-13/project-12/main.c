#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 30
#define CHAR_SIZE 20

int main()
{
	char words[WORD_SIZE][CHAR_SIZE + 1];
	char word[CHAR_SIZE + 1];

	char ch, end_of_line;
	int word_index = 0, char_index = 0;
	
	printf("Enter a sentence: ");
	while((ch = getchar()) != '\n') {
		word[char_index] = ch;

		if(isspace(ch)) {
			word[char_index] = '\0';
			strcpy(words[word_index++], word);
		} else if(ch == '?' || ch == '.' || ch == '!') {
			end_of_line = ch;

			word[char_index] = '\0';
			strcpy(words[word_index], word);
			break;
		}
	
		if(word[char_index] == '\0') {
			char_index = 0;
		} else {
			char_index++;
		}
	}

	printf("Reversal of sentence: ");
	for(; word_index >= 0; word_index--) {
		printf("%s", words[word_index]);
		if(word_index == 0) {
			printf("%c\n", end_of_line);
		} else {
			printf(" ");
		}
	}

	return 0;
}
