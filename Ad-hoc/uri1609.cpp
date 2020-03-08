#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int num;
		map<int, int> mapa;
		scanf("%d", &num);

		int cont = 0;
		for(int i = 0; i < num; i++){
			int temp;
			scanf("%d", &temp);
			if(mapa[temp] == 0){
				cont++;
			}
			mapa[temp]++;
		}
		printf("%d\n", cont);
	}
}