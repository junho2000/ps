#include <stdio.h>
#include <stdbool.h>
#define NV 6
#define INF 10000000

int mat[NV][NV] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool v[6] = {false}; //visitde Node
int d[6] = {0}; // each Node's distance

int getSmallIndex(){
    int min = INF;
    int index = 0;
    for(int i = 0; i < NV; i++){
        if(d[i] < min && !v[i]){
            min = d[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int start){
    for(int i = 0; i < NV; i++){
        d[i] = mat[start][i];
    } // 일단 starting node에 쫙 넣어준다
    v[start] = true;
    for(int i = 0; i < NV - 2; i++){ // 자시자신과 맨마지막으로 남은 노드(가중치가 가장 큰 노드)는 갱신할 필요없음
        int current = getSmallIndex();
        v[current] = true;
        for(int j = 0; j < 6; j++){
            if(!v[j]){
                if(d[current] + mat[current][j] < d[j]){ // 비용이 가장작은 current와 연결되어있는 노드들인 mat 가중치가 기록되어있는 거리보다 작으면 갱신
                    d[j] = d[current] + mat[current][j];
                }
            }
        }
    }
}

int main(){
    dijkstra(0);
    for(int i = 0; i < NV; i++){
        printf("%d ", d[i]);
    }
    return 0;
}