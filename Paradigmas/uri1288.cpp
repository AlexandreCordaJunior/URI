#include <bits/stdc++.h>

using namespace std;

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

typedef pair<int, int> ii;

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

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int qtd;
		scanf("%d", &qtd);
		ii *vet = (ii *) malloc(sizeof(ii) * qtd);
		for(int i = 0; i < qtd; i++){
			int poder, peso;
			scanf("%d %d", &poder, &peso);
			vet[i] = {poder, peso};
		}
		int cargaMaxima;
		scanf("%d", &cargaMaxima);
		init(qtd, cargaMaxima);
		int resistencia;
		scanf("%d", &resistencia);
		printf("%s\n", knapSack(vet, qtd, cargaMaxima) >= resistencia ?
			"Missao completada com sucesso" : "Falha na missao"
		);
	}
}