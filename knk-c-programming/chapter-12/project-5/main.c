#include <stdio.h>
#include <ctype.h>

#define SENTENCE_SIZE 50

int main()
{
	char ch, end_of_line, sentence[SENTENCE_SIZE];
	char *p = sentence, *end, *iter;
	
	printf("Enter a sentence: ");
	while((ch = getchar()) != '\n') {
		*p++ = ch;

		if(ch == '?' || ch == '.' || ch == '!') {
			end_of_line = ch;
			break;
		}
	}
	*p-- = '\0';

	printf("Reversal of sentence: ");

	while(!isalpha(*p)) {
		p--;
	}
	end = p;

	while(p >= sentence) {
		if(p == sentence) {
			for(iter = p; iter <= end; iter++) {
				putchar(*iter);
			}
			putchar(end_of_line);
			break;
		} else if(*p == ' ') {
			for(iter = p, ++iter; iter <= end; iter++) {
				putchar(*iter);
			}
			putchar(' ');
			end = p - 1;
		}
		p--;
	}
	putchar('\n');

	return 0;
}
