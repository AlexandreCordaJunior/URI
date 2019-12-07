#include <bits/stdc++.h>

using namespace std;

struct Graph{
	int v;
	int matrix[1000][1000];

	Graph(int v){
		this->v  = v;
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				matrix[i][j] = 0;
			}
		}
	}

	void addEdge(int u, int v, int w){
		matrix[u][v] = w;
	}

	bool bfs(int start, int finish, int *parent){
		bool *visited = new bool[v];
		for(int i = 0; i < v; i++){
			visited[i] = false;
		}
		visited[start] = true;
		queue<int> q;
		q.push(start);

		while(!q.empty()){
			int u = q.front(); q.pop();
			visited[u] = true;
			for(int i = 0; i < v; i++){
				if(matrix[u][i] != 0 && visited[i] == false){
					parent[i] = u;
					q.push(i);
				}
			}
		}
		return visited[finish];
	}

	int fordFulkerson(int start, int finish){
		int *parent = new int[v];
		for(int i = 0; i < v; i++){
			parent[i] = -1;
		}

		int maxFlow = 0;

		while(bfs(start, finish, parent)){
			int pathFlow = INT_MAX >> 2;

			for(int i = finish; parent[i] != -1; i = parent[i]){
				int u = parent[i];
				pathFlow = min(pathFlow, matrix[u][i]);
			}

			for(int i = finish; parent[i] != -1; i = parent[i]){
				int u = parent[i];
				matrix[u][i] -= pathFlow;
				matrix[i][u] += pathFlow;
			}
			maxFlow += pathFlow;
		}
		return maxFlow;
	}

};

int main(){
	int casos;
	scanf("%d", &casos);
	for(int i = 0; i < casos; i++){
		int qtd1;
		scanf("%d", &qtd1);
		int *vet1 = new int[qtd1];
		for(int i = 0; i < qtd1; i++){
			scanf("%d", &vet1[i]);
		}

		int qtd2;
		scanf("%d", &qtd2);
		int *vet2 = new int[qtd2];
		for(int i = 0; i < qtd2; i++){
			scanf("%d", &vet2[i]);
		}

		Graph g(qtd1 + qtd2 + 2);

		for(int j = 0; j < qtd1; j++){
			for(int k = 0; k < qtd2; k++){
				if(vet1[j] == 0 and vet2[k] == 0) g.addEdge(j + 1, 1 + qtd1 + k, INT_MAX >> 2);
				else if(vet1[j] != 0){
					if(vet2[k] % vet1[j] == 0){
						g.addEdge(j + 1, 1 + qtd1 + k, INT_MAX >> 2);
					}	
				}
			}
		}

		for(int j = 0; j < qtd1; j++){
			g.addEdge(0, j + 1, 1);
		}

		for(int j = 0; j < qtd2; j++){
			g.addEdge(1 + qtd1 + j, qtd1 + qtd2 + 1, 1);
		}

		printf("Case %d: %d\n", i + 1, g.fordFulkerson(0, qtd1 + qtd2 + 1));
	}
}