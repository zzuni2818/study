#include <stdio.h>

int main()
{
	float operand, result;
	char operator;

	printf("Enter an expression: ");

	scanf("%f", &result);
	while((operator = getchar()) != '\n') {
		scanf("%f", &operand);

		switch(operator) {
		case '+':
			result += operand;
			break;
		case '-':
			result -= operand;
			break;
		case '*':
			result *= operand;
			break;
		case '/':
			result /= operand;
			break;
		}
	}

	printf("Value of expression: %f\n", result);

	return 0;
}
