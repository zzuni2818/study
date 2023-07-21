#include <stdio.h>

int main()
{
	int dollar_amount, bill_20, bill_10, bill_5, bill_1;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	bill_20 = dollar_amount / 20;
	dollar_amount %= 20;
	
	bill_10 = dollar_amount / 10;
	dollar_amount %= 10;

	bill_5 = dollar_amount / 5;
	bill_1 = dollar_amount % 5;

	printf("$20 bills: %d\n", bill_20);
	printf("$10 bills: %d\n", bill_10);
	printf(" $5 bills: %d\n", bill_5);
	printf(" $1 bills: %d\n", bill_1);

	return 0;
}
