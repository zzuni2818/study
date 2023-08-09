#include <stdio.h>
#include <ctype.h>
#include "stack.h"

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
				operand2 = pop();
				operand1 = pop();

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
