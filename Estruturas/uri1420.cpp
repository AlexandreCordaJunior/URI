#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<char, int> mapa;
	mapa['W'] = 64;
	mapa['H'] = 32;
	mapa['Q'] = 16;
	mapa['E'] = 8;
	mapa['S'] = 4;
	mapa['T'] = 2;
	mapa['X'] = 1;
	while(1){
		string jingle;
		getline(cin, jingle);
		if(jingle.compare("*") == 0) break;
		int total = 0;
		int soma = 0;
		for(int i = 0; i < jingle.size(); i++){
			if(jingle[i] != '/'){
				soma += mapa[jingle[i]];
			}
			else{
				if(soma == 64){
					total += 1;
				}
				soma = 0;
			}
		}
		printf("%d\n", total);
	}
}