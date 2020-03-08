#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		getchar();

		int vet[61][2];
		for(int i = 0; i < 61; i++){
			vet[i][0] = vet[i][1] = 0;
		}

		int cont = 0;

		for(int i = 0; i < num; i++){
			string str;
			getline(cin, str);
			int tam = ((str[0] - '0') * 10) + (str[1] - '0');
			//db(tam);
			char par = str[3];
			if(par == 'D'){
				if(vet[tam][0] == 0 && vet[tam][1] > 0){
					cont++;
					vet[tam][1]--;
				}
				else{
					vet[tam][0]++;
				}
			}
			else{
				if(vet[tam][1] == 0 && vet[tam][0] > 0){
					cont++;
					vet[tam][0]--;
				}
				else{
					vet[tam][1]++;
				}
			}
		}
		printf("%d\n", cont);
	}
}