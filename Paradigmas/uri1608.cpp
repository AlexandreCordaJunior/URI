#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);

	while(casos--){
		int din, ingre, bolos;

		scanf("%d %d %d", &din, &ingre, &bolos);

		int *vetIngre = new int[ingre];
		for(int i = 0; i < ingre; i++){
			scanf("%d", &vetIngre[i]);
		}

		int *vetVal = new int[bolos];
		for(int i = 0; i < bolos; i++) vetVal[i] = 0;

		for(int i = 0; i < bolos; i++){
			int qtdIngre;
			scanf("%d", &qtdIngre);

			for(int j = 0; j < qtdIngre; j++){
				int pos, qtd;
				scanf("%d %d", &pos, &qtd);
				vetVal[i] += (qtd * vetIngre[pos]);
			}
		}
		int max = 0;
		for(int i = 0; i < bolos; i++){
			if(din / vetVal[i] > max){
				max = din / vetVal[i];
			}

		}
		printf("%d\n", max);
	}
}