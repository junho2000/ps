#include <stdio.h>
#include <assert.h>
#define MAX_STACK_SIZE 100000

int stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}
void push(int item)
{
    assert(!is_full());
    stack[++top] = item;
}
int pop()
{
    assert(!is_empty());
    return stack[top--];
}
