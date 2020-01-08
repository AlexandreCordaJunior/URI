#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	map<string, int> mapa;
	int cont = 0;

	getchar();

	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);
		if(mapa[str] == 0){
			mapa[str]++;
			cont++;
		}
	}
	printf("Falta(m) %d pomekon(s).\n", 151 - cont);
}