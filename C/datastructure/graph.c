#include<stdio.h>

int adj_mat[101][101];
int visit[101];
int count;
int vertex_size;

void dfs_mat(int v) {
	count++;
	visit[v] = 1;
	for (int i = 1; i <= vertex_size; i++) {
		if (adj_mat[v][i] == 1 && visit[i] == 0)
			dfs_mat(i);
	}
}

int main(void) {
	int node_size;
	int a, b;

	
	scanf("%d", &vertex_size);
	getchar();
	scanf("%d", &node_size);
	getchar();

	for (int i = 0; i < node_size; i++) {
		scanf("%d", &a);
		getchar();
		scanf("%d", &b);
		getchar();

		adj_mat[a][b] = 1;
		adj_mat[b][a] = 1;
	}

	dfs_mat(1);
	printf("%d\n", count - 1);

	return 0;
}