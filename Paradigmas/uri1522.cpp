#include <bits/stdc++.h>

using namespace std;

bool solve(int **mat, int *qtd, int n){
	bool quebrar = true;
	for(int i = 0; i < n; i++){
		if(qtd[i] != 0);
		quebrar = false;
		break;
	}
	if(quebrar) return true;

	for(int i = 0; i < 3; i++){
		return so
	}
}

int main()
{
	int n;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;

		int sum = 0;

		int **mat = (int **) malloc(sizeof(int *) * n);
		for(int i = 0; i < n; i++){
			mat[i] = (int *) malloc(sizeof(int) * 3);
			for(int j = 0; j < 3; j++){
				mat[i] = 0;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				scanf("%d", &mat[i][j]);
				sum += mat[i][j];
			}
		}
		if(sum % 3 != 0) printf("0\n");
		else{
			int *qtd = new int[n];
			for(int i = 0; i < n; i++){
				qtd[i] = 3;
			}
			bool res = solve(mat, qtd, n);
		}
	}
}