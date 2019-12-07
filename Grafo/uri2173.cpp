#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, ii>> Edge;

struct Graph{
	int v;
	Edge e;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v, int w){
		e.push_back({w, {u, v}});
	}

	int kruskal();
	int maximum();
};

struct DisjointSet{
	int n;
	int *rank, *parent;

	DisjointSet(int n){
		this->n = n;
		rank = new int[n + 1];
		parent = new int[n + 1];
		for(int i = 0; i<= n; i++){
			rank[i] = 0;
			parent[i] = i;
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

int Graph::kruskal(){
	int sum = 0;
	DisjointSet ds(v);
	sort(e.begin(), e.end());
	for(auto edge : e){
		int u = edge.second.first;
		int v = edge.second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			sum += edge.first;
			ds.merge(set_u, set_v);
		}
	}
	return sum;
}

int Graph::maximum(){
	int sum = 0;
	DisjointSet ds(v);
	sort(e.begin(), e.end(), greater<pair<int, pair<int, int>>>());
	for(auto edge : e){
		int u = edge.second.first;
		int v = edge.second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			sum += edge.first;
			ds.merge(set_u, set_v);
		}
	}
	return sum;
}

int main()
{
	while(1){
		int v, e;
		scanf("%d %d", &v, &e);
		if(v == 0 && e == 0) break;
		Graph g(v);
		for(int i = 0; i < e; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g.addEdge(u, v, w);
		}
		printf("%d\n", g.maximum() - g.kruskal());
	}
}