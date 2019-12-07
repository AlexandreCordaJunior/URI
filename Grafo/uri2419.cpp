#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	string mapa[x];
	for(int i = 0; i < x; i++){
		getchar();
		getline(cin, mapa[i]);
	}
	int cont = 0;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(mapa[i][j] == '#'){
				if(i - 1 >= 0 && mapa[i - 1][j] == '.'){
					cont++;
					continue;
				}
				if(i + 1 < x && mapa[i + 1][j] == '.'){
					cont++;
					continue;
				}
				if(j - 1 >= 0 && mapa[i][j - 1] == '.'){
					cont++;
					continue;
				}
				if(j + 1 < y && mapa[i][j + 1] == '.'){
					cont++;
					continue;
				}
			}
		}
	}
	printf("%d\n", cont);
}