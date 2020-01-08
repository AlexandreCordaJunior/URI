#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef pair<string, int> stringInt;
typedef pair<int, stringInt> par;

struct Graph{
	int v;
	vector<vector<par>> e;

	Graph(int v){
		this->v = v;
		e.assign(v, vector<par>());
	}

	void addEdge(int u, int v, string s){
		e[u].push_back({s.size(), {s, v}});
		e[v].push_back({s.size(), {s, u}});
	}

	int dijkstra(int start, int finish){
		vector<int> distancia(v, INT_MAX >> 1);
		distancia[start] = 0;
		priority_queue<
			par, vector<par>, greater<par>
		> pq;
		pq.push({0, {"A", start}});

		while(!pq.empty()){
			par p = pq.top(); pq.pop();
			int u = p.second.second;
			string str = p.second.first;
			for(auto i: e[u]){
				int v = i.second.second;
				db(str << " " << i.second.first);
				if(str[0] != i.second.first[0]){
					int w = i.first;
					if(distancia[v] > distancia[u] + w){
						distancia[v] = distancia[u] + w;
						pq.push({distancia[v], {i.second.first, v}});
					}
				}
			}
		}
		return distancia[finish];
	}
};

int main()
{
	while(1){
		int p;
		scanf("%d", &p);
		if(p == 0) break;

		getchar();

		Graph g(2 * p + 10);

		map<string, int> dest;
		string tot, str1, str2, str3;

		getline(cin, tot);

		str1 = tot.substr(0, tot.find(' '));
		str2 = tot.substr(tot.find(' ') + 1, tot.size());
		
		dest[str1] = 0;
		dest[str2] = 1;
		int cont = 2;
		for(int i = 0; i < p; i++){
			getline(cin, tot);
			str1 = tot.substr(0, tot.find(' '));
			tot = tot.substr(tot.find(' ') + 1, tot.size());

			str2 = tot.substr(0, tot.find(' '));
			str3 = tot.substr(tot.find(' ') + 1, tot.size());

			if(dest.find(str1) == dest.end()){
				dest[str1] = cont++;
			}
			if(dest.find(str2) == dest.end()){
				dest[str2] = cont++;
			}
			g.addEdge(dest[str1], dest[str2], str3);
		}
		int res = g.dijkstra(0, 1);
		if(res == INT_MAX >> 1){
			printf("impossivel\n");
		}
		else{
			printf("%d\n", res);
		}
	}
}