#include <bits/stdc++.h>

using namespace std;

struct Graph{
	int v;
	int **matrix;

	Graph(int v){
		this->v = v;
		matrix = (int **) malloc(sizeof(int *) * v);
		for(int i = 0; i < v; i++){
			matrix[i] = (int *) malloc(sizeof(int) * v);
		}
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				matrix[i][j] = INT_MAX >> 1;
			}
		}
	}

	void floyd(){
		for(int k = 0; k < v; k++){
			for(int i = 0; i < v; i++){
				for(int j = 0; j < v; j++){
					if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
						matrix[i][j] = matrix[i][k] + matrix[k][j];
					}
				}
			}
		}
	}
};

int main()
{
	int v, e, q;
	scanf("%d %d %d", &v, &e, &q);
	Graph g(v);
	while(e--){
		int u, v;
		scanf("%d %d", &u, &v);
		g.matrix[u - 1][v - 1] = g.matrix[v - 1][u - 1] = 1;
	}
	g.floyd();
	while(q--){
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%s\n", g.matrix[u - 1][v - 1] == INT_MAX >> 1 ? "Deu ruim" : "Lets que lets");
	}
}