#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(1){
		scanf("%d", &num);
		if(num == 0) break;

		for(int i = 0; i < num; i++){
			int vet[5];
			scanf("%d %d %d %d %d", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4]);

			int cont = 0;
			int res = -1;
			for(int i = 0; i < 5; i++){
				if(vet[i] <= 127){
					cont++;
					res = i;
				}
			}
			if(!cont){
				printf("*\n");
			}
			else{
				if(cont > 1){
					printf("*\n");
				}
				else{
					printf("%c\n", 'A' + res);
				}
			}
		}
	}
}