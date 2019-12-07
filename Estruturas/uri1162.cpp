#include <bits/stdc++.h>

using namespace std;

int bubbleSort(int *vet, int n){
	int cont = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1 ; j++){
			if(vet[j] > vet[j + 1]){
				cont++;
				int temp = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = temp;
			}
		}
	}
	return cont;	
}

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int trens;
		scanf("%d", &trens);
		int *vet = new int[trens];
		for(int i = 0; i < trens; i++){
			scanf("%d", &vet[i]);
		}
		printf("Optimal train swapping takes %d swaps.\n", bubbleSort(vet, trens));
	}
}