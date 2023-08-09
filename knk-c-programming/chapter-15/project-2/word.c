#include <stdio.h>
#include "word.h"

int read_char()
{
	int ch = getchar();

	if(ch == '\n' || ch == '\t') {
		return ' ';
	}
	return ch;
}

void read_word(char *word, int len)
{
	int ch, pos = 0;

	while((ch = getchar()) == ' ')
		;
	while(ch != ' ' && ch != EOF) {
		if(pos < len) {
			word[pos++] = ch;
		}
		ch = read_char();
	}
	if(pos >= len) {
		pos = len;
		word[pos++] = '*';
	}
	word[pos] = '\0';
}
