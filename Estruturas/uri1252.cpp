#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool comp(ii par1, ii par2){
	if(par1.second < par2.second) return true;
	if(par1.second > par2.second) return false;

	bool isPar1, isPar2;
	isPar1 = (par1.first % 2 == 0);
	isPar2 = (par2.first % 2 == 0);

	if(isPar1){
		if(isPar2){
			return par1.first < par2.first;
		}
		else{
			return false;
		}
	}
	else{
		if(isPar2){
			return true;
		}
		else{
			return par1.first > par2.first;
		}
	}
}

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) && n && m){
		ii *vet = new ii[n];
		for(int i = 0; i < n; i++){
			scanf("%d", &vet[i].first);
			vet[i].second = vet[i].first % m;
		}

		sort(vet, vet + n, comp);
		printf("%d %d\n", n, m);
		for(int i = 0; i < n; i++){
			printf("%d\n", vet[i].first);
		}
	}
	printf("0 0\n");
}