#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, b;
	while(scanf("%d %d", &n, &b) && n && b){
		int *vet = new int[b];
		for(int i = 0; i < b; i++) scanf("%d", &vet[i]);

		vector<bool> pos(n + 1, false);

		for(int i = 0; i < b; i++){
			for(int j = i + 1; j < b; j++){
				if(abs(vet[i] - vet[j]) <= n){
					pos[abs(vet[i] - vet[j])] = true;
				}
			}
		}

		bool v = true;
		for(int i = 1; i < n + 1; i++){
			if(pos[i] == false){
				v = false;
				break;
			}
		}
		printf("%c\n", v ? 'Y' : 'N');
	}
}