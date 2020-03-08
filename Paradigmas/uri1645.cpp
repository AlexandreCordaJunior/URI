#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[20002];

ll solve(ll num, ll qtd, ll *vet, int qtdAtual){
	
}

void init(){
	for(int i = 0; i < 20002; i++){
		dp[i] = -1;
	}
}

int main()
{
	ll num, tam;
	while(scanf("%lld %lld", &num, &tam) && num && tam){
		init();

		ll *vet = new ll[num];
		for(ll i = 0; i < num; i++){
			scanf("%lld", &vet[i]);
		}

		ll res = solve();

	}
}