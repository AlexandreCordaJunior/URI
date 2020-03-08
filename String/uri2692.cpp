#include <bits/stdc++.h>

using namespace std;

int main()
{
	int letras, queries;
	scanf("%d %d", &letras, &queries);
	getchar();

	map<char, char> mapa;
	for(int i = 0; i < letras; i++){
		string str;
		getline(cin, str);
		mapa[str[0]] = str[2];
		mapa[str[2]] = str[0];
	}

	for(int i = 0; i < queries; i++){
		string str;
		getline(cin, str);
		for(int j = 0; j < str.size(); j++){
			if(mapa[str[j]] == 0){
				printf("%c", str[j]);
			}
			else{
				printf("%c", mapa[str[j]]);
			}
		}
		printf("\n");
	}
}
