#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<double, ii>> Edges;

struct ponto{
	int x, y;
	ponto(int x, int y){
		this->x = x;
		this->y = y;
	}
};

typedef struct ponto Ponto;

struct Graph{
	int v;
	Edges edges;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u,int v,double w){
		edges.push_back(make_pair(w, make_pair(u, v)));
	}

	double kruskal();
};

struct DisjointSet{
	int n, *rank, *parent;

	DisjointSet(int n){
		this->n = n;
		rank = new int[n + 1];
		parent = new int[n + 1];

		for(int i = 0; i <= n; i++){
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

double Graph::kruskal(){
	double sum = 0;
	sort(edges.begin(), edges.end());
	DisjointSet ds(v);

	for(auto i = edges.begin(); i != edges.end(); i++){
		int u = i->second.first;
		int v = i->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			sum += i->first;
			ds.merge(set_u, set_v);
		}
	}
	return sum;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--){
		int pessoas;
		scanf("%d", &pessoas);
		Ponto *pontos = (Ponto *) malloc(sizeof(Ponto) * pessoas);
		Graph g(pessoas);
		for(int i = 0; i < pessoas; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			pontos[i] = Ponto(x, y);
		}

		for(int i = 0; i < pessoas; i++){
			for(int j = i + 1; j < pessoas; j++){
				double distance = sqrt(pow(pontos[i].x - pontos[j].x, 2) + 
					pow(pontos[i].y - pontos[j].y, 2));
				g.addEdge(i, j, distance);
			}
		}
		printf("%.2lf\n", g.kruskal()/100.0);
	}
}