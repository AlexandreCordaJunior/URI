#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int>> Edges;

struct Graph{
	int v;
	Edges e;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v){
		e.push_back(make_pair(u, v));
	}

	int connection();
};

struct DisjointSet{
	int n, *rank, *parent;
	DisjointSet(int n){
		this->n = n;
		rank = new int[n + 1];
		parent = new int[n + 1];

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

int Graph::connection(){
	DisjointSet ds(v);
	for(auto i = e.begin(); i != e.end(); i++){
		int u = i->first;
		int v = i->second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			ds.merge(set_v, set_u);
		}
	}
	bool *families = new bool[v];
	int cont = 0;
	for(int i = 0; i < v; i++){
		families[i] = false;
	}

	for(int i = 0; i < v; i++){
		if(families[ds.find(i)] == false){
			families[ds.find(i)] = true;
			cont++;
		}
	}
	return cont;
}

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	Graph g(v);
	while(e--){
		int u, v;
		scanf("%d %d", &u, &v);
		g.addEdge(u - 1, v - 1);
	}
	printf("%d\n", g.connection());
}