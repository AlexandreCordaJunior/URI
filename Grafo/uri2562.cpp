#include <bits/stdc++.h>

using namespace std;

struct Graph
{
	int v;
	vector<pair<int, int>> e;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v){
		e.push_back({u, v});
	}

	int same(int x);
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

int Graph::same(int x){
	DisjointSet ds(v);
	for(auto i : e){
		int u = i.first;
		int v = i.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		if(set_u != set_v){
			ds.merge(set_u, set_v);
		}
	}
	int set_x = ds.find(x);
	int cont = 0;
	for(int i = 0; i < v; i++){
		if(ds.find(i) == set_x){
			cont++;
		}
	}
	return cont;
}

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
		int x;
		scanf("%d", &x);
		printf("%d\n", g.same(x - 1));
	}
}