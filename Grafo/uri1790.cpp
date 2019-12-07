#include <bits/stdc++.h>

#define N 61

using namespace std;

typedef vector<vector<int>> vvi;

struct Graph{
	int v;
	vvi e;
	int counter;
	int low[N], num[N], parent[N];
	int bridge;

	Graph(int v){
		this->v = v;
		e.assign(v, vector<int>());
		counter = bridge = 0;
		for(int i = 0; i < v; i++){
			low[i] = num[i] = parent[i] = -1;
		}
	}

	void addEdge(int u, int v){
		e[u].push_back(v);
		e[v].push_back(u);
	}

	void articulationCaller(int u){
		low[u] = num[u] = counter++;
		for(int v: e[u]){
			if(num[v] == -1){
				parent[v] = u;
				articulationCaller(v);
				if(low[v] > num[u]) bridge++;
				low[u] = min(low[u], low[v]);
			}
			else if(v != parent[u]){
				low[u] = min(low[u], num[v]);
			}
		}
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
			g.addEdge(u - 1, v - 1);
		}
		g.articulationCaller(0);
		printf("%d\n", g.bridge);
	}
}