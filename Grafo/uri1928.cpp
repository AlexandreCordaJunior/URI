#include <bits/stdc++.h>
#define LOG 16
#define db(x) cout << x << endl

using namespace std;

typedef long long ll;

int v;
vector<int> e[50001 << 1];
int parent[50001 << 1];
int level[50001 << 1];
int visited[50001 << 1];
int dp[50001 << 1][LOG];

void addEdge(int u, int v){
	e[u].push_back(v);
	e[v].push_back(u);
}

void dfs(int s){
	visited[s] = 1;
	level[s] = 0;
	parent[s] = s;
	stack<int> pilha;
	pilha.push(s);
	while(!pilha.empty()){
		int u = pilha.top(); pilha.pop();
		for(int i: e[u]){
			//db(u << " " << i);
			if(!visited[i]){
				visited[i] = 1;
				pilha.push(i);
				level[i] = level[u] + 1;
				parent[i] = u;
			}
		}
	}
}

void precalculate(){
	for(int i = 0; i < v; i++){
		dp[i][0] = parent[i];
	}
	for(int h = 1; h < LOG; h++){
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
			x = dp[x][i];
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

int main()
{
	scanf("%d", &v);
	memset(parent, 0, sizeof parent);
	memset(level, 0, sizeof level);
	memset(visited, 0, sizeof visited);
	for(int i = 0; i < v; i++){
		for(int j = 0; j < LOG; j++){
			dp[i][j] = -1;
		}
	}

	stack<int> s[v];
	for(int i = 0; i < v; i++){
		int num;
		scanf("%d", &num);
		s[num].push(i);
	}

	for(int i = 0; i < v - 1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		addEdge(u, v);
	}

	dfs(0);
	precalculate();
	ll distance = 0;

	for(int i = 1; i <= v / 2; i++){
		int x = s[i].top(); s[i].pop();
		int y = s[i].top(); s[i].pop();

		distance += (level[x] + level[y]) - (2 * level[lca(x, y)]);
	}
	printf("%lld\n", distance);
}