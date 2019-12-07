#include <bits/stdc++.h>

using namespace std;

int matrix[5][5];

int backtrack(){
	if(matrix[0][0] == 1) return 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()){
		pair<int, int> u = q.front();
		q.pop();
		if(u.first == 4 && u.second == 4){
			return 1;
		}
		matrix[u.first][u.second] = 1;
		if(u.first + 1 < 5 && matrix[u.first + 1][u.second] == 0) q.push({u.first + 1, u.second});
		if(u.second + 1 < 5 && matrix[u.first][u.second + 1] == 0) q.push({u.first, u.second + 1});
		if(u.first - 1 >= 0 && matrix[u.first - 1][u.second] == 0) q.push({u.first - 1, u.second});
		if(u.second - 1 >= 0 && matrix[u.first][u.second - 1] == 0) q.push({u.first, u.second - 1});
	}
	return 0;
}


int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		printf("%s\n", backtrack() ? "COPS" : "ROBBERS");
	}
}