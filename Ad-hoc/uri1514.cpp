#include <bits/stdc++.h>

using namespace std;

int main()
{
	int part, prob;
	while(scanf("%d %d", &part, &prob) && part && prob){
		int matrix[part][prob];

		bool condicoes[4];
		condicoes[0] = true;
		condicoes[1] = true;
		condicoes[2] = true;
		condicoes[3] = true;

		for(int i = 0; i < part; i++){
			int sum = 0;
			for(int j = 0; j < prob; j++){
				scanf("%d", &matrix[i][j]);
				if(matrix[i][j] == 1){
					sum++;
				}
			}
			if(sum == prob){
				condicoes[0] = false;
			}
			if(sum == 0){
				condicoes[3] = false;
			}
		}

		for(int i = 0; i < prob; i++){
			int sum = 0;
			for(int j = 0; j < part; j++){
				if(matrix[j][i] == 1){
					sum++;
				}
			}
			if(sum == part){
				condicoes[2] = false;
			}
			if(sum == 0){
				condicoes[1] = false;
			}
		}
		int soma = 0;
		for(int i = 0; i < 4; i++){
			if(condicoes[i]){
				soma++;
			}
		}
		printf("%d\n", soma);
	}
}