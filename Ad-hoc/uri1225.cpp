#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		int *vet = new int[num];
		int cont = 0;

		for(int i = 0; i < num; i++){
			scanf("%d", &vet[i]);
			cont += vet[i];
		}

		if(cont % num == 0){
			int media = cont / num;
			int total = 0;

			for(int i = 0; i < num; i++){
				total += (abs(vet[i] - media));
			}
			total /= 2;
			printf("%d\n", total + 1);
		}
		else{
			printf("-1\n");
		}
	}
}