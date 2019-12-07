#include <bits/stdc++.h>

using namespace std;

double dp[16][1 << 16];

struct Graph{
	int v;
	double **matrix;

	Graph(int v){
		this->v = v;
		matrix = (double **) malloc(sizeof(double *) * v);
		for(int i = 0; i < v; i++){
			matrix[i] =  (double *) malloc(sizeof(double) * v);
			for(int j = 0; j < v; j++){
				matrix[i][j] = 0;
			}
		}
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < (1 << 16); j++){
				dp[i][j] = 0;
			}
		}
	}

	void addEdge(int u, int v, double w){
		matrix[u][v] = w;
		matrix[v][u] = w;
	}

	double tsp(int u, int vet){
		if(dp[u][vet] != 0) return dp[u][vet];
		//printf("%d %d\n", u, vet);
		bool continuar = false;
		for(int i = 0; i < v; i++){
			int temp = vet;
			temp &= (1 << i);
			if(!temp){
				continuar = true;
				break;
			}
		}
		if(!continuar) return matrix[u][0];

		double minimo = 1000000000.0;

		for(int i = 0; i < v; i++){
			int temp = vet & (1 << i);
			if(!temp){
				temp = vet;
				temp |= (1 << i);
				double temp2 = tsp(i, temp) + matrix[u][i];
				minimo = min(minimo, temp2);
			}
		}
		dp[u][vet] = minimo;
		return minimo;
	}
};

int main()
{
	int focos;
	while(1){
		scanf("%d", &focos);
		if(focos == 0) break;

		Graph g(focos + 1);
		vector<pair<int, int>> vet;
		for(int i = 0; i <= focos; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			vet.push_back({x, y});
		}

		for(int i = 0; i <= focos; i++){
			for(int j = i + 1; j <= focos; j++){
				double distance = sqrt(pow(vet[i].first - vet[j].first, 2)
					+ pow(vet[i].second - vet[j].second, 2));
				g.addEdge(i, j, distance);
			}
		}

		/*printf("\n\n");
		for(int i = 0; i <= focos; i++){
			for(int j = 0; j <= focos; j++){
				printf("%.2f\t", g.matrix[i][j]);
			}
			printf("\n");
		}*/

		printf("%.2f\n", g.tsp(0, 1));
	}
}