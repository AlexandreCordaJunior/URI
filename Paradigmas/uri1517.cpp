#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int tempoMax = 0;

int dp[25][25][2100];

void init(){
	for(int i = 0; i < 25; i++){
		for(int j = 0; j < 25; j++){
			for(int k = 0; k < 2100; k++){
				dp[i][j][k] = 0;
			}
		}
	}
}


int distance(int x1, int y1, int x2, int y2){
	if(x1 == x2){
		return abs(y1 - y2);
	}
	if(y1 == y2){
		return abs(x1 - x2);
	}
	return max(abs(x1 - x2), abs(y1 - y2));
}

int total(iii *vet, ii inicial, int qtd, int tempo){
	//printf("%d %d\n", inicial.first, inicial.second);
	if(qtd == 0 || tempo == tempoMax) return 0;
	if(dp[inicial.first][inicial.second][tempo] != 0) return dp[inicial.first][inicial.second][tempo];
	int distancia = distance(
		inicial.first, inicial.second,
		vet[qtd - 1].second.first, vet[qtd - 1].second.second
	);
	/*printf("%d %d -- %d %d -> %d\n", inicial.first, inicial.second,
		vet[qtd - 1].second.first, vet[qtd - 1].second.second, distancia);
	printf("%d -- %d -- TempoVet -> %d\n", tempo, tempoMax, vet[qtd - 1].first);*/
	if(tempo + distancia > tempoMax || tempo + distancia > vet[qtd - 1].first){
		return total(vet, inicial, qtd - 1, tempo);
	}
	int maximo = max(
		total(vet, inicial, qtd - 1, tempo),
		total(vet, {vet[qtd - 1].second.first, vet[qtd - 1].second.second}, qtd - 1, vet[qtd - 1].first
		) + 1
	);
	dp[inicial.first][inicial.second][tempo] = maximo;
	return maximo;
}

int main()
{
	while(1){
		int linhas, colunas, macas;
		scanf("%d %d %d", &linhas, &colunas, &macas);
		if(linhas == 0 && colunas == 0 && macas == 0) break;
		iii *vet = new iii[macas];
		for(int i = 0; i < macas; i++){
			int x, y, t;
			scanf("%d %d %d", &x, &y, &t);
			vet[i] = {t, {x, y}};
		}
		sort(vet, vet + macas, greater<pair<int, pair<int, int>>>());
		tempoMax = vet[0].first;
		int x, y;
		scanf("%d %d", &x, &y);
		ii inicial = {x, y};
		init();
		printf("%d\n", total(vet, inicial, macas, 0));
	}
}