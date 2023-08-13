#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
	Item contents[QUEUE_SIZE];
	int front;
	int back;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create()
{
	Queue q = malloc(sizeof(struct queue_type));
	if(q == NULL) {
		terminate("Error in create: queue could not be created.");
	}
	q->front = 0;
	q->back = 0;

	return q;
}
void destroy(Queue q)
{
	free(q);
}
void enqueue(Queue q, Item i)
{
	if(is_full(q)) {
		terminate("Error in enqueue: queue is full.");
	}
	q->contents[q->back++] = i;
}
Item dequeue(Queue q)
{
	if(is_empty(q)) {
		terminate("Error in dequeue: queue is empty.");
	}

	return q->contents[q->front++];
}
Item peek_front(Queue q)
{
	if(is_empty(q)) {
		terminate("Error in peek_front: queue is empty.");
	}
	
	return q->contents[q->front];
}
Item peek_back(Queue q)
{
	if(is_empty(q)) {
		terminate("Error in peek_back: queue is empty.");
	}
	return q->contents[q->back - 1];
}
bool is_full(Queue q)
{
	return q->back == QUEUE_SIZE;
}
bool is_empty(Queue q)
{
	return q->front == q->back;
}
