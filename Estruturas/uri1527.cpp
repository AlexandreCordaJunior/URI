#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int *parent;
int *ranking;
int *pontos;

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) && n && m){
		int vit = 0;

		parent = new int[n];
		ranking = new int[n];
		pontos = new int[n];

		for(int i = 0; i < n; i++){
			parent[i] = i;
			ranking[i] = 0;
			scanf("%d", &pontos[i]);
		}

		for(int i = 0; i < m; i++){
			int op, g1, g2;

			scanf("%d %d %d", &op, &g1, &g2);
			
			g1--;g2--;

			if(op == 1){

				while(g1 != parent[g1]){
					g1 = parent[g1];
				}

				while(g2 != parent[g2]){
					g2 = parent[g2];
				}

				if(ranking[g1] > ranking[g2]){
					parent[g2] = g1;
					pontos[g1] += pontos[g2];
				}
				else{
					parent[g1] = g2;
					pontos[g2] += pontos[g1];
				}
				if(ranking[g1] == ranking[g2]){
					ranking[g2]++;
				}
			}
			if(op == 2){
				while(g1 != parent[g1]){
					g1 = parent[g1];
				}

				while(g2 != parent[g2]){
					g2 = parent[g2];
				}

				int r = 0;
				while(r != parent[r]){
					r = parent[r];
				}

				int gr = 0;

				if(r == g1){
					gr = 1;
				}
				if(r == g2){
					g2 = 2;
				}

				if(pontos[g1] != pontos[g2]){
					if(gr == 1){
						if(pontos[g1] > pontos[g2]){
							vit++;
						}
					}
					if(gr == 2){
						if(pontos[g1] < pontos[g2]){
							vit++;
						}
					}
				}
			}
		}
		printf("%d\n", vit);

		/*for(int i = 0; i < n; i++){
			db(i << " " << pontos[i] << " " << parent[i] << " " << pontos[parent[i]]);
		}*/
	}
}