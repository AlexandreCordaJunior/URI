#include <bits/stdc++.h>

using namespace std;

int main(){
	int num;
	scanf("%d", &num);
	getchar();
	while(num--){
		string str;
		getline(cin, str);

		int vet[26];
		for(int i = 0; i < 26; i++){
			vet[i] = 0;
		}
		for(int i = 0; i < str.size(); i++){
			if(isalpha(str[i])){
				vet[str[i] - 'a']++;
			}
		}
		int cont = 0;
		for(int i = 0; i < 26; i++){
			if(vet[i] != 0){
				cont++;
			}
		}
		if(cont == 26){
			printf("frase completa\n");
		}
		else{
			if(cont >= 13){
				printf("frase quase completa\n");
			}
			else{
				printf("frase mal elaborada\n");
			}
		}
	}
}