#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	while(1){
		int num;
		scanf("%d", &num);
		if(num == 0) break;
		ull *vet = new ull[num];
		for(int i = 0; i < num; i++){
			scanf("%lld", &vet[i]);
		}
		sort(vet, vet + num);
		for(int i = 0; i < num; i += 2){
			if(vet[i] != vet[i + 1]){
				printf("%lld\n", vet[i]);
				break;
			}
		}
	}
}