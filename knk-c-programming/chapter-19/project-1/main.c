#include <stdio.h>
#include "stackADT.h"

int main()
{
	Stack s = create(100);
	char ch, poped;
	bool is_matched = true;

	printf("Enter parentheses and/or braces: ");
	while((ch = getchar()) != '\n') {
		if(ch == '{' || ch == '(') {
			push(s, ch);
		} else if(ch == '}') {
			poped = pop(s);
			if(poped != '{') {
				printf("not matched1, %c %c\n", poped, ch);
				is_matched = false;
				break;
			}
		} else if(ch == ')') {
			poped = pop(s);
			if(poped != '(') {
				printf("not matched1, %c %c\n", poped, ch);
				is_matched = false;
				break;
			}
		}
	}

	if(!is_matched || !is_empty(s)) {
		printf("Parentheses/braces are not nested properly\n");
	} else {
		printf("Parentheses/braces are nested properly\n");
	}

	destroy(s);

	return 0;
}
