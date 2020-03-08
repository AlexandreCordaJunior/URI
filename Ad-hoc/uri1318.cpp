#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) && n && m){
		int *vet = new int[n + 1];
		for(int i = 0; i < n + 1; i++) vet[i] = 0;

		int cont = 0;
		for(int i = 0; i < m; i++){
			int temp;
			scanf("%d", &temp);
			if(vet[temp] == 1) cont++;
			vet[temp]++;
		}
		printf("%d\n", cont);
	}
}