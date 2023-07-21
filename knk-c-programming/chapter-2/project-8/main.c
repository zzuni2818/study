#include <stdio.h>

int main()
{
	float amount_of_loan, interest_rate, monthly_payment, balance, monthly_interest_rate;

	printf("Enter amount of loan: ");
	scanf("%f", &amount_of_loan);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	monthly_interest_rate = interest_rate / 12;

	balance = amount_of_loan;
	
	balance = balance - monthly_payment + (balance * (monthly_interest_rate / 100));
	printf("Balance remaining after first payment: $%.2f\n", balance);

	balance = balance - monthly_payment + (balance * (monthly_interest_rate / 100));
	printf("Balance remaining after second payment: $%.2f\n", balance);

	balance = balance - monthly_payment + (balance * (monthly_interest_rate / 100));
	printf("Balance remaining after third payment: $%.2f\n", balance);

	return 0;
}
