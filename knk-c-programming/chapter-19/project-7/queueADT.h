#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create();
void destroy(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek_front(Queue q);
Item peek_back(Queue q);
bool is_full(Queue q);
bool is_empty(Queue q);

#endif 
