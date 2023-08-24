#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
	int ch;
	bool is_line = false;

	while((ch = fgetc(stdin)) != EOF) {
		if(is_line) {
			fputc(ch, stdout);
		} else if(!isspace(ch)) {
			is_line = true;
			fputc(ch, stdout);
		}

		if(ch == '\n') {
			is_line = false;
		}
	}

	return 0;
}
