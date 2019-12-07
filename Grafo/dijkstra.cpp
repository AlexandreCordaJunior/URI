#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;

struct Graph{
	int v;
	vvii edges;

	Graph (int v){
		this->v = v;
		edges.assign(v, vector<ii>());
	}

	void addEdge(int u, int v, int w){
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}

	void dijkstra(int start){
		int *distance = new int[v];
		for(int i = 0; i < v; i++){
			distance[i] = INT_MAX >> 1;
		}
		distance[start] = 0;
		priority_queue<ii, vector<ii>, greater<ii>> pq;

		pq.push({0, start});
		while(!pq.empty()){
			ii u = pq.top();
			pq.pop();

			for(auto i : edges[u.second]){
				int v = i.first;
				int peso = i.second;
				if(distance[v] > distance[u.second] + peso){
					distance[v] = distance[u.second] + peso;
					pq.push({distance[v], v});
				}
			}
		}
		for(int i = 0; i < v; i++){
			printf("%d\n", distance[i]);
		}
	}
};

int main()
{
	int V = 9;
	Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7);

    g.dijkstra(0);
}
