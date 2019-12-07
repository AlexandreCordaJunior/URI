#include <bits/stdc++.h>

using namespace std;

struct Graph{
	int v;
	int **matrix;

	Graph(int v){
		this->v = v;
		matrix = (int **) malloc(sizeof(int *) * v);
		for(int i = 0; i < v; i++){
			matrix[i] = (int *) malloc(sizeof(int) * v);
		}
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				matrix[i][j] = 0;
			}
		}
	}

	int bfs(int start, int end){
		int *distance = new int[v];
		bool *visited = new bool[v];
		queue<int> q;
		q.push(start);
		distance[start] = 0;
		visited[start] = true;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0; i < v; i++){
				if(matrix[u][i] == 1 && visited[i] == false){
					visited[u] = true;
					q.push(i);
					distance[i] = distance[u] + 1;
				}
			}
		}
		return distance[end];
	}
	
};

int main()
{
	int v, e;
	while(scanf("%d %d", &v, &e) != EOF){
		Graph g(v);
		while(e--){
			int u, v;
			scanf("%d %d", &u, &v);
			g.matrix[u - 1][v - 1] = g.matrix[v - 1][u - 1] = 1;
		}
		int c, r, e;
		scanf("%d %d %d", &c, &r, &e);
		for(int i = 0; i < v; i++){
			g.matrix[i][e - 1] = g.matrix[e - 1][i] = 0;
		}
		/*for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				printf("%d ", g.matrix[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n", g.bfs(c - 1, r - 1));
	}
}