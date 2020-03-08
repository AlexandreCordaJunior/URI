#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(1){
		scanf("%d", &num);
		if(!num) break;

		map<int, int> mapa;
		int *vet = new int[num];

		for(int i = 0; i < num; i++){
			scanf("%d", &vet[i]);
			mapa[vet[i]] = i;
		}

		sort(vet, vet + num);
		printf("%d\n", mapa[vet[num - 2]] + 1);
	}
}