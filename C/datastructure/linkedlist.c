#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//단 방향 링크드리스크
typedef struct listNode {
    int data;
    struct listNode* next;
}listNode;

listNode* first = NULL;
listNode* last = NULL;

int count = 0;

int empty()
{
    if (first == NULL)
        return 1;
    else
        return 0;
}

void push(int x)
{
    listNode* pNew = (listNode*)malloc(sizeof(listNode));
    pNew->data = x;
    pNew->next = NULL;
    count++;
    if (last)
    {
        last->next = pNew;
        last = pNew;
    }
    else
        first = last = pNew;
}

int pop()
{
    listNode* tmp = first;
    int temp;
    if (first)
    {
        temp = first->data;
        first = first->next;
        if (!first)
            last = NULL;
        free(tmp);
        count--;
        return temp;
    }
    else if (empty())
        return -1;
}

int front()
{
    if (empty())
        return -1;
    return first->data;
}

int back()
{
    if (empty())
        return -1;
    return last->data;
}

int size()
{
    return count;
}
