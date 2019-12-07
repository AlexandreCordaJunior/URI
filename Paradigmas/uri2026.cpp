#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int max(int a, int b){
	return a > b ? a : b;
}

int **dp;

void init(int qtd, int total){
	dp = (int **) malloc(sizeof(int *) * (qtd + 1));
	for(int i = 0; i <= qtd; i++){
		dp[i] = (int *) malloc(sizeof(int) * (total + 1));
	}
	for(int i = 0; i <= qtd; i++){
		for(int j = 0; j <= total; j++){
			dp[i][j] = 0;
		}
	}
}

int knapSack(ii *vet, int qtd, int total){
	if(qtd == 0 or total == 0) return 0;
	if(dp[qtd][total] != 0) return dp[qtd][total];
	if(vet[qtd - 1].second > total) return knapSack(vet, qtd - 1, total);
	int maximo = max(
		knapSack(vet, qtd - 1, total),
		knapSack(vet, qtd - 1, total - vet[qtd - 1].second) + vet[qtd - 1].first
	);
	dp[qtd][total] = maximo;
	return maximo;
}

int main()
{
	int casos;
	scanf("%d", &casos);
	for(int i = 0; i < casos; i++){
		int qtd;
		scanf("%d", &qtd);
		int maximo;
		scanf("%d", &maximo);
		ii *vet = new ii[qtd];
		for(int j = 0; j < qtd; j++){
			int total, peso;
			scanf("%d %d", &total, &peso);
			vet[j] = {total, peso};
		}
		init(qtd, maximo);

		printf("Galho %d:\n", i + 1);
		printf("Numero total de enfeites: %d\n", knapSack(vet, qtd, maximo));
		printf("\n");
	}
}