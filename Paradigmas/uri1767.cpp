#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

iii knapSack(int total, int peso, ii *vet, int pesoPego, int naoPegos){
	if(total == 0 or peso == 0){
		return {0, {pesoPego, naoPegos}};
	}
	if(vet[total - 1].second > peso){
		return knapSack(total - 1, peso, vet, pesoPego, naoPegos + 1);
	}
	iii v1 = knapSack(total - 1, peso, vet, pesoPego, naoPegos + 1);
	v1.second.second += 1;
	iii v2 = knapSack(total - 1, peso - vet[total - 1].second, vet, pesoPego, naoPegos);
	v2.first += vet[total - 1].first;
	v2.second.first += vet[total - 1].second;

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
		int totalPack = 0;
		for(int i = 0; i < total; i++){
			int qtd, peso;
			scanf("%d %d", &qtd, &peso);
			totalPack += qtd;
			vet[i] = {qtd, peso};
		}

		iii res = knapSack(total, 50, vet, 0, 0);
		printf("%d brinquedos\nPeso: %d kg\nsobra(m) %d pacote(s)\n\n",
			res.first, res.second.first, res.second.second);
	}
}