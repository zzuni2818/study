#include <stdio.h>
#include <ctype.h>

#define SENTENCE_SIZE 50

int main()
{
	char ch, end_of_line, sentence[SENTENCE_SIZE];
	int i = 0, start_index, end_index;
	
	printf("Enter a sentence: ");
	while((ch = getchar()) != '\n') {
		sentence[i] = ch;
		++i;

		if(ch == '?' || ch == '.' || ch == '!') {
			end_of_line = ch;
			break;
		}
	}
	sentence[i] = '\0';

	printf("Reversal of sentence: ");

	end_index = i;
	while(!isalpha(sentence[end_index])) {
		--end_index;
	}
	start_index = end_index;

	while(start_index >= -1) {
		if(start_index == -1 || sentence[start_index] == ' ') {
			for(i = start_index + 1; i <= end_index; i++) {
				putchar(sentence[i]);
			}

			if(start_index == -1) {
				putchar(end_of_line);
			} else {
				putchar(' ');
			}

			end_index = start_index - 1;
		}
		--start_index;
	}
	putchar('\n');

	return 0;
}
