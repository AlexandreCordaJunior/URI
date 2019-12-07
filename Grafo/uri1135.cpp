#include <bits/stdc++.h>

#define N 100005
#define LG 18

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct Graph{
	int v;
	vi parent;
	vi level;
	int dp[N][LG];
	vector<long long> distance;
	vector<vii> g;

	Graph(int v){
		this->v = v;
		parent.assign(v, 0);
		level.assign(v, 0);
		distance.assign(v, 0);
		g.assign(v, vii());
	}

	void addEdge(int u, int v, int w){
		g[u].push_back({v, w});
		g[v].push_back({u, w});
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
				if(!visited[u.first]){
					level[u.first] = level[i] + 1;
					parent[u.first] = i;
					distance[u.first] = distance[i] + u.second;
					s.push(u.first);
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
	while(1){
		scanf("%d", &v);
		if(v == 0) break;

		Graph g(v);

		for(int i = 1; i < v; i++){
			int de, peso;
			scanf("%d %d", &de, &peso);
			g.addEdge(de, i, peso);
		}
		int depth = 0;
		g.dfs(0);
		g.precalculate();

		int query;
		scanf("%d", &query);
		while(query--){
			int de, para;
			scanf("%d %d", &de, &para);
			//printf("%d : ", g.lca(de, para));
			printf("%lld%c", g.distance[de] + g.distance[para] - (2 * g.distance[g.lca(de, para)]),
				query == 0 ? '\n' : ' ');
		}
		/*for(int i = 0; i < v; i++){
			printf("%d\n", g.level[i]);
		}*/
	}
}