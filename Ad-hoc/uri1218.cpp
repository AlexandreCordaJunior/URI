#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos = 0;
	int num;
	while(scanf("%d", &num) != EOF){
		int cont, masc, fem;
		cont = masc = fem = 0;
		getchar();
		if(casos != 0) printf("\n");

		string str;
		getline(cin, str);
		int espacos = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ' ') espacos++;
		}
		int calcados = ((espacos - 1) / 2) + 1;
		for(int i = 0; i < calcados; i++){
			string str1, str2;
			str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			str2 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());
			int value = stoi(str1);
			if(value == num){
				cont++;
				if(str2[0] == 'F'){
					fem++;
				}
				else{
					masc++;
				}
			}
		}
		printf("Caso %d:\n", ++casos);
		printf("Pares Iguais: %d\n", cont);
		printf("F: %d\n", fem);
		printf("M: %d\n", masc);
	}
}