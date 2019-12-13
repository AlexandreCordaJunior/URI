#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int , ii> iii;
typedef vector<iii> edges;
typedef long long ll;

struct Graph{
	int v;
	edges e;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v, int w){
		e.push_back({w, {u, v}});
		e.push_back({w, {v, u}});
	}

	void kruskal();
};

struct DisjointSet{
	int n;
	int *parent;
	int *rank;

	DisjointSet(int n){
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];
		for(int i = 0; i < n; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int u){
		if(parent[u] != u){
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

void Graph::kruskal(){
	sort(e.begin(), e.end());
	DisjointSet ds(v);
	ll sum = 0;

	for(auto i : e){
		ll w;
		int u, v;
		w = i.first;
		u = i.second.first;
		v = i.second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			sum += w;
			ds.merge(set_u, set_v);
		}
	}

	int families = 0;
	vector<bool> f(v, false);
	for(int i = 0; i <v; i++){
		if(f[ds.find(i)] == false){
			families++;
			f[ds.find(i)] = true;
		}
	}
	printf("%d %lld\n", families, sum);
}

int main()
{
	int v;
	scanf("%d", &v);
	Graph g(v);
	for(int i = 0; i < v - 1; i++){
		int qtd;
		scanf("%d", &qtd);
		for(int j = 0; j < qtd; j++){
			int u, w;
			scanf("%d %d", &u, &w);
			g.addEdge(i, u - 1, w);
		}
	}
	g.kruskal();
}