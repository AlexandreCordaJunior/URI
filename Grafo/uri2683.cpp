#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, ii>> Edges;

struct Graph{
	int v;
	Edges edges;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v, int w){
		edges.pb(mp(w, mp(u, v)));
	}

	int kruskal();
	int inverse();
};

struct DisjointSet{
	int n, *parent, *rank;

	DisjointSet(int n){
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];

		for(int i = 0;  i <= n; i++){
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

int Graph::kruskal(){
	int sum = 0;
	sort(edges.begin(), edges.end());
	DisjointSet ds(v);
	for(auto i = edges.begin(); i != edges.end(); i++){
		int u = i->second.first;
		int v = i->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			sum += i->first;
			ds.merge(set_v, set_u);
		}
	}
	return sum;
}

bool compare(pair<int, ii> e1, pair<int, ii> e2){
	return e1.first > e2.first;
}

int Graph::inverse(){
	int sum = 0;
	sort(edges.begin(), edges.end(), compare);
	DisjointSet ds(v);
	for(auto i = edges.begin(); i != edges.end(); i++){
		int u = i->second.first;
		int v = i->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			sum += i->first;
			ds.merge(set_v, set_u);
		}
	}
	return sum;
}

int main()
{
	int v;
	scanf("%d", &v);
	Graph g(v);
	while(v--){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g.addEdge(u, v, w);
	}
	printf("%d\n%d\n", g.inverse(), g.kruskal());
}