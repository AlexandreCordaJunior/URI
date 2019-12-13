#include <bits/stdc++.h>

using namespace std;

int bfs(int **matrix, int x, int y, int m, int n){
	matrix[x][y] = 0;
	queue<pair<int, pair<int, int>>> q;
	int cont = 0;
	q.push({0, {x, y}});
	while(!q.empty()){
		pair<int, pair<int, int>> ii = q.front(); q.pop();
		int p1, x1, y1;
		p1 = ii.first;
		if(p1 > cont){
			cont = p1;
		}
		x1 = ii.second.first;
		y1 = ii.second.second;

		if(x1 != 0){
			if(matrix[x1 - 1][y1] == 1){
				q.push({p1 + 1, {x1 - 1, y1}});
				matrix[x1 - 1][y1] = 0;
			}
		}

		if(y1 != 0){
			if(matrix[x1][y1 - 1] == 1){
				q.push({p1 + 1, {x1, y1 - 1}});
				matrix[x1][y1 - 1] = 0;
			}
		}

		if(x1 != m - 1){
			if(matrix[x1 + 1][y1] == 1){
				q.push({p1 + 1, {x1 + 1, y1}});
				matrix[x1 + 1][y1] = 0;
			}
		}

		if(y1 != n - 1){
			if(matrix[x1][y1 + 1] == 1){
				q.push({p1 + 1, {x1, y1 + 1}});
				matrix[x1][y1 + 1] = 0;
			}
		}

		if(x1 != 0 && y1 != 0){
			if(matrix[x1 - 1][y1 - 1] == 1){
				q.push({p1 + 1, {x1 - 1, y1 - 1}});
				matrix[x1 - 1][y1 - 1] = 0;
			}	
		}

		if(x1 != 0 && y1 != n - 1){
			if(matrix[x1 - 1][y1 + 1] == 1){
				q.push({p1 + 1, {x1 - 1, y1 + 1}});
				matrix[x1 - 1][y1 + 1] = 0;
			}	
		}

		if(x1 != m - 1 && y1 != 0){
			if(matrix[x1 + 1][y1 - 1] == 1){
				q.push({p1 + 1, {x1 + 1, y1 - 1}});
				matrix[x1 + 1][y1 - 1] = 0;
			}	
		}

		if(x1 != m - 1 && y1 != n - 1){
			if(matrix[x1 + 1][y1 + 1] == 1){
				q.push({p1 + 1, {x1 + 1, y1 + 1}});
				matrix[x1 + 1][y1 + 1] = 0;
			}	
		}
	}
	return cont;
}

int main()
{
	int c;
	scanf("%d", &c);
	while(c--){
		int m, n;
		scanf("%d %d",&m, &n);
		int **matrix = (int **) malloc(sizeof(int *) * m);
		for(int i = 0; i < m; i++){
			matrix[i] = (int *) malloc(sizeof(int) * n);
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		int res = bfs(matrix, x, y, m, n);
		printf("%d\n", res);
	}
}