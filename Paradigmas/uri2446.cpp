#include <bits/stdc++.h>

using namespace std;

int **dp;

void init(int qtd, int valor){
	dp = (int **) malloc(sizeof(int *) * (qtd + 1));
	for(int i = 0; i <= qtd; i++){
		dp[i] = (int *) malloc(sizeof(int) * (valor + 1));
		for(int j = 0; j <= valor; j++){
			dp[i][j] = -1;
		}
	}
}

int change(int *coins, int qtd, int valor){
	if(valor == 0) return 1;
	if(valor < 0) return 0;
	if(qtd == 0) return 0;
	if(dp[qtd][valor] != -1) return dp[qtd][valor];
	int value =
		change(coins, qtd - 1, valor) ||
		change(coins, qtd - 1, valor - coins[qtd])
	;
	dp[qtd][valor] = value;
	return value;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int valor, moedas;
	scanf("%d %d", &valor, &moedas);

	int coins[moedas + 1];
	for(int i = 1; i <= moedas; i++){
		scanf("%d", &coins[i]);
	}
	init(moedas, valor);
	
	printf("%s\n", change(coins, moedas, valor) == 0 ? "N" : "S");
}