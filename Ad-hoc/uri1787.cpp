#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) && num){

		int pontosU, pontosR, pontosI;
		pontosU = pontosR = pontosI = 0;

		for(int j = 0; j < num; j++){
			int u, r, i;
			scanf("%d %d %d", &u, &r, &i);

			int qtdU, qtdR, qtdI;
			qtdU = qtdR = qtdI = 0;

			for(int k = 0; k < 31; k++){
				if(u  & (1 << k)){
					qtdU++;
				}
				if(r  & (1 << k)){
					qtdR++;
				}
				if(i  & (1 << k)){
					qtdI++;
				}
			}

			int maximo = max(u, max(r, i));


			if(qtdU == 1){
				pontosU++;
				if(maximo == u){
					pontosU++;
				}
			}
			if(qtdR == 1){
				pontosR++;
				if(maximo == r){
					pontosR++;
				}
			}
			if(qtdI == 1){
				pontosI++;
				if(maximo == i){
					pontosI++;
				}
			}
		}
		int pontosMaximos = max(pontosU, max(pontosR, pontosI));
		int qtdMax = 0;
		if(pontosMaximos == pontosU){
			qtdMax++;
		}
		if(pontosMaximos == pontosR){
			qtdMax++;
		}
		if(pontosMaximos == pontosI){
			qtdMax++;
		}
		if(qtdMax != 1){
			printf("URI\n");
		}
		else{
			if(pontosMaximos == pontosU){
				printf("Uilton\n");
			}
			if(pontosMaximos == pontosR){
				printf("Rita\n");
			}
			if(pontosMaximos == pontosI){
				printf("Ingred\n");
			}
		}
	}
}