#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b

using namespace std;

typedef pair<int, int> ii;

int knapSack(ii *vet, int total, int qtd){
	int dp[qtd + 1][total + 1];
	for(int i = 0; i <= qtd; i++){
		for(int j = 0; j <= total; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else{
				if(vet[i - 1].first <= j){
					dp[i][j] = max(vet[i - 1].second + dp[i - 1][j - vet[i - 1].first],
						dp[i - 1][j]);
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