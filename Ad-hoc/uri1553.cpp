#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) && n && k){
		int vet[101];
		for(int i = 0; i <= 100; i++) vet[i] = 0;

		int count = 0;

		for(int i = 0; i < n; i++){
			int temp;
			scanf("%d", &temp);
			vet[temp]++;
			if(vet[temp] == k){
				count++;
			}
		}
		printf("%d\n", count);
	}
}