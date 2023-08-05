#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define EXPRESSION_SIZE 100
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

int evaluate_RPN_expression(const char *expression);

int main()
{
	char rpn_expression[EXPRESSION_SIZE];
	
	while(1) {
		printf("Enter an RPN expression: ");
		fgets(rpn_expression, EXPRESSION_SIZE, stdin);
		rpn_expression[strlen(rpn_expression) - 1] = '\0';

		printf("Value of expression: %d\n", evaluate_RPN_expression(rpn_expression));
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

int evaluate_RPN_expression(const char *expression)
{
	int result, operand1, operand2;

	while(*expression) {
		if(isspace(*expression)) {
			expression++;
			continue;
		}

		if(isdigit(*expression)) {
			push(*expression - '0');
		} else if(*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
			operand2 = pop();
			operand1 = pop();

			switch(*expression) {
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
		} else if(*expression == '=') {
			return pop();
		} else {
			exit(EXIT_FAILURE);
		}

		expression++;
	}
}
