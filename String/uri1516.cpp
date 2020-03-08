#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) && n && m){
		getchar();

		string *vet = new string[n];
		for(int i = 0; i < n; i++){
			string temp;
			getline(cin, temp);
			vet[i] = temp;
		}
		
		int mN, mM;
		scanf("%d %d", &mN, &mM);

		int repN, repM;
		repN = mN / n;
		repM = mM / m;

		for(int i = 0; i < n; i++){
			for(int w = 0; w < repN; w++){
				for(int j = 0; j < m; j++){
					for(int y = 0; y < repM; y++){
						printf("%c", vet[i][j]);
					}
				}
				printf("\n");
			}
		}
		printf("\n");
	}
}