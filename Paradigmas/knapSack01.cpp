#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b

using namespace std;

typedef pair<int, int> ii;

int knapSack(ii* vet, int total, int qtd){
	printf("%d %d\n", total, qtd);
	if(qtd == 0 || total == 0){
		return 0;
	}
	if(vet[qtd - 1].first > total){
		return knapSack(vet, total, qtd - 1);
	}
	else{
		return max(vet[qtd - 1].second + knapSack(vet, total - vet[qtd - 1].first, qtd - 1),
			knapSack(vet, total, qtd - 1));
	}
}

int main()
{
	int valores;
	scanf("%d", &valores);
	ii *vet = (ii*) malloc(sizeof(ii) * valores);
	for(int i = 0; i < valores; i++){
		int peso;
		int valor;
		scanf("%d %d", &peso, &valor);
		vet[i] = {peso, valor};
	}
	int total = 50;
	printf("%d\n", knapSack(vet, total, valores));
}