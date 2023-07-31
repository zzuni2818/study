#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = -1;

void make_empty();
bool is_empty();
bool is_full();
void push(char ch);
char pop();
void stack_overflow();
void stack_underflow();

int main()
{
	char ch, poped;
	bool is_matched = true;

	printf("Enter parentheses and/or braces: ");
	while((ch = getchar()) != '\n') {
		if(ch == '{' || ch == '(') {
			push(ch);
		} else if(ch == '}') {
			poped = pop();
			if(poped != '{') {
				printf("not matched1, %c %c\n", poped, ch);
				is_matched = false;
				break;
			}
		} else if(ch == ')') {
			poped = pop();
			if(poped != '(') {
				printf("not matched1, %c %c\n", poped, ch);
				is_matched = false;
				break;
			}
		}
	}

	if(!is_matched || !is_empty()) {
		printf("Parentheses/braces are not nested properly\n");
	} else {
		printf("Parentheses/braces are nested properly\n");
	}

	return 0;
}

void make_empty()
{
	top = -1;
}
bool is_empty()
{
	return top == -1;
}
bool is_full()
{
	return top == STACK_SIZE;
}
void push(char ch)
{
	if(is_full()) {
		stack_overflow();
	}

	contents[++top] = ch;
}
char pop()
{
	if(is_empty()) {
		stack_underflow();
	}

	return contents[top--];
}
void stack_overflow()
{
	printf("stack overflow\n");

	exit(EXIT_FAILURE);
}
void stack_underflow()
{
	printf("stack underflow\n");

	exit(EXIT_FAILURE);
}
