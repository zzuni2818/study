#include <stdio.h>
#include <stdlib.h>

void print_on_exit1();
void print_on_exit2();

int main()
{
	atexit(print_on_exit2);
	atexit(print_on_exit1);

	return 0;
}
void print_on_exit1()
{
	printf("That's all, ");
}
void print_on_exit2()
{
	printf("folks!\n");
}
