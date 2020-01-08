#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef vector<int> vi;

struct Graph{
	int v;
	int e[1001][1001];

	Graph(int v){
		this->v = v;
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				scanf("%d", &e[i][j]);
			}
		}
	}

	bool isBi(){
		queue<int> q;
		vector<int> color(v, -1);
		color[0] = 0;
		q.push(0);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < v; i++){
				if(e[u][i] == 0){
					if(color[i] == -1){
						color[i] = 1 - color[u];
						q.push(i);
					}
					else{
						if(color[i] == color[u]){
							return false;
						}
					}
				}
			}
		}
		return true;

	}
};

int main()
{
	int n;
	scanf("%d", &n);
	Graph g(n);
	printf("%s\n", g.isBi() ? "Bazinga!" : "Fail!");
}