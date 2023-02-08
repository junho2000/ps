#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_STACK_SIZE 100000
#define MAX_QUEUE_SIZE 100000

//qeueu implement

int queue[MAX_QUEUE_SIZE];
int front = MAX_QUEUE_SIZE - 1;
int rear = MAX_QUEUE_SIZE - 1;

int is_empty(){
    return front == rear;
}
int is_full(){
    return front == (rear + 1) % MAX_QUEUE_SIZE;
}
void enqueue(int v){
    if(!is_full()){
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = v;
    }
}
int dequeue(){
    if(!is_empty()){
        front = (front + 1) % MAX_QUEUE_SIZE;
        return queue[front];
    }
    else
        return -1;
}
int adj_mat[1001][1001] = {0,};
int bfs_visited[1001] = {0,};
int dfs_visited[1001] = {0,};

void dfs(int v, int N){
    printf("%d ", v);
    dfs_visited[v] = 1;
    for(int i = 1; i <= N; i++){
        if(adj_mat[v][i] == 1 && dfs_visited[i] == 0)
            dfs(i, N);
    }
}
void bfs(int v, int N){
    int temp;
    enqueue(v);
    bfs_visited[v] = 1;
    while(!is_empty()){
        temp = dequeue();
        printf("%d ", temp);
        for(int i = 1; i <= N; i++){
            if(adj_mat[temp][i] == 1 && bfs_visited[i] == 0){
                enqueue(i);
                bfs_visited[i] = 1;
            }
        }
    }
    
}

int main(){
    int N, M, V;
    int n1, n2;
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &n1, &n2);
        adj_mat[n1][n2] = 1;
        adj_mat[n2][n1] = 1;
    }
    dfs(V,N);
    printf("\n");
    bfs(V,N);
    return 0;
}
