#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
	int ch;
	bool is_first_char = true;

	while((ch = fgetc(stdin)) != EOF) {
		if(isalpha(ch)) {
			if(is_first_char) {
				fputc(toupper(ch), stdout);
				is_first_char = false;
				continue;
			}
		} else if(isspace(ch)) {
			is_first_char = true;
		}
		fputc(ch, stdout);
	}

	return 0;
}
