#include <stdio.h>
#include "stackADT.h"

int main()
{
	Stack s1, s2;
	void *p;

	s1 = create();
	s2 = create();

	push(s1, "I am ");
	push(s1, "a boy");

	p = pop(s1);
	printf("Popped %s from s1\n", (char *)p);
	push(s2, p);
	p = pop(s1);
	printf("Popped %s from s1\n", (char *)p);
	push(s2, p);

	destroy(s1);

	while(!is_empty(s2)) {
		printf("Popped %s from s2\n", (char *)pop(s2));
	}
	
	push(s2, "!!!!");
	make_empty(s2);
	if(is_empty(s2)) {
		printf("s2 is empty\n");
	} else {
		printf("s2 is not empty\n");
	}

	destroy(s2);

	return 0;
}
