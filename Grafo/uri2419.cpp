#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	getchar();
	string *vet = new string[x];
	for(int i = 0; i < x; i++){
		getline(cin, vet[i]);
	}
	int cont = 0;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(vet[i][j] == '#'){
				if(i == 0 || j == 0 || i == x - 1 || j == y - 1){
					cont++;
					vet[i][j] = 'C';
				}
				else{
					if(i > 0 && vet[i - 1][j] == '.'){
						cont++;
						vet[i][j] = 'C';
					}
					else if(j > 0 && vet[i][j - 1] == '.'){
						cont++;
						vet[i][j] = 'C';	
					}
					else if(i < x - 1 && vet[i + 1][j] == '.'){
						cont++;
						vet[i][j] = 'C';
					}
					else if(j < y - 1 && vet[i][j + 1] == '.'){
						cont++;
						vet[i][j] = 'C';
					}
				}
			}
		}
	}
	printf("%d\n", cont);
}