#include <bits/stdc++.h>

#define BIG 10000;

using namespace std;


struct Graph{
	int v;
	double **matrix;
	Graph(int v){
		this->v = v;
		matrix = (double **) malloc(sizeof(double *) * v);
		for(int i = 0; i < v; i++){
			matrix[i] = (double *) malloc(sizeof(double) * v);
		}
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				matrix[i][j] = 0;
			}
		}
	}

	void floyd(){
		for(int k = 0; k < v; k++){
			for(int i = 0; i < v; i++){
				for(int j = 0; j < v; j++){
					if(matrix[i][j] < matrix[i][k] * matrix[k][j]){
						matrix[i][j] = matrix[i][k] * matrix[k][j];
					}
				}
			}
		}
	}
};

int main()
{
	while(1){
		int v, e;
		scanf("%d", &v);
		if(v == 0) break;
		scanf("%d", &e);
		Graph g(v);
		while(e--){
			int u, v;
			double w;
			scanf("%d %d %lf", &u, &v, &w);
			w = w / 100.0;
			g.matrix[u - 1][v - 1] = g.matrix[v - 1][u - 1] = w;
		}
		/*for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				printf("%.2lf ", g.matrix[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");*/
		g.floyd();
		/*
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				printf("%.6lf ", g.matrix[i][j]);
			}
			printf("\n");
		}*/
		printf("%.6lf percent\n", g.matrix[0][v]);
	}
}