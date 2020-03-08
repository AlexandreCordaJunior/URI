#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int saco(ii *vet, int partida, int compras)
{
	if(partida == 0 or compras == 0){
		return 0;
	}
	if(vet[partida - 1].first > vet[partida - 1].second){
		return saco(vet, partida - 1, compras);
	}
	if(compras < vet[partida - 1].first - vet[partida - 1].second){

	}
}

int main()
{
	int jogos, compras;
	while(scanf("%d %d", &jogos, &compras) && jogos && compras){
		ii *vet = new ii[jogos];
		for(int i = 0; i < jogos; i++){
			int marc, sofr;
			scanf("%d %d", &marc, &sofr);
			vet[i] = {marc, sofr};
		}

		
	}
}