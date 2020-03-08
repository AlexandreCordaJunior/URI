#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		int altura = (num + 1) / 2;

		int primEspacos = altura - 1;
		int secEspacos = altura - 2;

		for(int i = 0; i < altura; i++){
			for(int j = 0; j < (altura - i - 1); j++){
				printf(" ");
			}
			for(int j = 0; j < (2 * i + 1); j++){
				printf("*");
			}
			printf("\n");
		}
		for(int i = 0; i < primEspacos; i++){
			printf(" ");
		}
		printf("*\n");
		for(int i = 0; i < secEspacos; i++){
			printf(" ");
		}
		printf("***\n\n");
	}
}