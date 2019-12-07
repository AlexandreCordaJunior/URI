#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001
vector<int> tree[MAXN];
int path[3][MAXN];

void dfs(int current, int previous, int pathNumber, int ptr, int node, bool &flag){
	for(int v = 0; v < tree[current].size(); v++){
		if(tree[current][v] != previous and !flag){
			path[pathNumber][ptr] = tree[current][v];

			if(tree[current][v] == node){
				flag = true;
				path[pathNumber][ptr + 1] = -1;
				return;
			}
			dfs(tree[current][v], current, pathNumber, ptr + 1, node, flag);
		}
	}
}

int LCA(int u, int v){
	if(u == v) return u;
	path[1][0] = path[2][0] = 1;
	bool flag = false;
	dfs(1, 0, 1, 1, u, flag);

	flag = false;
	dfs(1, 0, 2, 1, v, flag);

	int i = 0;
	while(path[1][i] == path[2][i]){
		i++;
	}
	return path[1][i - 1];
}

void addEdge(int u, int v){
	tree[u].push_back(v);
	tree[v].push_back(u);
}

int main()
{
	int n = 8; // Number of nodes 
    addEdge(1,2); 
    addEdge(1,3); 
    addEdge(2,4); 
    addEdge(2,5); 
    addEdge(2,6); 
    addEdge(3,7); 
    addEdge(3,8); 
  
    cout << "LCA(4, 7) = " << LCA(4,7) << endl; 
    cout << "LCA(4, 6) = " << LCA(4,6) << endl; 
}