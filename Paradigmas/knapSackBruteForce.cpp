#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b

using namespace std;

typedef pair<int, int> ii;

int knapSack(ii *vet, int total, int valores){
	if(total == 0 || valores == 0) return 0;
	if(vet[valores - 1].first > total) return knapSack(vet, total, valores - 1);
	return max(knapSack(vet, total, valores - 1),
		vet[valores - 1].second + 
		knapSack(vet, total - vet[valores - 1].first, valores - 1));
}

int main()
{
	int total, valores;
	scanf("%d %d", &total, &valores);

	ii *vet = (ii *) malloc(sizeof(ii) * valores);
	for(int i = 0; i < valores; i++){
		int peso, valorReal;
		scanf("%d %d", &peso, &valorReal);
		vet[i] = {peso, valorReal};
	}
	printf("%d\n", knapSack(vet, total, valores));
}