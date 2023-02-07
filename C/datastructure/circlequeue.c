#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5001


typedef int element;

typedef struct circlequeueType {

    element queue[MAX_QUEUE_SIZE];

    int front, rear;

}circlequeueType;

int isEmpty(struct circlequeueType* q) {
	if (q->rear == q->front) return 1; //front == rear이면 공백상태
	return 0;
}
int isFull(struct circlequeueType* q) {
	int tmp = (q->rear + 1) % MAX_QUEUE_SIZE; //front 바로 뒤가 rear인 상태
	if (tmp == q->front) {
		return 1;
	}
	return 0;

}
void enqueue(struct circlequeueType* q, int data) {
	if (isFull(q)) {
		return;
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = data;
	}
}
int dequeue(struct circlequeueType* q) {
	if (isEmpty(q)) {
		return -1;
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}
