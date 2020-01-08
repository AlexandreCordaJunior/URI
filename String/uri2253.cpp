#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		bool valida = true;
		int qtdMasc, qtdMin, qtdDig;
		qtdMasc = qtdMin = qtdDig = 0;
		if(str.size() > 32 or str.size() < 6){
			valida = false;
		}
		else{
			for(int i = 0; i < str.size(); i++){
				if(!isalpha(str[i]) && !isdigit(str[i])){
					valida = false;
					break;
				}
				if(isdigit(str[i])){
					qtdDig++;
				}
				if(isalpha(str[i])){
					if(str[i] == toupper(str[i])){
						qtdMasc++;
					}
					else{
						qtdMin++;
					}
				}
			}
		}
		if(qtdMin == 0 or qtdMasc == 0 or qtdDig == 0){
			valida = false;
		}
		if(valida){
			printf("Senha valida.\n");
		}
		else{
			printf("Senha invalida.\n");
		}
	}
}