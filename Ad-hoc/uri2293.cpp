#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	int **m = new int*[x];
	for(int i = 0; i < x; i++){
		m[i] = new int[y];
	}

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			scanf("%d", &m[i][j]);
		}
	}

	int maximo = 0;

	for(int i = 0; i < x; i++){
		int cont = 0;
		for(int j = 0; j < y; j++){
			cont += m[i][j];
		}
		if(cont > maximo){
			maximo = cont;
		}
	}

	for(int j = 0; j < y; j++){
		int cont = 0;
		for(int i = 0; i < x; i++){
			cont += m[i][j];
		}
		if(cont > maximo){
			maximo = cont;
		}	
	}

	printf("%d\n", maximo);
}