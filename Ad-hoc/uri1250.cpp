#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int tiros;
		scanf("%d", &tiros);

		int *alturas = new int[tiros];
		for(int i = 0; i < tiros; i++){
			scanf("%d", &alturas[i]);
		}

		getchar();
		string str;
		getline(cin, str);

		int cont = 0;
		for(int i = 0; i < tiros; i++){
			if(str[i] == 'S'){
				if(alturas[i] <= 2){
					cont++;
				}
			}
			else{
				if(alturas[i] > 2){
					cont++;
				}
			}
		}
		printf("%d\n", cont);
	}
}