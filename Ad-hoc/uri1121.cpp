#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

vector<pair<int, int>> vet = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};
/* comeca no norte e sentido horario */

int main()
{
	int n, m, q;
	while(scanf("%d %d %d", &n, &m, &q) && n && m && q){
		char pista[105][105];
		for(int i = 0; i < n; i++){
			scanf("%s", pista[i]);
		}

		pair<int, int> pos;
		int dir;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(pista[i][j] == 'N' or pista[i][j] == 'S' or
					pista[i][j] == 'L' or pista[i][j] == 'O'){

					pos = {i, j};
					if(pista[i][j] == 'N'){
						dir = 0;
					}
					if(pista[i][j] == 'L'){
						dir = 1;
					}
					if(pista[i][j] == 'S'){
						dir = 2;
					}
					if(pista[i][j] == 'O'){
						dir = 3;
					}
					break;
				}
			}
		}

		char str[50002];
		scanf("%s", str);

		int cont = 0;
		for(int i = 0; i < strlen(str); i++){
			if(str[i] == 'D'){
				dir = (dir + 1) % 4;
			}
			if(str[i] == 'E'){
				dir = (dir - 1) < 0 ? 3 : (dir - 1);
			}
			if(str[i] == 'F'){
				int x, y;
				x = pos.first + vet[dir].first;
				y = pos.second + vet[dir].second;

				bool mexer = true;

				if(x < 0 or x > n - 1){
					mexer = false;
				}
				if(y < 0 or y > m - 1){
					mexer = false;
				}



				if(mexer){
					if(pista[x][y] == '#'){
						mexer = false;
					}
				}
				/*db(pos.first << " " << pos.second);
				db(mexer);
				db(pista[pos.first][pos.second]);*/
			
				if(mexer){
					pos = {x, y};
					if(pista[pos.first][pos.second] == '*'){
						pista[pos.first][pos.second] = '.';
						cont++;
					}
				}

			}
		}
		printf("%d\n", cont);
	}
}