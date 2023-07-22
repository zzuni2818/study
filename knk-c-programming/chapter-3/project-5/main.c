#include <stdio.h>

int main()
{
	int n11, n12, n13, n14, 
		n21, n22, n23, n24, 
		n31, n32, n33, n34, 
		n41, n42, n43, n44;

	printf("Enter the numbers from 1 to 16 in any order:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
		&n11, &n12, &n13, &n14, 
		&n21, &n22, &n23, &n24, 
		&n31, &n32, &n33, &n34, 
		&n41, &n42, &n43, &n44);

	printf("%2d	%2d	%2d	%2d\n", n11, n12, n13, n14);
	printf("%2d	%2d	%2d	%2d\n", n21, n22, n23, n24);
	printf("%2d	%2d	%2d	%2d\n", n31, n32, n33, n34);
	printf("%2d	%2d	%2d	%2d\n", n41, n42, n43, n44);

	printf("Row sum: %d %d %d %d\n", 
		(n11 + n12 + n13 + n14), 
		(n21 + n22 + n23 + n24), 
		(n31 + n32 + n33 + n34), 
		(n41 + n42 + n43 + n44));
	printf("Column sum: %d %d %d %d\n", 
		(n11 + n21 + n31 + n41), 
		(n12 + n22 + n32 + n42), 
		(n13 + n23 + n33 + n43), 
		(n14 + n24 + n34 + n44));
	printf("Diagonal sum: %d %d\n", 
		(n11 + n22 + n33 + n44), 
		(n14 + n23 + n32 + n41));
	
	return 0;
}
