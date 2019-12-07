#include <bits/stdc++.h>

/*Doesnot work*/

using namespace std;

#define MAX 100100
vector<int> graph[MAX];

int dist[MAX], match[MAX];
int n;

void addEdge(int u, int v){
	graph[u].push_back(v);
}

bool bfs(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!match[i]){
			dist[i] = 0;
			q.push(i);
		}
		else{
			dist[i] = 1 << 30;
		}
	}
	dist[0] = 1 << 30;
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u){
			for(auto v : graph[u]){
				if(dist[match[v]] == 1 << 30){
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return dist[0] != 1 << 30;
}

bool dfs(int u){
	if(u){
		for(auto v : graph[u]){
			if(dist[match[v]] == dist[u] + 1){
				if(dfs(match[v])){
					match[v] = u;
					match[u] = v;
					return 1;
				}
			}
		}
		dist[u] = 1 << 30;
		return 0;
	}
	return 1;
}

int hopcroftKarp(){
	int ans = 0;
	memset(match, 0, sizeof match);
	while(bfs()){
		for(int i = 1; i <= n; i++){
			if(!match[i] && dfs(i)){
				ans++;
			}
		}
	}
	return ans;
}

int main()
{
	n = 4; 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(2, 1); 
    addEdge(3, 2); 
    addEdge(4, 2); 
    addEdge(4, 4); 
  
    cout << "Size of maximum matching is " << hopcroftKarp(); 
  
    return 0; 

}