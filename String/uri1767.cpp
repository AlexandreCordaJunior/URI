#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

ii knapSack(int total, int peso, ii *vet, int pesoPego){
	if(total == 0 or peso == 0){
		return {0, pesoPego};
	}
	if(vet[total - 1].second > peso){
		return knapSack(total - 1, peso, vet, pesoPego);
	}
	ii v1 = knapSack(total - 1, peso, vet, pesoPego);
	ii v2 = knapSack(total - 1, peso - vet[total - 1].second, vet, pesoPego);
	v2.first += vet[total - 1].first;
	v2.second += vet[total - 1].second;

	if(v1.first > v2.first){
		return v1;
	}
	else{
		return v2;
	}
}

int main()
{
	int casos;
	scanf("%d", &casos);

	while(casos--){
		int total;
		scanf("%d", &total);

		ii *vet = new ii[total];

		for(int i = 0; i < total; i++){
			int qtd, peso;
			scanf("%d %d", &qtd, &peso);

			vet[i] = {qtd, peso};
		}

		ii res = knapSack(total, 50, vet, 0);
		printf("%d %d\n", res.first, res.second);
	}
}