#include <bits/stdc++.h>
#define N 50100
#define LG 16

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct Graph{
	int v;
	vi parent;
	vi level;
	int dp[N][LG];
	vector<int> distance;
	vector<vi> g;

	Graph(int v){
		this->v = v;
		parent.assign(v, 0);
		level.assign(v, 0);
		distance.assign(v, 0);
		g.assign(v, vi());
	}

	void addEdge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void dfs(int start){
		vector<bool> visited(v, false);
		visited[start] = true;
		level[start] = 0;
		stack<int> s;
		s.push(start);
		while(!s.empty()){
			int i = s.top(); s.pop();
			visited[i] = true;
			for(auto u : g[i]){
				if(!visited[u]){
					level[u] = level[i] + 1;
					parent[u] = i;
					distance[u] = distance[i] + 1;
					s.push(u);
				}
			}
		}
	}

	void precalculate(){
		for(int i = 0; i < v; i++){
			dp[i][0] = parent[i];
		}
		for(int h = 1; h < LG; h++){
			for(int i = 0; i < v; i++){
				if(dp[i][h - 1] != -1){
					dp[i][h] = dp[dp[i][h - 1]][h - 1];
				}
			}
		}
	}

	int lca(int x, int y){
		if(level[x] < level[y]){
			swap(x, y);
		}
		int log;
		for(log = 0; (1 << log) <= level[x]; log++);
		for(int i = log - 1; i >= 0; i--){
			if(level[x] - (1 << i) >= level[y]){
				x =  dp[x][i];
			}
		}
		if(x == y) return x;
		for(int i = log; i >= 0; i--){
			if(dp[x][i] != dp[y][i]){
				x = dp[x][i];
				y = dp[y][i];
			}
		}
		return parent[x];
	}

};

int main()
{
	int v;
	scanf("%d", &v);
	Graph g(v);
	stack<int> vet[v];
	map<int, int> mapa;
	for(int i = 0; i < v; i++){
		int x;
		scanf("%d", &x);
		vet[x].push(i);
		mapa[i] = x;
	}

	for(int i = 1; i < v; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g.addEdge(u - 1, v - 1);
	}
	g.dfs(0);
	g.precalculate();
	long long sum = 0;
	for(int i = 1; i < (v / 2) + 1; i++){
		int x = vet[i].top(); vet[i].pop();
		int y = vet[i].top(); vet[i].pop();
		int LCA = g.lca(x, y);
		sum += (long long) g.distance[x] + (long long) g.distance[y] - (long long) (2 * g.distance[LCA]);
	}
	printf("%lld\n", sum);
}