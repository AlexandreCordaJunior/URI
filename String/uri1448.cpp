#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	getchar();
	for(int i = 0; i < casos; i++){
		string original, str1, str2;
		getline(cin, original);
		getline(cin, str1);
		getline(cin, str2);

		int primeiraDiff, segundaDiff;
		primeiraDiff = segundaDiff = -1;

		int cont1, cont2;
		cont1 = cont2 = 0;

		for(int i = 0; i < original.size(); i++){
			if(original[i] == str1[i]){
				cont1++;
				if(primeiraDiff == -1 && original[i] != str2[i]){
					primeiraDiff = i;
				}
			}
			
			if(original[i] == str2[i]){
				cont2++;
				if(segundaDiff == -1 && original[i] != str1[i]){
					segundaDiff = i;
				}
			}
		}

		printf("Instancia %d\n", i + 1);
		if(cont1 > cont2){
			printf("time 1\n");
		}
		else{
			if(cont2 > cont1){
				printf("time 2\n");
			}
			else{
				if(primeiraDiff < segundaDiff){
					printf("time 1\n");
				}
				else{
					if(segundaDiff < primeiraDiff){
						printf("time 2\n");
					}
					else{
						printf("empate\n");
					}
				}
			}
		}
		printf("\n");
	}
}