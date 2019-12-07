#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		iii *vet = new iii[num];

		for(int i = 0; i < num; i++){
			int disp, temp;
			scanf("%d %d", &disp, &temp);
			vet[i] = {disp + temp, {disp, temp}};
		}

		sort(vet, vet + num);
		int cont = 1;
		for(int i = 0; i < num; i++){
			if(cont < vet[i].second.first){
				cont = vet[i].second.first;
			}
			cont += vet[i].second.second;
		}
		printf("%d\n", cont);
	}
}