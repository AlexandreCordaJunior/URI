#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int>> vii;

struct Graph{
	int v;
	vii edges;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v){
		edges.push_back({u, v});
	}

	bool connection();
};
struct DisjointSet{
	int n, *parent, *rank;

	DisjointSet(int n){
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];
		for(int i = 0; i <= n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int u){
		if(u != parent[u]){
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}

	void merge(int x, int y){
		x = find(x);
		y = find(y);
		if(rank[x] > rank[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if(rank[x] == rank[y]){
			rank[y]++;
		}
	}
};

bool Graph::connection(){
	DisjointSet ds(v);
	for(auto i: edges){
		int x = i.first;
		int y = i.second;
		int set_x = ds.find(x);
		int set_y = ds.find(y);
		if(set_x != set_y){
			ds.merge(set_x, set_y);
		}
	}
	vector<bool> parents(v, false);
	for(int i = 0; i < v; i++){
		parents[ds.find(i)] = true;
	}
	int cont = 0;
	for(int i = 0; i < v; i++){
		if(parents[i] == true) cont++;
	}
	return cont == 1;
}

int teste = 0;

int main()
{
	int v, e;
	while(1){
		scanf("%d %d", &v, &e);
		if(v == 0 && e == 0) break;
		//if(teste != 0) printf("\n");
		Graph g(v);
		while(e--){
			int u, v;
			scanf("%d %d", &u, &v);
			g.addEdge(u - 1, v - 1);
		}
		printf("Teste %d\n%s\n\n", ++teste, g.connection() ? "normal" : "falha");
	}
}