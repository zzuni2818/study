#include <stdio.h>
#include "queueADT.h"

int main()
{
	Queue q1, q2;
	int n;

	q1 = create(100);
	q2 = create(100);

	enqueue(q1, 1);
	enqueue(q1, 2);

	n = peek_front(q1);
	printf("Peeked at front %d from q1\n", n);
	n = peek_back(q1);
	printf("Peeked at back %d from q1\n", n);
	n = dequeue(q1);
	printf("Dequeued %d from q1\n", n);
	enqueue(q2, n);
	n = dequeue(q1);
	printf("Dequeued %d from q1\n", n);
	enqueue(q2, n);

	destroy(q1);

	while(!is_empty(q2)) {
		printf("Dequeued %d from q2\n", dequeue(q2));
	}
	
	if(is_empty(q2)) {
		printf("q2 is empty\n");
	} else {
		printf("q2 is not empty\n");
	}

	destroy(q2);

	return 0;
}
