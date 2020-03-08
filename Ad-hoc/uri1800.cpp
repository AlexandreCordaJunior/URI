#include <bits/stdc++.h>

using namespace std;

int main()
{
	int qtd, e;
	scanf("%d %d", &qtd, &e);
	map<int, bool> mapa;

	for(int i = 0; i < e; i++){
		int temp;
		scanf("%d", &temp);
		mapa[temp] = true;
	}

	for(int i = 0; i < qtd; i++){
		int temp;
		scanf("%d", &temp);
		if(mapa[temp]){
			printf("0\n");
		}
		else{
			printf("1\n");
			mapa[temp] = true;
		}
	}
}