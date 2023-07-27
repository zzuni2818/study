#include <stdio.h>
#include <limits.h>

int main()
{
	//short type
	/*
	short i;
	
	for(i = 1; i < (SHRT_MAX / i); i++) {
		printf("%10hd %10hd\n", i, i * i);
	}
	printf("%hd\n", i);
	*/
	
	//int type
	int i;
	
	for(i = 1; i < (INT_MAX / i); i++) {
		printf("%10d %10d\n", i, i * i);
	}
	printf("%d\n", i);

	//long type
	/*
	long i;
	
	for(i = 1; i < (LONG_MAX / i); i++) {
		printf("%10ld %10ld\n", i, i * i);
	}
	printf("%ld\n", i);
	*/

	return 0;
}
