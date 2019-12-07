	#include <bits/stdc++.h>

	using namespace std;

	int change(int x, int *coins, int qtd){
		int *value = new int[x + 1];
		for(int i = 1; i <= x; i++){
			value[i] = INT_MAX >> 1;
			for(int j = 0; j < qtd; j++){
				if(i - coins[j] >= 0){
					value[i] = min(value[i], value[i - coins[j]] + 1);
				}
			}
		}
		return value[x];
	}

	int main()
	{
		int casos;
		scanf("%d", &casos);
		while(casos--){
			int blocos, medida;
			scanf("%d %d", &blocos, &medida);
			int *coins = (int *) malloc(sizeof(int) * blocos);
			for(int i = 0; i < blocos; i++){
				int temp;
				scanf("%d", &temp);
				coins[i] = temp;
			}
			sort(coins, coins + blocos);
			printf("%d\n", change(medida, coins, blocos));
		}
	}