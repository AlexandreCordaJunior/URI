#include <bits/stdc++.h>
#define N 10000


using namespace std;

typedef vector<vector<int>> vvi;

struct Graph{
	int par[N], art[N], low[N], num[N], ch[N], cont;
	int v;
	vvi e;

	Graph(int v){
		this->v = v;
		for(int i = 0; i < v; i++){
			art[i] = low[i] = num[i] = ch[i] = 0;
			par[i] = -1;
		}

		e.assign(v, vector<int>());
	}

	void addEdge(int u, int v){
		e[u].push_back(v);
		e[v].push_back(u);
	}

	void articulation(int u){
		low[u] = num[u] = ++cont;
		for(int v : e[u]){
			if(!num[v]){
				par[v] = u;
				ch[u]++;
				articulation(v);
				if(low[v] >= num[u]) art[u] = 1;
				if(low[v] > num[u]) //printf("%d %d bridge\n", u, v);
				low[u] = min(low[u], low[v]);
			}
			else if(v != par[u]) low[u] = min(low[u], num[v]);
		}
	}

	void articulationCaller(){
		for(int i = 0; i < v; i++){
			if(!num[i]){
				//printf("%d\n", i);
				articulation(i);
				art[i] = ch[i] > 1;
			}
		}
		for(int i = 0; i < v; i++){
			if(art[i]){
				printf("%d\n", i);
			}
		}
	}
};

int main()
{
	cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.articulationCaller(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.articulationCaller(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.articulationCaller(); 
}