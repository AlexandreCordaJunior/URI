#include <bits/stdc++.h>
#define db(x) cout << x << endl;

using namespace std;

int main()
{
	int m, n;
	while(scanf("%d %d", &m, &n) && m && n){
		getchar();

		string *vet = new string[m];
		for(int i = 0; i < m; i++){
			getline(cin, vet[i]);
		}

		stack<pair<int, int>> s;

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(vet[i][j] == 'T'){
					s.push({i, j});
				}
			}
		}

		while(!s.empty()){
			pair<int, int> u = s.top(); s.pop();
			//printf("%d %d\n", u.first, u.second);

			if(u.first - 1 >= 0 && vet[u.first - 1][u.second] == 'A'){
				//printf("1\n");
				vet[u.first - 1][u.second] = 'T';
				s.push({u.first - 1, u.second});
			}
			if(u.first + 1 < m && vet[u.first + 1][u.second] == 'A'){
				//printf("2\n");
				vet[u.first + 1][u.second] = 'T';
				s.push({u.first + 1, u.second});
			}

			if(u.second - 1 >= 0 && vet[u.first][u.second - 1] == 'A'){
				//printf("3\n");
				vet[u.first][u.second - 1] = 'T';
				s.push({u.first, u.second - 1});
			}
			if(u.second + 1 < n && vet[u.first][u.second + 1] == 'A'){
				//printf("4\n");
				vet[u.first][u.second + 1] = 'T';
				s.push({u.first, u.second + 1});
			}
		}

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				printf("%c", vet[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
