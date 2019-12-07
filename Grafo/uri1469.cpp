#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

void swap(int *u, int *v){
	int temp = *u;
	*u = *v;
	*v = temp;
}

int bfs(Graph g, int source, int qtd, int* idade){
	int *visited = new int[qtd];
	for(int i = 0; i < qtd; i++){
		visited[i] = 0;
	}

	queue<int> q;
	q.push(source);
	int smallest = INT_MAX;
	bool himself = true;
	while(!q.empty()){
		int u = q.front();
		//printf("%d : %d\n", idade[u], u);
		q.pop();
		if(idade[u] < smallest){
			smallest = idade[u];
		}
		visited[u] = 1;
		for(int i = 0; i < g[u].size(); i++){
			if(visited[g[u][i]] == 0){
				himself = false;
				q.push(g[u][i]);
			}
		}
	}
	if(himself){
		return -1;
	}
	else{
		return smallest;
	}
}

int main()
{
	int v, e, q;
	while(scanf("%d %d %d", &v, &e, &q) != EOF){
		Graph g;
		g.assign(v, vector<int>());
		int *emp = new int[v];
		for(int i = 0; i < v; i++){
			int idade;
			scanf("%d", &idade);
			emp[i] = idade;
		}
		while(e--){
			int u, v;
			scanf("%d %d", &u, &v);
			g[v - 1].push_back(u - 1);
		}
		while(q--){
			getchar();
			char op;
			scanf("%c", &op);
			if(op == 'P'){
				int u;
				scanf("%d", &u);
				int info = bfs(g, u - 1, v, emp);
				if(info == -1){
					printf("*\n");
				}
				else{
					printf("%d\n", info);
				}
			}
			else{
				int u, v;
				scanf("%d %d", &u, &v);
				swap(&emp[u - 1], &emp[v - 1]);
			}
		}
	}
}
