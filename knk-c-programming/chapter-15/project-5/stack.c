#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int contents[STACK_SIZE];
int top = -1;

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
void push(int i)
{
	if(is_full()) {
		stack_overflow();
	}

	contents[++top] = i;
}
int pop()
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
