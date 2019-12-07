#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

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
	if(qtd == 0 || total == 0) return 0;
	if(dp[qtd][total] != 0) return dp[qtd][total];
	if(vet[qtd - 1].second > total) return knapSack(vet, qtd - 1, total);
	int maximo = max(
		knapSack(vet, qtd - 1, total),
		knapSack(vet, qtd - 1, total - vet[qtd - 1].second) + vet[qtd - 1].first
	);
	dp[qtd][total] = maximo;
	return maximo;
}

int max(int a, int b){
	return a > b ? a : b;
}

int main()
{
	while(1){
		int pedidos;
		scanf("%d", &pedidos);
		if(pedidos == 0) break;
		int maximo;
		scanf("%d", &maximo);
		init(pedidos, maximo);
		ii *vet = (ii *) malloc(sizeof(ii) * pedidos);
		for(int i = 0; i < pedidos; i++){
			int tempo, qtd;
			scanf("%d %d", &tempo, &qtd);
			vet[i] = {tempo, qtd};
		}
		printf("%d min.\n", knapSack(vet, pedidos, maximo));
	}
}