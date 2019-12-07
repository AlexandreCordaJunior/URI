#include <bits/stdc++.h>

using namespace std;

int cont = 0;

void bfs(char **matrix, int linhas, int colunas, int i, int j){
	matrix[i][j] = 'o';
	if(i + 1 < linhas && matrix[i + 1][j] == '.'){
		bfs(matrix, linhas, colunas, i + 1, j);
	}
	if(j + 1 < colunas && matrix[i][j + 1] == '.'){
		bfs(matrix, linhas, colunas, i, j + 1);
	}
	if(i - 1 >= 0 && matrix[i - 1][j] == '.'){
		bfs(matrix, linhas, colunas, i - 1, j);
	}
	if(j - 1 >= 0 && matrix[i][j - 1] == '.'){
		bfs(matrix, linhas, colunas, i, j - 1);
	}
}

int main()
{
	int linhas, colunas;
	scanf("%d %d", &linhas, &colunas);
	char **matrix = (char **) malloc(sizeof(char *) * linhas);
	for(int i = 0; i < linhas; i++){
		matrix[i] = (char *) malloc(sizeof(char) * (colunas + 1));
	}

	for(int i = 0; i < linhas; i++){
		getchar();
		char str[1025];
		scanf("%s", str);
		strcpy(matrix[i], str);
	}

	for(int i = 0;i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(matrix[i][j] == '.'){
				cont++;
				bfs(matrix, linhas, colunas, i, j);
			}
		}
	}
	printf("%d\n", cont);

}