#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int ch, check, count;
	
	while((ch = fgetc(stdin)) != EOF) {
		if(strchr(".,?!", ch)) {
			check = fgetc(stdin);
			if(isspace(check)) {
				count++;
			} else {
				ungetc(check, stdin);
			}
		}
	}

	printf("the number of sentences: %d\n", count);

	return 0;
}
