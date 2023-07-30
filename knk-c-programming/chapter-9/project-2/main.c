#include <stdio.h>

float calculate_tax(int income);

int main()
{
	int income;

	printf("Enter the amount of taxable income: ");
	scanf("%d", &income);

	printf("tax: $%.2f\n", calculate_tax(income));

	return 0;
}

float calculate_tax(int income)
{
	float tax;

	if(income < 750) {
		tax = income * 0.01f;
	} else if(income < 2250) {
		tax = 7.50f + ((income - 750.0f) * 0.02f);
	} else if(income < 3750) {
		tax = 37.50f + ((income - 2250.0f) * 0.03f);
	} else if(income < 5250) {
		tax = 82.50f + ((income - 3750.0f) * 0.04f);
	} else if(income < 7000) {
		tax = 142.50f + ((income - 5250.0f) * 0.05f);
	} else {
		tax = 230.00f + ((income - 7000.0f) * 0.06f);
	}
	
	return tax;
}
