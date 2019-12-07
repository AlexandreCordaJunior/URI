	#include <bits/stdc++.h>

	using namespace std;

	int main()
	{
		long long casas;
		while(1){
			scanf("%lld", &casas);
			if(casas == 0) break;
			long long vet[casas];
			for(long long i = 0; i < casas; i++){
				scanf("%lld", &vet[i]);
			}
			long long trabalho = 0;
			for(long long i = 1; i < casas; i++){
				if(vet[i - 1] < 0){
					trabalho -= vet[i - 1];
					vet[i] += vet[i - 1];
				}
				else{
					trabalho += vet[i - 1];
					vet[i] += vet[i - 1];
				}
			}
			printf("%lld\n", trabalho);
		}
	}