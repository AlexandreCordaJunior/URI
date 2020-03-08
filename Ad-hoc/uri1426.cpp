#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int vet[9][9];
		for(int i = 0; i < 9; i++){
			if(i % 2 == 1){
				for(int j = 0; j < 9; j++){
					if(j > i){
						vet[i][j] = 0;
					}
					else{
						vet[i][j] = -1;	
					}
					
				}
			}
			else{
				for(int j = 0; j < 9; j++){
					if(j <= i){
						if(j % 2 == 0){
							scanf("%d", &vet[i][j]);
						}
						else{
							if(j > i){
								vet[i][j] = 0;
							}
							else{
								vet[i][j] = -1;	
							}
						}	
					}
					else{
						if(j > i){
							vet[i][j] = 0;
						}
						else{
							vet[i][j] = -1;	
						}
					}
				}
			}
		}

		for(int i = 8; i >= 0; i--){
			for(int j = 0; j < 9; j++){
				if(vet[i][j] == -1){
					if(i % 2 == 0){
						vet[i][j] = (vet[i - 2][j - 1] - vet[i][j - 1] - vet[i][j + 1]) / 2;
					}
					else{
						vet[i][j] = vet[i + 1][j] + vet[i + 1][j + 1];
					}
				}
			}
		}

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(j > i) break;
				if(j == 0) printf("%d", vet[i][j]);
				else printf(" %d", vet[i][j]);
			}
			printf("\n");
		}
	}	
}