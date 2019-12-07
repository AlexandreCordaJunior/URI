#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int andares, capacidade, pessoasTotal;
		scanf("%d %d %d", &andares, &capacidade, &pessoasTotal);

		int *vet = new int[pessoasTotal];
		for(int i = 0; i < pessoasTotal; i++){
			scanf("%d", &vet[i]);
		}
		sort(vet, vet + pessoasTotal, greater<int>());
		int soma = 0;

		for(int i = 0; i < pessoasTotal; i += capacidade){
			soma += 2 * vet[i];
		}
		printf("%d\n", soma);
	}
}