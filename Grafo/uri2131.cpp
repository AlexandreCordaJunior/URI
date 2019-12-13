#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef vector<int> vi;
struct Graph{
	int v;
	vector<vi> e;

	Graph(int v){
		this->v = v;
		e.assign(v, vi());
	}

	void addEdge(int u, int v){
		e[u].push_back(v);
		e[v].push_back(u);
	}

	bool isBi(){
		vector<int> color(v, -1);
		stack<int> s;
		bool bi = true;
		for(int i = 0; i < v; i++){
			if(color[i] == -1){
				s.push(i);
				color[i] = 0;
				
				while(!s.empty()){
					int u = s.top(); s.pop();
					for(auto v: e[u]){
						if(color[v] == -1){
							color[v] = 1 - color[u];
							s.push(v);
						}
						else{
							if(color[u] == color[v]){
								bi = false;
								return false;
							}
						}
					}
				}	
			}
		}
		return bi;	
	}
};
int casos = 0;

int main()
{
	int v, e;
	while(scanf("%d %d", &v, &e) != EOF){
		Graph g(v);
		while(e--){
			int u, v;
			scanf("%d %d", &u, &v);
			g.addEdge(u - 1, v - 1);
		}
		printf("Instancia %d\n", ++casos);
		printf("%s\n\n", g.isBi() ? "sim" : "nao");
	}
}