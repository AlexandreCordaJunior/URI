#include <bits/stdc++.h>

#define db(x) cout << x << endl

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct Graph{
	int v;
	vector<iii> e;

	Graph(int v){
		this->v = v;
	}

	void addEdge(int u, int v, int w){
		e.push_back({w, {u, v}});
		e.push_back({w, {v, u}});
	}

	vector<int> kruskal(int comp);
};

struct DisjointSet{
	int n;
	int *rank;
	int *parent;

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

	void merge(int  x, int y){
		x = find(x);
		y = find(y);
		if(rank[x] > rank[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if(rank[x] == rank[y]) rank[y]++;	
	}
};

vector<int> Graph::kruskal(int comp){
	DisjointSet ds(v);
	sort(e.begin(), e.end());
	for(auto i : e){

		int qtdComp = 0;
		vector<bool> visited(v, false);
		for(int i = 0; i < v; i++){
			if(visited[ds.find(i)] == false){
				visited[ds.find(i)] = true;
				qtdComp++;
			}
		}
		if(qtdComp == comp) break;



		int u = i.second.first;
		int v = i.second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v){
			ds.merge(set_u, set_v);
		}
	}
	vector<int> vi(v, 0);
	for(int i = 0; i < v; i++){
		vi[i] = ds.find(i);
	}
	return vi;
}

int main()
{
	int pessoas, grupos;
	while(scanf("%d %d", &pessoas, &grupos) != EOF){
		int *vet = new int[pessoas];

		vet[0] = 0;
		for(int i = 1; i < pessoas; i++){
			scanf("%d", &vet[i]);
		}

		Graph g(pessoas);
		for(int i = 1; i < pessoas; i++){
			g.addEdge(i - 1, i, abs(vet[i] - vet[i - 1]));
		}
		vector<int> res = g.kruskal(grupos);
		map<int, pair<int, int>> mapa;
		vector<bool> vetPessoas(pessoas, false);

		vector<int> todos;

		for(int i = 0; i < pessoas; i++){
			if(vetPessoas[res[i]] == false){
				//db(res[i] << "ola");
				vetPessoas[res[i]] = true;
				mapa[res[i]] = {vet[i], -1};
				todos.push_back(res[i]);
			}
		}
		for(int i = 0; i < pessoas; i++){
			vetPessoas[i] = false;
		}
		for(int i = pessoas - 1; i >= 0; i--){
			if(vetPessoas[res[i]] == false){
				//db(res[i] << "oi");
				vetPessoas[res[i]] = true;
				mapa[res[i]] = {mapa[res[i]].first, vet[i]};
				//db(vet[i] << "lala");
			}
		}
		int sum = 0;
		for(auto i: todos){
			sum += (mapa[i].first - mapa[i].second);
			//db(i << " " << mapa[i].first << " " << mapa[i].second);
		}
		printf("%d\n", abs(sum));
	}
}