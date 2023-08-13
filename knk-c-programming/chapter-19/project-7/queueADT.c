#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *front;
	struct node *back;
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
	q->front = NULL;
	q->back = NULL;

	return q;
}
void destroy(Queue q)
{
	while(!is_empty(q)) {
		dequeue(q);
	}
	free(q);
}
void enqueue(Queue q, Item i)
{
	struct node *new_node;

	if(is_full(q)) {
		terminate("Error in enqueue: queue is full.");
	}

	new_node = malloc(sizeof(struct node));
	if(new_node == NULL) {
		terminate("Error in enqueue: failed to allocate new node.");
	}

	new_node->data = i;
	new_node->next = NULL;
	if(is_empty(q)) {
		q->front = new_node;
		q->back = new_node;
	} else {
		q->back->next = new_node;
		q->back = new_node;
	}
}
Item dequeue(Queue q)
{
	struct node *old_node;
	Item i;

	if(is_empty(q)) {
		terminate("Error in dequeue: queue is empty.");
	}

	old_node = q->front;
	i = old_node->data;

	q->front = q->front->next;
	free(old_node);

	return i;
}
Item peek_front(Queue q)
{
	if(is_empty(q)) {
		terminate("Error in peek_front: queue is empty.");
	}
	
	return q->front->data;
}
Item peek_back(Queue q)
{
	if(is_empty(q)) {
		terminate("Error in peek_back: queue is empty.");
	}
	return q->back->data;
}
bool is_full(Queue q)
{
	return false;
}
bool is_empty(Queue q)
{
	return q->front == NULL;
}
