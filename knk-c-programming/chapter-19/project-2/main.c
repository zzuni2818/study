#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "stackADT.h"

int main()
{
	Stack s = create(100);
	char ch;
	int result, operand1, operand2;
	bool is_running = true;
	while(is_running) {
		printf("Enter an RPN expression: ");

		while(1) {
			scanf(" %c", &ch);

			if(isdigit(ch)) {
				push(s, ch - '0');
			} else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
				operand2 = pop(s);
				operand1 = pop(s);

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

				push(s, result);
			} else if(ch == '=') {
				printf("Value of expression: %d\n", pop(s));
				break;
			} else {
				is_running = false;
				break;
			}
		}
	}
	destroy(s);

	return 0;
}
