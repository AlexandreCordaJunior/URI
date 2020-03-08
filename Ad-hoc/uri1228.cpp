#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		int *vet = new int[num];
		for(int i = 0; i < num; i++) scanf("%d", &vet[i]);
		
		int *v2 = new int[num];
		int *pos = new int[num + 1];
		for(int i = 0; i < num; i++){
			scanf("%d", &v2[i]);
			pos[v2[i]] = i;
		}

		int cont = 0;
		for(int i = 0; i < num; i++){
			for(int j = i + 1; j < num; j++){
				if(pos[vet[i]] > pos[vet[j]]) cont++;
			}
		}
		printf("%d\n", cont);

	}
}