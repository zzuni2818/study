#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main()
{
	int dollar_amount, bill_20, bill_10, bill_5, bill_1;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	pay_amount(dollar_amount, &bill_20, &bill_10, &bill_5, &bill_1);

	printf("$20 bills: %d\n", bill_20);
	printf("$10 bills: %d\n", bill_10);
	printf(" $5 bills: %d\n", bill_5);
	printf(" $1 bills: %d\n", bill_1);

	return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	*twenties = dollars / 20;
	dollars %= 20;
	
	*tens = dollars / 10;
	dollars %= 10;

	*fives = dollars / 5;
	*ones = dollars % 5;
}
