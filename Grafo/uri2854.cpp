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
		for(int i = 0; i <= n ; i++){
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

int Graph::connection(){
	DisjointSet ds(v);
	for(auto i = e.begin(); i != e.end(); i++){
		int u = i->first;
		int v = i->second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);
		if(set_u != set_v){
			ds.merge(set_u, set_v);
		}
	}

	bool *family = new bool[v];

	for(int i = 0; i < v; i++){
		family[i] = false;
	}

	int cont = 0;

	for(int i = 0; i < v; i++){
		if(family[ds.find(i)] == false){
			cont++;
			family[ds.find(i)] = true;
		}
	}
	return cont;
}

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	
	Graph g(v);
	map<string, int> mapa;
	int index = 0;
	getchar();
	while(e--){
		string pessoa1, relacao, pessoa2, linha;
		getline(cin, linha);
		pessoa1 = linha.substr(0, linha.find(' '));
		relacao = linha.substr(linha.find(' ') + 1, linha.size());
		pessoa2 = relacao.substr(relacao.find(' ') + 1, relacao.size());
		
		if(mapa.find(pessoa1) == mapa.end()){
			mapa[pessoa1] = index++;
		}
		if(mapa.find(pessoa2) == mapa.end()){
			mapa[pessoa2] = index++;
		}
		g.addEdge(mapa[pessoa1], mapa[pessoa2]);
	}
	printf("%d\n", g.connection());
}