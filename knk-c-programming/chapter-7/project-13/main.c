#include <stdio.h>
#include <ctype.h>

int main()
{
	int length = 0, count = 0;
	char ch;

	while((ch = getchar()) != '\n') {
		if(isalpha(ch)) {
			++length;
		} else {
			if(ch == '.') {
				++length;
			}
			++count;
		}
	}

	printf("Average word length: %.1f\n", (float) length / count);

	return 0;
}
