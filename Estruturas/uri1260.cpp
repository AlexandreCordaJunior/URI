#include <bits/stdc++.h>

using namespace std;

bool prim = true;

int main()
{
	int casos;
	cin >> casos;
	for(int i = 0; i < casos; i++){
		bool comecou = false;
		bool podeQuebrar = false;
		string str;
		map<string, int> mapa;
		int cont = 0;
		while(1){
			getline(cin, str);
			if(str.compare("") == 0 && comecou) break;
			if(str.compare("") != 0){
				comecou = true;
			}
			if(str[0] != 0){
				mapa[str]++;
				cont++;
			}
		}
		if(!prim){
			printf("\n");
		}
		prim = false;
		for(auto el : mapa){
			cout << el.first << " ";
			printf("%.4lf\n", el.second / (double) cont * 100.0);
		}
	}
}