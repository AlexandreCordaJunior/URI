#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Edge;

struct Graph{
	int v;
	Edge e;

	Graph(int v){
		this->v = v;
		e.assign(v, vector<int>());
	}

	int dijkstra(int start, int end){
		int *distance = new int[v];
		for(int i = 0; i < v; i++){
			distance[i] = 4004;
		}

		distance[start] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push({0, start});

		while(!pq.empty()){
			pair<int, int> par = pq.top();
			pq.pop();
			int u, w;
			u = par.second;
			w = par.first;

			for(auto i = e[u].begin(); i != e[u].end(); i++){
				if(distance[*i] > w + 1){
					distance[*i] = w + 1;
					pq.push({distance[*i], *i});
				}
			}
		} 
		return distance[end];
	}
};

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	Graph g(v);

	map<string, int> mapa;
	int index = 0;
	getchar();
	while(e--){
		string u, v;
		string temp;
		getline(cin, temp);
		u = temp.substr(0, temp.find(' '));
		v = temp.substr(temp.find(' ') + 1, temp.size());
		//cout << u << v << endl;
		if(mapa.find(u) == mapa.end()){	
			mapa[u] = index++;
		}
		if(mapa.find(v) == mapa.end()){
			mapa[v] = index++;
		}

		g.e[mapa[u]].push_back(mapa[v]);
		g.e[mapa[v]].push_back(mapa[u]);
	}
	printf("%d\n", g.dijkstra(mapa["Entrada"], mapa["*"]) + g.dijkstra(mapa["*"], mapa["Saida"]));
}