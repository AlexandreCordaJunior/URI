#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int max(int a, int b){
	return a > b ? a : b;
}

int knapSack(ii *vet, int total, int qtd){
	int dp[qtd + 1][total + 1];

	for(int i = 0; i <= qtd; i++){
		for(int j = 0; j <= total; j++){
			if(i == 0 || j == 0) dp[i][j] = 0;
			else{
				if(vet[i - 1].first <= j){
					dp[i][j] = max(dp[i - 1][j],
					dp[i - 1][j - vet[i - 1].first] + vet[i - 1].second
					);
				}
				else{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}
	return dp[qtd][total];
}

int main()
{
	int total, qtd;
	scanf("%d %d", &total, &qtd);

	ii *vet = (ii*) malloc(sizeof(ii) * qtd);
	for(int i = 0; i < qtd; i++){
		int peso, valor;
		scanf("%d %d", &peso, &valor);
		vet[i] = {peso, valor};
	}
	printf("%d\n", knapSack(vet, total, qtd));
}