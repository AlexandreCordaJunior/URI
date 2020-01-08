#include <bits/stdc++.h>

#define db(x) cout << x << endl

using namespace std;

typedef vector<pair<double, int>> vd;


struct Graph{
	int v;
	vector<vd> e;

	Graph(int v){
		this->v = v;
		e.assign(v, vd());
	}

	void addEdge(int u, int v, double w){
		e[u].push_back({w, v});
		e[v].push_back({w, u});
	}

	double dijkstra(int start, int finish){
		vector<double> d(v, -1);
		d[start] = 1.0;
		priority_queue<pair<double, int>, vd, greater<pair<double, int>>> pq;
		pq.push({1.0, start});

		while(!pq.empty()){
			pair<double, int> u = pq.top(); pq.pop();

			for(auto i: e[u.second]){
				if(d[i.second] < d[u.second] * i.first){
					d[i.second] = d[u.second] * i.first;
					pq.push({d[i.second], i.second});
				}
			}
		}
		return d[finish];
	}
};

int main()
{
	int n, m;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d", &m);

		Graph g(n);
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g.addEdge(u - 1, v - 1, w / 100.0);
		}

		printf("%.6lf percent\n", g.dijkstra(0, n - 1) * 100);
	}
}