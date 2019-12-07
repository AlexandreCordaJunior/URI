#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int max(int a, int b){
	return a > b ? a : b;
}

int **dp;
int **pai;

void init(int qtd, int valor){
	pai = (int **) malloc(sizeof(int *) * (qtd + 1));
	dp = (int **) malloc(sizeof(int *) * (qtd + 1));
	for(int i = 0; i <= qtd; i++){
		dp[i] = (int *) malloc(sizeof(int) * (valor + 1));
		pai[i] = (int *) malloc(sizeof(int) * (valor + 1));
	}
	for(int i = 0; i <= qtd; i++){
		for(int j = 0; j <= valor; j++){
			dp[i][j] = 0;
			pai[i][j] = 0;
		}
	}
}

int knapSack(ii *vet, int qtd, int total){
	if(total == 0 or qtd == 0){
		return 0;
	}
	if(dp[qtd][total] != 0) return dp[qtd][total];
	if(vet[qtd - 1].second > total) return knapSack(vet, qtd - 1, total);
	int maximo = knapSack(vet, qtd - 1, total);
	int temp = knapSack(vet, qtd - 1, total - vet[qtd - 1].second) + vet[qtd - 1].first;
	if(temp > maximo){
		maximo = temp;
		pai[qtd - 1][total - vet[qtd - 1].second] = total;
	}
	else{
		pai[qtd - 1][total] = total;
	}
	dp[qtd][total] = maximo;
	return maximo;
}

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int qtd;
		scanf("%d", &qtd);
		ii *vet = new ii[qtd];
		for(int i = 0; i < qtd; i++){
			int qtd, peso;
			scanf("%d %d", &qtd, &peso);
			vet[i] = {qtd, peso};
		}
		init(qtd, 50);
		int brinquedos = knapSack(vet, qtd, 50);
	}
}