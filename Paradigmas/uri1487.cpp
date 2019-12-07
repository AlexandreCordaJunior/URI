#include <bits/stdc++.h>

using namespace std;

bool prim = true;
int caso = 0;
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

int max(int a, int b){
	return a > b ? a : b;
}

typedef pair<int, int> ii;

int knapSack(ii *vet, int qtd, int total){
	if(qtd == 0 || total == 0) return 0;
	if(dp[qtd][total] != 0) return dp[qtd][total];
	if(vet[qtd - 1].first > total) return knapSack(vet, qtd - 1, total);
	int maximo = max(
		knapSack(vet, qtd - 1, total),
		knapSack(vet, qtd, total - vet[qtd - 1].first) + vet[qtd - 1].second
	);
	dp[qtd][total] = maximo;
	return maximo;
}

int main()
{
	int qtd, total;
	while(1){
		scanf("%d %d", &qtd, &total);
		if(qtd == 0 && total == 0) break;
		//if(!prim) printf("\n");
		ii *vet = (ii *) malloc(sizeof(ii) * qtd);
		init(qtd, total);
		for(int i = 0; i < qtd; i++){
			int tempo, pontuacao;
			scanf("%d %d", &tempo, &pontuacao);
			vet[i] = {tempo, pontuacao};
		}
		printf("Instancia %d\n", ++caso);
		printf("%d\n", knapSack(vet, qtd, total));
		//prim = false;
		printf("\n");
	}
}