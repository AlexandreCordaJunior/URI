#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef vector<pair<int, int>> vi;

struct Graph{
	int v;
	int **e;

	Graph(int v){
		this->v = v;
		e = (int **) malloc(sizeof(int *) * v);
		for(int i = 0; i < v; i++){
			e[i] = (int *) malloc(sizeof(int) * v);
			for(int j = 0; j < v; j++){
				e[i][j] = INT_MAX >> 1;
			}
		}
	}

	void addEdge(int u, int v, int w){
		e[u][v] = w;
		e[v][u] = w;
	}

	void floyd(){
		for(int k = 0; k < v; k++){
			for(int i = 0; i < v; i++){
				for(int j = 0; j < v; j++){
					if(e[i][j] > e[i][k] + e[k][j]){
						e[i][j] = e[i][k] + e[k][j];
					}
				}
			}
		}
	}
};

int casos = 0;

int main()
{
	while(1){
		int v, e;
		scanf("%d %d", &v, &e);
		if(v == 0 && e  == 0) break;
		Graph g(v);
		for(int i = 0; i < e; i++){
			int v1, v2, w;
			scanf("%d %d %d", &v1, &v2, &w);
			g.addEdge(v1 - 1, v2 - 1, w);
		}
		g.floyd();
		int q;
		scanf("%d", &q);
		printf("Instancia %d\n", ++casos);
		while(q--){
			int de, para;
			scanf("%d %d", &de, &para);
			printf("%d\n", g.e[de - 1][para - 1]);
		}
	}
}