#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef pair<int, int> ii;

int dp[100000][1000];

int knap(ii *vet, int n, int h, int estado){
	if(dp[n][estado] != -1) return dp[n][estado];
	if(n == 0){
		return 0;
	}
	if(vet[n - 1].second <= estado){
		return knap(vet, n - 1, h, estado);
	}
	int val = max(
		knap(vet, n - 1, h, estado),
		knap(vet, n - 1, h, estado + 1) + vet[n - 1].first
	);
	dp[n][estado] = val;
	return val;
}

bool comp(ii t1, ii t2){
	if(t1.second < t2.second){
		return false;
	}
	return true;
}

int main()
{
	int n, h;

	while(scanf("%d %d", &n, &h) != EOF){
		ii *vet = new ii[n];

		for(int i = 0; i <= n; i++){			
			for(int j = 0; j <= h; j++){
				dp[i][j] = -1;
			}
		}

		int total = 0;
		for(int i = 0; i < n; i++){
			int valor, tempo;
			scanf("%d %d", &valor, &tempo);

			vet[i] = {valor, tempo};
			total += valor;
		}

		/*for(int i = 0; i < n; i++){
			db(vet[i].first << " " << vet[i].second);
		}*/

		sort(vet, vet + n, comp);

		int res = knap(vet, n, h, 0);
		db(total - res);
	}
}