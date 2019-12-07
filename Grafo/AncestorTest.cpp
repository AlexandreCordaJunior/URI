#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> LG; // Acho que é a matrix
int v; //Quantidade de vertices
vector<int> depth; //vetor de profundidade, obvio
vector<ll> distancia; //vetor de distancia, obvio
int parent[1000005][18]; //Vetor de pais, menos obvio, TODO

void dfs(int start){
	depth.assign(v, INT_MAX);
	distancia.assign(v, LLONG_MAX);

	depth[start] = distancia[start] = 0;

	parent[start][0] = 0;
	stack<int> s;
	s.push(start);
	while(!s.empty()){
		int u = s.top(); s.pop();
		/*Posso estar errando nesse laço*/
		for(auto i : LG[u]){
			int v = i.first;
			int w = i.second;
			if(depth[v] == INT_MAX){
				depth[v] = depth[u] + 1;
				distancia[v] = distancia[u] + (ll) w;
				parent[v][0] = u;	
				s.push(v);
			}
		}
	}
}

void preComputeSparceTable(){
	for(int i = 1; i < 18; i++){
		for(int u = 0; u < v; u++){
			if(parent[u][i - 1] != -1){
				parent[u][i] = parent[parent[u][i - 1]][i - 1];
			}
		}
	}
}

int LCA(int u, int v){
	if(depth[u] > depth[v]){
		swap(u, v);
	}
	int diff = depth[v] - depth[u];
	for(int i = 0; i < 18; i++){
		if((diff >> i) & 1){
			v = parent[v][i];
		}
	}
	if(u == v){
		return u;
	}
	for(int i = 17; i >= 0; i--){
		if(parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int main()
{
	while(1){
		scanf("%d", &v);
		if(v == 0) break;
		LG.assign(v, vii());
		for(int i = 1; i < v; i++){
			int v, w;
			scanf("%d %d", &v, &w);
			if(i < v){
				LG[i].push_back({v, w});
			}
			else{
				LG[v].push_back({i, w});
			}
		}
		//Até aqui um grafo tradicional

		dfs(0);
		preComputeSparceTable();

		int queries;
		scanf("%d", &queries);
		while(queries--){
			int u, v;
			scanf("%d %d", &u, &v);
			int lca = LCA(u, v);
			ll ans = (distancia[u] - distancia[lca]) + (distancia[v] - distancia[lca]);
			printf("%lld%c", ans, queries > 0 ? ' ' : '\n');
		}
	}

}