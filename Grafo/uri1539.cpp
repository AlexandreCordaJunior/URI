#include <bits/stdc++.h>

using namespace std;

class Antena{
public:
	int x, y, r, index;

	Antena(int x, int y, int r, int index){
		this->x = x;
		this->y = y;
		this->r = r;
		this->index = index;
	}
};

class Graph{
public:
	int v;
	double **peso;
	Graph(int v){
		this->v = v;
		for(int i = 0; i < v; i++){
			peso = (double **) malloc(sizeof(double *) * v);
		}

		for(int i = 0; i < v; i++){
			peso[i] = (double *) malloc(sizeof(double ) * v);
		}
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(i == j) peso[i][j] = 0.0;
				else peso[i][j] = 99999999.99;
			}
		}
	}

	void floyd(){
		for(int k = 0; k < v; k++){
			for(int i = 0; i < v; i++){
				for(int j = 0; j < v; j++){
					if(peso[i][j] > peso[i][k] + peso[k][j]){
						peso[i][j] = peso[i][k] + peso[k][j];
					}
				}
			}
		}
	}
};

int main()
{
	while(1){
		int v;
		scanf("%d", &v);
		if(v == 0) break;
		Graph g(v);
		Antena *antenas = (Antena *) malloc(sizeof(Antena) * v);
		for(int i = 0; i < v; i++){
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			antenas[i] = Antena(x, y, r, i);
		}

		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(i != j){
					double distance = sqrt(pow(antenas[i].x - antenas[j].x, 2) +
						pow(antenas[i].y - antenas[j].y, 2));
					if(distance < antenas[i].r){
						g.peso[i][j] = distance;
					}
				}
			}
		}

		g.floyd();

		/*for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				printf("%.6lf ", g.peso[i][j]);
			}
			printf("\n");
		}*/

		int q;
		scanf("%d", &q);
		while(q--){
			int u, v;
			scanf("%d %d", &u, &v);
			double distance = g.peso[u - 1][v - 1];
			if((int)distance == (int)99999999.99){
				printf("-1\n");
			}
			else{
				printf("%d\n", (int)distance);
			}
		}
	}
}