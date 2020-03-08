#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int **m = new int*[num];
	for(int i = 0; i < num; i++){
		m[i] = new int[num];
	}

	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			scanf("%d", &m[i][j]);
		}
	}

	map<int, bool> mapa;
	int cont = 0;

	for(int i = 0; i < 2 * num; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if(mapa[m[x][y]] == false){
			mapa[m[x][y]] = true;
			cont++;
		}
	}
	printf("%d\n", cont);
}