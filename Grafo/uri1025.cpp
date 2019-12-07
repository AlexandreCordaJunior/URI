#include <bits/stdc++.h>

using namespace std;

int caso = 1;

int main()
{
	
	while(1){
		int m, q;
		scanf("%d %d", &m, &q);
		
		if(m == 0 && q == 0) break;
		printf("CASE# %d:\n", caso++);
		int *vet = new int[m];
		for(int i = 0; i < m; i++){
			int num;
			scanf("%d", &num);
			vet[i] = num;
		}
		sort(vet, vet + m);
		while(q--){
			int num;
			bool exibir = true;
			scanf("%d", &num);
			for(int i = 0; i < m; i++){
				if(vet[i] == num){
					printf("%d found at %d\n", num, i + 1);
					exibir = false;
					break;
				}
				else{
					if(vet[i] > num){
						break;
					}
				}
			}
			if(exibir){
				printf("%d not found\n", num);
			}
		}
	}
}