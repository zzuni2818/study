#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = -1;

void make_empty();
bool is_empty();
bool is_full();
void push(int i);
int pop();
void stack_overflow();
void stack_underflow();

int main()
{
	char ch;
	int result, operand1, operand2;
	bool is_running = true;
	while(is_running) {
		printf("Enter an RPN expression: ");

		while(1) {
			scanf(" %c", &ch);

			if(isdigit(ch)) {
				push(ch - '0');
			} else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
				operand1 = pop();
				operand2 = pop();

				switch(ch) {
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					result = operand1 / operand2;
					break;
				}

				push(result);
			} else if(ch == '=') {
				printf("Value of expression: %d\n", pop());
				break;
			} else {
				is_running = false;
				break;
			}
		}
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
