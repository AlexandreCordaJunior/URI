#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, r;
	while(scanf("%d %d", &n, &r) != EOF){
		int *vet = new int[n + 1];
		for(int i  = 0; i < n + 1; i++){
			vet[i] = 0;
		}
		for(int i = 0; i < r; i++){
			int temp;
			scanf("%d", &temp);
			vet[temp]++;
		}
		bool ast = true;
		for(int i = 1; i < n + 1; i++){
			if(!vet[i]){
				ast = false;
				printf("%d ", i);
			}
		}
		if(ast){
			printf("*");
		}
		printf("\n");
	}
}