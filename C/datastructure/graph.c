#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0
#define NV 8
#define MAX_QUEUE_SIZE 100 

typedef int element;
element queue[MAX_QUEUE_SIZE];

int front = MAX_QUEUE_SIZE - 1;
int rear = MAX_QUEUE_SIZE - 1;

int is_empty() {
     return front == rear;
}
int is_full() {
     return front == (rear+1) % MAX_QUEUE_SIZE;
}
void enqueue(element item)
{ /* add an item to the queue */
     assert( !is_full() );
     rear = (rear + 1) % MAX_QUEUE_SIZE;
     queue[rear] = item;
}
element dequeue()
{ /* remove front element from the queue */
     assert( !is_empty() );
     front = (front + 1) % MAX_QUEUE_SIZE;
     return queue[front];
}
int adj_mat[NV][NV] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 1, 1, 1, 0}};
int dfs_visited[NV] = {0};
int bfs_visited[NV] = {0};
void dfs_mat(int v)
{
	int w;
	dfs_visited[v] = TRUE;		 // 정점 v의 방문 표시
	printf("%d ", v);		 // 방문한 정점 출력
	for(w = 0; w < NV; w++) // 인접 정점 탐색
		if(adj_mat[v][w] && !dfs_visited[w]) //길이 연결되어 있고 방문 안했으면
			dfs_mat(w);
	// 정점 w에서 DFS 새로시작
}
void bfs_mat(int v)
{
	int w;
	bfs_visited[v] = TRUE; // 정점 v 방문 표시 
	printf("%d ", v); // 정점 출력 
	enqueue(v); // 시작 정점을 큐에 저장 
	while ( !is_empty() )
	{
		v = dequeue(); // 큐에 정점 추출 
		printf("%d\n", v);
		for(w = 0; w < NV; w++) //인접정점탐색
			if(adj_mat[v][w] && !bfs_visited[w]) //길이 연결되어 있고 방문 안했으면
			{ 
				bfs_visited[w] = TRUE; 
				printf("%d ", w); 
				enqueue(w);
			}
	}
}
int main()
{
	dfs_mat(0);
	bfs_mat(0);

	return 0;
}