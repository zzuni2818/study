#include <stdio.h>

int main()
{
	float amount_of_loan, interest_rate, monthly_payment, balance, monthly_interest_rate;
	int number_of_payment, i;

	printf("Enter amount of loan: ");
	scanf("%f", &amount_of_loan);
	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);
	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);
	printf("Enter number of payment: ");
	scanf("%d", &number_of_payment);

	monthly_interest_rate = interest_rate / 12;

	balance = amount_of_loan;
	
	for(i = 0; i < number_of_payment; i++) {
		balance = balance - monthly_payment + (balance * (monthly_interest_rate / 100));
		printf("Balance remaining after the payment: $%.2f\n", balance);
	}

	return 0;
}
