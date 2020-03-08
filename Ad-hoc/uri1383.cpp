#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);

	for(int w = 0; w < casos; w++){



		int matrix[10][10];
		bool secoes[3][3][10];
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k <= 9; k++){
					secoes[i][j][k] = false;
				}
			}
		}



		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= 9; j++){
				scanf("%d", &matrix[i][j]);
				secoes[(i - 1) / 3][(j - 1) / 3][matrix[i][j]] = true;
			}
		}

		bool solu = true;

		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 1; k <= 9; k++){
					//db(secoes[i][j][k] << " " << i << " " << j << " " << k);
					if(!secoes[i][j][k]){
						solu = false;
						break;
					}
				}
			}
		}

		for(int i = 1; i <= 9; i++){
			vector<int> vet(10, false);
			for(int j = 1; j <= 9; j++){
				vet[matrix[i][j]] = true;
			}
			if(solu){
				for(int j = 1; j <= 9; j++){
					if(vet[j] == false){
						solu = false;
						break;
					}
				}	
			}
		}

		if(solu){
			for(int j = 1; j <= 9; j++){
				vector<int> vet(10, false);
				for(int i = 1; i <= 9; i++){
					vet[matrix[i][j]] = true;
				}
				if(solu){
					for(int i = 1; i <= 9; i++){
						if(vet[i] == false){
							solu = false;
							break;
						}
					}	
				}
			}
		}
		printf("Instancia %d\n", w + 1);
		printf("%s\n\n", solu ? "SIM" : "NAO");
	}
}