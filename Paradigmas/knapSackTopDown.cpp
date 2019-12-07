#include <bits/stdc++.h>

using namespace std;

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

typedef pair<int, int> ii;

int max(int a, int b){
	return a > b ? a : b;
}

int knapSack(ii *vet, int total, int qtd){
	if(total == 0 || qtd == 0) return 0;
	if(dp[qtd][total] != 0) return dp[qtd][total];
	if(vet[qtd - 1].first > total) return knapSack(vet, total, qtd - 1);
	int maximo = max(
		knapSack(vet, total, qtd - 1),
		knapSack(vet, total - vet[qtd - 1].first, qtd - 1) + vet[qtd - 1].second
		);
	dp[qtd][total] = maximo;
	return dp[qtd][total];
}

int main()
{
	int total, qtd;
	scanf("%d %d", &total, &qtd);
	init(qtd, total);
	ii *vet = (ii*) malloc(sizeof(ii) * qtd);
	for(int i = 0; i < qtd; i++){
		int peso, valor;
		scanf("%d %d", &peso, &valor);
		vet[i] = {peso, valor};
	}
	printf("%d\n", knapSack(vet, total, qtd));
}