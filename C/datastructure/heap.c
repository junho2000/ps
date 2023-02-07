#include<stdio.h>
#define HEAP_SIZE 100002
//heap is a complete binary tree, so we can use array to make heap.
//O(logn)
int min_heap[HEAP_SIZE];
int max_heap[HEAP_SIZE];
int min_heap_size = 0; //비어 있는 상태
int max_heap_size = 0;

void insert_max_heap(int item)
{
	int i = ++max_heap_size;
	int j = 1;

	while ((i != 1) && (item > max_heap[i / 2])) // i == 1이면 rootnode
	{
		max_heap[i] = max_heap[i / 2];
		i /= 2;
	}
	max_heap[i] = item;
}

void insert_min_heap(int item)     
{
	int i = ++min_heap_size;
	int j = 1;

	while ((i != 1) && (item < min_heap[i / 2]))
	{
		min_heap[i] = min_heap[i / 2];
		i /= 2;
	}
	min_heap[i] = item;
}
void delete_max_heap()
{
	int parent, child;
	int item, temp;

	item = max_heap[1];

	temp = max_heap[(max_heap_size)--];

	parent = 1; 
	child = 2; 

	while (child <= max_heap_size)
	{
		if ((child < max_heap_size) && (max_heap[child]) < max_heap[child + 1])
			child++;

		if (temp >= max_heap[child])
			break;

		max_heap[parent] = max_heap[child]; 
		parent = child; 
		child *= 2; 
	}
	max_heap[parent] = temp;
}
void delete_min_heap()
{
	int parent, child;
	int item, temp;

	item = min_heap[1];

	temp = min_heap[(min_heap_size)--];

	parent = 1;
	child = 2;

	while (child <= min_heap_size)
	{
		if ((child < min_heap_size) && (min_heap[child]) > min_heap[child + 1])
			child++;

		if (temp <= min_heap[child])
			break;

		min_heap[parent] = min_heap[child];
		parent = child;
		child *= 2;
	}
	min_heap[parent] = temp;
}