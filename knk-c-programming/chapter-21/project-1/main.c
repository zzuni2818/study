#include <stdio.h>
#include <stddef.h>

struct s {
	char a;
	int b[2];
	float c;
};

int main()
{
	struct s s1;

	printf("size of struct s: %zu\n", sizeof(struct s));
	
	printf("\n");
	printf("offset of a: %zu\n", offsetof(struct s, a));
	printf("offset of b: %zu\n", offsetof(struct s, b));
	//printf("offset of b[0]: %zu\n", offsetof(struct s, b[0]));
	//printf("offset of b[1]: %zu\n", offsetof(struct s, b[1]));
	printf("offset of c: %zu\n", offsetof(struct s, c));

	printf("\n");
	printf("hole between a and b: %zu\n", offsetof(struct s, b) - offsetof(struct s, a) - sizeof(s1.a));
	printf("hole between b and c: %zu\n", offsetof(struct s, c) - offsetof(struct s, b) - sizeof(s1.b));

	return 0;
}
