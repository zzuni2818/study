#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

void make_empty();
bool is_empty();
bool is_full();
void push(int i);
int pop();
void stack_overflow();
void stack_underflow();

#endif
