#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();

	map<string, string> mapa;

	while(num--){
		string idioma, natal;
		getline(cin, idioma);
		getline(cin, natal);
		mapa[idioma] = natal;
	}

	scanf("%d", &num);
	getchar();

	while(num--){
		string nome, idioma;
		getline(cin, nome);
		getline(cin, idioma);

		cout << nome << endl;
		cout << mapa[idioma] << endl;
		cout << endl;
	}
}