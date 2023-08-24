#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;

	while((ch = fgetc(stdin)) != EOF) {
		if(iscntrl(ch) && ch != '\n') {
			fputc('?', stdout);
		} else {
			fputc(ch, stdout);
		}
	}

	return 0;
}
